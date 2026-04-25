#include "data/ending_data.h"

#include "macros.h"
#include "oam.h"

const u16 sPreResultsSamusWithoutHelmetBgPal[160] = INCBIN_U16("data/ending/samus_without_helmet_bg.pal");
const u16 sPreResultsSamusSuitlessBgPal[160] = INCBIN_U16("data/ending/samus_suitless_bg.pal");
const u16 sPreResultsSamusObjPal[256] = INCBIN_U16("data/ending/samus_obj.pal");

const u16 sOamFrame_749c80[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-18, -75, OAM_DIMS_32x32, OAM_NO_FLIP, 0x0, 2, 0),
    OAM_ENTRY(-10, -43, OAM_DIMS_16x8, OAM_NO_FLIP, 0x47, 2, 0),
    OAM_ENTRY(-34, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-2, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x48, 3, 0),
    OAM_ENTRY(-34, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-34, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0xd, 5, 0),
    OAM_ENTRY(-26, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8e, 5, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 5, 0),
    OAM_ENTRY(14, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa, 1, 0),
    OAM_ENTRY(30, -51, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2c, 4, 0),
    OAM_ENTRY(22, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x6b, 3, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 0x89, 6, 0),
    OAM_ENTRY(-10, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x10, 7, 0),
    OAM_ENTRY(-18, -19, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f, 4, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x90, 3, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_16x32, OAM_NO_FLIP, 0x13, 3, 0),
    OAM_ENTRY(-10, 29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x93, 6, 0),
    OAM_ENTRY(-18, 13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x52, 7, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x19, 7, 0),
    OAM_ENTRY(14, 21, OAM_DIMS_16x32, OAM_NO_FLIP, 0x5a, 7, 0),
    OAM_ENTRY(38, 69, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5e, 9, 0),
    OAM_ENTRY(-18, 45, OAM_DIMS_16x32, OAM_NO_FLIP, 0x16, 9, 0),
    OAM_ENTRY(-26, 69, OAM_DIMS_8x8, OAM_NO_FLIP, 0x75, 9, 0),
    OAM_ENTRY(-26, 77, OAM_DIMS_16x8, OAM_NO_FLIP, 0x95, 8, 0),
    OAM_ENTRY(22, 53, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1c, 9, 0),
};

const u16 sOamFrame_749d18[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-34, -75, OAM_DIMS_64x64, OAM_NO_FLIP, 0xc0, 1, 0),
    OAM_ENTRY(30, -75, OAM_DIMS_8x32, OAM_NO_FLIP, 0xc8, 1, 0),
    OAM_ENTRY(30, -43, OAM_DIMS_8x32, OAM_NO_FLIP, 0x148, 1, 0),
    OAM_ENTRY(-34, -11, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1c0, 1, 0),
    OAM_ENTRY(-34, 53, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2c0, 1, 0),
    OAM_ENTRY(30, 53, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 1, 0),
};

const u16 sOamFrame_749d3e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-30, -76, OAM_DIMS_64x64, OAM_NO_FLIP, 0xca, 1, 0),
    OAM_ENTRY(-30, -12, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1ca, 1, 0),
    OAM_ENTRY(-30, 52, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2ca, 1, 0),
    OAM_ENTRY(34, 52, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2d2, 1, 0),
};

const u16 sEnding_0_Pal[256] = INCBIN_U16("data/ending/ending_0.pal");
const u16 sEnding_1_Pal[256] = INCBIN_U16("data/ending/ending_1.pal");
const u16 sEnding_2_Pal[256] = INCBIN_U16("data/ending/ending_2.pal");
const u16 sEnding_3_Pal[256] = INCBIN_U16("data/ending/ending_3.pal");
const u16 sEnding_4_Pal[256] = INCBIN_U16("data/ending/ending_4.pal");
const u16 sResultsTextPal[64] = INCBIN_U16("data/ending/results_text.pal");

static const u8 sBlob_74a7d8_74e620[] = INCBIN_U8("data/Blob_74a7d8_74e620.bin");

const u32* const sPreResultsSamusBgGfxPointers1[4] = {
    (const u32*)0x8755720,
    (const u32*)0x87571c0,
    (const u32*)0x8758db4,
    (const u32*)0x875a828
};

const u32* const sPreResultsSamusBgGfxPointers2[4] = {
    (const u32*)0x8756470,
    (const u32*)0x8757f00,
    (const u32*)0x8759c00,
    (const u32*)0x875b694
};

const u32* const sPreResultsSamusBgGfxPointers3[4] = {
    (const u32*)0x875de04,
    (const u32*)0x875e100,
    (const u32*)0x875e414,
    (const u32*)0x875e6fc
};

static const u8 sBlob_74e650_753e80[] = INCBIN_U8("data/Blob_74e650_753e80.bin");

const u8 sTilemap_753E80[374] = INCBIN_U8("data/ending/tilemap_753e80.tm.lz");

static const u8 sBlob_753ff6_75be54[] = INCBIN_U8("data/Blob_753ff6_75be54.bin");

const u32 sPreResultsSamusWithoutHelmetBgGfx1[897] = INCBIN_U32("data/ending/samus_without_helmet_bg_1.gfx.lz");
const u32 sPreResultsSamusWithoutHelmetBgGfx2[124] = INCBIN_U32("data/ending/samus_without_helmet_bg_2.gfx.lz");
const u32 sPreResultsSamusSuitlessBgGfx1[710] = INCBIN_U32("data/ending/samus_suitless_bg_1.gfx.lz");
const u32 sPreResultsSamusSuitlessBgGfx2[124] = INCBIN_U32("data/ending/samus_suitless_bg_2.gfx.lz");

static const u8 sBlob_75db50_75e990[] = INCBIN_U8("data/Blob_75db50_75e990.bin");

const u8 sTilemap_75E990[516] = INCBIN_U8("data/ending/tilemap_75e990.tm.lz");
const u8 sTilemap_75EB94[474] = INCBIN_U8("data/ending/tilemap_75eb94.tm.lz");

static const u8 sBlob_75ed6e_761a88[] = INCBIN_U8("data/Blob_75ed6e_761a88.bin");

const u32 sEnding_0_GfxTop[5628] = INCBIN_U32("data/ending/ending_0_top.gfx.lz");
const u32 sEnding_0_GfxBottom[3191] = INCBIN_U32("data/ending/ending_0_bottom.gfx.lz");
const u32 sEnding_1_GfxTop[5900] = INCBIN_U32("data/ending/ending_1_top.gfx.lz");
const u32 sEnding_1_GfxBottom[2986] = INCBIN_U32("data/ending/ending_1_bottom.gfx.lz");
const u32 sEnding_2_GfxTop[5731] = INCBIN_U32("data/ending/ending_2_top.gfx.lz");
const u32 sEnding_2_GfxBottom[3293] = INCBIN_U32("data/ending/ending_2_bottom.gfx.lz");
const u32 sEnding_3_GfxTop[6364] = INCBIN_U32("data/ending/ending_3_top.gfx.lz");
const u32 sEnding_3_GfxBottom[3818] = INCBIN_U32("data/ending/ending_3_bottom.gfx.lz");
const u32 sEnding_4_GfxTop[6851] = INCBIN_U32("data/ending/ending_4_top.gfx.lz");
const u32 sEnding_4_GfxBottom[3504] = INCBIN_U32("data/ending/ending_4_bottom.gfx.lz");

const u8 sEnding_0_TilemapTop[2204] = INCBIN_U8("data/ending/ending_0_top.tm.lz");
const u8 sEnding_0_TilemapBottom[1472] = INCBIN_U8("data/ending/ending_0_bottom.tm.lz");
const u8 sEnding_1_TilemapTop[2204] = INCBIN_U8("data/ending/ending_1_top.tm.lz");
const u8 sEnding_1_TilemapBottom[1472] = INCBIN_U8("data/ending/ending_1_bottom.tm.lz");
const u8 sEnding_2_TilemapTop[2204] = INCBIN_U8("data/ending/ending_2_top.tm.lz");
const u8 sEnding_2_TilemapBottom[1472] = INCBIN_U8("data/ending/ending_2_bottom.tm.lz");
const u8 sEnding_3_TilemapTop[2204] = INCBIN_U8("data/ending/ending_3_top.tm.lz");
const u8 sEnding_3_TilemapBottom[1476] = INCBIN_U8("data/ending/ending_3_bottom.tm.lz");
const u8 sEnding_4_TilemapTop[2204] = INCBIN_U8("data/ending/ending_4_top.tm.lz");
const u8 sEnding_4_TilemapBottom[1476] = INCBIN_U8("data/ending/ending_4_bottom.tm.lz");

const u32 sResultsScreenEnglishTextGfx[1201] = INCBIN_U32("data/ending/results_english_text.gfx.lz");
const u32 sResultsScreenFrenchTextGfx[1171] = INCBIN_U32("data/ending/results_french_text.gfx.lz");
const u32 sResultsScreenItalianTextGfx[1221] = INCBIN_U32("data/ending/results_italian_text.gfx.lz");
const u32 sResultsScreenSpanishTextGfx[1197] = INCBIN_U32("data/ending/results_spanish_text.gfx.lz");
const u32 sResultsScreenGermanTextGfx[1144] = INCBIN_U32("data/ending/results_german_text.gfx.lz");

static const u8 sBlob_79a19c_79a29c[] = INCBIN_U8("data/Blob_79a19c_79a29c.bin");
