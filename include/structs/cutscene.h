#ifndef CUTSCENE_STRUCT_H
#define CUTSCENE_STRUCT_H

#include "types.h"

struct SpecialCutsceneOam {
    s16 spawnX;
    s16 spawnY;
    s16 unk_4;
    u16 scaling;
    s16 unk_8;
    u16 unk_A;
    s16 xPosition;                // 0xC
    s16 yPosition;                // 0xE
    u8 type;                       // 0x10
    u8 currentAnimationFrame;      // 0x11
    u8 animationDurationCounter;   // 0x12
    u8 timer;                      // 0x13
    u8 stage;                      // 0x14
    u8 rotation;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18_0 : 1;
    u8 unk_18_1 : 2;
    u8 unk_18_3 : 5;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    struct FrameData* pOam;        // 0x1C
    void* pFunction;               // 0x20
};

#endif /* CUTSCENE_STRUCT_H */
