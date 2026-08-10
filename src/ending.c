#include "globals.h"
#include "init_helpers.h"
#include "macros.h"
#include "syscalls.h"

#include "constants/game_state.h"

#include "data/ending_data.h"
#include "data/animated_graphics_data.h"

#include "structs/ending.h"
#include "structs/samus.h"

void CreditsInit(void);
boolu32 CreditsProcess(void);
u32 CreditsDisplayLine(u32 line);
boolu32 SamusPosingInit(void);
boolu32 EndingFadeIn(void);
boolu32 SamusPosing(void);
boolu32 SamusPosingTransforming(void);
boolu32 EndingImageInit(void);
boolu32 EndingImage(void);

static boolu32 (*sSamusPosingFunctionPointers[7]) (void) = {
    SamusPosingInit,
    EndingFadeIn,
    SamusPosing,
    SamusPosing,
    SamusPosing,
    SamusPosing,
    SamusPosingTransforming
};

static boolu32 (*sEndingImageFunctionPointers[3]) (void) = {
    EndingImageInit,
    EndingFadeIn,
    EndingImage
};


/**
 * @brief a1c84 | 78 | Main handler for the credits
 * 
 * @return boolu32 Finished
 */
boolu32 CreditsHandler(void)
{
    boolu32 finished;

    finished = FALSE;

    ENDING_DATA.unk_0 = 0;
    gNextOamSlot = 0;

    switch (gSubGameMode1)
    {
        case 0:
            CreditsInit();
            gSubGameMode1++;
            break;

        case 1:
            if (gWrittenToBldy)
            {
                gWrittenToBldy--;
            }
            else
            {
                WRITE_16(REG_BLDCNT, 0);
                gSubGameMode1++;
            }
            break;

        case 2:
            if (CreditsProcess())
                gSubGameMode1++;
            break;

        case 3:
            finished = TRUE;
            break;
    }

    return finished;
}

/**
 * @brief a1cfc | c | VBlank for the ending/credits init functions
 * 
 */
void EndingInitFunctionsVBlank(void)
{
    UpdateAudio();
}

/**
 * @brief a1d08 | 68 | VBlank for the credits roll
 * 
 */
void CreditsVBlank(void)
{
    if (ENDING_DATA.unk_0)
    {
        DMA3_COPY_16(ENDING_DATA.creditLineTilemap_1, VRAM_BASE + ENDING_DATA.unk_8C, 32);
        DMA3_COPY_16(ENDING_DATA.creditLineTilemap_2, VRAM_BASE + ENDING_DATA.unk_90, 32);
    }

    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition / 16, 512));
}

/**
 * @brief a1d70 | 58 | VBlank for Samus posing after credits
 * 
 */
void SamusPosingVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);

    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition / 16, 512));
    WRITE_16(REG_BG2VOFS, MOD_AND(gBg2YPosition / 16, 512));
}

/**
 * @brief a1dc8 | 9c | VBlank for the ending image display
 * 
 */
void EndingImageVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);

    if (ENDING_DATA.unk_0)
    {
        DMA3_COPY_16(ENDING_DATA.creditLineTilemap_1, VRAM_BASE + ENDING_DATA.unk_8C, 32);
        DMA3_COPY_16(ENDING_DATA.creditLineTilemap_1, VRAM_BASE + ENDING_DATA.unk_90, 32);
    }
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition / 16, 512));
    WRITE_16(REG_BG1VOFS, MOD_AND(gBg1YPosition / 16, 512));
}

/**
 * @brief a1e64 | 28 | HBlank code for Samus posing after credits
 * 
 */
void SamusPosingHBlankCode(void)
{
    u16 index;

    index = MOD_AND(READ_16(REG_VCOUNT) + ENDING_DATA.currentCreditLine, 128);
    WRITE_16(REG_BG0HOFS, ENDING_DATA.unk_A4[index]);
}

/**
 * @brief a1e8c | 260 | Setup for the credits roll
 * 
 */
void CreditsInit(void)
{
    s32 minutes;
    s32 missileTanks;
    s32 energyTanks;
    s32 powerBombTanks;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(EndingInitFunctionsVBlank);

    WRITE_16(REG_DISPCNT, 0);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    
    ClearGfxRam();
    
    DMA3_COPY_16(sCreditsCharacterGfx, VRAM_BASE, 0x400);
    DMA3_COPY_16(sCreditsCharacterGfx + 0x800, VRAM_BASE + 0x800, 0x400);
    DMA3_COPY_16(sCreditsCharacterGfx + 0x1000, VRAM_BASE + 0x1000, 0x200);
    DMA3_COPY_16(sCreditsCopyrightText1_Gfx, VRAM_BASE + 0x1400, 0xE0);
    DMA3_COPY_16(sCreditsCopyrightText2_Gfx, VRAM_BASE + 0x1800, 0x120);
    DMA3_COPY_16(sCreditsCopyrightText3_Gfx, VRAM_BASE + 0x1C00, 0x160);
    DMA3_COPY_16(sCreditsCopyrightText4_Gfx, VRAM_BASE + 0x2000, 0x120);
    DMA3_COPY_16(sPal_7478A0, PALRAM_BASE, 0x30);
    
    WRITE_16(REG_BG0CNT, 0x1000);
    WRITE_16(REG_DISPCNT, 0x1100);
    
    gNextOamSlot = 0;
    ResetFreeOam();
    
    gBg0XPosition = 0;
    gBg0YPosition = 0;
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
    
    ENDING_DATA.unk_8 = 128;
    
    minutes = gInGameTimer.hours * 60 + gInGameTimer.minutes;
    if (minutes < 120)
        ENDING_DATA.unk_99 = 2;
    else if (minutes < 240)
        ENDING_DATA.unk_99 = 1;
    
    energyTanks = (gEquipment.maxEnergy - 99) / 100;
    if (energyTanks < 0)
        energyTanks = 0;
    
    missileTanks = (gEquipment.maxMissiles - 10) / 5;
    if (missileTanks < 0)
        missileTanks = 0;
    
    powerBombTanks = (gEquipment.maxPowerBombs - 10) / 2;
    if (powerBombTanks < 0)
        powerBombTanks = 0;
    
    ENDING_DATA.completionPercentage = energyTanks + missileTanks + powerBombTanks;
    if (ENDING_DATA.completionPercentage > 100)
        ENDING_DATA.completionPercentage = 100;
    
    PlayMusic(0x55, 0xE);
    CallbackSetVBlank(CreditsVBlank);
}

/**
 * @brief a20ec | 1f4 | Processes the credits and ending sequence
 * 
 * @return boolu32 Finished
 */
boolu32 CreditsProcess(void)
{
    u32 lineHeight;
    u32 temp_r3;
    s32 var_r0;
    boolu32 finished;
    s32 i;

    finished = FALSE;
    
    switch (ENDING_DATA.stage)
    {
        case 0:
            if (ENDING_DATA.unk_8 > 127)
            {
                //ENDING_DATA.unk_8 &= 127;
                ENDING_DATA.unk_8 = MOD_AND(ENDING_DATA.unk_8, 128);
                
                if (ENDING_DATA.unk_2 == ENDING_DATA.unk_4)
                {
                    lineHeight = CreditsDisplayLine(ENDING_DATA.currentCreditLine);
                    
                    if (lineHeight == 9)
                    {
                        ENDING_DATA.stage++;
                    }
                    else
                    {
                        temp_r3 = ENDING_DATA.unk_4 << 6;
                        var_r0 = temp_r3 + 0x500;
                        
                        if (var_r0 > 0x7FF)
                            //var_r0 &= 0x7FF;
                            var_r0 = MOD_AND(var_r0, 0x800);
                        
                        ENDING_DATA.unk_8C = var_r0 + 0x8000;
                        var_r0 = temp_r3 + 0x540;
                        
                        if (var_r0 > 0x7FF)
                            //var_r0 &= 0x7FF;
                            var_r0 = MOD_AND(var_r0, 0x800);
                        
                        ENDING_DATA.unk_90 = var_r0 + 0x8000;
                        ENDING_DATA.unk_4 += lineHeight;
                        ENDING_DATA.currentCreditLine++;
                        ENDING_DATA.unk_0++;
                    }
                }
                
                ENDING_DATA.unk_2++;
            }
            
            ENDING_DATA.unk_8 += 9;
            gBg0YPosition += 9;
            break;
        
        case 1:
            for (i = 0; i < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1); i++)
            {
                ENDING_DATA.creditLineTilemap_1[i] = 0;
                ENDING_DATA.creditLineTilemap_2[i] = 0;
            }

            if (ENDING_DATA.timer++ > 512)
            {
                WRITE_16(REG_BLDCNT, 0x1FDF);
                gWrittenToBldy = 0;
                ENDING_DATA.timer = 0;
                ENDING_DATA.stage++;
            }
            break;
        
        case 2:
        case 5:
        case 8:
            if (gWrittenToBldy < 16)
            {
                if (MOD_AND(ENDING_DATA.timer++, 2))
                    gWrittenToBldy++;
            }
            else
            {
                WRITE_16(REG_DISPCNT, 0);
                ENDING_DATA.timer = 0;
                ENDING_DATA.stage++;
            }
            break;
        
        case 3:
            if (sSamusPosingFunctionPointers[ENDING_DATA.unk_98]())
                ENDING_DATA.stage++;

            gBg2YPosition += 4;
            break;
        
        case 4:
        case 7:
            WRITE_16(REG_BLDCNT, 0x1FDF);
            gWrittenToBldy = 0;
            ENDING_DATA.timer = 0;
            ENDING_DATA.unk_97 = 0;
            ENDING_DATA.unk_98 = 0;
            ENDING_DATA.stage++;
            break;
        
        case 6:
            if (sEndingImageFunctionPointers[ENDING_DATA.unk_98]())
                ENDING_DATA.stage++;
            break;
        
        case 9:
            finished++;
            FadeMusic(0x1E);
            break;
    }
    
    return finished;
}

/**
 * @brief a22e0 | 26c | Displays a credit line
 * 
 * @param line Line
 * @return u32 Height of line in tiles
 */
u32 CreditsDisplayLine(u32 line)
{
    const struct CreditsEntry* pCredits;
    s32 i;
    u32 lineHeight;

    pCredits = sCredits;
    pCredits += line;

    for (i = 0; i < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1); i++)
    {
        ENDING_DATA.creditLineTilemap_1[i] = 0;
        ENDING_DATA.creditLineTilemap_2[i] = 0;
    }

    i = 0;
    
    switch (pCredits->type)
    {
        case CREDIT_LINE_TYPE_BLUE:
            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                {
                    break;
                }
            
                if (pCredits->text[i] >= 'A' && pCredits->text[i] <= 'Z')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = pCredits->text[i] + 0xFC0;
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x101B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x101C;
                }
                else if (pCredits->text[i] == '&')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x101D;
                }

                i++;
            }
        
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_RED:
            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                {
                    break;
                }

                if (pCredits->text[i] >= 'A' && pCredits->text[i] <= 'Z')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = pCredits->text[i] + 0x1FC0;
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x201B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x201C;
                }
                else if (pCredits->text[i] == '&')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x201D;
                }

                i++;
            }
            
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_END:
            lineHeight = 9;
            break;
        
        case CREDIT_LINE_TYPE_ALL_RIGHTS:
            for (i = 8; i < 22; i++)
                gNonGameplayRam.ending.creditLineTilemap_1[i] = i + 0x98;

            lineHeight = 1;
            break;

        case CREDIT_LINE_TYPE_BLANK:
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_THE_COPYRIGHT:
            for (i = 6; i < 24; i++)
                gNonGameplayRam.ending.creditLineTilemap_1[i] = i + 0xBA;
        
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_SCENARIO:
            for (i = 4; i < 26; i++)
                gNonGameplayRam.ending.creditLineTilemap_1[i] = i + 0xDC;
        
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_RESERVED:
            for (i = 6; i < 24; i++)
                gNonGameplayRam.ending.creditLineTilemap_1[i] = i + 0xFA;
        
            lineHeight = 1;
            break;
        
        case CREDIT_LINE_TYPE_WHITE_BIG:
            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                {
                    break;
                }
            
                if (pCredits->text[i] >= 'A' && pCredits->text[i] <= 'Z')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = pCredits->text[i] + 0xFFDF;
                    ENDING_DATA.creditLineTilemap_2[i] = pCredits->text[i] + 0xFFFF;
                }
                else if (pCredits->text[i] >= 'a' && pCredits->text[i] <= 'z')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = pCredits->text[i] + 0xFFFF;
                    ENDING_DATA.creditLineTilemap_2[i] = pCredits->text[i] + 0x1F;
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_2[i] = 0x5B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_2[i] = 0x5C;
                }
                else if (pCredits->text[i] == '-')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x3A;
                }
                else if (pCredits->text[i] == '+')
                {
                    ENDING_DATA.creditLineTilemap_1[i] = 0x7A;
                    ENDING_DATA.creditLineTilemap_2[i] = 0x9A;
                }

                i++;
            }

            lineHeight = 2;
            break;
    } // End switch
    
    return lineHeight;
}

/**
 * @brief a254c | 170 | Setup for Samus posing after the credits
 * 
 * @return boolu32 Always false
 */
boolu32 SamusPosingInit(void)
{
    CallbackSetVBlank(EndingInitFunctionsVBlank);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram(sPreResultsSpaceBgGfx, VRAM_BASE);
    LZ77UncompVram(sTilemap_7535e0, VRAM_BASE + 0xE800);
    LZ77UncompVram(sPreResultsSamusSuitedGfx1, VRAM_BASE + 0x8000);
    LZ77UncompVram(sPreResultsSamusSuitedGfx2, VRAM_BASE + 0x9000);
    LZ77UncompVram(sTilemap_75db50, VRAM_BASE + 0xF800);
    LZ77UncompVram(sPreResultsSamusObjGfx, VRAM_OBJ);

    DMA3_COPY_16(sPal_749600, PALRAM_BASE, PAL_ROW * 6);
    DMA3_COPY_16(sPal_7496c0, PALRAM_BASE + PAL_ROW_SIZE * 6, PAL_ROW * 10);
    DMA3_COPY_16(sPreResultsSamusObjPal, PALRAM_OBJ, PAL_ROW * 16);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
    WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | 
        BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | 
        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);

    gBg0YPosition = 0;

    DMA3_COPY_16(sSamusPosingSineTable, gNonGameplayRam.ending.unk_A4, 64);

    gNonGameplayRam.ending.unk_2 = 0;
    gNonGameplayRam.ending.unk_4 = 0;
    gNonGameplayRam.ending.currentCreditLine = 0;
    gNonGameplayRam.ending.unk_98++;
    
    CallbackSetVBlank(SamusPosingVBlank);

    DMA3_COPY_16(SamusPosingHBlankCode, &gNonGameplayRam.ending.unk_270, 32);

    CallbackSetHBlank(gNonGameplayRam.ending.unk_270 + 1);

    return FALSE;
}

/**
 * @brief a26bc | 58 | Handles fading in Samus posing and ending image
 * 
 * @return boolu32 Always false
 */
boolu32 EndingFadeIn(void)
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
 * @brief a2714 | 1d8 | Processes Samus posing after the credits
 * 
 * @return boolu32 Always false
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
        
        case CONVERT_SECONDS(1.f / 60):
            index = gNonGameplayRam.ending.unk_98 - 2;

            if (gNonGameplayRam.ending.unk_98 & 1)
                offset = 0x9000;
            else 
                offset = 0xB800;

            LZ77UncompVram(sPreResultsSamusBgGfxPointers2[index], VRAM_BASE + offset);
            break;
        
        case CONVERT_SECONDS(1.f / 30):
            index = gNonGameplayRam.ending.unk_98 - 2;

            if (gNonGameplayRam.ending.unk_98 & 1)
                offset = 0xF800;
            else 
                offset = 0xF000;
                
            LZ77UncompVram(sPreResultsSamusBgTilemapPointers[index], VRAM_BASE + offset);
            break;
        
        case CONVERT_SECONDS(5.f / 6):
            gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_Evb = 0;

            //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
            temp1 = REG_BLDALPHA;
            temp2 = BLDALPHA_MAX_VALUE;
            WRITE_16(temp1, temp2);
            
            if (gNonGameplayRam.ending.unk_98 & 1)
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | 
                    BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL);
            else
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | 
                    BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL);
            
            WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ);
            gNonGameplayRam.ending.unk_2 = 1;
            break;
        
        case CONVERT_SECONDS(1 + 2.f / 3):
            WRITE_16(REG_BLDCNT, 0);
            
            if (gNonGameplayRam.ending.unk_98 & 1) 
            {
                WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
                WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
            } 
            else
            {
                WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG2 | DCNT_OBJ);
                WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
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
 * @return boolu32 finished
 */
boolu32 SamusPosingTransforming(void) 
{
    boolu32 finished;
    u16* src;
    u16* dst;
    u16 part;
    u8 currSlot;
    u8 nextSlot;
    void* temp1;
    u32 temp2;

    finished = FALSE;
    
    switch (gNonGameplayRam.ending.timer++) 
    {
        case CONVERT_SECONDS(5.f / 6):
            gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_Evb = 0;
            
            //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
            temp1 = REG_BLDALPHA;
            temp2 = BLDALPHA_MAX_VALUE;
            WRITE_16(temp1, temp2);
            
            WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | 
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
            gNonGameplayRam.ending.unk_9B = 1;
            gNonGameplayRam.ending.unk_9D = 1;
            gNonGameplayRam.ending.unk_A0 = (u16*)&sOamFrame_749c80;
            gNonGameplayRam.ending.unk_2 = 1;
            break;

        case CONVERT_SECONDS(1 + 2.f / 3):
            WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_OBJ);
            WRITE_16(REG_BLDCNT, 0);
            gNonGameplayRam.ending.unk_9D = 0;
            gNonGameplayRam.ending.unk_2 = 0;
            break;

        case CONVERT_SECONDS(1 + 41.f / 60):
            if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sTilemap_753E80, VRAM_BASE + 0xF800);
                WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            }
            break;

        //case CONVERT_SECONDS(1 + 5.f / 6): // No match
        case CONVERT_SECONDS(11.f / 6):
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_IME, 0);
                WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) | DSTAT_IF_HBLANK);
                WRITE_16(REG_IE, READ_16(REG_IE) | IF_HBLANK);
                WRITE_16(REG_IME, 1);
                gNonGameplayRam.ending.unk_96 = 1;
            }
            break;

        case CONVERT_SECONDS(2 + 1.f / 3):
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_WIN0H, 0);
                WRITE_16(REG_WIN0V, 0);
                WRITE_16(REG_WININ, 0);
                WRITE_16(REG_WINOUT, WIN0_BG1 | WIN0_BG2 | WIN0_COLOR_EFFECT | WIN1_BG0 | WIN1_BG1 | WIN1_COLOR_EFFECT);
                WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ | DCNT_WIN0 | DCNT_WINOBJ);
                gNonGameplayRam.ending.unk_9C = 2;
            }
            break;

        case CONVERT_SECONDS(2 + 21.f / 60):
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sPreResultsSamusWithoutHelmetBgGfx1, VRAM_BASE + 0x8000);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sPreResultsSamusSuitlessBgGfx1, VRAM_BASE + 0x8000);
            }
            break;
        
        case CONVERT_SECONDS(2 + 22.f / 60):
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sPreResultsSamusWithoutHelmetBgGfx2, VRAM_BASE + 0x9000);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                LZ77UncompVram(sPreResultsSamusSuitlessBgGfx2, VRAM_BASE + 0x9000);
            }
            break;

        case CONVERT_SECONDS(2 + 23.f / 60):
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                LZ77UncompVram(sTilemap_75E990, VRAM_BASE + 0xF000);
            }
            else if (gNonGameplayRam.ending.unk_99) 
            {
                LZ77UncompVram(sTilemap_75EB94, VRAM_BASE + 0xF000);
            }
            break;

        case CONVERT_SECONDS(2 + 24.f / 60):
            if (gNonGameplayRam.ending.unk_99 == 1)
            {
                DMA3_COPY_16(&sPreResultsSamusWithoutHelmetBgPal, PALRAM_BASE + 6 * PAL_ROW_SIZE, 10 * PAL_ROW);
            }
            else if (gNonGameplayRam.ending.unk_99)
            {
                DMA3_COPY_16(&sPreResultsSamusSuitlessBgPal, PALRAM_BASE + 6 * PAL_ROW_SIZE, 10 * PAL_ROW);
            }
            break;
        
        case CONVERT_SECONDS(2 + 5.f / 6):
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

        case CONVERT_SECONDS(3 + 2.f / 3):
            if (gNonGameplayRam.ending.unk_99)
            {
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                gWrittenToBldalpha_Evb = 0;
                
                //WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE); // Doesn't match
                temp1 = REG_BLDALPHA;
                temp2 = BLDALPHA_MAX_VALUE;
                WRITE_16(temp1, temp2);
                
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | 
                    BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ | DCNT_WIN0 | DCNT_WINOBJ);
                gNonGameplayRam.ending.unk_2 = 1;
                gNonGameplayRam.ending.unk_97 = 0;
            }
            break;
        
        case CONVERT_SECONDS(4 + 1.f / 2):
            if (gNonGameplayRam.ending.unk_99)
            {
                WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG2);
                WRITE_16(REG_BLDCNT, 0);
                gNonGameplayRam.ending.unk_9B = 0;
                gNonGameplayRam.ending.unk_2 = 0;
                gNonGameplayRam.ending.unk_96 = 0;
            }
            break;

        case CONVERT_SECONDS(6 + 5.f / 6):
            finished = TRUE;
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
        gNonGameplayRam.ending.currentCreditLine++;

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
    
    return finished;
}

/**
 * @brief a2d34 | 378 | Setup for the ending image
 * 
 * @return boolu32 Always false
 */
boolu32 EndingImageInit(void) 
{
    s32 ending;
    u32 value;
    s32 i;
    
    WRITE_16(REG_IME, 0);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, 1);

    CallbackSetVBlank(EndingInitFunctionsVBlank);

    WRITE_16(REG_DISPCNT, 0);
    
    if (gNonGameplayRam.ending.completionPercentage > 99)
    {
        ending = 3;

        if (gNonGameplayRam.ending.unk_99 == 2)
        {
            ending = 4;
        }
    }
    else
    {
        ending = gNonGameplayRam.ending.unk_99;
    }

    switch (ending)
    {
        case 0:
            LZ77UncompVram(sEnding_0_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_0_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_0_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_0_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(sEnding_0_Pal, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 1:
            LZ77UncompVram(sEnding_1_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_1_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_1_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_1_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(sEnding_1_Pal, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 2:
            LZ77UncompVram(sEnding_2_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_2_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_2_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_2_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(sEnding_2_Pal, PALRAM_BASE, 16 * PAL_ROW);
            break;

        case 3:
            LZ77UncompVram(sEnding_3_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_3_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_3_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_3_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(sEnding_3_Pal, PALRAM_BASE, 16 * PAL_ROW);
            break;

        default:
            LZ77UncompVram(sEnding_4_GfxTop, VRAM_BASE);
            LZ77UncompVram(sEnding_4_GfxBottom, VRAM_BASE + 0x8000);
            LZ77UncompVram(sEnding_4_TilemapTop, VRAM_BASE + 0xF000);
            LZ77UncompVram(sEnding_4_TilemapBottom, VRAM_BASE + 0xF800);
            DMA3_COPY_16(sEnding_4_Pal, PALRAM_BASE, 16 * PAL_ROW);
            break;
    }

    switch (gLanguage)
    {
        case LANGUAGE_GERMAN:
            LZ77UncompVram(sResultsScreenGermanTextGfx, VRAM_OBJ);
            break;

        case LANGUAGE_FRENCH:
            LZ77UncompVram(sResultsScreenFrenchTextGfx, VRAM_OBJ);
            break;

        case LANGUAGE_ITALIAN:
            LZ77UncompVram(sResultsScreenItalianTextGfx, VRAM_OBJ);
            break;

        case LANGUAGE_SPANISH:
            LZ77UncompVram(sResultsScreenSpanishTextGfx, VRAM_OBJ);
            break;

        default:
            LZ77UncompVram(sResultsScreenEnglishTextGfx, VRAM_OBJ);
            break;
    }

    DMA3_COPY_16(sResultsTextPal, PALRAM_OBJ, 4 * PAL_ROW);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_OBJ);
    WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL | 
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT | 
        BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | 
        BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);

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
    gNonGameplayRam.ending.currentCreditLine = 0;
    gNonGameplayRam.ending.unk_98++;

    value = 31;
    for (i = 31; i >= 0; i--)
        gNonGameplayRam.ending.creditLineTilemap_1[i] = value;

    CallbackSetVBlank(EndingImageVBlank);

    return FALSE;    
}

/**
 * @brief a30ac | 380 | Processes the ending image display
 * 
 * @return boolu32 Finished
 */
boolu32 EndingImage(void) 
{
    boolu32 finished;
    s32 i;
    u16* src;
    u16* dst;
    u32 palette;
    s32 currSlot;
    s32 nextSlot;
    u16 part;
    
    finished = FALSE;
    
    switch (gLanguage) 
    {
        case LANGUAGE_GERMAN:
        case LANGUAGE_FRENCH:
        case LANGUAGE_SPANISH:
            break;
        
        case LANGUAGE_ITALIAN:
        default:
            if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6 + 1.f / 4)) 
            {
                EndingImageDisplayLinePermanently(2);
            } 
            else if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6 + 1.f / 3)) 
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
        
        case CONVERT_SECONDS(1.f / 2):
            EndingImageLoadTextOam(0);
            gNonGameplayRam.ending.unk_97 = 1;
            break;
        
        //case CONVERT_SECONDS(1 + 5.f / 6): // No match
        case CONVERT_SECONDS(11.f / 6):
            EndingImageDisplayLinePermanently(0);
            break;
        
        case CONVERT_SECONDS(3):
            EndingImageDisplayLinePermanently(1);
            break;
        
        case CONVERT_SECONDS(5 + 1.f / 2):
            EndingImageLoadTextOam(1);
            break;
        
        case CONVERT_SECONDS(7 + 2.f / 3):
            EndingImageDisplayLinePermanently(3);
            break;
        
        case CONVERT_SECONDS(8 + 5.f / 6):
            EndingImageDisplayLinePermanently(4);
            break;
        
        case CONVERT_SECONDS(13):
            EndingImageDisplayLinePermanently(5);
            break;
        
        case CONVERT_SECONDS(22 + 14.f / 15):
            if (!(gChangedInput & (KEY_A | KEY_B | KEY_START)))
                gNonGameplayRam.ending.timer--;
            break;
        
        case CONVERT_SECONDS(27 + 11.f / 15):
            finished++;
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

    if (gNonGameplayRam.ending.timer <= CONVERT_SECONDS(23) && (gNonGameplayRam.ending.timer < CONVERT_SECONDS(13 + 1.f / 2) || 
        !(gButtonInput & (KEY_L | KEY_R))))  
    {
        dst = (u16*)&gOamData;
        dst += gNextOamSlot * sizeof(union OamData) / sizeof(*dst);
        
        currSlot = nextSlot = gNextOamSlot;

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
            nextSlot += MOD_AND(part, 0x100);
            
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
    
    return finished;
}

