#include "intro.h"
#include "globals.h"
#include "new_file_intro.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/new_file_intro_data.h"
#include "data/sprite_data.h"

// V-blank callbacks
void unk_93884(void);
void unk_99940(void);
void IntroShipAlertAndDraftingVblank(void);

u8 SpecialCutsceneGetRandomNumber(void);

/**
 * @brief 9209c | 1a0 | Unused intro setup function
 * 
 */
void unk_9209c(void)
{
    u16 i;
    u16* tmp1;
    u16* tmp2;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    for (i = 0; i < 5; i++)
        LZ77UncompVram(sIntroSamusSittingBgGfxPointers[i], VRAM_BASE + 0x8000 + i * 0x1000);

    LZ77UncompVram(sIntroTilemap_658be0, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroPal_6591e4, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg2XPosition = 8;
    gBg2YPosition = 8;
    gBg3XPosition = 8;
    gBg3YPosition = 8;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 29, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    // Doesn't match
    //gWrittenToBldalpha_Eva = 0;
    //gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    tmp1 = &gWrittenToBldalpha_Eva;
    tmp2 = &gWrittenToBldalpha_Evb;
    *tmp1 = 0;
    *tmp2 = BLDALPHA_MAX_VALUE;

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    gNonGameplayRam.intro.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_OBJ);

    CallbackSetVBlank(unk_93884);
}

/**
 * @brief 9223c | 294 | Processes the title intro Samus in ship cutscene
 * 
 */
boolu32 IntroSamusInShipProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer <= 5 * DELTA_TIME)
            {
                LZ77UncompVram(sIntroSamusSittingBgGfxPointers[INTRO_DATA.timer - 1], VRAM_BASE + 0x8000 + (INTRO_DATA.timer - 1) * 0x1000);
            }
            else if (INTRO_DATA.timer == 6 * DELTA_TIME)
            {
                LZ77UncompVram(sIntroTilemap_658be0, VRAM_BASE + 0xE800);
                DMA3_COPY_32(sIntroPal_6591e4, PALRAM_BASE, 8 * PAL_ROW_SIZE / sizeof(u32));
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
                WRITE_16(REG_BG1HOFS, 0);
                WRITE_16(REG_BG1VOFS, 0);
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 29, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            }
            else if (INTRO_DATA.timer == 7 * DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL 
                         | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Evb)
                {
                    if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE)
                    {
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EC].trackGroupNumber].pTrack, 10);
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1ED].trackGroupNumber].pTrack, 10);
                    }

                    gWrittenToBldalpha_Evb -= 2;
                }
                else
                {
                    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
                    INTRO_DATA.subStage = 2;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                {
                    if (!gWrittenToBldalpha_Eva)
                        PlayFadingSound(SOUND_1EB, 0);

                    gWrittenToBldalpha_Eva++;
                }
                else
                {
                    INTRO_DATA.subStage = 3;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            if (INTRO_DATA.timer == TWO_THIRD_SECOND)
			{
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
                gWrittenToBldy = 0;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 4:
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 5;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 5:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.subStage = 6;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 6:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy += 2;
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

/**
 * @brief 924d0 | 270 | Setup for the title intro ship collision alert cutscene
 * 
 */
void IntroShipAlertInit(void)
{
    u16 i;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    
    for (i = 0; i <= 5; i++)
        LZ77UncompVram(sTitleIntroCollisionWarningObjGfxPointers[i], VRAM_OBJ + i * 0x1000);

    DMA3_COPY_32(sIntroPal_65c268, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    for (i = 0; i <= 4; i++)
        LZ77UncompVram(sTitleIntroCollisionWarningBgGfxPointers[i], VRAM_BASE + i * 0x1000);
    
    LZ77UncompVram(sIntroTilemap_6593e4, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroPal_6599a4, PALRAM_BASE, 8 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    
    IntroSetupOam(19, 96, 128, 0);
    IntroSetupOam(20, 128, 96, 0);
    IntroSetupOam(21, 128, 128, 0);
    IntroSetupOam(22, 200, 38, 0);
    IntroSetupOam(23, 210, 88, 0);
    
    IntroSetupBigNumberOam(24, 210, 88, 210);
    IntroSetupBigNumberOam(25, 67, 151, 200);
    IntroSetupBigNumberOam(26, 44, 152, 200);
    IntroSetupBigNumberOam(27, 37, 152, 200);
    IntroSetupBigNumberOam(28, 69, 125, 200);
    IntroSetupBigNumberOam(29, 62, 125, 200);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_OBJ);
    
    CallbackSetVBlank(IntroShipAlertAndDraftingVblank);
}

/**
 * @brief 92740 | f0 | Processes the title intro ship collision alert cutscene
 * 
 */
boolu32 IntroShipAlertProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            IntroShipAlertInit();
            INTRO_DATA.subStage = 1;
            INTRO_DATA.timer = 0;
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 1:
            if (gWrittenToBldy)
            {
                gWrittenToBldy -= 2;
            }
            else
            {
                INTRO_DATA.subStage = 2;
                INTRO_DATA.timer = 0;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(6 + 2.f / 3) - DELTA_TIME)
            {
                gWrittenToBldy = 0;
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(6 + 2.f / 3))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.subStage = 3;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (!gWrittenToBldy)
                    ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EB].trackGroupNumber].pTrack, 10);

                gWrittenToBldy += 2;
            }
            else
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.timer = 0;
                finished = TRUE;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

/**
 * @brief 92830 | 1d0 | Setup for the title intro Samus drifting out cutscene
 * 
 */
void IntroSamusDriftingOutInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    
    LZ77UncompVram(sTitleIntroBslObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sPal_612f48, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVram(sTitleScreenSpaceBackgroundTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sPal_609020, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    
    IntroSetupOam(10, 145, 140, FALSE);
    IntroSetupOam(11, 140, 80, FALSE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(IntroShipAlertAndDraftingVblank);
}

/**
 * @brief 92a00 | 1f4 | Processes the title intro Samus drifting out cutscene
 * 
 */
boolu32 IntroSamusDriftingOutProcess(void)
{
    boolu32 finished;
    s16 x;
    s16 y;

    finished = FALSE;
    
    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
	    case 0:
	        IntroSamusDriftingOutInit();
	        INTRO_DATA.subStage = 1;
	        INTRO_DATA.timer = 0;
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 1:
	        if (gWrittenToBldy)
	        {
	            if (gWrittenToBldy == BLDY_MAX_VALUE)
	            {
	                PlayFadingSound(0x1EC, 0);
	                PlayFadingSound(0x1ED, 0);
	            }
	
	            gWrittenToBldy -= 2;
	        }
	        else
	        {
	            INTRO_DATA.subStage = 2;
	            INTRO_DATA.timer = 0;
	        }
	
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            IntroSetupOam(16, x, y, TRUE);
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 2:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(2 + 1.f / 3))
	            PlayMusic(0x49, 15);
	
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            IntroSetupOam(16, x, y, TRUE);
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 3:
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            IntroSetupOam(16, x, y, TRUE);
	        }
	
	        if (INTRO_DATA.timer == DELTA_TIME)
	        {
	            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
	            INTRO_DATA.timer = 0;
	            INTRO_DATA.subStage = 4;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;

	    case 4:
	        if (gWrittenToBldy < BLDY_MAX_VALUE)
	        {
	            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 20))
	            {
	                INTRO_DATA.timer = 0;
	
	                if (!gWrittenToBldy)
	                    ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[0x1EC].trackGroupNumber].pTrack, 30);
	
	                gWrittenToBldy++;
	            }
	        }
	        else if (INTRO_DATA.timer == CONVERT_SECONDS(2.f / 15))
	        {
	            INTRO_DATA.timer = 0;
	            finished = TRUE;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
    }
    
    IntroProcessText();
    
    return finished;
}

/**
 * @brief 92bf4 | 118 | Main handler for the title intro Samus crashing cutscenes
 * 
 */
boolu32 IntroSamusShipCrashing(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (INTRO_DATA.stage)
    {
        case 0:
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();

            INTRO_DATA.stage = 2;
            break;

        case 1:
            if (gWrittenToBldy)
                gWrittenToBldy--;
            else
                INTRO_DATA.stage = 2;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 2:
            if (IntroSamusInShipProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;
            
        case 3:
            if (IntroShipAlertProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 4;
            }
            break;
            
        case 4:
            if (IntroSamusDriftingOutProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 5;
            }
            break;
    
        case 5:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = 1;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

/**
 * @brief 92d0c | 148 | Unused, modified variant of NewFileIntroProcessSamusFainting
 * 
 */
void unk_92d0c(struct SpecialCutsceneOam* pOam)
{
    u8 rng1;
    u8 rng2;

    rng1 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit, 32)] / 4;
    rng2 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit + 7, 32)] / 4;

    if (!pOam->unk_8)
    {
        pOam->timer++;
        if (pOam->timer)
        {
            pOam->timer = 0;
            if (pOam->yPosition < 16)
            {
                pOam->yPosition += rng2;
                if (pOam->yPosition > 15)
                {
                    pOam->yPosition = 16;
                    pOam->unk_8 = 1;
                }
            }
        }
    }
    else
    {
        pOam->timer++;
        if (pOam->timer)
        {
            pOam->timer = 0;
            if (pOam->yPosition > 0)
            {
                pOam->yPosition -= rng2;
                if (pOam->yPosition <= 0)
                {
                    pOam->yPosition = 0;
                    pOam->unk_8 = 0;
                }
            }
        }
    }

    if (!pOam->unk_4)
    {
        pOam->unk_A++;
        if (pOam->unk_A)
        {
            pOam->unk_A = 0;
            if (pOam->xPosition < 16)
            {
                pOam->xPosition += rng1;
                if (pOam->xPosition > 15)
                {
                    pOam->xPosition = 16;
                    pOam->unk_4 = 1;
                }
            }
        }
    }
    else
    {
        pOam->unk_A++;
        if (pOam->unk_A)
        {
            pOam->unk_A = 0;
            if (pOam->xPosition > 0)
            {
                pOam->xPosition -= rng1;
                if (pOam->xPosition <= 0)
                {
                    pOam->xPosition = 0;
                    pOam->unk_4 = 0;
                }
            }
        }
    }

    gBg2XPosition = pOam->xPosition;
    gBg2YPosition = pOam->yPosition;

    if (INTRO_DATA.subStage == 4)
    {
        pOam->rotation++;
        if (pOam->rotation == Q_8_8(1.f / 128))
        {
            pOam->rotation = 0;
            
            if (gWrittenToBldalpha_Eva)
                gWrittenToBldalpha_Eva--;

            if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                gWrittenToBldalpha_Evb++;
        }
    }
}

/**
 * @brief 92e54 | 26c | Processes Samus' ship drifting into asteroids
 * 
 */
void IntroProcessDriftingShip(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->yPosition = pOam->spawnY + (SIN(pOam->timer) >> 7);

        if (pOam->timer > CONVERT_SECONDS(13.f / 15))
        {
            pOam->unk_4++;
            if (pOam->unk_4 == 12)
            {
                pOam->rotation--;
                pOam->xPosition--;
                pOam->unk_4 = 0;
            }

            pOam->unk_8++;
            if (pOam->unk_8 == 10)
            {
                pOam->unk_8 = 0;
                pOam->scaling--;
            }
        }

        if (pOam->timer >= CONVERT_SECONDS(2 + 2.f / 15))
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
            SoundPlay(SOUND_1F2);
        }
    }
    else if (pOam->stage == 2)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 3) + (SIN(pOam->timer) >> 7);

        pOam->unk_4++;
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 2)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }
        
        if (pOam->timer == 0)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 3);
        
        pOam->unk_4++;
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 1)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }
        
        if (pOam->timer == 0)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 4;
        }
        
        if (pOam->scaling < 3)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 4)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 1);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 2);

        pOam->unk_4++;
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 1)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }

        if (pOam->scaling < 3)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->unk_A = 0;
        pOam->scaling = Q_8_8(1);
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->affineMode = OAM_AFFINE_MODE_NORMAL;
        pOam->pOam = sOam_60ad48;
        pOam->stage = 6;
        SoundPlay_3b1c(SOUND_1F3);
        INTRO_DATA.timer = 0;
        INTRO_DATA.subStage = 3;
    }
    else if (pOam->stage == 6)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

