#include "cutscenes/monologue.h"

#include "globals.h"
#include "new_file_intro.h"

#include "data/cutscene_data.h"

void CutsceneMonologueProcessCursor(struct MonologueOam* pOam);
void unk_9d09c(struct MonologueOam* pOam);

/**
 * @brief 9994c | 78 | Main handler for a cutscene
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
 * @brief 999c4 | 120 | Setup for a cutscene
 * 
 */
void CutsceneInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(CutsceneInitVBlank);

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

    CallbackSetVBlank(CutsceneVBlank);
}

/**
 * @brief 99ae4 | 14 | V-blank for a cutscene
 * 
 */
void CutsceneVBlank(void)
{
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 99af8 | c | V-blank for the cutscene setup
 * 
 */
void CutsceneInitVBlank(void)
{
    UpdateAudio();
}

/**
 * @brief 99b04 | a8 | Processes a cutscene
 * 
 */
boolu32 CutsceneProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (gCurrentCutscene - 1)
    {
        case CUTSCENE_MONOLOGUE_INTRO - 1:
        case CUTSCENE_MONOLOGUE_END - 1:
            if (CutsceneInternalMonologue(0))
                finished = TRUE;
            break;

        case CUTSCENE_ELEVATOR_MONOLOGUE_REMIND - 1:
            if (CutsceneElevatorMonologue(FALSE))
                finished = TRUE;
            break;
    
        case CUTSCENE_ELEVATOR_MONOLOGUE_TRUST - 1:
            if (CutsceneElevatorMonologue(FALSE))
                finished = TRUE;
            break;
    
        case CUTSCENE_ELEVATOR_MONOLOGUE_SA_X - 1:
            if (CutsceneElevatorMonologue(FALSE))
                finished = TRUE;
            break;
    
        case CUTSCENE_ELEVATOR_MONOLOGUE_ANIMALS - 1:
            if (CutsceneElevatorMonologue(TRUE))
                finished = TRUE;
            break;
    
        case CUTSCENE_ELEVATOR_MONOLOGUE_INCIDENT - 1:
            if (CutsceneElevatorMonologue(FALSE))
                finished = TRUE;
            break;
    
        case CUTSCENE_MONOLOGUE_FEDERATION - 1:
            if (CutsceneFederationMonologue(0))
                finished = TRUE;
            break;
    
        case CUTSCENE_SECRET_CONVERSATION - 1:
            if (CutsceneSecretConversation())
                finished = TRUE;
            break;
    
        case CUTSCENE_RESTRICTED_LAB_DETACHING - 1:
        case CUTSCENE_RESTRICTED_LAB_DETACHING_DYING - 1:
            if (CutsceneRestrictedLabDetaching())
                finished = TRUE;
            break;
    
        case CUTSCENE_BSL_EXPLODING - 1:
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
 * @brief 99bac | 8c | Processes an elevator monologue cutscene
 * 
 */
boolu32 CutsceneElevatorMonologue(boolu8 movingDown)
{
    boolu32 finished;

    finished = FALSE;

    switch (MONOLOGUE_DATA.stage)
    {
        case 0:
            MONOLOGUE_DATA.stage = 1;
            CutsceneElevatorMonologueInit(movingDown);
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
 * @brief 99c38 | 22c | Setup for an elevator monologue cutscene
 * 
 */
void CutsceneElevatorMonologueInit(boolu8 movingDown)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(CutsceneElevatorMonologueInitVBlank);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram(sMonologueObjGfxPointers[gCurrentCutscene - 1], VRAM_OBJ + 0x2000);
    LZ77UncompVram(sMonologueTextCursorGfx, VRAM_OBJ + 0x7C00);

    DMA3_COPY_32(sMonologueTextCursorPal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sMonologueObjPalPointers[gCurrentCutscene - 1], PALRAM_OBJ, 6 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sMonologueBgGfxPointers[gCurrentCutscene - 1], VRAM_BASE);
    LZ77UncompVram(sMonologueTilemapPointers[gCurrentCutscene - 1], VRAM_BASE + 0xD000);
    LZ77UncompWram(sCutsceneTextTilemap, EWRAM_BASE);
    LZ77UncompVram(sMonologueElevatorLightBeamTilemap, VRAM_BASE + 0xD800);

    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sMonologueBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sMonologueBgPalPointers[gCurrentCutscene - 1], PALRAM_BASE, 11 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 27, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);

    gWrittenToBldy--;

    CutsceneElevatorMonologueSetupOam(ELEVATOR_MONOLOGUE_OAM_TYPE_CURSOR, 12, 16);
    CutsceneElevatorMonologueSetupOam(ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS, SCREEN_X_MIDDLE, 120);
    CutsceneElevatorMonologueSetupOam(ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS_OBJ_WINDOW, SCREEN_X_MIDDLE, 120);

    if (!movingDown)
        CutsceneElevatorMonologueSetupOam(ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_UP, SCREEN_X_MIDDLE, 104);
    else
        CutsceneElevatorMonologueSetupOam(ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_DOWN, SCREEN_X_MIDDLE, 104);

    MONOLOGUE_DATA.monologueId = gCurrentCutscene - 1;
    MONOLOGUE_DATA.pText = sMonologueTextPointers[gLanguage][MONOLOGUE_DATA.monologueId];

    CutsceneMonologueDrawAllOam();

    CallbackSetVBlank(CutsceneElevatorMonologueVBlank);
}

/**
 * @brief 99e64 | 3c | Processes an elevator monologue cutscene
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
 * @brief 99ea0 | 1e8 | Spawns a new OAM for an elevator monologue cutscene
 * 
 */
u8 CutsceneElevatorMonologueSetupOam(ElevatorMonologueOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == ELEVATOR_MONOLOGUE_OAM_TYPE_NONE)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);

    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;

    if (type == ELEVATOR_MONOLOGUE_OAM_TYPE_CURSOR)
    {
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueCursorOam;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    else if (type == ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][0];
        MONOLOGUE_DATA.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS_OBJ_WINDOW)
    {
        MONOLOGUE_DATA.oam[slot].objMode = OAM_OBJ_MODE_WINDOW;
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][0];
        MONOLOGUE_DATA.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_UP)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][1];
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneProcessElevatorScrollingUp;
    }
    else if (type == ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_DOWN)
    {
        MONOLOGUE_DATA.oam[slot].priority = 3;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueOamPointers[gCurrentCutscene - 1][1];
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneProcessElevatorScrollingDown;
    }
    
    return slot;
}

/**
 * @brief 9a088 | 120 | Processes the scrolling in an elevator monologue (going up)
 * 
 */
void CutsceneProcessElevatorScrollingUp(struct MonologueOam* pOam)
{
    pOam->yPosition += 2;
    WRITE_16(REG_BG2VOFS, --MONOLOGUE_DATA.unk_12);

    if (pOam->stage == 0)
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
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        if (gWrittenToBldalpha_Eva == 10)
        {
            pOam->stage = 2;
            pOam->timer = 0;
        }
        else
        {
            if (pOam->timer > 3)
            {
                pOam->timer = 0;
                gWrittenToBldalpha_Eva++;
            }
            else
            {
                pOam->timer++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 -= 3);
    }
    else
    {
        if (gWrittenToBldalpha_Eva == 4)
        {
            pOam->stage = 1;
            pOam->timer = 0;
        }
        else
        {
            if (pOam->timer > 3)
            {
                pOam->timer = 0;
                gWrittenToBldalpha_Eva--;
            }
            else
            {
                pOam->timer++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 -= 3);
    }
}

/**
 * @brief 9a1a8 | 120 | Processes the scrolling in an elevator monologue (going down)
 * 
 */
void CutsceneProcessElevatorScrollingDown(struct MonologueOam* pOam)
{
    pOam->yPosition -= 2;
    WRITE_16(REG_BG2VOFS, ++MONOLOGUE_DATA.unk_12);

    if (pOam->stage == 0)
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
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        if (gWrittenToBldalpha_Eva == 10)
        {
            pOam->stage = 2;
            pOam->timer = 0;
        }
        else
        {
            if (pOam->timer > 3)
            {
                pOam->timer = 0;
                gWrittenToBldalpha_Eva++;
            }
            else
            {
                pOam->timer++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 += 3);
    }
    else
    {
        if (gWrittenToBldalpha_Eva == 4)
        {
            pOam->stage = 1;
            pOam->timer = 0;
        }
        else
        {
            if (pOam->timer > 3)
            {
                pOam->timer = 0;
                gWrittenToBldalpha_Eva--;
            }
            else
            {
                pOam->timer++;
            }
        }

        WRITE_16(REG_BG1VOFS, MONOLOGUE_DATA.unk_14 += 3);
    }
}
 
/**
 * @brief 9a2c8 | 54 | V-blank for an elevator monologue
 * 
 */
void CutsceneElevatorMonologueVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9a31c | c | V-blank for the elevator monologue setup
 * 
 */
void CutsceneElevatorMonologueInitVBlank(void)
{
    UpdateAudio();
}

/**
 * @brief 9a328 | 84 | Handler for an internal monologue
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
 * @brief 9a3ac | 13c | Setup for an internal monologue cutscene
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
    
    LZ77UncompVram(sMonologueTextCursorGfx, VRAM_OBJ + 0x7C00);
    
    DMA3_COPY_32(sMonologueTextCursorPal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompWram(sCutsceneTextTilemap, EWRAM_BASE);
    
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sMonologueBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_OBJ);
    
    gWrittenToBldy--;

    CutsceneInternalMonologueSetupOam(INTERNAL_MONOLOGUE_OAM_TYPE_CURSOR, 12, 16);
    
    MONOLOGUE_DATA.monologueId = gCurrentCutscene - 1;
    MONOLOGUE_DATA.pText = sMonologueTextPointers[gLanguage][MONOLOGUE_DATA.monologueId];
    
    CutsceneMonologueDrawAllOam();
    
    CallbackSetVBlank(CutsceneInternalMonologueVBlank);
}

/**
 * @brief 9a4e8 | 3c | Processes an internal monologue cutscene
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
 * @brief 9a524 | e0 | Spawns an OAM for an internal monologue cutscene
 * 
 */
u8 CutsceneInternalMonologueSetupOam(InternalMonologueOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == INTERNAL_MONOLOGUE_OAM_TYPE_NONE)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);
    
    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;
    
    if (type == INTERNAL_MONOLOGUE_OAM_TYPE_CURSOR)
    {
        MONOLOGUE_DATA.oam[slot].priority = 2;
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueCursorOam;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    
    return slot;
}

/**
 * @brief 9a604 | 38 | V-blank for an internal monologue cutscene
 * 
 */
void CutsceneInternalMonologueVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9a63c | c | V-blank for an internal monologue setup
 * 
 */
void unk_9a63c(void)
{
    UpdateAudio();
}

/**
 * @brief 9a648 | 84 | Handler for the federation monologue cutscene
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
 * @brief 9a6cc | 17c | Setup for the federation monologue cutscene
 * 
 */
void CutsceneFederationMonologueInit(u8 arg0)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(CutsceneFederationMonologueInitVBlank);
    
    WRITE_16(REG_DISPCNT, 0);
    
    LZ77UncompVram(sMonologueTextCursorGfx, VRAM_OBJ + 0x7C00);
    
    DMA3_COPY_32(sMonologueTextCursorPal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    
    LZ77UncompVram(sFederationMonologueBgGfx, VRAM_BASE);
    LZ77UncompVram(sFederationMonologueBgTilemap, VRAM_BASE + 0xD000);
    LZ77UncompWram(sCutsceneTextTilemap, EWRAM_BASE);
    
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / sizeof(u32));
    DMA3_COPY_32(sFederationMonologueBgPal, PALRAM_BASE, 12 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sCutsceneTextPal, PALRAM_BASE + 12 * PAL_ROW_SIZE, 4 * PAL_ROW_SIZE / sizeof(u32));
    
    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0VOFS, 4);
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
    
    gWrittenToBldy--;
    
    CutsceneFederationMonologueSetupOam(FEDERATION_MONOLOGUE_OAM_TYPE_CURSOR, 12, 16);
    
    MONOLOGUE_DATA.monologueId = gCurrentCutscene - 1;
    MONOLOGUE_DATA.pText = sMonologueTextPointers[gLanguage][MONOLOGUE_DATA.monologueId];
    
    CutsceneMonologueDrawAllOam();
    
    CallbackSetVBlank(CutsceneFederationMonologueVBlank);
}

/**
 * @brief 9a848 | 3c | Processes the federation monologue cutscene
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
 * @brief 9a884 | e0 | Spawns an OAM for the federation monologue cutscene
 * 
 */
u8 CutsceneFederationMonologueSetupOam(FederationMonologueOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(MONOLOGUE_DATA.oam); slot++)
    {
        if (MONOLOGUE_DATA.oam[slot].type == FEDERATION_MONOLOGUE_OAM_TYPE_NONE)
            break;
    }

    if (slot >= ARRAY_SIZE(MONOLOGUE_DATA.oam))
        return ARRAY_SIZE(MONOLOGUE_DATA.oam);
    
    CutsceneMonologueResetOam(slot);
    
    MONOLOGUE_DATA.oam[slot].xPosition = xPosition;
    MONOLOGUE_DATA.oam[slot].yPosition = yPosition;
    MONOLOGUE_DATA.oam[slot].type = type;
    MONOLOGUE_DATA.oam[slot].isDrawn = TRUE;
    
    if (type == FEDERATION_MONOLOGUE_OAM_TYPE_CURSOR)
    {
        MONOLOGUE_DATA.oam[slot].priority = 0;
        MONOLOGUE_DATA.oam[slot].palette = 15;
        MONOLOGUE_DATA.oam[slot].tile = 0x3E0;
        MONOLOGUE_DATA.oam[slot].pOam = sMonologueCursorOam;
        MONOLOGUE_DATA.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    
    return slot;
}

/**
 * @brief 9a964 | 38 | V-blank for the federation monologue cutscene
 * 
 */
void CutsceneFederationMonologueVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    unk_9cc4c();
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9a99c | c | V-blank for the federation monologue setup
 * 
 */
void CutsceneFederationMonologueInitVBlank(void)
{
    UpdateAudio();
}

