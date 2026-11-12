#include "ending_cutscene.h"
#include "new_file_intro.h"
#include "globals.h"

#include "constants/audio.h"
#include "constants/ending_cutscene.h"
#include "constants/text.h"

#include "data/audio.h"
#include "data/cutscene_data.h"
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
                CUTSCENE_DATA.unk_20E = 0;
                gSubGameMode1 = 3;
            }
            break;

        case 3:
            CUTSCENE_DATA.unk_20E++;

            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (CUTSCENE_DATA.unk_20E == 1)
                {
                    CUTSCENE_DATA.unk_20E = 0;
                    gWrittenToBldy++;
                }
            }
            else
            {
                if (CUTSCENE_DATA.unk_20E == 1)
                {
                    Sram_ProcessEndingSave(0);
                }
                else if (CUTSCENE_DATA.unk_20E == 2)
                {   
                    Sram_ProcessEndingSave(1);
                }
                else if (CUTSCENE_DATA.unk_20E == 3)
                {  
                    Sram_ProcessEndingSave(2);
                }
                else if (CUTSCENE_DATA.unk_20E == 4)
                {  
                    Sram_ProcessEndingSave(3);
                    CUTSCENE_DATA.unk_20E = 0;
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

    CUTSCENE_DATA.pText = sCutsceneTextNone;

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

    DMA3_FILL_32(0, &CUTSCENE_DATA.oam, sizeof(CUTSCENE_DATA.oam));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_14, sizeof(CUTSCENE_DATA.unk_14));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_110, 0xFC);

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

    CUTSCENE_DATA.pText = sCutsceneTextNone;

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
    
    APPLY_DELTA_TIME_INC(CUTSCENE_DATA.timer);
    
    switch (CUTSCENE_DATA.subStage)
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
            else if (CUTSCENE_DATA.timer == ONE_THIRD_SECOND)
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
                if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 10))
                {
                    CUTSCENE_DATA.timer = 0;
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb++;
                }
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 5;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 5:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 6;
                EndingShipFrontViewInit();
            }
            break;
            
        case 6:
            WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
            CUTSCENE_DATA.timer = 0;
            CUTSCENE_DATA.subStage = 7;
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 7:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(2.8f))
            {
                CUTSCENE_DATA.timer = 0;
                gWrittenToBldy = 2;
                CUTSCENE_DATA.subStage = 8;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 8:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                CUTSCENE_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva)
                {
                    gWrittenToBldalpha_Eva--;
                    if (!gWrittenToBldalpha_Eva)
                        SpecialCutsceneDestroyOamOfType(ENDING_BSL_CRASHING_OAM_TYPE_EXPLOSION_AFTERGLOW);
                }
                else
                {
                    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                    CUTSCENE_DATA.subStage = 9;
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    
        case 9:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 15))
                {
                    gWrittenToBldy++;
                    CUTSCENE_DATA.timer = 0;
                }
            }
            else if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.5f))
            {
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 0;
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

    switch (CUTSCENE_DATA.stage)
    {
        case 0:
            EndingBslCrashingInit();
            CUTSCENE_DATA.stage = 2;
            break;
            
        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                CUTSCENE_DATA.stage = 2;
            break;
            
        case 2:
            if (EndingBslCrashingProcess())
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
u8 EndingBslCrashingSetupOam(EndingBslCrashingOamType type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
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

    if (type == ENDING_BSL_CRASHING_OAM_TYPE_FALLING_BSL)
    {
        CUTSCENE_DATA.oam[slot].scaling = Q_8_8(1);
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslFallingOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_PLASMA)
    {
        CUTSCENE_DATA.oam[slot].scaling = Q_8_8(2);
        CUTSCENE_DATA.oam[slot].unk_18_3 = 1;
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslReentryPlasmaOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_REENTRY_DEBRIS)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslReentryDebrisOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessReentryDebris;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_SHIP_SMALL)
    {
        CUTSCENE_DATA.oam[slot].unk_18_0 = 0;
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingLeavingSmallShipOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessLeavingSmallShip;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_SHIP_BIG)
    {
        CUTSCENE_DATA.oam[slot].unk_18_0 = 0;
        CUTSCENE_DATA.oam[slot].pOam = sEndingLeavingBigShipOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessLeavingBigShip;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_EXPLOSION_AFTERGLOW)
    {
        CUTSCENE_DATA.oam[slot].unk_18_3 = 1;
        CUTSCENE_DATA.oam[slot].priority = 3;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslExplosionAfterglowOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessOam_Empty;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP_THRUSTERS)
    {
        CUTSCENE_DATA.oam[slot].priority = 3;
        CUTSCENE_DATA.oam[slot].pOam = sEndingFrontFacingShipThrustersOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessFrontFacingShipThrusters;
    }
    else if (type == ENDING_BSL_CRASHING_OAM_TYPE_FRONT_FACING_SHIP)
    {
        CUTSCENE_DATA.oam[slot].unk_18_0 = 0;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslExplosionAfterglowOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessFrontFacingShip;
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

    if (CUTSCENE_DATA.unk_110 == 1)
    {
        CUTSCENE_DATA.unk_110 = 0;
        DMA3_COPY_32(&sEndingBslExplosionFlashPal[CUTSCENE_DATA.unk_111 * PAL_ROW], PALRAM_BASE + 9 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));   
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
 * @brief 95e20 | 4 | Empty OAM handler
 * 
 */
void EndingProcessOam_Empty(struct SpecialCutsceneOam* pOam)
{
    return;
}

/**
 * @brief 95e24 | 200 | Setup for the ending monologue cutscene
 * 
 */
void EndingMonologueInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    
    LZ77UncompVram(sEndingMonologueObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sEndingMonologueObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompVram(sEndingMonologueBgGfx, VRAM_BASE + 0x8000);
    LZ77UncompVram(sEndingSamusSittingTilemap, VRAM_BASE + 0xF800);
    
    DMA3_COPY_32(sEndingMonologueBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0x4800, 0x800 / sizeof(u32));
    
    DMA3_FILL_32(0, VRAM_BASE, 0x4800);
    
    DMA3_COPY_32(sIntroPal_663820, PALRAM_BASE + 12 * PAL_ROW_SIZE, 4 * PAL_ROW_SIZE / sizeof(u32));
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 4);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 9, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 0;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    
    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_MONOLOGUE_CURSOR, 260, 180, FALSE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    CUTSCENE_DATA.pText = sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(EndingMonologueVblank);
}

/**
 * @brief 96024 | 204 | Setup for the ending Adam conversation cutscene
 */
void EndingAdamConversationInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &CUTSCENE_DATA.oam, sizeof(CUTSCENE_DATA.oam));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_14, sizeof(CUTSCENE_DATA.unk_14));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_110, 0xFC);
    
    LZ77UncompVram(sEndingSpaceMapGfx, VRAM_BASE + 0x8000);
    LZ77UncompVram(sEndingSpaceMapTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sEndingMonologueBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    gBg0XPosition = -8;
    gBg0YPosition = 8;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 8);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    
    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_SHIP_TRAJECTORY, 112, SCREEN_Y_MIDDLE, TRUE);
    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_PLANETS, 112, SCREEN_Y_MIDDLE, TRUE);
    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_SHIP, 112, SCREEN_Y_MIDDLE, TRUE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    CUTSCENE_DATA.pText = sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(EndingConversationAndAnimalsVblank);
}

/**
 * @brief 96228 | 220 | Setup for the ending animals cutscene
 * 
 */
void EndingAnimalsInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &CUTSCENE_DATA.oam, sizeof(CUTSCENE_DATA.oam));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_14, sizeof(CUTSCENE_DATA.unk_14));
    DMA3_FILL_16(0, &CUTSCENE_DATA.unk_110, 0xFC);
    
    LZ77UncompVram(sEndingAnimalsGfx_Top, VRAM_BASE);
    LZ77UncompVram(sEndingAnimalsGfx_Bottom, VRAM_BASE + 0x8000);
    LZ77UncompVram(sEndingAnimalsTilemap_Bottom, VRAM_BASE + 0xF000);
    LZ77UncompVram(sEndingAnimalsTilemap_Top, VRAM_BASE + 0xF800);
    
    DMA3_COPY_32(sEndingAnimalsBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_FILL_16(0x2FF, VRAM_BASE + 0xF500, 0x300);

    gBg0XPosition = 0;
    gBg0YPosition = 0;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg3XPosition = 0;
    gBg2YPosition = -30;
    gBg3YPosition = 226;
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 226);
    
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    
    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_ANIMAL_SCROLLING, 0, 0, FALSE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    CUTSCENE_DATA.pText = sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(EndingConversationAndAnimalsVblank);
}

/**
 * @brief 96448 | 4e0 | Processes the ending in ship cutscene
 * 
 */
boolu32 EndingInShipProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    APPLY_DELTA_TIME_INC(CUTSCENE_DATA.timer);
    
    switch (CUTSCENE_DATA.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(7.f / 60))
            {
                CUTSCENE_DATA.timer = 0;
                
                if (gWrittenToBldy)
                {
                    gWrittenToBldy--;
                }
                else
                {
                    PlayMusic(MUSIC_EPILOGUE, 14);
                    CUTSCENE_DATA.subStage = 1;
                }
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 1:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(7.f / 6))
            {
                CUTSCENE_DATA.timer = 0;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
                CUTSCENE_DATA.unk_12 = 0;
                CUTSCENE_DATA.unk_10 = 0;
                CUTSCENE_DATA.unk_E = 0;
                CUTSCENE_DATA.unk_C = 0;
                CUTSCENE_DATA.unk_212 = 0;
                CUTSCENE_DATA.pText = sMonologueTextPointers[gLanguage][7];
                CUTSCENE_DATA.subStage = 2;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 2:
            if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && CUTSCENE_DATA.unk_218 == 0)
                CUTSCENE_DATA.unk_218 = 1;
    
            CUTSCENE_DATA.timer = 0;
        
            if (CUTSCENE_DATA.unk_218 == 2)
            {
                CUTSCENE_DATA.unk_218 = 0;
            }
            else if (CUTSCENE_DATA.unk_218 == 3)
            {
                CUTSCENE_DATA.unk_218 = 0;
                CUTSCENE_DATA.subStage = 3;
            }
            
            if (EndingCheckMonologueEnded())
            {
                CUTSCENE_DATA.subStage = 3;
                CUTSCENE_DATA.unk_218 = 0;
            }
    
            if (CUTSCENE_DATA.unk_213 == 0)
            {
                CUTSCENE_DATA.unk_213 = 100;
            }
            else if (CUTSCENE_DATA.unk_213 == 1)
            {
                CUTSCENE_DATA.unk_213 = 100;
                SpecialCutsceneProcessMonologue();
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 3:
            if (CUTSCENE_DATA.timer == DELTA_TIME)
            {
                gWrittenToBldalpha_Evb = 0;
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            }
            else if (CUTSCENE_DATA.timer == ONE_THIRD_SECOND)
            {
                CUTSCENE_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                CUTSCENE_DATA.subStage = 4;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 4:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 15))
            {
                CUTSCENE_DATA.timer = 0;
                
                if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Evb++;
    
                if (gWrittenToBldalpha_Eva)
                    gWrittenToBldalpha_Eva--;
    
                if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE && gWrittenToBldalpha_Eva == 0)
                {
                    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                    CUTSCENE_DATA.subStage = 5;
                }
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 5:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_SCREEN_GLARE, SCREEN_X_MIDDLE, SCREEN_Y_MIDDLE, TRUE);
            }
            else if (CUTSCENE_DATA.timer == TWO_THIRD_SECOND - DELTA_TIME)
            {
                gWrittenToBldy = BLDY_MAX_VALUE;
            }
            else if (CUTSCENE_DATA.timer == TWO_THIRD_SECOND)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 6;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 6:
            if (CUTSCENE_DATA.timer == DELTA_TIME)
            {
                CUTSCENE_DATA.timer = 0;
                CUTSCENE_DATA.subStage = 7;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 7:
            CUTSCENE_DATA.timer = 0;
            EndingAdamConversationInit();
            CUTSCENE_DATA.subStage = 8;
            break;
            
        case 8:
            gWrittenToBldy = 0;
            CUTSCENE_DATA.timer = 0;
            SoundPlay(SOUND_24C);
            CUTSCENE_DATA.subStage = 9;
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 9:
            if (CUTSCENE_DATA.timer != CONVERT_SECONDS(1.f / 6))
            {
                if (CUTSCENE_DATA.timer == TWO_THIRD_SECOND)
                {
                    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_BSL_EXPLOSION_POPUP_2, 0, 0, FALSE);
                    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_ADAM_TEXT_CURSOR, 20, 192, FALSE);
                    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME, 128, 192, FALSE);
                    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_BACKGROUND, 128, 192, FALSE);
                    CUTSCENE_DATA.timer = 0;
                    CUTSCENE_DATA.subStage = 10;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            EndingProcessAdamText();
            break;
            
        case 10:
            CUTSCENE_DATA.timer = 0;

            if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && CUTSCENE_DATA.unk_218 == 0)
                CUTSCENE_DATA.unk_218 = 1;

            if (CUTSCENE_DATA.unk_218 == 2)
            {
                CUTSCENE_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
            }
            else if (CUTSCENE_DATA.unk_218 == 3)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                CUTSCENE_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
                FadeMusic(10);
                CUTSCENE_DATA.subStage = 11;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            EndingProcessAdamText();
            break;
            
        case 11:
            CUTSCENE_DATA.timer = 0;
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 12:
            if (CUTSCENE_DATA.timer == DELTA_TIME)
            {
                ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_24C].trackGroupNumber].pTrack, 0);
            }
            else if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                CUTSCENE_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                CUTSCENE_DATA.subStage = 13;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 13:
            EndingAnimalsInit();
            CUTSCENE_DATA.timer = 0;
            gWrittenToBldy = 0;
            CUTSCENE_DATA.subStage = 14;
            break;

        case 14:
            if (CUTSCENE_DATA.timer == DELTA_TIME)
            {
                PlayMusic(MUSIC_EPILOGUE_END, 14);
            }
            else if (CUTSCENE_DATA.timer == CONVERT_SECONDS(10 + 2.f / 3))
            {
                CUTSCENE_DATA.timer = 0;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                CUTSCENE_DATA.subStage = 15;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 15:
            if (CUTSCENE_DATA.timer == CONVERT_SECONDS(1.f / 30))
            {
                CUTSCENE_DATA.timer = 0;

                if (gWrittenToBldy < BLDY_MAX_VALUE)
                {
                    gWrittenToBldy++;
                }
                else
                {
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
 * @brief 96928 | 88 | Handler for the ending in ship cutscene
 * 
 */
boolu32 EndingInShip(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (CUTSCENE_DATA.stage)
    {
        case 0:
            EndingMonologueInit();
            CUTSCENE_DATA.stage = 2;
            break;
    
        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                CUTSCENE_DATA.stage = 2;
            break;
    
        case 2:
            if (EndingInShipProcess())
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
 * @brief 969b0 | 30 | Processes the monologue cursor in the ending cutscene
 * 
 */
void EndingProcessMonologueCursor(struct SpecialCutsceneOam* pOam)
{
    if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        pOam->xPosition = 118;
        pOam->yPosition = CUTSCENE_DATA.unk_E * 8 + 24;
    }
    else
    {
        pOam->xPosition = 260;
    }
}

/**
 * @brief 969e0 | 28 | Processes the ship trajectory in the ending Adam dialogue cutscene
 * 
 */
void EndingProcessShipTrajectory(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 96a08 | 34 | Processes the planets in the ending Adam dialogue cutscene
 * 
 */
void EndingProcessSr388RadarView(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingRadarPlanetsOam_2;
            pOam->stage = 1;
        }
    }
}

/**
 * @brief 96a3c | 34 | Processes Samus' ship in the ending Adam dialogue cutscene
 * 
 */
void EndingProcessSamusViewRadarView(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingRadarShipOam_2;
            pOam->stage = 1;
        }
    }
}

/**
 * @brief 96a70 | 9c | Processes the BSL explosion popup in the ending Adam dialogue cutscene (unused)
 * 
 */
void EndingProcessBslExplosionPopup(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    frame = &pOam->pOam[pOam->currentAnimationFrame];

    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 1 && pOam->animationDurationCounter == 1)
            SoundPlay(SOUND_11C);
        
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->animationDurationCounter = 0;

        if (CUTSCENE_DATA.subStage == 11)
        {
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingBslExplosionPopupOam_Closing;
            SoundPlay(SOUND_11D);
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 96b0c | 8c | Processes the Adam text cursor in the ending cutscene
 * 
 */
void EndingProcessAdamTextCursor(struct SpecialCutsceneOam* pOam)
{
    if (*CUTSCENE_DATA.pText == CHAR_TERMINATOR)
    {
        pOam->xPosition = 290;
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEW_LINE)
    {
        pOam->xPosition = CUTSCENE_DATA.unk_C * 8 + CUTSCENE_DATA.unk_212 + 14;
        pOam->yPosition = CUTSCENE_DATA.unk_E * 8 + 132;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEW_PAGE)
    {
        pOam->xPosition = 290;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->pOam = sEndingAdamTextCursorOam;
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        pOam->xPosition = SCREEN_X_MIDDLE;
        pOam->yPosition = 154;
        pOam->pOam = sEndingMonologueCursorOam;
    }
    else
    {
        pOam->xPosition = CUTSCENE_DATA.unk_C * 8 + CUTSCENE_DATA.unk_212 + 14;
        pOam->yPosition = CUTSCENE_DATA.unk_E * 8 + 132;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
    }
}

/**
 * @brief 96b98 | 1a8 | Processes the Adam panel during the ending cutscene
 * 
 */
void EndingProcessAdamPanel(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        
        if (pOam->yPosition > 128)
        {
            pOam->yPosition -= 8;
        }
        else
        {
            pOam->yPosition = 128;

            if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
                SoundPlay(SOUND_20A);

            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter)
        {
            if (frame[1].timer == 0)
            {
                pOam->animationDurationCounter = 0;
                pOam->stage = 2;
            }
            
            if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
            {
                if (pOam->currentAnimationFrame == 10)
                    EndingDialogueSetupOam(ENDING_DIALOGUE_OAM_TYPE_ADAM_LENS, pOam->xPosition, pOam->yPosition, FALSE);
            }
        }

        if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
        {
            if (pOam->currentAnimationFrame == 11)
            {
                if (pOam->animationDurationCounter == 15)
                {
                    CUTSCENE_DATA.unk_212 = 0;
                    CUTSCENE_DATA.unk_E = 0;
                    CUTSCENE_DATA.unk_C = 0;
                    CUTSCENE_DATA.pText = sNavigationTextPointers[gLanguage][112];
                }
            }
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->animationDurationCounter = 0;

        APPLY_DELTA_TIME_INC(pOam->timer);
        if (pOam->timer == DELTA_TIME)
        {
            pOam->timer = 0;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        pOam->animationDurationCounter = 0;
        
        if (CUTSCENE_DATA.subStage == 11)
        {
            pOam->currentAnimationFrame = 0;
            
            if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
            {
                pOam->pOam = sEndingAdamPanelFrameOam_Closing;
                SoundPlay(SOUND_20B);
            }
            else if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_BACKGROUND)
            {
                pOam->pOam = sEndingAdamPanelBackgroundOam_Closing;
            }

            pOam->stage = 4;
        }
    }
    else if (pOam->stage == 4)
    {
        if (pOam->currentAnimationFrame == 11 && pOam->animationDurationCounter == 3)
        {
            if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
                SpecialCutsceneDestroyOamOfType(ENDING_DIALOGUE_OAM_TYPE_ADAM_LENS);

            pOam->animationDurationCounter = 0;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->animationDurationCounter = 0;

        if (pOam->yPosition < 192)
        {
            pOam->yPosition += 8;
        }
        else
        {
            if (pOam->type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
                CUTSCENE_DATA.subStage = 12;

            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 96d40 | 88 | Processes Adam's lens in the ending cutscene
 * 
 */
void EndingProcessAdamIcon(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    frame = &pOam->pOam[pOam->currentAnimationFrame];
    
    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 3)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingAdamLensOam_Idle;
            pOam->stage = 1;
        }
        
        if (CUTSCENE_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingAdamLensOam_Closing;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 1)
    {
        if (CUTSCENE_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sEndingAdamLensOam_Closing;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 96dc8 | 138 | Processes the scrolling during the ending animals cutscene
 * 
 */
void EndingProcessAnimalsScrolling(struct SpecialCutsceneOam* pOam)
{
    APPLY_DELTA_TIME_INC(pOam->timer);
    
    if (pOam->stage == 0)
    {
        pOam->xPosition = gBg2XPosition;
        pOam->yPosition = gBg2YPosition;
        pOam->spawnX = gBg3XPosition;
        pOam->spawnY = gBg3YPosition;

        if ((s16)gBg2YPosition < -32)
        {
            pOam->unk_A = 0x4000;
            DMA3_FILL_32(0, VRAM_BASE + 0x8000 + pOam->unk_A, 0x1000);
        }
        else
        {
            pOam->unk_A = 0x5000;
        }
        
        pOam->timer = 0;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->timer == CONVERT_SECONDS(1.f / 6))
        {
            pOam->timer = 0;
            pOam->stage = 2;
        }
    }
    else if (CUTSCENE_DATA.subStage == 14)
    {
        if (pOam->timer == CONVERT_SECONDS(1.f / 30))
        {
            pOam->timer = 0;

            if (pOam->yPosition > -SCREEN_SIZE_Y)
            {
                pOam->yPosition--;
                pOam->unk_8++;
            }
            
            if (pOam->spawnY > 0)
                pOam->spawnY--;

            gBg2YPosition = pOam->yPosition;
            gBg3YPosition = pOam->spawnY;
        }
        
        if (pOam->unk_8 == 9)
        {
            pOam->unk_8 = 0;
            
            if (pOam->unk_A)
            {
                pOam->unk_A -= 0x400;
                DMA3_FILL_32(0, VRAM_BASE + 0x8000 + pOam->unk_A, 0x400);
            }
        }
    }
    else
    {
        pOam->timer = 0;
    }
}

/**
 * @brief 96f00 | 8 | To document
 * 
 */
void unk_96f00(struct SpecialCutsceneOam* pOam)
{
    pOam->type = 0;
}

/**
 * @brief 96f08 | 380 | Spawn a new OAM for the ending dialogue
 * 
 */
u8 EndingDialogueSetupOam(EndingDialogueOamType type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
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
    
    if (type == ENDING_DIALOGUE_OAM_TYPE_MONOLOGUE_CURSOR)
    {
        CUTSCENE_DATA.oam[slot].pOam = sEndingMonologueCursorOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessMonologueCursor;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_SHIP_TRAJECTORY)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingRadarShipTrajectoryOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessShipTrajectory;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_PLANETS)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingRadarPlanetsOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessSr388RadarView;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_SHIP)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingRadarShipOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessSamusViewRadarView;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_BSL_EXPLOSION_POPUP)
    {
        CUTSCENE_DATA.oam[slot].priority = 2;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslExplosionPopupOam_Opening;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessBslExplosionPopup;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_ADAM_TEXT_CURSOR)
    {
        CUTSCENE_DATA.oam[slot].pOam = sEndingAdamTextCursorOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessAdamTextCursor;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_FRAME)
    {
        CUTSCENE_DATA.oam[slot].priority = 1;
        CUTSCENE_DATA.oam[slot].pOam = sEndingAdamPanelFrameOam_Opening;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessAdamPanel;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_ADAM_LENS)
    {
        CUTSCENE_DATA.oam[slot].priority = 1;
        CUTSCENE_DATA.oam[slot].pOam = sEndingAdamLensOam_Opening;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessAdamIcon;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_ADAM_PANEL_BACKGROUND)
    {
        CUTSCENE_DATA.oam[slot].priority = 1;
        CUTSCENE_DATA.oam[slot].pOam = sEndingAdamPanelBackgroundOam_Opening;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessAdamPanel;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_ANIMAL_SCROLLING)
    {
        CUTSCENE_DATA.oam[slot].unk_18_0 = 0;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessAnimalsScrolling;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_SCREEN_GLARE)
    {
        SoundPlay(SOUND_12D);
        CUTSCENE_DATA.oam[slot].priority = 1;
        CUTSCENE_DATA.oam[slot].pOam = sEndingScreenGlareOam;
        CUTSCENE_DATA.oam[slot].pFunction = EndingProcessOam_Empty2;
    }
    else if (type == ENDING_DIALOGUE_OAM_TYPE_BSL_EXPLOSION_POPUP_2)
    {
        CUTSCENE_DATA.oam[slot].unk_18_0 = 0;
        CUTSCENE_DATA.oam[slot].pOam = sEndingBslExplosionPopupOam_Opening;
        CUTSCENE_DATA.oam[slot].pFunction = unk_96f00;
    }

    return slot;
}

/**
 * @brief 97288 | 9c | V-blank for the ending monologue
 * 
 */
void EndingMonologueVblank(void)
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
    
    unk_98158();
}

/**
 * @brief 97324 | 94 | V-blank for the ending conversation and animals cutscenes
 * 
 */
void EndingConversationAndAnimalsVblank(void)
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
 * @brief 973b8 | 60 | Returns slot, X and Y position of an OAM
 * 
 */
u8 EndingGetPositionAndSlotOfOamByType_2(EndingDialogueOamType type, s16* pXPosition, s16* pYPosition)
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
 * @brief 97418 | 4 | Empty OAM handler
 * 
 */
void EndingProcessOam_Empty2(struct SpecialCutsceneOam* pOam)
{
    return;
}

