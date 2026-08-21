#ifndef ZAZABI_AI_H
#define ZAZABI_AI_H

#include "types.h"

enum ZazabiPart {
    ZAZABI_PART_MOUTH_FRONT,
    ZAZABI_PART_MOUTH_BACK,
    ZAZABI_PART_HAIR,
    ZAZABI_PART_EYE_SHELL,
    ZAZABI_PART_PUPIL,
    ZAZABI_PART_EYE,
    ZAZABI_PART_UPPER_SHELL,
    ZAZABI_PART_MIDDLE_SHELL,
    ZAZABI_PART_LOWER_SHELL,

    ZAZABI_PART_END,
};

void ZazabiSyncSubSprites(void);
void ZazabiProjectilesCollision(void);
void ZazabiEnableProjectilesToPassThrough(void);
void Zazabi_Empty(void);
u8 ZazabiXMovement(u16 movement);
void ZazabiSpawningFromX(void);
void ZazabiInit(void);
void ZazabiIdleInit(void);
void ZazabiIdle(void);
void ZazabiCrawlingInit(void);
void ZazabiCrawling(void);
void ZazabiJumpWarningInit(void);
void ZazabiJumpWarning(void);
void ZazabiJumpingInit(void);
void ZazabiJumping(void);
void ZazabiFallingInit(void);
void ZazabiFalling(void);
void ZazabiLandingMouthOpenInit(void);
void ZazabiLandingMouthOpen(void);
void ZazabiLandingInit(void);
void ZazabiLanding(void);
void ZazabiEatingSamus1Init(void);
void ZazabiEatingSamus1(void);
void ZazabiEatingSamus2Init(void);
void ZazabiEatingSamus2(void);
void ZazabiEatingSamus3Init(void);
void ZazabiEatingSamus3(void);
void ZazabiEatingSamus4Init(void);
void ZazabiEatingSamus4(void);
void ZazabiEatingSamus5Init(void);
void ZazabiEatingSamus5(void);
void ZazabiSpittingSamusInit(void);
void ZazabiSpittingSamus(void);
void ZazabiLandingAfterSpittingInit(void);
void ZazabiLandingAfterSpitting(void);
void ZazabiDyingInit(void);
void ZazabiDying(void);
void ZazabiPartInit(void);
void ZazabiPartDefault(void);
void ZazabiPartMouth(void);
void ZazabiPartPupil(void);
void Zazabi(void);
void ZazabiPart(void);

#endif /* ZAZABI_AI_H */
