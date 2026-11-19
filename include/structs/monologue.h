#ifndef MONOLOGUE_STRUCT_H
#define MONOLOGUE_STRUCT_H

#include "types.h"

struct MonologueOam;
typedef void (*MonologueOamFunc_T)(struct MonologueOam*);

struct MonologueOam {
    s16 xPosition;
    s16 yPosition;
    u8 type;
    boolu8 isDrawn;
    u8 currentAnimationFrame;
    u8 timer;
    u8 unk_8;
    u8 unk_9;
    u8 objMode;
    u8 priority;
    boolu8 xFlip;
    u8 palette;
    u16 tile;
    const struct FrameData* pOam;
    MonologueOamFunc_T pFunction;
};

struct MonologueData {
    u8 unk_0[0x8];
    u16 stage;			// 0x8
    u16 unk_A;
    const u16* pText;	// 0xC
    u8 unk_10[2];
    u16 unk_12;
    u16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18[0x1FC];
    struct MonologueOam oam[5]; // 0x214
};

#endif /* MONOLOGUE_STRUCT_H */
