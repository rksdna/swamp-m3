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

#ifndef BKP_H
#define BKP_H

#include <types.h>

struct bkp
{
    u32_t RESERVED0;
    volatile u32_t DR1;
    volatile u32_t DR2;
    volatile u32_t DR3;
    volatile u32_t DR4;
    volatile u32_t DR5;
    volatile u32_t DR6;
    volatile u32_t DR7;
    volatile u32_t DR8;
    volatile u32_t DR9;
    volatile u32_t DR10;
    volatile u32_t RTCCR;
    volatile u32_t CR;
    volatile u32_t CSR;
    u32_t RESERVED1[2];
    volatile u32_t DR11;
    volatile u32_t DR12;
    volatile u32_t DR13;
    volatile u32_t DR14;
    volatile u32_t DR15;
    volatile u32_t DR16;
    volatile u32_t DR17;
    volatile u32_t DR18;
    volatile u32_t DR19;
    volatile u32_t DR20;
    volatile u32_t DR21;
    volatile u32_t DR22;
    volatile u32_t DR23;
    volatile u32_t DR24;
    volatile u32_t DR25;
    volatile u32_t DR26;
    volatile u32_t DR27;
    volatile u32_t DR28;
    volatile u32_t DR29;
    volatile u32_t DR30;
    volatile u32_t DR31;
    volatile u32_t DR32;
    volatile u32_t DR33;
    volatile u32_t DR34;
    volatile u32_t DR35;
    volatile u32_t DR36;
    volatile u32_t DR37;
    volatile u32_t DR38;
    volatile u32_t DR39;
    volatile u32_t DR40;
    volatile u32_t DR41;
    volatile u32_t DR42;
};

#define BKP ((struct bkp *)0x40006C00)

#define BKP_DR1_DATA ((u32_t)0x0000FFFF)

#define BKP_DR2_DATA ((u32_t)0x0000FFFF)

#define BKP_DR3_DATA ((u32_t)0x0000FFFF)

#define BKP_DR4_DATA ((u32_t)0x0000FFFF)

#define BKP_DR5_DATA ((u32_t)0x0000FFFF)

#define BKP_DR6_DATA ((u32_t)0x0000FFFF)

#define BKP_DR7_DATA ((u32_t)0x0000FFFF)

#define BKP_DR8_DATA ((u32_t)0x0000FFFF)

#define BKP_DR9_DATA ((u32_t)0x0000FFFF)

#define BKP_DR10_DATA ((u32_t)0x0000FFFF)

#define BKP_RTCCR_CAL ((u32_t)0x0000007F)
#define BKP_RTCCR_CCO ((u32_t)0x00000080)
#define BKP_RTCCR_ASOE ((u32_t)0x00000100)
#define BKP_RTCCR_ASOS ((u32_t)0x00000200)

#define BKP_CR_TPE ((u32_t)0x00000001)
#define BKP_CR_TPAL ((u32_t)0x00000002)

#define BKP_CSR_CTE ((u32_t)0x00000001)
#define BKP_CSR_CTI ((u32_t)0x00000002)
#define BKP_CSR_TPIE ((u32_t)0x00000004)
#define BKP_CSR_TEF ((u32_t)0x00000100)
#define BKP_CSR_TIF ((u32_t)0x00000200)

#define BKP_DR11_DATA ((u32_t)0x0000FFFF)

#define BKP_DR12_DATA ((u32_t)0x0000FFFF)

#define BKP_DR13_DATA ((u32_t)0x0000FFFF)

#define BKP_DR14_DATA ((u32_t)0x0000FFFF)

#define BKP_DR15_DATA ((u32_t)0x0000FFFF)

#define BKP_DR16_DATA ((u32_t)0x0000FFFF)

#define BKP_DR17_DATA ((u32_t)0x0000FFFF)

#define BKP_DR18_DATA ((u32_t)0x0000FFFF)

#define BKP_DR19_DATA ((u32_t)0x0000FFFF)

#define BKP_DR20_DATA ((u32_t)0x0000FFFF)

#define BKP_DR21_DATA ((u32_t)0x0000FFFF)

#define BKP_DR22_DATA ((u32_t)0x0000FFFF)

#define BKP_DR23_DATA ((u32_t)0x0000FFFF)

#define BKP_DR24_DATA ((u32_t)0x0000FFFF)

#define BKP_DR25_DATA ((u32_t)0x0000FFFF)

#define BKP_DR26_DATA ((u32_t)0x0000FFFF)

#define BKP_DR27_DATA ((u32_t)0x0000FFFF)

#define BKP_DR28_DATA ((u32_t)0x0000FFFF)

#define BKP_DR29_DATA ((u32_t)0x0000FFFF)

#define BKP_DR30_DATA ((u32_t)0x0000FFFF)

#define BKP_DR31_DATA ((u32_t)0x0000FFFF)

#define BKP_DR32_DATA ((u32_t)0x0000FFFF)

#define BKP_DR33_DATA ((u32_t)0x0000FFFF)

#define BKP_DR34_DATA ((u32_t)0x0000FFFF)

#define BKP_DR35_DATA ((u32_t)0x0000FFFF)

#define BKP_DR36_DATA ((u32_t)0x0000FFFF)

#define BKP_DR37_DATA ((u32_t)0x0000FFFF)

#define BKP_DR38_DATA ((u32_t)0x0000FFFF)

#define BKP_DR39_DATA ((u32_t)0x0000FFFF)

#define BKP_DR40_DATA ((u32_t)0x0000FFFF)

#define BKP_DR41_DATA ((u32_t)0x0000FFFF)

#define BKP_DR42_DATA ((u32_t)0x0000FFFF)

#endif
