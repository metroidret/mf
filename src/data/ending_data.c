#include "macros.h"
#include "oam.h"

#include "data/ending_data.h"

#include "structs/ending.h"

#include "constants/ending.h"

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

static const u8 sBlob_74a7d8_74b0b0[] = INCBIN_U8("data/Blob_74a7d8_74b0b0.bin");

const struct CreditsEntry sCredits[310] = {
	[0] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[1] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[2] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[3] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[4] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[5] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "           PRODUCER"
	},
	[6] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[7] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Izushi Takehiro"
	},
	[8] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = ""
	},
	[9] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[10] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[11] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[12] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[13] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[14] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        CHIEF DIRECTOR"
	},
	[15] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[16] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Sakamoto Yoshio"
	},
	[17] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[18] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[19] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[20] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[21] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[22] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[23] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SYSTEM DIRECTOR"
	},
	[24] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[25] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Hosokawa Takehiko"
	},
	[26] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[27] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[28] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[29] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SCENARIO & STORY"
	},
	[30] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[31] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Sakamoto Yoshio"
	},
	[32] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[33] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[34] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[35] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "          GAME DESIGN"
	},
	[36] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[37] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yamane Tomoyoshi"
	},
	[38] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[39] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Hosokawa Takehiko"
	},
	[40] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[41] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[42] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[43] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         COURSE DESIGN"
	},
	[44] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[45] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "          Ueda Masani"
	},
	[46] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[47] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Nakada Ryuichi"
	},
	[48] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[49] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[50] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[51] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        VISUAL DIRECTOR"
	},
	[52] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[53] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamane Tomoyoshi"
	},
	[54] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[55] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[56] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[57] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         SAMUS DESIGN"
	},
	[58] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[59] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Sano Shinya"
	},
	[60] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[61] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[62] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[63] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "     SAMUS ORIGINAL DESIGN"
	},
	[64] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[65] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Kiyotake Hiroji"
	},
	[66] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[67] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[68] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[69] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "    ENEMY CHARACTER DESIGN"
	},
	[70] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[71] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yamane Tomoyoshi"
	},
	[72] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[73] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Hirano Isao"
	},
	[74] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[75] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Sano Shinya"
	},
	[76] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[77] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      Matsushita Tadashi"
	},
	[78] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[79] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[80] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[81] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   BACKGROUND GRAPHIC DESIGN"
	},
	[82] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[83] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Morisawa Takayasu"
	},
	[84] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[85] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Miyamoto Fumiko"
	},
	[86] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[87] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[88] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[89] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        GRAPHIC DESIGN"
	},
	[90] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[91] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Momose Hiroshi"
	},
	[92] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[93] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Sakiyama Chiharu"
	},
	[94] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[95] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[96] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[97] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       PROGRAM DIRECTOR"
	},
	[98] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[99] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamano Katsuya"
	},
	[100] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[101] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[102] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[103] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       SAMUS PROGRAMMING"
	},
	[104] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[105] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Katsuki Yoshinori"
	},
	[106] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[107] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[108] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[109] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = " ENEMY CHARACTER PROGRAMMING"
	},
	[110] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[111] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamano Katsuya"
	},
	[112] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[113] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[114] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[115] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      SYSTEM PROGRAMMING"
	},
	[116] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[117] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Ozaki Nobuhiro"
	},
	[118] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[119] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[120] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[121] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   CINEMA SCENE PROGRAMMING"
	},
	[122] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[123] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Nakae Eisaku"
	},
	[124] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[125] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[126] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[127] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       TOOL PROGRAMMING"
	},
	[128] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[129] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Harada Takahiro"
	},
	[130] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[131] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "          Fukui Kota"
	},
	[132] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[133] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Katsuki Yoshinori"
	},
	[134] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[135] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Ozaki Nobuhiro"
	},
	[136] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[137] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Momose Hiroshi"
	},
	[138] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[139] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[140] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[141] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SOUND DIRECTOR"
	},
	[142] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[143] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamamoto Kenji"
	},
	[144] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[145] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[146] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[147] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      MUSIC COMPOSITION"
	},
	[148] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[149] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hamano Minako"
	},
	[150] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[151] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Fujiwara Akira"
	},
	[152] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[153] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[154] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[155] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "  SOUND EFFECTS & PROGRAMMING"
	},
	[156] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[157] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Fujii Takaya"
	},
	[158] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[159] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[160] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[161] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        PACKAGE DESIGN"
	},
	[162] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[163] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Nakamichi Sachiko"
	},
	[164] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[165] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[166] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[167] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        MANUAL DESIGN"
	},
	[168] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[169] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      Nakamichi Sachiko"
	},
	[170] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[171] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Itani Kiyomi"
	},
	[172] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[173] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Takahashi Yasuko"
	},
	[174] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[175] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[176] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[177] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         COORDINATION"
	},
	[178] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[179] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Harada Takahiro"
	},
	[180] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[181] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[182] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[183] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "  INTERNATIONAL COORDINATION"
	},
	[184] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[185] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamazaki Sakae"
	},
	[186] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[187] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[188] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[189] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "            DEBUG"
	},
	[190] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[191] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       SUPER MARIO CLUB"
	},
	[192] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[193] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[194] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[195] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[196] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[197] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[198] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[199] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SPECIAL THANKS"
	},
	[200] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[201] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Matsumura Satoshi"
	},
	[202] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[203] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      "
	},
	[204] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[205] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[206] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[207] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[208] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[209] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[210] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[211] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[212] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[213] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[214] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[215] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "   NOA ENGLISH LOCALIZATION"
	},
	[216] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[217] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[218] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   LOCALIZATION MANAGEMENT"
	},
	[219] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[220] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Jeff Miller"
	},
	[221] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[222] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Leslie Swan"
	},
	[223] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[224] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[225] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[226] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         LOCALIZATION"
	},
	[227] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[228] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Scot Ritchey"
	},
	[229] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[230] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Nathan Bihldorff"
	},
	[231] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[232] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Tim O-Leary"
	},
	[233] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[234] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[235] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[236] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       ENGINEERING DEBUG"
	},
	[237] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[238] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Raychole L'Anett"
	},
	[239] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[240] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Robert Crombie"
	},
	[241] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[242] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Kirk Buchanan"
	},
	[243] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[244] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yoshinobu Mantani"
	},
	[245] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[246] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[247] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[248] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Scott Callahan"
	},
	[249] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[250] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Don Dillinger"
	},
	[251] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[252] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hisako Sakauchi"
	},
	[253] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[254] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[255] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[256] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SPECIAL THANKS"
	},
	[257] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[258] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Tatsumi Kimishima"
	},
	[259] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[260] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Mike Fukuda"
	},
	[261] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[262] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hiroshi Kamada"
	},
	[263] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[264] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[265] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[266] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[267] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[268] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[269] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[270] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[271] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[272] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[273] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[274] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[275] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[276] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[277] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[278] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      EXECUTIVE PRODUCER"
	},
	[279] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[280] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Iwata Satoru"
	},
	[281] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[282] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[283] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[284] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[285] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[286] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[287] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[288] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[289] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[290] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[291] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[292] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[293] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[294] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[295] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[296] = {
		.type = CREDIT_LINE_TYPE_ALL_RIGHTS,
		.text = ""
	},
	[297] = {
		.type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
		.text = ""
	},
	[298] = {
		.type = CREDIT_LINE_TYPE_SCENARIO,
		.text = ""
	},
	[299] = {
		.type = CREDIT_LINE_TYPE_RESERVED,
		.text = ""
	},
	[300] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[301] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[302] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[303] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[304] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[305] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[306] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[307] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[308] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[309] = {
		.type = CREDIT_LINE_TYPE_END,
		.text = ""
	},
};

static const u8 sBlob_74dc48_74e620[] = INCBIN_U8("data/Blob_74dc48_74e620.bin");

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
