#ifndef CUTSCENE_STRUCT_H
#define CUTSCENE_STRUCT_H

#include "types.h"

#define CUTSCENE_DATA gNonGameplayRam.cutscene

struct SpecialCutsceneOam {
    s16 spawnX;
    s16 spawnY;
    s16 unk_4;
    s16 scaling;
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
    u32 affineMode : 2;         // Can't be u8
    u8 unk_18_3 : 2;
    u8 unk_18_5 : 1;
    u8 unk_19;
    u8 unk_1A_0 : 2;
    u8 priority : 2;
    u8 unk_1A_4 : 4;
    u8 unk_1B;
    const struct FrameData* pOam;  // 0x1C
    void* pFunction;               // 0x20
};

struct CutsceneData {
    const u16* pText;
    const u16* pText2;
    u16 stage;
    u16 unk_A;
    u16 unk_C;
    u16 unk_E;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[252];
    u8 unk_110;
    u8 unk_111;
    u8 unk_112[26];
    u8 unk_12C;
    u8 unk_12D;
    u8 unk_12E[26];
    u8 unk_148;
    u8 unk_149;
    u8 unk_14A[166];
    u8 unk_1F0;
    u8 unk_1F1;
    u8 unk_1F2;
    u8 unk_1F3;
    u8 unk_1F4;
    u8 unk_1F5;
    u8 unk_1F6[22];
    u16 unk_20C;
    u16 unk_20E;
    u16 timer;
    u8 unk_212;
    u8 unk_213;
    u8 subStage;
    u8 unk_215;
    s8 unk_216;
    s8 unk_217;
    u8 unk_218;
    u8 unk_219[3];
    struct SpecialCutsceneOam oam[20];
    u8 hBlankCode[80];
    u8* hBlankCodePointer;
};

#endif /* CUTSCENE_STRUCT_H */
