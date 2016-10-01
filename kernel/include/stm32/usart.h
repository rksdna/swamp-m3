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

#warning "Layout not approved"

#include <types.h>

struct usart
{
    volatile u16_t SR;
    u16_t RESERVED0;
    volatile u16_t DR;
    u16_t RESERVED1;
    volatile u16_t BRR;
    u16_t RESERVED2;
    volatile u16_t CR1;
    u16_t RESERVED3;
    volatile u16_t CR2;
    u16_t RESERVED4;
    volatile u16_t CR3;
    u16_t RESERVED5;
    volatile u16_t GTPR;
    u16_t RESERVED6;
};

#define USART1 ((struct usart *)0x40013800)
#define USART2 ((struct usart *)0x40004400)
#define USART3 ((struct usart *)0x40004800)
#define USART4 ((struct usart *)0x40004C00)
#define USART5 ((struct usart *)0x40005000)

#define USART_SR_PE ((u16_t)0x0001)
#define USART_SR_FE ((u16_t)0x0002)
#define USART_SR_NE ((u16_t)0x0004)
#define USART_SR_ORE ((u16_t)0x0008)
#define USART_SR_IDLE ((u16_t)0x0010)
#define USART_SR_RXNE ((u16_t)0x0020)
#define USART_SR_TC ((u16_t)0x0040)
#define USART_SR_TXE ((u16_t)0x0080)
#define USART_SR_LBD ((u16_t)0x0100)
#define USART_SR_CTS ((u16_t)0x0200)

#define USART_DR_DR ((u16_t)0x01FF)

#define USART_BRR_DIV ((u16_t)0xFFFF)

#define USART_CR1_SBK ((u16_t)0x0001)
#define USART_CR1_RWU ((u16_t)0x0002)
#define USART_CR1_RE ((u16_t)0x0004)
#define USART_CR1_TE ((u16_t)0x0008)
#define USART_CR1_IDLEIE ((u16_t)0x0010)
#define USART_CR1_RXNEIE ((u16_t)0x0020)
#define USART_CR1_TCIE ((u16_t)0x0040)
#define USART_CR1_TXEIE ((u16_t)0x0080)
#define USART_CR1_PEIE ((u16_t)0x0100)
#define USART_CR1_PS ((u16_t)0x0200)
#define USART_CR1_PCE ((u16_t)0x0400)
#define USART_CR1_WAKE ((u16_t)0x0800)
#define USART_CR1_M ((u16_t)0x1000)
#define USART_CR1_UE ((u16_t)0x2000)
#define USART_CR1_OVER8 ((u16_t)0x8000)

#define USART_CR2_ADD ((u16_t)0x000F)
#define USART_CR2_LBDL ((u16_t)0x0020)
#define USART_CR2_LBDIE ((u16_t)0x0040)
#define USART_CR2_LBCL ((u16_t)0x0100)
#define USART_CR2_CPHA ((u16_t)0x0200)
#define USART_CR2_CPOL ((u16_t)0x0400)
#define USART_CR2_CLKEN ((u16_t)0x0800)
#define USART_CR2_STOP ((u16_t)0x3000)
#define USART_CR2_STOP_0 ((u16_t)0x1000)
#define USART_CR2_STOP_1 ((u16_t)0x2000)
#define USART_CR2_LINEN ((u16_t)0x4000)

#define USART_CR3_EIE ((u16_t)0x0001)
#define USART_CR3_IREN ((u16_t)0x0002)
#define USART_CR3_IRLP ((u16_t)0x0004)
#define USART_CR3_HDSEL ((u16_t)0x0008)
#define USART_CR3_NACK ((u16_t)0x0010)
#define USART_CR3_SCEN ((u16_t)0x0020)
#define USART_CR3_DMAR ((u16_t)0x0040)
#define USART_CR3_DMAT ((u16_t)0x0080)
#define USART_CR3_RTSE ((u16_t)0x0100)
#define USART_CR3_CTSE ((u16_t)0x0200)
#define USART_CR3_CTSIE ((u16_t)0x0400)
#define USART_CR3_ONEBIT ((u16_t)0x0800)

#define USART_GTPR_PSC ((u16_t)0x00FF)
#define USART_GTPR_PSC_0 ((u16_t)0x0001)
#define USART_GTPR_PSC_1 ((u16_t)0x0002)
#define USART_GTPR_PSC_2 ((u16_t)0x0004)
#define USART_GTPR_PSC_3 ((u16_t)0x0008)
#define USART_GTPR_PSC_4 ((u16_t)0x0010)
#define USART_GTPR_PSC_5 ((u16_t)0x0020)
#define USART_GTPR_PSC_6 ((u16_t)0x0040)
#define USART_GTPR_PSC_7 ((u16_t)0x0080)
#define USART_GTPR_GT ((u16_t)0xFF00)

#endif
