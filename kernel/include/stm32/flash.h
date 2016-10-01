#ifndef FLASH_H
#define FLASH_H

#warning "Layout not approved"

#include <types.h>

struct flash
{
    volatile u32_t ACR;
    volatile u32_t KEYR;
    volatile u32_t OPTKEYR;
    volatile u32_t SR;
    volatile u32_t CR;
    volatile u32_t AR;
    volatile u32_t RESERVED;
    volatile u32_t OBR;
    volatile u32_t WRPR;
    u32_t RESERVED1[8];
    volatile u32_t KEYR2;
    u32_t RESERVED2;
    volatile u32_t SR2;
    volatile u32_t CR2;
    volatile u32_t AR2;
};

#define FLASH ((struct flash *)0x40022000)

#define FLASH_ACR_LATENCY ((u8_t)0x03)
#define FLASH_ACR_LATENCY_0 ((u8_t)0x00)
#define FLASH_ACR_LATENCY_1 ((u8_t)0x01)
#define FLASH_ACR_LATENCY_2 ((u8_t)0x02)
#define FLASH_ACR_HLFCYA ((u8_t)0x08)
#define FLASH_ACR_PRFTBE ((u8_t)0x10)
#define FLASH_ACR_PRFTBS ((u8_t)0x20)

#define FLASH_KEYR_FKEYR ((u32_t)0xFFFFFFFF)

#define FLASH_OPTKEYR_OPTKEYR ((u32_t)0xFFFFFFFF)

#define FLASH_SR_BSY ((u8_t)0x01)
#define FLASH_SR_PGERR ((u8_t)0x04)
#define FLASH_SR_WRPRTERR ((u8_t)0x10)
#define FLASH_SR_EOP ((u8_t)0x20)

#define FLASH_CR_PG ((u16_t)0x0001)
#define FLASH_CR_PER ((u16_t)0x0002)
#define FLASH_CR_MER ((u16_t)0x0004)
#define FLASH_CR_OPTPG ((u16_t)0x0010)
#define FLASH_CR_OPTER ((u16_t)0x0020)
#define FLASH_CR_STRT ((u16_t)0x0040)
#define FLASH_CR_LOCK ((u16_t)0x0080)
#define FLASH_CR_OPTWRE ((u16_t)0x0200)
#define FLASH_CR_ERRIE ((u16_t)0x0400)
#define FLASH_CR_EOPIE ((u16_t)0x1000)

#define FLASH_AR_FAR ((u32_t)0xFFFFFFFF)

#define FLASH_OBR_OPTERR ((u16_t)0x0001)
#define FLASH_OBR_RDPRT ((u16_t)0x0002)
#define FLASH_OBR_USER ((u16_t)0x03FC)
#define FLASH_OBR_WDG_SW ((u16_t)0x0004)
#define FLASH_OBR_nRST_STOP ((u16_t)0x0008)
#define FLASH_OBR_nRST_STDBY ((u16_t)0x0010)
#define FLASH_OBR_BFB2 ((u16_t)0x0020)

#define FLASH_WRPR_WRP ((u32_t)0xFFFFFFFF)

#define FLASH_RDP_RDP ((u32_t)0x000000FF)
#define FLASH_RDP_NRDP ((u32_t)0x0000FF00)

#define FLASH_USER_USER ((u32_t)0x00FF0000)
#define FLASH_USER_NUSER ((u32_t)0xFF000000)

#define FLASH_DATA0_DATA0 ((u32_t)0x000000FF)
#define FLASH_DATA0_NDATA0 ((u32_t)0x0000FF00)

#define FLASH_DATA1_DATA1 ((u32_t)0x00FF0000)
#define FLASH_DATA1_NDATA1 ((u32_t)0xFF000000)

#define FLASH_WRP0_WRP0 ((u32_t)0x000000FF)
#define FLASH_WRP0_nWRP0 ((u32_t)0x0000FF00)

#define FLASH_WRP1_WRP1 ((u32_t)0x00FF0000)
#define FLASH_WRP1_NWRP1 ((u32_t)0xFF000000)

#define FLASH_WRP2_WRP2 ((u32_t)0x000000FF)
#define FLASH_WRP2_NWRP2 ((u32_t)0x0000FF00)

#define FLASH_WRP3_WRP3 ((u32_t)0x00FF0000)
#define FLASH_WRP3_NWRP3 ((u32_t)0xFF000000)


#endif
