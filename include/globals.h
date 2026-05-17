#ifndef GLOBALS_H
#define GLOBALS_H

#include "types.h"
#include "gba.h"
#include "structs/menus/pause_screen.h"
#include "structs/menus/title_screen.h"
#include "structs/sa_x_close_up.h"
#include "structs/ending.h"

struct InGameData {
    u8 clipdataCode[640];
};

struct IntroData {
    u16* pText;
    u8 padding1[4];
    u16 stage;
    u16 unk_A;
    u16 unk_C;
    u16 unk_E;
    u8 padding2[256];
    u8 unk_110;
    u8 padding3[253];
    u16 unk_20E;
    u16 timer;
    u8 unk_212;
    u8 unk_213;
    u8 unk_214;
    u8 unk_215;
    u8 padding4[2];
    u8 unk_218;
    u8 padding_219[3];
    u32 unk_21C;
};

union NonGameplayRam {
    struct PauseScreenData pauseScreen;
    struct InGameData inGame;
    struct TitleScreenData titleScreen;
    struct SaXCloseUpData saXCloseUp;
    struct IntroData intro;
    struct EndingData ending;
    u8 size[1344];
};

extern union NonGameplayRam gNonGameplayRam;

#define PAUSE_SCREEN_DATA gNonGameplayRam.pauseScreen
#define IN_GAME_DATA gNonGameplayRam.inGame
#define TITLE_SCREEN_DATA gNonGameplayRam.titleScreen
#define SA_X_CLOSE_UP_DATA gNonGameplayRam.saXCloseUp

extern u8 gCommonSpriteGfxBackup[0x4000];
extern u8 gRoomSpriteGfxBackup[0x4000];
extern u16 gBackgroundPalette[COLORS_IN_PAL];

extern u8 gRebootGame;
extern u8 gClearedEveryFrame;
extern vu16 gVBlankRequestFlag;
extern s16 gMainGameMode;
extern s16 gSubGameMode1;
extern s8 gSubGameMode2;

extern u8 gFrameCounter8Bit;
extern u16 gFrameCounter16Bit;
extern s8 gPauseScreenFlag;
extern u8 gCurrentCutscene;
extern s8 gIsLoadingFile;
extern s8 gUnk_3000be3;
extern u8 gUnk_3000b8f;
extern u8 gUnk_3000064;

extern u8 gCurrentEventBasedEffect;
extern u8 gQueuedEventBasedEffect;

extern u8 gDebugFlag;
extern u16 gButtonInput;
extern u8 gNotPressingUp;
extern u16 gButtonInputCopy;
extern u16 gChangedInput;
extern u8 gDisableSoftReset;

extern u16 gBg0XPosition;
extern u16 gBg0YPosition;
extern u16 gBg1XPosition;
extern u16 gBg1YPosition;
extern u16 gBg2XPosition;
extern u16 gBg2YPosition;
extern u16 gBg3XPosition;
extern u16 gBg3YPosition;

extern u8 gSpritesetNumber;

extern u8 gDisplayLocationName;

extern u8 gSamusOnTopOfBackgrounds;

extern u16 gWrittenToBldcnt;
extern u16 gWrittenToBldalpha_Eva;
extern u16 gWrittenToBldalpha_Evb;
extern u16 gWrittenToBldy;
extern u8 gDisableScrolling;
extern u8 gDisableMusicFlag;
extern s8 gDisablePauseFlag;

extern u16 gBg3CntDuringDoorTransition;
extern u16 gBg1CntDuringDoorTransition;

extern s8 gLanguage;

struct GameCompletion {
    s8 completedGame;
    s8 introPlayed;
};

extern struct GameCompletion gGameCompletion;

struct WindowBorder {
    u8 left;
    u8 right;
    u8 top;
    u8 bottom;
    u8 timer;
};

extern struct WindowBorder gWindow1Border;

extern u8 gInterruptCode[512];
extern void* gInterruptCodePointer;

struct BackgroundPositions {
    struct RawCoordsX bg[4];
    struct RawCoordsX doorTransition;
};

extern struct BackgroundPositions gBackgroundPositions;

struct Haze {
    void* pAffected;
    u16 unk_4;
    u8 size;
    u8 enabled:7;
    u8 active:1;
};

extern struct Haze gHazeInfo;

extern u16 gBackdropColor;

struct InGameTime {
    u8 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

extern struct InGameTime gInGameTimer;
extern u8 gMaxInGameTimeFlag;

enum Cutscene {
    CUTSCENE_NONE,
    CUTSCENE_MONOLOGUE_INTRO,
    CUTSCENE_ELEVATOR_MONOLOGUE_REMIND,
    CUTSCENE_ELEVATOR_MONOLOGUE_TRUST,
    CUTSCENE_ELEVATOR_MONOLOGUE_SA_X,
    CUTSCENE_ELEVATOR_MONOLOGUE_ANIMALS,
    CUTSCENE_ELEVATOR_MONOLOGUE_INCIDENT,
    CUTSCENE_MONOLOGUE_FEDERATION,
    CUTSCENE_MONOLOGUE_END,
    CUTSCENE_SECRET_CONVERSATION,
    CUTSCENE_RESTRICTED_LAB_DETACHING,
    CUTSCENE_RESTRICTED_LAB_DETACHING_DYING,
    CUTSCENE_BSL_EXPLODING,

    CUTSCENE_END,
};

struct IoRegisters {
    u16 dispcnt;
    u16 bldcnt;
    u8 bldalpha_eva;
    u8 bldalpha_evb;
    u8 winin_H;
    u8 winout_L;
    u16 bg0Cnt;
    u16 bg1Cnt;
    u16 bg2Cnt;
    u16 bg3Cnt;
    u16 unk_10;
};

extern struct IoRegisters gIoRegisters;

struct DefaultTransparency {
    u8 unk_0;
    u8 evbCoef;
    u8 evaCoef;
    u16 bldcnt;
};

extern struct DefaultTransparency gDefaultTransparency;

extern u16 gEffectYPosition;

struct ButtonAssignments {
    u16 armMissiles;
    u16 diagonalAim;
    u16 swapMissiles;
    u16 pause;
};

extern struct ButtonAssignments gButtonAssignments;

extern u8 gMonochromeFading;
extern u8 gWhichBgPositionIsWrittenToBg3Ofs;
extern u8 gSkipDoorTransition;

extern u16 gWrittenToMosaic_H;
extern u16 gWrittenToMosaic_L;

extern u8 gDisableDoorsAndTanks;
extern u8 gColorFading;

enum GameMode {
    GAME_MODE_TITLE,
    GAME_MODE_IN_GAME,
    GAME_MODE_SOFT_RESET,
    GAME_MODE_MAP_SCREEN,
    GAME_MODE_CUTSCENE,
    GAME_MODE_SA_X_CLOSE_UP,
    GAME_MODE_ERASE_SRAM_MENU,
    GAME_MODE_FILE_SELECT_OR_INTRO,
    GAME_MODE_GAME_OVER,
    GAME_MODE_ENDING,
    GAME_MODE_DIED_FROM_SR388_COLLISION,
    GAME_MODE_CREDITS,
    GAME_MODE_DEMO,
    GAME_MODE_UNKNOWN,
    GAME_MODE_DEBUG,

    GAME_MODE_COUNT
};

enum PauseScreenFlag {
    PAUSE_SCREEN_NONE,
};

// For in game
enum SubGameMode {
    SUB_GAME_MODE_DOOR_TRANSITION = 1,
    SUB_GAME_MODE_PLAYING,
    SUB_GAME_MODE_LOADING_ROOM,
    SUB_GAME_MODE_SA_X_ELEVATOR,
    SUB_GAME_MODE_DYING,
    SUB_GAME_MODE_NO_CLIP,

    SUB_GAME_MODE_COUNT
};


extern u16 gUnk_3000050;
extern s8 gUnk_3004e3a;
extern u8 gUnk_3004e42;

struct Unk_3004e44 {
    s8 unk_0;
    u8 unk_1;
};

extern struct Unk_3004e44 gUnk_3004e44;

struct Unk_3004e4c {
    u8 unk_0[8]; // Padding
    s16 unk_8;
};

extern struct Unk_3004e4c gUnk_3004e4c;

struct EventBasedEffectInfo {
    u16 stage;
    u16 timer;
};

extern struct EventBasedEffectInfo gEventBasedEffectInfo;

#endif /* GLOBALS_H */
