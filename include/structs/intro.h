#ifndef INTRO_STRUCT_H
#define INTRO_STRUCT_H

#include "types.h"

#include "structs/cutscene.h"

#define INTRO_DATA gNonGameplayRam.intro

struct IntroData {
    const u16* pText;
    const u16* pText2;
    u16 stage;
    u16 unk_A;
    u16 unk_C;
    u16 unk_E;
    u8 unk_10[256];
    u8 unk_110;
    u8 unk_111;
    u8 unk_112[26];
    u8 unk_12C;
    u8 unk_12D;
    u8 unk_12E[197];
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
    u8 unk_217;
    u8 unk_218;
    u8 unk_219[3];
    struct SpecialCutsceneOam oam[20];
    u8 hBlankCode[80];
    u8* hBlankCodePointer;
};

#endif /* INTRO_STRUCT_H */
