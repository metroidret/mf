#include "cutscenes/died_from_sr388_collision.h"
#include "globals.h"

#include "constants/audio.h"

#include "data/cutscene_data.h"

void unk_99940(void); // For V-blank callback

/**
 * @brief 9741c | a8 | Main handler for the died on SR388 collision cutscene
 * 
 */
boolu32 DiedOnSr388CollisionHandler(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (gSubGameMode1)
    {
        case 0:
            DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
            gSubGameMode1 = 1;
            break;

        case 1:
            if (DiedOnSr388Collision())
            {
                CUTSCENE_DATA.unk_20E = 0;
                gSubGameMode1 = 2;
            }
            break;

        case 2:
            if (!CUTSCENE_DATA.unk_20E)
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    finished = TRUE;
            }
            else
            {
                CUTSCENE_DATA.unk_20E--;
            }

            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

/**
 * @brief 974c4 | 1f4 | Setup for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram(sEndingBslCrashingObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sEndingBslCrashingObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sEndingBslCrashingBgGfx, VRAM_BASE);
    LZ77UncompVram(sEndingBslExplodingTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sEndingSr388Tilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sEndingBslCrashingBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    gBg1XPosition = 0;
    gBg1YPosition = 8;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 8);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 8;
    gWrittenToBldalpha_Evb = 14;

    SoundPlay_3b1c(SOUND_24D);

    DiedOnSr388CollisionSetupOam(DIED_ON_BSL_COLLISION_OAM_TYPE_REENTRY_PLASMA, 164, 40, TRUE);
    DiedOnSr388CollisionSetupOam(DIED_ON_BSL_COLLISION_OAM_TYPE_FALLING_BSL, 164, 40, TRUE);
    DiedOnSr388CollisionSetupOam(DIED_ON_BSL_COLLISION_OAM_TYPE_REENTRY_DEBRIS, 134, 60, TRUE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    CUTSCENE_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(DiedOnSr388CollisionVblank);
}

/**
 * @brief 976b8 | 1b8 | Processes the died on SR388 collision cutscene
 * 
 */
boolu32 DiedOnSr388CollisionProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    APPLY_DELTA_TIME_INC(CUTSCENE_DATA.timer);
    
    switch (CUTSCENE_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy)
            {
                gWrittenToBldy--;
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 1;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 1:
            CUTSCENE_DATA.timer = 0;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 2:
            if (CUTSCENE_DATA.timer == DELTA_TIME)
            {
                gWrittenToBldalpha_Eva = 10;
                gWrittenToBldalpha_Evb = 10;
                CUTSCENE_DATA.unk_110 = 1;
                CUTSCENE_DATA.unk_111 = 0;
            }
            else if (CUTSCENE_DATA.timer == 2 * DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 3;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    
        case 3:
            if (CUTSCENE_DATA.unk_111 < 15)
            {
                if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 15))
                {
                    CUTSCENE_DATA.timer = 0;
                    CUTSCENE_DATA.unk_110 = 1;
                    CUTSCENE_DATA.unk_111++;
                }
            }
            else if (CUTSCENE_DATA.timer == CONVERT_SECONDS(.25f))
            {
                CUTSCENE_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                CUTSCENE_DATA.subStage = 4;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 4:
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                if (CUTSCENE_DATA.timer == CONVERT_SECONDS(.1f))
                {
                    CUTSCENE_DATA.timer = 0;
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb++;
                }
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                
                if (CUTSCENE_DATA.timer == CONVERT_SECONDS(.25f)) 
                {
                    CUTSCENE_DATA.timer = 0;
                    CUTSCENE_DATA.subStage = 0;
                    finished = TRUE;
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

/**
 * @brief 97870 | 88 | Handler for the died on SR388 collision cutscene
 * 
 */
boolu32 DiedOnSr388Collision(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (CUTSCENE_DATA.stage)
    {
        case 0:
            DiedOnSr388CollisionInit();
            CUTSCENE_DATA.stage = 2;
            break;
            
        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                CUTSCENE_DATA.stage = 2;
            break;
            
        case 2:
            if (DiedOnSr388CollisionProcess())
            {
                CUTSCENE_DATA.subStage = 0;
                CUTSCENE_DATA.unk_213 = 0;
                CUTSCENE_DATA.stage = 3;
            }
            break;
    
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                CUTSCENE_DATA.stage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

/**
 * @brief 978f8 | d8 | Processes the BSL in the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionProcessFallingBsl(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        pOam->xPosition = pOam->spawnX - (pOam->unk_A / 5);
        pOam->yPosition = pOam->spawnY + (pOam->unk_A / 5);
        
        if (pOam->yPosition > SCREEN_Y_MIDDLE)
        {
            pOam->unk_A = 0;
            pOam->stage = 2;
        }

        if (pOam->type == DIED_ON_BSL_COLLISION_OAM_TYPE_FALLING_BSL)
            pOam->scaling--;
        else 
            pOam->scaling -= 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->stage = 3;

        if (pOam->type == DIED_ON_BSL_COLLISION_OAM_TYPE_FALLING_BSL)
        {
            pOam->pOam = sEndingBslExplosionOam_Small;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            CUTSCENE_DATA.subStage = 2;
        }
        else
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    else if (pOam->stage == 3)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 979d0 | 30 | Processes the BSL debris in the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionProcessReentryDebris(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 97a00 | 200 | Spawns a new OAM for the died on SR388 collision cutscene
 * 
 */
u8 DiedOnSr388CollisionSetupOam(DiedOnSr388CollisionOamType type, s16 xPosition, s16 yPosition, u8 descendingSearch)
{
    s8 slot;

    if (!descendingSearch)
    {
        for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_DATA.oam); slot++)
        {
            if (CUTSCENE_DATA.oam[slot].type == 0)
                break;
        }

        if (slot >= ARRAY_SIZE(CUTSCENE_DATA.oam))
            return ARRAY_SIZE(CUTSCENE_DATA.oam);
    }
    else
    {
        for (slot = ARRAY_SIZE(CUTSCENE_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (CUTSCENE_DATA.oam[slot].type == 0)
                break;
        }

        if (slot < 0)
            return ARRAY_SIZE(CUTSCENE_DATA.oam);
    }

    DMA3_FILL_32(0, &CUTSCENE_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    CUTSCENE_DATA.oam[slot].xPosition = xPosition;
    CUTSCENE_DATA.oam[slot].yPosition = yPosition;
    CUTSCENE_DATA.oam[slot].type = type;
    CUTSCENE_DATA.oam[slot].unk_18_0 = 1;

    if (type == DIED_ON_BSL_COLLISION_OAM_TYPE_FALLING_BSL)
    {
        CUTSCENE_DATA.oam[slot].scaling = Q_8_8(1);
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslFallingOam;
        CUTSCENE_DATA.oam[slot].pFunction = DiedOnSr388CollisionProcessFallingBsl;
    }
    else if (type == DIED_ON_BSL_COLLISION_OAM_TYPE_REENTRY_PLASMA)
    {
        CUTSCENE_DATA.oam[slot].scaling = Q_8_8(2);
        CUTSCENE_DATA.oam[slot].unk_18_3 = 1;
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslReentryPlasmaOam;
        CUTSCENE_DATA.oam[slot].pFunction = DiedOnSr388CollisionProcessFallingBsl;
    }
    else if (type == DIED_ON_BSL_COLLISION_OAM_TYPE_REENTRY_DEBRIS)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslReentryDebrisOam;
        CUTSCENE_DATA.oam[slot].pFunction = DiedOnSr388CollisionProcessReentryDebris;
    }

    return slot;
}

/**
 * @brief 97c00 | d8 | V-blank for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);

    if (CUTSCENE_DATA.unk_110 == 1)
    {
        CUTSCENE_DATA.unk_110 = 0;
        DMA3_COPY_32(&sEndingBslExplosionFlashPal[CUTSCENE_DATA.unk_111 * PAL_ROW], PALRAM_BASE + 9 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));   
    }
}

/**
 * @brief 97cd8 | 94 | Unused V-blank for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionVblank_Unused(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
}

/**
 * @brief 97d6c | 60 | Returns slot, X and Y position of an OAM
 * 
 */
u8 DiedOnSr388CollisionGetPositionAndSlotOfOamByType(DiedOnSr388CollisionOamType type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_DATA.oam); slot++)
    {
        if (CUTSCENE_DATA.oam[slot].type == type)
        {
            *pXPosition = CUTSCENE_DATA.oam[slot].xPosition;
            *pYPosition = CUTSCENE_DATA.oam[slot].yPosition;
        
            return slot;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
        
    return ARRAY_SIZE(CUTSCENE_DATA.oam);
}

/**
 * @brief 97dcc | 4 | Empty function
 * 
 */
void unk_97dcc(void)
{
    return;
}

