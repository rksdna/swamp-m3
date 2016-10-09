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

#ifndef ETH_H
#define ETH_H

#include <types.h>

struct eth
{
    volatile u32_t MACCR;
    volatile u32_t MACFFR;
    volatile u32_t MACHTHR;
    volatile u32_t MACHTLR;
    volatile u32_t MACMIIAR;
    volatile u32_t MACMIIDR;
    volatile u32_t MACFCR;
    volatile u32_t MACVLANTR;
    u32_t RESERVED0[2];
    volatile u32_t MACRWUFFR;
    volatile u32_t MACPMTCSR;
    u32_t RESERVED1[2];
    volatile u32_t MACSR;
    volatile u32_t MACIMR;
    volatile u32_t MACA0HR;
    volatile u32_t MACA0LR;
    volatile u32_t MACA1HR;
    volatile u32_t MACA1LR;
    volatile u32_t MACA2HR;
    volatile u32_t MACA2LR;
    volatile u32_t MACA3HR;
    volatile u32_t MACA3LR;
    u32_t RESERVED2[40];
    volatile u32_t MMCCR;
    volatile u32_t MMCRIR;
    volatile u32_t MMCTIR;
    volatile u32_t MMCRIMR;
    volatile u32_t MMCTIMR;
    u32_t RESERVED3[14];
    volatile u32_t MMCTGFSCCR;
    volatile u32_t MMCTGFMSCCR;
    u32_t RESERVED4[5];
    volatile u32_t MMCTGFCR;
    u32_t RESERVED5[10];
    volatile u32_t MMCRFCECR;
    volatile u32_t MMCRFAECR;
    u32_t RESERVED6[10];
    volatile u32_t MMCRGUFCR;
    u32_t RESERVED7[334];
    volatile u32_t PTPTSCR;
    volatile u32_t PTPSSIR;
    volatile u32_t PTPTSHR;
    volatile u32_t PTPTSLR;
    volatile u32_t PTPTSHUR;
    volatile u32_t PTPTSLUR;
    volatile u32_t PTPTSAR;
    volatile u32_t PTPTTHR;
    volatile u32_t PTPTTLR;
    u32_t RESERVED8[567];
    volatile u32_t DMABMR;
    volatile u32_t DMATPDR;
    volatile u32_t DMARPDR;
    volatile u32_t DMARDLAR;
    volatile u32_t DMATDLAR;
    volatile u32_t DMASR;
    volatile u32_t DMAOMR;
    volatile u32_t DMAIER;
    volatile u32_t DMAMFBOCR;
    u32_t RESERVED9[9];
    volatile u32_t DMACHTDR;
    volatile u32_t DMACHRDR;
    volatile u32_t DMACHTBAR;
    volatile u32_t DMACHRBAR;
};

struct eth_tx
{
    volatile u32_t TDES0;
    volatile u32_t TDES1;
    volatile u32_t TDES2;
    volatile u32_t TDES3;
};

struct eth_rx
{
    volatile u32_t RDES0;
    volatile u32_t RDES1;
    volatile u32_t RDES2;
    volatile u32_t RDES3;
};

#define ETH ((struct eth *)0x40028000)

#define ETH_MACCR_WD ((u32_t)0x00800000)
#define ETH_MACCR_JD ((u32_t)0x00400000)
#define ETH_MACCR_IFG ((u32_t)0x000E0000)
#define ETH_MACCR_IFG_96BIT ((u32_t)0x00000000)
#define ETH_MACCR_IFG_88BIT ((u32_t)0x00020000)
#define ETH_MACCR_IFG_80BIT ((u32_t)0x00040000)
#define ETH_MACCR_IFG_72BIT ((u32_t)0x00060000)
#define ETH_MACCR_IFG_64BIT ((u32_t)0x00080000)
#define ETH_MACCR_IFG_56BIT ((u32_t)0x000A0000)
#define ETH_MACCR_IFG_48BIT ((u32_t)0x000C0000)
#define ETH_MACCR_IFG_40BIT ((u32_t)0x000E0000)
#define ETH_MACCR_CSD ((u32_t)0x00010000)
#define ETH_MACCR_FES ((u32_t)0x00004000)
#define ETH_MACCR_ROD ((u32_t)0x00002000)
#define ETH_MACCR_LM ((u32_t)0x00001000)
#define ETH_MACCR_DM ((u32_t)0x00000800)
#define ETH_MACCR_IPCO ((u32_t)0x00000400)
#define ETH_MACCR_RD ((u32_t)0x00000200)
#define ETH_MACCR_APCS ((u32_t)0x00000080)
#define ETH_MACCR_BL ((u32_t)0x00000060)
#define ETH_MACCR_BL_10 ((u32_t)0x00000000)
#define ETH_MACCR_BL_8 ((u32_t)0x00000020)
#define ETH_MACCR_BL_4 ((u32_t)0x00000040)
#define ETH_MACCR_BL_1 ((u32_t)0x00000060)
#define ETH_MACCR_DC ((u32_t)0x00000010)
#define ETH_MACCR_TE ((u32_t)0x00000008)
#define ETH_MACCR_RE ((u32_t)0x00000004)

#define ETH_MACFFR_RA ((u32_t)0x80000000)
#define ETH_MACFFR_HPF ((u32_t)0x00000400)
#define ETH_MACFFR_SAF ((u32_t)0x00000200)
#define ETH_MACFFR_SAIF ((u32_t)0x00000100)
#define ETH_MACFFR_PCF ((u32_t)0x000000C0)
#define ETH_MACFFR_PCF_BLOCKALL ((u32_t)0x00000040)
#define ETH_MACFFR_PCF_FORWARDALL ((u32_t)0x00000080)
#define ETH_MACFFR_PCF_FORWARDPASSEDFILTER ((u32_t)0x000000C0)
#define ETH_MACFFR_BFD ((u32_t)0x00000020)
#define ETH_MACFFR_PAM ((u32_t)0x00000010)
#define ETH_MACFFR_DAIF ((u32_t)0x00000008)
#define ETH_MACFFR_HM ((u32_t)0x00000004)
#define ETH_MACFFR_HU ((u32_t)0x00000002)
#define ETH_MACFFR_PM ((u32_t)0x00000001)

#define ETH_MACHTHR_HTH ((u32_t)0xFFFFFFFF)

#define ETH_MACHTLR_HTL ((u32_t)0xFFFFFFFF)

#define ETH_MACMIIAR_PA ((u32_t)0x0000F800)
#define ETH_MACMIIAR_MR ((u32_t)0x000007C0)
#define ETH_MACMIIAR_CR ((u32_t)0x0000001C)
#define ETH_MACMIIAR_CR_DIV42 ((u32_t)0x00000000)
#define ETH_MACMIIAR_CR_DIV16 ((u32_t)0x00000008)
#define ETH_MACMIIAR_CR_DIV26 ((u32_t)0x0000000C)
#define ETH_MACMIIAR_MW ((u32_t)0x00000002)
#define ETH_MACMIIAR_MB ((u32_t)0x00000001)

#define ETH_MACMIIDR_MD ((u32_t)0x0000FFFF)

#define ETH_MACFCR_PT ((u32_t)0xFFFF0000)
#define ETH_MACFCR_ZQPD ((u32_t)0x00000080)
#define ETH_MACFCR_PLT ((u32_t)0x00000030)
#define ETH_MACFCR_PLT_MINUS4 ((u32_t)0x00000000)
#define ETH_MACFCR_PLT_MINUS28 ((u32_t)0x00000010)
#define ETH_MACFCR_PLT_MINUS144 ((u32_t)0x00000020)
#define ETH_MACFCR_PLT_MINUS256 ((u32_t)0x00000030)
#define ETH_MACFCR_UPFD ((u32_t)0x00000008)
#define ETH_MACFCR_RFCE ((u32_t)0x00000004)
#define ETH_MACFCR_TFCE ((u32_t)0x00000002)
#define ETH_MACFCR_FCBBPA ((u32_t)0x00000001)

#define ETH_MACVLANTR_VLANTC ((u32_t)0x00010000)
#define ETH_MACVLANTR_VLANTI ((u32_t)0x0000FFFF)

#define ETH_MACRWUFFR_D ((u32_t)0xFFFFFFFF)

#define ETH_MACPMTCSR_WFFRPR ((u32_t)0x80000000)
#define ETH_MACPMTCSR_GU ((u32_t)0x00000200)
#define ETH_MACPMTCSR_WFR ((u32_t)0x00000040)
#define ETH_MACPMTCSR_MPR ((u32_t)0x00000020)
#define ETH_MACPMTCSR_WFE ((u32_t)0x00000004)
#define ETH_MACPMTCSR_MPE ((u32_t)0x00000002)
#define ETH_MACPMTCSR_PD ((u32_t)0x00000001)

#define ETH_MACSR_TSTS ((u32_t)0x00000200)
#define ETH_MACSR_MMCTS ((u32_t)0x00000040)
#define ETH_MACSR_MMMCRS ((u32_t)0x00000020)
#define ETH_MACSR_MMCS ((u32_t)0x00000010)
#define ETH_MACSR_PMTS ((u32_t)0x00000008)

#define ETH_MACIMR_TSTIM ((u32_t)0x00000200)
#define ETH_MACIMR_PMTIM ((u32_t)0x00000008)

#define ETH_MACA0HR_MACA0H ((u32_t)0x0000FFFF)

#define ETH_MACA0LR_MACA0L ((u32_t)0xFFFFFFFF)

#define ETH_MACA1HR_AE ((u32_t)0x80000000)
#define ETH_MACA1HR_SA ((u32_t)0x40000000)
#define ETH_MACA1HR_MBC ((u32_t)0x3F000000)
#define ETH_MACA1HR_MBC_HBITS15_8 ((u32_t)0x20000000)
#define ETH_MACA1HR_MBC_HBITS7_0 ((u32_t)0x10000000)
#define ETH_MACA1HR_MBC_LBITS31_24 ((u32_t)0x08000000)
#define ETH_MACA1HR_MBC_LBITS23_16 ((u32_t)0x04000000)
#define ETH_MACA1HR_MBC_LBITS15_8 ((u32_t)0x02000000)
#define ETH_MACA1HR_MBC_LBITS7_0 ((u32_t)0x01000000)
#define ETH_MACA1HR_MACA1H ((u32_t)0x0000FFFF)

#define ETH_MACA1LR_MACA1L ((u32_t)0xFFFFFFFF)

#define ETH_MACA2HR_AE ((u32_t)0x80000000)
#define ETH_MACA2HR_SA ((u32_t)0x40000000)
#define ETH_MACA2HR_MBC ((u32_t)0x3F000000)
#define ETH_MACA2HR_MBC_HBITS15_8 ((u32_t)0x20000000)
#define ETH_MACA2HR_MBC_HBITS7_0 ((u32_t)0x10000000)
#define ETH_MACA2HR_MBC_LBITS31_24 ((u32_t)0x08000000)
#define ETH_MACA2HR_MBC_LBITS23_16 ((u32_t)0x04000000)
#define ETH_MACA2HR_MBC_LBITS15_8 ((u32_t)0x02000000)
#define ETH_MACA2HR_MBC_LBITS7_0 ((u32_t)0x01000000)
#define ETH_MACA2HR_MACA2H ((u32_t)0x0000FFFF)

#define ETH_MACA2LR_MACA2L ((u32_t)0xFFFFFFFF)

#define ETH_MACA3HR_AE ((u32_t)0x80000000)
#define ETH_MACA3HR_SA ((u32_t)0x40000000)
#define ETH_MACA3HR_MBC ((u32_t)0x3F000000)
#define ETH_MACA3HR_MBC_HBITS15_8 ((u32_t)0x20000000)
#define ETH_MACA3HR_MBC_HBITS7_0 ((u32_t)0x10000000)
#define ETH_MACA3HR_MBC_LBITS31_24 ((u32_t)0x08000000)
#define ETH_MACA3HR_MBC_LBITS23_16 ((u32_t)0x04000000)
#define ETH_MACA3HR_MBC_LBITS15_8 ((u32_t)0x02000000)
#define ETH_MACA3HR_MBC_LBITS7_0 ((u32_t)0x01000000)
#define ETH_MACA3HR_MACA3H ((u32_t)0x0000FFFF)

#define ETH_MACA3LR_MACA3L ((u32_t)0xFFFFFFFF)

#define ETH_MMCCR_MCF ((u32_t)0x00000008)
#define ETH_MMCCR_ROR ((u32_t)0x00000004)
#define ETH_MMCCR_CSR ((u32_t)0x00000002)
#define ETH_MMCCR_CR ((u32_t)0x00000001)

#define ETH_MMCRIR_RGUFS ((u32_t)0x00020000)
#define ETH_MMCRIR_RFAES ((u32_t)0x00000040)
#define ETH_MMCRIR_RFCES ((u32_t)0x00000020)

#define ETH_MMCTIR_TGFS ((u32_t)0x00200000)
#define ETH_MMCTIR_TGFMSCS ((u32_t)0x00008000)
#define ETH_MMCTIR_TGFSCS ((u32_t)0x00004000)

#define ETH_MMCRIMR_RGUFM ((u32_t)0x00020000)
#define ETH_MMCRIMR_RFAEM ((u32_t)0x00000040)
#define ETH_MMCRIMR_RFCEM ((u32_t)0x00000020)

#define ETH_MMCTIMR_TGFM ((u32_t)0x00200000)
#define ETH_MMCTIMR_TGFMSCM ((u32_t)0x00008000)
#define ETH_MMCTIMR_TGFSCM ((u32_t)0x00004000)

#define ETH_MMCTGFSCCR_TGFSCC ((u32_t)0xFFFFFFFF)

#define ETH_MMCTGFMSCCR_TGFMSCC ((u32_t)0xFFFFFFFF)

#define ETH_MMCTGFCR_TGFC ((u32_t)0xFFFFFFFF)

#define ETH_MMCRFCECR_RFCEC ((u32_t)0xFFFFFFFF)

#define ETH_MMCRFAECR_RFAEC ((u32_t)0xFFFFFFFF)

#define ETH_MMCRGUFCR_RGUFC ((u32_t)0xFFFFFFFF)

#define ETH_PTPTSCR_TSARU ((u32_t)0x00000020)
#define ETH_PTPTSCR_TSITE ((u32_t)0x00000010)
#define ETH_PTPTSCR_TSSTU ((u32_t)0x00000008)
#define ETH_PTPTSCR_TSSTI ((u32_t)0x00000004)
#define ETH_PTPTSCR_TSFCU ((u32_t)0x00000002)
#define ETH_PTPTSCR_TSE ((u32_t)0x00000001)

#define ETH_PTPSSIR_STSSI ((u32_t)0x000000FF)

#define ETH_PTPTSHR_STS ((u32_t)0xFFFFFFFF)

#define ETH_PTPTSLR_STPNS ((u32_t)0x80000000)
#define ETH_PTPTSLR_STSS ((u32_t)0x7FFFFFFF)

#define ETH_PTPTSHUR_TSUS ((u32_t)0xFFFFFFFF)

#define ETH_PTPTSLUR_TSUPNS ((u32_t)0x80000000)
#define ETH_PTPTSLUR_TSUSS ((u32_t)0x7FFFFFFF)

#define ETH_PTPTSAR_TSA ((u32_t)0xFFFFFFFF)

#define ETH_PTPTTHR_TTSH ((u32_t)0xFFFFFFFF)

#define ETH_PTPTTLR_TTSL ((u32_t)0xFFFFFFFF)

#define ETH_DMABMR_AAB ((u32_t)0x02000000)
#define ETH_DMABMR_FPM ((u32_t)0x01000000)
#define ETH_DMABMR_USP ((u32_t)0x00800000)
#define ETH_DMABMR_RDP ((u32_t)0x007E0000)
#define ETH_DMABMR_RDP_1BEAT ((u32_t)0x00020000)
#define ETH_DMABMR_RDP_2BEAT ((u32_t)0x00040000)
#define ETH_DMABMR_RDP_4BEAT ((u32_t)0x00080000)
#define ETH_DMABMR_RDP_8BEAT ((u32_t)0x00100000)
#define ETH_DMABMR_RDP_16BEAT ((u32_t)0x00200000)
#define ETH_DMABMR_RDP_32BEAT ((u32_t)0x00400000)
#define ETH_DMABMR_RDP_4PBL_4BEAT ((u32_t)0x01020000)
#define ETH_DMABMR_RDP_4PBL_8BEAT ((u32_t)0x01040000)
#define ETH_DMABMR_RDP_4PBL_16BEAT ((u32_t)0x01080000)
#define ETH_DMABMR_RDP_4PBL_32BEAT ((u32_t)0x01100000)
#define ETH_DMABMR_RDP_4PBL_64BEAT ((u32_t)0x01200000)
#define ETH_DMABMR_RDP_4PBL_128BEAT ((u32_t)0x01400000)
#define ETH_DMABMR_FB ((u32_t)0x00010000)
#define ETH_DMABMR_RTPR ((u32_t)0x0000C000)
#define ETH_DMABMR_RTPR_1_1 ((u32_t)0x00000000)
#define ETH_DMABMR_RTPR_2_1 ((u32_t)0x00004000)
#define ETH_DMABMR_RTPR_3_1 ((u32_t)0x00008000)
#define ETH_DMABMR_RTPR_4_1 ((u32_t)0x0000C000)
#define ETH_DMABMR_PBL ((u32_t)0x00003F00)
#define ETH_DMABMR_PBL_1BEAT ((u32_t)0x00000100)
#define ETH_DMABMR_PBL_2BEAT ((u32_t)0x00000200)
#define ETH_DMABMR_PBL_4BEAT ((u32_t)0x00000400)
#define ETH_DMABMR_PBL_8BEAT ((u32_t)0x00000800)
#define ETH_DMABMR_PBL_16BEAT ((u32_t)0x00001000)
#define ETH_DMABMR_PBL_32BEAT ((u32_t)0x00002000)
#define ETH_DMABMR_PBL_4PBL_4BEAT ((u32_t)0x01000100)
#define ETH_DMABMR_PBL_4PBL_8BEAT ((u32_t)0x01000200)
#define ETH_DMABMR_PBL_4PBL_16BEAT ((u32_t)0x01000400)
#define ETH_DMABMR_PBL_4PBL_32BEAT ((u32_t)0x01000800)
#define ETH_DMABMR_PBL_4PBL_64BEAT ((u32_t)0x01001000)
#define ETH_DMABMR_PBL_4PBL_128BEAT ((u32_t)0x01002000)
#define ETH_DMABMR_DSL ((u32_t)0x0000007C)
#define ETH_DMABMR_DA ((u32_t)0x00000002)
#define ETH_DMABMR_SR ((u32_t)0x00000001)

#define ETH_DMATPDR_TPD ((u32_t)0xFFFFFFFF)
#define ETH_DMARPDR_RPD ((u32_t)0xFFFFFFFF)
#define ETH_DMARDLAR_SRL ((u32_t)0xFFFFFFFF)
#define ETH_DMATDLAR_STL ((u32_t)0xFFFFFFFF)

#define ETH_DMASR_TSTS ((u32_t)0x20000000)
#define ETH_DMASR_PMTS ((u32_t)0x10000000)
#define ETH_DMASR_MMCS ((u32_t)0x08000000)
#define ETH_DMASR_EBS ((u32_t)0x03800000)
#define ETH_DMASR_EBS_DESCACCESS ((u32_t)0x02000000)
#define ETH_DMASR_EBS_READTRANSF ((u32_t)0x01000000)
#define ETH_DMASR_EBS_DATATRANSFTX ((u32_t)0x00800000)
#define ETH_DMASR_TPS ((u32_t)0x00700000)
#define ETH_DMASR_TPS_STOPPED ((u32_t)0x00000000)
#define ETH_DMASR_TPS_FETCHING ((u32_t)0x00100000)
#define ETH_DMASR_TPS_WAITING ((u32_t)0x00200000)
#define ETH_DMASR_TPS_READING ((u32_t)0x00300000)
#define ETH_DMASR_TPS_SUSPENDED ((u32_t)0x00600000)
#define ETH_DMASR_TPS_CLOSING ((u32_t)0x00700000)
#define ETH_DMASR_RPS ((u32_t)0x000E0000)
#define ETH_DMASR_RPS_STOPPED ((u32_t)0x00000000)
#define ETH_DMASR_RPS_FETCHING ((u32_t)0x00020000)
#define ETH_DMASR_RPS_WAITING ((u32_t)0x00060000)
#define ETH_DMASR_RPS_SUSPENDED ((u32_t)0x00080000)
#define ETH_DMASR_RPS_CLOSING ((u32_t)0x000A0000)
#define ETH_DMASR_RPS_QUEUING ((u32_t)0x000E0000)
#define ETH_DMASR_NIS ((u32_t)0x00010000)
#define ETH_DMASR_AIS ((u32_t)0x00008000)
#define ETH_DMASR_ERS ((u32_t)0x00004000)
#define ETH_DMASR_FBES ((u32_t)0x00002000)
#define ETH_DMASR_ETS ((u32_t)0x00000400)
#define ETH_DMASR_RWTS ((u32_t)0x00000200)
#define ETH_DMASR_RPSS ((u32_t)0x00000100)
#define ETH_DMASR_RBUS ((u32_t)0x00000080)
#define ETH_DMASR_RS ((u32_t)0x00000040)
#define ETH_DMASR_TUS ((u32_t)0x00000020)
#define ETH_DMASR_ROS ((u32_t)0x00000010)
#define ETH_DMASR_TJTS ((u32_t)0x00000008)
#define ETH_DMASR_TBUS ((u32_t)0x00000004)
#define ETH_DMASR_TPSS ((u32_t)0x00000002)
#define ETH_DMASR_TS ((u32_t)0x00000001)

#define ETH_DMAOMR_DTCEFD ((u32_t)0x04000000)
#define ETH_DMAOMR_RSF ((u32_t)0x02000000)
#define ETH_DMAOMR_DFRF ((u32_t)0x01000000)
#define ETH_DMAOMR_TSF ((u32_t)0x00200000)
#define ETH_DMAOMR_FTF ((u32_t)0x00100000)
#define ETH_DMAOMR_TTC ((u32_t)0x0001C000)
#define ETH_DMAOMR_TTC_64BYTES ((u32_t)0x00000000)
#define ETH_DMAOMR_TTC_128BYTES ((u32_t)0x00004000)
#define ETH_DMAOMR_TTC_192BYTES ((u32_t)0x00008000)
#define ETH_DMAOMR_TTC_256BYTES ((u32_t)0x0000C000)
#define ETH_DMAOMR_TTC_40BYTES ((u32_t)0x00010000)
#define ETH_DMAOMR_TTC_32BYTES ((u32_t)0x00014000)
#define ETH_DMAOMR_TTC_24BYTES ((u32_t)0x00018000)
#define ETH_DMAOMR_TTC_16BYTES ((u32_t)0x0001C000)
#define ETH_DMAOMR_ST ((u32_t)0x00002000)
#define ETH_DMAOMR_FEF ((u32_t)0x00000080)
#define ETH_DMAOMR_FUGF ((u32_t)0x00000040)
#define ETH_DMAOMR_RTC ((u32_t)0x00000018)
#define ETH_DMAOMR_RTC_64BYTES ((u32_t)0x00000000)
#define ETH_DMAOMR_RTC_32BYTES ((u32_t)0x00000008)
#define ETH_DMAOMR_RTC_96BYTES ((u32_t)0x00000010)
#define ETH_DMAOMR_RTC_128BYTES ((u32_t)0x00000018)
#define ETH_DMAOMR_OSF ((u32_t)0x00000004)
#define ETH_DMAOMR_SR ((u32_t)0x00000002)

#define ETH_DMAIER_NISE ((u32_t)0x00010000)
#define ETH_DMAIER_AISE ((u32_t)0x00008000)
#define ETH_DMAIER_ERIE ((u32_t)0x00004000)
#define ETH_DMAIER_FBEIE ((u32_t)0x00002000)
#define ETH_DMAIER_ETIE ((u32_t)0x00000400)
#define ETH_DMAIER_RWTIE ((u32_t)0x00000200)
#define ETH_DMAIER_RPSIE ((u32_t)0x00000100)
#define ETH_DMAIER_RBUIE ((u32_t)0x00000080)
#define ETH_DMAIER_RIE ((u32_t)0x00000040)
#define ETH_DMAIER_TUIE ((u32_t)0x00000020)
#define ETH_DMAIER_ROIE ((u32_t)0x00000010)
#define ETH_DMAIER_TJTIE ((u32_t)0x00000008)
#define ETH_DMAIER_TBUIE ((u32_t)0x00000004)
#define ETH_DMAIER_TPSIE ((u32_t)0x00000002)
#define ETH_DMAIER_TIE ((u32_t)0x00000001)

#define ETH_DMAMFBOCR_OFOC ((u32_t)0x10000000)
#define ETH_DMAMFBOCR_MFA ((u32_t)0x0FFE0000)
#define ETH_DMAMFBOCR_OMFC ((u32_t)0x00010000)
#define ETH_DMAMFBOCR_MFC ((u32_t)0x0000FFFF)

#define ETH_DMACHTDR_HTDAP ((u32_t)0xFFFFFFFF)

#define ETH_DMACHRDR_HRDAP ((u32_t)0xFFFFFFFF)

#define ETH_DMACHTBAR_HTBAP ((u32_t)0xFFFFFFFF)

#define ETH_DMACHRBAR_HRBAP ((u32_t)0xFFFFFFFF)

#define ETH_TDES0_OWN ((u32_t)0x80000000)
#define ETH_TDES0_IC ((u32_t)0x40000000)
#define ETH_TDES0_LS ((u32_t)0x20000000)
#define ETH_TDES0_FS ((u32_t)0x10000000)
#define ETH_TDES0_DC ((u32_t)0x08000000)
#define ETH_TDES0_DP ((u32_t)0x04000000)
#define ETH_TDES0_TTSE ((u32_t)0x02000000)
#define ETH_TDES0_CIC ((u32_t)0x00C00000)
#define ETH_TDES0_TER ((u32_t)0x00200000)
#define ETH_TDES0_TCH ((u32_t)0x00100000)
#define ETH_TDES0_TTSS ((u32_t)0x00020000)
#define ETH_TDES0_IHE ((u32_t)0x00010000)
#define ETH_TDES0_ES ((u32_t)0x00008000)
#define ETH_TDES0_JT ((u32_t)0x00004000)
#define ETH_TDES0_FF ((u32_t)0x00002000)
#define ETH_TDES0_IPE ((u32_t)0x00001000)
#define ETH_TDES0_LCA ((u32_t)0x00000800)
#define ETH_TDES0_NC ((u32_t)0x00000400)
#define ETH_TDES0_LCO ((u32_t)0x00000200)
#define ETH_TDES0_EC ((u32_t)0x00000100)
#define ETH_TDES0_VF ((u32_t)0x00000080)
#define ETH_TDES0_CC ((u32_t)0x00000078)
#define ETH_TDES0_ED ((u32_t)0x00000004)
#define ETH_TDES0_UF ((u32_t)0x00000002)
#define ETH_TDES0_DB ((u32_t)0x00000001)

#define ETH_TDES1_TBS2 ((u32_t)0x1FFF0000)
#define ETH_TDES1_TBS1 ((u32_t)0x00001FFF)

#define ETH_TDES2_TBAP1 ((u32_t)0xFFFFFFFF)

#define ETH_TDES3_TBAP2 ((u32_t)0xFFFFFFFF)

#define ETH_RDES0_OWN ((u32_t)0x80000000)
#define ETH_RDES0_AFM ((u32_t)0x40000000)
#define ETH_RDES0_FL ((u32_t)0x3FFF0000)
#define ETH_RDES0_ES ((u32_t)0x00008000)
#define ETH_RDES0_DE ((u32_t)0x00004000)
#define ETH_RDES0_SAF ((u32_t)0x00002000)
#define ETH_RDES0_LE ((u32_t)0x00001000)
#define ETH_RDES0_OE ((u32_t)0x00000800)
#define ETH_RDES0_VLAN ((u32_t)0x00000400)
#define ETH_RDES0_FS ((u32_t)0x00000200)
#define ETH_RDES0_LS  ((u32_t)0x00000100)
#define ETH_RDES0_IPHCE ((u32_t)0x00000080)
#define ETH_RDES0_LCO ((u32_t)0x00000040)
#define ETH_RDES0_FT ((u32_t)0x00000020)
#define ETH_RDES0_RWT ((u32_t)0x00000010)
#define ETH_RDES0_RE ((u32_t)0x00000008)
#define ETH_RDES0_DBE ((u32_t)0x00000004)
#define ETH_RDES0_CE ((u32_t)0x00000002)
#define ETH_RDES0_PCE ((u32_t)0x00000001)

#define ETH_RDES1_DIC ((u32_t)0x80000000)
#define ETH_RDES1_RBS2 ((u32_t)0x1FFF0000)
#define ETH_RDES1_RER ((u32_t)0x00008000)
#define ETH_RDES1_RCH ((u32_t)0x00004000)
#define ETH_RDES1_RBS1 ((u32_t)0x00001FFF)

#define ETH_RDES2_RBAP1 ((u32_t)0xFFFFFFFF)

#define ETH_RDES3_RBAP2 ((u32_t)0xFFFFFFFF)

#endif
