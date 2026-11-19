#include "cutscenes/monologue.h"

#include "globals.h"
#include "new_file_intro.h"

#include "data/cutscene_data.h"

void CutsceneMonologueProcessCursor(struct MonologueOam* pOam);
void unk_9d09c(struct MonologueOam* pOam);

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneHandler(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (gSubGameMode1)
    {
        case 0:
            CutsceneInit();
            gSubGameMode1 = 2;
            break;

        case 1:
            if (gWrittenToBldy != 0)
                gWrittenToBldy--;
            else
                gSubGameMode1++;
            break;
        
        case 2:
            if (CutsceneProcess())
                gSubGameMode1++;
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                finished = TRUE;
                gSubGameMode1 = 0;
            }
            break;
    }

    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99af8);

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    DMA3_COPY_32(VRAM_OBJ, EWRAM_BASE + 0x1C000, 0x8000 / sizeof(u32));

    gNextOamSlot = 0;
    ResetFreeOam();

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    DMA3_FILL_32(COLOR_WHITE, PALRAM_BASE, 16 * PAL_ROW_SIZE);
    SET_BACKDROP_COLOR(COLOR_BLACK);
    DMA3_FILL_32(0, VRAM_BASE, 0x10000);

    WRITE_16(REG_BG3CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    WRITE_16(REG_BG1CNT, 0);
    WRITE_16(REG_BG0CNT, 0);

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_DISPCNT, 0);

    CallbackSetVBlank(CutsceneVblank);
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneVblank(void)
{
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 99af8 | c | To document
 * 
 */
void unk_99af8(void)
{
    UpdateAudio();
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (gCurrentCutscene - 1)
    {
        case 0:
        case 7:
            if (CutsceneInternalMonologue(0))
                finished = TRUE;
            break;

        case 1:
            if (CutsceneElevatorMonologue(0))
                finished = TRUE;
            break;
    
        case 2:
            if (CutsceneElevatorMonologue(0))
                finished = TRUE;
            break;
    
        case 3:
            if (CutsceneElevatorMonologue(0))
                finished = TRUE;
            break;
    
        case 4:
            if (CutsceneElevatorMonologue(1))
                finished = TRUE;
            break;
    
        case 5:
            if (CutsceneElevatorMonologue(0))
                finished = TRUE;
            break;
    
        case 6:
            if (CutsceneFederationMonologue(0))
                finished = TRUE;
            break;
    
        case 8:
            if (CutsceneSecretConversation())
                finished = TRUE;
            break;
    
        case 9:
        case 10:
            if (CutsceneRestrictedLabDetaching())
                finished = TRUE;
            break;
    
        case 11:
            if (CutsceneBslExploding())
                finished = TRUE;
            break;

        default:
            finished = TRUE;
            break;

    }

    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneElevatorMonologue(u8 arg0)
{
    boolu32 finished;

    finished = FALSE;

    switch (MONOLOGUE_DATA.stage)
    {
        case 0:
            MONOLOGUE_DATA.stage = 1;
            CutsceneElevatorMonologueInit(arg0);
            break;
        
        case 1:
            CutsceneMonologueFadeIn();
            if (gWrittenToBldy == 0)
                MONOLOGUE_DATA.stage++;
            break;
        
        case 2:
            if (CutsceneElevatorMonologueProcess())
            {
                MONOLOGUE_DATA.stage = 3;
                WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;
        
        case 3:
            CutsceneMonologueFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                finished = TRUE;
            break;
    }

    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneElevatorMonologueInit(u8 arg0)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_9a31c);
    
    WRITE_16(REG_DISPCNT, 0);
    
    LZ77UncompVram(sMonologueObjGfxPointers[gCurrentCutscene - 1], VRAM_OBJ + 0x2000);
    LZ77UncompVram(sMonologueTilemap_65fb5c, VRAM_OBJ + 0x7C00);

    DMA3_COPY_32(sMonologuePal_6638A0, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sMonologueObjPalPointers[gCurrentCutscene - 1], PALRAM_OBJ, 6 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sMonologueBgGfxPointers[gCurrentCutscene - 1], VRAM_BASE);
    LZ77UncompVram(sMonologueTilemapPointers[gCurrentCutscene - 1], VRAM_BASE + 0xD000);
    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    LZ77UncompVram(sMonologueTilemap_663598, VRAM_BASE + 0xD800);

    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sMonologuePal_6636a0, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sMonologueBgPalPointers[gCurrentCutscene - 1], PALRAM_BASE, 11 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 27, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);

    gWrittenToBldy--;

    CutsceneElevatorMonologueSetupOam(1, 12, 16);
    CutsceneElevatorMonologueSetupOam(2, SCREEN_X_MIDDLE, 120);
    CutsceneElevatorMonologueSetupOam(3, SCREEN_X_MIDDLE, 120);

    if (arg0 == 0)
        CutsceneElevatorMonologueSetupOam(4, SCREEN_X_MIDDLE, 104);
    else
        CutsceneElevatorMonologueSetupOam(5, SCREEN_X_MIDDLE, 104);

    MONOLOGUE_DATA.unk_A = gCurrentCutscene - 1;
    MONOLOGUE_DATA.pText = sMonologueTextPointers[gLanguage][MONOLOGUE_DATA.unk_A];

    CutsceneMonologueDrawAllOam();

    CallbackSetVBlank(CutsceneElevatorMonologueVblank);
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneElevatorMonologueProcess(void)
{
    boolu32 finished;

    finished = CutsceneMonologueProcessSpecialTextCharacters();
    
    switch (MONOLOGUE_DATA.unk_17)
    {
        case 0:
            MONOLOGUE_DATA.unk_17 = 100;
            break;

        case 1:
            MONOLOGUE_DATA.unk_17 = 100;
            CutsceneMonologueProcessText();
            break;
    }
    
    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();

    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
u8 CutsceneElevatorMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);

    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;

    if (type == 1)
    {
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sOam_663e5c;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    else if (type == 2)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][0];
        MONOLOGUE_DATA.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == 3)
    {
        MONOLOGUE_DATA.oam[slot].objMode = OAM_OBJ_MODE_WINDOW;
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][0];
        MONOLOGUE_DATA.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == 4)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][1];
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneProcessElevatorScrolling;
    }
    else if (type == 5)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][1];
        MONOLOGUE_DATA.oam[slot].pFunction = unk_9a1a8;
    }
    
    return slot;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneProcessElevatorScrolling(struct MonologueOam* pOam)
{
    pOam->yPosition += 2;
    WRITE_16(REG_BG2VOFS, --MONOLOGUE_DATA.unk_12);

    if (pOam->unk_9 == 0)
    {
        if (gWrittenToBldy == 0)
        {
            gWrittenToBldalpha_Eva = 0;
            gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
            WRITE_16(REG_WININ, 0);
            WRITE_16(REG_WINOUT, WIN0_BG0 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN1_BG0 | WIN1_BG1 | WIN1_OBJ | WIN1_COLOR_EFFECT);
            WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 = 0);
            WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
            WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | (DCNT_BG1 | DCNT_WINOBJ));
            pOam->unk_9 = 1;
        }
    }
    else if (pOam->unk_9 == 1)
    {
        if (gWrittenToBldalpha_Eva == 10)
        {
            pOam->unk_9 = 2;
            pOam->unk_8 = 0;
        }
        else
        {
            if (pOam->unk_8 > 3)
            {
                pOam->unk_8 = 0;
                gWrittenToBldalpha_Eva++;
            }
            else
            {
                pOam->unk_8++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 -= 3);
    }
    else
    {
        if (gWrittenToBldalpha_Eva == 4)
        {
            pOam->unk_9 = 1;
            pOam->unk_8 = 0;
        }
        else
        {
            if (pOam->unk_8 > 3)
            {
                pOam->unk_8 = 0;
                gWrittenToBldalpha_Eva--;
            }
            else
            {
                pOam->unk_8++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 -= 3);
    }
}

/**
 * @brief  |  | To document
 * 
 */
void unk_9a1a8(struct MonologueOam* pOam)
{
    pOam->yPosition -= 2;
    WRITE_16(REG_BG2VOFS, ++MONOLOGUE_DATA.unk_12);

    if (pOam->unk_9 == 0)
    {
        if (gWrittenToBldy == 0)
        {
            gWrittenToBldalpha_Eva = 0;
            gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
            WRITE_16(REG_WININ, 0);
            WRITE_16(REG_WINOUT, WIN0_BG0 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN1_BG0 | WIN1_BG1 | WIN1_OBJ | WIN1_COLOR_EFFECT);
            WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 = 0);
            WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
            WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | (DCNT_BG1 | DCNT_WINOBJ));
            pOam->unk_9 = 1;
        }
    }
    else if (pOam->unk_9 == 1)
    {
        if (gWrittenToBldalpha_Eva == 10)
        {
            pOam->unk_9 = 2;
            pOam->unk_8 = 0;
        }
        else
        {
            if (pOam->unk_8 > 3)
            {
                pOam->unk_8 = 0;
                gWrittenToBldalpha_Eva++;
            }
            else
            {
                pOam->unk_8++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 += 3);
    }
    else
    {
        if (gWrittenToBldalpha_Eva == 4)
        {
            pOam->unk_9 = 1;
            pOam->unk_8 = 0;
        }
        else
        {
            if (pOam->unk_8 > 3)
            {
                pOam->unk_8 = 0;
                gWrittenToBldalpha_Eva--;
            }
            else
            {
                pOam->unk_8++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 += 3);
    }
}
 
/**
 * @brief  |  | To document
 * 
 */
void CutsceneElevatorMonologueVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief  |  | To document
 * 
 */
void unk_9a31c(void)
{
    UpdateAudio();
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneInternalMonologue(u8 arg0)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (MONOLOGUE_DATA.stage)
    {
        case 0:
            MONOLOGUE_DATA.stage = 1;
            CutsceneInternalMonologueInit(arg0);
            break;
        
        case 1:
            CutsceneMonologueFadeIn();
            if (gWrittenToBldy == 0)
                MONOLOGUE_DATA.stage++;
            break;
        
        case 2:
            if (CutsceneInternalMonologueProcess())
            {
                MONOLOGUE_DATA.stage = 3;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;
        
        case 3:
            CutsceneMonologueFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                finished = TRUE;
            break;
    }
    
    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneInternalMonologueInit(u8 arg0)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_9a63c);
    
    WRITE_16(REG_DISPCNT, 0);
    
    LZ77UncompVram(sMonologueTilemap_65fb5c, VRAM_OBJ + 0x7C00);
    
    DMA3_COPY_32(sMonologuePal_6638A0, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sMonologuePal_6636a0, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_OBJ);
    
    gWrittenToBldy--;

    CutsceneInternalMonologueSetupOam(1, 12, 16);
    
    MONOLOGUE_DATA.unk_A = gCurrentCutscene - 1;
    MONOLOGUE_DATA.pText = sMonologueTextPointers[gLanguage][MONOLOGUE_DATA.unk_A];
    
    CutsceneMonologueDrawAllOam();
    
    CallbackSetVBlank(CutsceneInternalMonologueVblank);
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneInternalMonologueProcess(void)
{
    boolu32 finished;

    finished = CutsceneMonologueProcessSpecialTextCharacters();
    
    switch (MONOLOGUE_DATA.unk_17)
    {
        case 0:
            MONOLOGUE_DATA.unk_17 = 100;
            break;
        
        case 1:
            MONOLOGUE_DATA.unk_17 = 100;
            CutsceneMonologueProcessText();
            break;
    }
    
    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();
    
    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
u8 CutsceneInternalMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);
    
    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;
    
    if (type == 1)
    {
        MONOLOGUE_DATA.oam[slot].priority = 2;
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sOam_663e5c;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    
    return slot;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneInternalMonologueVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief  |  | To document
 * 
 */
void unk_9a63c(void)
{
    UpdateAudio();
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneFederationMonologue(u8 arg0)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (MONOLOGUE_DATA.stage)
    {
        case 0:
            MONOLOGUE_DATA.stage = 1;
            CutsceneFederationMonologueInit(arg0);
            break;
        
        case 1:
            CutsceneMonologueFadeIn();
            if (gWrittenToBldy == 0)
                MONOLOGUE_DATA.stage++;
            break;
        
        case 2:
            if (CutsceneFederationMonologueProcess())
            {
                MONOLOGUE_DATA.stage = 3;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;
        
        case 3:
            CutsceneMonologueFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                finished = TRUE;
            break;
    }
    
    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneFederationMonologueInit(u8 arg0)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9a99c);
    
    WRITE_16(REG_DISPCNT, 0);
    
    LZ77UncompVram(sMonologueTilemap_65fb5c, VRAM_OBJ + 0x7C00);
    
    DMA3_COPY_32(sMonologuePal_6638A0, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompVram(sMonologueGfx_6724c0, VRAM_BASE);
    LZ77UncompVram(sMonologueTilemap_674ad8, VRAM_BASE + 0xD000);
    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sMonologuePal_674958, PALRAM_BASE, 12 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sIntroPal_663820, PALRAM_BASE + 12 * PAL_ROW_SIZE, 4 * PAL_ROW_SIZE / sizeof(u32));
    
    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
    
    gWrittenToBldy--;
    
    CutsceneFederationMonologueSetupOam(1, 12, 16);
    
    gNonGameplayRam.monologue.unk_A = gCurrentCutscene - 1;
    gNonGameplayRam.monologue.pText = sMonologueTextPointers[gLanguage][gNonGameplayRam.monologue.unk_A];
    
    CutsceneMonologueDrawAllOam();
    
    CallbackSetVBlank(CutsceneFederationMonologueVblank);
}

/**
 * @brief  |  | To document
 * 
 */
boolu32 CutsceneFederationMonologueProcess(void)
{
    boolu32 finished;

    finished = CutsceneMonologueProcessSpecialTextCharacters();
    
    switch (MONOLOGUE_DATA.unk_17)
    {
        case 0:
            MONOLOGUE_DATA.unk_17 = 100;
            break;
        
        case 1:
            MONOLOGUE_DATA.unk_17 = 100;
            CutsceneMonologueProcessText();
            break;
    }
    
    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();
    
    return finished;
}

/**
 * @brief  |  | To document
 * 
 */
u8 CutsceneFederationMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);
    
    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;
    
    if (type == 1)
    {
        MONOLOGUE_DATA.oam[slot].priority = 0;
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sOam_663e5c;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    
    return slot;
}

/**
 * @brief  |  | To document
 * 
 */
void CutsceneFederationMonologueVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief  |  | To document
 * 
 */
void unk_9a99c(void)
{
    UpdateAudio();
}

