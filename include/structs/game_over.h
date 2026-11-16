#ifndef GAME_OVER_STRUCT_H
#define GAME_OVER_STRUCT_H

#include "types.h"

#define GAME_OVER_DATA gNonGameplayRam.gameOver

struct GameOverOam;
typedef void (*GameOverOamFunc_T)(struct GameOverOam*);

struct GameOverOam {
    s16 xPosition;
    s16 yPosition;
    u8 type;
    boolu8 isDrawn;
    u8 currentAnimationFrame;
    u8 timer;
    u8 unk_C;
    u8 unk_D;
    u8 objMode;
    u8 priority;
    boolu8 xFlip;
    u8 palette;
    u16 tile;
    const struct FrameData* pOam;
    GameOverOamFunc_T pFunction;
};

struct GameOverData {
    u8 unk_0;
    u8 stage;
    u8 timer;
    u8 unk_3;
    struct GameOverOam oam[3];
};

#endif /* GAME_OVER_STRUCT_H */
