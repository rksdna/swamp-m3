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

#ifndef GPIO_H
#define GPIO_H

#warning "Not checked"

#include <types.h>

struct gpio
{
    volatile u32_t CRL;
    volatile u32_t CRH;
    volatile u32_t IDR;
    volatile u32_t ODR;
    volatile u32_t BSRR;
    volatile u32_t BRR;
    volatile u32_t LCKR;
};

#define GPIOA ((struct gpio *)0x40010800)
#define GPIOB ((struct gpio *)0x40010C00)
#define GPIOC ((struct gpio *)0x40011000)
#define GPIOD ((struct gpio *)0x40011400)
#define GPIOE ((struct gpio *)0x40011800)
#define GPIOF ((struct gpio *)0x40011C00)
#define GPIOG ((struct gpio *)0x40012000)

#define GPIO_CRL_MODE0 ((u32_t)0x00000003)
#define GPIO_CRL_MODE0_0 ((u32_t)0x00000001)
#define GPIO_CRL_MODE0_1 ((u32_t)0x00000002)
#define GPIO_CRL_MODE1 ((u32_t)0x00000030)
#define GPIO_CRL_MODE1_0 ((u32_t)0x00000010)
#define GPIO_CRL_MODE1_1 ((u32_t)0x00000020)
#define GPIO_CRL_MODE2 ((u32_t)0x00000300)
#define GPIO_CRL_MODE2_0 ((u32_t)0x00000100)
#define GPIO_CRL_MODE2_1 ((u32_t)0x00000200)
#define GPIO_CRL_MODE3 ((u32_t)0x00003000)
#define GPIO_CRL_MODE3_0 ((u32_t)0x00001000)
#define GPIO_CRL_MODE3_1 ((u32_t)0x00002000)
#define GPIO_CRL_MODE4 ((u32_t)0x00030000)
#define GPIO_CRL_MODE4_0 ((u32_t)0x00010000)
#define GPIO_CRL_MODE4_1 ((u32_t)0x00020000)
#define GPIO_CRL_MODE5 ((u32_t)0x00300000)
#define GPIO_CRL_MODE5_0 ((u32_t)0x00100000)
#define GPIO_CRL_MODE5_1 ((u32_t)0x00200000)
#define GPIO_CRL_MODE6 ((u32_t)0x03000000)
#define GPIO_CRL_MODE6_0 ((u32_t)0x01000000)
#define GPIO_CRL_MODE6_1 ((u32_t)0x02000000)
#define GPIO_CRL_MODE7 ((u32_t)0x30000000)
#define GPIO_CRL_MODE7_0 ((u32_t)0x10000000)
#define GPIO_CRL_MODE7_1 ((u32_t)0x20000000)
#define GPIO_CRL_CNF0 ((u32_t)0x0000000C)
#define GPIO_CRL_CNF0_0 ((u32_t)0x00000004)
#define GPIO_CRL_CNF0_1 ((u32_t)0x00000008)
#define GPIO_CRL_CNF1 ((u32_t)0x000000C0)
#define GPIO_CRL_CNF1_0 ((u32_t)0x00000040)
#define GPIO_CRL_CNF1_1 ((u32_t)0x00000080)
#define GPIO_CRL_CNF2 ((u32_t)0x00000C00)
#define GPIO_CRL_CNF2_0 ((u32_t)0x00000400)
#define GPIO_CRL_CNF2_1 ((u32_t)0x00000800)
#define GPIO_CRL_CNF3 ((u32_t)0x0000C000)
#define GPIO_CRL_CNF3_0 ((u32_t)0x00004000)
#define GPIO_CRL_CNF3_1 ((u32_t)0x00008000)
#define GPIO_CRL_CNF4 ((u32_t)0x000C0000)
#define GPIO_CRL_CNF4_0 ((u32_t)0x00040000)
#define GPIO_CRL_CNF4_1 ((u32_t)0x00080000)
#define GPIO_CRL_CNF5 ((u32_t)0x00C00000)
#define GPIO_CRL_CNF5_0 ((u32_t)0x00400000)
#define GPIO_CRL_CNF5_1 ((u32_t)0x00800000)
#define GPIO_CRL_CNF6 ((u32_t)0x0C000000)
#define GPIO_CRL_CNF6_0 ((u32_t)0x04000000)
#define GPIO_CRL_CNF6_1 ((u32_t)0x08000000)
#define GPIO_CRL_CNF7 ((u32_t)0xC0000000)
#define GPIO_CRL_CNF7_0 ((u32_t)0x40000000)
#define GPIO_CRL_CNF7_1 ((u32_t)0x80000000)

#define GPIO_CRH_MODE8 ((u32_t)0x00000003)
#define GPIO_CRH_MODE8_0 ((u32_t)0x00000001)
#define GPIO_CRH_MODE8_1 ((u32_t)0x00000002)
#define GPIO_CRH_MODE9 ((u32_t)0x00000030)
#define GPIO_CRH_MODE9_0 ((u32_t)0x00000010)
#define GPIO_CRH_MODE9_1 ((u32_t)0x00000020)
#define GPIO_CRH_MODE10 ((u32_t)0x00000300)
#define GPIO_CRH_MODE10_0 ((u32_t)0x00000100)
#define GPIO_CRH_MODE10_1 ((u32_t)0x00000200)
#define GPIO_CRH_MODE11 ((u32_t)0x00003000)
#define GPIO_CRH_MODE11_0 ((u32_t)0x00001000)
#define GPIO_CRH_MODE11_1 ((u32_t)0x00002000)
#define GPIO_CRH_MODE12 ((u32_t)0x00030000)
#define GPIO_CRH_MODE12_0 ((u32_t)0x00010000)
#define GPIO_CRH_MODE12_1 ((u32_t)0x00020000)
#define GPIO_CRH_MODE13 ((u32_t)0x00300000)
#define GPIO_CRH_MODE13_0 ((u32_t)0x00100000)
#define GPIO_CRH_MODE13_1 ((u32_t)0x00200000)
#define GPIO_CRH_MODE14 ((u32_t)0x03000000)
#define GPIO_CRH_MODE14_0 ((u32_t)0x01000000)
#define GPIO_CRH_MODE14_1 ((u32_t)0x02000000)
#define GPIO_CRH_MODE15 ((u32_t)0x30000000)
#define GPIO_CRH_MODE15_0 ((u32_t)0x10000000)
#define GPIO_CRH_MODE15_1 ((u32_t)0x20000000)
#define GPIO_CRH_CNF8 ((u32_t)0x0000000C)
#define GPIO_CRH_CNF8_0 ((u32_t)0x00000004)
#define GPIO_CRH_CNF8_1 ((u32_t)0x00000008)
#define GPIO_CRH_CNF9 ((u32_t)0x000000C0)
#define GPIO_CRH_CNF9_0 ((u32_t)0x00000040)
#define GPIO_CRH_CNF9_1 ((u32_t)0x00000080)
#define GPIO_CRH_CNF10 ((u32_t)0x00000C00)
#define GPIO_CRH_CNF10_0 ((u32_t)0x00000400)
#define GPIO_CRH_CNF10_1 ((u32_t)0x00000800)
#define GPIO_CRH_CNF11 ((u32_t)0x0000C000)
#define GPIO_CRH_CNF11_0 ((u32_t)0x00004000)
#define GPIO_CRH_CNF11_1 ((u32_t)0x00008000)
#define GPIO_CRH_CNF12 ((u32_t)0x000C0000)
#define GPIO_CRH_CNF12_0 ((u32_t)0x00040000)
#define GPIO_CRH_CNF12_1 ((u32_t)0x00080000)
#define GPIO_CRH_CNF13 ((u32_t)0x00C00000)
#define GPIO_CRH_CNF13_0 ((u32_t)0x00400000)
#define GPIO_CRH_CNF13_1 ((u32_t)0x00800000)
#define GPIO_CRH_CNF14 ((u32_t)0x0C000000)
#define GPIO_CRH_CNF14_0 ((u32_t)0x04000000)
#define GPIO_CRH_CNF14_1 ((u32_t)0x08000000)
#define GPIO_CRH_CNF15 ((u32_t)0xC0000000)
#define GPIO_CRH_CNF15_0 ((u32_t)0x40000000)
#define GPIO_CRH_CNF15_1 ((u32_t)0x80000000)

#define GPIO_CRx_ANALOG_INPUT(pin)               ((u32_t)0x0 << (pin << 2))
#define GPIO_CRx_FLOATING_INPUT(pin)             ((u32_t)0x4 << (pin << 2))
#define GPIO_CRx_PULLED_INPUT(pin)               ((u32_t)0x8 << (pin << 2))
#define GPIO_CRx_OUTPUT_10MHz(pin)               ((u32_t)0x1 << (pin << 2))
#define GPIO_CRx_OUTPUT_2MHz(pin)                ((u32_t)0x2 << (pin << 2))
#define GPIO_CRx_OUTPUT_50MHz(pin)               ((u32_t)0x3 << (pin << 2))
#define GPIO_CRx_OPEN_DRAIN_10MHz(pin)           ((u32_t)0x5 << (pin << 2))
#define GPIO_CRx_OPEN_DRAIN_2MHz(pin)            ((u32_t)0x6 << (pin << 2))
#define GPIO_CRx_OPEN_DRAIN_50MHz(pin)           ((u32_t)0x7 << (pin << 2))
#define GPIO_CRx_ALTERNATE_OUTPUT_10MHz(pin)     ((u32_t)0x9 << (pin << 2))
#define GPIO_CRx_ALTERNATE_OUTPUT_2MHz(pin)      ((u32_t)0xA << (pin << 2))
#define GPIO_CRx_ALTERNATE_OUTPUT_50MHz(pin)     ((u32_t)0xB << (pin << 2))
#define GPIO_CRx_ALTERNATE_OPEN_DRAIN_10MHz(pin) ((u32_t)0xD << (pin << 2))
#define GPIO_CRx_ALTERNATE_OPEN_DRAIN_2MHz(pin)  ((u32_t)0xE << (pin << 2))
#define GPIO_CRx_ALTERNATE_OPEN_DRAIN_50MHz(pin) ((u32_t)0xF << (pin << 2))

#define GPIO_IDR_0 ((u32_t)0x00000001)
#define GPIO_IDR_1 ((u32_t)0x00000002)
#define GPIO_IDR_2 ((u32_t)0x00000004)
#define GPIO_IDR_3 ((u32_t)0x00000008)
#define GPIO_IDR_4 ((u32_t)0x00000010)
#define GPIO_IDR_5 ((u32_t)0x00000020)
#define GPIO_IDR_6 ((u32_t)0x00000040)
#define GPIO_IDR_7 ((u32_t)0x00000080)
#define GPIO_IDR_8 ((u32_t)0x00000100)
#define GPIO_IDR_9 ((u32_t)0x00000200)
#define GPIO_IDR_10 ((u32_t)0x00000400)
#define GPIO_IDR_11 ((u32_t)0x00000800)
#define GPIO_IDR_12 ((u32_t)0x00001000)
#define GPIO_IDR_13 ((u32_t)0x00002000)
#define GPIO_IDR_14 ((u32_t)0x00004000)
#define GPIO_IDR_15 ((u32_t)0x00008000)

#define GPIO_ODR_0 ((u32_t)0x00000001)
#define GPIO_ODR_1 ((u32_t)0x00000002)
#define GPIO_ODR_2 ((u32_t)0x00000004)
#define GPIO_ODR_3 ((u32_t)0x00000008)
#define GPIO_ODR_4 ((u32_t)0x00000010)
#define GPIO_ODR_5 ((u32_t)0x00000020)
#define GPIO_ODR_6 ((u32_t)0x00000040)
#define GPIO_ODR_7 ((u32_t)0x00000080)
#define GPIO_ODR_8 ((u32_t)0x00000100)
#define GPIO_ODR_9 ((u32_t)0x00000200)
#define GPIO_ODR_10 ((u32_t)0x00000400)
#define GPIO_ODR_11 ((u32_t)0x00000800)
#define GPIO_ODR_12 ((u32_t)0x00001000)
#define GPIO_ODR_13 ((u32_t)0x00002000)
#define GPIO_ODR_14 ((u32_t)0x00004000)
#define GPIO_ODR_15 ((u32_t)0x00008000)

#define GPIO_BSRR_BS_0 ((u32_t)0x00000001)
#define GPIO_BSRR_BS_1 ((u32_t)0x00000002)
#define GPIO_BSRR_BS_2 ((u32_t)0x00000004)
#define GPIO_BSRR_BS_3 ((u32_t)0x00000008)
#define GPIO_BSRR_BS_4 ((u32_t)0x00000010)
#define GPIO_BSRR_BS_5 ((u32_t)0x00000020)
#define GPIO_BSRR_BS_6 ((u32_t)0x00000040)
#define GPIO_BSRR_BS_7 ((u32_t)0x00000080)
#define GPIO_BSRR_BS_8 ((u32_t)0x00000100)
#define GPIO_BSRR_BS_9 ((u32_t)0x00000200)
#define GPIO_BSRR_BS_10 ((u32_t)0x00000400)
#define GPIO_BSRR_BS_11 ((u32_t)0x00000800)
#define GPIO_BSRR_BS_12 ((u32_t)0x00001000)
#define GPIO_BSRR_BS_13 ((u32_t)0x00002000)
#define GPIO_BSRR_BS_14 ((u32_t)0x00004000)
#define GPIO_BSRR_BS_15 ((u32_t)0x00008000)
#define GPIO_BSRR_BR_0 ((u32_t)0x00010000)
#define GPIO_BSRR_BR_1 ((u32_t)0x00020000)
#define GPIO_BSRR_BR_2 ((u32_t)0x00040000)
#define GPIO_BSRR_BR_3 ((u32_t)0x00080000)
#define GPIO_BSRR_BR_4 ((u32_t)0x00100000)
#define GPIO_BSRR_BR_5 ((u32_t)0x00200000)
#define GPIO_BSRR_BR_6 ((u32_t)0x00400000)
#define GPIO_BSRR_BR_7 ((u32_t)0x00800000)
#define GPIO_BSRR_BR_8 ((u32_t)0x01000000)
#define GPIO_BSRR_BR_9 ((u32_t)0x02000000)
#define GPIO_BSRR_BR_10 ((u32_t)0x04000000)
#define GPIO_BSRR_BR_11 ((u32_t)0x08000000)
#define GPIO_BSRR_BR_12 ((u32_t)0x10000000)
#define GPIO_BSRR_BR_13 ((u32_t)0x20000000)
#define GPIO_BSRR_BR_14 ((u32_t)0x40000000)
#define GPIO_BSRR_BR_15 ((u32_t)0x80000000)

#define GPIO_BRR_BR_0 ((u32_t)0x00000001)
#define GPIO_BRR_BR_1 ((u32_t)0x00000002)
#define GPIO_BRR_BR_2 ((u32_t)0x00000004)
#define GPIO_BRR_BR_3 ((u32_t)0x00000008)
#define GPIO_BRR_BR_4 ((u32_t)0x00000010)
#define GPIO_BRR_BR_5 ((u32_t)0x00000020)
#define GPIO_BRR_BR_6 ((u32_t)0x00000040)
#define GPIO_BRR_BR_7 ((u32_t)0x00000080)
#define GPIO_BRR_BR_8 ((u32_t)0x00000100)
#define GPIO_BRR_BR_9 ((u32_t)0x00000200)
#define GPIO_BRR_BR_10 ((u32_t)0x00000400)
#define GPIO_BRR_BR_11 ((u32_t)0x00000800)
#define GPIO_BRR_BR_12 ((u32_t)0x00001000)
#define GPIO_BRR_BR_13 ((u32_t)0x00002000)
#define GPIO_BRR_BR_14 ((u32_t)0x00004000)
#define GPIO_BRR_BR_15 ((u32_t)0x00008000)

#define GPIO_LCKR_LCK_0 ((u32_t)0x00000001)
#define GPIO_LCKR_LCK_1 ((u32_t)0x00000002)
#define GPIO_LCKR_LCK_2 ((u32_t)0x00000004)
#define GPIO_LCKR_LCK_3 ((u32_t)0x00000008)
#define GPIO_LCKR_LCK_4 ((u32_t)0x00000010)
#define GPIO_LCKR_LCK_5 ((u32_t)0x00000020)
#define GPIO_LCKR_LCK_6 ((u32_t)0x00000040)
#define GPIO_LCKR_LCK_7 ((u32_t)0x00000080)
#define GPIO_LCKR_LCK_8 ((u32_t)0x00000100)
#define GPIO_LCKR_LCK_9 ((u32_t)0x00000200)
#define GPIO_LCKR_LCK_10 ((u32_t)0x00000400)
#define GPIO_LCKR_LCK_11 ((u32_t)0x00000800)
#define GPIO_LCKR_LCK_12 ((u32_t)0x00001000)
#define GPIO_LCKR_LCK_13 ((u32_t)0x00002000)
#define GPIO_LCKR_LCK_14 ((u32_t)0x00004000)
#define GPIO_LCKR_LCK_15 ((u32_t)0x00008000)
#define GPIO_LCKR_LCKK ((u32_t)0x00010000)

#endif
