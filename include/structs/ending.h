#ifndef ENDING_STRUCT_H
#define ENDING_STRUCT_H

#include "types.h"

struct EndingData {
    u8 unk_0;
    u8 stage;
    u16 unk_2;
    u16 unk_4;
    u16 currentCreditLine;
    u16 unk_8;
    u16 creditLineTilemap_1[32];
    u16 creditLineTilemap_2[32];
    u32 unk_8C;
    u32 unk_90;
    u16 timer;
    u8 unk_96;
    u8 unk_97;
    u8 unk_98;
    u8 unk_99;
    u8 unk_9A;
    u8 unk_9B;
    u8 unk_9C;
    u8 unk_9D;
    u8 padding2[2];
    u16* unk_A0;
    u8 unk_A4[0x80];
    u8 unk_124[6];
    u8 padding3[0x36];
    u8 unk_160[0x1D];
    u16 oamXPositions[30]; // 17E
    u16 oamYPositions[30]; // 1BA
    u8 padding4[2];
    u16* oamFramePointers[10]; // 1F8
    u8 unk_220[0x50];
    u8 unk_270[10]; // FIXME find actual length
};

#endif /* ENDING_STRUCT_H */
