#include "dma.h"
#include "gba.h"
#include "macros.h"

struct Dma {
    const void* pSrc;
    void* pDst;
    u32 control;
};

/**
 * @brief 2f1c | d0 | Peform DMA transfer
 * 
 * @param channel The DMA channel to perform the transfer on
 * @param src The pointer to the source
 * @param dst The pointer to the destination
 * @param len The number of bytes to transfer
 * @param bitSize The number of bits per transfer, either 16 or 32
 */
void DmaTransfer(u8 channel, const void *src, void *dst, u32 len, u8 bitSize)
{
    volatile struct Dma *regDMA;
    volatile struct Dma *pDma;
    volatile struct Dma *_pDma;
    vu32 sizeControl;
    s32 chunkSize;
    u32 nbrHalfWords;
    u32 lengthControl;
    u32 tmp;
    u32 tmp2;
    u32 dmaEnable0;
    u32 dmaEnable1;
    u32 dmaEnable2;

    pDma = (regDMA = REG_DMA0) + channel;

    if (bitSize == 32)
    {
        // Code written like this to match
        tmp = DMA_32BIT;
        tmp <<= 16;
        sizeControl = DMA_32BIT << 16;
    }
    else
    {
        sizeControl = 0;
    }

    tmp2 = channel << 1;
    chunkSize = 0x800;
    nbrHalfWords = bitSize / 16;
    lengthControl = chunkSize >> nbrHalfWords;
    dmaEnable0 = DMA_ENABLE << 16;
    lengthControl |= dmaEnable0;
    tmp2 += channel;
    tmp = tmp2 << 2;

    transferNextChunk:
    while (len > chunkSize)
    {
        pDma->pSrc = src;
        pDma->pDst = dst;

        pDma->control = sizeControl | lengthControl;
        pDma->control;

        _pDma = (volatile struct Dma*)((u8*)regDMA + tmp);
        if (_pDma->control & dmaEnable0)
        {
            dmaEnable1 = DMA_ENABLE << 16;
            waitForDmaEnable1:
            if (_pDma->control & dmaEnable1) goto waitForDmaEnable1;
        }

        len -= 0x800;
        src += chunkSize;
        dst += chunkSize;
        goto transferNextChunk;
    }

    pDma->pSrc = src;
    pDma->pDst = dst;

    len = len >> nbrHalfWords;
    dmaEnable1 = dmaEnable0;
    len = len | dmaEnable1;
    pDma->control = sizeControl | len;
    pDma->control;

    _pDma = (volatile struct Dma*)((u8*)regDMA + tmp);
    if (_pDma->control & dmaEnable1)
    {
        dmaEnable2 = DMA_ENABLE << 16;
        waitForDmaEnable2:
        if (_pDma->control & dmaEnable2) goto waitForDmaEnable2;
    }
}

#ifdef NON_MATCHING
void BitFill(u8 channel, u32 value, void *dst, u32 len, u8 bitSize)
{
    // https://decomp.me/scratch/Qei01

    volatile struct Dma *regDMA; // sl (swapped with r9)
    volatile struct Dma* pDma; // r2
    volatile struct Dma* _pDma; // r1
    vu32 sizeControl; // sp + 0
    u32 lengthControl; // r5 (swapped with r6)
    s32 chunkSize; // r9 (swapped with r8)
    u32 tmp; // ip
    u32 tmp2; // r0
    u32 tmp3; // ??
    u32 tmp4; // r4
    u32 tmp5; // r2
    u32 tmp6; // r8 (swapped with sl)
    u32 *tmp7; // r7
    u32 tmp8;
    u32 dma; // r0 (not needed?)
    

    pDma = (regDMA = REG_DMA0) + channel;

    if (bitSize == 32)
    {
        tmp = DMA_32BIT;
        tmp <<= 16;
        sizeControl = tmp;
    }
    else
    {
        sizeControl = 0;
    }

    tmp2 = channel << 1;
    // lengthControl = 0x800;
    chunkSize = 0x800;
    tmp7 = &value;
    tmp6 = bitSize / 16;
    lengthControl = (0x800 >> (bitSize / 16));
    tmp8 = DMA_ENABLE << 16;
    tmp3 = ((DMA_ENABLE | DMA_SRC_FIXED) << 16);
    lengthControl |= tmp3;
    tmp2 += channel;
    tmp = tmp2 << 2;
    regDMA = REG_DMA0;

    loop:
    // if (len > chunkSize)
    while (len > chunkSize)
    {
        pDma->pSrc = tmp7;
        pDma->pDst = dst;

        pDma->control = sizeControl | lengthControl;
        pDma->control;

        _pDma = (volatile struct Dma*)((u8*)regDMA + tmp);
        dma = _pDma->control;
        tmp4 = DMA_ENABLE << 16;
        goto skip2;
        loop2:
        dma = _pDma->control;
        skip2:
        if ((dma & tmp4) != 0) goto loop2;
        

        len -= 0x800;
        dst += chunkSize;
        goto loop;
    }

    pDma->pSrc = tmp7;
    pDma->pDst = dst;

    len = len >> tmp6;
    tmp4 = tmp3;
    len = len | tmp4;
    pDma->control = sizeControl | len;
    pDma->control;

    _pDma = (volatile struct Dma*)((u8*)regDMA + tmp);
    dma = _pDma->control;
    tmp4 = tmp8;
    if (dma & (tmp4))
    {
        tmp5 = tmp4;
        loop3:
        dma = _pDma->control;
        if ((dma & tmp5) != 0) goto loop3;
    }
}
#else
NAKED_FUNCTION
void BitFill(u8 channel, u32 value, void *dst, u32 len, u8 bitSize)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    sub sp, #8 \n\
    str r1, [sp, #4] \n\
    add r6, r2, #0 \n\
    ldr r1, [sp, #0x28] \n\
    lsl r0, r0, #0x18 \n\
    lsr r4, r0, #0x18 \n\
    lsl r1, r1, #0x18 \n\
    lsr r1, r1, #0x18 \n\
    lsl r0, r4, #1 \n\
    add r0, r0, r4 \n\
    lsl r0, r0, #2 \n\
    ldr r5, lbl_080032e4 @ =0x040000b0 \n\
    add r2, r0, r5 \n\
    cmp r1, #0x20 \n\
    bne lbl_080032e8 \n\
    movs r0, #0x80 \n\
    lsl r0, r0, #0x13 \n\
    b lbl_080032ea \n\
    .align 2, 0 \n\
lbl_080032e4: .4byte 0x040000b0 \n\
lbl_080032e8: \n\
    movs r0, #0 \n\
lbl_080032ea: \n\
    str r0, [sp] \n\
    lsl r0, r4, #1 \n\
    movs r5, #0x80 \n\
    lsl r5, r5, #4 \n\
    mov sb, r5 \n\
    add r7, sp, #4 \n\
    lsr r1, r1, #4 \n\
    mov r8, r1 \n\
    asr r5, r1 \n\
    movs r1, #0x81 \n\
    lsl r1, r1, #0x18 \n\
    orr r5, r1 \n\
    add r0, r0, r4 \n\
    lsl r0, r0, #2 \n\
    mov ip, r0 \n\
    ldr r4, lbl_08003328 @ =0x040000b0 \n\
    mov sl, r4 \n\
lbl_0800330c: \n\
    cmp r3, sb \n\
    bls lbl_08003340 \n\
    str r7, [r2] \n\
    str r6, [r2, #4] \n\
    ldr r0, [sp] \n\
    orr r0, r5 \n\
    str r0, [r2, #8] \n\
    ldr r0, [r2, #8] \n\
    mov r1, ip \n\
    add r1, sl \n\
    ldr r0, [r1, #8] \n\
    movs r4, #0x80 \n\
    lsl r4, r4, #0x18 \n\
    b lbl_0800332e \n\
    .align 2, 0 \n\
lbl_08003328: .4byte 0x040000b0 \n\
lbl_0800332c: \n\
    ldr r0, [r1, #8] \n\
lbl_0800332e: \n\
    and r0, r4 \n\
    cmp r0, #0 \n\
    bne lbl_0800332c \n\
    ldr r0, lbl_0800333c @ =0xfffff800 \n\
    add r3, r3, r0 \n\
    add r6, sb \n\
    b lbl_0800330c \n\
    .align 2, 0 \n\
lbl_0800333c: .4byte 0xfffff800 \n\
lbl_08003340: \n\
    str r7, [r2] \n\
    str r6, [r2, #4] \n\
    mov r1, r8 \n\
    lsr r3, r1 \n\
    movs r4, #0x81 \n\
    lsl r4, r4, #0x18 \n\
    orr r3, r4 \n\
    ldr r0, [sp] \n\
    orr r0, r3 \n\
    str r0, [r2, #8] \n\
    ldr r0, [r2, #8] \n\
    mov r1, ip \n\
    add r1, sl \n\
    ldr r0, [r1, #8] \n\
    movs r5, #0x80 \n\
    lsl r5, r5, #0x18 \n\
    and r0, r5 \n\
    cmp r0, #0 \n\
    beq lbl_08003370 \n\
    add r2, r5, #0 \n\
lbl_08003368: \n\
    ldr r0, [r1, #8] \n\
    and r0, r2 \n\
    cmp r0, #0 \n\
    bne lbl_08003368 \n\
lbl_08003370: \n\
    add sp, #8 \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    ");
}
#endif
