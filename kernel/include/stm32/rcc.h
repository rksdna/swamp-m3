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

#ifndef RCC_H
#define RCC_H

// WARNING!!!

#include <types.h>

struct rcc
{
    volatile u32_t CR;
    volatile u32_t CFGR;
    volatile u32_t CIR;
    volatile u32_t APB2RSTR;
    volatile u32_t APB1RSTR;
    volatile u32_t AHBENR;
    volatile u32_t APB2ENR;
    volatile u32_t APB1ENR;
    volatile u32_t BDCR;
    volatile u32_t CSR;
    volatile u32_t AHBRSTR;
    volatile u32_t CFGR2;
};

#define RCC ((struct rcc *)0x40021000)

#define RCC_CR_HSION ((u32_t)0x00000001)
#define RCC_CR_HSIRDY ((u32_t)0x00000002)
#define RCC_CR_HSITRIM ((u32_t)0x000000F8)
#define RCC_CR_HSICAL ((u32_t)0x0000FF00)
#define RCC_CR_HSEON ((u32_t)0x00010000)
#define RCC_CR_HSERDY ((u32_t)0x00020000)
#define RCC_CR_HSEBYP ((u32_t)0x00040000)
#define RCC_CR_CSSON ((u32_t)0x00080000)
#define RCC_CR_PLLON ((u32_t)0x01000000)
#define RCC_CR_PLLRDY ((u32_t)0x02000000)
#define RCC_CR_PLL2ON ((u32_t)0x04000000)
#define RCC_CR_PLL2RDY ((u32_t)0x08000000)
#define RCC_CR_PLL3ON ((u32_t)0x10000000)
#define RCC_CR_PLL3RDY ((u32_t)0x20000000)

#define RCC_CFGR_SW ((u32_t)0x00000003)
#define RCC_CFGR_SW_0 ((u32_t)0x00000001)
#define RCC_CFGR_SW_1 ((u32_t)0x00000002)
#define RCC_CFGR_SW_HSI ((u32_t)0x00000000)
#define RCC_CFGR_SW_HSE ((u32_t)0x00000001)
#define RCC_CFGR_SW_PLL ((u32_t)0x00000002)
#define RCC_CFGR_SWS ((u32_t)0x0000000C)
#define RCC_CFGR_SWS_0 ((u32_t)0x00000004)
#define RCC_CFGR_SWS_1 ((u32_t)0x00000008)
#define RCC_CFGR_SWS_HSI ((u32_t)0x00000000)
#define RCC_CFGR_SWS_HSE ((u32_t)0x00000004)
#define RCC_CFGR_SWS_PLL ((u32_t)0x00000008)
#define RCC_CFGR_HPRE ((u32_t)0x000000F0)
#define RCC_CFGR_HPRE_0 ((u32_t)0x00000010)
#define RCC_CFGR_HPRE_1 ((u32_t)0x00000020)
#define RCC_CFGR_HPRE_2 ((u32_t)0x00000040)
#define RCC_CFGR_HPRE_3 ((u32_t)0x00000080)
#define RCC_CFGR_HPRE_DIV1 ((u32_t)0x00000000)
#define RCC_CFGR_HPRE_DIV2 ((u32_t)0x00000080)
#define RCC_CFGR_HPRE_DIV4 ((u32_t)0x00000090)
#define RCC_CFGR_HPRE_DIV8 ((u32_t)0x000000A0)
#define RCC_CFGR_HPRE_DIV16 ((u32_t)0x000000B0)
#define RCC_CFGR_HPRE_DIV64 ((u32_t)0x000000C0)
#define RCC_CFGR_HPRE_DIV128 ((u32_t)0x000000D0)
#define RCC_CFGR_HPRE_DIV256 ((u32_t)0x000000E0)
#define RCC_CFGR_HPRE_DIV512 ((u32_t)0x000000F0)
#define RCC_CFGR_PPRE1 ((u32_t)0x00000700)
#define RCC_CFGR_PPRE1_0 ((u32_t)0x00000100)
#define RCC_CFGR_PPRE1_1 ((u32_t)0x00000200)
#define RCC_CFGR_PPRE1_2 ((u32_t)0x00000400)
#define RCC_CFGR_PPRE1_DIV1 ((u32_t)0x00000000)
#define RCC_CFGR_PPRE1_DIV2 ((u32_t)0x00000400)
#define RCC_CFGR_PPRE1_DIV4 ((u32_t)0x00000500)
#define RCC_CFGR_PPRE1_DIV8 ((u32_t)0x00000600)
#define RCC_CFGR_PPRE1_DIV16 ((u32_t)0x00000700)
#define RCC_CFGR_PPRE2 ((u32_t)0x00003800)
#define RCC_CFGR_PPRE2_0 ((u32_t)0x00000800)
#define RCC_CFGR_PPRE2_1 ((u32_t)0x00001000)
#define RCC_CFGR_PPRE2_2 ((u32_t)0x00002000)
#define RCC_CFGR_PPRE2_DIV1 ((u32_t)0x00000000)
#define RCC_CFGR_PPRE2_DIV2 ((u32_t)0x00002000)
#define RCC_CFGR_PPRE2_DIV4 ((u32_t)0x00002800)
#define RCC_CFGR_PPRE2_DIV8 ((u32_t)0x00003000)
#define RCC_CFGR_PPRE2_DIV16 ((u32_t)0x00003800)
#define RCC_CFGR_ADCPRE ((u32_t)0x0000C000)
#define RCC_CFGR_ADCPRE_0 ((u32_t)0x00004000)
#define RCC_CFGR_ADCPRE_1 ((u32_t)0x00008000)
#define RCC_CFGR_ADCPRE_DIV2 ((u32_t)0x00000000)
#define RCC_CFGR_ADCPRE_DIV4 ((u32_t)0x00004000)
#define RCC_CFGR_ADCPRE_DIV6 ((u32_t)0x00008000)
#define RCC_CFGR_ADCPRE_DIV8 ((u32_t)0x0000C000)
#define RCC_CFGR_PLLSRC ((u32_t)0x00010000)
#define RCC_CFGR_PLLXTPRE ((u32_t)0x00020000)
#define RCC_CFGR_PLLMULL ((u32_t)0x003C0000)
#define RCC_CFGR_PLLMULL_0 ((u32_t)0x00040000)
#define RCC_CFGR_PLLMULL_1 ((u32_t)0x00080000)
#define RCC_CFGR_PLLMULL_2 ((u32_t)0x00100000)
#define RCC_CFGR_PLLMULL_3 ((u32_t)0x00200000)

#define RCC_CFGR_PLLSRC_HSI_DIV2 ((u32_t)0x00000000)
#define RCC_CFGR_PLLSRC_PREDIV1 ((u32_t)0x00010000)
#define RCC_CFGR_PLLSRC_HSE ((u32_t)0x00010000)
#define RCC_CFGR_PLLXTPRE_PREDIV1 ((u32_t)0x00000000)
#define RCC_CFGR_PLLXTPRE_HSE ((u32_t)0x00000000)
#define RCC_CFGR_PLLXTPRE_PREDIV1_DIV2 ((u32_t)0x00020000)
#define RCC_CFGR_PLLXTPRE_HSE_DIV2 ((u32_t)0x00020000)
#define RCC_CFGR_PLLMULL_MUL2 ((u32_t)0x00000000)
#define RCC_CFGR_PLLMULL_MUL3 ((u32_t)0x00040000)
#define RCC_CFGR_PLLMULL_MUL4 ((u32_t)0x00080000)
#define RCC_CFGR_PLLMULL_MUL5 ((u32_t)0x000C0000)
#define RCC_CFGR_PLLMULL_MUL6 ((u32_t)0x00100000)
#define RCC_CFGR_PLLMULL_MUL7 ((u32_t)0x00140000)
#define RCC_CFGR_PLLMULL_MUL8 ((u32_t)0x00180000)
#define RCC_CFGR_PLLMULL_MUL9 ((u32_t)0x001C0000)
#define RCC_CFGR_PLLMULL_MUL10 ((u32_t)0x00200000)
#define RCC_CFGR_PLLMULL_MUL11 ((u32_t)0x00240000)
#define RCC_CFGR_PLLMULL_MUL12 ((u32_t)0x00280000)
#define RCC_CFGR_PLLMULL_MUL13 ((u32_t)0x002C0000)
#define RCC_CFGR_PLLMULL_MUL14 ((u32_t)0x00300000)
#define RCC_CFGR_PLLMULL_MUL6_5 ((u32_t)0x00340000)
#define RCC_CFGR_PLLMULL_MUL15 ((u32_t)0x00340000)
#define RCC_CFGR_PLLMULL_MUL16 ((u32_t)0x00380000)
#define RCC_CFGR_USBPRE ((u32_t)0x00400000)
#define RCC_CFGR_OTGFSPRE ((u32_t)0x00400000)
#define RCC_CFGR_MCO ((u32_t)0x0F000000)
#define RCC_CFGR_MCO_0 ((u32_t)0x01000000)
#define RCC_CFGR_MCO_1 ((u32_t)0x02000000)
#define RCC_CFGR_MCO_2 ((u32_t)0x04000000)
#define RCC_CFGR_MCO_3 ((u32_t)0x08000000)
#define RCC_CFGR_MCO_NOCLOCK ((u32_t)0x00000000)
#define RCC_CFGR_MCO_SYSCLK ((u32_t)0x04000000)
#define RCC_CFGR_MCO_HSI ((u32_t)0x05000000)
#define RCC_CFGR_MCO_HSE ((u32_t)0x06000000)
#define RCC_CFGR_MCO_PLL ((u32_t)0x07000000)
#define RCC_CFGR_MCO_PLLCLK_DIV2 ((u32_t)0x07000000)
#define RCC_CFGR_MCO_PLL2CLK ((u32_t)0x08000000)
#define RCC_CFGR_MCO_PLL3CLK_DIV2 ((u32_t)0x09000000)
#define RCC_CFGR_MCO_EXT_HSE ((u32_t)0x0A000000)
#define RCC_CFGR_MCO_PLL3CLK ((u32_t)0x0B000000)

#define RCC_CIR_LSIRDYF ((u32_t)0x00000001)
#define RCC_CIR_LSERDYF ((u32_t)0x00000002)
#define RCC_CIR_HSIRDYF ((u32_t)0x00000004)
#define RCC_CIR_HSERDYF ((u32_t)0x00000008)
#define RCC_CIR_PLLRDYF ((u32_t)0x00000010)
#define RCC_CIR_PLL2RDYF ((u32_t)0x00000020)
#define RCC_CIR_PLL3RDYF ((u32_t)0x00000040)
#define RCC_CIR_CSSF ((u32_t)0x00000080)
#define RCC_CIR_LSIRDYIE ((u32_t)0x00000100)
#define RCC_CIR_LSERDYIE ((u32_t)0x00000200)
#define RCC_CIR_HSIRDYIE ((u32_t)0x00000400)
#define RCC_CIR_HSERDYIE ((u32_t)0x00000800)
#define RCC_CIR_PLLRDYIE ((u32_t)0x00001000)
#define RCC_CIR_PLL2RDYIE ((u32_t)0x00002000)
#define RCC_CIR_PLL3RDYIE ((u32_t)0x00004000)
#define RCC_CIR_LSIRDYC ((u32_t)0x00010000)
#define RCC_CIR_LSERDYC ((u32_t)0x00020000)
#define RCC_CIR_HSIRDYC ((u32_t)0x00040000)
#define RCC_CIR_HSERDYC ((u32_t)0x00080000)
#define RCC_CIR_PLLRDYC ((u32_t)0x00100000)
#define RCC_CIR_PLL2RDYC ((u32_t)0x00200000)
#define RCC_CIR_PLL3RDYC ((u32_t)0x00400000)
#define RCC_CIR_CSSC ((u32_t)0x00800000)

#define RCC_APB2RSTR_AFIORST ((u32_t)0x00000001)
#define RCC_APB2RSTR_IOPARST ((u32_t)0x00000004)
#define RCC_APB2RSTR_IOPBRST ((u32_t)0x00000008)
#define RCC_APB2RSTR_IOPCRST ((u32_t)0x00000010)
#define RCC_APB2RSTR_IOPDRST ((u32_t)0x00000020)
#define RCC_APB2RSTR_IOPERST ((u32_t)0x00000040)
#define RCC_APB2RSTR_IOPFRST ((u32_t)0x00000080)
#define RCC_APB2RSTR_IOPGRST ((u32_t)0x00000100)
#define RCC_APB2RSTR_ADC1RST ((u32_t)0x00000200)
#define RCC_APB2RSTR_ADC2RST ((u32_t)0x00000400)
#define RCC_APB2RSTR_TIM1RST ((u32_t)0x00000800)
#define RCC_APB2RSTR_SPI1RST ((u32_t)0x00001000)
#define RCC_APB2RSTR_TIM8RST ((u32_t)0x00002000)
#define RCC_APB2RSTR_USART1RST ((u32_t)0x00004000)
#define RCC_APB2RSTR_ADC3RST ((u32_t)0x00008000)
#define RCC_APB2RSTR_TIM9RST ((u32_t)0x00080000)
#define RCC_APB2RSTR_TIM10RST ((u32_t)0x00100000)
#define RCC_APB2RSTR_TIM11RST ((u32_t)0x00200000)

#define RCC_APB2ENR_AFIOEN ((u32_t)0x00000001)
#define RCC_APB2ENR_IOPAEN ((u32_t)0x00000004)
#define RCC_APB2ENR_IOPBEN ((u32_t)0x00000008)
#define RCC_APB2ENR_IOPCEN ((u32_t)0x00000010)
#define RCC_APB2ENR_IOPDEN ((u32_t)0x00000020)
#define RCC_APB2ENR_IOPEEN ((u32_t)0x00000040)
#define RCC_APB2ENR_IOPFEN ((u32_t)0x00000080)
#define RCC_APB2ENR_IOPGEN ((u32_t)0x00000100)
#define RCC_APB2ENR_ADC1EN ((u32_t)0x00000200)
#define RCC_APB2ENR_ADC2EN ((u32_t)0x00000400)
#define RCC_APB2ENR_TIM1EN ((u32_t)0x00000800)
#define RCC_APB2ENR_SPI1EN ((u32_t)0x00001000)
#define RCC_APB2ENR_TIM8EN ((u32_t)0x00002000)
#define RCC_APB2ENR_USART1EN ((u32_t)0x00004000)
#define RCC_APB2ENR_ADC3EN ((u32_t)0x00008000)
#define RCC_APB2ENR_TIM9EN ((u32_t)0x00080000)
#define RCC_APB2ENR_TIM10EN ((u32_t)0x00100000)
#define RCC_APB2ENR_TIM11EN ((u32_t)0x00200000)

#define RCC_APB1RSTR_TIM2RST ((u32_t)0x00000001)
#define RCC_APB1RSTR_TIM3RST ((u32_t)0x00000002)
#define RCC_APB1RSTR_TIM4RST ((u32_t)0x00000004)
#define RCC_APB1RSTR_TIM5RST ((u32_t)0x00000008)
#define RCC_APB1RSTR_TIM6RST ((u32_t)0x00000010)
#define RCC_APB1RSTR_TIM7RST ((u32_t)0x00000020)
#define RCC_APB1RSTR_TIM12RST ((u32_t)0x00000040)
#define RCC_APB1RSTR_TIM13RST ((u32_t)0x00000080)
#define RCC_APB1RSTR_TIM14RST ((u32_t)0x00000100)
#define RCC_APB1RSTR_WWDGRST ((u32_t)0x00000800)
#define RCC_APB1RSTR_SPI2RST ((u32_t)0x00004000)
#define RCC_APB1RSTR_SPI3RST ((u32_t)0x00008000)
#define RCC_APB1RSTR_USART2RST ((u32_t)0x00020000)
#define RCC_APB1RSTR_USART3RST ((u32_t)0x00040000)
#define RCC_APB1RSTR_UART4RST ((u32_t)0x00080000)
#define RCC_APB1RSTR_UART5RST ((u32_t)0x00100000)
#define RCC_APB1RSTR_I2C1RST ((u32_t)0x00200000)
#define RCC_APB1RSTR_I2C2RST ((u32_t)0x00400000)
#define RCC_APB1RSTR_CAN1RST ((u32_t)0x02000000)
#define RCC_APB1RSTR_CAN2RST ((u32_t)0x04000000)
#define RCC_APB1RSTR_USBRST ((u32_t)0x00800000)
#define RCC_APB1RSTR_BKPRST ((u32_t)0x08000000)
#define RCC_APB1RSTR_PWRRST ((u32_t)0x10000000)
#define RCC_APB1RSTR_DACRST ((u32_t)0x20000000)

#define RCC_APB1ENR_TIM2EN ((u32_t)0x00000001)
#define RCC_APB1ENR_TIM3EN ((u32_t)0x00000002)
#define RCC_APB1ENR_TIM4EN ((u32_t)0x00000004)
#define RCC_APB1ENR_TIM5EN ((u32_t)0x00000008)
#define RCC_APB1ENR_TIM6EN ((u32_t)0x00000010)
#define RCC_APB1ENR_TIM7EN ((u32_t)0x00000020)
#define RCC_APB1ENR_TIM12EN ((u32_t)0x00000040)
#define RCC_APB1ENR_TIM13EN ((u32_t)0x00000080)
#define RCC_APB1ENR_TIM14EN ((u32_t)0x00000100)
#define RCC_APB1ENR_WWDGEN ((u32_t)0x00000800)
#define RCC_APB1ENR_SPI2EN ((u32_t)0x00004000)
#define RCC_APB1ENR_SPI3EN ((u32_t)0x00008000)
#define RCC_APB1ENR_USART2EN ((u32_t)0x00020000)
#define RCC_APB1ENR_USART3EN ((u32_t)0x00040000)
#define RCC_APB1ENR_UART4EN ((u32_t)0x00080000)
#define RCC_APB1ENR_UART5EN ((u32_t)0x00100000)
#define RCC_APB1ENR_I2C1EN ((u32_t)0x00200000)
#define RCC_APB1ENR_I2C2EN ((u32_t)0x00400000)
#define RCC_APB1ENR_CAN1EN ((u32_t)0x02000000)
#define RCC_APB1ENR_CAN2EN ((u32_t)0x04000000)
#define RCC_APB1ENR_USBEN ((u32_t)0x00800000)
#define RCC_APB1ENR_BKPEN ((u32_t)0x08000000)
#define RCC_APB1ENR_PWREN ((u32_t)0x10000000)
#define RCC_APB1ENR_DACEN ((u32_t)0x20000000)

#define RCC_AHBRSTR_OTGFSRST ((u32_t)0x00001000)
#define RCC_AHBRSTR_ETHMACRST ((u32_t)0x00004000)

#define RCC_AHBENR_DMA1EN ((u32_t)0x00000001)
#define RCC_AHBENR_DMA2EN ((u32_t)0x00000002)
#define RCC_AHBENR_SRAMEN ((u32_t)0x00000004)
#define RCC_AHBENR_FLITFEN ((u32_t)0x00000010)
#define RCC_AHBENR_CRCEN ((u32_t)0x00000040)
#define RCC_AHBENR_FSMCEN ((u32_t)0x00000100)
#define RCC_AHBENR_SDIOEN ((u32_t)0x00000400)
#define RCC_AHBENR_OTGFSEN ((u32_t)0x00001000)
#define RCC_AHBENR_ETHMACEN ((u32_t)0x00004000)
#define RCC_AHBENR_ETHMACTXEN ((u32_t)0x00008000)
#define RCC_AHBENR_ETHMACRXEN ((u32_t)0x00010000)

#define RCC_BDCR_LSEON ((u32_t)0x00000001)
#define RCC_BDCR_LSERDY ((u32_t)0x00000002)
#define RCC_BDCR_LSEBYP ((u32_t)0x00000004)
#define RCC_BDCR_RTCSEL ((u32_t)0x00000300)
#define RCC_BDCR_RTCSEL_0 ((u32_t)0x00000100)
#define RCC_BDCR_RTCSEL_1 ((u32_t)0x00000200)
#define RCC_BDCR_RTCSEL_NOCLOCK ((u32_t)0x00000000)
#define RCC_BDCR_RTCSEL_LSE ((u32_t)0x00000100)
#define RCC_BDCR_RTCSEL_LSI ((u32_t)0x00000200)
#define RCC_BDCR_RTCSEL_HSE ((u32_t)0x00000300)
#define RCC_BDCR_RTCEN ((u32_t)0x00008000)
#define RCC_BDCR_BDRST ((u32_t)0x00010000)

#define RCC_CSR_LSION ((u32_t)0x00000001)
#define RCC_CSR_LSIRDY ((u32_t)0x00000002)
#define RCC_CSR_RMVF ((u32_t)0x01000000)
#define RCC_CSR_PINRSTF ((u32_t)0x04000000)
#define RCC_CSR_PORRSTF ((u32_t)0x08000000)
#define RCC_CSR_SFTRSTF ((u32_t)0x10000000)
#define RCC_CSR_IWDGRSTF ((u32_t)0x20000000)
#define RCC_CSR_WWDGRSTF ((u32_t)0x40000000)
#define RCC_CSR_LPWRRSTF ((u32_t)0x80000000)

#define RCC_CFGR2_PREDIV1 ((u32_t)0x0000000F)
#define RCC_CFGR2_PREDIV1_0 ((u32_t)0x00000001)
#define RCC_CFGR2_PREDIV1_1 ((u32_t)0x00000002)
#define RCC_CFGR2_PREDIV1_2 ((u32_t)0x00000004)
#define RCC_CFGR2_PREDIV1_3 ((u32_t)0x00000008)
#define RCC_CFGR2_PREDIV1_DIV1 ((u32_t)0x00000000)
#define RCC_CFGR2_PREDIV1_DIV2 ((u32_t)0x00000001)
#define RCC_CFGR2_PREDIV1_DIV3 ((u32_t)0x00000002)
#define RCC_CFGR2_PREDIV1_DIV4 ((u32_t)0x00000003)
#define RCC_CFGR2_PREDIV1_DIV5 ((u32_t)0x00000004)
#define RCC_CFGR2_PREDIV1_DIV6 ((u32_t)0x00000005)
#define RCC_CFGR2_PREDIV1_DIV7 ((u32_t)0x00000006)
#define RCC_CFGR2_PREDIV1_DIV8 ((u32_t)0x00000007)
#define RCC_CFGR2_PREDIV1_DIV9 ((u32_t)0x00000008)
#define RCC_CFGR2_PREDIV1_DIV10 ((u32_t)0x00000009)
#define RCC_CFGR2_PREDIV1_DIV11 ((u32_t)0x0000000A)
#define RCC_CFGR2_PREDIV1_DIV12 ((u32_t)0x0000000B)
#define RCC_CFGR2_PREDIV1_DIV13 ((u32_t)0x0000000C)
#define RCC_CFGR2_PREDIV1_DIV14 ((u32_t)0x0000000D)
#define RCC_CFGR2_PREDIV1_DIV15 ((u32_t)0x0000000E)
#define RCC_CFGR2_PREDIV1_DIV16 ((u32_t)0x0000000F)
#define RCC_CFGR2_PREDIV2 ((u32_t)0x000000F0)
#define RCC_CFGR2_PREDIV2_0 ((u32_t)0x00000010)
#define RCC_CFGR2_PREDIV2_1 ((u32_t)0x00000020)
#define RCC_CFGR2_PREDIV2_2 ((u32_t)0x00000040)
#define RCC_CFGR2_PREDIV2_3 ((u32_t)0x00000080)
#define RCC_CFGR2_PREDIV2_DIV1 ((u32_t)0x00000000)
#define RCC_CFGR2_PREDIV2_DIV2 ((u32_t)0x00000010)
#define RCC_CFGR2_PREDIV2_DIV3 ((u32_t)0x00000020)
#define RCC_CFGR2_PREDIV2_DIV4 ((u32_t)0x00000030)
#define RCC_CFGR2_PREDIV2_DIV5 ((u32_t)0x00000040)
#define RCC_CFGR2_PREDIV2_DIV6 ((u32_t)0x00000050)
#define RCC_CFGR2_PREDIV2_DIV7 ((u32_t)0x00000060)
#define RCC_CFGR2_PREDIV2_DIV8 ((u32_t)0x00000070)
#define RCC_CFGR2_PREDIV2_DIV9 ((u32_t)0x00000080)
#define RCC_CFGR2_PREDIV2_DIV10 ((u32_t)0x00000090)
#define RCC_CFGR2_PREDIV2_DIV11 ((u32_t)0x000000A0)
#define RCC_CFGR2_PREDIV2_DIV12 ((u32_t)0x000000B0)
#define RCC_CFGR2_PREDIV2_DIV13 ((u32_t)0x000000C0)
#define RCC_CFGR2_PREDIV2_DIV14 ((u32_t)0x000000D0)
#define RCC_CFGR2_PREDIV2_DIV15 ((u32_t)0x000000E0)
#define RCC_CFGR2_PREDIV2_DIV16 ((u32_t)0x000000F0)
#define RCC_CFGR2_PLL2MUL ((u32_t)0x00000F00)
#define RCC_CFGR2_PLL2MUL_0 ((u32_t)0x00000100)
#define RCC_CFGR2_PLL2MUL_1 ((u32_t)0x00000200)
#define RCC_CFGR2_PLL2MUL_2 ((u32_t)0x00000400)
#define RCC_CFGR2_PLL2MUL_3 ((u32_t)0x00000800)
#define RCC_CFGR2_PLL2MUL_MUL8 ((u32_t)0x00000600)
#define RCC_CFGR2_PLL2MUL_MUL9 ((u32_t)0x00000700)
#define RCC_CFGR2_PLL2MUL_MUL10 ((u32_t)0x00000800)
#define RCC_CFGR2_PLL2MUL_MUL11 ((u32_t)0x00000900)
#define RCC_CFGR2_PLL2MUL_MUL12 ((u32_t)0x00000A00)
#define RCC_CFGR2_PLL2MUL_MUL13 ((u32_t)0x00000B00)
#define RCC_CFGR2_PLL2MUL_MUL14 ((u32_t)0x00000C00)
#define RCC_CFGR2_PLL2MUL_MUL16 ((u32_t)0x00000E00)
#define RCC_CFGR2_PLL2MUL_MUL20 ((u32_t)0x00000F00)
#define RCC_CFGR2_PLL3MUL ((u32_t)0x0000F000)
#define RCC_CFGR2_PLL3MUL_0 ((u32_t)0x00001000)
#define RCC_CFGR2_PLL3MUL_1 ((u32_t)0x00002000)
#define RCC_CFGR2_PLL3MUL_2 ((u32_t)0x00004000)
#define RCC_CFGR2_PLL3MUL_3 ((u32_t)0x00008000)
#define RCC_CFGR2_PLL3MUL_MUL8 ((u32_t)0x00006000)
#define RCC_CFGR2_PLL3MUL_MUL9 ((u32_t)0x00007000)
#define RCC_CFGR2_PLL3MUL_MUL10 ((u32_t)0x00008000)
#define RCC_CFGR2_PLL3MUL_MUL11 ((u32_t)0x00009000)
#define RCC_CFGR2_PLL3MUL_MUL12 ((u32_t)0x0000A000)
#define RCC_CFGR2_PLL3MUL_MUL13 ((u32_t)0x0000B000)
#define RCC_CFGR2_PLL3MUL_MUL14 ((u32_t)0x0000C000)
#define RCC_CFGR2_PLL3MUL_MUL16 ((u32_t)0x0000E000)
#define RCC_CFGR2_PLL3MUL_MUL20 ((u32_t)0x0000F000)
#define RCC_CFGR2_PREDIV1SRC ((u32_t)0x00010000)
#define RCC_CFGR2_PREDIV1SRC_PLL2 ((u32_t)0x00010000)
#define RCC_CFGR2_PREDIV1SRC_HSE ((u32_t)0x00000000)
#define RCC_CFGR2_I2S2SRC ((u32_t)0x00020000)
#define RCC_CFGR2_I2S3SRC ((u32_t)0x00040000)

#endif