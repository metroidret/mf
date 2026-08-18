#include "macros.h"
#include "oam.h"

#include "data/new_file_intro_data.h"

const struct FrameData sOam_597ec0[2] = {
    [0] = {
        .pFrame = (u16*)0x08597708,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ed0[2] = {
    [0] = {
        .pFrame = (u16*)0x08597710,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ee0[2] = {
    [0] = {
        .pFrame = (u16*)0x08597718,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ef0[2] = {
    [0] = {
        .pFrame = (u16*)0x08597720,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_597f00_5980b0[] = INCBIN_U8("data/Blob_597f00_5980b0.bin");

const u16 sIntroSamusShipPal[16 * 5] = INCBIN_U16("data/new_file_intro/samus_ship.pal");
const u16 sPal_598150[16 * 2] = INCBIN_U16("data/new_file_intro/598150.pal"); // Loaded to PALRAM but not used?

const u32 sIntroSamusHelmetCloseupTilemap[172] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup.tm.lz");

static const u8 sBlob_598440_598818[] = INCBIN_U8("data/Blob_598440_598818.bin");

const u16 sIntroSamusHelmetCloseupPal[16 * 4] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup.pal");

const u32 sIntroSamusShipFlyingTextTilemap[125] = INCBIN_U32("data/new_file_intro/samus_ship_flying_text.tm.lz");

const u16 sPal_598a8c[16 * 1] = INCBIN_U16("data/new_file_intro/598a8c.pal");
const u16 sIntroSamusCloseupGrayscalePal[16 * 4] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup_grayscale.pal");

static const u8 sBlob_598b2c_60093c[] = INCBIN_U8("data/Blob_598b2c_60093c.bin");

const u32 sIntroSamusSittingGfx[4818] = INCBIN_U32("data/new_file_intro/samus_sitting.gfx.lz");
const u16 sIntroSamusSittingPal[16 * 16] = INCBIN_U16("data/new_file_intro/samus_sitting.pal");
const u32 sIntroSamusSittingTilemap[171] = INCBIN_U32("data/new_file_intro/samus_sitting.tm.lz");

static const u8 sBlob_605930_605d08[] = INCBIN_U8("data/Blob_605930_605d08.bin");

const u32 sTitleScreenSpaceBackgroundGfx[830] = INCBIN_U32("data/menus/title_screen/space_background.gfx.lz");

static const u8 sBlob_606a00_609020[] = INCBIN_U8("data/Blob_606a00_609020.bin");

const u16 sPal_609020[16 * 8] = INCBIN_U16("data/new_file_intro/609020.pal");
const u16 sTitleScreenSpaceBackgroundPal[16 * 8] = INCBIN_U16("data/menus/title_screen/space_background.pal");

const u32 sTitleScreenSpaceBackgroundTilemap[172] = INCBIN_U32("data/menus/title_screen/space_background.tm.lz");

static const u8 sBlob_6094d0_60b148[] = INCBIN_U8("data/Blob_6094d0_60b148.bin");

const u8 sIntroSpaceTilemap[1320] = INCBIN_U8("data/new_file_intro/space_bg.tm.lz");
const u8 sIntroBslTilemap[1586] = INCBIN_U8("data/new_file_intro/bsl_bg.tm.lz");

static const u8 padding[2] = {0, 0};

const u32 sIntroBslSpaceBgGfx[4421] = INCBIN_U32("data/new_file_intro/bsl_space_bg.gfx.lz");

static const u8 sBlob_6101b8_612e48[] = INCBIN_U8("data/Blob_6101b8_612e48.bin");

const u16 sIntroBslSpaceBgPal[16 * 8] = INCBIN_U16("data/new_file_intro/bsl_space_bg.pal");
const u16 sPal_612f48[16 * 16] = INCBIN_U16("data/new_file_intro/612f48.pal");

const u32 sNextPageArrowGfx[8] = INCBIN_U32("data/new_file_intro/next_page_arrow.gfx");

static const u8 sBlob_613168_6131a8[] = INCBIN_U8("data/Blob_613168_6131a8.bin");

const u16 sNextPageArrowPal[16 * 1] = INCBIN_U16("data/new_file_intro/next_page_arrow.pal");

static const u8 sBlob_6131c8_63a19c[] = INCBIN_U8("data/Blob_6131c8_63a19c.bin");

const u16 sCutsceneTextNone[2] = {
    0xff00, 0xff00
};

static const u8 sBlob_63a1a0_642a30[] = INCBIN_U8("data/Blob_63a1a0_642a30.bin");

const u32 sIntroBslObjectGfx0[448] = INCBIN_U32("data/new_file_intro/bsl_object_0.gfx.lz");
const u32 sIntroBslObjectGfx1[402] = INCBIN_U32("data/new_file_intro/bsl_object_1.gfx.lz");
const u32 sIntroBslObjectGfx2[420] = INCBIN_U32("data/new_file_intro/bsl_object_2.gfx.lz");
const u32 sIntroBslObjectGfx3[124] = INCBIN_U32("data/new_file_intro/bsl_object_3.gfx.lz");
const u32 sIntroBslObjectGfx4[298] = INCBIN_U32("data/new_file_intro/bsl_object_4.gfx.lz");
const u32 sIntroBslObjectGfx5[186] = INCBIN_U32("data/new_file_intro/bsl_object_5.gfx.lz");
const u32 sIntroBslObjectGfx6[543] = INCBIN_U32("data/new_file_intro/bsl_object_6.gfx.lz");
const u32 sIntroBslObjectGfx7[482] = INCBIN_U32("data/new_file_intro/bsl_object_7.gfx.lz");

static const u8 sBlob_64578c_72eee0[] = INCBIN_U8("data/Blob_64578c_72eee0.bin");



