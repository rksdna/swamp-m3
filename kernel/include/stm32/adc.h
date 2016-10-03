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

#ifndef ADC_H
#define ADC_H

#include <types.h>

struct adc
{
    volatile u32_t SR;
    volatile u32_t CR1;
    volatile u32_t CR2;
    volatile u32_t SMPR1;
    volatile u32_t SMPR2;
    volatile u32_t JOFR1;
    volatile u32_t JOFR2;
    volatile u32_t JOFR3;
    volatile u32_t JOFR4;
    volatile u32_t HTR;
    volatile u32_t LTR;
    volatile u32_t SQR1;
    volatile u32_t SQR2;
    volatile u32_t SQR3;
    volatile u32_t JSQR;
    volatile u32_t JDR1;
    volatile u32_t JDR2;
    volatile u32_t JDR3;
    volatile u32_t JDR4;
    volatile u32_t DR;
};

#define ADC1 ((struct adc *)0x40012400)
#define ADC2 ((struct adc *)0x40012800)
#define ADC3 ((struct adc *)0x40013C00)

#define ADC_SR_AWD ((u32_t)0x00000001)
#define ADC_SR_EOC ((u32_t)0x00000002)
#define ADC_SR_JEOC ((u32_t)0x00000004)
#define ADC_SR_JSTRT ((u32_t)0x00000008)
#define ADC_SR_STRT ((u32_t)0x00000010)

#define ADC_CR1_AWDCH ((u32_t)0x0000001F)
#define ADC_CR1_AWDCH_0 ((u32_t)0x00000001)
#define ADC_CR1_AWDCH_1 ((u32_t)0x00000002)
#define ADC_CR1_AWDCH_2 ((u32_t)0x00000004)
#define ADC_CR1_AWDCH_3 ((u32_t)0x00000008)
#define ADC_CR1_AWDCH_4 ((u32_t)0x00000010)
#define ADC_CR1_EOCIE ((u32_t)0x00000020)
#define ADC_CR1_AWDIE ((u32_t)0x00000040)
#define ADC_CR1_JEOCIE ((u32_t)0x00000080)
#define ADC_CR1_SCAN ((u32_t)0x00000100)
#define ADC_CR1_AWDSGL ((u32_t)0x00000200)
#define ADC_CR1_JAUTO ((u32_t)0x00000400)
#define ADC_CR1_DISCEN ((u32_t)0x00000800)
#define ADC_CR1_JDISCEN ((u32_t)0x00001000)
#define ADC_CR1_DISCNUM ((u32_t)0x0000E000)
#define ADC_CR1_DISCNUM_0 ((u32_t)0x00002000)
#define ADC_CR1_DISCNUM_1 ((u32_t)0x00004000)
#define ADC_CR1_DISCNUM_2 ((u32_t)0x00008000)
#define ADC_CR1_DUALMOD ((u32_t)0x000F0000)
#define ADC_CR1_DUALMOD_0 ((u32_t)0x00010000)
#define ADC_CR1_DUALMOD_1 ((u32_t)0x00020000)
#define ADC_CR1_DUALMOD_2 ((u32_t)0x00040000)
#define ADC_CR1_DUALMOD_3 ((u32_t)0x00080000)
#define ADC_CR1_JAWDEN ((u32_t)0x00400000)
#define ADC_CR1_AWDEN ((u32_t)0x00800000)

#define ADC_CR2_ADON ((u32_t)0x00000001)
#define ADC_CR2_CONT ((u32_t)0x00000002)
#define ADC_CR2_CAL ((u32_t)0x00000004)
#define ADC_CR2_RSTCAL ((u32_t)0x00000008)
#define ADC_CR2_DMA ((u32_t)0x00000100)
#define ADC_CR2_ALIGN ((u32_t)0x00000800)
#define ADC_CR2_JEXTSEL ((u32_t)0x00007000)
#define ADC_CR2_JEXTSEL_0 ((u32_t)0x00001000)
#define ADC_CR2_JEXTSEL_1 ((u32_t)0x00002000)
#define ADC_CR2_JEXTSEL_2 ((u32_t)0x00004000)
#define ADC_CR2_JEXTTRIG ((u32_t)0x00008000)
#define ADC_CR2_EXTSEL ((u32_t)0x000E0000)
#define ADC_CR2_EXTSEL_0 ((u32_t)0x00020000)
#define ADC_CR2_EXTSEL_1 ((u32_t)0x00040000)
#define ADC_CR2_EXTSEL_2 ((u32_t)0x00080000)
#define ADC_CR2_EXTTRIG ((u32_t)0x00100000)
#define ADC_CR2_JSWSTART ((u32_t)0x00200000)
#define ADC_CR2_SWSTART ((u32_t)0x00400000)
#define ADC_CR2_TSVREFE ((u32_t)0x00800000)

#define ADC_SMPR1_SMP10 ((u32_t)0x00000007)
#define ADC_SMPR1_SMP10_0 ((u32_t)0x00000001)
#define ADC_SMPR1_SMP10_1 ((u32_t)0x00000002)
#define ADC_SMPR1_SMP10_2 ((u32_t)0x00000004)
#define ADC_SMPR1_SMP11 ((u32_t)0x00000038)
#define ADC_SMPR1_SMP11_0 ((u32_t)0x00000008)
#define ADC_SMPR1_SMP11_1 ((u32_t)0x00000010)
#define ADC_SMPR1_SMP11_2 ((u32_t)0x00000020)
#define ADC_SMPR1_SMP12 ((u32_t)0x000001C0)
#define ADC_SMPR1_SMP12_0 ((u32_t)0x00000040)
#define ADC_SMPR1_SMP12_1 ((u32_t)0x00000080)
#define ADC_SMPR1_SMP12_2 ((u32_t)0x00000100)
#define ADC_SMPR1_SMP13 ((u32_t)0x00000E00)
#define ADC_SMPR1_SMP13_0 ((u32_t)0x00000200)
#define ADC_SMPR1_SMP13_1 ((u32_t)0x00000400)
#define ADC_SMPR1_SMP13_2 ((u32_t)0x00000800)
#define ADC_SMPR1_SMP14 ((u32_t)0x00007000)
#define ADC_SMPR1_SMP14_0 ((u32_t)0x00001000)
#define ADC_SMPR1_SMP14_1 ((u32_t)0x00002000)
#define ADC_SMPR1_SMP14_2 ((u32_t)0x00004000)
#define ADC_SMPR1_SMP15 ((u32_t)0x00038000)
#define ADC_SMPR1_SMP15_0 ((u32_t)0x00008000)
#define ADC_SMPR1_SMP15_1 ((u32_t)0x00010000)
#define ADC_SMPR1_SMP15_2 ((u32_t)0x00020000)
#define ADC_SMPR1_SMP16 ((u32_t)0x001C0000)
#define ADC_SMPR1_SMP16_0 ((u32_t)0x00040000)
#define ADC_SMPR1_SMP16_1 ((u32_t)0x00080000)
#define ADC_SMPR1_SMP16_2 ((u32_t)0x00100000)
#define ADC_SMPR1_SMP17 ((u32_t)0x00E00000)
#define ADC_SMPR1_SMP17_0 ((u32_t)0x00200000)
#define ADC_SMPR1_SMP17_1 ((u32_t)0x00400000)
#define ADC_SMPR1_SMP17_2 ((u32_t)0x00800000)

#define ADC_SMPR2_SMP0 ((u32_t)0x00000007)
#define ADC_SMPR2_SMP0_0 ((u32_t)0x00000001)
#define ADC_SMPR2_SMP0_1 ((u32_t)0x00000002)
#define ADC_SMPR2_SMP0_2 ((u32_t)0x00000004)
#define ADC_SMPR2_SMP1 ((u32_t)0x00000038)
#define ADC_SMPR2_SMP1_0 ((u32_t)0x00000008)
#define ADC_SMPR2_SMP1_1 ((u32_t)0x00000010)
#define ADC_SMPR2_SMP1_2 ((u32_t)0x00000020)
#define ADC_SMPR2_SMP2 ((u32_t)0x000001C0)
#define ADC_SMPR2_SMP2_0 ((u32_t)0x00000040)
#define ADC_SMPR2_SMP2_1 ((u32_t)0x00000080)
#define ADC_SMPR2_SMP2_2 ((u32_t)0x00000100)
#define ADC_SMPR2_SMP3 ((u32_t)0x00000E00)
#define ADC_SMPR2_SMP3_0 ((u32_t)0x00000200)
#define ADC_SMPR2_SMP3_1 ((u32_t)0x00000400)
#define ADC_SMPR2_SMP3_2 ((u32_t)0x00000800)
#define ADC_SMPR2_SMP4 ((u32_t)0x00007000)
#define ADC_SMPR2_SMP4_0 ((u32_t)0x00001000)
#define ADC_SMPR2_SMP4_1 ((u32_t)0x00002000)
#define ADC_SMPR2_SMP4_2 ((u32_t)0x00004000)
#define ADC_SMPR2_SMP5 ((u32_t)0x00038000)
#define ADC_SMPR2_SMP5_0 ((u32_t)0x00008000)
#define ADC_SMPR2_SMP5_1 ((u32_t)0x00010000)
#define ADC_SMPR2_SMP5_2 ((u32_t)0x00020000)
#define ADC_SMPR2_SMP6 ((u32_t)0x001C0000)
#define ADC_SMPR2_SMP6_0 ((u32_t)0x00040000)
#define ADC_SMPR2_SMP6_1 ((u32_t)0x00080000)
#define ADC_SMPR2_SMP6_2 ((u32_t)0x00100000)
#define ADC_SMPR2_SMP7 ((u32_t)0x00E00000)
#define ADC_SMPR2_SMP7_0 ((u32_t)0x00200000)
#define ADC_SMPR2_SMP7_1 ((u32_t)0x00400000)
#define ADC_SMPR2_SMP7_2 ((u32_t)0x00800000)
#define ADC_SMPR2_SMP8 ((u32_t)0x07000000)
#define ADC_SMPR2_SMP8_0 ((u32_t)0x01000000)
#define ADC_SMPR2_SMP8_1 ((u32_t)0x02000000)
#define ADC_SMPR2_SMP8_2 ((u32_t)0x04000000)
#define ADC_SMPR2_SMP9 ((u32_t)0x38000000)
#define ADC_SMPR2_SMP9_0 ((u32_t)0x08000000)
#define ADC_SMPR2_SMP9_1 ((u32_t)0x10000000)
#define ADC_SMPR2_SMP9_2 ((u32_t)0x20000000)

#define ADC_JOFR1_JOFFSET1 ((u32_t)0x00000FFF)

#define ADC_JOFR2_JOFFSET2 ((u32_t)0x00000FFF)

#define ADC_JOFR3_JOFFSET3 ((u32_t)0x00000FFF)

#define ADC_JOFR4_JOFFSET4 ((u32_t)0x00000FFF)

#define ADC_HTR_HT ((u32_t)0x00000FFF)

#define ADC_LTR_LT ((u32_t)0x00000FFF)

#define ADC_SQR1_SQ13 ((u32_t)0x0000001F)
#define ADC_SQR1_SQ13_0 ((u32_t)0x00000001)
#define ADC_SQR1_SQ13_1 ((u32_t)0x00000002)
#define ADC_SQR1_SQ13_2 ((u32_t)0x00000004)
#define ADC_SQR1_SQ13_3 ((u32_t)0x00000008)
#define ADC_SQR1_SQ13_4 ((u32_t)0x00000010)
#define ADC_SQR1_SQ14 ((u32_t)0x000003E0)
#define ADC_SQR1_SQ14_0 ((u32_t)0x00000020)
#define ADC_SQR1_SQ14_1 ((u32_t)0x00000040)
#define ADC_SQR1_SQ14_2 ((u32_t)0x00000080)
#define ADC_SQR1_SQ14_3 ((u32_t)0x00000100)
#define ADC_SQR1_SQ14_4 ((u32_t)0x00000200)
#define ADC_SQR1_SQ15 ((u32_t)0x00007C00)
#define ADC_SQR1_SQ15_0 ((u32_t)0x00000400)
#define ADC_SQR1_SQ15_1 ((u32_t)0x00000800)
#define ADC_SQR1_SQ15_2 ((u32_t)0x00001000)
#define ADC_SQR1_SQ15_3 ((u32_t)0x00002000)
#define ADC_SQR1_SQ15_4 ((u32_t)0x00004000)
#define ADC_SQR1_SQ16 ((u32_t)0x000F8000)
#define ADC_SQR1_SQ16_0 ((u32_t)0x00008000)
#define ADC_SQR1_SQ16_1 ((u32_t)0x00010000)
#define ADC_SQR1_SQ16_2 ((u32_t)0x00020000)
#define ADC_SQR1_SQ16_3 ((u32_t)0x00040000)
#define ADC_SQR1_SQ16_4 ((u32_t)0x00080000)
#define ADC_SQR1_L ((u32_t)0x00F00000)
#define ADC_SQR1_L_0 ((u32_t)0x00100000)
#define ADC_SQR1_L_1 ((u32_t)0x00200000)
#define ADC_SQR1_L_2 ((u32_t)0x00400000)
#define ADC_SQR1_L_3 ((u32_t)0x00800000)

#define ADC_SQR2_SQ7 ((u32_t)0x0000001F)
#define ADC_SQR2_SQ7_0 ((u32_t)0x00000001)
#define ADC_SQR2_SQ7_1 ((u32_t)0x00000002)
#define ADC_SQR2_SQ7_2 ((u32_t)0x00000004)
#define ADC_SQR2_SQ7_3 ((u32_t)0x00000008)
#define ADC_SQR2_SQ7_4 ((u32_t)0x00000010)
#define ADC_SQR2_SQ8 ((u32_t)0x000003E0)
#define ADC_SQR2_SQ8_0 ((u32_t)0x00000020)
#define ADC_SQR2_SQ8_1 ((u32_t)0x00000040)
#define ADC_SQR2_SQ8_2 ((u32_t)0x00000080)
#define ADC_SQR2_SQ8_3 ((u32_t)0x00000100)
#define ADC_SQR2_SQ8_4 ((u32_t)0x00000200)
#define ADC_SQR2_SQ9 ((u32_t)0x00007C00)
#define ADC_SQR2_SQ9_0 ((u32_t)0x00000400)
#define ADC_SQR2_SQ9_1 ((u32_t)0x00000800)
#define ADC_SQR2_SQ9_2 ((u32_t)0x00001000)
#define ADC_SQR2_SQ9_3 ((u32_t)0x00002000)
#define ADC_SQR2_SQ9_4 ((u32_t)0x00004000)
#define ADC_SQR2_SQ10 ((u32_t)0x000F8000)
#define ADC_SQR2_SQ10_0 ((u32_t)0x00008000)
#define ADC_SQR2_SQ10_1 ((u32_t)0x00010000)
#define ADC_SQR2_SQ10_2 ((u32_t)0x00020000)
#define ADC_SQR2_SQ10_3 ((u32_t)0x00040000)
#define ADC_SQR2_SQ10_4 ((u32_t)0x00080000)
#define ADC_SQR2_SQ11 ((u32_t)0x01F00000)
#define ADC_SQR2_SQ11_0 ((u32_t)0x00100000)
#define ADC_SQR2_SQ11_1 ((u32_t)0x00200000)
#define ADC_SQR2_SQ11_2 ((u32_t)0x00400000)
#define ADC_SQR2_SQ11_3 ((u32_t)0x00800000)
#define ADC_SQR2_SQ11_4 ((u32_t)0x01000000)
#define ADC_SQR2_SQ12 ((u32_t)0x3E000000)
#define ADC_SQR2_SQ12_0 ((u32_t)0x02000000)
#define ADC_SQR2_SQ12_1 ((u32_t)0x04000000)
#define ADC_SQR2_SQ12_2 ((u32_t)0x08000000)
#define ADC_SQR2_SQ12_3 ((u32_t)0x10000000)
#define ADC_SQR2_SQ12_4 ((u32_t)0x20000000)

#define ADC_SQR3_SQ1 ((u32_t)0x0000001F)
#define ADC_SQR3_SQ1_0 ((u32_t)0x00000001)
#define ADC_SQR3_SQ1_1 ((u32_t)0x00000002)
#define ADC_SQR3_SQ1_2 ((u32_t)0x00000004)
#define ADC_SQR3_SQ1_3 ((u32_t)0x00000008)
#define ADC_SQR3_SQ1_4 ((u32_t)0x00000010)
#define ADC_SQR3_SQ2 ((u32_t)0x000003E0)
#define ADC_SQR3_SQ2_0 ((u32_t)0x00000020)
#define ADC_SQR3_SQ2_1 ((u32_t)0x00000040)
#define ADC_SQR3_SQ2_2 ((u32_t)0x00000080)
#define ADC_SQR3_SQ2_3 ((u32_t)0x00000100)
#define ADC_SQR3_SQ2_4 ((u32_t)0x00000200)
#define ADC_SQR3_SQ3 ((u32_t)0x00007C00)
#define ADC_SQR3_SQ3_0 ((u32_t)0x00000400)
#define ADC_SQR3_SQ3_1 ((u32_t)0x00000800)
#define ADC_SQR3_SQ3_2 ((u32_t)0x00001000)
#define ADC_SQR3_SQ3_3 ((u32_t)0x00002000)
#define ADC_SQR3_SQ3_4 ((u32_t)0x00004000)
#define ADC_SQR3_SQ4 ((u32_t)0x000F8000)
#define ADC_SQR3_SQ4_0 ((u32_t)0x00008000)
#define ADC_SQR3_SQ4_1 ((u32_t)0x00010000)
#define ADC_SQR3_SQ4_2 ((u32_t)0x00020000)
#define ADC_SQR3_SQ4_3 ((u32_t)0x00040000)
#define ADC_SQR3_SQ4_4 ((u32_t)0x00080000)
#define ADC_SQR3_SQ5 ((u32_t)0x01F00000)
#define ADC_SQR3_SQ5_0 ((u32_t)0x00100000)
#define ADC_SQR3_SQ5_1 ((u32_t)0x00200000)
#define ADC_SQR3_SQ5_2 ((u32_t)0x00400000)
#define ADC_SQR3_SQ5_3 ((u32_t)0x00800000)
#define ADC_SQR3_SQ5_4 ((u32_t)0x01000000)
#define ADC_SQR3_SQ6 ((u32_t)0x3E000000)
#define ADC_SQR3_SQ6_0 ((u32_t)0x02000000)
#define ADC_SQR3_SQ6_1 ((u32_t)0x04000000)
#define ADC_SQR3_SQ6_2 ((u32_t)0x08000000)
#define ADC_SQR3_SQ6_3 ((u32_t)0x10000000)
#define ADC_SQR3_SQ6_4 ((u32_t)0x20000000)

#define ADC_JSQR_JSQ1 ((u32_t)0x0000001F)
#define ADC_JSQR_JSQ1_0 ((u32_t)0x00000001)
#define ADC_JSQR_JSQ1_1 ((u32_t)0x00000002)
#define ADC_JSQR_JSQ1_2 ((u32_t)0x00000004)
#define ADC_JSQR_JSQ1_3 ((u32_t)0x00000008)
#define ADC_JSQR_JSQ1_4 ((u32_t)0x00000010)
#define ADC_JSQR_JSQ2 ((u32_t)0x000003E0)
#define ADC_JSQR_JSQ2_0 ((u32_t)0x00000020)
#define ADC_JSQR_JSQ2_1 ((u32_t)0x00000040)
#define ADC_JSQR_JSQ2_2 ((u32_t)0x00000080)
#define ADC_JSQR_JSQ2_3 ((u32_t)0x00000100)
#define ADC_JSQR_JSQ2_4 ((u32_t)0x00000200)
#define ADC_JSQR_JSQ3 ((u32_t)0x00007C00)
#define ADC_JSQR_JSQ3_0 ((u32_t)0x00000400)
#define ADC_JSQR_JSQ3_1 ((u32_t)0x00000800)
#define ADC_JSQR_JSQ3_2 ((u32_t)0x00001000)
#define ADC_JSQR_JSQ3_3 ((u32_t)0x00002000)
#define ADC_JSQR_JSQ3_4 ((u32_t)0x00004000)
#define ADC_JSQR_JSQ4 ((u32_t)0x000F8000)
#define ADC_JSQR_JSQ4_0 ((u32_t)0x00008000)
#define ADC_JSQR_JSQ4_1 ((u32_t)0x00010000)
#define ADC_JSQR_JSQ4_2 ((u32_t)0x00020000)
#define ADC_JSQR_JSQ4_3 ((u32_t)0x00040000)
#define ADC_JSQR_JSQ4_4 ((u32_t)0x00080000)
#define ADC_JSQR_JL ((u32_t)0x00300000)
#define ADC_JSQR_JL_0 ((u32_t)0x00100000)
#define ADC_JSQR_JL_1 ((u32_t)0x00200000)

#define ADC_JDR1_JDATA ((u32_t)0x0000FFFF)

#define ADC_JDR2_JDATA ((u32_t)0x0000FFFF)

#define ADC_JDR3_JDATA ((u32_t)0x0000FFFF)

#define ADC_JDR4_JDATA ((u32_t)0x0000FFFF)

#define ADC_DR_DATA ((u32_t)0x0000FFFF)
#define ADC_DR_ADC2DATA ((u32_t)0xFFFF0000)

#endif
