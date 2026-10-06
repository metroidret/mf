#include "haze.h"

#include "macros.h"
#include "globals.h"
#include "gba/dma.h"

#include "data/haze_data.h"

#include "constants/haze.h"
#include "constants/room.h"

#include "structs/animated_graphics.h"
#include "structs/color_effects.h"
#include "structs/display.h"
#include "structs/event.h"
#include "structs/haze.h"
#include "structs/power_bomb.h"
#include "structs/room.h"

static u8 sHazeData[EFFECT_HAZE_COUNT][3] = {
    [EFFECT_NONE] = {
        HAZE_VALUE_NONE, EFFECT_NONE, FALSE
    },
    [EFFECT_WATER] = {
        HAZE_VALUE_BG3, EFFECT_WATER, TRUE
    },
    [EFFECT_LAVA] = {
        HAZE_VALUE_BG3, EFFECT_LAVA, FALSE
    },
    [EFFECT_LAVA_HEAT_HAZE] = {
        HAZE_VALUE_BG3_STRONG_WEAK, EFFECT_LAVA_HEAT_HAZE, FALSE
    },
    [EFFECT_ACID] = {
        HAZE_VALUE_BG3, EFFECT_ACID, FALSE
    },
    [EFFECT_SNOWFLAKES_COLD_KNOCKBACK] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD_KNOCKBACK, FALSE
    },
    [EFFECT_SNOWFLAKES_COLD] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD, FALSE
    },
    [EFFECT_HEAT_BG3_HAZE] = {
        HAZE_VALUE_BG3_NONE_WEAK, EFFECT_NONE, FALSE
    },
    [EFFECT_HEAT_BG2_BG3_HAZE] = {
        HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM, EFFECT_NONE, FALSE
    },
    [EFFECT_BG3_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE
    },
    [EFFECT_BG2_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_BG1_BG2_BG3] = {
        HAZE_VALUE_BG3_BG2_BG1, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_12] = {
        HAZE_VALUE_13, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_13] = {
        HAZE_VALUE_13, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_14] = {
        HAZE_VALUE_14, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_15] = {
        HAZE_VALUE_14, EFFECT_NONE, FALSE
    },
    [EFFECT_HAZE_16] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE
    },
};

/**
 * @brief 6ed84 | 70 | Sets the background haze effect based on the visual effect of the room entry
 * 
*/
void HazeSetBackgroundEffect(void)
{
    u8 hazeValue;

    HazeResetLoops();

    gCurrentHazeValue = sHazeData[gCurrentRoomEntry.visualEffect][0];

    if (gCurrentHazeValue != 0)
    {
        gCurrentRoomEntry.damagingEffect = sHazeData[gCurrentRoomEntry.visualEffect][1];
        gWaterMovement.moving = sHazeData[gCurrentRoomEntry.visualEffect][2];
    }
    else if (gCurrentRoomEntry.bg0Prop == BG_PROP_FOG)
    {
        gCurrentHazeValue = HazeGetAtmosphericStabilizerValue();
    }

    HazeSetupCode(gCurrentHazeValue);
}

/**
 * @brief 6edf4 | 30 | Gets the haze value for atmospheric stabilizer rooms
 * 
 * @return u8 Haze value
*/
u8 HazeGetAtmosphericStabilizerValue(void)
{
    s32 i;
    u8 hazeValue;

    for (i = 0; i < ARRAY_SIZE(sHaze_3e3758[0]); i++)
    {
        hazeValue = sHaze_3e3758[i][1];
        
        if (gEventCounter <= sHaze_3e3758[i][0])
            break;
    }
    
    return hazeValue;
}

/**
 * @brief 6ee24 | 68 | Transfers the haze effect and clears it
 * 
*/
void HazeTransferAndDeactivate(void)
{
    vu8 buffer;

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_ENABLE | DMA_DEST_RELOAD, gHazeInfo.size / 2));

        buffer = sHaze_3c94cc[0];
        buffer = sHaze_3c94cc[0];

        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / 2));

        gHazeInfo.active = FALSE;
    }
}

/**
 * @brief 6ee8c | 7c | To document
 * 
*/
void unk_6ee8c(void)
{
    vu8 buffer;

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_ENABLE | DMA_DEST_RELOAD, gHazeInfo.size / 2));

        buffer = sHaze_3c94cc[0];
        buffer = sHaze_3c94cc[0];

        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / 2));

        gHazeInfo.active = FALSE;
        gHazeInfo.size = 2;
        gHazeInfo.pAffected = gPreviousHazeValues;
        gCurrentHazeValue = 0;
    }
}

/**
 * @brief 6ef08 | 314 | Sets up code and values for a haze effect
 * 
 * @param hazeValue Haze value
*/
void HazeSetupCode(u8 hazeValue)
{
    gCurrentHazeValue = hazeValue;
    gHazeInfo.enabled = FALSE;

    HazeTransferAndDeactivate();

    switch (gCurrentHazeValue)
    {
        case HAZE_VALUE_GRADIENT:
            HazeCalculateGradient();

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = PALRAM_BASE;
            break;

        case HAZE_VALUE_BG3:
            DmaTransfer(3, Haze_Bg3, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_STRONG_WEAK:
            DmaTransfer(3, Haze_Bg3StrongWeak, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG0:
            DmaTransfer(3, Haze_Bg0, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG0HOFS;
            break;
 
        case HAZE_VALUE_BG3_NONE_WEAK:
            DmaTransfer(3, Haze_Bg3NoneWeak, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM:
            DmaTransfer(3, Haze_Bg3Bg2StrongWeakMedium, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 8;
            gHazeInfo.unk_4 = 0x500;
            gHazeInfo.pAffected = REG_BG2HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_BG1:
            DmaTransfer(3, Haze_Bg3Bg2Bg1, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 12;
            gHazeInfo.unk_4 = 0x780;
            gHazeInfo.pAffected = REG_BG1HOFS;
            break;

        case HAZE_VALUE_POWER_BOMB_EXPANDING:
            gWrittenToWinin_H = HIGH_BYTE(WIN1_ALL_NO_COLOR_EFFECT);
            gWrittenToWinout_L = WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_OBJ | WIN0_COLOR_EFFECT;

            gWrittenToBldcnt_Special = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            WRITE_16(REG_BLDY, 12);

            gWrittenToWin1V = SCREEN_SIZE_Y;
            gWrittenToWin1H = 0;

            ColorEffectPowerBombYellowTint(0);

#ifdef BUGFIX
            WRITE_16(gBackgroundPalette1, COLOR_WHITE);
#endif // BUGFIX

            if (gIoRegisters.dispcnt & DCNT_BG0 && gCurrentRoomEntry.bg0Prop != BG_PROP_14)
                gWrittenToDispcnt = READ_16(REG_DISPCNT) ^ DCNT_BG0;

            gBackdropColor = COLOR_WHITE;

            DmaTransfer(3, Haze_PowerBombExpanding, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_WIN1H;

            if (gHazeInfo.enabled)
                gHazeInfo.active = TRUE;
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            DmaTransfer(3, Haze_PowerBombRetracting, IN_GAME_DATA.hazeCode, sizeof(IN_GAME_DATA.hazeCode), 16);
            gHazeProcessCodePointer = (HazeFunc_T)(IN_GAME_DATA.hazeCode + 1);

            gHazeInfo.enabled = TRUE;

            if (gHazeInfo.enabled)
                gHazeInfo.active = TRUE;
            break;

        case HAZE_VALUE_AFTER_POWER_BOMB:
        case HAZE_VALUE_COLD:
            gCurrentHazeValue = HAZE_VALUE_NONE;
            break;
    }
}

/**
 * @brief 6f21c | 3c | Resets the haze loops
 * 
*/
void HazeResetLoops(void)
{
    if (gPauseScreenFlag == 0)
    {
        gHazeLoops[0] = sHazeLoop_Empty;
        gHazeLoops[1] = sHazeLoop_Empty;
        gHazeLoops[2] = sHazeLoop_Empty;
    }

    gUnk_30053f8 = 0;
    gUnk_30053f9 = 0;
}

/**
 * @brief 6f258 | 1a8 | Calculates the gradient
 * 
*/
void HazeCalculateGradient(void)
{
    s32 i;
    s32 j;
    u16* dst;
    u16* src;
    u16* src2;

    u8 rBase;
    u8 gBase;
    u8 bBase;

    s32 r;
    s32 g;
    s32 b;
    
    u8 newR;
    u8 newG;
    u8 newB;

    dst = gPreviousHazeValues;

    for (i = 0; i < 10 * 16; i++)
    {
        j = 0;
        if (i < 5)
        {
            // Use row 14's first color for first 5
            src = (u16*)(PALRAM_BASE + 14 * PAL_ROW_SIZE);
            j = src[0];
        }
        else if (i >= 10 * PAL_ROW - 5)
        {
            // Use row 14's last color for last 5
            src = (u16*)(PALRAM_BASE + 14 * PAL_ROW_SIZE);
            j = src[PAL_ROW - 1];
        }

        dst[i] = j;
    }

    dst += 5;

    for (i = 0; i < PAL_ROW - 1; i++)
    {
        src = (u16*)(PALRAM_BASE + 14 * PAL_ROW_SIZE);
        src2 = &src[i];
        
        rBase = RED(src2[0]);
        gBase = GREEN(src2[0]);
        bBase = BLUE(src2[0]);

        r = RED(src2[1]);
        g = GREEN(src2[1]);
        b = BLUE(src2[1]);

        r -= rBase;
        g -= gBase;
        b -= bBase;

        for (j = 0; j < 10; j++)
        {
            newR = j * (r / 10) + rBase;
            newR += (r % 10 * j) / 10;
            newR += (r % 100 * j) / 100;

            newG = j * (g / 10) + gBase;
            newG += (g % 10 * j) / 10;
            newG += (g % 100 * j) / 100;
            
            newB = j * (b / 10) + bBase;
            newB += (b % 10 * j) / 10;
            newB += (b % 100 * j) / 100;

            *dst++ = COLOR_GRAD(newR, newG, newB);
        }
    }
}

/**
 * @brief 6f400 | 1c8 | Processes the current haze effect
 * 
 * @return s32 bool, ended
*/
bools32 HazeProcess(void)
{
    bools32 ended;

    ended = FALSE;

    switch (gCurrentHazeValue)
    {
        case HAZE_VALUE_NONE:
            break;
    
        case HAZE_VALUE_BG3:
        case HAZE_VALUE_BG3_STRONG_WEAK:
        case HAZE_VALUE_BG0:
        case HAZE_VALUE_BG3_NONE_WEAK:
        case HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM:
            // Update the haze
            gHazeProcessCodePointer();
            break;

        case HAZE_VALUE_POWER_BOMB_EXPANDING:
            // Update the haze
            if (gHazeProcessCodePointer())
            {
                // Expanding ended, setup retracting
                gCurrentHazeValue = HAZE_VALUE_POWER_BOMB_RETRACTING;
                HazeSetupCode(HAZE_VALUE_POWER_BOMB_RETRACTING);
                gCurrentPowerBomb.animationState = PB_STATE_IMPLODING;

                if (gAnimatedPaletteAndTileset.animatedPalette == 0)
                {
                    DMA3_COPY_16(gBackgroundPalette2, gBackgroundPalette1, COLORS_IN_PAL);
                }
                else
                {
                    DMA3_COPY_16(gBackgroundPalette2, gBackgroundPalette1, COLORS_IN_PAL - (1 * PAL_ROW));
                }

                gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
                gWrittenToWinin_H = HIGH_BYTE(WIN1_BG0 | WIN1_BG1 | WIN1_BG2 | WIN1_OBJ | WIN1_COLOR_EFFECT);
                gWrittenToWinout_L = WIN0_ALL_NO_COLOR_EFFECT;
                gBackdropColor = COLOR_BLACK;
            }
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            if (gHazeProcessCodePointer())
            {
                gIoRegisters.unk_10 = gIoRegisters.bg0Cnt;
                gCurrentPowerBomb.animationState = PB_STATE_ENDING;
                gCurrentPowerBomb.stage = 0;

                HazeSetupCode(HAZE_VALUE_AFTER_POWER_BOMB);

                if (gAnimatedPaletteAndTileset.animatedPalette == 0)
                {
                    DMA3_COPY_16(gBackgroundPalette2, gBackgroundPalette1, COLORS_IN_PAL);
                }
                else
                {
                    DMA3_COPY_16(gBackgroundPalette2, gBackgroundPalette1, COLORS_IN_PAL - (1 * PAL_ROW));
                }

                gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
                ended = TRUE;
            }
            break;

        case HAZE_VALUE_BG3_BG2_BG1:
            Haze_Bg3Bg2Bg1();
            break;

        case 13:
        case 14:
            unk_6fdd0();
            break;
    }

    if (ended)
    {
        HazeSetBackgroundEffect();
        if (gCurrentHazeValue == HAZE_VALUE_NONE)
            ended = FALSE;
    }

    return ended;
}

/**
 * @brief 6f5c8 | c0 | Updates the haze effect (BG3, strong everywhere)
 * 
*/
void Haze_Bg3(void)
{
    u16* dst;
    s32 i;
    const s8* src;
    s32 mask;
    s32 position;
    u8* ptr;

    do {
    dst = gPreviousHazeValues;
    } while (0);
    i = 0;
    
    gHazeLoops[2].unk_3 = 0;
    gHazeLoops[1].unk_3 = 0;
    
    src = sHaze_Bg3_StrongEffect;
    mask = 0xF;
    
    gHazeLoops[0].unk_3 = 0;
    gHazeLoops[0].timer++;

    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;

    position = SUB_PIXEL_TO_PIXEL(gEffectYPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition) - 1;

    CLAMP(position, 0, SCREEN_SIZE_Y);

    for (i = 0; i < position; i++)
    {
        dst[i] = gBackgroundPositions.bg[3].x;
    }

    while (i < SCREEN_SIZE_Y)
    {
        ptr = &gUnk_30053f8;
        do {
        position = (gBackgroundPositions.bg[3].y + i + *ptr) & mask;
        } while (0);
        dst[i] = src[position] + gBackgroundPositions.bg[3].x;
        i++;
    }
}

/**
 * @brief 6f688 | 118 | Updates the haze effect (BG3, strong in effect, weak outside)
 * 
*/
void Haze_Bg3StrongWeak(void)
{
    s32 i;
    const s8* src1;
    s32 mask1;
    const s8* src2;
    s32 mask2;
    s32 position;
    u16* dst;
    s32 offset;
    u8* ptr1;
    u8* ptr2;

    dst = gPreviousHazeValues;

    i = 0;
    gHazeLoops[2].unk_3 = 0;

    src1 = sHaze_Bg3_StrongEffect;
    mask1 = 0xF;

    gHazeLoops[0].unk_3 = 0;
    gHazeLoops[0].timer++;

    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    src2 = sHaze_Bg3_WeakOutside;
    mask2 = ARRAY_SIZE(sHaze_Bg3_WeakOutside) - 1;

    gHazeLoops[1].unk_3 = 0;
    gHazeLoops[1].timer++;

    if (gHazeLoops[1].timer > 11)
    {
        gHazeLoops[1].unk_3 = 1;
        gHazeLoops[1].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;
    gUnk_30053f9 += gHazeLoops[1].unk_3;

    position = SUB_PIXEL_TO_PIXEL(gEffectYPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition) - 1;

    CLAMP(position, 0, SCREEN_SIZE_Y);

    for (i = 0; i < position; i++)
    {
        ptr1 = &gUnk_30053f9;
        offset = (gBackgroundPositions.bg[3].y + i + *ptr1) & mask2;
        dst[i] = src2[offset] + gBackgroundPositions.bg[3].x;
    }

    while (i < SCREEN_SIZE_Y)
    {
        ptr2 = &gUnk_30053f8;
        offset = (gBackgroundPositions.bg[3].y + i + *ptr2) & mask1;
        dst[i] = src1[offset] + gBackgroundPositions.bg[3].x;
        i++;
    }
}

/**
 * @brief 6f7a0 | 70 | Updates the haze effect (BG3, nothing in effect, weak outside)
 * 
*/
void Haze_Bg3NoneWeak(void)
{
    s32 i;
    s32 mask;
    const s8* src;
    u8* ptr;

    i = 0;

    gHazeLoops[2].unk_3 = 0;
    gHazeLoops[1].unk_3 = 0;

    src = sHaze_Bg_WeakOutside;
    mask = ARRAY_SIZE(sHaze_Bg_WeakOutside) - 1;
    gHazeLoops[0].unk_3 = 0;

    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;
    ptr = &gUnk_30053f8;

    for (; i < SCREEN_SIZE_Y; i++)
    {
        gPreviousHazeValues[i] = src[(gBackgroundPositions.bg[3].y + i + *ptr) & mask] + gBackgroundPositions.bg[3].x;
    }
}

/**
 * @brief 6f810 | 90 |  Updates the haze effect (BG3 and BG2, strong in effect, weak outside and medium everywhere)
 * 
*/
void Haze_Bg3Bg2StrongWeakMedium(void)
{
    s32 i;
    s32 mask;
    const s8* src;
    u16* dst;

    i = 0;

    gHazeLoops[1].unk_3 = 0;

    src = sHaze_Bg_WeakOutside;
    mask = ARRAY_SIZE(sHaze_Bg_WeakOutside) - 1;
    gHazeLoops[0].unk_3 = 0;

    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;
    dst = gPreviousHazeValues;

    for (; i < SCREEN_SIZE_Y; i++)
    {
        *dst++ = src[(gBackgroundPositions.bg[2].y + i + gUnk_30053f8) & mask] + gBackgroundPositions.bg[2].x;
        *dst++ = gBackgroundPositions.bg[2].y;

        *dst++ = src[(gBackgroundPositions.bg[3].y + i + gUnk_30053f8) & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}

/**
 * @brief 6f8a0 | ac | To document
 * 
*/
void Haze_Bg0(void)
{
    s32 i;
    s32 mask;
    const s8* src;
    u16* dst;

    i = 0;

    gHazeLoops[1].unk_3 = 0;

    if (gEventBasedEffectInfo.stage > 1)
    {
        gHazeLoops[2].timer++;
        if (gHazeLoops[2].timer > 1)
        {
            gHazeLoops[2].timer = 0;

            if (gHazeLoops[2].unk_3 + 1 < 0xEu)
                gHazeLoops[2].unk_3++;
        }
    }
    else
    {
        gHazeLoops[2].timer = 0;
        gHazeLoops[2].unk_3 = 0;
    }

    src = sHaze_3e3518[gHazeLoops[2].unk_3];
    mask = ARRAY_SIZE(sHaze_3e3518[0]) - 1;
    
    gHazeLoops[0].unk_3 = 0;
    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer >= (gHazeLoops[2].unk_3 + 6) / 2)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;
    dst = gPreviousHazeValues;

    for (i = 0; i < SCREEN_SIZE_Y; i++)
    {
        *dst++ = src[((gBackgroundPositions.bg[0].y + i + gUnk_30053f8) & mask)] + gBackgroundPositions.bg[0].x;
    }
}

/**
 * @brief 6f94c | ec | Updates the haze effect (BG3, BG2 and BG1, strong everywhere)
 * 
*/
void Haze_Bg3Bg2Bg1(void)
{
    s32 i;
    s32 mask;
    const s8* src;
    u16* dst;
    u8* ptr;
    s32 tmp;

    i = 0;
    gHazeLoops[2].timer++;

    if (gUnk_3004e42 == 1)
    {
        if (gHazeLoops[2].timer > 15)
        {
            gHazeLoops[2].timer = 0;
            if (gHazeLoops[2].unk_3 < 4)
                gHazeLoops[2].unk_3++;
        }
    }
    else
    {
        if (gHazeLoops[2].timer > 15)
        {
            gHazeLoops[2].timer = 0;
            if (gHazeLoops[2].unk_3 > 0)
                gHazeLoops[2].unk_3--;
        }
    }

    src = sHaze_Bg3Bg2Bg1[gHazeLoops[2].unk_3];
    mask = ARRAY_SIZE(sHaze_Bg3Bg2Bg1[0]) - 1;

    gHazeLoops[0].unk_3 = 0;
    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 7)
    {
        gHazeLoops[0].unk_3 = 1;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 -= gHazeLoops[0].unk_3;
    dst = gPreviousHazeValues;

    for (i = 0; i < SCREEN_SIZE_Y; i++)
    {
        ptr = &gUnk_30053f8;

        tmp = gBackgroundPositions.bg[1].y + i + *ptr;
        tmp = src[tmp & mask] + gBackgroundPositions.bg[1].x;
        *dst++ = tmp;
        *dst++ = gBackgroundPositions.bg[1].y;

        *dst++ = tmp;
        *dst++ = gBackgroundPositions.bg[2].y;

        tmp = gBackgroundPositions.bg[3].y + i + *ptr;
        *dst++ = src[tmp & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}

/**
 * @brief 6fa38 | 138 | Updates the haze effect (power bomb expanding)
 * 
 * @return s32 bool, ended
*/
bools32 Haze_PowerBombExpanding(void)
{
    const s16* src;
    s16 size;
    s16 xPosition;
    s16 yPosition;
    u16* dst;
    s32 i;
    s32 screenY;
    s32 subSlice;
    s16 left;
    s16 right;

    if (gCurrentPowerBomb.unk_12 != 0)
        return FALSE;

    src = sHaze_PowerBomb_WindowValuesPointers[gCurrentPowerBomb.semiMinorAxis];
    size = gCurrentPowerBomb.semiMinorAxis;
    xPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.xPosition - gBg1XPosition);
    yPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.yPosition - gBg1YPosition);

    dst = gPreviousHazeValues;
    for (i = 0; i <= 53 * 3; i++, dst++)
        *dst = 0;

    screenY = yPosition + size + 1;
    CLAMP(screenY, 0, 53 * 3);

    do {
    subSlice = 0;
    } while(0);
    i = yPosition - size;
    if (i < 0)
    {
        subSlice = -i;
        i = 0;
    }
    else if (i > 53 * 3)
    {
        i = 53 * 3;
    }

    dst = &gPreviousHazeValues[i];
    for (; i < screenY; i++, subSlice++, dst++)
    {
        left = xPosition + src[subSlice * 2 + 1] * 2;
        right = xPosition + src[subSlice * 2 + 0] * 2;

        CLAMP2(left, 0, SCREEN_SIZE_X);
        CLAMP(right, 0, SCREEN_SIZE_X);

        *dst = C_16_2_8_(left, right);
    }

    if (gCurrentPowerBomb.semiMinorAxis >= 53 * 3)
    {
        gCurrentPowerBomb.stage++;
        if (gCurrentPowerBomb.stage > 4)
            return TRUE;
    }
    else
    {
        gCurrentPowerBomb.semiMinorAxis += 3;
        if (gCurrentPowerBomb.semiMinorAxis > 53 * 3)
            gCurrentPowerBomb.semiMinorAxis = 53 * 3;
    }

    return FALSE;
}

/**
 * @brief 6fb70 | 138 | Updates the haze effect (power bomb retracting)
 * 
 * @return s32 bool, ended
*/
bools32 Haze_PowerBombRetracting(void)
{
    const s16* src;
    s16 size;
    s16 xPosition;
    s16 yPosition;
    u16* dst;
    s32 i;
    s32 screenY;
    s32 subSlice;
    s16 left;
    s16 right;

    if (gCurrentPowerBomb.unk_12 != 0)
        return FALSE;

    src = sHaze_PowerBomb_WindowValuesPointers[gCurrentPowerBomb.semiMinorAxis];
    size = gCurrentPowerBomb.semiMinorAxis;
    xPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.xPosition - gBg1XPosition);
    yPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.yPosition - gBg1YPosition);

    dst = gPreviousHazeValues;
    for (i = 0; i <= 53 * 3; i++, dst++)
        *dst = 0;

    screenY = yPosition + size + 1;
    CLAMP(screenY, 0, 53 * 3);

    do {
    subSlice = 0;
    } while(0);
    i = yPosition - size;
    if (i < 0)
    {
        subSlice = -i;
        i = 0;
    }
    else if (i > 53 * 3)
    {
        i = 53 * 3;
    }

    dst = &gPreviousHazeValues[i];
    for (; i < screenY; i++, subSlice++, dst++)
    {
        left = xPosition + src[subSlice * 2 + 1] * 2;
        right = xPosition + src[subSlice * 2 + 0] * 2;

        CLAMP2(left, 0, SCREEN_SIZE_X);
        CLAMP(right, 0, SCREEN_SIZE_X);

        *dst = C_16_2_8_(left, right);
    }

    if (gCurrentPowerBomb.semiMinorAxis <= 4)
    {
        gCurrentPowerBomb.stage++;
        if (gCurrentPowerBomb.stage > 4)
            return TRUE;
    }
    else
    {
        gCurrentPowerBomb.semiMinorAxis -= 3;
        if (gCurrentPowerBomb.semiMinorAxis < 4)
            gCurrentPowerBomb.semiMinorAxis = 4;
    }

    return FALSE;
}

/**
 * @brief 6fca8 | 98 | To document
 * 
*/
void unk_6fca8(void)
{
    s32 i;
    u16* dst;
    s16 fade;
    s32 tmp;
    s16 red;
    s16 green;
    s16 blue;
    s32 fadeGreen;
    s32 fadeBlue;

    gTilesetTransparentColor.unk_4 = gTilesetTransparentColor.transparentColor;

    if (gTilesetTransparentColor.transparentColor == gTilesetTransparentColor.unk_2)
        return;

    gTilesetTransparentColor.unk_2 = gTilesetTransparentColor.transparentColor;

    for (i = 0, dst = gPreviousHazeValues; i < SCREEN_SIZE_Y; i++)
    {
        fade = i >> 2;

        tmp = RED(gTilesetTransparentColor.unk_2) - fade;
        red = tmp;
        if (red < 0)
            red = 0;

        fadeGreen = fade << 5;
        // Written this way to produce matching ASM
        green = ((GREEN(gTilesetTransparentColor.unk_2) << 5) - fadeGreen) & ~(COLOR_MASK | (COLOR_MASK << 10));
        if (green < 0)
            green = 0;

        fadeBlue = fade << 10;
        blue = (BLUE(gTilesetTransparentColor.unk_2) << 10) - fadeBlue;
        if (blue < 0)
            blue = 0;

        dst[i] = blue | green | red;
    }
}

/**
 * @brief 6fd40 | 90 | To document
 * 
*/
void Haze_Bg3Y(void)
{
    const s8* src;
    s32 i;
    u8 offset;

    gHazeLoops[1].unk_3 = 0;

    gHazeLoops[2].timer++;
    if (gHazeLoops[2].timer > 3 && gHazeLoops[2].unk_3 < 0x40)
    {
        gHazeLoops[2].unk_3++;
        gHazeLoops[2].timer = 0;
    }

    src = sHaze_Bg3Y[gHazeLoops[2].unk_3];
    
    gHazeLoops[0].unk_3 = 0;
    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 3)
    {
        gHazeLoops[0].unk_3++;
        gHazeLoops[0].timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;

    for (i = 0; i < SCREEN_SIZE_Y; i++)
    {
        offset = gUnk_30053f8;
        gPreviousHazeValues[i] = src[MOD_AND(gBackgroundPositions.bg[3].y + i + offset, ARRAY_SIZE(sHaze_Bg3Y[0]))];
    }
}

/**
 * @brief 6fdd0 | f8 | To document
 * 
*/
void unk_6fdd0(void)
{
    s32 i;
    u16* dst;
    const s8* src1;
    const s8* src2;
    u8 offset;
    s32 y;

    i = 0;
    gHazeLoops[2].unk_3 = 0;
    gHazeLoops[1].unk_3 = 0;

    dst = gPreviousHazeValues;
    src1 = sHaze_3c9da0;
    src2 = sHaze_3c9dc0;

    gHazeLoops[0].unk_3 = 0;

    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 3)
    {
        gHazeLoops->unk_3 = 1;
        gHazeLoops->timer = 0;
    }

    gUnk_30053f8 += gHazeLoops[0].unk_3;

    if (gCurrentRoomEntry.visualEffect == 0xD || gCurrentRoomEntry.visualEffect == 0xF)
    {
        for (; i < SCREEN_SIZE_Y; i++)
        {
            offset = gUnk_30053f8;
            y = gBackgroundPositions.bg[3].y + i + offset;
            dst[i * 2] = src2[y & 0xF];
            dst[i * 2 + 1] = src1[y & 0x1F];
        }
    }
    else
    {
        for (; i < SCREEN_SIZE_Y; i++)
        {
            offset = gUnk_30053f8;
            y = gBackgroundPositions.bg[3].y + i + offset;
            dst[i * 2] = src2[y & 0xF];
            dst[i * 2 + 1] = src1[y & 0x1F];
        }
    }
}
