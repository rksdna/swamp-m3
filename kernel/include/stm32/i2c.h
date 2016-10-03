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

#ifndef I2C_H
#define I2C_H

#include <types.h>

struct i2c
{
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t OAR1;
    volatile u32_t OAR2;
    volatile u32_t DR;
    volatile u32_t SR1;
    volatile u32_t SR2;
    volatile u32_t CCR;
    volatile u32_t TRISE;
};

#define I2C1 ((struct i2c *)0x40005400)
#define I2C2 ((struct i2c *)0x40005800)

#define I2C_CR1_PE ((u32_t)0x00000001)
#define I2C_CR1_SMBUS ((u32_t)0x00000002)
#define I2C_CR1_SMBTYPE ((u32_t)0x00000008)
#define I2C_CR1_ENARP ((u32_t)0x00000010)
#define I2C_CR1_ENPEC ((u32_t)0x00000020)
#define I2C_CR1_ENGC ((u32_t)0x00000040)
#define I2C_CR1_NOSTRETCH ((u32_t)0x00000080)
#define I2C_CR1_START ((u32_t)0x00000100)
#define I2C_CR1_STOP ((u32_t)0x00000200)
#define I2C_CR1_ACK ((u32_t)0x00000400)
#define I2C_CR1_POS ((u32_t)0x00000800)
#define I2C_CR1_PEC ((u32_t)0x00001000)
#define I2C_CR1_ALERT ((u32_t)0x00002000)
#define I2C_CR1_SWRST ((u32_t)0x00008000)

#define I2C_CR2_FREQ ((u32_t)0x0000003F)
#define I2C_CR2_FREQ_0 ((u32_t)0x00000001)
#define I2C_CR2_FREQ_1 ((u32_t)0x00000002)
#define I2C_CR2_FREQ_2 ((u32_t)0x00000004)
#define I2C_CR2_FREQ_3 ((u32_t)0x00000008)
#define I2C_CR2_FREQ_4 ((u32_t)0x00000010)
#define I2C_CR2_FREQ_5 ((u32_t)0x00000020)
#define I2C_CR2_ITERREN ((u32_t)0x00000100)
#define I2C_CR2_ITEVTEN ((u32_t)0x00000200)
#define I2C_CR2_ITBUFEN ((u32_t)0x00000400)
#define I2C_CR2_DMAEN ((u32_t)0x00000800)
#define I2C_CR2_LAST ((u32_t)0x00001000)

#define I2C_OAR1_ADD ((u32_t)0x000003FF)
#define I2C_OAR1_ADD0 ((u32_t)0x00000001)
#define I2C_OAR1_ADD1 ((u32_t)0x00000002)
#define I2C_OAR1_ADD2 ((u32_t)0x00000004)
#define I2C_OAR1_ADD3 ((u32_t)0x00000008)
#define I2C_OAR1_ADD4 ((u32_t)0x00000010)
#define I2C_OAR1_ADD5 ((u32_t)0x00000020)
#define I2C_OAR1_ADD6 ((u32_t)0x00000040)
#define I2C_OAR1_ADD7 ((u32_t)0x00000080)
#define I2C_OAR1_ADD8 ((u32_t)0x00000100)
#define I2C_OAR1_ADD9 ((u32_t)0x00000200)
#define I2C_OAR1_ADDMODE ((u32_t)0x00008000)

#define I2C_OAR2_ENDUAL ((u32_t)0x00000001)
#define I2C_OAR2_ADD2 ((u32_t)0x000000FE)

#define I2C_DR_DR ((u32_t)0x000000FF)

#define I2C_SR1_SB ((u32_t)0x00000001)
#define I2C_SR1_ADDR ((u32_t)0x00000002)
#define I2C_SR1_BTF ((u32_t)0x00000004)
#define I2C_SR1_ADD10 ((u32_t)0x00000008)
#define I2C_SR1_STOPF ((u32_t)0x00000010)
#define I2C_SR1_RXNE ((u32_t)0x00000040)
#define I2C_SR1_TXE ((u32_t)0x00000080)
#define I2C_SR1_BERR ((u32_t)0x00000100)
#define I2C_SR1_ARLO ((u32_t)0x00000200)
#define I2C_SR1_AF ((u32_t)0x00000400)
#define I2C_SR1_OVR ((u32_t)0x00000800)
#define I2C_SR1_PECERR ((u32_t)0x00001000)
#define I2C_SR1_TIMEOUT ((u32_t)0x00004000)
#define I2C_SR1_SMBALERT ((u32_t)0x00008000)

#define I2C_SR2_MSL ((u32_t)0x00000001)
#define I2C_SR2_BUSY ((u32_t)0x00000002)
#define I2C_SR2_TRA ((u32_t)0x00000004)
#define I2C_SR2_GENCALL ((u32_t)0x00000010)
#define I2C_SR2_SMBDEFAULT ((u32_t)0x00000020)
#define I2C_SR2_SMBHOST ((u32_t)0x00000040)
#define I2C_SR2_DUALF ((u32_t)0x00000080)
#define I2C_SR2_PEC ((u32_t)0x0000FF00)

#define I2C_CCR_CCR ((u32_t)0x00000FFF)
#define I2C_CCR_DUTY ((u32_t)0x00004000)
#define I2C_CCR_FS ((u32_t)0x00008000)

#define I2C_TRISE_TRISE ((u32_t)0x0000003F)

#endif
