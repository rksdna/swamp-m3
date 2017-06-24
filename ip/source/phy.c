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

#include <threads.h>
#include <stm32/eth.h>
#include <phy.h>

#define PHY_ADDRESS 0x10

#define PHY_BCR ((u32_t)0x00000000)
#define PHY_BSR ((u32_t)0x00000001)
#define PHY_ID1 ((u32_t)0x00000002)
#define PHY_ID2 ((u32_t)0x00000003)

#define PHY_BCR_RESET ((u32_t)0x00008000)
#define PHY_BCR_LOOPBACK ((u32_t)0x00004000)
#define PHY_BCR_SPEED ((u32_t)0x00002000)
#define PHY_BCR_AUTO_NEGOTIATION_ENABLE ((u32_t)0x00001000)
#define PHY_BCR_POWER_DOWN ((u32_t)0x00000800)
#define PHY_BCR_RESTART_AUTO_NEGOTIATION ((u32_t)0x00000200)
#define PHY_BCR_DUPLEX_MODE ((u32_t)0x00000100)

#define PHY_BSR_100BASE_T4_SUPPORT  ((u32_t)0x00008000)
#define PHY_BSR_100BASE_TX_FD_SUPPORT ((u32_t)0x00004000)
#define PHY_BSR_100BASE_TX_HD_SUPPORT ((u32_t)0x00002000)
#define PHY_BSR_10BASE_T_FD_SUPPORT ((u32_t)0x00001000)
#define PHY_BSR_10BASE_T_HD_SUPPORT ((u32_t)0x00000800)
#define PHY_BSR_MF_PREAMBLE_SUPPRESSION ((u32_t)0x00000040)
#define PHY_BSR_AUTO_NEGOTIATION_COMPLETE ((u32_t)0x00000020)
#define PHY_BSR_REMOTE_FAULT ((u32_t)0x00000010)
#define PHY_BSR_AUTO_NEGOTIATION ((u32_t)0x00000008)
#define PHY_BSR_LINK_STATUS ((u32_t)0x00000004)
#define PHY_BSR_JABBER_DETECT ((u32_t)0x00000002)
#define PHY_BSR_EXTENDED_CAPABILITY ((u32_t)0x00000001)

#define PHY_ID1_ID ((u32_t)0x0000FFFF)

#define PHY_ID2_ID ((u32_t)0x0000FFFF)

static u32_t phy_bsr = 0;

static u32_t read_phy_register(u32_t address, u32_t reg)
{
    ETH->MACMIIAR = ((address << 11) & ETH_MACMIIAR_PA) | ((reg << 6) & ETH_MACMIIAR_MR) | ETH_MACMIIAR_CR_DIV42 | ETH_MACMIIAR_MB;
    wait_for(&ETH->MACMIIAR, ETH_MACMIIAR_MB, 0);
    return ETH->MACMIIDR;
}

static void write_phy_register(u32_t address, u32_t reg, u32_t value)
{
    ETH->MACMIIDR = value;
    ETH->MACMIIAR = ((address << 11) & ETH_MACMIIAR_PA) | ((reg << 6) & ETH_MACMIIAR_MR) | ETH_MACMIIAR_CR_DIV42 | ETH_MACMIIAR_MW | ETH_MACMIIAR_MB;
    wait_for(&ETH->MACMIIAR, ETH_MACMIIAR_MB, 0);
}

void startup_phy_service(void)
{
    write_phy_register(PHY_ADDRESS, PHY_BCR, PHY_BCR_RESET | PHY_BCR_AUTO_NEGOTIATION_ENABLE);
}

void poll_phy_service(void)
{
    const u32_t bsr = read_phy_register(PHY_ADDRESS, PHY_BSR);

    if ((bsr & PHY_BSR_LINK_STATUS) && !(phy_bsr & PHY_BSR_LINK_STATUS))
    {
        const u32_t bcr = read_phy_register(PHY_ADDRESS, PHY_BCR);

        if (bcr & PHY_BCR_SPEED)
            ETH->MACCR |= ETH_MACCR_FES;
        else
            ETH->MACCR &= ~ETH_MACCR_FES;

        if (bcr & PHY_BCR_DUPLEX_MODE)
            ETH->MACCR |= ETH_MACCR_DM;
        else
            ETH->MACCR &= ~ETH_MACCR_DM;
    }

    phy_bsr = bsr;
}

u32_t has_phy_connection(void)
{
    return phy_bsr & PHY_BSR_LINK_STATUS;
}

u32_t get_phy_id(void )
{
    return read_phy_register(PHY_ADDRESS, PHY_ID1) | (read_phy_register(PHY_ADDRESS, PHY_ID2) << 16);
}
