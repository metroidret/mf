#include "data/menus/game_over_data.h"

#include "macros.h"
#include "oam.h"

#include "gba/memory.h"

const u8 sGameOverOamXFlipOffsets[12] = {
	1, 2, 4, 8,
	2, 4, 4, 8,
	1, 1, 2, 4
};

const u32 sGameOverBgGfx[5651] = INCBIN_U32("data/game_over/background.gfx.lz");
const u32 sGameOverObjGfx[184] = INCBIN_U32("data/game_over/object.gfx.lz");

const u32 sGameOverTextGfx_English[438] = INCBIN_U32("data/game_over/text_english.gfx.lz");
const u32 sGameOverTextGfx_German[446] = INCBIN_U32("data/game_over/text_german.gfx.lz");
const u32 sGameOverTextGfx_French[504] = INCBIN_U32("data/game_over/text_french.gfx.lz");
const u32 sGameOverTextGfx_Italian[489] = INCBIN_U32("data/game_over/text_italian.gfx.lz");
const u32 sGameOverTextGfx_Spanish[475] = INCBIN_U32("data/game_over/text_spanish.gfx.lz");

static const u16 sOamFrame_73c218[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 2, 3, 0),
};

static const u16 sOamFrame_73c220[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 4, 3, 0),
};

static const u16 sOamFrame_73c228[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 6, 3, 0),
};

static const u16 sOamFrame_73c230[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 3, 0),
};

static const u16 sOamFrame_73c238[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 3, 0),
};

static const u16 sOamFrame_73c246[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 32, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 3, 0),
};

static const u16 sOamFrame_73c254[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 1, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 3, 0),
};

static const u16 sOamFrame_73c262[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 2, 5, 0),
};

static const u16 sOamFrame_73c26a[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 2, 6, 0),
};

const struct FrameData sGameOverSamusHelmetOam_Idle[5] = {
	[0] = {
		.pFrame = sOamFrame_73c218,
		.timer = 14
	},
	[1] = {
		.pFrame = sOamFrame_73c262,
		.timer = 14
	},
	[2] = {
		.pFrame = sOamFrame_73c26a,
		.timer = 14
	},
	[3] = {
		.pFrame = sOamFrame_73c262,
		.timer = 14
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGameOverSamusHelmetOam_Turning[9] = {
	[0] = {
		.pFrame = sOamFrame_73c218,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_73c220,
		.timer = 4
	},
	[2] = {
		.pFrame = sOamFrame_73c228,
		.timer = 4
	},
	[3] = {
		.pFrame = sOamFrame_73c230,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_73c238,
		.timer = 5
	},
	[5] = {
		.pFrame = sOamFrame_73c246,
		.timer = 5
	},
	[6] = {
		.pFrame = sOamFrame_73c254,
		.timer = 5
	},
	[7] = {
		.pFrame = sOamFrame_73c230,
		.timer = 255
	},
	[8] = FRAME_DATA_TERMINATOR
};

const u16 sGameOverBgPal[16 * PAL_ROW] = INCBIN_U16("data/game_over/background.pal");
const u16 sGameOverObjPal[16 * PAL_ROW] = INCBIN_U16("data/game_over/object.pal");

const u32 sGameOverBgTilemap[369] = INCBIN_U32("data/game_over/background.tm.lz");
const u32 sGameOverTextTilemap[193] = INCBIN_U32("data/game_over/text.tm.lz");

static const u8 sBlob_73cfac_7478a0[] = INCBIN_U8("data/Blob_73cfac_7478a0.bin");

