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

#define MAC_DESCRIPTORS_COUNT 8

static struct eth_tx *tx_descriptor;
static struct eth_rx *rx_descriptor;

void startup_mac_service(const u8_t *mac)
{
    static struct eth_tx tx_descriptors[MAC_DESCRIPTORS_COUNT];
    static struct eth_rx rx_descriptors[MAC_DESCRIPTORS_COUNT];

    u32_t count = MAC_DESCRIPTORS_COUNT;
    while (count--)
    {
        tx_descriptors[count].TDES0 = 0;
        tx_descriptors[count].TDES3 = (u32_t)(tx_descriptors + count + 1);
        rx_descriptors[count].RDES0 = 0;
        rx_descriptors[count].RDES3 = (u32_t)(rx_descriptors + count + 1);
    }

    tx_descriptors[MAC_DESCRIPTORS_COUNT - 1].TDES3 = (u32_t)tx_descriptors;
    rx_descriptors[MAC_DESCRIPTORS_COUNT - 1].RDES3 = (u32_t)rx_descriptors;
    tx_descriptor = tx_descriptors;
    rx_descriptor = rx_descriptors;

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

    ETH->DMATDLAR = (u32_t)tx_descriptors;
    ETH->DMARDLAR = (u32_t)rx_descriptors;

    ETH->MACIMR = 0;
    ETH->DMAIER = 0;
    ETH->MACCR |= ETH_MACCR_TE | ETH_MACCR_RE;
    ETH->DMAOMR |= ETH_DMAOMR_ST | ETH_DMAOMR_SR;
}

void write_mac_data(const void *data, u32_t size)
{
    struct eth_tx *descriptor = tx_descriptor;
    tx_descriptor = (struct eth_tx *)descriptor->TDES3;

    descriptor->TDES1 = size & ETH_TDES1_TBS1;
    descriptor->TDES2 = (u32_t)data;
    descriptor->TDES0 = ETH_TDES0_IC | ETH_TDES0_TCH | ETH_TDES0_LS | ETH_TDES0_FS | ETH_TDES0_OWN;

    if (ETH->DMASR & ETH_DMASR_TBUS)
    {
        ETH->DMASR = ETH_DMASR_TBUS;
        ETH->DMATPDR = 0;
    }

    wait_for(&descriptor->TDES0, ETH_RDES0_OWN, 0);
}

u32_t read_mac_data(void *data, u32_t size)
{
    struct eth_rx *descriptor = rx_descriptor;
    rx_descriptor = (struct eth_rx *)descriptor->RDES3;

    descriptor->RDES1 = ETH_RDES1_RCH | (ETH_RDES1_RBS1 & size);
    descriptor->RDES2 = (u32_t)data;
    descriptor->RDES0 = ETH_RDES0_OWN;

    if (ETH->DMASR & ETH_DMASR_RBUS)
    {
        ETH->DMASR = ETH_DMASR_RBUS;
        ETH->DMARPDR = 0;
    }

    wait_for(&descriptor->RDES0, ETH_RDES0_OWN, 0);

    if ((descriptor->RDES0 & (ETH_RDES0_FS | ETH_RDES0_LS | ETH_RDES0_ES)) != (ETH_RDES0_FS | ETH_RDES0_LS))
        return 0;

    return (descriptor->RDES0 & ETH_RDES0_FL) >> 16;
}
