#ifndef INTRO_STRUCT_H
#define INTRO_STRUCT_H

#include "types.h"

#include "structs/cutscene.h"

#define INTRO_DATA gNonGameplayRam.intro

struct IntroData {
    u16* pText;
    u8 unk_1[4];
    u16 stage;
    u16 unk_A;
    u16 unk_C;
    u16 unk_E;
    u8 unk_10[256];
    u8 unk_110;
    u8 unk_111[253];
    u16 unk_20E;
    u16 timer;
    u8 unk_212;
    u8 unk_213;
    u8 subStage;
    u8 unk_215;
    u8 unk_216[2];
    u8 unk_218;
    u8 unk_219[3];
    struct SpecialCutsceneOam oam[20];
};

#endif /* INTRO_STRUCT_H */
