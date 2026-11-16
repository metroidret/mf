#include "globals.h"

#include "constants/game_state.h"

#include "data/menus/game_over_data.h"

#include "menus/game_over.h"

#include "structs/game_over.h"

static const struct FrameData* sData_79E868[3] = {
    (const struct FrameData*)0x873c274,
    (const struct FrameData*)0x873c29c,
    (const struct FrameData*)0x873c29c
};

static const u32* sData_79E874[LANGUAGE_COUNT] = {
    (u32*)0x8739d58,
    (u32*)0x8739d58,
    (u32*)0x8739d58,
    (u32*)0x873a430,
    (u32*)0x873ab28,
    (u32*)0x873b308,
    (u32*)0x873baac
};

static u8 sBlob_79e890_79eca0[] = INCBIN_U8("data/Blob_79e890_79eca0.bin");

 /**
 * @brief 9deb4 | a4 | Main handler for the game over menu
 * 
 */
boolu32 GameOverHandler(void)
{
    u32 exitCode;

    exitCode = 0;
    
    switch (gSubGameMode1)
    {
        case 0:
            GameOverInit();
            gSubGameMode1 = 1;
            break;
            
        case 1:
            GameOverDrawAllOam();
    
            if (gWrittenToBldy != 0)
            {
                gWrittenToBldy--;
            }
            else
            {
                PlayMusic(3, 0);
                gSubGameMode1++;
            }
            break;
            
        case 2:
            if (GameOverAfterOptionDelay())
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                gSubGameMode1++;
            }
            break;
            
        case 3:
            GameOverDrawAllOam();
            
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                if (gNonGameplayRam.size[3] == 1)
                    exitCode = 1;
                else if (gNonGameplayRam.size[3] == 2)
                    exitCode = 2;
    
                gSubGameMode1 = 0;
            }
            break;
    }
    
    return exitCode;
}

 /**
 * @brief 9df58 | 1cc | Setup for the game over menu
 * 
 */
void GameOverInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_9e58c);
    
    WRITE_16(REG_DISPCNT, 0);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
     
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    DMA3_COPY_32(VRAM_OBJ, EWRAM_BASE + 0x1C000, 0x8000 / sizeof(u32));
     
    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOam();

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

    LZ77UncompVram(sGameOverObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sGameOverObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sGameOverBgGfx, VRAM_BASE);

    if (gLanguage > LANGUAGE_HIRAGANA)
        LZ77UncompVram(sData_79E874[gLanguage], VRAM_BASE);

    LZ77UncompVram(sGameOverBgTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sGameOverTextTilemap, VRAM_BASE + 0xF000);

    DMA3_COPY_32(sGameOverBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    GameOverSetupOam(1, 43, 111);
    GameOverDrawAllOam();

    WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(GameOverVblank);
}

 /**
 * @brief 9e124 | 34 | Processes the delay after choosing a game over menu option
 * 
 */
boolu32 GameOverAfterOptionDelay(void)
{
    boolu32 finished;

    finished = FALSE;
    
    GameOverProcessOam();
    GameOverDrawAllOam();
    
    if (GAME_OVER_DATA.stage == 1)
    {
        APPLY_DELTA_TIME_INC(GAME_OVER_DATA.timer);

        if (GAME_OVER_DATA.timer == CONVERT_SECONDS(.5f))
        {
            GAME_OVER_DATA.timer = 0;
            finished = TRUE;
        }
    }
    
    return finished;
}

 /**
 * @brief 9e158 | ac | Spawns a new OAM for the game over menu
 * 
 */
u8 GameOverSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(GAME_OVER_DATA.oam); slot++)
    {
        if (GAME_OVER_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(GAME_OVER_DATA.oam))
        return ARRAY_SIZE(GAME_OVER_DATA.oam);

    GameOverResetOam(slot);

    GAME_OVER_DATA.oam[slot].xPosition = xPosition;
    GAME_OVER_DATA.oam[slot].yPosition = yPosition;
    GAME_OVER_DATA.oam[slot].type = type;
    GAME_OVER_DATA.oam[slot].isDrawn = TRUE;

    if (type == 1)
    {
        GAME_OVER_DATA.oam[slot].priority = 3;
        GAME_OVER_DATA.oam[slot].pOam = sData_79E868[0];
        GAME_OVER_DATA.oam[slot].pFunction = GameOverProcessCursor;
    }
    else if (type == 2)
    {
        GAME_OVER_DATA.oam[slot].priority = 3;
        GAME_OVER_DATA.oam[slot].pOam = sOam_73c274;
        GAME_OVER_DATA.oam[slot].pFunction = unk_9e2cc;
    }
    
    return slot;
}

 /**
 * @brief 9e204 | c8 | Processes the game over menu cursor
 * 
 */
void GameOverProcessCursor(struct GameOverOam* pOam)
{
    if (pOam->unk_D == 0)
    {
        if (gChangedInput & KEY_UP)
        {
            if (pOam->yPosition != 111)
            {
                pOam->yPosition = 111;
                SoundPlay(0x1F9);
            }
        }
        else if (gChangedInput & KEY_DOWN && pOam->yPosition != 136)
        {
            pOam->yPosition = 136;
            SoundPlay(0x1F9);
        }

        if (gChangedInput & (KEY_A | KEY_START))
        {
            if (pOam->yPosition == 111)
            {
                SoundPlay(0x1FE);
                FadeMusic(10);
                pOam->pOam = sData_79E868[1];
                GAME_OVER_DATA.unk_3 = 1;
            }
            else if (pOam->yPosition == 136)
            {
                SoundPlay(0x1FE);
                FadeMusic(10);
                pOam->pOam = sData_79E868[2];
                GAME_OVER_DATA.unk_3 = 2;
            }
            
            GAME_OVER_DATA.stage = 1;
            pOam->currentAnimationFrame = 0;
            pOam->timer = 0;
            pOam->unk_D = 1;
        }
    }
}

 /**
 * @brief 9e2cc | 28 | To document
 * 
 */
void unk_9e2cc(struct GameOverOam* pOam)
{
    s16 x;
    s16 y;

    GameOverGetPositionOfOamByType(1, &x, &y);
    pOam->xPosition = x;
    pOam->yPosition = y;
}

 /**
 * @brief 9e2f4 | 28 | Partially resets a game over OAM slot
 * 
 */
void GameOverResetOam(u8 slot)
{
    GAME_OVER_DATA.oam[slot].currentAnimationFrame = 0;
    GAME_OVER_DATA.oam[slot].timer = 0;
    GAME_OVER_DATA.oam[slot].unk_C = 0;
    GAME_OVER_DATA.oam[slot].unk_D = 0;
    GAME_OVER_DATA.oam[slot].objMode = 0;
    GAME_OVER_DATA.oam[slot].priority = 0;
    GAME_OVER_DATA.oam[slot].xFlip = FALSE;
    GAME_OVER_DATA.oam[slot].palette = 0;
    GAME_OVER_DATA.oam[slot].tile = 0;
}

 /**
 * @brief 9e31c | 38 | Calls the handler functions of active game over menu OAMs
 * 
 */
void GameOverProcessOam(void)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(GAME_OVER_DATA.oam); slot++)
    {
        if (GAME_OVER_DATA.oam[slot].type != 0)
            GAME_OVER_DATA.oam[slot].pFunction(&GAME_OVER_DATA.oam[slot]);
    }
}

 /**
 * @brief 9e354 | 40 | Calls the draw function on all game over menu OAMs with a set draw flag
 * 
 */
void GameOverDrawAllOam(void)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(GAME_OVER_DATA.oam); slot++)
    {
        if (GAME_OVER_DATA.oam[slot].isDrawn)
            GameOverDrawOam(&GAME_OVER_DATA.oam[slot]);
    }

    ResetFreeOam();
    gNextOamSlot = 0;
}

 /**
 * @brief 9e394 | 188 | Draws a game over menu OAM
 * 
 */
void GameOverDrawOam(struct GameOverOam* pOam)
{
    u16* dst;
    const u16* src;
    const struct FrameData* frame;
    u16 partsCount;
    s32 i;
    u32 slot;
    u16 part1;
    u16 part2;
    u16 x;
    u16 y;
    u32 tmp;

    dst = (u16*)&gOamData[gNextOamSlot];
    frame = &pOam->pOam[pOam->currentAnimationFrame];
    if (frame->timer == pOam->timer)
    {
        pOam->currentAnimationFrame++;
        pOam->timer = 0;
        frame++;
    }

    if (frame->timer == 0)
    {
        frame -= pOam->currentAnimationFrame;
        pOam->currentAnimationFrame = 0;
    }

    src = frame->pFrame;
    partsCount = *src++;

    for (i = 0; i < partsCount; i++)
    {
        part1 = *src++;
        part2 = *src++;

        *dst++ = part1;
        *dst++ = part2;
        *dst++ = *src++;
        
        slot = gNextOamSlot + i;

        if (pOam->xFlip == TRUE)
        {
            gOamData[slot].split.xFlip ^= TRUE;
            tmp = sData_734220[gOamData[slot].split.size + (gOamData[slot].split.shape << 2)] * 8 + part2;
            x = MOD_AND(pOam->xPosition - tmp, 512);
            y = MOD_AND(part1 + pOam->yPosition, 256);
        }
        else
        {
            y = MOD_AND(part1 + pOam->yPosition, 256);
            x = MOD_AND(part2 + pOam->xPosition, 512);
        }

        gOamData[slot].split.y = y;
        gOamData[slot].split.x = MOD_AND(x, 512);
        gOamData[slot].split.priority = pOam->priority;
        gOamData[slot].split.paletteNum += pOam->palette;
        gOamData[slot].split.tileNum += pOam->tile;
        gOamData[slot].split.objMode = pOam->objMode;

        dst++;
    }

    gNextOamSlot += partsCount;
    APPLY_DELTA_TIME_INC(pOam->timer);
}

 /**
 * @brief 9e51c | 44 | Returns X and Y position of a game over menu OAM
 * 
 */
void GameOverGetPositionOfOamByType(u8 type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(GAME_OVER_DATA.oam); slot++)
    {
        if (GAME_OVER_DATA.oam[slot].type == type)
        {
            *pXPosition = GAME_OVER_DATA.oam[slot].xPosition;
            *pYPosition = GAME_OVER_DATA.oam[slot].yPosition;

            return;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
}

 /**
 * @brief 9e560 | 2c | V-blank for the game over menu
 * 
 */
void GameOverVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

 /**
 * @brief 9e58c | c | To document
 * 
 */
void unk_9e58c(void)
{
    UpdateAudio();
}

