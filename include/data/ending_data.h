#ifndef ENDING_DATA_H
#define ENDING_DATA_H

#include "macros.h"

#include "gba/memory.h"

extern const u16 sPal_7478A0[PAL_ROW * 3];

extern const u32 sCreditsCharacterGfx[1280];
extern const u32 sCreditsCopyrightText1_Gfx[112];
extern const u32 sCreditsCopyrightText2_Gfx[144];
extern const u32 sCreditsCopyrightText3_Gfx[176];
extern const u32 sCreditsCopyrightText4_Gfx[144];

extern const u16 sPal_749600[PAL_ROW * 6];
extern const u16 sPal_7496c0[PAL_ROW * 10];

extern const u16 sPreResultsSamusWithoutHelmetBgPal[PAL_ROW * 10];
extern const u16 sPreResultsSamusSuitlessBgPal[PAL_ROW * 10];
extern const u16 sPreResultsSamusObjPal[PAL_ROW * 16];

extern const u16 sOamFrame_749c80[OAM_DATA_SIZE(25)];
extern const u16 sOamFrame_749d18[OAM_DATA_SIZE(6)];
extern const u16 sOamFrame_749d3e[OAM_DATA_SIZE(4)];

extern const u16 sEnding_0_Pal[PAL_ROW * 16];
extern const u16 sEnding_1_Pal[PAL_ROW * 16];
extern const u16 sEnding_2_Pal[PAL_ROW * 16];
extern const u16 sEnding_3_Pal[PAL_ROW * 16];
extern const u16 sEnding_4_Pal[PAL_ROW * 16];
extern const u16 sResultsTextPal[PAL_ROW * 4];

extern const struct CreditsEntry sCredits[310];

extern const u32* const sPreResultsSamusBgGfxPointers1[4];
extern const u32* const sPreResultsSamusBgGfxPointers2[4];
extern const u8* const sPreResultsSamusBgTilemapPointers[4];

extern const u32 sPreResultsSpaceBgGfx[4772];

extern const u8 sTilemap_7535e0[2208];
extern const u8 sTilemap_753E80[376];

extern const u32 sPreResultsSamusSuitedGfx1[853];
extern const u32 sPreResultsSamusSuitedGfx2[629];
extern const u32 sPreResultsSamusSuitedGfx3[852];
extern const u32 sPreResultsSamusSuitedGfx4[852];
extern const u32 sPreResultsSamusSuitedGfx5[848];
extern const u32 sPreResultsSamusSuitedGfx6[941];
extern const u32 sPreResultsSamusSuitedGfx7[915];
extern const u32 sPreResultsSamusSuitedGfx8[778];
extern const u32 sPreResultsSamusSuitedGfx9[923];
extern const u32 sPreResultsSamusSuitedGfx10[496];

extern const u32 sPreResultsSamusWithoutHelmetBgGfx1[897];
extern const u32 sPreResultsSamusWithoutHelmetBgGfx2[124];
extern const u32 sPreResultsSamusSuitlessBgGfx1[710];
extern const u32 sPreResultsSamusSuitlessBgGfx2[124];

extern const u8 sTilemap_75db50[692];
extern const u8 sTilemap_75de04[764];
extern const u8 sTilemap_75e100[788];
extern const u8 sTilemap_75e414[744];
extern const u8 sTilemap_75e6fc[660];
extern const u8 sTilemap_75E990[516];
extern const u8 sTilemap_75EB94[472];

extern const u32 sPreResultsSamusObjGfx[2887];

extern const u32 sEnding_0_GfxTop[5628];
extern const u32 sEnding_0_GfxBottom[3191];
extern const u32 sEnding_1_GfxTop[5900];
extern const u32 sEnding_1_GfxBottom[2986];
extern const u32 sEnding_2_GfxTop[5731];
extern const u32 sEnding_2_GfxBottom[3293];
extern const u32 sEnding_3_GfxTop[6364];
extern const u32 sEnding_3_GfxBottom[3818];
extern const u32 sEnding_4_GfxTop[6851];
extern const u32 sEnding_4_GfxBottom[3504];

extern const u8 sEnding_0_TilemapTop[2204];
extern const u8 sEnding_0_TilemapBottom[1472];
extern const u8 sEnding_1_TilemapTop[2204];
extern const u8 sEnding_1_TilemapBottom[1472];
extern const u8 sEnding_2_TilemapTop[2204];
extern const u8 sEnding_2_TilemapBottom[1472];
extern const u8 sEnding_3_TilemapTop[2204];
extern const u8 sEnding_3_TilemapBottom[1476];
extern const u8 sEnding_4_TilemapTop[2204];
extern const u8 sEnding_4_TilemapBottom[1476];

extern const u32 sResultsScreenEnglishTextGfx[1201];
extern const u32 sResultsScreenFrenchTextGfx[1171];
extern const u32 sResultsScreenItalianTextGfx[1221];
extern const u32 sResultsScreenSpanishTextGfx[1197];
extern const u32 sResultsScreenGermanTextGfx[1144];

#endif /* ENDING_DATA_H */
