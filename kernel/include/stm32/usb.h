#ifndef USB_H
#define USB_H

#warning "Layout not approved"

#include <types.h>

struct usb
{
    volatile u16_t EP0R;
    u16_t RESERVED0;
    volatile u16_t EP1R;
    u16_t RESERVED1;
    volatile u16_t EP2R;
    u16_t RESERVED2;
    volatile u16_t EP3R;
    u16_t RESERVED3;
    volatile u16_t EP4R;
    u16_t RESERVED4;
    volatile u16_t EP5R;
    u16_t RESERVED5;
    volatile u16_t EP6R;
    u16_t RESERVED6;
    volatile u16_t EP7R;
    u16_t RESERVED7;
    u32_t RESERVED8[8];
    volatile u16_t CNTR;
    u16_t RESERVED9;
    volatile u16_t ISTR;
    u16_t RESERVED10;
    volatile u16_t FNR;
    u16_t RESERVED11;
    volatile u16_t DADDR;
    u16_t RESERVED12;
    volatile u16_t BTABLE;
    u16_t RESERVED13;
};

/*

#define USB_ISTR_CTR ((u16_t)0x8000)
#define USB_ISTR_PMAOVR ((u16_t)0x4000)
#define USB_ISTR_ERR ((u16_t)0x2000)
#define USB_ISTR_WKUP ((u16_t)0x1000)
#define USB_ISTR_SUSP ((u16_t)0x0800)
#define USB_ISTR_RESET ((u16_t)0x0400)
#define USB_ISTR_SOF ((u16_t)0x0200)
#define USB_ISTR_ESOF ((u16_t)0x0100)
#define USB_ISTR_L1REQ ((u16_t)0x0080)
#define USB_ISTR_DIR ((u16_t)0x0010)
#define USB_ISTR_EP_ID ((u16_t)0x000F)

#define USB_CLR_CTR (~USB_ISTR_CTR)
#define USB_CLR_PMAOVR (~USB_ISTR_PMAOVR)
#define USB_CLR_ERR (~USB_ISTR_ERR)
#define USB_CLR_WKUP (~USB_ISTR_WKUP)
#define USB_CLR_SUSP (~USB_ISTR_SUSP)
#define USB_CLR_RESET (~USB_ISTR_RESET)
#define USB_CLR_SOF (~USB_ISTR_SOF)
#define USB_CLR_ESOF (~USB_ISTR_ESOF)
#define USB_CLR_L1REQ (~USB_ISTR_L1REQ)

#define USB_CNTR_CTRM ((u16_t)0x8000)
#define USB_CNTR_PMAOVRM ((u16_t)0x4000)
#define USB_CNTR_ERRM ((u16_t)0x2000)
#define USB_CNTR_WKUPM ((u16_t)0x1000)
#define USB_CNTR_SUSPM ((u16_t)0x0800)
#define USB_CNTR_RESETM ((u16_t)0x0400)
#define USB_CNTR_SOFM ((u16_t)0x0200)
#define USB_CNTR_ESOFM ((u16_t)0x0100)
#define USB_CNTR_L1REQM ((u16_t)0x0080)
#define USB_CNTR_L1RESUME ((u16_t)0x0020)
#define USB_CNTR_RESUME ((u16_t)0x0010)
#define USB_CNTR_FSUSP ((u16_t)0x0008)
#define USB_CNTR_LPMODE ((u16_t)0x0004)
#define USB_CNTR_PDWN ((u16_t)0x0002)
#define USB_CNTR_FRES ((u16_t)0x0001)

#define USB_BCDR_DPPU ((u16_t)0x8000)
#define USB_BCDR_PS2DET ((u16_t)0x0080)
#define USB_BCDR_SDET ((u16_t)0x0040)
#define USB_BCDR_PDET ((u16_t)0x0020)
#define USB_BCDR_DCDET ((u16_t)0x0010)
#define USB_BCDR_SDEN ((u16_t)0x0008)
#define USB_BCDR_PDEN ((u16_t)0x0004)
#define USB_BCDR_DCDEN ((u16_t)0x0002)
#define USB_BCDR_BCDEN ((u16_t)0x0001)

#define USB_LPMCSR_BESL ((u16_t)0x00F0)
#define USB_LPMCSR_REMWAKE ((u16_t)0x0008)
#define USB_LPMCSR_LPMACK ((u16_t)0x0002)
#define USB_LPMCSR_LMPEN ((u16_t)0x0001)

#define USB_FNR_RXDP ((u16_t)0x8000)
#define USB_FNR_RXDM ((u16_t)0x4000)
#define USB_FNR_LCK ((u16_t)0x2000)
#define USB_FNR_LSOF ((u16_t)0x1800)
#define USB_FNR_FN ((u16_t)0x07FF)

#define USB_DADDR_EF ((u8_t)0x80)
#define USB_DADDR_ADD ((u8_t)0x7F)

#define USB_EP_CTR_RX ((u16_t)0x8000)
#define USB_EP_DTOG_RX ((u16_t)0x4000)
#define USB_EP_DBUF_TX ((u16_t)0x4000)
#define USB_EP_STAT_RX ((u16_t)0x3000)
#define USB_EP_STAT_RX_1 ((u16_t)0x2000)
#define USB_EP_STAT_RX_0 ((u16_t)0x1000)
#define USB_EP_STAT_RX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_RX_STALL ((u16_t)0x1000)
#define USB_EP_STAT_RX_NAK ((u16_t)0x2000)
#define USB_EP_STAT_RX_VALID ((u16_t)0x3000)
#define USB_EP_SETUP ((u16_t)0x0800)
#define USB_EP_TYPE ((u16_t)0x0600)
#define USB_EP_TYPE_BULK ((u16_t)0x0000)
#define USB_EP_TYPE_CONTROL ((u16_t)0x0200)
#define USB_EP_TYPE_ISOCHRONOUS ((u16_t)0x0400)
#define USB_EP_TYPE_INTERRUPT ((u16_t)0x0600)
#define USB_EP_KIND ((u16_t)0x0100)
#define USB_EP_CTR_TX ((u16_t)0x0080)
#define USB_EP_DTOG_TX ((u16_t)0x0040)
#define USB_EP_DBUF_RX ((u16_t)0x0040)
#define USB_EP_STAT_TX ((u16_t)0x0030)
#define USB_EP_STAT_TX_1 ((u16_t)0x0020)
#define USB_EP_STAT_TX_0 ((u16_t)0x0010)
#define USB_EP_STAT_TX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_TX_STALL ((u16_t)0x0010)
#define USB_EP_STAT_TX_NAK ((u16_t)0x0020)
#define USB_EP_STAT_TX_VALID ((u16_t)0x0030)
#define USB_EP_EA ((u16_t)0x000F)

*/

#define USB ((struct usb *)0x40005C00)

/*#define USB_EP_EA ((u16_t)0x000F)
#define USB_EP_STAT_TX_0 ((u16_t)0x0010)
#define USB_EP_STAT_TX_1 ((u16_t)0x0020)
#define USB_EP_STAT_TX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_TX_STALL ((u16_t)0x0010)
#define USB_EP_STAT_TX_NAK ((u16_t)0x0020)
#define USB_EP_STAT_TX_VALID ((u16_t)0x0030)
#define USB_EP_STAT_TX ((u16_t)0x0030)
#define USB_EP_DTOG_TX ((u16_t)0x0040)
#define USB_EP_DBUF_RX ((u16_t)0x0040)
#define USB_EP_CTR_TX ((u16_t)0x0080)
#define USB_EP_KIND ((u16_t)0x0100)
#define USB_EP_TYPE_BULK ((u16_t)0x0000)
#define USB_EP_TYPE_CONTROL ((u16_t)0x0200)
#define USB_EP_TYPE_ISO ((u16_t)0x0400)
#define USB_EP_TYPE_INTERRUPT ((u16_t)0x0600)
#define USB_EP_TYPE ((u16_t)0x0600)
#define USB_EP_SETUP ((u16_t)0x0800)
#define USB_EP_STAT_RX_0 ((u16_t)0x1000)
#define USB_EP_STAT_RX_1 ((u16_t)0x2000)
#define USB_EP_STAT_RX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_RX_STALL ((u16_t)0x1000)
#define USB_EP_STAT_RX_NAK ((u16_t)0x2000)
#define USB_EP_STAT_RX_VALID ((u16_t)0x3000)
#define USB_EP_STAT_RX ((u16_t)0x3000)
#define USB_EP_DTOG_RX ((u16_t)0x4000)
#define USB_EP_DBUF_TX ((u16_t)0x4000)
#define USB_EP_CTR_RX ((u16_t)0x8000)*/

#define USB_EP_CTR_RX ((u16_t)0x8000)
#define USB_EP_DTOG_RX ((u16_t)0x4000)
#define USB_EP_DBUF_TX ((u16_t)0x4000)
#define USB_EP_STAT_RX ((u16_t)0x3000)
#define USB_EP_STAT_RX_1 ((u16_t)0x2000)
#define USB_EP_STAT_RX_0 ((u16_t)0x1000)
#define USB_EP_STAT_RX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_RX_STALL ((u16_t)0x1000)
#define USB_EP_STAT_RX_NAK ((u16_t)0x2000)
#define USB_EP_STAT_RX_VALID ((u16_t)0x3000)
#define USB_EP_SETUP ((u16_t)0x0800)
#define USB_EP_TYPE ((u16_t)0x0600)
#define USB_EP_TYPE_BULK ((u16_t)0x0000)
#define USB_EP_TYPE_CONTROL ((u16_t)0x0200)
#define USB_EP_TYPE_ISOCHRONOUS ((u16_t)0x0400)
#define USB_EP_TYPE_INTERRUPT ((u16_t)0x0600)
#define USB_EP_KIND ((u16_t)0x0100)
#define USB_EP_CTR_TX ((u16_t)0x0080)
#define USB_EP_DTOG_TX ((u16_t)0x0040)
#define USB_EP_DBUF_RX ((u16_t)0x0040)
#define USB_EP_STAT_TX ((u16_t)0x0030)
#define USB_EP_STAT_TX_1 ((u16_t)0x0020)
#define USB_EP_STAT_TX_0 ((u16_t)0x0010)
#define USB_EP_STAT_TX_DISABLED ((u16_t)0x0000)
#define USB_EP_STAT_TX_STALL ((u16_t)0x0010)
#define USB_EP_STAT_TX_NAK ((u16_t)0x0020)
#define USB_EP_STAT_TX_VALID ((u16_t)0x0030)
#define USB_EP_EA ((u16_t)0x000F)


#define USB_CNTR_FRES ((u16_t)0x0001)
#define USB_CNTR_PDWN ((u16_t)0x0002)
#define USB_CNTR_LP_MODE ((u16_t)0x0004)
#define USB_CNTR_FSUSP ((u16_t)0x0008)
#define USB_CNTR_RESUME ((u16_t)0x0010)
#define USB_CNTR_ESOFM ((u16_t)0x0100)
#define USB_CNTR_SOFM ((u16_t)0x0200)
#define USB_CNTR_RESETM ((u16_t)0x0400)
#define USB_CNTR_SUSPM ((u16_t)0x0800)
#define USB_CNTR_WKUPM ((u16_t)0x1000)
#define USB_CNTR_ERRM ((u16_t)0x2000)
#define USB_CNTR_PMAOVRM ((u16_t)0x4000)
#define USB_CNTR_CTRM ((u16_t)0x8000)

#define USB_ISTR_EP_ID ((u16_t)0x000F)
#define USB_ISTR_DIR ((u16_t)0x0010)
#define USB_ISTR_ESOF ((u16_t)0x0100)
#define USB_ISTR_SOF ((u16_t)0x0200)
#define USB_ISTR_RESET ((u16_t)0x0400)
#define USB_ISTR_SUSP ((u16_t)0x0800)
#define USB_ISTR_WKUP ((u16_t)0x1000)
#define USB_ISTR_ERR ((u16_t)0x2000)
#define USB_ISTR_PMAOVR ((u16_t)0x4000)
#define USB_ISTR_CTR ((u16_t)0x8000)

#define USB_FNR_FN ((u16_t)0x07FF)
#define USB_FNR_LSOF ((u16_t)0x1800)
#define USB_FNR_LCK ((u16_t)0x2000)
#define USB_FNR_RXDM ((u16_t)0x4000)
#define USB_FNR_RXDP ((u16_t)0x8000)

#define USB_DADDR_ADD ((u8_t)0x7F)
#define USB_DADDR_ADD0 ((u8_t)0x01)
#define USB_DADDR_ADD1 ((u8_t)0x02)
#define USB_DADDR_ADD2 ((u8_t)0x04)
#define USB_DADDR_ADD3 ((u8_t)0x08)
#define USB_DADDR_ADD4 ((u8_t)0x10)
#define USB_DADDR_ADD5 ((u8_t)0x20)
#define USB_DADDR_ADD6 ((u8_t)0x40)

#define USB_DADDR_EF ((u8_t)0x80)

#define USB_BTABLE_BTABLE ((u16_t)0xFFF8)

#define USB_ADDR0_TX_ADDR0_TX ((u16_t)0xFFFE)

#define USB_ADDR1_TX_ADDR1_TX ((u16_t)0xFFFE)

#define USB_ADDR2_TX_ADDR2_TX ((u16_t)0xFFFE)

#define USB_ADDR3_TX_ADDR3_TX ((u16_t)0xFFFE)

#define USB_ADDR4_TX_ADDR4_TX ((u16_t)0xFFFE)

#define USB_ADDR5_TX_ADDR5_TX ((u16_t)0xFFFE)

#define USB_ADDR6_TX_ADDR6_TX ((u16_t)0xFFFE)

#define USB_ADDR7_TX_ADDR7_TX ((u16_t)0xFFFE)

#define USB_COUNT0_TX_COUNT0_TX ((u16_t)0x03FF)

#define USB_COUNT1_TX_COUNT1_TX ((u16_t)0x03FF)

#define USB_COUNT2_TX_COUNT2_TX ((u16_t)0x03FF)

#define USB_COUNT3_TX_COUNT3_TX ((u16_t)0x03FF)

#define USB_COUNT4_TX_COUNT4_TX ((u16_t)0x03FF)

#define USB_COUNT5_TX_COUNT5_TX ((u16_t)0x03FF)

#define USB_COUNT6_TX_COUNT6_TX ((u16_t)0x03FF)

#define USB_COUNT7_TX_COUNT7_TX ((u16_t)0x03FF)

#define USB_COUNT0_TX_0_COUNT0_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT0_TX_1_COUNT0_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT1_TX_0_COUNT1_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT1_TX_1_COUNT1_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT2_TX_0_COUNT2_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT2_TX_1_COUNT2_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT3_TX_0_COUNT3_TX_0 ((u16_t)0x000003FF)
#define USB_COUNT3_TX_1_COUNT3_TX_1 ((u16_t)0x03FF0000)

#define USB_COUNT4_TX_0_COUNT4_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT4_TX_1_COUNT4_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT5_TX_0_COUNT5_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT5_TX_1_COUNT5_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT6_TX_0_COUNT6_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT6_TX_1_COUNT6_TX_1 ((u32_t)0x03FF0000)

#define USB_COUNT7_TX_0_COUNT7_TX_0 ((u32_t)0x000003FF)
#define USB_COUNT7_TX_1_COUNT7_TX_1 ((u32_t)0x03FF0000)

#define USB_ADDR0_RX_ADDR0_RX ((u16_t)0xFFFE)

#define USB_ADDR1_RX_ADDR1_RX ((u16_t)0xFFFE)

#define USB_ADDR2_RX_ADDR2_RX ((u16_t)0xFFFE)

#define USB_ADDR3_RX_ADDR3_RX ((u16_t)0xFFFE)

#define USB_ADDR4_RX_ADDR4_RX ((u16_t)0xFFFE)

#define USB_ADDR5_RX_ADDR5_RX ((u16_t)0xFFFE)

#define USB_ADDR6_RX_ADDR6_RX ((u16_t)0xFFFE)

#define USB_ADDR7_RX_ADDR7_RX ((u16_t)0xFFFE)

#define USB_COUNTx_RX_COUNT0_RX ((u16_t)0x03FF)
#define USB_COUNTx_RX_NUM_BLOCK ((u16_t)0x7C00)
#define USB_COUNTx_RX_NUM_BLOCK_0 ((u16_t)0x0400)
#define USB_COUNTx_RX_NUM_BLOCK_1 ((u16_t)0x0800)
#define USB_COUNTx_RX_NUM_BLOCK_2 ((u16_t)0x1000)
#define USB_COUNTx_RX_NUM_BLOCK_3 ((u16_t)0x2000)
#define USB_COUNTx_RX_NUM_BLOCK_4 ((u16_t)0x4000)
#define USB_COUNTx_RX_BLSIZE ((u16_t)0x8000)

#define USB_COUNTx_RX_0_COUNT0_RX_0 ((u32_t)0x000003FF)
#define USB_COUNTx_RX_0_NUM_BLOCK_0 ((u32_t)0x00007C00)
#define USB_COUNTx_RX_0_NUM_BLOCK_0_0 ((u32_t)0x00000400)
#define USB_COUNTx_RX_0_NUM_BLOCK_0_1 ((u32_t)0x00000800)
#define USB_COUNTx_RX_0_NUM_BLOCK_0_2 ((u32_t)0x00001000)
#define USB_COUNTx_RX_0_NUM_BLOCK_0_3 ((u32_t)0x00002000)
#define USB_COUNTx_RX_0_NUM_BLOCK_0_4 ((u32_t)0x00004000)
#define USB_COUNTx_RX_0_BLSIZE_0 ((u32_t)0x00008000)
#define USB_COUNTx_RX_1_COUNT0_RX_1 ((u32_t)0x03FF0000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1 ((u32_t)0x7C000000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1_0 ((u32_t)0x04000000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1_1 ((u32_t)0x08000000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1_2 ((u32_t)0x10000000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1_3 ((u32_t)0x20000000)
#define USB_COUNTx_RX_1_NUM_BLOCK_1_4 ((u32_t)0x40000000)
#define USB_COUNTx_RX_1_BLSIZE_1 ((u32_t)0x80000000)



#define PMA ((u32_t *)0x40006000)

#define USB_PMA_BLSIZE ((u16_t)0x8000)
#define USB_PMA_NUM_BLOCK_4 ((u16_t)0x4000)
#define USB_PMA_NUM_BLOCK_3 ((u16_t)0x2000)
#define USB_PMA_NUM_BLOCK_2 ((u16_t)0x1000)
#define USB_PMA_NUM_BLOCK_1 ((u16_t)0x0800)
#define USB_PMA_NUM_BLOCK_0 ((u16_t)0x0400)
#define USB_PMA_COUNT ((u16_t)0x03FF)

#endif // USB_H
