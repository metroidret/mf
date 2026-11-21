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
    u8 unk_6;
    u8 unk_7;
    u8 timer;
    u8 stage;
    u8 objMode;
    u8 priority;
    u8 unk_C;
    u8 palette;
    u16 tile;
    const struct FrameData* pOam;
    MonologueOamFunc_T pFunction;
};

struct MonologueData {
    u8 unk_0[0x8];
    u16 stage;
    u16 monologueId;
    const u16* pText;
    u8 unk_10[2];
    u16 unk_12;
    u16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18[0x1FC];
    struct MonologueOam oam[5];
};

#endif /* MONOLOGUE_STRUCT_H */
