#ifndef BLOCK_DATA_H
#define BLOCK_DATA_H

#include "types.h"

#include "constants/block.h"
#include "constants/clipdata.h"

#include "structs/block.h"

extern const CaaDamageType sClipdataActionDamageTypes[CAA_COUNT];

extern const struct BlockBehavior sBlockBehaviors[BEHAVIOR_BLOCK_COUNT];

extern const u16 sBlockWeaknesses[BLOCK_TYPE_COUNT];

extern const ClipdataTilemap sReformingBlocksTilemapValue[BLOCK_TYPE_COUNT];

extern const u8 sBrokenBlockTimers[BLOCK_TYPE_REFORM_COUNT][13];

extern const struct BombChainReverseData sBombChainReverseData[8];

extern const struct TankBehavior sTankBehaviors[BEHAVIOR_TANK_COUNT];

extern const s8 sSubBombChainPositionOffset[SUB_BOMB_CHAIN_REQUEST_COUNT][4];

extern const u8 sBlockTouchOffsets[4][2];


extern const s8 sEndingSamusPosingSineTable[128];

#endif /* BLOCK_DATA_H */
