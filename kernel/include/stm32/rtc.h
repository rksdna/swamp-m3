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

#ifndef RTC_H
#define RTC_H

#include <types.h>

struct rtc
{
    volatile u32_t CRH;
    volatile u32_t CRL;
    volatile u32_t PRLH;
    volatile u32_t PRLL;
    volatile u32_t DIVH;
    volatile u32_t DIVL;
    volatile u32_t CNTH;
    volatile u32_t CNTL;
    volatile u32_t ALRH;
    volatile u32_t ALRL;
};

#define RTC ((struct rtc *)0x40002800)

#define RTC_CRH_SECIE ((u32_t)0x00000001)
#define RTC_CRH_ALRIE ((u32_t)0x00000002)
#define RTC_CRH_OWIE ((u32_t)0x00000004)

#define RTC_CRL_SECF ((u32_t)0x00000001)
#define RTC_CRL_ALRF ((u32_t)0x00000002)
#define RTC_CRL_OWF ((u32_t)0x00000004)
#define RTC_CRL_RSF ((u32_t)0x00000008)
#define RTC_CRL_CNF ((u32_t)0x00000010)
#define RTC_CRL_RTOFF ((u32_t)0x00000020)

#define RTC_PRLH_PRL ((u32_t)0x0000000F)

#define RTC_PRLL_PRL ((u32_t)0x0000FFFF)

#define RTC_DIVH_DIV ((u32_t)0x0000000F)

#define RTC_DIVL_DIV ((u32_t)0x0000FFFF)

#define RTC_CNTH_CNT ((u32_t)0x0000FFFF)

#define RTC_CNTL_CNT ((u32_t)0x0000FFFF)

#define RTC_ALRH_ALR ((u32_t)0x0000FFFF)

#define RTC_ALRL_ALR ((u32_t)0x0000FFFF)

#endif
