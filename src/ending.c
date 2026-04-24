#include "globals.h"
#include "init_helpers.h"
#include "macros.h"
#include "syscalls.h"

#include "structs/ending.h"

#include "data/ending_data.h"

extern void EndingDrawIgtAndCompletionPercentage(void);
extern void EndingImageDisplayLinePermanently(s32);
extern void EndingImageLoadTextOam(s32);
extern void EndingImageUpdateLettersSpawnDelay(s32);
extern void unk_a1cfc(void);
extern void EndingImageVblank(void);

/**
 * @brief a26bc | 58 | To document
 * 
 */
boolu32 CreditsFadeIn(void)
{
    if (gWrittenToBldy)
    {
        if (gNonGameplayRam.ending.unk_97 & 1)
            gWrittenToBldy--;
        
        gNonGameplayRam.ending.unk_97++;
    }
    else
    {
        WRITE_16(REG_BLDCNT, 0);
        gNonGameplayRam.ending.unk_98++;
        gNonGameplayRam.ending.unk_97 = 0;
    }
    
    return FALSE;
}

/**
 * @brief a2714 | 1d8 | To document
 * 
 */
boolu32 SamusPosing(void)
{
    u32 index;
    u32 offset;
    void* temp1;
    u32 temp2;

    switch (gNonGameplayRam.ending.timer++) 
    {
        case 0:
            index = gNonGameplayRam.ending.unk_98 - 2;
            
            if (gNonGameplayRam.ending.unk_98 & 1)
                offset = 0x8000;
            else 
                offset = 0xA800;
            
            LZ77UncompVram(sPreResultsSamusBgGfxPointers1[index], VRAM_BASE + offset);
            break;
        
        case 1:
            index = gNonGameplayRam.ending.unk_98 - 2;

            if (gNonGameplayRam.ending.unk_98 & 1)
                offset = 0x9000;
            else 
                offset = 0xB800;

            LZ77UncompVram(sPreResultsSamusBgGfxPointers2[index], VRAM_BASE + offset);
            break;
        
        case 2:
            index = gNonGameplayRam.ending.unk_98 - 2;

            if (gNonGameplayRam.ending.unk_98 & 1)
                offset = 0xF800;
            else 
                offset = 0xF000;
                
            LZ77UncompVram(sPreResultsSamusBgGfxPointers3[index], VRAM_BASE + offset);
            break;
        
        case 50:
            gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_Evb = 0;

            //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
            temp1 = REG_BLDALPHA;
            temp2 = BLDALPHA_MAX_VALUE;
            WRITE_16(temp1, temp2);
            
            if (gNonGameplayRam.ending.unk_98 & 1)
                WRITE_16(REG_BLDCNT, 0x542);
            else
                WRITE_16(REG_BLDCNT, 0x641);
            
            WRITE_16(REG_DISPCNT, 0x1700);
            gNonGameplayRam.ending.unk_2 = 1;
            break;
        
        case 100:
            WRITE_16(REG_BLDCNT, 0);
            
            if (1 & gNonGameplayRam.ending.unk_98) 
            {
                WRITE_16(REG_DISPCNT, 0x1500);
                WRITE_16(REG_BG0CNT, 0x1F08);
                WRITE_16(REG_BG1CNT, 0x1E09);
            } 
            else 
            {
                WRITE_16(REG_DISPCNT, 0x1600);
                WRITE_16(REG_BG0CNT, 0x1F09);
                WRITE_16(REG_BG1CNT, 0x1E08);
            }
        
            gNonGameplayRam.ending.unk_2 = 0;
            gNonGameplayRam.ending.timer = 0;
            gNonGameplayRam.ending.unk_97 = 0;
            gNonGameplayRam.ending.unk_98++;
            break;
    }
    
    if (gNonGameplayRam.ending.unk_2 == 1 && gNonGameplayRam.ending.unk_97++ > 1) 
    {
        gNonGameplayRam.ending.unk_97 = 0;
            
        if (gWrittenToBldalpha_Eva)
            gWrittenToBldalpha_Eva--;
                
        if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
            gWrittenToBldalpha_Evb++;

        WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    }
    
    return FALSE;
}

/**
 * @brief a28ec | 448 | To document
 * 
 */
boolu32 SamusPosingTransforming(void) 
{
    boolu32 ended;
    u16* src;
    u16* dst;
    u16 part;
    u8 currSlot;
    u8 nextSlot;
    void* temp1;
    u32 temp2;

    ended = FALSE;
    
    switch (gNonGameplayRam.ending.timer++) 
    {
        case 0x32:
            gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_Evb = 0;
            
            //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
            temp1 = REG_BLDALPHA;
            temp2 = BLDALPHA_MAX_VALUE;
            WRITE_16(temp1, temp2);
            
            WRITE_16(REG_BLDCNT, 0x1441);
            gNonGameplayRam.ending.unk_9B = 1;
            gNonGameplayRam.ending.unk_9D = 1;
            gNonGameplayRam.ending.unk_A0 = (u16*)&sOamFrame_749c80;
            gNonGameplayRam.ending.unk_2 = 1;
            break;

        case 0x64:
            WRITE_16(REG_DISPCNT, 0x1400);
            WRITE_16(REG_BLDCNT, 0);
            gNonGameplayRam.ending.unk_9D = 0;
            gNonGameplayRam.ending.unk_2 = 0;
            break;

        case 0x65:
            if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sData_753E80, VRAM_BASE + 0xF800);
                WRITE_16(REG_BG0CNT, 0x1F00);
            }
            break;

        case 0x6E:
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_IME, 0);
                WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) | 0x10);
                WRITE_16(REG_IE, READ_16(REG_IE) | 2);
                WRITE_16(REG_IME, 1);
                gNonGameplayRam.ending.unk_96 = 1;
            }
            break;

        case 0x8C:
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_WIN0H, 0);
                WRITE_16(REG_WIN0V, 0);
                WRITE_16(REG_WININ, 0);
                WRITE_16(REG_WINOUT, 0x2326);
                WRITE_16(REG_DISPCNT, 0xB500);
                gNonGameplayRam.ending.unk_9C = 2;
            }
            break;

        case 0x8D:
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sPreResultsSamusWithoutHelmetBgGfx1, VRAM_BASE + 0x8000);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sPreResultsSamusSuitlessBgGfx1, VRAM_BASE + 0x8000);
            }
            break;
        
        case 0x8E:
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sPreResultsSamusWithoutHelmetBgGfx2, VRAM_BASE + 0x9000);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sPreResultsSamusSuitlessBgGfx2, VRAM_BASE + 0x9000);
            }
            break;

        case 0x8F:
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sData_75E990, VRAM_BASE + 0xF000);
            }
            else if (gNonGameplayRam.ending.unk_99) 
            {
                LZ77UncompVram(sData_75EB94, VRAM_BASE + 0xF000);
            }
            break;

        case 0x90:
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                DMA3_COPY_16(&sPreResultsSamusWithoutHelmetBgPal, PALRAM_BASE + 6 * PAL_ROW_SIZE, 10 * PAL_ROW);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                DMA3_COPY_16(&sPreResultsSamusSuitlessBgPal, PALRAM_BASE + 6 * PAL_ROW_SIZE, 10 * PAL_ROW);
            }
            break;
        
        case 0xAA:
            if (gNonGameplayRam.ending.unk_99 == 1) 
            {
                gNonGameplayRam.ending.unk_A0 = (u16*)&sOamFrame_749d18;
            } 
            else if (gNonGameplayRam.ending.unk_99)
            {
                gNonGameplayRam.ending.unk_A0 = (u16*)&sOamFrame_749d3e;
                WRITE_16(REG_BG1HOFS, 4);
            }
            break;

        case 0xDC:
            if (gNonGameplayRam.ending.unk_99)
            {
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                gWrittenToBldalpha_Evb = 0;
                
                //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
                temp1 = REG_BLDALPHA;
                temp2 = BLDALPHA_MAX_VALUE;
                WRITE_16(temp1, temp2);
                
                WRITE_16(REG_BLDCNT, 0x651);
                WRITE_16(REG_DISPCNT, 0xB700);
                gNonGameplayRam.ending.unk_2 = 1;
                gNonGameplayRam.ending.unk_97 = 0;
            }
            break;
        
        case 0x10E:
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_DISPCNT, 0x600);
                WRITE_16(REG_BLDCNT, 0);
                gNonGameplayRam.ending.unk_9B = 0;
                gNonGameplayRam.ending.unk_2 = 0;
                gNonGameplayRam.ending.unk_96 = 0;
            }
            break;

        case 0x19A:
            ended = TRUE;
            break;
    }

    if (gNonGameplayRam.ending.unk_2 == 1 && gNonGameplayRam.ending.unk_97++ > 1) 
    {
        gNonGameplayRam.ending.unk_97 = 0;
            
        if (gWrittenToBldalpha_Eva)
            gWrittenToBldalpha_Eva--;
                
        if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
            gWrittenToBldalpha_Evb++;
            
        WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    }
    
    if (gNonGameplayRam.ending.unk_96)
        gNonGameplayRam.ending.unk_6++;

    dst = (u16*)&gOamData;
    nextSlot = 0;

    if (gNonGameplayRam.ending.unk_9B)
    {
        src = gNonGameplayRam.ending.unk_A0;
        part = *src++;
        nextSlot = (u8)part;
        
        for (currSlot = 0; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + 0x4C;
            gOamData[currSlot].split.objMode = gNonGameplayRam.ending.unk_9C;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + 0x82) & 0x1FF;

            *dst = *src++;
            
            gOamData[currSlot].split.priority = gNonGameplayRam.ending.unk_9D;

            dst += 2;
        }
    }

    gNextOamSlot = nextSlot;
    ResetFreeOam();
    
    return ended;
}

/**
 * @brief a2d34 | 378 | To document
 * 
 */
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
            LZ77UncompVram(sEnding_0_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_0_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_0_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_0_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x08749d58, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 1:
            LZ77UncompVram(sEnding_1_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_1_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_1_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_1_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x08749f58, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 2:
            LZ77UncompVram(sEnding_2_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_2_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_2_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_2_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a158, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 3:
            LZ77UncompVram(sEnding_3_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_3_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_3_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_3_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a358, PALRAM_BASE, 16 * PAL_ROW);
            break;

        default:
            LZ77UncompVram(sEnding_4_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_4_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_4_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_4_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(0x0874a558, PALRAM_BASE, 16 * PAL_ROW);
            break;
    }

    switch (gLanguage)
    {
        case 3:
            LZ77UncompVram(sResultScreenGermanTextGfx, VRAM_OBJ);
            break;

        case 4:
            LZ77UncompVram(sResultScreenFrenchTextGfx, VRAM_OBJ);
            break;

        case 5:
            LZ77UncompVram(sResultScreenItalianTextGfx, VRAM_OBJ);
            break;

        case 6:
            LZ77UncompVram(sResultScreenSpanishTextGfx, VRAM_OBJ);
            break;

        default:
            LZ77UncompVram(sResultScreenEnglishTextGfx, VRAM_OBJ);
            break;
    }

    DMA3_COPY_16(0x0874a758, PALRAM_OBJ, 4 * PAL_ROW);

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

/**
 * @brief a30ac | 380 | To document
 * 
 */
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
        if (gNonGameplayRam.ending.unk_8 > 127) 
        {
            gNonGameplayRam.ending.unk_8 = MOD_AND(gNonGameplayRam.ending.unk_8, 128);
            gNonGameplayRam.ending.unk_8C = ((u16)-64 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_90 = ((u16)-128 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_4 = MOD_AND(gNonGameplayRam.ending.unk_4 + 1, 32);
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
            
            if (gNonGameplayRam.ending.unk_160[i] <= 63)
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
                if (gNonGameplayRam.ending.unk_160[i] > 63)
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

                gOamData[currSlot].split.x = MOD_AND(part + gNonGameplayRam.ending.oamXPositions[i], 512);

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

