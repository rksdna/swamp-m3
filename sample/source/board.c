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

#include <stm32/flash.h>
#include <stm32/usart.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <stm32/des.h>
#include <stm32/afio.h>
#include <threads.h>
#include <timers.h>
#include <debug.h>
#include <tools.h>
#include "board.h"

static void debug_put(void *data, char value)
{
    while (~USART1->SR & USART_SR_TXE)
        continue;

    USART1->DR = value;
}

struct stream debug_stream = {debug_put, 0};

void startup_board_103(void)
{
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_72MHz;

    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_MUL9 | RCC_CFGR_PPRE1_2;
    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON;
    wait_for(&RCC->CR, RCC_CR_HSERDY, RCC_CR_HSERDY);

    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON | RCC_CR_PLLON | RCC_CR_CSSON;
    wait_for(&RCC->CR, RCC_CR_PLLRDY, RCC_CR_PLLRDY);

    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_MUL9 | RCC_CFGR_PPRE1_2 | RCC_CFGR_SW_PLL;

    RCC->APB1ENR = RCC_APB1ENR_USBEN;
    RCC->APB2ENR = RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;

    GPIOA->CRL = GPIO_CRL_GPO_PP(0) | GPIO_CRL_GPI_PU(1) | GPIO_CRL_GPI_PU(2) | GPIO_CRL_GPI_PU(3) | GPIO_CRL_GPI_PU(4) | GPIO_CRL_GPI_PU(5) | GPIO_CRL_GPI_PU(6) | GPIO_CRL_GPI_PU(7);
    GPIOA->CRH = GPIO_CRH_GPI_PU(8) | GPIO_CRH_AFO_PP(9) | GPIO_CRH_GPI_PU(10) | GPIO_CRH_AFO_PP_F(11) | GPIO_CRH_AFO_PP_F(12) | GPIO_CRH_GPI_PU(13) | GPIO_CRH_GPI_PU(14) | GPIO_CRH_GPI_PU(15);

    USART1->CR1 = USART_CR1_UE;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_PCE | USART_CR1_M;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = 625;

    start_timers_clock(72000);

    debug("hello\n");
}

void board_usb_pullup(u32_t state)
{
    GPIOA->BSRR = state ? GPIO_BSRR_BS0 : GPIO_BSRR_BR0;
}

void startup_board_107(void)
{
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_72MHz;

    RCC->CFGR2 = RCC_CFGR2_PREDIV1_DIV2;
    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_3 | RCC_CFGR_PLLXTPRE | RCC_CFGR_PPRE1_2;
    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON;
    wait_for(&RCC->CR, RCC_CR_HSERDY, RCC_CR_HSERDY);

    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON | RCC_CR_PLLON | RCC_CR_CSSON;
    wait_for(&RCC->CR, RCC_CR_PLLRDY, RCC_CR_PLLRDY);

    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_3 | RCC_CFGR_PLLXTPRE | RCC_CFGR_PPRE1_2 | RCC_CFGR_SW_PLL;
    RCC->CSR = RCC_CSR_RMVF | RCC_CSR_LSION;

    RCC->AHBENR = RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN | RCC_AHBENR_ETHMACEN | RCC_AHBENR_ETHMACRXEN | RCC_AHBENR_ETHMACTXEN;
    RCC->APB2ENR = RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_USART1EN;

    AFIO->MAPR = AFIO_MAPR_SWJ_CFG_2;

    GPIOA->CRL = GPIO_CRL_GPI_PU(0) | GPIO_CRL_GPI_PU(1) | GPIO_CRL_AFO_PP_F(2) | GPIO_CRL_GPI_PU(3) | GPIO_CRL_GPI_PU(4) | GPIO_CRL_GPI_PU(5) | GPIO_CRL_GPI_PU(6) | GPIO_CRL_GPI_PU(7);
    GPIOA->CRH = GPIO_CRH_GPI_PU(8) | GPIO_CRH_AFO_PP(9) | GPIO_CRH_GPI_PU(10) | GPIO_CRH_GPI_PU(11) | GPIO_CRH_GPI_PU(12) | GPIO_CRH_GPI_PU(13) | GPIO_CRH_GPI_PU(14) | GPIO_CRH_GPI_PU(15);

    GPIOB->CRL = GPIO_CRL_GPI_PU(0) | GPIO_CRL_GPI_PU(1) | GPIO_CRL_GPI_PU(2) | GPIO_CRL_GPI_PU(3) | GPIO_CRL_GPI_PU(4) | GPIO_CRL_GPI_PU(5) | GPIO_CRL_GPI_PU(6) | GPIO_CRL_GPI_PU(7);
    GPIOB->CRH = GPIO_CRH_AFO_PP_F(8) | GPIO_CRH_GPI_PU(9) | GPIO_CRH_GPI_PU(10) | GPIO_CRH_AFO_PP_F(11) | GPIO_CRH_AFO_PP_F(12) | GPIO_CRH_AFO_PP_F(13) | GPIO_CRH_GPI_PU(14) | GPIO_CRH_GPI_PU(15);

    GPIOC->CRL = GPIO_CRL_GPO_PP_F(0) | GPIO_CRL_AFO_PP_F(1) | GPIO_CRL_AFO_PP_F(2) | GPIO_CRL_GPI_PU(3) | GPIO_CRL_GPI_PU(4) | GPIO_CRL_GPI_PU(5) | GPIO_CRL_GPI_PU(6) | GPIO_CRL_GPI_PU(7);
    GPIOC->CRH = GPIO_CRH_GPI_PU(8) | GPIO_CRH_GPI_PU(9) | GPIO_CRH_GPI_PU(10) | GPIO_CRH_GPI_PU(11) | GPIO_CRH_GPI_PU(12) | GPIO_CRH_GPI_PU(13) | GPIO_CRH_GPI_PU(14) | GPIO_CRH_GPI_PU(15);

    USART1->CR1 = USART_CR1_UE;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_PCE | USART_CR1_M;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = 434;

    start_timers_clock(50000);

    debug("hello\n");
}

void board_phy_reset(u32_t state)
{
    GPIOC->BSRR = state ? GPIO_BSRR_BR0 : GPIO_BSRR_BS0;
}

void board_info(void)
{
    debug("id: %*m flash: %dKbytes\n", sizeof(DES->ID), DES->ID, DES->FSIZE & DES_FSIZE_FSIZE);
}
