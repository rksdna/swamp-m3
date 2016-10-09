/*
 * Swamp - cooperative multitasking operating system
 * Copyright (c) 2016 rksdna
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <tools.h>
#include <ip.h>

#define DIX_TYPE_ARP ((u16_t)0x0608)
#define DIX_TYPE_IP ((u16_t)0x0008)

#define ARP_HTYPE_ETH ((u16_t)0x0100)
#define ARP_PTYPE_IP ((u16_t)0x0008)
#define ARP_OPER_REQUEST ((u16_t)0x0100)
#define ARP_OPER_RESPONSE ((u16_t)0x0200)

#define IP_TOH_IPv4 ((u8_t)0x45)
#define IP_PROTOCOL_ICMP ((u8_t)0x01)
#define IP_PROTOCOL_TCP ((u8_t)0x06)
#define IP_PROTOCOL_UDP ((u8_t)0x11)

#define ICMP_TYPE_ECHO_REQUEST ((u8_t)0x08)
#define ICMP_TYPE_ECHO_REPLY ((u8_t)0x00)

struct dix_frame
{
    u8_t THA[MAC_SIZE];
    u8_t SHA[MAC_SIZE];
    u16_t TYPE;
    u8_t data[];
};

struct arp_frame
{
    u16_t HTYPE;
    u16_t PTYPE;
    u8_t HLEN;
    u8_t PLEN;
    u16_t OPER;
    u8_t SHA[MAC_SIZE];
    u8_t SPA[IP_SIZE];
    u8_t THA[MAC_SIZE];
    u8_t TPA[IP_SIZE];
};

struct ip_frame
{
    u8_t TOH;
    u8_t TOS;
    u16_t TLEN;
    u16_t FID;
    u16_t FOFFSET;
    u8_t TTL;
    u8_t PROTOCOL;
    u16_t CHKSUM;
    u8_t SPA[IP_SIZE];
    u8_t TPA[IP_SIZE];
    u8_t data[];
};

struct icmp_frame
{
    u8_t TYPE;
    u8_t CODE;
    u16_t CHKSUM;
    u32_t ROH;
    u8_t data[];
};

struct udp_frame
{
    u16_t SPORT;
    u16_t TPORT;
    u16_t LEN;
    u16_t CHKSUM;
    u8_t data[];
};

static u16_t swap16(u16_t value)
{
    u32_t result = 0;
    asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
    return result;
}

static u16_t checksum(const void * buffer, u32_t size)
{
    u32_t checksum = 0;

    while (size > 1)
    {
        checksum += swap16(*(u16_t *)buffer);
        buffer += sizeof(u16_t);
        size -= 2;
    }

    if (size)
        checksum += swap16(*(u8_t *)buffer);

    while (checksum >> 16)
        checksum = (checksum & 0xFFFF) + (checksum >> 16);

    return ~checksum;
}

static u32_t arp_parse(struct ip_socket *target, struct ip_socket *source, struct arp_frame *reply, const struct arp_frame *request, u32_t size)
{
    if (size < sizeof(struct arp_frame))
        return 0;

    if (request->HTYPE != ARP_HTYPE_ETH)
        return 0;

    if (request->PTYPE != ARP_PTYPE_IP)
        return 0;

    if (request->HLEN != MAC_SIZE)
        return 0;

    if (request->PLEN != IP_SIZE)
        return 0;

    if (request->OPER != ARP_OPER_REQUEST)
        return 0;

    target->ip = request->TPA;
    source->ip = request->SPA;

    if (!ip_address_handler(target, source))
        return 0;

    reply->HTYPE = ARP_HTYPE_ETH;
    reply->PTYPE = ARP_PTYPE_IP;
    reply->HLEN = MAC_SIZE;
    reply->PLEN = IP_SIZE;
    reply->OPER = ARP_OPER_RESPONSE;
    copy(reply->SHA, target->mac, MAC_SIZE);
    copy(reply->SPA, target->ip, IP_SIZE);
    copy(reply->THA, source->mac, MAC_SIZE);
    copy(reply->TPA, source->ip, IP_SIZE);

    return sizeof(struct arp_frame);
}

static u32_t icmp_parse(struct ip_socket *target, struct ip_socket *source, struct icmp_frame *reply, const struct icmp_frame *request, u32_t size)
{
    if (size < sizeof(struct icmp_frame))
        return 0;

    if (request->TYPE != ICMP_TYPE_ECHO_REQUEST)
        return 0;

    if (!ip_ping_handler(target, source))
        return 0;

    reply->TYPE = ICMP_TYPE_ECHO_REPLY;
    reply->CODE = request->CODE;
    reply->CHKSUM = request->CHKSUM + 8; // Trick
    reply->ROH = request->ROH;
    copy(reply->data, request->data, size - sizeof(struct icmp_frame));
    return size;
}

static u32_t udp_parse(struct ip_socket *target, struct ip_socket *source, struct udp_frame *reply, const struct udp_frame *request, u32_t size)
{
    if (size < sizeof(struct udp_frame))
        return 0;

    if (swap16(request->LEN) < sizeof(struct udp_frame))
        return 0;

    size = swap16(request->LEN) - sizeof(struct udp_frame);
    target->port = swap16(request->TPORT);
    source->port = swap16(request->SPORT);

    size = ip_datagram_handler(target, source, reply->data, request->data, size);

    if (!size)
        return 0;

    size += sizeof(struct udp_frame);
    reply->SPORT = swap16(target->port);
    reply->TPORT = swap16(source->port);
    reply->LEN = swap16(size);
    reply->CHKSUM = 0;
    return size;
}

static u32_t ip_parse(struct ip_socket *target, struct ip_socket *source, struct ip_frame *reply, const struct ip_frame *request, u32_t size)
{
    if (size < sizeof(struct ip_frame))
        return 0;

    if (request->TOH != IP_TOH_IPv4)
        return 0;

    if (swap16(request->TLEN) < sizeof(struct ip_frame))
        return 0;

    size = swap16(request->TLEN) - sizeof(struct ip_frame);
    target->ip = request->TPA;
    source->ip = request->SPA;

    switch (request->PROTOCOL)
    {
    case IP_PROTOCOL_ICMP:
        size = icmp_parse(target, source, (void *)reply->data, (const void *)request->data, size);
        break;

    case IP_PROTOCOL_UDP:
        size = udp_parse(target, source, (void *)reply->data, (const void *)request->data, size);
        break;

    default:
        break;
    }

    if (!size)
        return 0;

    size += sizeof(struct ip_frame);
    reply->TOH = IP_TOH_IPv4;
    reply->TOS = request->TOS;
    reply->TLEN = swap16(size);
    reply->FID = 0;
    reply->FOFFSET = 0;
    reply->TTL = 64;
    reply->PROTOCOL = request->PROTOCOL;
    reply->CHKSUM = 0;
    copy(reply->SPA, target->ip, IP_SIZE);
    copy(reply->TPA, source->ip, IP_SIZE);
    reply->CHKSUM = swap16(checksum(reply, sizeof(struct ip_frame)));
    return size;
}

static u32_t dix_parse(struct ip_socket *target, struct ip_socket *source, struct dix_frame *reply, const struct dix_frame *request, u32_t size)
{
    if (size < sizeof(struct dix_frame))
        return 0;

    size -= sizeof(struct dix_frame);
    target->mac = request->THA;
    source->mac = request->SHA;

    switch (request->TYPE)
    {
    case DIX_TYPE_ARP:
        size = arp_parse(target, source, (void *)reply->data, (const void *)request->data, size);
        break;

    case DIX_TYPE_IP:
        size = ip_parse(target, source, (void *)reply->data, (const void *)request->data, size);
        break;

    default:
        break;
    }

    if (!size)
        return 0;

    size += sizeof(struct dix_frame);
    copy(reply->SHA, target->mac, MAC_SIZE);
    copy(reply->THA, source->mac, MAC_SIZE);
    reply->TYPE = request->TYPE;
    return size;
}

u32_t poll_ip_service(void *reply, const void *request, u32_t size)
{
    struct ip_socket target = {0, 0, 0};
    struct ip_socket source = {0, 0, 0};

    return dix_parse(&target, &source, reply, request, size);
}
