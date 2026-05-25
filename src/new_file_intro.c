#include "globals.h"
#include "new_file_intro.h"

#include "constants/game_state.h"

#include "data/new_file_intro_data.h"

extern void unk_99940(void); // For V-blank callback

static void NewFileIntroSamusShipFlyingInit(void);
static boolu32 NewFileIntroSamusShipFlyingProcess(void);
static boolu32 NewFileIntroSamusShipFlying(void);
static void NewFileIntroSamusFaintingInit(void);
static boolu32 NewFileIntroSamusFaintingProcess(void);
static boolu32 NewFileIntroSamusFainting(void);

static u16* sMonologueTextPointersJapanese[19];
static u16* sMonologueTextPointersEnglish[19];
static u16* sMonologueTextPointersGerman[19];
static u16* sMonologueTextPointersFrench[19];
static u16* sMonologueTextPointersItalian[19];
static u16* sMonologueTextPointersSpanish[19];

static const u32* sIntroBslObjectGfxPointers[8] = {
    sIntroBslObjectGfx0,
    sIntroBslObjectGfx1,
    sIntroBslObjectGfx2,
    sIntroBslObjectGfx3,
    sIntroBslObjectGfx4,
    sIntroBslObjectGfx5,
    sIntroBslObjectGfx6,
    sIntroBslObjectGfx7
};

// 79C41C Intro Samus sitting BG graphics pointers [5]
static const u32* sIntroSamusSittingBgGfxPointers[5] = {
    (u32*)0x0864578c,
    (u32*)0x086465ec,
    (u32*)0x08647534,
    (u32*)0x0864843c,
    (u32*)0x086492fc,
};

// 79C430 Intro Samus helmet close up BG graphics pointers [6]
static const u32* sIntroSamusHelmetCloseupBgGfxPointers[6] = {
    (u32*)0x08649f7c,
    (u32*)0x0864a8d4,
    (u32*)0x0864b614,
    (u32*)0x0864c444,
    (u32*)0x0864d0f4,
    (u32*)0x0864de24,
};

static u8 sBlob_79c448_79c5a4[] = INCBIN_U8("data/Blob_79c448_79c5a4.bin");

static u16** sMonologueTextPointers[LANGUAGE_COUNT] = {
    sMonologueTextPointersJapanese,
    sMonologueTextPointersJapanese,
    sMonologueTextPointersEnglish,
    sMonologueTextPointersGerman,
    sMonologueTextPointersFrench,
    sMonologueTextPointersItalian,
    sMonologueTextPointersSpanish
};

static u8 sBlob_79c5c0_79cdd8[] = INCBIN_U8("data/Blob_79c5c0_79cdd8.bin");

u16** sLocationTextPointers[LANGUAGE_COUNT] = {
    (u16**)0x879c680,
    (u16**)0x879c7a8,
    (u16**)0x879c8d0,
    (u16**)0x879c9f8,
    (u16**)0x879cb20,
    (u16**)0x879cc48,
    (u16**)0x879cd70
};

u16** sMessageTextPointers[LANGUAGE_COUNT] = {
    (u16**)0x879c5c0,
    (u16**)0x879c6e8,
    (u16**)0x879c810,
    (u16**)0x879c938,
    (u16**)0x879ca60,
    (u16**)0x879cb88,
    (u16**)0x879ccb0
};

static u8 sBlob_79ce10_79e6a0[] = INCBIN_U8("data/Blob_79ce10_79e6a0.bin");

static u16* sMonologueTextPointersJapanese[19] = {
	(u16*)0x871e20c,
	(u16*)0x871e4e4,
	(u16*)0x871e67e,
	(u16*)0x871e814,
	(u16*)0x871e9b6,
	(u16*)0x871eb34,
	(u16*)0x871ecac,
	(u16*)0x871efc2,
	(u16*)0x871f498,
	(u16*)0x871f52c,
	(u16*)0x871f56c,
	(u16*)0x871f5fc,
	(u16*)0x871f656,
	(u16*)0x871f71a,
	(u16*)0x871f7cc,
	(u16*)0x871f896,
	(u16*)0x871f98a,
	(u16*)0x871fa32,
	(u16*)0x871fa92
};

static u16* sMonologueTextPointersEnglish[19] = {
	(u16*)0x871fad4,
	(u16*)0x87200ee,
	(u16*)0x8720310,
	(u16*)0x8720528,
	(u16*)0x8720748,
	(u16*)0x872094a,
	(u16*)0x8720b4a,
	(u16*)0x8721116,
	(u16*)0x872192e,
	(u16*)0x8721a12,
	(u16*)0x8721ab6,
	(u16*)0x8721c28,
	(u16*)0x8721d12,
	(u16*)0x8721f20,
	(u16*)0x8722068,
	(u16*)0x8722238,
	(u16*)0x8722438,
	(u16*)0x8722550,
	(u16*)0x87225f8
};

static u16* sMonologueTextPointersGerman[19] = {
	(u16*)0x87226a0,
	(u16*)0x8723016,
	(u16*)0x8723324,
	(u16*)0x8723624,
	(u16*)0x8723958,
	(u16*)0x8723be2,
	(u16*)0x8723e44,
	(u16*)0x872475e,
	(u16*)0x87252c6,
	(u16*)0x8725412,
	(u16*)0x87254ea,
	(u16*)0x87256d8,
	(u16*)0x872581e,
	(u16*)0x8725a60,
	(u16*)0x8725b94,
	(u16*)0x8725dac,
	(u16*)0x872603c,
	(u16*)0x87261c6,
	(u16*)0x87262aa
};

static u16* sMonologueTextPointersFrench[19] = {
	(u16*)0x872638c,
	(u16*)0x8726aa6,
	(u16*)0x8726cfe,
	(u16*)0x8726f04,
	(u16*)0x8727106,
	(u16*)0x8727314,
	(u16*)0x8727522,
	(u16*)0x8727b08,
	(u16*)0x87282bc,
	(u16*)0x87283a6,
	(u16*)0x8728466,
	(u16*)0x8728608,
	(u16*)0x87286e8,
	(u16*)0x87288ba,
	(u16*)0x8728a12,
	(u16*)0x8728bfc,
	(u16*)0x8728e4a,
	(u16*)0x8728f96,
	(u16*)0x872904e
};

static u16* sMonologueTextPointersItalian[19] = {
	(u16*)0x87290fc,
	(u16*)0x8729792,
	(u16*)0x8729a6e,
	(u16*)0x8729c84,
	(u16*)0x8729f24,
	(u16*)0x872a124,
	(u16*)0x872a330,
	(u16*)0x872a8f6,
	(u16*)0x872b142,
	(u16*)0x872b254,
	(u16*)0x872b2c8,
	(u16*)0x872b446,
	(u16*)0x872b56e,
	(u16*)0x872b7a6,
	(u16*)0x872b8e6,
	(u16*)0x872bab4,
	(u16*)0x872bcc2,
	(u16*)0x872bdb8,
	(u16*)0x872be4a
};

static u16* sMonologueTextPointersSpanish[19] = {
	(u16*)0x872bef8,
	(u16*)0x872c69c,
	(u16*)0x872c8f2,
	(u16*)0x872cb02,
	(u16*)0x872cd92,
	(u16*)0x872d002,
	(u16*)0x872d212,
	(u16*)0x872d81e,
	(u16*)0x872e0b8,
	(u16*)0x872e1b6,
	(u16*)0x872e220,
	(u16*)0x872e3d2,
	(u16*)0x872e4ea,
	(u16*)0x872e70a,
	(u16*)0x872e848,
	(u16*)0x872ea20,
	(u16*)0x872ebf6,
	(u16*)0x872ed50,
	(u16*)0x872ee1c
};

static u8 sBlob_79e868_79ecc8[] = INCBIN_U8("data/Blob_79e868_79ecc8.bin");

/**
 * @brief 87610 | f8 | Handler for intro
 * 
 */
boolu32 IntroHandler(void) 
{
    boolu32 result;

    result = FALSE;
    
    if (gChangedInput & (KEY_START | KEY_A))
    {
        if (gSubGameMode1 == 3)
        {
            if (gNonGameplayRam.intro.unk_20E != 0)
                gNonGameplayRam.intro.unk_20E = 0;
        }
        else if (gSubGameMode1 != 0 && gSubGameMode1 != 3)
        {
            if (READ_16(REG_BLDCNT) & BLDCNT_ALPHA_BLENDING_EFFECT)
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
            
            gNonGameplayRam.intro.unk_20E = 0;
            gSubGameMode1 = 3;
            FadeAllSounds(20);
            FadeMusic(20);
        }
    }

    switch (gSubGameMode1)
    {
        case 0:
            NewFileIntroInit();
            gSubGameMode1 = 1;
            break;
        
        case 1:
            if (IntroSpaceView())
                gSubGameMode1 = 2;
            break;
        
        case 2:
            if (IntroSamusShipCrashing())
                gSubGameMode1 = 3;
            break;
        
        case 3:
            if (gNonGameplayRam.intro.unk_20E == 0)
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    result = TRUE;
            }
            else
                gNonGameplayRam.intro.unk_20E--;
            
            SpecialCutsceneDrawAllOam(); 
    }

    return result;
}

 /**
 * @brief 87708 | 218 | Handler for new file intro
 * 
 */
boolu32 NewFileIntroHandler(void) 
{
    boolu32 result;

    result = FALSE;

    switch (gSubGameMode1)
    {
        case 0:
            StopAllMusicAndSounds();
            NewFileIntroInit();

            if (gGameCompletion.introPlayed == TRUE)
                return TRUE;
            else 
                gSubGameMode1 = 1;
            break;

        case 1:
            gNonGameplayRam.intro.timer++;
            if (gNonGameplayRam.intro.timer >= 100)
            {
                gNonGameplayRam.intro.timer = 0;
                gSubGameMode1 = 2;
            }
            break;

        case 2:
            if (NewFileIntroSr388Preview())
                gSubGameMode1 = 3;
            break;

        case 3:
            if (NewFileIntroInSr388())
                gSubGameMode1 = 4;
            break;

        case 4:
            if (NewFileIntroSamusShipFlying())
                gSubGameMode1 = 5;
            break;

        case 5:
            if (NewFileIntroSamusFainting())
                gSubGameMode1 = 6;
            break;

        case 6:
            if (NewFileIntroSamusDrifting())
                gSubGameMode1 = 7;
            break;

        case 7:
            if (NewFileIntroSamusFound())
                gSubGameMode1 = 8;
            break;

        case 8:
            if (NewFileIntroSamusGettingCured())
                gSubGameMode1 = 9;
            break;

        case 9:
            if (NewFileIntroSamusCured())
                gSubGameMode1 = 10;
            break;

        case 10:
            if (NewFileIntroArrivingAtBsl())
                gSubGameMode1 = 11;
            break;

        case 11:
            if (NewFileIntroLandingOnBsl())
            {
                gNonGameplayRam.intro.unk_20E = 0;
                gSubGameMode1 = 12;
            }
            break;
        
        case 12:
            gNonGameplayRam.intro.unk_20E++;
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (gNonGameplayRam.intro.unk_20E == 1)
                {
                    gNonGameplayRam.intro.unk_20E = 0;
                    gWrittenToBldy++;
                }
            }
            else
            {
                if (gNonGameplayRam.intro.unk_20E == 1)
                {
                    Sram_ProcessIntroSave(0);
                }
                else if (gNonGameplayRam.intro.unk_20E == 2)
                {
                    Sram_ProcessIntroSave(1);
                } 
                else if (gNonGameplayRam.intro.unk_20E == 3)
                {
                    Sram_ProcessIntroSave(2);
                }
                else if (gNonGameplayRam.intro.unk_20E == 4)
                {
                    Sram_ProcessIntroSave(3);
                    gNonGameplayRam.intro.timer = 0;
                    gNonGameplayRam.intro.unk_20E = 0;
                    result = TRUE;
                }
            }

            SpecialCutsceneDrawAllOam();
    }

    return result;
}

 /**
 * @brief 87920 | 50 | To document
 * 
 */
boolu32 unk_87920(void) 
{
    boolu32 result;
    boolu32 done;
    
    result = FALSE;

    switch (gCurrentCutscene)
    {
        default:
            result = TRUE;
            done = FALSE;
            break;

        case 1:
            done = IntroHandler();
            break;

        case 2:
            done = NewFileIntroHandler();
            break;

        case 3:
            done = EndingHandler();
            break;

        case 4:
            done = DiedFromSr388CollisionHandler();
    }

    if (done)
    {
        StopAllMusicAndSounds();
        result = TRUE;
    }
    
    return result;
}

 /**
 * @brief 87970 | 94 | V-blank for the new file intro Samus ship flying cutscene
 * 
 */
void NewFileIntroSamusShipFlyingVblank(void) 
{
    DMA3_COPY_32(gOamData, OAM_BASE, 256);

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
 * @brief 87a04 | 264 | Setup for the new file intro Samus ship flying cutscene
 * 
 */
static void NewFileIntroSamusShipFlyingInit(void) 
{
    u16 i;
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    for (i = 0; i < 8; i++)
    {
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    }
    
    DMA3_COPY_32(sIntroSamusShipPal, PALRAM_OBJ, 5 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompWram(sIntroBslSpaceBgGfx, EWRAM_BASE + 0x10000);

    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE, (VRAM_SIZE / 3) / 4);

    LZ77UncompVram(sIntroBslTilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSpaceTilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);

    WRITE_16(PALRAM_BASE, 0);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 48;
    gBg2YPosition = -8;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
    WRITE_16(REG_BG0CNT, 28 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT);
    WRITE_16(REG_BG2CNT, BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT | 29 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_MID_PRIORITY);
    WRITE_16(REG_BG3CNT, 31 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_PRIORITY);

    NewFileIntroSetupOam(200, 250, 0, 0);
    NewFileIntroSetupOam(1, (s16)gBg2XPosition, (s16)gBg2YPosition, 0);
    NewFileIntroSetupOam(2, 160, 90, 0);
    NewFileIntroSetupOam(4, 0, 0, 1);

    for (i = 0; i < 10; i++)
    {
        NewFileIntroSetupOam(3, (u8)SpecialCutsceneGetRandomNumber(), (u8)SpecialCutsceneGetRandomNumber(), 1);
    }

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4 );

    gNonGameplayRam.intro.pText = (u16*)sCutsceneTextNone;
    WRITE_16(REG_DISPCNT, DCNT_OBJ | DCNT_BG3 | DCNT_BG2);

    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
}

 /**
 * @brief 87C68 | 188 | Processes the new file intro Samus ship flying cutscene
 * 
 */
static boolu32 NewFileIntroSamusShipFlyingProcess(void) 
{
    boolu32 result;

    result = FALSE;

    if (*gNonGameplayRam.intro.pText == 0xfc00 && gChangedInput & KEY_A && gNonGameplayRam.intro.unk_218 == 0)
        gNonGameplayRam.intro.unk_218 = 1;
    
    gNonGameplayRam.intro.timer++;

    switch (gNonGameplayRam.intro.unk_214)
    {
        case 0:
            if ((SpecialCutsceneGetRandomNumber() << 24) >= 0 && gNonGameplayRam.intro.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, (u8)SpecialCutsceneGetRandomNumber(), 1);

            if (gNonGameplayRam.intro.timer == 99)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (gNonGameplayRam.intro.timer == 100)
            {
                gNonGameplayRam.intro.timer = 0;
                gNonGameplayRam.intro.unk_212 = 0;
                gNonGameplayRam.intro.unk_E = 0;
                gNonGameplayRam.intro.unk_C = 0;
                gNonGameplayRam.intro.pText = sMonologueTextPointers[gLanguage][10];
                gNonGameplayRam.intro.unk_214 = 1;
            }
            break;
        
        case 1:
            if ((SpecialCutsceneGetRandomNumber() << 24) >= 0 && gNonGameplayRam.intro.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, (u8)SpecialCutsceneGetRandomNumber(), 1);

            gNonGameplayRam.intro.timer = 0;
            
            if (gNonGameplayRam.intro.unk_218 == 2 || gNonGameplayRam.intro.unk_218 == 4)
            {
                gNonGameplayRam.intro.unk_218 = 0;
            }
            else if (gNonGameplayRam.intro.unk_218 == 3)
            {
                gNonGameplayRam.intro.unk_218 = 0;
                gNonGameplayRam.intro.unk_214 = 2;
            }
            break;

        case 2:
            if (gNonGameplayRam.intro.timer == 30)
            {
                gNonGameplayRam.intro.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                result = TRUE;
            }
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();

    return result;
}

 /**
 * @brief 87df0 | a0 | Main handler for new file intro Samus ship flying cutscene
 * 
 */
static boolu32 NewFileIntroSamusShipFlying(void)
{
    boolu32 result;

    result = FALSE;

    switch (gNonGameplayRam.intro.stage)
    {
        case 0:
            NewFileIntroSamusShipFlyingInit();
            gNonGameplayRam.intro.stage = 1;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                gNonGameplayRam.intro.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusShipFlyingProcess())
            {
                gNonGameplayRam.intro.stage = 3;
                gNonGameplayRam.intro.timer = 0;
                gNonGameplayRam.intro.unk_214 = 0;   
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else 
            {
                gNonGameplayRam.intro.unk_213 = 0;
                gNonGameplayRam.intro.unk_214 = 0;
                gNonGameplayRam.intro.stage = 0;
                result = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
    }

    return result;
}

 /**
 * @brief 87e90 | 1d8 | Setup for the new file intro Samus fainting cutscene
 * 
 */
static void NewFileIntroSamusFaintingInit(void)
{
    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompVram(sIntroSamusSittingTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusSittingTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusSittingGfx, VRAM_BASE);

    DMA3_COPY_32(sIntroSamusSittingPal, PALRAM_BASE, 128);

    WRITE_16(PALRAM_BASE, 0);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 64);
    
    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 10;
    gBg2YPosition = 2;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
    WRITE_16(REG_BG0CNT, 28 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT);
    WRITE_16(REG_BG2CNT, 30 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_MID_PRIORITY);
    WRITE_16(REG_BG3CNT, 31 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_PRIORITY);

    NewFileIntroSetupOam(200, 250, 0, 0);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, VRAM_SIZE / 24 );

    gNonGameplayRam.intro.pText = (u16*)sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_OBJ | DCNT_BG3 | DCNT_BG2);

    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
    gWrittenToBldalpha_Eva = 12;
    gWrittenToBldalpha_Evb = 8;
}

 /**
 * @brief 88068 | 13c | Processes the new file intro Samus fainting cutscene
 * 
 */
static boolu32 NewFileIntroSamusFaintingProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if ((*gNonGameplayRam.intro.pText == 0xFC00) && (gChangedInput & KEY_A) && (gNonGameplayRam.intro.unk_218 == 0))
        gNonGameplayRam.intro.unk_218 = 1;
    
    gNonGameplayRam.intro.timer += 1;
    
    switch (gNonGameplayRam.intro.unk_214) 
    {
        case 0:
            if (gNonGameplayRam.intro.timer == 1)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_FIRST_TARGET_PIXEL);
                NewFileIntroSetupOam(10, (s16)gBg2XPosition, (s16)gBg2YPosition, 1);
            }
            else if (gNonGameplayRam.intro.timer == 59)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (gNonGameplayRam.intro.timer == 60)
            {
                gNonGameplayRam.intro.timer = 0;
                gNonGameplayRam.intro.unk_212 = 0;
                gNonGameplayRam.intro.unk_E = 0;
                gNonGameplayRam.intro.unk_C = 0;
                gNonGameplayRam.intro.pText = sMonologueTextPointers[gLanguage][11];
                gNonGameplayRam.intro.unk_214 = 1;
            }
            break;
        
        case 1:
            gNonGameplayRam.intro.timer = 0;

            if (gNonGameplayRam.intro.unk_218 == 2 || gNonGameplayRam.intro.unk_218 == 4)
            {
                gNonGameplayRam.intro.unk_218 = 0;
            }
            else if (gNonGameplayRam.intro.unk_218 == 3)
            {
                gNonGameplayRam.intro.unk_218 = 0;
                gNonGameplayRam.intro.unk_214 = 2;
                gWrittenToBldy = 16;
            }
            break;
        
        case 2:
            if (gNonGameplayRam.intro.timer == 30) 
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                gNonGameplayRam.intro.timer = 0;
                finished = TRUE;
            }
            break;
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 881a4 | 9c | Main handler for the new file intro Samus fainting cutscene
 * 
 */
static boolu32 NewFileIntroSamusFainting(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (gNonGameplayRam.intro.stage)
    {
        case 0:
            NewFileIntroSamusFaintingInit();
            gNonGameplayRam.intro.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                gNonGameplayRam.intro.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusFaintingProcess())
            {
                gNonGameplayRam.intro.stage = 3;
                gNonGameplayRam.intro.timer = 0;
                gNonGameplayRam.intro.unk_214 = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < 16)
            {
                gWrittenToBldy++;
            }
            else 
            {
                gNonGameplayRam.intro.unk_213 = 0;
                gNonGameplayRam.intro.unk_214 = 0;
                gNonGameplayRam.intro.stage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}


void NewFileIntroSamusDriftingInit(void)
{
    u16 i;

    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    
    for (i = 0; i < 8; i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(sIntroSamusShipPal, PALRAM_OBJ, 5 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);
    
    LZ77UncompWram(sIntroBslSpaceBgGfx, 0x02010000);
    
    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE, (VRAM_SIZE / 3) / 4);
    
    LZ77UncompVram(sIntroBslTilemap, 0x0600E800);
    LZ77UncompVram(sIntroSpaceTilemap, 0x0600F800);
    
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    
    WRITE_16(PALRAM_BASE, 0);
    
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, 0x0600E000);
    
    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 48;
    gBg2YPosition = -8;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BLDCNT, 0xFF);
    WRITE_16(REG_BG0CNT, 0x1C08);
    WRITE_16(REG_BG2CNT, 0x5D02);
    WRITE_16(REG_BG3CNT, 0x1F03);
    
    NewFileIntroSetupOam(200, 250, 0, 0);
    NewFileIntroSetupOam(1, (s16)gBg2XPosition, (s16)gBg2YPosition, 0);
    NewFileIntroSetupOam(20, 160, 90, 0);
    NewFileIntroSetupOam(4, 0, 0, 1);
    
    for (i = 0; i < 10; i++)
    {
        NewFileIntroSetupOam(3, (u8)SpecialCutsceneGetRandomNumber(), (u8)SpecialCutsceneGetRandomNumber(), 1);
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    gNonGameplayRam.intro.pText = (u16*)sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, 0x1C00);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}


void NewFileIntroSamusLosingConsciousnessVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, 256);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
    
    if (gNonGameplayRam.intro.unk_110 == 1)
    {
        gNonGameplayRam.intro.unk_110 = 0;
        DMA3_COPY_32(0x08598AAC, PALRAM_BASE, 32);
    }
}


void NewFileIntroSamusLosingConsciousnessInit(void) 
{
    u16 i;

    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, 0x030016a0, 720);
    
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    for (i = 0; i < 6; i++)
        LZ77UncompVram(sIntroSamusHelmetCloseupBgGfxPointers[i], VRAM_BASE + i * 0x1000);
    
    LZ77UncompVram(0x08598190, 0x0600F000);
    LZ77UncompVram(0x08598190, 0x0600F800);

    DMA3_COPY_32(0x08598818, PALRAM_BASE, 4 * PAL_ROW_SIZE / 4);
    
    WRITE_16(PALRAM_BASE, 0);
    
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, 0x0600E000);
    
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 10;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BLDCNT, 0xFF);
    
    WRITE_16(REG_BG0CNT, 0x1C08);
    WRITE_16(REG_BG2CNT, 0x1E02);
    WRITE_16(REG_BG3CNT, 0x1F03);
    
    NewFileIntroSetupOam(0xC8, 0xFA, 0, 0);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4 );
    
    gNonGameplayRam.intro.pText = (u16*)sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, 0x1C00);
    
    CallbackSetVBlank(NewFileIntroSamusLosingConsciousnessVblank);
    
    gWrittenToBldy = 0;
    gWrittenToBldalpha_Eva = 12;
    gWrittenToBldalpha_Evb = 8;
}


void NewFileIntroSamusDriftingIntoAsteroidsInit(void) 
{
    u16 i;
    void* temp1;
    u32 temp2;
    
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & 0xFFEF);
    WRITE_16(REG_IE, READ_16(REG_IE) & 0xFFFD);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam + 0x21C, 720);
    
    for (i = 0; i < 8; i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(0x08612F48, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompVram((u32 *)0x08605D08, 0x06000000);
    LZ77UncompVram((u32 *)0x08609220, 0x0600F800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, 0x0600E000);
    
    DMA3_COPY_32(0x08609020, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(0x08598A8C, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
    
    WRITE_16(PALRAM_BASE, 0);
    
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
    
    WRITE_16(REG_BG0CNT, 0x1C08);
    WRITE_16(REG_BG3CNT, 0x1F03);
    WRITE_16(REG_BLDCNT, 0xFF);

    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;

    //WRITE_16(REG_BLDALPHA, 0); // Doesn't match
    temp1 = REG_BLDALPHA;
    temp2 = 0;
    WRITE_16(temp1, temp2);
    
    NewFileIntroSetupOam(0x1E, 0x8CU, 0x8CU, 0);
    NewFileIntroSetupOam(0x1F, 0x8CU, 0x50U, 0);
    
    for (i = 0; i < 4; i++)
        NewFileIntroSetupOam(36, (u8)SpecialCutsceneGetRandomNumber(), (u8)SpecialCutsceneGetRandomNumber(), 1);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    gNonGameplayRam.intro.pText = (u16*)sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4 );
    
    WRITE_16(REG_DISPCNT, 0x1900);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}



