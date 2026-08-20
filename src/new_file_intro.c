#include "globals.h"
#include "new_file_intro.h"

#include "constants/game_state.h"

#include "structs/cutscene.h"

#include "data/new_file_intro_data.h"
#include "data/generic_data.h"
#include "data/menus/title_screen.h"
#include "data/sprite_data.h"

void unk_99940(void); // For V-blank callback

u8 SpecialCutsceneGetRandomNumber(void);
u8 NewFileIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearchOrder);
boolu32 NewFileIntroSamusDrifting(void);
static void NewFileIntroSamusShipFlyingInit(void);
static boolu32 NewFileIntroSamusShipFlyingProcess(void);
static boolu32 NewFileIntroSamusShipFlying(void);
static void NewFileIntroSamusFaintingInit(void);
static boolu32 NewFileIntroSamusFaintingProcess(void);
static boolu32 NewFileIntroSamusFainting(void);
void NewFileIntroProcessOam_Empty(void);
void NewFileIntroProcessTextCursor(struct SpecialCutsceneOam* pOam);

static u16* sMonologueTextPointersJapanese[19];
static u16* sMonologueTextPointersEnglish[19];
static u16* sMonologueTextPointersGerman[19];
static u16* sMonologueTextPointersFrench[19];
static u16* sMonologueTextPointersItalian[19];
static u16* sMonologueTextPointersSpanish[19];

const u8* sTitleScreenDebugTextPointer = {
    sTitleScreenDebugText,
};

const struct FrameData* sData_79C2CC[6] = {
    sOam_597ec0,
    sOam_597ed0,
    sOam_597ee0,
    sOam_597ef0,
    sOam_597ee0,
    sOam_597ed0
};

static u8 sBlob_79c2e4_79c3fc[] = INCBIN_U8("data/Blob_79c2e4_79c3fc.bin");

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

static const u32* sIntroSamusSittingBgGfxPointers[5] = {
    (u32*)0x0864578c,
    (u32*)0x086465ec,
    (u32*)0x08647534,
    (u32*)0x0864843c,
    (u32*)0x086492fc,
};

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

static u8 sBlob_79e868_79eca0[] = INCBIN_U8("data/Blob_79e868_79eca0.bin");

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
            if (INTRO_DATA.unk_20E != 0)
                INTRO_DATA.unk_20E = 0;
        }
        else if (gSubGameMode1 != 0 && gSubGameMode1 != 3)
        {
            if (READ_16(REG_BLDCNT) & BLDCNT_ALPHA_BLENDING_EFFECT)
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
            
            INTRO_DATA.unk_20E = 0;
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
            if (INTRO_DATA.unk_20E == 0)
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    result = TRUE;
            }
            else
                INTRO_DATA.unk_20E--;
            
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
            INTRO_DATA.timer++;
            if (INTRO_DATA.timer >= 100)
            {
                INTRO_DATA.timer = 0;
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
                INTRO_DATA.unk_20E = 0;
                gSubGameMode1 = 12;
            }
            break;
        
        case 12:
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
                    Sram_ProcessIntroSave(0);
                }
                else if (INTRO_DATA.unk_20E == 2)
                {
                    Sram_ProcessIntroSave(1);
                } 
                else if (INTRO_DATA.unk_20E == 3)
                {
                    Sram_ProcessIntroSave(2);
                }
                else if (INTRO_DATA.unk_20E == 4)
                {
                    Sram_ProcessIntroSave(3);
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.unk_20E = 0;
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
static void NewFileIntroSamusShipFlyingVblank(void) 
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
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
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
        NewFileIntroSetupOam(3, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4 );

    INTRO_DATA.pText = (u16*)sCutsceneTextNone;
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

    if (*INTRO_DATA.pText == 0xfc00 && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), 1);

            if (INTRO_DATA.timer == 99)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == 100)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][10];
                INTRO_DATA.subStage = 1;
            }
            break;
        
        case 1:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), 1);

            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
            }
            break;

        case 2:
            if (INTRO_DATA.timer == 30)
            {
                INTRO_DATA.timer = 0;
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

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusShipFlyingInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusShipFlyingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;   
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
                INTRO_DATA.stage = 0;
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

    INTRO_DATA.pText = (u16*)sCutsceneTextNone;
    
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
    
    if ((*INTRO_DATA.pText == 0xFC00) && (gChangedInput & KEY_A) && (INTRO_DATA.unk_218 == 0))
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer += 1;
    
    switch (INTRO_DATA.subStage) 
    {
        case 0:
            if (INTRO_DATA.timer == 1)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_FIRST_TARGET_PIXEL);
                NewFileIntroSetupOam(10, (s16)gBg2XPosition, (s16)gBg2YPosition, 1);
            }
            else if (INTRO_DATA.timer == 59)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == 60)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][11];
                INTRO_DATA.subStage = 1;
            }
            break;
        
        case 1:
            INTRO_DATA.timer = 0;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
                gWrittenToBldy = 16;
            }
            break;
        
        case 2:
            if (INTRO_DATA.timer == 30) 
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.timer = 0;
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

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusFaintingInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusFaintingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < 16)
            {
                gWrittenToBldy++;
            }
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
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
 * @brief 88240 | 26c | Setup for the 'gunship drifting away from BSL ship' cutscene
 * 
 */
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
    
    LZ77UncompWram(sIntroBslSpaceBgGfx, EWRAM_BASE + 0x10000);
    
    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE, (VRAM_SIZE / 3) / 4);
    
    LZ77UncompVram(sIntroBslTilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSpaceTilemap, VRAM_BASE + 0xF800);
    
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

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
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    NewFileIntroSetupOam(200, 250, 0, 0);
    NewFileIntroSetupOam(1, (s16)gBg2XPosition, (s16)gBg2YPosition, 0);
    NewFileIntroSetupOam(20, 160, 90, 0);
    NewFileIntroSetupOam(4, 0, 0, 1);
    
    for (i = 0; i < 10; i++)
        NewFileIntroSetupOam(3, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    INTRO_DATA.pText = (u16*)sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}

 /**
 * @brief 884ac | c8 | V-blank for the 'Samus losing conciousness' cutscene
 * 
 */
static void NewFileIntroSamusLosingConsciousnessVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);

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
        DMA3_COPY_32(sIntroSamusCloseupGrayscalePal, PALRAM_BASE, 4 * PAL_ROW_SIZE / 4);
    }
}

 /**
 * @brief 88574 | 1e0 | Setup for the 'Samus losing conciousness' cutscene
 * 
 */
void NewFileIntroSamusLosingConsciousnessInit(void) 
{
    u16 i;

    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, 0x030016a0, 720); // TODO: Find out what 16a0 is
    
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    for (i = 0; i < 6; i++)
        LZ77UncompVram(sIntroSamusHelmetCloseupBgGfxPointers[i], VRAM_BASE + i * 0x1000);
    
    LZ77UncompVram(sIntroSamusHelmetCloseupTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusHelmetCloseupTilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sIntroSamusHelmetCloseupPal, PALRAM_BASE, 4 * PAL_ROW_SIZE / 4);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
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
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    NewFileIntroSetupOam(200, 250, 0, 0);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    INTRO_DATA.pText = (u16*)sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusLosingConsciousnessVblank);
    
    gWrittenToBldy = 0;
    gWrittenToBldalpha_Eva = 12;
    gWrittenToBldalpha_Evb = 8;
}

 /**
 * @brief 88754 | 25c | Setup for the 'gunship drifting into asteroids' cutscene
 * 
 */
void NewFileIntroSamusDriftingIntoAsteroidsInit(void) 
{
    u16 i;
    void* temp1;
    u32 temp2;
    
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam + 0x21C, 720);
    
    for (i = 0; i < 8; i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(sPal_612f48, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVram(sTitleScreenSpaceBackgroundTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sPal_609020, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598a8c, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
    
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

    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;

    //WRITE_16(REG_BLDALPHA, 0); // Doesn't match
    temp1 = REG_BLDALPHA;
    temp2 = 0;
    WRITE_16(temp1, temp2);
    
    NewFileIntroSetupOam(30, 140, 140, 0);
    NewFileIntroSetupOam(31, 140, 80, 0);
    
    for (i = 0; i < 4; i++)
        NewFileIntroSetupOam(36, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = (u16*)sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}

 /**
 * @brief 889b0 | 318 | To document
 * 
 */
boolu32 NewFileIntroSamusDriftingProcess(void)
{
    boolu32 finished;
    s16 x;
    s16 y;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == 0xFC00 && gChangedInput & KEY_A && !INTRO_DATA.unk_218)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer++;
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), TRUE);
            
            if (INTRO_DATA.timer != 149) // Why?
            {
                if (INTRO_DATA.timer == 150)
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.subStage = 1;
                    gWrittenToBldy = BLDY_MAX_VALUE;
                }
            }
            break;
        
        case 1:
            NewFileIntroSamusLosingConsciousnessInit();
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 2;
            break;
        
        case 2:
            if (INTRO_DATA.timer == 1)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                NewFileIntroSetupOam(10, gBg2XPosition, gBg2YPosition, TRUE);
                gWrittenToBldy = 0;
            }
            else if (INTRO_DATA.timer == 118)
            {
                break;
            }
            else if (INTRO_DATA.timer == 120)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.unk_110 = 1;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }
            break;

        case 3:
            if (INTRO_DATA.timer == 60)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
                gWrittenToBldy = 16;
            }
            break;
        
        case 4:
            NewFileIntroSamusDriftingIntoAsteroidsInit();
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 5;
            break;
        
        case 5:
            INTRO_DATA.timer = 0;
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;

        case 6:
            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
            
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.timer == 3)
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldy++;
                }
            } 
            else if (INTRO_DATA.timer == 10)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 7;
                finished = TRUE;
            }
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 7:
            if (gWrittenToBldy) 
            {
                if (INTRO_DATA.timer == 6) 
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldy--;
                }
            } 
            else 
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 8;
            }

            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 8:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 1)
            {
                SpecialCutsceneDestroyOamOfType(201);
                INTRO_DATA.subStage = 9;
            }
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 9:
            finished = TRUE;
            break;
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 88cc8 | 9c | To document
 * 
 */
boolu32 NewFileIntroSamusDrifting(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusDriftingInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusDriftingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
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
 * @brief 88d64 | 150 | To document
 * 
 */
void NewFileIntroProcessBslShip(struct SpecialCutsceneOam *pOam)
{
    s32 cos;
    s32 sin;
    
    pOam->unk_4 = pOam->xPosition;
    
    if (pOam->stage == 0) 
    {
        pOam->stage = 2;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        pOam->xPosition = (((60 - pOam->spawnX) * pOam->unk_A) >> 10) + pOam->spawnX;
        pOam->yPosition = (((10 - pOam->spawnY) * pOam->unk_A) >> 10) + pOam->spawnY;
        
        if (pOam->xPosition > 39) 
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 1) 
        {
            pOam->unk_A = 0;
            pOam->spawnX = 0;
            pOam->spawnY = 4;
            pOam->unk_8 = pOam->yPosition;
            pOam->timer = 128;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        cos = pOam->spawnX * COS(pOam->timer);
        sin = pOam->spawnY * SIN(pOam->timer);
        pOam->yPosition = ((SIN(0) * cos + COS(0) * sin) >> 16) + pOam->unk_8;
        pOam->timer++;
        
        if (pOam->unk_A != 60) // Why?
        {
            if (pOam->unk_A == 200)
            {
                pOam->unk_A = 0;
                pOam->stage = 4;
            } 
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->stage = 5;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
    } 
    else if (pOam->stage == 5)
    {    
        pOam->unk_A++;
        pOam->xPosition = (((520 - pOam->spawnX) * pOam->unk_A) >> 10) + pOam->spawnX;
        pOam->yPosition = (((100 - pOam->spawnY) * pOam->unk_A) >> 10) + pOam->spawnY;

        if (pOam->xPosition >= 520)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 6;
        }
    }
    
    gBg2XPosition = pOam->xPosition;
    gBg2YPosition = pOam->yPosition;
}

 /**
 * @brief 88eb4 | 128 | To document
 * 
 */
void NewFileIntroProcessFlyingSamusShip(struct SpecialCutsceneOam *pOam)
{
    s32 rotation;
    s32 cos;
    s32 sin;
    s32 x;
    s32 y;

    rotation = 0;
    
    if (pOam->stage == 0)
    {
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition;
        pOam->timer = 64;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->scaling -= 2;

        if (pOam->timer == 128)
        {
            pOam->stage = 2;
            pOam->scaling = Q_8_8(1);
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->spawnX = 0;
        pOam->spawnY = 8;
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition;
        pOam->stage = 3;
    }
    else if (pOam->stage == 3)
    {
        pOam->timer += 2;
    }
    else if (pOam->stage == 4)
    {
        pOam->timer++;
        pOam->unk_A++;
        if (pOam->unk_A == 180)
        {
            pOam->unk_A = 0;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->spawnX = 280 - pOam->xPosition;
        pOam->spawnY = 60;
        pOam->unk_4 = pOam->xPosition + pOam->spawnX;
        pOam->unk_8 = pOam->yPosition;
        pOam->timer = 128;
        pOam->stage = 6;
    }
    else if (pOam->stage == 6)
    {
        pOam->timer++;
        if (pOam->timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    
    cos = pOam->spawnX * COS(pOam->timer);
    sin = pOam->spawnY * SIN(pOam->timer);
    
    x = cos * COS(rotation) - sin * SIN(0);
    y = cos * SIN(0) + sin * COS(rotation);
    
    pOam->xPosition = (x >> 16) + pOam->unk_4;
    pOam->yPosition = (y >> 16) + pOam->unk_8;
}

 /**
 * @brief 88fdc | b4 | To document
 * 
 */
void NewFileIntroProcessHorizontalParticle(struct SpecialCutsceneOam *pOam)
{
    s32 rng;
    
    if (pOam->stage == 0)
    {
        rng = SpecialCutsceneGetRandomNumber() & 7;
        pOam->unk_8 = rng + 1;
        rng = SpecialCutsceneGetRandomNumber() & 3;
        pOam->unk_4 = rng;
        pOam->pOam = (struct FrameData*)sData_79C2CC[pOam->unk_4];
        pOam->spawnX = pOam->xPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        pOam->xPosition = ((pOam->unk_8 * pOam->unk_A) >> 4) + pOam->spawnX;
        
        pOam->timer++;
        if (pOam->timer == 8)
        {
            pOam->timer = 0;
            
            if (pOam->unk_4 < 5)
                pOam->unk_4++;
            else
                pOam->unk_4 = 0;
            
            pOam->pOam = (struct FrameData*)sData_79C2CC[pOam->unk_4];
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }
    }
    
    if (pOam->xPosition >= SCREEN_SIZE_X || pOam->yPosition >= SCREEN_SIZE_Y)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 89090 | 28 | To document
 * 
 */
void unk_89090(struct SpecialCutsceneOam *pOam) 
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 25)
    {
        pOam->animationDurationCounter = 0;
        gBg3XPosition--;
    }
}

 /**
 * @brief 890b8 | 104 | To document
 * 
 */
void NewFileIntroProcessSamusFainting(struct SpecialCutsceneOam* pOam)
{
    u8 rng1;
    u8 rng2;

    rng1 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit, 32)] / 2;
    rng2 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit + 7, 32)] / 2;

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
}

 /**
 * @brief 891bc | 74 | To document
 * 
 */
void NewFileIntroProcessSamusDrifting(struct SpecialCutsceneOam* pOam)
{
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
        pOam->xPosition = pOam->spawnX + (pOam->unk_A >> 1);
        pOam->yPosition = pOam->spawnY + (pOam->unk_A >> 2);

        pOam->timer++;
        if (pOam->timer == 2)
        {
            pOam->timer = 0;
            pOam->scaling++;
        }
    }

    if (pOam->xPosition > (SCREEN_SIZE_X + 40) || pOam->yPosition > (SCREEN_SIZE_Y + 20))
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 89230 | 258 | To document
 * 
 */
void NewFileIntroProcessSamusDriftingIntoAsteroids(struct SpecialCutsceneOam *pOam)
{
    struct FrameData* frame;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->rotation -= 4;
        pOam->scaling -= 8;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->yPosition = (SIN(pOam->timer) >> 7) + pOam->spawnY;
        
        if (pOam->timer > 52)
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

        if (pOam->timer > 127)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
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
        pOam->timer++;
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
        pOam->timer++;
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
        pOam->unk_18_1 = 0;
        pOam->pOam = (struct FrameData*)0x08598000;
        pOam->stage = 6;
        INTRO_DATA.subStage = 6;
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

 /**
 * @brief 89488 | 64 | To document
 * 
 */
void unk_89488(struct SpecialCutsceneOam *pOam) 
{
    if (pOam->stage == 0)
    {
        NewFileIntroSetupOam(32, pOam->xPosition + 122, pOam->yPosition, FALSE);
        NewFileIntroSetupOam(33, pOam->xPosition + 50, pOam->yPosition + 1, FALSE);
        NewFileIntroSetupOam(34, pOam->xPosition + 36, pOam->yPosition, FALSE);
        NewFileIntroSetupOam(35, pOam->xPosition, pOam->yPosition, FALSE);
        pOam->type = 0;
    }
}

 /**
 * @brief 894ec | c4 | To document
 * 
 */
void NewFileIntroProcessSidewaysBslShip(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->timer++;
        if (pOam->timer == 20)
        {
            pOam->spawnX++;
            pOam->timer = 0;

            if (pOam->unk_A == 4)
                pOam->unk_A = 0;

            if (pOam->unk_A < 2)
                pOam->yPosition++;
            else if (pOam->unk_A < 4)
                pOam->yPosition--;
                
            pOam->unk_A++;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->stage = 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
        if (pOam->timer == 2)
        {
            pOam->unk_A++;
            pOam->timer = 0;
        }

        pOam->xPosition = (((900 - pOam->spawnX) * pOam->unk_A) >> 12) + pOam->spawnX;
        pOam->yPosition = (((pOam->unk_4 - pOam->spawnY) * pOam->unk_A) >> 11) + pOam->spawnY;

        if (pOam->xPosition > 320)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 3;
        }
    }
}

 /**
 * @brief 895b0 | c4 | To document
 * 
 */
void NewFileIntroProcessDepthParticle(struct SpecialCutsceneOam* pOam)
{
    s32 x;
    s32 y;
    s32 divisor;
    
    pOam->unk_4 = pOam->unk_A;

    if (pOam->stage == 0)
    {
        pOam->spawnX = (pOam->xPosition - SCREEN_X_MIDDLE) * 100;
        pOam->spawnY = (pOam->yPosition - SCREEN_Y_MIDDLE) * 100;
        pOam->stage = 1;
    }
    else
    {
        if ((s16)pOam->unk_A < 100)
        {
            if ((s16)pOam->unk_A == 25)
                pOam->pOam = (struct FrameData*)sOam_597ed0;
            else if ((s16)pOam->unk_A == 50)
                pOam->pOam = (struct FrameData*)sOam_597ee0;
            else if ((s16)pOam->unk_A == 70)
                pOam->pOam = (struct FrameData*)sOam_597ef0;

            divisor = -pOam->unk_4 + 100;
            x = pOam->spawnX / divisor;
            pOam->xPosition = x + SCREEN_X_MIDDLE;
            y = pOam->spawnY / divisor + SCREEN_Y_MIDDLE;
            pOam->yPosition = y;

            if ((u16)(x + 128) > 256 || (s16)y > 168 || (s16)y < -8)
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
        else
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    
    pOam->unk_A++;
}

 /**
 * @brief 89674 | 400 | To document
 * 
 */
u8 NewFileIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearchOrder)
{
    s8 slot;

    if (!descendingSearchOrder)
    {
        for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot > 19)
            return 20;
    }
    else
    {
        for (slot = ARRAY_SIZE(INTRO_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot < 0)
            return 20;
    }
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], 36);

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == 1)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslShip;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597f50;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessFlyingSamusShip;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].unk_1A_2 = 3;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597ec0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessHorizontalParticle;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_89090;
    }
    else if (type == 10)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFainting;
    }
    else if (type == 20)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].unk_18_1 = 3;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597f50;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusDrifting;
    }
    else if (type == 30)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].unk_18_1 = 1;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597f88;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusDriftingIntoAsteroids;
    }
    else if (type == 31)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597f88;
        INTRO_DATA.oam[slot].pFunction = unk_89488;
    }
    else if (type == 32)
    {
        INTRO_DATA.oam[slot].unk_4 = -40;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597fe0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 33)
    {
        INTRO_DATA.oam[slot].unk_4 = -30;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597fd0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 34)
    {
        INTRO_DATA.oam[slot].unk_4 = -20;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597fc0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 35)
    {
        INTRO_DATA.oam[slot].unk_4 = -10;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597fb0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 36)
    {
        INTRO_DATA.oam[slot].unk_1A_2 = 2;
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08597ec0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessDepthParticle;
    }
    else if (type == 200)
    {
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08613180;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }
    else if (type == 201)
    {
        INTRO_DATA.oam[slot].pOam = (struct FrameData*)0x08613180;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessOam_Empty;
    }
    
    return slot;
}

 /**
 * @brief 89a74 | 3c | To document
 * 
 */
void unk_89a74(u8 type, s16 xPos, s16 yPos, s16 arg3) 
{
    u8 slot;
    
    slot = NewFileIntroSetupOam(type, xPos, yPos, TRUE);
    INTRO_DATA.oam[slot].unk_8 = arg3;
}

 /**
 * @brief 89ab0 | 4 | To document
 * 
 */
void NewFileIntroProcessOam_Empty(void) 
{
    return;
}


