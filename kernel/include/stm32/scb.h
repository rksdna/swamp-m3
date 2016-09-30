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

#ifndef SCB_H
#define SCB_H

#include <types.h>

struct scb
{
    volatile const u32_t CPUID;
    volatile u32_t ICSR;
    volatile u32_t VTOR;
    volatile u32_t AIRCR;
    volatile u32_t SCR;
    volatile u32_t CCR;
    volatile u8_t SHP[12];
    volatile u32_t SHCSR;
    volatile u32_t CFSR;
    volatile u32_t HFSR;
    u32_t RESERVED0;
    volatile u32_t MMFAR;
    volatile u32_t BFAR;
    volatile u32_t AFSR;
};

#define SCB ((struct scb *)0xE000ED00)

#define SCB_CPUID_REVISION ((u32_t)0x0000000F)
#define SCB_CPUID_PARTNO ((u32_t)0x0000FFF0)
#define SCB_CPUID_CONSTANT ((u32_t)0x000F0000)
#define SCB_CPUID_VARIANT ((u32_t)0x00F00000)
#define SCB_CPUID_IMPLEMENTER ((u32_t)0xFF000000)

#define SCB_ICSR_VECTACTIVE ((u32_t)0x000001FF)
#define SCB_ICSR_RETTOBASE ((u32_t)0x00000800)
#define SCB_ICSR_VECTPENDING ((u32_t)0x003FF000)
#define SCB_ICSR_ISRPENDING ((u32_t)0x00400000)
#define SCB_ICSR_PENDSTCLR ((u32_t)0x02000000)
#define SCB_ICSR_PENDSTSET ((u32_t)0x04000000)
#define SCB_ICSR_PENDSVCLR ((u32_t)0x08000000)
#define SCB_ICSR_PENDSVSET ((u32_t)0x10000000)
#define SCB_ICSR_NMIPENDSET ((u32_t)0x80000000)

#define SCB_VTOR_TBLOFF ((u32_t)0x1FFFFE00)
#define SCB_VTOR_TBLBASE ((u32_t)0x20000000)

#define SCB_AIRCR_VECTRESET ((u32_t)0x00000001)
#define SCB_AIRCR_VECTCLRACTIVE ((u32_t)0x00000002)
#define SCB_AIRCR_SYSRESETREQ ((u32_t)0x00000004)
#define SCB_AIRCR_PRIGROUP ((u32_t)0x00000700)
#define SCB_AIRCR_PRIGROUP_0 ((u32_t)0x00000100)
#define SCB_AIRCR_PRIGROUP_1 ((u32_t)0x00000200)
#define SCB_AIRCR_PRIGROUP_2 ((u32_t)0x00000400)
#define SCB_AIRCR_ENDIANESS ((u32_t)0x00008000)
#define SCB_AIRCR_VECTKEY ((u32_t)0xFFFF0000)
#define SCB_AIRCR_VECTKEY_KEY ((u32_t)0x05FA0000)

#define SCB_SCR_SLEEPONEXIT ((u32_t)0x02)
#define SCB_SCR_SLEEPDEEP ((u32_t)0x04)
#define SCB_SCR_SEVONPEND ((u32_t)0x10)

#define SCB_CCR_NONBASETHRDENA ((u32_t)0x0001)
#define SCB_CCR_USERSETMPEND ((u32_t)0x0002)
#define SCB_CCR_UNALIGN_TRP ((u32_t)0x0008)
#define SCB_CCR_DIV_0_TRP ((u32_t)0x0010)
#define SCB_CCR_BFHFNMIGN ((u32_t)0x0100)
#define SCB_CCR_STKALIGN ((u32_t)0x0200)

#define SCB_SHPx_PRI ((u8_t)0xFF)

#define SCB_SHCSR_MEMFAULTACT ((u32_t)0x00000001)
#define SCB_SHCSR_BUSFAULTACT ((u32_t)0x00000002)
#define SCB_SHCSR_USGFAULTACT ((u32_t)0x00000008)
#define SCB_SHCSR_SVCALLACT ((u32_t)0x00000080)
#define SCB_SHCSR_MONITORACT ((u32_t)0x00000100)
#define SCB_SHCSR_PENDSVACT ((u32_t)0x00000400)
#define SCB_SHCSR_SYSTICKACT ((u32_t)0x00000800)
#define SCB_SHCSR_USGFAULTPENDED ((u32_t)0x00001000)
#define SCB_SHCSR_MEMFAULTPENDED ((u32_t)0x00002000)
#define SCB_SHCSR_BUSFAULTPENDED ((u32_t)0x00004000)
#define SCB_SHCSR_SVCALLPENDED ((u32_t)0x00008000)
#define SCB_SHCSR_MEMFAULTENA ((u32_t)0x00010000)
#define SCB_SHCSR_BUSFAULTENA ((u32_t)0x00020000)
#define SCB_SHCSR_USGFAULTENA ((u32_t)0x00040000)

#define SCB_CFSR_IACCVIOL ((u32_t)0x00000001)
#define SCB_CFSR_DACCVIOL ((u32_t)0x00000002)
#define SCB_CFSR_MUNSTKERR ((u32_t)0x00000008)
#define SCB_CFSR_MSTKERR ((u32_t)0x00000010)
#define SCB_CFSR_MMARVALID ((u32_t)0x00000080)
#define SCB_CFSR_IBUSERR ((u32_t)0x00000100)
#define SCB_CFSR_PRECISERR ((u32_t)0x00000200)
#define SCB_CFSR_IMPRECISERR ((u32_t)0x00000400)
#define SCB_CFSR_UNSTKERR ((u32_t)0x00000800)
#define SCB_CFSR_STKERR ((u32_t)0x00001000)
#define SCB_CFSR_BFARVALID ((u32_t)0x00008000)
#define SCB_CFSR_UNDEFINSTR ((u32_t)0x00010000)
#define SCB_CFSR_INVSTATE ((u32_t)0x00020000)
#define SCB_CFSR_INVPC ((u32_t)0x00040000)
#define SCB_CFSR_NOCP ((u32_t)0x00080000)
#define SCB_CFSR_UNALIGNED ((u32_t)0x01000000)
#define SCB_CFSR_DIVBYZERO ((u32_t)0x02000000)

#define SCB_HFSR_VECTTBL ((u32_t)0x00000002)
#define SCB_HFSR_FORCED ((u32_t)0x40000000)
#define SCB_HFSR_DEBUGEVT ((u32_t)0x80000000)

#define SCB_MMFAR_MMFAR ((u32_t)0xFFFFFFFF)

#define SCB_BFAR_BFAR ((u32_t)0xFFFFFFFF)

#endif
