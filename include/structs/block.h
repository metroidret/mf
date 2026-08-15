#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H

#include "types.h"

#define MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS 64

struct BrokenBlock {
    u8 stage;
    u8 timer;
    u8 xPosition;
    u8 yPosition;
};

struct BombChain {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};

extern u16 gMakeSolidBlocks[MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS];
extern struct BrokenBlock gBrokenBlocks[32];
extern struct BrokenBlock gUnk_3004ee0[32];
extern struct BombChain gBombChains[4];
extern u8 gActiveBombChainTypes;

#endif /* BLOCK_STRUCT_H */
