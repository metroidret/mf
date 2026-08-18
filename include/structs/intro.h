#ifndef INTRO_STRUCT_H
#define INTRO_STRUCT_H

#include "types.h"

#include "structs/cutscene.h"

#define INTRO_DATA gNonGameplayRam.intro

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
    u8 subStage;
    u8 unk_215;
    u8 padding4[2];
    u8 unk_218;
    u8 padding_219[3];
    struct SpecialCutsceneOam unk_21C[20]; // not sure if correct size
};

#endif /* INTRO_STRUCT_H */
