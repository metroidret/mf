#include "data/block_data.h"

const CaaDamageType sClipdataActionDamageTypes[CAA_COUNT] = {
    [CAA_NONE] = CAA_DAMAGE_TYPE_NONE,
    [CAA_REMOVE_SOLID] = CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_SOLID] = CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_SOLID_STOP_ENEMY] = CAA_DAMAGE_TYPE_NONE,
    [CAA_4] = CAA_DAMAGE_TYPE_NONE,
    [CAA_ENEMY_PROJECTILE] = CAA_DAMAGE_TYPE_NONE,
    [CAA_BEAM] = CAA_DAMAGE_TYPE_BEAM,
    [CAA_BOMB] = CAA_DAMAGE_TYPE_BOMB,
    [CAA_MISSILE] = CAA_DAMAGE_TYPE_MISSILE,
    [CAA_POWER_BOMB] = CAA_DAMAGE_TYPE_POWER_BOMB,
    [CAA_SPEED_BOOST] = CAA_DAMAGE_TYPE_SPEEDBOOST,
    [CAA_SPEED_BOOST_GROUND] = CAA_DAMAGE_TYPE_SPEEDBOOST_ON_GROUND,
    [CAA_SCREW_ATTACK] = CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [CAA_BOMB_CHAIN] = CAA_DAMAGE_TYPE_BOMB_CHAIN,
};

const struct BlockBehavior sBlockBehaviors[BEHAVIOR_BLOCK_COUNT] = {
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_MISSILE_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_BOMB_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_POWER_BOMB_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_MISSILE_NO_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEED_BOOST_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEED_BOOST_NO_REFORM,
        .isSpeedboost = TRUE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEED_BOOST_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEED_BOOST_REFORM,
        .isSpeedboost = TRUE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SCREW_ATTACK_NO_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_CRUMBLE_BLOCK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_CRUMBLE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_BROKEN,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    }
};

const u16 sBlockWeaknesses[BLOCK_TYPE_COUNT] = {
    [BLOCK_TYPE_SHOT_REFORM] = CAA_NONE,
    [BLOCK_TYPE_BOMB_REFORM] = CAA_NONE,
    [BLOCK_TYPE_SPEED_BOOST_REFORM] = CAA_SPEED_BOOST,
    [BLOCK_TYPE_CRUMBLE] = CAA_SPEED_BOOST,
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] = CAA_MISSILE,
    [BLOCK_TYPE_MISSILE_NO_REFORM] = CAA_MISSILE,
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] = CAA_POWER_BOMB,
    [BLOCK_TYPE_SCREW_ATTACK_NO_REFORM] = CAA_SCREW_ATTACK,
    [BLOCK_TYPE_SPEED_BOOST_NO_REFORM] = CAA_SPEED_BOOST,
    [BLOCK_TYPE_BROKEN] = CAA_NONE,
};

const ClipdataTilemap sReformingBlocksTilemapValue[BLOCK_TYPE_COUNT] = {
    [BLOCK_TYPE_SHOT_REFORM] = CLIPDATA_TILEMAP_SHOT_BLOCK_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_BOMB_REFORM] = CLIPDATA_TILEMAP_BOMB_BLOCK_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_SPEED_BOOST_REFORM] = CLIPDATA_TILEMAP_SPEED_BOOST_BLOCK_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_CRUMBLE] = CLIPDATA_TILEMAP_CRUMBLE_BLOCK | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] = CLIPDATA_TILEMAP_MISSILE_BLOCK_NEVER_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_MISSILE_NO_REFORM] = CLIPDATA_TILEMAP_MISSILE_BLOCK_NO_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] = CLIPDATA_TILEMAP_POWER_BOMB_BLOCK_NEVER_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_SCREW_ATTACK_NO_REFORM] = CLIPDATA_TILEMAP_SCREW_ATTACK_BLOCK_NO_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_SPEED_BOOST_NO_REFORM] = CLIPDATA_TILEMAP_SPEED_BOOST_BLOCK_NO_REFORM | CLIPDATA_TILEMAP_FLAG,
    [BLOCK_TYPE_BROKEN] = CLIPDATA_TILEMAP_SHOT_BLOCK_REFORM | CLIPDATA_TILEMAP_FLAG,
};

const u8 sBrokenBlockTimers[BLOCK_TYPE_REFORM_COUNT][13] = {
    [BLOCK_TYPE_SHOT_REFORM] = {
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(4.25f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
    },
    [BLOCK_TYPE_BOMB_REFORM] = {
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(4.25f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
    },
    [BLOCK_TYPE_SPEED_BOOST_REFORM] = {
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/3.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
    },
    [BLOCK_TYPE_CRUMBLE] = {
        CONVERT_SECONDS(0),
        CONVERT_SECONDS(1/12.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/2.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
        CONVERT_SECONDS(1/15.f),
    },
};

const struct BombChainReverseData sBombChainReverseData[8] = {
    {
        .typeFlag = 1 << 0,
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_1
    },
    {
        .typeFlag = 1 << 1,
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_2
    },
    {
        .typeFlag = 1 << 2,
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_3
    },
    {
        .typeFlag = 1 << 3,
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_4
    },
    {
        .typeFlag = 1 << 4,
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_1
    },
    {
        .typeFlag = 1 << 5,
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_2
    },
    {
        .typeFlag = 1 << 6,
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_3
    },
    {
        .typeFlag = 1 << 7,
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_4
    }
};

const struct TankBehavior sTankBehaviors[BEHAVIOR_TANK_COUNT] = {
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .tankType = TANK_TYPE_ENERGY,
        .underwater = FALSE,
        .messageId = 0x12
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .tankType = TANK_TYPE_MISSILE,
        .underwater = FALSE,
        .messageId = 0x13
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .tankType = TANK_TYPE_POWER_BOMB,
        .underwater = FALSE,
        .messageId = 0x14
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .tankType = TANK_TYPE_NONE,
        .underwater = FALSE,
        .messageId = 0
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .tankType = TANK_TYPE_NONE,
        .underwater = FALSE,
        .messageId = 0
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .tankType = TANK_TYPE_NONE,
        .underwater = FALSE,
        .messageId = 0
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .tankType = TANK_TYPE_ENERGY,
        .underwater = TRUE,
        .messageId = 0x12
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .tankType = TANK_TYPE_MISSILE,
        .underwater = TRUE,
        .messageId = 0x13
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .tankType = TANK_TYPE_POWER_BOMB,
        .underwater = TRUE,
        .messageId = 0x14
    },
};

const s8 sSubBombChainPositionOffset[SUB_BOMB_CHAIN_REQUEST_COUNT][4] = {
    [SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_GOING_UP] = {
        1, 1, -1, 1
    },
    [SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_GOING_DOWN] = {
        1, -1, -1, -1
    },
    [SUB_BOMB_CHAIN_REQUEST_VERTICAL_GOING_LEFT] = {
        1, -1,  1, 1
    },
    [SUB_BOMB_CHAIN_REQUEST_VERTICAL_GOING_RIGHT] = {
        -1, -1, -1, 1
    }
};

// Offsets into y and x arrays
const u8 sBlockTouchOffsets[4][2] = {
    { 0, 0 }, // (center, right)
    { 0, 1 }, // (center, left)
    { 1, 2 }, // (bottom, center)
    { 2, 2 }, // (top, center)
};

// TODO: Move these

static const u8 sBlob_3c942c_3c94d0[] = INCBIN_U8("data/Blob_3c942c_3c94d0.bin");

const s8 sEndingSamusPosingSineTable[128] = {
    0, 6, 12, 19, 25, 31, 37, 43,
    49, 54, 60, 65, 71, 76, 81, 85,
    90, 94, 98, 102, 106, 109, 112, 115,
    117, 120, 122, 123, 125, 126, 126, 127,
    127, 127, 126, 126, 125, 123, 122, 120,
    117, 115, 112, 109, 106, 102, 98, 94,
    90, 85, 81, 76, 71, 65, 60, 54,
    49, 43, 37, 31, 25, 19, 12, 6,
    0, -6, -12, -19, -25, -31, -37, -43,
    -49, -54, -60, -65, -71, -76, -81, -85,
    -90, -94, -98, -102, -106, -109, -112, -115,
    -117, -120, -122, -123, -125, -126, -126, -127,
    -127, -127, -126, -126, -125, -123, -122, -120,
    -117, -115, -112, -109, -106, -102, -98, -94,
    -90, -85, -81, -76, -71, -65, -60, -54,
    -49, -43, -37, -31, -25, -19, -12, -6,
};

static const u8 sBlob_3c9550_3e392c[] = INCBIN_U8("data/Blob_3c9550_3e392c.bin");
