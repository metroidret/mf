#include "types.h"

#include "data/empty_data.h"

const struct RawCoordsX sRawCoordsX_Empty = {
    .x = USHORT_MAX,
    .y = USHORT_MAX
};

const struct BrokenBlock sBrokenBlock_Empty = {
    .stage = 0,
    .timer = 0,
    .xPosition = 0,
    .yPosition = 0
};

const struct BombChain sBombChain_Empty = {
    .currentOffset = 0,
    .srcXPosition = 0,
    .srcYPosition = 0,
    .type = 0,
    .padding = 0,
    .negativeActive = FALSE,
    .positiveActive = FALSE
};

const struct HatchData sHatchData_Empty = {
    .exists = FALSE,
    .currentAnimation = 0,
    .facingRight = FALSE,
    .lockType = HATCH_LOCK_GRAY,
    .state = 0,
    .locked = FALSE,
    .unk_1_3 = 0,
    .xPosition = 0,
    .yPosition = 0
};

const struct PowerBomb sPowerBomb_Empty = {
    .animationState = 0,
    .unk_1 = 0,
    .semiMinorAxis = 0,
    .unk_3 = 0,
    .xPosition = 0,
    .yPosition = 0,
    .hitboxLeft = 0,
    .hitboxRight = 0,
    .hitboxTop = 0,
    .hitboxBottom = 0,
    .powerBombPlaced = 0,
    .ownedBySaX = FALSE,
    .unk_12 = 0
};

const struct ScreenShake sScreenShake_Empty = {
    .timer = 0,
    .delay = 0,
    .intensity = 0,
    .direction = 0
};

const struct Bg0Movement sBg0Movement_Empty = {
    .type = 0,
    .counter = 0,
    .unused = 0,
    .xOffset = 0,
    .yOffset = 0
};

const struct Bg3Movement sBg3Movement_Empty = {
    .direction = 0,
    .timer = 0,
    .leftToRightStage = 0,
    .xOffset = 0
};

const struct Unk_3004e30 sUnk_3c88dc = {
    .unk_0 = 0,
    .unk_1 = 0,
    .unk_2 = 0,
    .unk_3 = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0
};

const struct WaterMovement sWaterMovement_Empty = {
    .moving = 0,
    .unk_1 = 0,
    .stage = 0,
    .yOffset = 0,
    .unk_6 = 0,
    .unk_8 = 0
};
