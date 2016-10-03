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

#ifndef FSMC_H
#define FSMC_H

#include <types.h>

struct fsmc_sram_nor
{
    volatile u32_t BCR1;
    volatile u32_t BTR1;
    volatile u32_t BCR2;
    volatile u32_t BTR2;
    volatile u32_t BCR3;
    volatile u32_t BTR3;
    volatile u32_t BCR4;
    volatile u32_t BTR4;
    u32_t RESERVED0[57];
    volatile u32_t BWTR1;
    u32_t RESERVED1;
    volatile u32_t BWTR2;
    u32_t RESERVED2;
    volatile u32_t BWTR3;
    u32_t RESERVED3;
    volatile u32_t BWTR4;
    u32_t RESERVED4;
};

struct fsmc_nand
{
    volatile u32_t PCR;
    volatile u32_t SR;
    volatile u32_t PMEM;
    volatile u32_t PATT;
    u32_t RESERVED0;
    volatile u32_t ECCR;
};

struct fsmc_pc_card
{
    volatile u32_t PCR;
    volatile u32_t SR;
    volatile u32_t PMEM;
    volatile u32_t PATT;
    volatile u32_t PIO;
    u32_t RESERVED0;
};

#define FSMC_MEMORY1 ((void *)0x60000000)
#define FSMC_BANK1 ((struct fsmc_sram_nor *) 0xA0000000)

#define FSMC_MEMORY2 ((void *)0x70000000)
#define FSMC_BANK2 ((struct fsmc_nand *) 0xA0000060)

#define FSMC_MEMORY3 ((void *)0x80000000)
#define FSMC_BANK3 ((struct fsmc_nand *)0xA0000080)

#define FSMC_MEMORY4 ((void *)0x90000000)
#define FSMC_BANK4 ((struct fsmc_pc_card *)0xA00000A0)

#define FSMC_BCR_MBKEN ((u32_t)0x00000001)
#define FSMC_BCR_MUXEN ((u32_t)0x00000002)
#define FSMC_BCR_MTYP ((u32_t)0x0000000C)
#define FSMC_BCR_MTYP_0 ((u32_t)0x00000004)
#define FSMC_BCR_MTYP_1 ((u32_t)0x00000008)
#define FSMC_BCR_MTYP_SRAM ((u32_t)0x00000000)
#define FSMC_BCR_MTYP_PSRAM ((u32_t)0x00000004)
#define FSMC_BCR_MTYP_NOR ((u32_t)0x00000008)
#define FSMC_BCR_MWID ((u32_t)0x00000030)
#define FSMC_BCR_MWID_0 ((u32_t)0x00000010)
#define FSMC_BCR_MWID_1 ((u32_t)0x00000020)
#define FSMC_BCR_MWID_8BIT ((u32_t)0x00000000)
#define FSMC_BCR_xMWID_16BIT ((u32_t)0x00000010)
#define FSMC_BCR_FACCEN ((u32_t)0x00000040)
#define FSMC_BCR_BURSTEN ((u32_t)0x00000100)
#define FSMC_BCR_WAITPOL ((u32_t)0x00000200)
#define FSMC_BCR_WRAPMOD ((u32_t)0x00000400)
#define FSMC_BCR_WAITCFG ((u32_t)0x00000800)
#define FSMC_BCR_WREN ((u32_t)0x00001000)
#define FSMC_BCR_WAITEN ((u32_t)0x00002000)
#define FSMC_BCR_EXTMOD ((u32_t)0x00004000)
#define FSMC_BCR_ASYNCWAIT ((u32_t)0x00008000)
#define FSMC_BCR_CPSIZE ((u32_t)0x00070000)
#define FSMC_BCR_CPSIZE_0 ((u32_t)0x00010000)
#define FSMC_BCR_CPSIZE_1 ((u32_t)0x00020000)
#define FSMC_BCR_CPSIZE_2 ((u32_t)0x00040000)
#define FSMC_BCR_CBURSTRW  ((u32_t)0x00080000)

#define FSMC_BTR_ADDSET ((u32_t)0x0000000F)
#define FSMC_BTR_ADDSET_0 ((u32_t)0x00000001)
#define FSMC_BTR_ADDSET_1 ((u32_t)0x00000002)
#define FSMC_BTR_ADDSET_2 ((u32_t)0x00000004)
#define FSMC_BTR_ADDSET_3 ((u32_t)0x00000008)
#define FSMC_BTR_ADDHLD ((u32_t)0x000000F0)
#define FSMC_BTR_ADDHLD_0 ((u32_t)0x00000010)
#define FSMC_BTR_ADDHLD_1 ((u32_t)0x00000020)
#define FSMC_BTR_ADDHLD_2 ((u32_t)0x00000040)
#define FSMC_BTR_ADDHLD_3 ((u32_t)0x00000080)
#define FSMC_BTR_DATAST ((u32_t)0x0000FF00)
#define FSMC_BTR_DATAST_0 ((u32_t)0x00000100)
#define FSMC_BTR_DATAST_1 ((u32_t)0x00000200)
#define FSMC_BTR_DATAST_2 ((u32_t)0x00000400)
#define FSMC_BTR_DATAST_3 ((u32_t)0x00000800)
#define FSMC_BTR_BUSTURN ((u32_t)0x000F0000)
#define FSMC_BTR_BUSTURN_0 ((u32_t)0x00010000)
#define FSMC_BTR_BUSTURN_1 ((u32_t)0x00020000)
#define FSMC_BTR_BUSTURN_2 ((u32_t)0x00040000)
#define FSMC_BTR_BUSTURN_3 ((u32_t)0x00080000)
#define FSMC_BTR_CLKDIV ((u32_t)0x00F00000)
#define FSMC_BTR_CLKDIV_0 ((u32_t)0x00100000)
#define FSMC_BTR_CLKDIV_1 ((u32_t)0x00200000)
#define FSMC_BTR_CLKDIV_2 ((u32_t)0x00400000)
#define FSMC_BTR_CLKDIV_3 ((u32_t)0x00800000)
#define FSMC_BTR_DATLAT ((u32_t)0x0F000000)
#define FSMC_BTR_DATLAT_0 ((u32_t)0x01000000)
#define FSMC_BTR_DATLAT_1 ((u32_t)0x02000000)
#define FSMC_BTR_DATLAT_2 ((u32_t)0x04000000)
#define FSMC_BTR_DATLAT_3 ((u32_t)0x08000000)
#define FSMC_BTR_ACCMOD ((u32_t)0x30000000)
#define FSMC_BTR_ACCMOD_0 ((u32_t)0x10000000)
#define FSMC_BTR_ACCMOD_1 ((u32_t)0x20000000)

#define FSMC_BWTR_ADDSET ((u32_t)0x0000000F)
#define FSMC_BWTR_ADDSET_0 ((u32_t)0x00000001)
#define FSMC_BWTR_ADDSET_1 ((u32_t)0x00000002)
#define FSMC_BWTR_ADDSET_2 ((u32_t)0x00000004)
#define FSMC_BWTR_ADDSET_3 ((u32_t)0x00000008)
#define FSMC_BWTR_ADDHLD ((u32_t)0x000000F0)
#define FSMC_BWTR_ADDHLD_0 ((u32_t)0x00000010)
#define FSMC_BWTR_ADDHLD_1 ((u32_t)0x00000020)
#define FSMC_BWTR_ADDHLD_2 ((u32_t)0x00000040)
#define FSMC_BWTR_ADDHLD_3 ((u32_t)0x00000080)
#define FSMC_BWTR_DATAST ((u32_t)0x0000FF00)
#define FSMC_BWTR_DATAST_0 ((u32_t)0x00000100)
#define FSMC_BWTR_DATAST_1 ((u32_t)0x00000200)
#define FSMC_BWTR_DATAST_2 ((u32_t)0x00000400)
#define FSMC_BWTR_DATAST_3 ((u32_t)0x00000800)
#define FSMC_BWTR_CLKDIV ((u32_t)0x00F00000)
#define FSMC_BWTR_CLKDIV_0 ((u32_t)0x00100000)
#define FSMC_BWTR_CLKDIV_1 ((u32_t)0x00200000)
#define FSMC_BWTR_CLKDIV_2 ((u32_t)0x00400000)
#define FSMC_BWTR_CLKDIV_3 ((u32_t)0x00800000)
#define FSMC_BWTR_DATLAT ((u32_t)0x0F000000)
#define FSMC_BWTR_DATLAT_0 ((u32_t)0x01000000)
#define FSMC_BWTR_DATLAT_1 ((u32_t)0x02000000)
#define FSMC_BWTR_DATLAT_2 ((u32_t)0x04000000)
#define FSMC_BWTR_DATLAT_3 ((u32_t)0x08000000)
#define FSMC_BWTR_ACCMOD ((u32_t)0x30000000)
#define FSMC_BWTR_ACCMOD_0 ((u32_t)0x10000000)
#define FSMC_BWTR_ACCMOD_1 ((u32_t)0x20000000)

#define FSMC_PCR_PWAITEN ((u32_t)0x00000002)
#define FSMC_PCR_PBKEN ((u32_t)0x00000004)
#define FSMC_PCR_PTYP ((u32_t)0x00000008)
#define FSMC_PCR_PWID ((u32_t)0x00000030)
#define FSMC_PCR_PWID_0 ((u32_t)0x00000010)
#define FSMC_PCR_PWID_1 ((u32_t)0x00000020)
#define FSMC_PCR_ECCEN ((u32_t)0x00000040)
#define FSMC_PCR_TCLR ((u32_t)0x00001E00)
#define FSMC_PCR_TCLR_0 ((u32_t)0x00000200)
#define FSMC_PCR_TCLR_1 ((u32_t)0x00000400)
#define FSMC_PCR_TCLR_2 ((u32_t)0x00000800)
#define FSMC_PCR_TCLR_3 ((u32_t)0x00001000)
#define FSMC_PCR_TAR ((u32_t)0x0001E000)
#define FSMC_PCR_TAR_0 ((u32_t)0x00002000)
#define FSMC_PCR_TAR_1 ((u32_t)0x00004000)
#define FSMC_PCR_TAR_2 ((u32_t)0x00008000)
#define FSMC_PCR_TAR_3 ((u32_t)0x00010000)
#define FSMC_PCR_ECCPS ((u32_t)0x000E0000)
#define FSMC_PCR_ECCPS_0 ((u32_t)0x00020000)
#define FSMC_PCR_ECCPS_1 ((u32_t)0x00040000)
#define FSMC_PCR_ECCPS_2 ((u32_t)0x00080000)

#define FSMC_SR_IRS ((u32_t)0x00000001)
#define FSMC_SR_ILS ((u32_t)0x00000002)
#define FSMC_SR_IFS ((u32_t)0x00000004)
#define FSMC_SR_IREN ((u32_t)0x00000008)
#define FSMC_SR_ILEN ((u32_t)0x00000010)
#define FSMC_SR_IFEN ((u32_t)0x00000020)
#define FSMC_SR_FEMPT ((u32_t)0x00000040)

#define FSMC_PMEM_MEMSET2 ((u32_t)0x000000FF)
#define FSMC_PMEM_MEMSET2_0 ((u32_t)0x00000001)
#define FSMC_PMEM_MEMSET2_1 ((u32_t)0x00000002)
#define FSMC_PMEM_MEMSET2_2 ((u32_t)0x00000004)
#define FSMC_PMEM_MEMSET2_3 ((u32_t)0x00000008)
#define FSMC_PMEM_MEMSET2_4 ((u32_t)0x00000010)
#define FSMC_PMEM_MEMSET2_5 ((u32_t)0x00000020)
#define FSMC_PMEM_MEMSET2_6 ((u32_t)0x00000040)
#define FSMC_PMEM_MEMSET2_7 ((u32_t)0x00000080)
#define FSMC_PMEM_MEMWAIT2 ((u32_t)0x0000FF00)
#define FSMC_PMEM_MEMWAIT2_0 ((u32_t)0x00000100)
#define FSMC_PMEM_MEMWAIT2_1 ((u32_t)0x00000200)
#define FSMC_PMEM_MEMWAIT2_2 ((u32_t)0x00000400)
#define FSMC_PMEM_MEMWAIT2_3 ((u32_t)0x00000800)
#define FSMC_PMEM_MEMWAIT2_4 ((u32_t)0x00001000)
#define FSMC_PMEM_MEMWAIT2_5 ((u32_t)0x00002000)
#define FSMC_PMEM_MEMWAIT2_6 ((u32_t)0x00004000)
#define FSMC_PMEM_MEMWAIT2_7 ((u32_t)0x00008000)
#define FSMC_PMEM_MEMHOLD2 ((u32_t)0x00FF0000)
#define FSMC_PMEM_MEMHOLD2_0 ((u32_t)0x00010000)
#define FSMC_PMEM_MEMHOLD2_1 ((u32_t)0x00020000)
#define FSMC_PMEM_MEMHOLD2_2 ((u32_t)0x00040000)
#define FSMC_PMEM_MEMHOLD2_3 ((u32_t)0x00080000)
#define FSMC_PMEM_MEMHOLD2_4 ((u32_t)0x00100000)
#define FSMC_PMEM_MEMHOLD2_5 ((u32_t)0x00200000)
#define FSMC_PMEM_MEMHOLD2_6 ((u32_t)0x00400000)
#define FSMC_PMEM_MEMHOLD2_7 ((u32_t)0x00800000)
#define FSMC_PMEM_MEMHIZ2 ((u32_t)0xFF000000)
#define FSMC_PMEM_MEMHIZ2_0 ((u32_t)0x01000000)
#define FSMC_PMEM_MEMHIZ2_1 ((u32_t)0x02000000)
#define FSMC_PMEM_MEMHIZ2_2 ((u32_t)0x04000000)
#define FSMC_PMEM_MEMHIZ2_3 ((u32_t)0x08000000)
#define FSMC_PMEM_MEMHIZ2_4 ((u32_t)0x10000000)
#define FSMC_PMEM_MEMHIZ2_5 ((u32_t)0x20000000)
#define FSMC_PMEM_MEMHIZ2_6 ((u32_t)0x40000000)
#define FSMC_PMEM_MEMHIZ2_7 ((u32_t)0x80000000)

#define FSMC_PATT_ATTSET2 ((u32_t)0x000000FF)
#define FSMC_PATT_ATTSET2_0 ((u32_t)0x00000001)
#define FSMC_PATT_ATTSET2_1 ((u32_t)0x00000002)
#define FSMC_PATT_ATTSET2_2 ((u32_t)0x00000004)
#define FSMC_PATT_ATTSET2_3 ((u32_t)0x00000008)
#define FSMC_PATT_ATTSET2_4 ((u32_t)0x00000010)
#define FSMC_PATT_ATTSET2_5 ((u32_t)0x00000020)
#define FSMC_PATT_ATTSET2_6 ((u32_t)0x00000040)
#define FSMC_PATT_ATTSET2_7 ((u32_t)0x00000080)
#define FSMC_PATT_ATTWAIT2 ((u32_t)0x0000FF00)
#define FSMC_PATT_ATTWAIT2_0 ((u32_t)0x00000100)
#define FSMC_PATT_ATTWAIT2_1 ((u32_t)0x00000200)
#define FSMC_PATT_ATTWAIT2_2 ((u32_t)0x00000400)
#define FSMC_PATT_ATTWAIT2_3 ((u32_t)0x00000800)
#define FSMC_PATT_ATTWAIT2_4 ((u32_t)0x00001000)
#define FSMC_PATT_ATTWAIT2_5 ((u32_t)0x00002000)
#define FSMC_PATT_ATTWAIT2_6 ((u32_t)0x00004000)
#define FSMC_PATT_ATTWAIT2_7 ((u32_t)0x00008000)
#define FSMC_PATT_ATTHOLD2 ((u32_t)0x00FF0000)
#define FSMC_PATT_ATTHOLD2_0 ((u32_t)0x00010000)
#define FSMC_PATT_ATTHOLD2_1 ((u32_t)0x00020000)
#define FSMC_PATT_ATTHOLD2_2 ((u32_t)0x00040000)
#define FSMC_PATT_ATTHOLD2_3 ((u32_t)0x00080000)
#define FSMC_PATT_ATTHOLD2_4 ((u32_t)0x00100000)
#define FSMC_PATT_ATTHOLD2_5 ((u32_t)0x00200000)
#define FSMC_PATT_ATTHOLD2_6 ((u32_t)0x00400000)
#define FSMC_PATT_ATTHOLD2_7 ((u32_t)0x00800000)
#define FSMC_PATT_ATTHIZ2 ((u32_t)0xFF000000)
#define FSMC_PATT_ATTHIZ2_0 ((u32_t)0x01000000)
#define FSMC_PATT_ATTHIZ2_1 ((u32_t)0x02000000)
#define FSMC_PATT_ATTHIZ2_2 ((u32_t)0x04000000)
#define FSMC_PATT_ATTHIZ2_3 ((u32_t)0x08000000)
#define FSMC_PATT_ATTHIZ2_4 ((u32_t)0x10000000)
#define FSMC_PATT_ATTHIZ2_5 ((u32_t)0x20000000)
#define FSMC_PATT_ATTHIZ2_6 ((u32_t)0x40000000)
#define FSMC_PATT_ATTHIZ2_7 ((u32_t)0x80000000)

#define FSMC_PIO_IOSET4 ((u32_t)0x000000FF)
#define FSMC_PIO_IOSET4_0 ((u32_t)0x00000001)
#define FSMC_PIO_IOSET4_1 ((u32_t)0x00000002)
#define FSMC_PIO_IOSET4_2 ((u32_t)0x00000004)
#define FSMC_PIO_IOSET4_3 ((u32_t)0x00000008)
#define FSMC_PIO_IOSET4_4 ((u32_t)0x00000010)
#define FSMC_PIO_IOSET4_5 ((u32_t)0x00000020)
#define FSMC_PIO_IOSET4_6 ((u32_t)0x00000040)
#define FSMC_PIO_IOSET4_7 ((u32_t)0x00000080)
#define FSMC_PIO_IOWAIT4 ((u32_t)0x0000FF00)
#define FSMC_PIO_IOWAIT4_0 ((u32_t)0x00000100)
#define FSMC_PIO_IOWAIT4_1 ((u32_t)0x00000200)
#define FSMC_PIO_IOWAIT4_2 ((u32_t)0x00000400)
#define FSMC_PIO_IOWAIT4_3 ((u32_t)0x00000800)
#define FSMC_PIO_IOWAIT4_4 ((u32_t)0x00001000)
#define FSMC_PIO_IOWAIT4_5 ((u32_t)0x00002000)
#define FSMC_PIO_IOWAIT4_6 ((u32_t)0x00004000)
#define FSMC_PIO_IOWAIT4_7 ((u32_t)0x00008000)
#define FSMC_PIO_IOHOLD4 ((u32_t)0x00FF0000)
#define FSMC_PIO_IOHOLD4_0 ((u32_t)0x00010000)
#define FSMC_PIO_IOHOLD4_1 ((u32_t)0x00020000)
#define FSMC_PIO_IOHOLD4_2 ((u32_t)0x00040000)
#define FSMC_PIO_IOHOLD4_3 ((u32_t)0x00080000)
#define FSMC_PIO_IOHOLD4_4 ((u32_t)0x00100000)
#define FSMC_PIO_IOHOLD4_5 ((u32_t)0x00200000)
#define FSMC_PIO_IOHOLD4_6 ((u32_t)0x00400000)
#define FSMC_PIO_IOHOLD4_7 ((u32_t)0x00800000)
#define FSMC_PIO_IOHIZ4 ((u32_t)0xFF000000)
#define FSMC_PIO_IOHIZ4_0 ((u32_t)0x01000000)
#define FSMC_PIO_IOHIZ4_1 ((u32_t)0x02000000)
#define FSMC_PIO_IOHIZ4_2 ((u32_t)0x04000000)
#define FSMC_PIO_IOHIZ4_3 ((u32_t)0x08000000)
#define FSMC_PIO_IOHIZ4_4 ((u32_t)0x10000000)
#define FSMC_PIO_IOHIZ4_5 ((u32_t)0x20000000)
#define FSMC_PIO_IOHIZ4_6 ((u32_t)0x40000000)
#define FSMC_PIO_IOHIZ4_7 ((u32_t)0x80000000)

#define FSMC_ECCR_ECC ((u32_t)0xFFFFFFFF)

#endif