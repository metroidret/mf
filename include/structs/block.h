#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H

#include "types.h"
#include "macros.h"

#include "constants/clipdata.h"
#include "constants/block.h"
#include "constants/connection.h"

#define MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS 64
#define MAX_AMOUNT_OF_BROKEN_BLOCKS 32
#define MAX_AMOUNT_OF_BOMB_CHAINS 4

struct BrokenBlock {
    u8 stage:4;
    BlockType type:4;
    u8 timer;
    u8 xPosition;
    u8 yPosition;
};

struct ClipdataBlockData {
    u16 xPosition;
    u16 yPosition;
    u16 behavior;
    u16 tilemapValue;
    u8 blockBehavior;
};

struct BombChain {
    u8 currentOffset;
    u8 srcXPosition; 
    u8 srcYPosition;
    u8 type:3;
    u8 padding:3;
    u8 negativeActive:1;
    u8 positiveActive:1;
};

struct BlockBehavior {
    BlockLifeType lifeType;
    BlockSubType subType;
    BlockType type;
    u8 isSpeedboost:4;
    u8 isBombChain:4;
};

struct BombChainReverseData {
    u8 typeFlag;
    ClipBehavior behavior;
};

struct TankBehavior {
    TankType tankType;
    boolu8 underwater;
    u8 messageId;
};

typedef void (*BlockFunc_T)(struct ClipdataBlockData*);

#define NEVER_REFORM_BLOCKS_SIZE 512
#define NEVER_REFORM_BLOCK_INFO_SIZE 3
#define MAX_AMOUNT_OF_NEVER_REFORM_BLOCK_PER_AREA (NEVER_REFORM_BLOCKS_SIZE / NEVER_REFORM_BLOCK_INFO_SIZE)

#ifdef USE_EWRAM_SYMBOLS
extern u8 gNeverReformBlocks[MAX_AMOUNT_OF_AREAS][NEVER_REFORM_BLOCKS_SIZE];
#else
#define gNeverReformBlocks CAST_TO_ARRAY(u8, [MAX_AMOUNT_OF_AREAS][NEVER_REFORM_BLOCKS_SIZE], EWRAM_BASE + 0x36000)
#endif // USE_EWRAM_SYMBOLS

extern u8 gNumberOfNeverReformBlocks[MAX_AMOUNT_OF_AREAS];

extern u16 gMakeSolidBlocks[MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS];

extern struct BrokenBlock gBrokenReformBlocks[MAX_AMOUNT_OF_BROKEN_BLOCKS];
extern struct BrokenBlock gBrokenNonReformBlocks[MAX_AMOUNT_OF_BROKEN_BLOCKS];
extern u16 gBrokenBlockBg1Values[MAX_AMOUNT_OF_BROKEN_BLOCKS];

extern struct BombChain gBombChains[4];
extern u8 gActiveBombChainTypes;

#endif /* BLOCK_STRUCT_H */
