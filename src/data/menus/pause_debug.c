#include "data/menus/pause_debug.h"
#include "macros.h"
#include "gba.h"
#include "globals.h"

#include "constants/samus.h"

const u8 sPauseDebugBeamFlags[5] = {
    [0] = BF_CHARGE_BEAM,
    [1] = BF_WIDE_BEAM,
    [2] = BF_PLASMA_BEAM,
    [3] = BF_WAVE_BEAM,
    [4] = BF_ICE_BEAM,
};

const u8 sPauseDebugMissileFlags[4] = {
    [0] = MBF_MISSILES,
    [1] = MBF_SUPER_MISSILES,
    [2] = MBF_ICE_MISSILES,
    [3] = MBF_DIFFUSION_MISSILES,
};

const u8 sPauseDebugBombFlags[2] = {
    [0] = MBF_BOMBS,
    [1] = MBF_POWER_BOMBS,
};

const u8 sPauseDebugSuitFlags[2] = {
    [0] = SMF_VARIA_SUIT,
    [1] = SMF_GRAVITY_SUIT,
};

const u8 sPauseDebugMiscFlags[5] = {
    [0] = SMF_MORPH_BALL,
    [1] = SMF_HIGH_JUMP,
    [2] = SMF_SPEED_BOOSTER,
    [3] = SMF_SPACE_JUMP,
    [4] = SMF_SCREW_ATTACK,
};

const u8 sStatusScreenSectionSizes[5] = {
    [0] = ARRAY_SIZE(sPauseDebugBeamFlags),
    [1] = ARRAY_SIZE(sPauseDebugMissileFlags),
    [2] = ARRAY_SIZE(sPauseDebugBombFlags),
    [3] = ARRAY_SIZE(sPauseDebugSuitFlags),
    [4] = ARRAY_SIZE(sPauseDebugMiscFlags),
};

const u16 sPauseDebugNumbersIncrementValues[5] = {
    1, 10, 100, 1000, 10000,
};

const u16 sPauseDebugNumbersMaxValues[3] = {
    [PAUSE_DEBUG_AMMO_TYPE_HEALTH] = 2099,
    [PAUSE_DEBUG_AMMO_TYPE_MISSILES] = 255,
    [PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS] = 254,
};

const u8 sMinimap_576190[48] = {
    0x00, 0x01, 0x01, 0x0C, 0x0E, 0x05, 0x0C, 0x07,
    0x01, 0x01, 0x01, 0x01, 0x0C, 0x0C, 0x0C, 0x0C,
    0x00, 0x01, 0x0D, 0x0D, 0x0E, 0x05, 0x01, 0x07,
    0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
    0x00, 0x01, 0x03, 0x03, 0x0E, 0x05, 0x01, 0x07,
    0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
};

const u8 sMinimap_5761C0[48] = {
    0x00, 0x10, 0x10, 0xC0, 0xE0, 0x50, 0xC0, 0x70,
    0x10, 0x10, 0x10, 0x10, 0xC0, 0xC0, 0xC0, 0xC0,
    0x00, 0x10, 0xD0, 0xD0, 0xE0, 0x50, 0x10, 0x70,
    0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
    0x00, 0x10, 0x30, 0x30, 0xE0, 0x50, 0x10, 0x70,
    0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
};

const void* const sPauseScreen_5761f0[8] = {
    [0] = VRAM_OBJ + 0x3700 + 0x60 * 1,
    [1] = VRAM_OBJ + 0x3700 + 0x60 * 2,
    [2] = VRAM_OBJ + 0x3B00 + 0x60 * 1,
    [3] = VRAM_OBJ + 0x3B00 + 0x60 * 2,
    [4] = VRAM_OBJ + 0x3F00 + 0x60 * 1,
    [5] = VRAM_OBJ + 0x3F00 + 0x60 * 2,
    [6] = VRAM_OBJ + 0x3300 + 0x60 * 1,
    [7] = VRAM_OBJ + 0x3300 + 0x60 * 2,
};

const u8 sMaintainedInputDelays[7] = {
    15, 10, 6, 4, 4, 4, 2,
};


static const u8 sBlob_576217_581510[] = INCBIN_U8("data/Blob_576217_581510.bin");


const u8 sPauseDebugEventNames[EVENT_END][EVENT_NAME_SIZE] = {
    [EVENT_NONE] = SHIFT_JIS("TOHOKANKO   トクベツホカンコヘ ムカエ  "),
    [EVENT_NAVIGATION_ROOM_BEFORE_QUARANTINE_BAY] = SHIFT_JIS("TOHOKANKO2  トクベツホカンコノ チョウサ "),
    [EVENT_QUARANTINE_BAY_HORNOAD_DEAD] = SHIFT_JIS("HOKANKO     ナビヘ モドレ       "),
    [EVENT_NAVIGATION_ROOM_AFTER_QUARANTINE_BAY] = SHIFT_JIS("TOMARUKARA  キョダイセイブツヲ タオセ "),
    [EVENT_NAVIGATION_ROOM_BEFORE_ELEVATOR] = SHIFT_JIS("TOMISSILE   ミサイルヲ ニュウシュセヨ   "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_1] = SHIFT_JIS("DATA3       トナリノ ヘヤヘ        "),
    [EVENT_ENTERED_MISSILE_DATA_ROOM] = SHIFT_JIS("TODATA      データルームニ ハイル    "),
    [EVENT_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("MISSILE     データルームデ ミサイルヲ "),
    [EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE] = SHIFT_JIS("DOWNENE     デンゲンガ オチタ    "),
    [EVENT_NAVIGATION_ROOM_AFTER_MISSILES] = SHIFT_JIS("TOMARUKARA2 キョダイセイブツヲ タオセ2"),
    [EVENT_MORPH_BALL_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS1   ナビヘ ムカエ        "),
    [EVENT_NAVIGATION_ROOM_AFTER_MORPH_BALL] = SHIFT_JIS("TOKUTYOU    SR388ヘ ムカエ      "),
    [EVENT_ENTERED_ELEVATOR_ROOM] = SHIFT_JIS("ELESTART    エレデモ SR388ヘムカエ "),
    [EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS] = SHIFT_JIS("ELEEND      デモエンド SR388ヘ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_SRX] = SHIFT_JIS("TOKUTYOU2   クウチョウメロンヲ タオセ   "),
    [EVENT_CHARGE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("POWERB      コアXゴ ノコリハカイセヨ  "),
    [EVENT_ALL_STABILIZERS_ONLINE] = SHIFT_JIS("KUTYOU      ハカイゴ ナビヘ ムカエ  "),
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX] = SHIFT_JIS("TOBOM       ボムヲ ニュウシュセヨ    "),
    [EVENT_NAVIGATION_ROOM_ENTERING_TRO] = SHIFT_JIS("TOLV1KEY    レベル1ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_1_UNLOCKED] = SHIFT_JIS("LV1KEY      レベル1カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_2] = SHIFT_JIS("TOBOM2      カイジョゴ ボムデータヘ"),
    [EVENT_ENTERING_BOMB_DATA_ROOM] = SHIFT_JIS("DATATRO     データルームニ ハイル    "),
    [EVENT_BOMB_DATA_DOWNLOADED] = SHIFT_JIS("BOM         ネッタイカラ ダッシュツセヨ "),
    [EVENT_SA_X_QUAKE] = SHIFT_JIS("BOMQUAKE    ボムゴ ジシン      "),
    [EVENT_LEFT_SA_X_QUAKE_ROOM] = SHIFT_JIS("BOMQUAKE2   ジシン シュウリョウ     "),
    [EVENT_HIGH_JUMP_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS2   ボスノノチ ダッシュツ   "),
    [EVENT_ESCAPED_TRO_1_SA_X] = SHIFT_JIS("TROSAX      SAXカラ ニゲル      "),
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO] = SHIFT_JIS("TOWATER     スイチュウセクションヘ     "),
    [EVENT_NAVIGATION_ROOM_ENTERING_AQA] = SHIFT_JIS("WATER       スイイヲ サゲロ       "),
    [EVENT_SPEED_BOOSTER_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS3   ボスノノチ スイイヲサゲロ "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_3] = SHIFT_JIS("TOWATSWITCH ダッシュノ セツメイ     "),
    [EVENT_ENTERED_PUMP_CONTROL_UNIT] = SHIFT_JIS("WATSWTROOM  スイイヘンコウヘヤ       "),
    [EVENT_WATER_LEVEL_LOWERED] = SHIFT_JIS("WATSWITCH   スイイヘンコウ         "),
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA] = SHIFT_JIS("TOPWMISSILE パワーミサイルヲ テニイレロ "),
    [EVENT_NAVIGATION_ROOM_ENTERING_PYR] = SHIFT_JIS("TOLV2KEY    レベル2ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_2_UNLOCKED] = SHIFT_JIS("LV2KEY      レベル2カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_4] = SHIFT_JIS("TOPWMISSILE2Pミサイルヘ カイジョゴ  "),
    [EVENT_ENTERED_SUPER_MISSILE_DATA_ROOM] = SHIFT_JIS("DATABUR     データルームニ ハイル    "),
    [EVENT_SUPER_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("PWMISSILE   パワーミサイル カンリョウ  "),
    [EVENT_TRIGGERED_BOX_RUMBLE] = SHIFT_JIS("DOTADOTA    オートデモゴニ モドレ  "),
    [EVENT_BOX_DEFEATED] = SHIFT_JIS("DOWNBOSSA1  ボスA タオス        "),
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR] = SHIFT_JIS("TOENEGAS    アンコクセクションヘ ムカエ  "),
    [EVENT_LEFT_NAVIGATION_ROOM] = SHIFT_JIS("ADAMRENPO   アダム レンポウ      "),
    [EVENT_SECRET_CONVERSATION] = SHIFT_JIS("ADAMRENPODEMOアダムレンポウチュ    "),
    [EVENT_SECRET_CONVERSATION_OVER] = SHIFT_JIS("ADAMRENPOENDアダムレンポエンド    "),
    [EVENT_SKIPPED_BY_USING_NOC_NAVIGATION_ROOM] = SHIFT_JIS("TOANKOKU    アンコク イガイデ コウシン"),
    [EVENT_ENTERED_NOC_NAVIGATION_ROOM] = SHIFT_JIS("DARNAVI     アンコクナビニ ハイル    "),
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC] = SHIFT_JIS("TOENEGAS2   ボス4ヲ タオセ       "),
    [EVENT_NOC_SA_X_ENCOUNTER] = SHIFT_JIS("DARSAX      SAXニ アウ         "),
    [EVENT_ESCAPED_NOC_SA_X] = SHIFT_JIS("DARSAXESC   SAXカラ ニゲキル     "),
    [EVENT_NOC_DATA_ROOM_DESTROYED] = SHIFT_JIS("BARILOSS    バリア スワレル       "),
    [EVENT_VARIA_SUIT_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS4   ナビヘ モドレ       "),
    [EVENT_REACHED_TOP_OF_ROOM_AFTER_VARIA] = SHIFT_JIS("CXESCAPE    コールドX ニゲル     "),
    [EVENT_NAVIGATION_ROOM_LEAVING_NOC] = SHIFT_JIS("TOFREEZEM   ゴッカンセクションヘ ムカエ "),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC] = SHIFT_JIS("TOLV3KEY    レベル3ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_3_UNLOCKED] = SHIFT_JIS("LV3KEY      レベル3カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_5] = SHIFT_JIS("TOFREEZEM2  アイスミサイルヲ ニュウシュセヨ"),
    [EVENT_ENTERED_ICE_MISSILE_DATA_ROOM] = SHIFT_JIS("DATAFRI     データルームニ ハイル    "),
    [EVENT_ICE_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("FREEZEM     アイスミサイル カンリョウ   "),
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC] = SHIFT_JIS("TOENEBALL   ネツボウソウ カイシ     "),
    [EVENT_WIDE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("WIDEB       コンソールヲ オセ       "),
    [EVENT_COOLING_UNIT_OPERATIONAL] = SHIFT_JIS("ENEBALL     ナビヘ モドレ       "),
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR_2] = SHIFT_JIS("TOETEKON    キョジュウクヘ ムカエ    "),
    [EVENT_ANIMALS_RELEASED] = SHIFT_JIS("ETEKON      ナビヘ キュウシュツゴ   "),
    [EVENT_NAVIGATION_ROOM_AFTER_ANIMALS] = SHIFT_JIS("TOPBOM      パワーボムヲ ニュウシュセヨ"),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_2] = SHIFT_JIS("TOPBOM2     ゴッカン コウシン      "),
    [EVENT_POWER_BOMB_DATA_DOWNLOADED] = SHIFT_JIS("PBOM        パワーボム カンリョウ   "),
    [EVENT_ARC_SA_X_ENCOUNTER] = SHIFT_JIS("FRISAX      SAXニ デアウ       "),
    [EVENT_ESCAPED_ARC_SA_X] = SHIFT_JIS("FRISAXESC   SAXカラ ニゲキル     "),
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC_2] = SHIFT_JIS("TOSTARSHIP  スペースシップヘ ムカエ  "),
    [EVENT_POWER_OUTAGE] = SHIFT_JIS("ENGDOWN     スペースシップヘムカエ   "),
    [EVENT_ENTERED_SHIP] = SHIFT_JIS("TODOURYOKU  ホジョ デンゲンヲ イレロ"),
    [EVENT_ENTERED_YAKUZA_ROOM] = SHIFT_JIS("BOSS5ROOM   ボス ヘヤ          "),
    [EVENT_SPACE_JUMP_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS5   ホジョデンゲンヲイレロ  "),
    [EVENT_AUXILARY_POWER_ENGAGED] = SHIFT_JIS("SUBENG      ホジョデンゲン カンリョウ"),
    [EVENT_NAVIGATION_ROOM_AFTER_YAKUZA] = SHIFT_JIS("TOPLASMAB   ネッタイセクションヘ ムカエ  "),
    [EVENT_ENGAGED_TRO_2_SA_X] = SHIFT_JIS("TROSAX2     SAXニ デアウ       "),
    [EVENT_ESCAPED_TRO_2_SA_X] = SHIFT_JIS("TROSAX2ESC  SAXカラ ニゲキル     "),
    [EVENT_PLASMA_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("PLASMAB     ドウリョク カイフク ナビヘ"),
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO_2] = SHIFT_JIS("TOGOKAN     ゴッカン ボスヲ タオセ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_3] = SHIFT_JIS("TOGOKAN2    ゴッカンナビデ コウシン "),
    [EVENT_GRAVITY_SUIT_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS6   ボス タオス ナビヘ    "),
    [EVENT_ENTERED_LEVEL_4_SECURITY_ROOM] = SHIFT_JIS("TOLV4KEY    レベル4ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_4_UNLOCKED] = SHIFT_JIS("LV4KEY      レベル4カイジョ      "),
    [EVENT_SECRET_MESSAGE_2] = SHIFT_JIS("TOKAKUSAN2  カクサンヲ ニュウシュセヨ2  "),
    [EVENT_ENTERED_DIFFUSION_MISSILE_DATA_ROOM] = SHIFT_JIS("DATAWAT     データルームニ ハイル    "),
    [EVENT_DIFFUSION_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("KAKUSAN     カクサン ニュウシュ ナビヘ "),
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA_2] = SHIFT_JIS("TOANKOKUOKU アンコク カクシヲ サガセ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC_2] = SHIFT_JIS("TOSHUTTER   アンコクナビデ コウシン  "),
    [EVENT_RESTRICTED_ZONE_WARNING] = SHIFT_JIS("SHUTTER     アンコクノ オクヘ       "),
    [EVENT_TRIGGERED_BOX_2_RUMBLE] = SHIFT_JIS("SHUTTER2    シャッター ジシン      "),
    [EVENT_WAVE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("WAVEB       アンコクノ オクヘ2      "),
    [EVENT_RESTRICTED_LABORATORY_EXPLOSION] = SHIFT_JIS("TOGOKUHIKEN ゴクヒ デモ        "),
    [EVENT_60_SECONDS_TO_DETACHMENT] = SHIFT_JIS("RANSHA      ランシャ アンド タイマー  "),
    [EVENT_ESCAPED_RESTRICTED_LABORATORY] = SHIFT_JIS("TOKIRIHANA  キリハナシ           "),
    [EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY] = SHIFT_JIS("KIRIHANA    カサイゴ コウシン      "),
    [EVENT_SCREW_ATTACK_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS7   ボス7 タオシ ダッシュツ "),
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX_2] = SHIFT_JIS("TOOPE       シンジツ           "),
    [EVENT_END_OF_FIRST_CONVERSATION] = SHIFT_JIS("TOOPEMONO   モノローグ          "),
    [EVENT_SECOND_CONVERSATION] = SHIFT_JIS("TOOPE2      キドウヲ カエロ       "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6] = SHIFT_JIS("TOOPE3      アダム サイド コウシン  "),
    [EVENT_ENTERED_OPERATION_DECK] = SHIFT_JIS("INTOOPE     オペレーションニ ハイル   "),
    [EVENT_SA_X_DEFEATED] = SHIFT_JIS("DOWNSAX     SAXヲ タオス        "),
    [EVENT_ORBIT_CHANGE_IMPLEMENTED] = SHIFT_JIS("KIDOUKAE    キドウヲ カエル       "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7] = SHIFT_JIS("ESCAPE      キドウヘンコウゴ コウシン "),
    [EVENT_ENTERED_SHIP_ROOM] = SHIFT_JIS("OMEGA       メトロイド ト セントウ   "),
    [EVENT_SA_X_KILLED_BY_OMEGA_METROID] = SHIFT_JIS("DOWNSAX2    オメガ SAXヲ タオス   "),
    [EVENT_ICE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("ICEBEAM     アイスビーム カクトク    "),
    [EVENT_OMEGA_METROID_DEFEATED] = SHIFT_JIS("DOWNOMEGA   メトロイド ヲ タオス    "),
    [EVENT_ESCAPED_ON_SHIP] = SHIFT_JIS("END         エンド            "),
};

const u8 sDebugLocationSectionInfo[2][2] = {
    [0] = {
        [0] = 12,
        [1] = 17,
    },
    [1] = {
        [0] = 13,
        [1] = 17,
    }
};

const u8 sDebugSectionInfo[PAUSE_DEBUG_SECTION_END][5] = {
    [PAUSE_DEBUG_SECTION_BEAM] = {
        [0] = 4,
        [1] = 4 + ARRAY_SIZE(sPauseDebugBeamFlags) - 1,
        [2] = 1,
        [3] = 7,
        [4] = PAUSE_DEBUG_SECTION_BEAM,
    },
    [PAUSE_DEBUG_SECTION_MISSILE] = {
        [0] = 11,
        [1] = 11 + ARRAY_SIZE(sPauseDebugMissileFlags) - 1,
        [2] = 1,
        [3] = 7,
        [4] = PAUSE_DEBUG_SECTION_MISSILE,
    },
    [PAUSE_DEBUG_SECTION_BOMB] = {
        [0] = 3,
        [1] = 3 + ARRAY_SIZE(sPauseDebugBombFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_BOMB,
    },
    [PAUSE_DEBUG_SECTION_SUIT] = {
        [0] = 7,
        [1] = 7 + ARRAY_SIZE(sPauseDebugSuitFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_SUIT,
    },
    [PAUSE_DEBUG_SECTION_MISC] = {
        [0] = 11,
        [1] = 11 + ARRAY_SIZE(sPauseDebugMiscFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_MISC,
    },
    [PAUSE_DEBUG_SECTION_ENERGY_CURRENT] = {
        [0] = 2,
        [1] = 2,
        [2] = 25,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ENERGY_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_ENERGY_MAX] = {
        [0] = 3,
        [1] = 3,
        [2] = 25,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ENERGY_MAX,
    },
    [PAUSE_DEBUG_SECTION_SUPPLY] = {
        [0] = UCHAR_MAX,
        [1] = UCHAR_MAX,
        [2] = 1,
        [3] = 1,
        [4] = PAUSE_DEBUG_SECTION_SUPPLY,
    },
    [PAUSE_DEBUG_SECTION_MISSILE_CURRENT] = {
        [0] = 5,
        [1] = 5,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_MISSILE_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_MISSILE_MAX] = {
        [0] = 6,
        [1] = 6,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_MISSILE_MAX,
    },
    [PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT] = {
        [0] = 7,
        [1] = 7,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_POWER_BOMB_MAX] = {
        [0] = 8,
        [1] = 8,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_POWER_BOMB_MAX,
    },
    [PAUSE_DEBUG_SECTION_ABILITY_COUNT] = {
        [0] = 9,
        [1] = 9,
        [2] = 27,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ABILITY_COUNT,
    },
    [PAUSE_DEBUG_SECTION_SECURITY] = {
        [0] = 15,
        [1] = 15,
        [2] = 24,
        [3] = 24 + SECURITY_LEVEL_4,
        [4] = PAUSE_DEBUG_SECTION_SECURITY,
    },
    [PAUSE_DEBUG_SECTION_MAP] = {
        [0] = 18,
        [1] = 18,
        [2] = 1,
        [3] = 1 + AREA_NORMAL_LAST,
        [4] = PAUSE_DEBUG_SECTION_MAP,
    },
    [PAUSE_DEBUG_SECTION_EVENT] = {
        [0] = 10,
        [1] = 10,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_EVENT,
    },
    [PAUSE_DEBUG_SECTION_SOUND_EVENT] = {
        [0] = 13,
        [1] = 13,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_SOUND_EVENT,
    },
    [PAUSE_DEBUG_SECTION_IN_GAME_TIME] = {
        [0] = 18,
        [1] = 18,
        [2] = 23,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_IN_GAME_TIME,
    },
    [PAUSE_DEBUG_SECTION_QUICK_SAVE] = {
        [0] = 15,
        [1] = 15,
        [2] = 17,
        [3] = 21,
        [4] = PAUSE_DEBUG_SECTION_QUICK_SAVE,
    },
};

static const u8 sBlob_58217b_58225c[] = INCBIN_U8("data/Blob_58217b_58225c.bin");
