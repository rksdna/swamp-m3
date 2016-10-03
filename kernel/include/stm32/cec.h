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

#ifndef CEC_H
#define CEC_H

#include <types.h>

struct cec
{
    volatile u32_t CFGR;
    volatile u32_t OAR;
    volatile u32_t PRES;
    volatile u32_t ESR;
    volatile u32_t CSR;
    volatile u32_t TXD;
    volatile u32_t RXD;
};

#define CEC ((struct cec *)0x40007800)

#define CEC_CFGR_PE ((u32_t)0x00000001)
#define CEC_CFGR_IE ((u32_t)0x00000002)
#define CEC_CFGR_BTEM ((u32_t)0x00000004)
#define CEC_CFGR_BPEM ((u32_t)0x00000008)

#define CEC_OAR_OA ((u32_t)0x0000000F)

#define CEC_PRES_PRES ((u32_t)0x00003FFF)

#define CEC_ESR_BTE ((u32_t)0x00000001)
#define CEC_ESR_BPE ((u32_t)0x00000002)
#define CEC_ESR_RBTFE ((u32_t)0x00000004)
#define CEC_ESR_SBE ((u32_t)0x00000008)
#define CEC_ESR_ACKE ((u32_t)0x00000010)
#define CEC_ESR_LINE ((u32_t)0x00000020)
#define CEC_ESR_TBTFE ((u32_t)0x00000040)

#define CEC_CSR_TSOM ((u32_t)0x00000001)
#define CEC_CSR_TEOM ((u32_t)0x00000002)
#define CEC_CSR_TERR ((u32_t)0x00000004)
#define CEC_CSR_TBTRF ((u32_t)0x00000008)
#define CEC_CSR_RSOM ((u32_t)0x00000010)
#define CEC_CSR_REOM ((u32_t)0x00000020)
#define CEC_CSR_RERR ((u32_t)0x00000040)
#define CEC_CSR_RBTF ((u32_t)0x00000080)

#define CEC_TXD_TXD ((u32_t)0x000000FF)

#define CEC_RXD_RXD ((u32_t)0x000000FF)

#endif
