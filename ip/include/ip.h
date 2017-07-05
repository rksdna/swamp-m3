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

#ifndef IP_H
#define IP_H

#include <types.h>

#define IP_SIZE 4
#define MAC_SIZE 6

struct ip_socket
{
    const u8_t *mac;
    const u8_t *ip;
    u16_t port;
};

extern u32_t ip_address_handler(struct ip_socket *target, struct ip_socket *source);
extern u32_t ip_ping_handler(struct ip_socket *target, struct ip_socket *source);
extern u32_t ip_datagram_handler(struct ip_socket *target, struct ip_socket *source, void *reply, u32_t *reply_size, const void *request, u32_t request_size);

u32_t poll_ip_service(void *reply, const void *request, u32_t size);

#endif
