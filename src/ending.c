#include "globals.h"
#include "init_helpers.h"
#include "macros.h"

#include "structs/ending.h"

extern void EndingDrawIgtAndCompletionPercentage();
extern void EndingImageDisplayLinePermanently(s32);
extern void EndingImageLoadTextOam(s32);
extern void EndingImageUpdateLettersSpawnDelay(s32);
extern void unk_a1cfc(void);
extern void EndingImageVblank(void);



boolu32 EndingImageInit(void) 
{
    s32 temp;
    s32 i;
    u32 value;
    
    WRITE_16(REG_IME, 0);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~16);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~2);
    WRITE_16(REG_IME, 1);

    CallbackSetVBlank(unk_a1cfc);

    WRITE_16(REG_DISPCNT, 0);
    
    if (gNonGameplayRam.ending.unk_9A > 99)
    {
        temp = 3;

        if (gNonGameplayRam.ending.unk_99 == 2)
        {
            temp = 4;
        }
    }
    else
    {
        temp = gNonGameplayRam.ending.unk_99;
    }

    switch (temp)
    {
        case 0:
            LZ77UncompVram(0x08761a88, VRAM_BASE);
            LZ77UncompVram(0x08767278, VRAM_BASE + 0x8000);
            LZ77UncompVram(0x0878fd10, VRAM_BASE + 0xF000);
            LZ77UncompVram(0x087905ac, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x08749d58, PALRAM_BASE, 256);
            break;

        case 1:
            LZ77UncompVram(0x0876a454, VRAM_BASE);
            LZ77UncompVram(0x08770084, VRAM_BASE + 0x8000);
            LZ77UncompVram(0x08790b6c, VRAM_BASE + 0xF000);
            LZ77UncompVram(0x08791408, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x08749f58, PALRAM_BASE, 256);
            break;

        case 2:
            LZ77UncompVram(0x08772f2c, VRAM_BASE);
            LZ77UncompVram(0x087788b8, VRAM_BASE + 0x8000);
            LZ77UncompVram(0x087919c8, VRAM_BASE + 0xF000);
            LZ77UncompVram(0x08792264, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a158, PALRAM_BASE, 256);
            break;

        case 3:
            LZ77UncompVram(0x0877bc2c, VRAM_BASE);
            LZ77UncompVram(0x08781f9c, VRAM_BASE + 0x8000);
            LZ77UncompVram(0x08792824, VRAM_BASE + 0xF000);
            LZ77UncompVram(0x087930c0, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a358, PALRAM_BASE, 256);
            break;

        default:
            LZ77UncompVram(0x08785b44, VRAM_BASE);
            LZ77UncompVram(0x0878c650, VRAM_BASE + 0x8000);
            LZ77UncompVram(0x08793684, VRAM_BASE + 0xF000);
            LZ77UncompVram(0x08793f20, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a558, PALRAM_BASE, 256);
            break;
    }

    switch (gLanguage)
    {
        case 3:
            LZ77UncompVram(0x08798fbc, VRAM_OBJ);
            break;

        case 4:
            LZ77UncompVram(0x087957a8, VRAM_OBJ);
            break;

        case 5:
            LZ77UncompVram(0x087969f4, VRAM_OBJ);
            break;

        case 6:
            LZ77UncompVram(0x08797d08, VRAM_OBJ);
            break;

        default:
            LZ77UncompVram(0x087944e4, VRAM_OBJ);
            break;
    }

    DMA3_COPY_16(0x0874a758, PALRAM_OBJ, 64);

    WRITE_16(REG_BG0CNT, 0x1e01);
    WRITE_16(REG_BG1CNT, 0x1f08);
    WRITE_16(REG_DISPCNT, 0x1300);
    WRITE_16(REG_BLDCNT, 0x1fdf);

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gNonGameplayRam.ending.unk_8 = 128;
    gNonGameplayRam.ending.unk_2 = 0;
    gNonGameplayRam.ending.unk_4 = 0;
    gNonGameplayRam.ending.unk_6 = 0;
    gNonGameplayRam.ending.unk_98++;

    value = 31;
    for (i = 31; i >= 0; i--)
        gNonGameplayRam.ending.unk_A[i] = value;

    CallbackSetVBlank(EndingImageVblank);

    return FALSE;    
}





boolu32 EndingImage(void) 
{
    boolu32 ended;
    s32 i;
    u16* src;
    u16* dst;
    u32 palette;
    s32 currSlot;
    s32 nextSlot;
    u16 part;
    
    ended = FALSE;
    
    switch (gLanguage) 
    {
        case 3:
        case 4:
        case 6:
            break;
        
        case 5:
        default:
            if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6.25f)) 
            {
                EndingImageDisplayLinePermanently(2);
            } 
            else if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6.34f)) 
            {
                EndingImageLoadTextOam(2);
            }
            break;
    }
    
    switch (gNonGameplayRam.ending.timer++) 
    {
        case 0:
            EndingDrawIgtAndCompletionPercentage();
            gNonGameplayRam.ending.unk_2 = 1;
            break;
        
        case CONVERT_SECONDS(0.5f):
            EndingImageLoadTextOam(0);
            gNonGameplayRam.ending.unk_97 = 1;
            break;
        
        case CONVERT_SECONDS(1.84f):
            EndingImageDisplayLinePermanently(0);
            break;
        
        case CONVERT_SECONDS(3):
            EndingImageDisplayLinePermanently(1);
            break;
        
        case CONVERT_SECONDS(5.5f):
            EndingImageLoadTextOam(1);
            break;
        
        case CONVERT_SECONDS(7.67f):
            EndingImageDisplayLinePermanently(3);
            break;
        
        case CONVERT_SECONDS(8.84f):
            EndingImageDisplayLinePermanently(4);
            break;
        
        case CONVERT_SECONDS(13):
            EndingImageDisplayLinePermanently(5);
            break;
        
        case CONVERT_SECONDS(22.94f):
            if (!(gChangedInput & (KEY_A | KEY_B | KEY_START)))
                gNonGameplayRam.ending.timer--;
            break;
        
        case CONVERT_SECONDS(27.74f):
            ended++;
            break;
    }
    
    if (gNonGameplayRam.ending.unk_2 == 1) 
    {
        if (gNonGameplayRam.ending.unk_8 > 0x7F) 
        {
            gNonGameplayRam.ending.unk_8 = MOD_AND(gNonGameplayRam.ending.unk_8, 0x80);
            gNonGameplayRam.ending.unk_8C = ((u16)-64 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_90 = ((u16)-128 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_4 = MOD_AND(gNonGameplayRam.ending.unk_4 + 1, 0x20);
            gNonGameplayRam.ending.unk_0++;
        }

        gBg0YPosition -= 6;
        gBg1YPosition -= 6;
        gNonGameplayRam.ending.unk_8 += 6;
        
        if (!gBg0YPosition || (gBg0YPosition & 0x8000))
        {
            gBg0YPosition = 0;
            gNonGameplayRam.ending.unk_2 = 0;
        }
    }
    
    if (gNonGameplayRam.ending.unk_97 == 1) 
    {
        for (currSlot = 6; currSlot < gNonGameplayRam.ending.unk_9B; currSlot++)
            EndingImageUpdateLettersSpawnDelay(currSlot);
    }

    if (gNonGameplayRam.ending.timer <= CONVERT_SECONDS(23) && (gNonGameplayRam.ending.timer < CONVERT_SECONDS(13.5f) || !(gButtonInput & (KEY_L | KEY_R))))  
    {
        dst = (u16*)&gOamData;
        dst += gNextOamSlot * sizeof(union OamData) / sizeof(*dst);
        
        currSlot = gNextOamSlot;
        nextSlot = currSlot;

        EMPTY_DO_WHILE
        
        for (i = 0; i < gNonGameplayRam.ending.unk_9B; i++) 
        {
            if (gNonGameplayRam.ending.unk_124[i] <= 1)
                continue;
            
            if (gNonGameplayRam.ending.unk_160[i] <= 0x3F)
                gNonGameplayRam.ending.unk_160[i]++;
                
            palette = 0;
            
            if (i > 5) 
            {                    
                if (gNonGameplayRam.ending.unk_160[i] < 4)
                    palette = 3;
                else if (gNonGameplayRam.ending.unk_160[i] < 8)
                    palette = 2;
                else if (gNonGameplayRam.ending.unk_160[i] < 12)
                    palette = 1;
            } 
            else if (i == 5) 
            {
                if (gNonGameplayRam.ending.unk_160[i] > 0x3F)
                    gNonGameplayRam.ending.unk_160[i] = palette;
                    
                switch (gNonGameplayRam.ending.unk_160[i] / 8)
                {
                    case 0:
                    case 7:
                        palette = 3;
                        break;

                    case 1:
                    case 6:
                        palette = 2;
                        break;
                        
                    case 2:
                    case 5:    
                        palette = 1;
                        break;

                    case 3:
                    case 4:
                        break;  
                }
            }

            src = gNonGameplayRam.ending.oamFramePointers[i];
            part = *src++;
            nextSlot += (part & 0xFF);
            
            for (; currSlot < nextSlot; currSlot++)
            {
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + gNonGameplayRam.ending.oamYPositions[i];

                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = MOD_AND(part + gNonGameplayRam.ending.oamXPositions[i], 0x200);

                *dst++ = *src++;
                
                gOamData[currSlot].split.priority = 0;
                gOamData[currSlot].split.paletteNum = palette;
                
                dst++;
            }
        }
        
        gNextOamSlot = nextSlot;
    }
                
    ResetFreeOam();
    
    return ended;
}

