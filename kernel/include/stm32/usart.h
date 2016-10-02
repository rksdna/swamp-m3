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

#ifndef USART_H
#define USART_H

#include <types.h>

struct usart
{
    volatile u32_t SR;
    volatile u32_t DR;
    volatile u32_t BRR;
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t CR3;
    volatile u32_t GTPR;
};

#define USART1 ((struct usart *)0x40013800)
#define USART2 ((struct usart *)0x40004400)
#define USART3 ((struct usart *)0x40004800)
#define UART4 ((struct usart *)0x40004C00)
#define UART5 ((struct usart *)0x40005000)

#define USART_SR_PE ((u32_t)0x00000001)
#define USART_SR_FE ((u32_t)0x00000002)
#define USART_SR_NE ((u32_t)0x00000004)
#define USART_SR_ORE ((u32_t)0x00000008)
#define USART_SR_IDLE ((u32_t)0x00000010)
#define USART_SR_RXNE ((u32_t)0x00000020)
#define USART_SR_TC ((u32_t)0x00000040)
#define USART_SR_TXE ((u32_t)0x00000080)
#define USART_SR_LBD ((u32_t)0x00000100)
#define USART_SR_CTS ((u32_t)0x00000200)

#define USART_DR_DR ((u32_t)0x000001FF)

#define USART_BRR_DIV ((u32_t)0x0000FFFF)

#define USART_CR1_SBK ((u32_t)0x00000001)
#define USART_CR1_RWU ((u32_t)0x00000002)
#define USART_CR1_RE ((u32_t)0x00000004)
#define USART_CR1_TE ((u32_t)0x00000008)
#define USART_CR1_IDLEIE ((u32_t)0x00000010)
#define USART_CR1_RXNEIE ((u32_t)0x00000020)
#define USART_CR1_TCIE ((u32_t)0x00000040)
#define USART_CR1_TXEIE ((u32_t)0x00000080)
#define USART_CR1_PEIE ((u32_t)0x00000100)
#define USART_CR1_PS ((u32_t)0x00000200)
#define USART_CR1_PCE ((u32_t)0x00000400)
#define USART_CR1_WAKE ((u32_t)0x00000800)
#define USART_CR1_M ((u32_t)0x00001000)
#define USART_CR1_UE ((u32_t)0x00002000)
#define USART_CR1_OVER8 ((u32_t)0x00008000)

#define USART_CR2_ADD ((u32_t)0x0000000F)
#define USART_CR2_LBDL ((u32_t)0x00000020)
#define USART_CR2_LBDIE ((u32_t)0x00000040)
#define USART_CR2_LBCL ((u32_t)0x00000100)
#define USART_CR2_CPHA ((u32_t)0x00000200)
#define USART_CR2_CPOL ((u32_t)0x00000400)
#define USART_CR2_CLKEN ((u32_t)0x00000800)
#define USART_CR2_STOP ((u32_t)0x00003000)
#define USART_CR2_STOP_0 ((u32_t)0x00001000)
#define USART_CR2_STOP_1 ((u32_t)0x00002000)
#define USART_CR2_STOP_ONE ((u32_t)0x00000000)
#define USART_CR2_STOP_HALF ((u32_t)0x00001000)
#define USART_CR2_STOP_TWO ((u32_t)0x00002000)
#define USART_CR2_STOP_ONE_AND_HALF ((u32_t)0x00003000)
#define USART_CR2_LINEN ((u32_t)0x00004000)

#define USART_CR3_EIE ((u32_t)0x00000001)
#define USART_CR3_IREN ((u32_t)0x00000002)
#define USART_CR3_IRLP ((u32_t)0x00000004)
#define USART_CR3_HDSEL ((u32_t)0x00000008)
#define USART_CR3_NACK ((u32_t)0x00000010)
#define USART_CR3_SCEN ((u32_t)0x00000020)
#define USART_CR3_DMAR ((u32_t)0x00000040)
#define USART_CR3_DMAT ((u32_t)0x00000080)
#define USART_CR3_RTSE ((u32_t)0x00000100)
#define USART_CR3_CTSE ((u32_t)0x00000200)
#define USART_CR3_CTSIE ((u32_t)0x00000400)
#define USART_CR3_ONEBIT ((u32_t)0x00000800)

#define USART_GTPR_PSC ((u32_t)0x000000FF)
#define USART_GTPR_GT ((u32_t)0x0000FF00)

#endif
