#include "color_effects.h"

#include "dma.h"
#include "gba/memory.h"
#include "globals.h"
#include "macros.h"

#include "data/color_fading_data.h"

#include "structs/animated_graphics.h"
#include "structs/color_effects.h"

s32 (*sBlendWhiteBlackFunctionPointers[4])(u8, u8, u8, u8) = {
    ColorEffectBlendFromWhite,
    ColorEffectBlendToWhite,
    ColorEffectBlendFromBlack,
    ColorEffectBlendToBlack,
};

/**
 * @brief 6cf0c | 14 | Copies palette RAM to EWRAM palettes 2 and 1
 * 
 */
void ColorEffectCopyPalramToEwramPal2And1(void)
{
    ColorEffectCopyPalramToEwramPal2();
    WaitForDma3();
    ColorEffectCopyPalramToEwramPal1();
}

/**
 * @brief 6cf20 | 40 | Copies palette RAM to EWRAM palette 2
 * 
 */
void ColorEffectCopyPalramToEwramPal2(void)
{
    DMA3_COPY_16(PALRAM_BASE, gBackgroundPalette2, COLORS_IN_PAL);
    WaitForDma3();
    DMA3_COPY_16(PALRAM_OBJ, gObjectPalette2, COLORS_IN_PAL);
}

/**
 * @brief 6cf60 | 40 | Copies palette RAM to EWRAM palette 1
 * 
 */
void ColorEffectCopyPalramToEwramPal1(void)
{
    DMA3_COPY_16(PALRAM_BASE, gBackgroundPalette1, COLORS_IN_PAL);
    WaitForDma3();
    DMA3_COPY_16(PALRAM_OBJ, gObjectPalette1, COLORS_IN_PAL);
}

/**
 * @brief 6cfa0 | 40 | Copies EWRAM palette 2 to EWRAM palette 1
 * 
 */
void ColorEffectCopyEwramPal2ToEwramPal1(void)
{
    DMA3_COPY_16(gBackgroundPalette2, gBackgroundPalette1, COLORS_IN_PAL);
    WaitForDma3();
    DMA3_COPY_16(gObjectPalette2, gObjectPalette1, COLORS_IN_PAL);
}

/**
 * @brief 6cfe0 | 40 | Copies EWRAM palette 3 to EWRAM palette 1
 * 
 */
void ColorEffectCopyEwramPal3ToEwramPal1(void)
{
    DMA3_COPY_16(gBackgroundPalette3, gBackgroundPalette1, COLORS_IN_PAL);
    WaitForDma3();
    DMA3_COPY_16(gObjectPalette3, gObjectPalette1, COLORS_IN_PAL);
}

/**
 * @brief 6d020 | 40 | Copies EWRAM background palette 3 and object palette 2 to EWRAM palette 1
 * 
 */
void ColorEffectCopyBgPal3AndObjPal2ToPal1(void)
{
    DMA3_COPY_16(gBackgroundPalette3, gBackgroundPalette1, COLORS_IN_PAL);
    WaitForDma3();
    DMA3_COPY_16(gObjectPalette2, gObjectPalette1, COLORS_IN_PAL);
}

/**
 * @brief 6d060 | 94 | Creates a monochrome version of background palette 2 in palette 1
 * 
 */
void ColorEffectMakePaletteMonochrome(void)
{
    struct ColorMultiplier factors;
    u16* dst;
    u16* src;
    s32 i;
    u8 r;
    u8 g;
    u8 b;
    s32 average;
    u16 result;

    factors = sMonochromeMultiplier;
    dst = gBackgroundPalette3;
    src = gBackgroundPalette2;

    for (i = 0; i < COLORS_IN_PAL; i++, dst++, src++)
    {
        r = RED(*src);
        g = GREEN(*src);
        b = BLUE(*src);
        average = ((r * factors.red) + (g * factors.green) + (b * factors.blue)) / 3;

        if (average > COLOR_MAX)
            average = COLOR_MAX;
        b = average & COLOR_MASK;

        *dst = COLOR_GRAD(b, b, b);
    }
}

/**
 * @brief 6d0f4 | 68 | Checks the color fading status and transfers EWRAM palette 1 to palette RAM (all rows)
 * 
 */
void ColorEffectCheckTransferFadedPalette_All(void)
{
    if (gColorFading.status == 0)
        return;

    if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
    {
        DMA3_COPY_16(gBackgroundPalette1, PALRAM_BASE, COLORS_IN_PAL);
        gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
    }

    if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
    {
        DMA3_COPY_16(gObjectPalette1, PALRAM_OBJ, COLORS_IN_PAL);
        gColorFading.status &= ~COLOR_FADING_STATUS_ON_OBJ;
    }
}

/**
 * @brief 6d15c | dc | Checks the color fading status and transfers EWRAM palette 1 to palette RAM (skips Samus rows)
 * 
 */
void ColorEffectCheckTransferFadedPalette_SkipSamus(void)
{
    if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
    {
        if (gColorFading.status != 0)
        {
            if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
            {
                DMA3_COPY_16(gBackgroundPalette1, PALRAM_BASE, COLORS_IN_PAL);
                gColorFading.status ^= COLOR_FADING_STATUS_ON_BG;
            }

            if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
            {
                DMA3_COPY_16(gObjectPalette1 + PAL_ROW_SIZE * 2,
                    PALRAM_OBJ + PAL_ROW_SIZE * 2, PAL_ROW * 14);
                gColorFading.status ^= COLOR_FADING_STATUS_ON_OBJ;
            }
        }
    }
    else
    {
        if (gColorFading.status != 0)
        {
            if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
            {
                DMA3_COPY_16(gBackgroundPalette1, PALRAM_BASE, COLORS_IN_PAL);
                gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
            }

            if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
            {
                DMA3_COPY_16(gObjectPalette1, PALRAM_OBJ, COLORS_IN_PAL);
                gColorFading.status &= ~COLOR_FADING_STATUS_ON_OBJ;
            }
        }
    }
}

/**
 * @brief 6d238 | 1b0 | Fades palette 2 or 3 between black or white into palette 1 (skips hatches, HUD, and minimap rows)
 * 
 * @param fadeOut Fade from original to black/white
 * @param step Color fading step (0-32)
 */
void ColorEffectFadePalette_SkipHud(boolu8 fadeOut, u8 step)
{
    u8 i;
    u16* dst;
    u16* src;
    s32 j;
    u8 red;
    u8 green;
    u8 blue;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            // Background palette
            dst = gBackgroundPalette1;
            if (gColorFading.usePalette3 & COLOR_FADING_STATUS_ON_BG)
                src = gBackgroundPalette3;
            else
                src = gBackgroundPalette2;
        }
        else
        {
            // Object palette
            dst = gObjectPalette1;
            if (gColorFading.usePalette3 & COLOR_FADING_STATUS_ON_OBJ)
                src = gObjectPalette3;
            else
                src = gObjectPalette2;
        }

        for (j = 0; j < COLORS_IN_PAL; j++, dst++, src++)
        {
            if (i == 0)
            {
                // Background palette
                if (gColorFading.type == COLOR_FADING_DOOR_WHITE || gColorFading.type == COLOR_FADING_DOOR_BLACK)
                {
                    // Skip row 1 (hatches)
                    if (DIV_SHIFT(j, PAL_ROW) == BG_PAL_ROW_HATCHES)
                        continue;
                }
            }
            else
            {
                // Object palette
                // Skip rows 3 and 6 (HUD and minimap)
                if (DIV_SHIFT(j, PAL_ROW) == OBJ_PAL_ROW_HUD_AMMO || DIV_SHIFT(j, PAL_ROW) == OBJ_PAL_ROW_MINIMAP)
                    continue;
            }

            red = RED(*src);
            green = GREEN(*src);
            blue = BLUE(*src);

            if (gColorFading.type & COLOR_FADING_WHITE)
            {
                if (!fadeOut)
                {
                    // Fade from white to original
                    red = COLOR_MAX - DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = COLOR_MAX - DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = COLOR_MAX - DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to white
                    red = red + DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = green + DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = blue + DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
            }
            else
            {
                if (!fadeOut)
                {
                    // Fade from black to original
                    red = DIV_SHIFT(red * step, COLOR_RANGE);
                    green = DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = DIV_SHIFT(blue * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to black
                    red = red - DIV_SHIFT(red * step, COLOR_RANGE);
                    green = green - DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = blue - DIV_SHIFT(blue * step, COLOR_RANGE);
                }
            }

            *dst = COLOR_GRAD(red, green, blue);
        }
    }

    gColorFading.status = 3;
}

/**
 * @brief 6d3e8 | 178 | Fades palette 2 or 3 between black or white into palette 1 (all rows)
 * 
 * @param fadeOut Fade from original to black/white
 * @param step Color fading step (0-32)
 */
void ColorEffectFadePalette_All(boolu8 fadeOut, u8 step)
{
    u8 i;
    u16* dst;
    u16* src;
    s32 j;
    u8 red;
    u8 green;
    u8 blue;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            // Background palette
            dst = gBackgroundPalette1;
            if (gColorFading.usePalette3 & 1)
                src = gBackgroundPalette3;
            else
                src = gBackgroundPalette2;
        }
        else
        {
            // Object palette
            dst = gObjectPalette1;
            if (gColorFading.usePalette3 & 2)
                src = gObjectPalette3;
            else
                src = gObjectPalette2;
        }

        for (j = 0; j < COLORS_IN_PAL; j++, dst++, src++)
        {
            red = RED(*src);
            green = GREEN(*src);
            blue = BLUE(*src);

            if (gColorFading.type & COLOR_FADING_WHITE)
            {
                if (!fadeOut)
                {
                    // Fade from white to original
                    red = COLOR_MAX - DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = COLOR_MAX - DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = COLOR_MAX - DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to white
                    red = red + DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = green + DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = blue + DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
            }
            else
            {
                if (!fadeOut)
                {
                    // Fade from black to original
                    red = DIV_SHIFT(red * step, COLOR_RANGE);
                    green = DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = DIV_SHIFT(blue * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to black
                    red = red - DIV_SHIFT(red * step, COLOR_RANGE);
                    green = green - DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = blue - DIV_SHIFT(blue * step, COLOR_RANGE);
                }
            }

            *dst = COLOR_GRAD(red, green, blue);

        }
    }

    gColorFading.status = 3;
}

/**
 * @brief 6d560 | 158 | Fades palette 2 or 3 between black or white into palette 1 (skips Samus rows)
 * 
 * @param fadeOut Fade from original to black/white
 * @param step Color fading step (0-32)
 */
void ColorEffectFadePalette_SkipSamus(boolu8 fadeOut, u8 step)
{
    u8 i;
    u16* dst;
    u16* src;
    s32 j;
    u8 red;
    u8 green;
    u8 blue;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            // Background palette
            dst = gBackgroundPalette1;
            src = gBackgroundPalette2;
        }
        else
        {
            // Object palette
            dst = gObjectPalette1;
            src = gObjectPalette2;
        }

        for (j = 0; j < COLORS_IN_PAL; j++, dst++, src++)
        {
            // Skip if object palette row 0 or 1 (used for Samus)
            if (i != 0 && DIV_SHIFT(j, PAL_ROW) <= OBJ_PAL_ROW_SAMUS_2)
                continue;

            red = RED(*src);
            green = GREEN(*src);
            blue = BLUE(*src);

            if (gColorFading.type & COLOR_FADING_WHITE)
            {
                if (!fadeOut)
                {
                    // Fade from white to original
                    red = COLOR_MAX - DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = COLOR_MAX - DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = COLOR_MAX - DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to white
                    red = red + DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE);
                    green = green + DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE);
                    blue = blue + DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE);
                }
            }
            else
            {
                if (!fadeOut)
                {
                    // Fade from black to original
                    red = DIV_SHIFT(red * step, COLOR_RANGE);
                    green = DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = DIV_SHIFT(blue * step, COLOR_RANGE);
                }
                else
                {
                    // Fade from original to black
                    red = red - DIV_SHIFT(red * step, COLOR_RANGE);
                    green = green - DIV_SHIFT(green * step, COLOR_RANGE);
                    blue = blue - DIV_SHIFT(blue * step, COLOR_RANGE);
                }
            }

            *dst = COLOR_GRAD(red, green, blue);

        }
    }

    gColorFading.status = 3;
}

/**
 * @brief 6d6b8 | 170 | Cross fades between EWRAM palette 2 and 3 into palette 1
 * 
 * @param startPal3 Fade from palette 3 to palette 2
 * @param speed Controls the speed of the fade
 * @return s32 bool, done fading
 */
bools32 ColorEffectUpdateBgCrossFade(boolu8 startPal3, s8 speed)
{
    s32 i;
    s32 step;
    u16* dst;
    u16* pPalStart;
    u16* pPalEnd;

    u8 startR, startG, startB;
    u8 endR, endG, endB;
    u8 newR, newG, newB;

    if (gColorFading.fadeTimer == COLOR_RANGE)
        return TRUE;

    i = speed;
    if (i < 0)
    {
        // Increment fade timer by `speed` every frame
        i = (0xFF ^ i) + 1;
        step = 1;
    }
    else
    {
        // Increment fade timer by 1 every `speed` frames
        step = i;
        i = 1;
    }

    gColorFading.unk_3++;

    if (gColorFading.unk_3 >= step)
    {
        gColorFading.unk_3 = 0;

        gColorFading.fadeTimer += i;
        if (gColorFading.fadeTimer > COLOR_RANGE)
            gColorFading.fadeTimer = COLOR_RANGE;

        step = gColorFading.fadeTimer;
        dst = gBackgroundPalette1;

        if (!startPal3)
        {
            pPalStart = gBackgroundPalette2;
            pPalEnd = gBackgroundPalette3;
        }
        else
        {
            pPalEnd = gBackgroundPalette2;
            pPalStart = gBackgroundPalette3;
        }

        for (i = 0; i < COLORS_IN_PAL; i++, dst++, pPalStart++, pPalEnd++)
        {
            startR = RED(*pPalStart);
            startG = GREEN(*pPalStart);
            startB = BLUE(*pPalStart);

            endR = RED(*pPalEnd);
            endG = GREEN(*pPalEnd);
            endB = BLUE(*pPalEnd);

            if (endR > startR)
                newR = startR + DIV_SHIFT(step * (endR - startR), COLOR_RANGE);
            else
                newR = startR - DIV_SHIFT(step * (startR - endR), COLOR_RANGE);

            if (endG > startG)
                newG = startG + DIV_SHIFT(step * (endG - startG), COLOR_RANGE);
            else
                newG = startG - DIV_SHIFT(step * (startG - endG), COLOR_RANGE);

            if (endB > startB)
                newB = startB + DIV_SHIFT(step * (endB - startB), COLOR_RANGE);
            else
                newB = startB - DIV_SHIFT(step * (startB - endB), COLOR_RANGE);

            *dst = COLOR_GRAD(newR, newG, newB);
        }
    }

    return FALSE;
}

/**
 * @brief 6d828 | 88 | Makes the object palette monochrome and copies it to EWRAM palette 2
 * 
 * @param startRow The palette row to start from
 */
void ColorEffectMakeObjPaletteMonochrome(u8 startRow)
{
    u16* pPal;
    s32 i;
    u8 r;
    u8 g;
    u8 b;
    s32 average;

    pPal = (u16*)(PALRAM_OBJ + startRow * PAL_ROW_SIZE);

    for (i = startRow * PAL_ROW; i < COLORS_IN_PAL; i++, pPal++)
    {
        r = RED(*pPal);
        g = GREEN(*pPal);
        b = BLUE(*pPal);
        average = (r + g + b) / 3;

        if (average > COLOR_MAX)
            average = COLOR_MAX;

        *pPal = COLOR(average, average, average);
    };

    DMA3_COPY_16(PALRAM_OBJ + startRow * PAL_ROW_SIZE,
        gObjectPalette2 + startRow * PAL_ROW_SIZE, (PAL_SIZE - startRow * PAL_ROW_SIZE) / 2);
}

/**
 * @brief 6d8b0 | ac | Creates the yellow tint during a power bomb explosion
 * 
 * @param startRow The palette row to start from
 */
void ColorEffectPowerBombYellowTint(u8 startRow)
{
    s32 end;
    u16* pPal;
    s32 i;
    u8 r;
    u8 g;
    u8 b;

    // Skip animated palette row if present
    if (gAnimatedPaletteAndTileset.animatedPalette == 0)
        end = COLORS_IN_PAL;
    else
        end = COLORS_IN_PAL - (1 * PAL_ROW);

    // Apply tint on background palette 1
    DMA3_COPY_16(PALRAM_BASE, gBackgroundPalette1, COLORS_IN_PAL);

    pPal = gBackgroundPalette1 + (startRow * PAL_ROW);

    for (i = startRow * PAL_ROW; i < end; i++, pPal++)
    {
        // Skip first color of each row
        if (i % PAL_ROW == 0)
            continue;

        r = RED(*pPal);
        g = GREEN(*pPal);
        b = BLUE(*pPal);

        r += 5;
        g += 5;

        if (r > COLOR_MAX)
            r = COLOR_MAX;

        if (g > COLOR_MAX)
            g = COLOR_MAX;

        *pPal = COLOR(r, g, b);
    }

    gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
}

/**
 * @brief 6d95c | 6c | Makes the background palette monochrome and copies it to EWRAM palette 2
 * 
 */
void ColorEffectMakeBgPaletteMonochrome(void)
{
    u16* pPal;
    s32 i;
    u8 r;
    u8 g;
    u8 b;
    s32 average;

    pPal = (u16*)PALRAM_BASE;

    for (i = 0; i < COLORS_IN_PAL; i++, pPal++)
    {
        r = RED(*pPal);
        g = GREEN(*pPal);
        b = BLUE(*pPal);
        average = (r + g + b) / 3;

        if (average > COLOR_MAX)
            average = COLOR_MAX;

        *pPal = COLOR(average, average, average);
    }

    DMA3_COPY_16(PALRAM_BASE, gBackgroundPalette2, COLORS_IN_PAL);
}

/**
 * @brief 6d9c8 | 48 | Blends from white to a color
 * 
 * @param red Red component
 * @param green Green component
 * @param blue Blue component
 * @param step Color blend step (0-32)
 * @return s32 Blended color
 */
s32 ColorEffectBlendFromWhite(u8 red, u8 green, u8 blue, u8 step)
{
    u8 r;
    u8 g;
    u8 b;

    r = (COLOR_MAX - DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE)) & COLOR_MASK;
    g = (COLOR_MAX - DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE)) & COLOR_MASK;
    b = (COLOR_MAX - DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE)) & COLOR_MASK;

    return COLOR_GRAD(r, g, b);
}

/**
 * @brief 6da10 | 44 | Blends from a color to white
 * 
 * @param red Red component
 * @param green Green component
 * @param blue Blue component
 * @param step Color blend step (0-32)
 * @return s32 Blended color
 */
s32 ColorEffectBlendToWhite(u8 red, u8 green, u8 blue, u8 step)
{
    u8 r;
    u8 g;
    u8 b;

    r = (red + DIV_SHIFT((COLOR_MAX - red) * step, COLOR_RANGE)) & COLOR_MASK;
    g = (green + DIV_SHIFT((COLOR_MAX - green) * step, COLOR_RANGE)) & COLOR_MASK;
    b = (blue + DIV_SHIFT((COLOR_MAX - blue) * step, COLOR_RANGE)) & COLOR_MASK;

    return COLOR_GRAD(r, g, b);
}

/**
 * @brief 6da54 | 38 | Blends from black to a color
 * 
 * @param red Red component
 * @param green Green component
 * @param blue Blue component
 * @param step Color blend step (0-32)
 * @return s32 Blended color
 */
s32 ColorEffectBlendFromBlack(u8 red, u8 green, u8 blue, u8 step)
{
    u8 r;
    u8 g;
    u8 b;

    r = DIV_SHIFT(red * step, COLOR_RANGE) & COLOR_MASK;
    g = DIV_SHIFT(green * step, COLOR_RANGE) & COLOR_MASK;
    b = DIV_SHIFT(blue * step, COLOR_RANGE) & COLOR_MASK;

    return COLOR_GRAD(r, g, b);
}

/**
 * @brief 6da8c | 40 | Blends from a color to black
 * 
 * @param red Red component
 * @param green Green component
 * @param blue Blue component
 * @param step Color blend step (0-32)
 * @return s32 Blended color
 */
s32 ColorEffectBlendToBlack(u8 red, u8 green, u8 blue, u8 step)
{
    u8 r;
    u8 g;
    u8 b;

    r = (red - DIV_SHIFT(red * step, COLOR_RANGE)) & COLOR_MASK;
    g = (green - DIV_SHIFT(green * step, COLOR_RANGE)) & COLOR_MASK;
    b = (blue - DIV_SHIFT(blue * step, COLOR_RANGE)) & COLOR_MASK;

    return COLOR_GRAD(r, g, b);
}
