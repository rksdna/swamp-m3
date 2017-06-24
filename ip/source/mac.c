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

#include <stm32/gpio.h>
#include <stm32/eth.h>
#include <stm32/crc.h>
#include <threads.h>
#include <mac.h>

#define TX_BUFFERS_COUNT 2
#define RX_BUFFERS_COUNT 4
#define BUFFER_SIZE 1536

static u8_t tx_buffers[TX_BUFFERS_COUNT][BUFFER_SIZE];
static u8_t rx_buffers[RX_BUFFERS_COUNT][BUFFER_SIZE];
static struct eth_tx tx_descriptors[TX_BUFFERS_COUNT];
static struct eth_rx rx_descriptors[RX_BUFFERS_COUNT];

static struct eth_tx *tx_descriptor;
static struct eth_rx *rx_descriptor;

static void make_buffers(void)
{
    u32_t i = TX_BUFFERS_COUNT;
    while (i--)
    {
        tx_descriptors[i].TDES0 = ETH_TDES0_IC | ETH_TDES0_TCH;
        tx_descriptors[i].TDES1 = 0;
        tx_descriptors[i].TDES2 = (u32_t)tx_buffers[i];
        tx_descriptors[i].TDES3 = (u32_t)&tx_descriptors[i + 1];
    }

    tx_descriptors[TX_BUFFERS_COUNT - 1].TDES3 = (u32_t)&tx_descriptors[0];

    i = RX_BUFFERS_COUNT;
    while (i--)
    {
        rx_descriptors[i].RDES0 = ETH_RDES0_OWN;
        rx_descriptors[i].RDES1 = ETH_RDES1_RCH | (BUFFER_SIZE & ETH_RDES1_RBS1);
        rx_descriptors[i].RDES2 = (u32_t)rx_buffers[i];
        rx_descriptors[i].RDES3 = (u32_t)&rx_descriptors[i + 1];
    }

    rx_descriptors[RX_BUFFERS_COUNT - 1].RDES3 = (u32_t)&rx_descriptors[0];

    tx_descriptor = tx_descriptors;
    rx_descriptor = rx_descriptors;
    ETH->DMATDLAR = (u32_t)tx_descriptors;
    ETH->DMARDLAR = (u32_t)rx_descriptors;
}

void startup_mac_service(const u8_t *mac)
{
    ETH->DMABMR |= ETH_DMABMR_SR;
    wait_for(&ETH->DMABMR, ETH_DMABMR_SR, 0);

    ETH->MACCR = ETH_MACCR_ROD | ETH_MACCR_APCS;
    ETH->MACA0LR = mac[0] | (mac[1] << 8) | (mac[2] << 16) | (mac[3] << 24);
    ETH->MACA0HR = mac[4] | (mac[5] << 8);
    ETH->MACHTLR = 0;
    ETH->MACHTHR = 0;
    ETH->MACFFR = ETH_MACFFR_HPF | ETH_MACFFR_HM;
    ETH->MACFCR = 0;
    ETH->DMAOMR = ETH_DMAOMR_RSF | ETH_DMAOMR_TSF;
    ETH->DMABMR = ETH_DMABMR_AAB | ETH_DMABMR_USP | ETH_DMABMR_RDP_1BEAT | ETH_DMABMR_RTPR_1_1 | ETH_DMABMR_PBL_1BEAT;

    make_buffers();

    ETH->MACIMR = 0;
    ETH->DMAIER = 0;
    ETH->MACCR |= ETH_MACCR_TE | ETH_MACCR_RE;
    ETH->DMAOMR |= ETH_DMAOMR_ST | ETH_DMAOMR_SR;
}

void *wait_mac_tx_empty(void)
{
    if (tx_descriptor->TDES0 & ETH_TDES0_OWN)
        wait_for(&tx_descriptor->TDES0, ETH_TDES0_OWN, 0);

    return (void *)tx_descriptor->TDES2;
}

void send_mac_tx_buffer(u32_t size)
{
    tx_descriptor->TDES1 = size & ETH_TDES1_TBS1;
    tx_descriptor->TDES0 |= ETH_TDES0_LS | ETH_TDES0_FS;
    tx_descriptor->TDES0 |= ETH_TDES0_OWN;
    tx_descriptor = (struct eth_tx *)tx_descriptor->TDES3;

    if (ETH->DMASR & ETH_DMASR_TBUS)
    {
        ETH->DMASR = ETH_DMASR_TBUS;
        ETH->DMATPDR = 0;
    }
}

void * wait_mac_rx_full(u32_t * size)
{
    while (1)
    {
        wait_for(&rx_descriptor->RDES0, ETH_RDES0_OWN, 0);

        if ((rx_descriptor->RDES0 & (ETH_RDES0_FS | ETH_RDES0_LS | ETH_RDES0_ES)) == (ETH_RDES0_FS | ETH_RDES0_LS))
            break;

        receive_mac_rx();
    }

    *size = (rx_descriptor->RDES0 & ETH_RDES0_FL) >> 16;
    return (void *)rx_descriptor->RDES2;
}

void receive_mac_rx(void)
{
    rx_descriptor->RDES0 = ETH_RDES0_OWN;
    rx_descriptor = (struct eth_rx *)rx_descriptor->RDES3;

    if (ETH->DMASR & ETH_DMASR_RBUS)
    {
        ETH->DMASR = ETH_DMASR_RBUS;
        ETH->DMARPDR = 0;
    }
}
