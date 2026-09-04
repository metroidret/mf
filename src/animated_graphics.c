#include "animated_graphics.h"

#include "macros.h"
#include "gba/dma.h"

#include "data/animated_graphics_data.h"
#include "data/animated_tiles_data.h"

#include "constants/animated_graphics.h"

#include "structs/animated_graphics.h"

/**
 * @brief 695b4 | 270 | Transfers the animated graphics to VRAM
 *
 */
void AnimatedGraphicsTransfer(void)
{
    if (gAnimatedGraphicsToUpdate == 0)
        return;

    if (gAnimatedGraphicsToUpdate & 1 << 0)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(0), ANIMATED_GFX_VRAM_POS(0), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 1)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(1), ANIMATED_GFX_VRAM_POS(1), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 2)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(2), ANIMATED_GFX_VRAM_POS(2), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 3)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(3), ANIMATED_GFX_VRAM_POS(3), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 4)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(4), ANIMATED_GFX_VRAM_POS(4), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 5)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(5), ANIMATED_GFX_VRAM_POS(5), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 6)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(6), ANIMATED_GFX_VRAM_POS(6), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 7)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(7), ANIMATED_GFX_VRAM_POS(7), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 8)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(8), ANIMATED_GFX_VRAM_POS(8), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 9)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(9), ANIMATED_GFX_VRAM_POS(9), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 10)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(10), ANIMATED_GFX_VRAM_POS(10), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 11)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(11), ANIMATED_GFX_VRAM_POS(11), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 12)
    {
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(3), ANIMATED_GFX_SIZE_16_BITS);
    }

    if (gAnimatedGraphicsToUpdate & 1 << 13)
    {
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_POS(13), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_END_POS(2), ANIMATED_GFX_SIZE_16_BITS);
    }

    if (gAnimatedGraphicsToUpdate & 1 << 14)
    {
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_POS(14), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_END_POS(1), ANIMATED_GFX_SIZE_16_BITS);
    }

    if (gAnimatedGraphicsToUpdate & 1 << 15)
    {
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_POS(15), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_END_POS(0), ANIMATED_GFX_SIZE_16_BITS);
    }

    gAnimatedGraphicsToUpdate = 0;
}

/**
 * @brief 69824 | 168 | Updates the animated graphics
 * 
 */
void AnimatedGraphicsUpdate(void)
{
    struct AnimatedGraphicsInfo* pGraphics;
    s32 i;
    bools32 update;
    s8 frame;
    s32 currFrame;
    const u8* src;

    // Loop through every current animated graphics
    for (pGraphics = gAnimatedGraphicsData, i = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); i++, pGraphics++)
    {
        update = FALSE;

        // Apply animation type
        switch (pGraphics->type)
        {
            case ANIMATED_GFX_TYPE_NONE:
                // No type, so no graphics
                break;

            case ANIMATED_GFX_TYPE_NORMAL:
                // Standard animation progression
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);
                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;

                    if (pGraphics->currentAnimationFrame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 0;
                }
                break;

            case ANIMATED_GFX_TYPE_NORMAL_ONCE:
                // Play the animation normally, but only once (no looping)
                if (pGraphics->currentAnimationFrame != pGraphics->numberOfStates - 1)
                {
                    APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);
                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;

                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame++;
                    }
                }
                break;

            case ANIMATED_GFX_TYPE_ALTERNATE:
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;

                    frame = pGraphics->currentAnimationFrame;
                    if (frame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 2 - frame;
                }
                break;

            case ANIMATED_GFX_TYPE_REVERSE_ONCE:
                // Standard animation progression, just played backwards and played once (no looping)
                if (pGraphics->currentAnimationFrame != 0)
                {
                    APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;

                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame--;
                    }
                }
                break;

            case ANIMATED_GFX_TYPE_REVERSE:
                // Standard animation progression, just played backwards
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame--;

                    if (pGraphics->currentAnimationFrame < 0)
                    {
                        // Reached "start", set last frame
                        pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
                    }
                }
                break;
        }

        if (update)
        {
            frame = pGraphics->currentAnimationFrame;
            currFrame = pGraphics->currentAnimationFrame;
            if (currFrame < 0)
            {
                // Fancy negation
                frame = ~currFrame + 1;
            }

            // Get graphics
            src = &pGraphics->pGraphics[frame * ANIMATED_GFX_SIZE];

            // Transfer graphics to EWRAM
            DMA3_COPY_16(src, ANIMATED_GFX_EWRAM_POS(i), ANIMATED_GFX_SIZE_16_BITS);

            // Mark for transfer to VRAM
            gAnimatedGraphicsToUpdate |= 1 << i;
        }
    }
}

/**
 * @brief 6998c | f0 | Loads the animated graphics
 * 
 */
void AnimatedGraphicsLoad(void)
{
    struct AnimatedGraphicsInfo* pGraphics;
    s32 i;
    s32 j;
    u8 altFlagIdx;
    u8 entry;
    const struct AnimatedGraphicsData* pData;
    const u8* src;
    u8* dst;

    gAnimatedGraphicsToUpdate = 0;

    for (pGraphics = gAnimatedGraphicsData, i = 0, j = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); i++, pGraphics++, j += 3)
    {
        // Get animated graphics entry
        // j + 0 is the default animated graphics ID
        // j + 1 is an index into gUseAlternateAnimatedTilesetFlags
        // j + 2 is the alternate animated graphics ID
        if (gUseAlternateAnimatedTilesetFlags[sAnimatedTilesetEntries[gAnimatedPaletteAndTileset.animatedTileset][j + 1]] & 1)
            entry = sAnimatedTilesetEntries[gAnimatedPaletteAndTileset.animatedTileset][j + 2];
        else
            entry = sAnimatedTilesetEntries[gAnimatedPaletteAndTileset.animatedTileset][j];
        pData = &sAnimatedGraphicsEntries[entry];

        // Fetch data
        pGraphics->type = pData->type;
        pGraphics->framesPerState = pData->framesPerState;
        pGraphics->numberOfStates = pData->numberOfStates;

        // Setup animation
        pGraphics->animationDurationCounter = 0;
        pGraphics->currentAnimationFrame = 0;
        pGraphics->pGraphics = pData->pGraphics;

        switch (pGraphics->type)
        {
            case ANIMATED_GFX_TYPE_NORMAL_ONCE:
            case ANIMATED_GFX_TYPE_REVERSE:
                // Set start on last frame
                pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
        }

        // Direct transfer to VRAM
        src = &pGraphics->pGraphics[pGraphics->currentAnimationFrame * ANIMATED_GFX_SIZE];
        dst = ANIMATED_GFX_VRAM_POS(i);

        DMA3_COPY_16(src, dst, ANIMATED_GFX_SIZE_16_BITS);
    }

    DMA3_COPY_16(ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(4 - 1), ANIMATED_GFX_SIZE * 4 / 2);
}

/**
 * @brief 69a7c | 1c | Resets the tank animations
 * 
 */
void AnimatedGraphicsResetTanks(void)
{
    gTankAnimations[0].timer = DELTA_TIME * 1;
    gTankAnimations[0].frame = 0;

    gTankAnimations[1].timer = DELTA_TIME * 2;
    gTankAnimations[1].frame = 0;

    gTankAnimations[2].timer = DELTA_TIME * 3;
    gTankAnimations[2].frame = 0;
}

/**
 * @brief 69a98 | 6c | Updates the tank animations
 * 
 */
void AnimatedGraphicsUpdateTanks(void)
{
    s32 i;

    for (i = ARRAY_SIZE(gTankAnimations) - 1; i >= 0; i--)
    {
        // Update timer
        APPLY_DELTA_TIME_INC(gTankAnimations[i].timer);

        // Swap animation frame every 5 frames
        if (gTankAnimations[i].timer <= ANIMATED_GFX_TANK_FRAME_DELAY)
            continue;

        gTankAnimations[i].timer = 0;

        // Update current frame
        gTankAnimations[i].frame++;
        if (gTankAnimations[i].frame >= ANIMATED_GFX_TANK_NBR)
            gTankAnimations[i].frame = 0;

        // Transfer graphics
        DMA3_COPY_16(&sAnimatedTankGfx[ANIMATED_GFX_TANK_POS(i, gTankAnimations[i].frame)],
            ANIMATED_GFX_TANK_VRAM_POS(i), ANIMATED_GFX_SIZE_16_BITS);
    }
}
