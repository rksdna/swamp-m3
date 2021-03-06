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

#ifndef SDIO_H
#define SDIO_H

#include <types.h>

struct sdio
{
    volatile u32_t POWER;
    volatile u32_t CLKCR;
    volatile u32_t ARG;
    volatile u32_t CMD;
    volatile u32_t RESPCMD;
    volatile u32_t RESP1;
    volatile u32_t RESP2;
    volatile u32_t RESP3;
    volatile u32_t RESP4;
    volatile u32_t DTIMER;
    volatile u32_t DLEN;
    volatile u32_t DCTRL;
    volatile u32_t DCOUNT;
    volatile u32_t STA;
    volatile u32_t ICR;
    volatile u32_t MASK;
    u32_t RESERVED0[2];
    volatile u32_t FIFOCNT;
    u32_t RESERVED1[13];
    volatile u32_t FIFO;
};

#define SDIO ((struct sdio *)0x40018000)

#define SDIO_POWER_PWRCTRL ((u32_t)0x00000003)
#define SDIO_POWER_PWRCTRL_0 ((u32_t)0x00000001)
#define SDIO_POWER_PWRCTRL_1 ((u32_t)0x00000002)

#define SDIO_CLKCR_CLKDIV ((u32_t)0x000000FF)
#define SDIO_CLKCR_CLKEN ((u32_t)0x00000100)
#define SDIO_CLKCR_PWRSAV ((u32_t)0x00000200)
#define SDIO_CLKCR_BYPASS ((u32_t)0x00000400)
#define SDIO_CLKCR_WIDBUS ((u32_t)0x00001800)
#define SDIO_CLKCR_WIDBUS_0 ((u32_t)0x00000800)
#define SDIO_CLKCR_WIDBUS_1 ((u32_t)0x00001000)
#define SDIO_CLKCR_WIDBUS_1BIT ((u32_t)0x00000000)
#define SDIO_CLKCR_WIDBUS_4BIT ((u32_t)0x00000800)
#define SDIO_CLKCR_WIDBUS_8BIT ((u32_t)0x00001000)

#define SDIO_CLKCR_NEGEDGE ((u32_t)0x00002000)
#define SDIO_CLKCR_HWFC_EN ((u32_t)0x00004000)

#define SDIO_ARG_CMDARG ((u32_t)0xFFFFFFFF)

#define SDIO_CMD_CMDINDEX ((u32_t)0x0000003F)
#define SDIO_CMD_WAITRESP ((u32_t)0x000000C0)
#define SDIO_CMD_WAITRESP_0 ((u32_t)0x00000040)
#define SDIO_CMD_WAITRESP_1 ((u32_t)0x00000080)
#define SDIO_CMD_WAITRESP_NONE ((u32_t)0x00000000)
#define SDIO_CMD_WAITRESP_SHORT ((u32_t)0x00000040)
#define SDIO_CMD_WAITRESP_LONG ((u32_t)0x000000C0)
#define SDIO_CMD_WAITINT ((u32_t)0x00000100)
#define SDIO_CMD_WAITPEND ((u32_t)0x00000200)
#define SDIO_CMD_CPSMEN ((u32_t)0x00000400)
#define SDIO_CMD_SDIOSUSPEND ((u32_t)0x00000800)
#define SDIO_CMD_ENCMDCOMPL ((u32_t)0x00001000)
#define SDIO_CMD_NIEN ((u32_t)0x00002000)
#define SDIO_CMD_CEATACMD ((u32_t)0x00004000)

#define SDIO_RESPCMD_RESPCMD ((u32_t)0x0000003F)

#define SDIO_RESP0_CARDSTATUS0 ((u32_t)0xFFFFFFFF)

#define SDIO_RESP1_CARDSTATUS1 ((u32_t)0xFFFFFFFF)

#define SDIO_RESP2_CARDSTATUS2 ((u32_t)0xFFFFFFFF)

#define SDIO_RESP3_CARDSTATUS3 ((u32_t)0xFFFFFFFF)

#define SDIO_RESP4_CARDSTATUS4 ((u32_t)0xFFFFFFFF)

#define SDIO_DTIMER_DATATIME ((u32_t)0xFFFFFFFF)

#define SDIO_DLEN_DATALENGTH ((u32_t)0x01FFFFFF)

#define SDIO_DCTRL_DTEN ((u32_t)0x00000001)
#define SDIO_DCTRL_DTDIR ((u32_t)0x00000002)
#define SDIO_DCTRL_DTMODE ((u32_t)0x00000004)
#define SDIO_DCTRL_DMAEN ((u32_t)0x00000008)
#define SDIO_DCTRL_DBLOCKSIZE ((u32_t)0x000000F0)
#define SDIO_DCTRL_DBLOCKSIZE_0 ((u32_t)0x00000010)
#define SDIO_DCTRL_DBLOCKSIZE_1 ((u32_t)0x00000020)
#define SDIO_DCTRL_DBLOCKSIZE_2 ((u32_t)0x00000040)
#define SDIO_DCTRL_DBLOCKSIZE_3 ((u32_t)0x00000080)
#define SDIO_DCTRL_RWSTART ((u32_t)0x00000100)
#define SDIO_DCTRL_RWSTOP ((u32_t)0x00000200)
#define SDIO_DCTRL_RWMOD ((u32_t)0x00000400)
#define SDIO_DCTRL_SDIOEN ((u32_t)0x00000800)

#define SDIO_DCOUNT_DATACOUNT ((u32_t)0x01FFFFFF)

#define SDIO_STA_CCRCFAIL ((u32_t)0x00000001)
#define SDIO_STA_DCRCFAIL ((u32_t)0x00000002)
#define SDIO_STA_CTIMEOUT ((u32_t)0x00000004)
#define SDIO_STA_DTIMEOUT ((u32_t)0x00000008)
#define SDIO_STA_TXUNDERR ((u32_t)0x00000010)
#define SDIO_STA_RXOVERR ((u32_t)0x00000020)
#define SDIO_STA_CMDREND ((u32_t)0x00000040)
#define SDIO_STA_CMDSENT ((u32_t)0x00000080)
#define SDIO_STA_DATAEND ((u32_t)0x00000100)
#define SDIO_STA_STBITERR ((u32_t)0x00000200)
#define SDIO_STA_DBCKEND ((u32_t)0x00000400)
#define SDIO_STA_CMDACT ((u32_t)0x00000800)
#define SDIO_STA_TXACT ((u32_t)0x00001000)
#define SDIO_STA_RXACT ((u32_t)0x00002000)
#define SDIO_STA_TXFIFOHE ((u32_t)0x00004000)
#define SDIO_STA_RXFIFOHF ((u32_t)0x00008000)
#define SDIO_STA_TXFIFOF ((u32_t)0x00010000)
#define SDIO_STA_RXFIFOF ((u32_t)0x00020000)
#define SDIO_STA_TXFIFOE ((u32_t)0x00040000)
#define SDIO_STA_RXFIFOE ((u32_t)0x00080000)
#define SDIO_STA_TXDAVL ((u32_t)0x00100000)
#define SDIO_STA_RXDAVL ((u32_t)0x00200000)
#define SDIO_STA_SDIOIT ((u32_t)0x00400000)
#define SDIO_STA_CEATAEND ((u32_t)0x00800000)

#define SDIO_ICR_CCRCFAILC ((u32_t)0x00000001)
#define SDIO_ICR_DCRCFAILC ((u32_t)0x00000002)
#define SDIO_ICR_CTIMEOUTC ((u32_t)0x00000004)
#define SDIO_ICR_DTIMEOUTC ((u32_t)0x00000008)
#define SDIO_ICR_TXUNDERRC ((u32_t)0x00000010)
#define SDIO_ICR_RXOVERRC ((u32_t)0x00000020)
#define SDIO_ICR_CMDRENDC ((u32_t)0x00000040)
#define SDIO_ICR_CMDSENTC ((u32_t)0x00000080)
#define SDIO_ICR_DATAENDC ((u32_t)0x00000100)
#define SDIO_ICR_STBITERRC ((u32_t)0x00000200)
#define SDIO_ICR_DBCKENDC ((u32_t)0x00000400)
#define SDIO_ICR_SDIOITC ((u32_t)0x00400000)
#define SDIO_ICR_CEATAENDC ((u32_t)0x00800000)

#define SDIO_MASK_CCRCFAILIE ((u32_t)0x00000001)
#define SDIO_MASK_DCRCFAILIE ((u32_t)0x00000002)
#define SDIO_MASK_CTIMEOUTIE ((u32_t)0x00000004)
#define SDIO_MASK_DTIMEOUTIE ((u32_t)0x00000008)
#define SDIO_MASK_TXUNDERRIE ((u32_t)0x00000010)
#define SDIO_MASK_RXOVERRIE ((u32_t)0x00000020)
#define SDIO_MASK_CMDRENDIE ((u32_t)0x00000040)
#define SDIO_MASK_CMDSENTIE ((u32_t)0x00000080)
#define SDIO_MASK_DATAENDIE ((u32_t)0x00000100)
#define SDIO_MASK_STBITERRIE ((u32_t)0x00000200)
#define SDIO_MASK_DBCKENDIE ((u32_t)0x00000400)
#define SDIO_MASK_CMDACTIE ((u32_t)0x00000800)
#define SDIO_MASK_TXACTIE ((u32_t)0x00001000)
#define SDIO_MASK_RXACTIE ((u32_t)0x00002000)
#define SDIO_MASK_TXFIFOHEIE ((u32_t)0x00004000)
#define SDIO_MASK_RXFIFOHFIE ((u32_t)0x00008000)
#define SDIO_MASK_TXFIFOFIE ((u32_t)0x00010000)
#define SDIO_MASK_RXFIFOFIE ((u32_t)0x00020000)
#define SDIO_MASK_TXFIFOEIE ((u32_t)0x00040000)
#define SDIO_MASK_RXFIFOEIE ((u32_t)0x00080000)
#define SDIO_MASK_TXDAVLIE ((u32_t)0x00100000)
#define SDIO_MASK_RXDAVLIE ((u32_t)0x00200000)
#define SDIO_MASK_SDIOITIE ((u32_t)0x00400000)
#define SDIO_MASK_CEATAENDIE ((u32_t)0x00800000)

#define SDIO_FIFOCNT_FIFOCOUNT ((u32_t)0x00FFFFFF)

#define SDIO_FIFO_FIFODATA ((u32_t)0xFFFFFFFF)

#endif
