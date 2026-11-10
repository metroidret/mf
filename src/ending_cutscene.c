#include "ending_cutscene.h"
#include "globals.h"

#include "constants/audio.h"
#include "constants/ending_cutscene.h"

#include "data/intro_data.h"
#include "data/generic_data.h"

void unk_99940(void); // For V-blank callback

/**
 * @brief 94e84 | f0 | Main handler for the ending cutscenes
 */
boolu32 EndingHandler(void)
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
            if (EndingBslCrashing())
                gSubGameMode1 = 2;
            break;

        case 2:
            if (EndingInShip())
            {
                INTRO_DATA.unk_20E = 0;
                gSubGameMode1 = 3;
            }
            break;

        case 3:
            INTRO_DATA.unk_20E++;

            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.unk_20E == 1)
                {
                    INTRO_DATA.unk_20E = 0;
                    gWrittenToBldy++;
                }
            }
            else
            {
                if (INTRO_DATA.unk_20E == 1)
                {
                    Sram_ProcessEndingSave(0);
                }
                else if (INTRO_DATA.unk_20E == 2)
                {   
                    Sram_ProcessEndingSave(1);
                }
                else if (INTRO_DATA.unk_20E == 3)
                {  
                    Sram_ProcessEndingSave(2);
                }
                else if (INTRO_DATA.unk_20E == 4)
                {  
                    Sram_ProcessEndingSave(3);
                    INTRO_DATA.unk_20E = 0;
                    finished = TRUE;
                }
            }

            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

/**
 * @brief 94f74 | 204 | Setup for the ending BSL crashing cutscene
 * 
 */
void EndingBslCrashingInit(void)
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
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 8;
    gWrittenToBldalpha_Evb = 14;

    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_SHIP_BIG, -40, 200, FALSE);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_SHIP_SMALL, 128, 72, TRUE);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_PLASMA, 164, 40, TRUE);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_FALLING_BSL, 164, 40, TRUE);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_DEBRIS, 134, 60, TRUE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(EndingBslCrashingVblank);
}

/**
 * @brief 95178 | 200 | Setup for the ending ship front view
 * 
 */
void EndingShipFrontViewInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    DMA3_FILL_16(0, &INTRO_DATA.unk_14, sizeof(INTRO_DATA.unk_14));
    DMA3_FILL_16(0, &INTRO_DATA.unk_110, 0xFC);

    LZ77UncompVram(sEndingShipFrontViewBgGfx, VRAM_BASE);
    LZ77UncompVram(sEndingShipFrontTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sEndingSpaceExplosionTilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sEndingShipFrontViewBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = -30;
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
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP, 0, gBg2YPosition, FALSE);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_EXPLOSION_AFTERGLOW, SCREEN_X_MIDDLE, 106, 1);
    EndingBslCrashingSetupOam(ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP_THRUSTERS, SCREEN_X_MIDDLE, 64, 0);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingShipFrontViewVblank);
}

/**
 * @brief 95378 | 2c4 | Processes the ending BSL crashing cutscene
 * 
 */
boolu32 EndingBslCrashingProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy)
            {
                if (gWrittenToBldy == BLDY_MAX_VALUE)
                    SoundPlay_3b1c(SOUND_24B);
    
                gWrittenToBldy--;
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 1:
            INTRO_DATA.timer = 0;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 2:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                gWrittenToBldalpha_Eva = 10;
                gWrittenToBldalpha_Evb = 10;
                INTRO_DATA.unk_110 = 1;
                INTRO_DATA.unk_111 = 0;
            }
            else if (INTRO_DATA.timer == 2 * DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 3:
            if (INTRO_DATA.unk_111 < 15)
            {
                if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 15))
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.unk_110 = 1;
                    INTRO_DATA.unk_111++;
                }
            }
            else if (INTRO_DATA.timer == ONE_THIRD_SECOND)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                INTRO_DATA.subStage = 4;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 4:
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 10))
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb++;
                }
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 5;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 5:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 6;
                EndingShipFrontViewInit();
            }
            break;
            
        case 6:
            WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 7;
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 7:
            if (INTRO_DATA.timer == CONVERT_SECONDS(2.8f))
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = 2;
                INTRO_DATA.subStage = 8;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 8:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva)
                {
                    gWrittenToBldalpha_Eva--;
                    if (!gWrittenToBldalpha_Eva)
                        SpecialCutsceneDestroyOamOfType(ENDING_BSL_CRASHING_OAM_TYPE_EXPLOSION_AFTERGLOW);
                }
                else
                {
                    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                    INTRO_DATA.subStage = 9;
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    
        case 9:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 15))
                {
                    gWrittenToBldy++;
                    INTRO_DATA.timer = 0;
                }
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

/**
 * @brief 9563c | 88 | Handler for the ending BSL crashing cutscene
 * 
 */
boolu32 EndingBslCrashing(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            EndingBslCrashingInit();
            INTRO_DATA.stage = 2;
            break;
            
        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;
            
        case 2:
            if (EndingBslCrashingProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;
    
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

/**
 * @brief 956c4 | d8 | Processes the falling BSL in the ending cutscene
 * 
 */
void EndingProcessFallingBsl(struct SpecialCutsceneOam* pOam)
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

        if (pOam->type == ENDING_BSL_CRASHING_OAM_TYPE_FALLING_BSL)
            pOam->scaling--;
        else 
            pOam->scaling -= 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->stage = 3;

        if (pOam->type == ENDING_BSL_CRASHING_OAM_TYPE_FALLING_BSL)
        {
            pOam->pOam = sEndingBslExplosionOam_Small; // Barely visible ingame because the scaling doesn't get reset
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            INTRO_DATA.subStage = 2;
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
 * @brief 9579c | 30 | Processes the BSL debris in the ending cutscene
 * 
 */
void EndingProcessReentryDebris(struct SpecialCutsceneOam* pOam)
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
 * @brief 957cc | 64 | Processes Samus's ship leaving the BSL in the ending cutscene (far away)
 * 
 */
void EndingProcessLeavingSmallShip(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        
        if (pOam->unk_A == CONVERT_SECONDS(2.5f))
        {
            pOam->unk_A = 0;
            pOam->unk_18_0 = 1;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->xPosition = pOam->spawnX - (pOam->unk_A << 2);
        pOam->yPosition = pOam->spawnY + (pOam->unk_A / 3);
        
        if (pOam->xPosition < 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 95830 | 64 | Processes Samus's ship leaving the BSL in the ending cutscene (close up)
 * 
 */
void EndingProcessLeavingBigShip(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        
        if (pOam->unk_A == 240)
        {
            pOam->unk_A = 0;
            pOam->unk_18_0 = 1;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->xPosition = pOam->spawnX + (pOam->unk_A << 2);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A * 3);
        
        if (pOam->xPosition > 280)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 95894 | 34 | Processes the thrusters of the front facing ship in the ending cutscene
 * 
 */
void EndingProcessFrontFacingShipThrusters(struct SpecialCutsceneOam* pOam)
{
    s16 x;
    s16 y;

    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    
    EndingGetPositionAndSlotOfOamByType(ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP, &x, &y);
    pOam->yPosition = pOam->spawnY - y;
}

/**
 * @brief 958c8 | 90 | Processes the front facing ship in the ending cutscene
 * 
 */
void EndingProcessFrontFacingShip(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->timer = CONVERT_SECONDS(1.f / 15);
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->yPosition = (SIN(pOam->timer) >> 3) + pOam->spawnY;
        if (pOam->timer == CONVERT_SECONDS(16.f / 15))
        {
            pOam->stage = 2;
            pOam->unk_A = 0;
        }
    }
    else if (pOam->stage == 2)
    {
        if (pOam->unk_A == 2)
        {
            pOam->unk_A = 0;
            APPLY_DELTA_TIME_INC(pOam->timer);
        }
    
        pOam->yPosition = (SIN(pOam->timer) >> 3) + pOam->spawnY;
    }
    
    gBg2YPosition = pOam->yPosition;
}

/**
 * @brief 95958 | 2fc | Spawns an OAM for the ending BSL crashing cutscene
 * 
 */
u8 EndingBslCrashingSetupOam(EndingBslCrashingOamType type, s16 xPosition, s16 yPosition, u8 descendingSearch)
{
    s8 slot;

    if (!descendingSearch)
    {
        for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }

        if (slot >= ARRAY_SIZE(INTRO_DATA.oam))
            return ARRAY_SIZE(INTRO_DATA.oam);
    }
    else
    {
        for (slot = ARRAY_SIZE(INTRO_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }

        if (slot < 0)
            return ARRAY_SIZE(INTRO_DATA.oam);
    }

    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == ENDING_BSL_CRASHING_OAM_TYPE_FALLING_BSL)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = sEndingBslFallingOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_PLASMA)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(2);
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = sEndingBslReentryPlasmaOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_DEBRIS)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sEndingBslReentryDebrisOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessReentryDebris;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_SHIP_SMALL)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sEndingLeavingSmallShipOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessLeavingSmallShip;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_SHIP_BIG)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = sEndingLeavingBigShipOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessLeavingBigShip;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_EXPLOSION_AFTERGLOW)
    {
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sEndingBslExplosionAfterglowOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessOam_Empty;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP_THRUSTERS)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sEndingFrontFacingShipThrustersOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFrontFacingShipThrusters;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = sEndingBslExplosionAfterglowOam;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFrontFacingShip;
    }
    
    return slot;
}

/**
 * @brief 95c54 | d8 | V-blank for the ending BSL crashing cutscene
 * 
 */
void EndingBslCrashingVblank(void)
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

    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;
        DMA3_COPY_32(&sEndingPal_636a38[INTRO_DATA.unk_111 * PAL_ROW], PALRAM_BASE + 9 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));   
    }
}

/**
 * @brief 95d2c | 94 | V-blank for the ending ship front view cutscene
 * 
 */
void EndingShipFrontViewVblank(void)
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
 * @brief 95dc0 | 60 | Returns slot, X and Y position of an ending OAM
 * 
 */
u8 EndingGetPositionAndSlotOfOamByType(EndingBslCrashingOamType type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == type)
        {
            *pXPosition = INTRO_DATA.oam[slot].xPosition;
            *pYPosition = INTRO_DATA.oam[slot].yPosition;
        
            return slot;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
        
    return ARRAY_SIZE(INTRO_DATA.oam);
}

/**
 * @brief 95e20 | 4 | Empty OAM handler
 * 
 */
void EndingProcessOam_Empty(struct SpecialCutsceneOam* pOam)
{
    return;
}



/**
 * @brief  |  | To document
 * 
 */
