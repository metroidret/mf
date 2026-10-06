#ifndef POWER_BOMB_STRUCTS_H
#define POWER_BOMB_STRUCTS_H

#include "types.h"
#include "oam.h"

MAKE_ENUM(u8, PowerBombState) {
    PB_STATE_NONE,
    PB_STATE_UNK_1,
    PB_STATE_UNK_2,
    PB_STATE_EXPLODING,
    PB_STATE_IMPLODING,
    PB_STATE_ENDING
};

struct PowerBomb {
    u8 animationState;
    u8 stage;
    u8 semiMinorAxis;
    u8 unk_3;
    u16 xPosition;
    u16 yPosition;
    s16 hitboxLeft;
    s16 hitboxRight;
    s16 hitboxTop;
    s16 hitboxBottom;
    u8 powerBombPlaced;
    boolu8 ownedBySaX;
    u8 unk_12;
};

extern struct PowerBomb gCurrentPowerBomb;

#endif /* POWER_BOMB_STRUCTS_H */
