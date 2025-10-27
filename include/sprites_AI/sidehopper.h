#ifndef SIDEHOPPER_AI_H
#define SIDEHOPPER_AI_H

#include "types.h"

u8 SidehopperCheckSamusInRange(void);
void SidehopperInit(void);
void SidehopperPreparingtoJumpInit(void);
void SidehopperJumpingInit(void);
void SidehopperLandingInit(void);
void SidehopperIdleInit(void);
void SidehopperFallingInit(void);
void SidehopperPreparingToJumpGround(void);
void SidehopperPreparingToJumpCeiling(void);
void SidehopperJumpingGround(void);
void SidehopperJumpingCeiling(void);
void SidehopperCheckLandingAnimEnded(void);
void SidehopperFallingGround(void);
void SidehopperFallingCeiling(void);
void SidehopperIdleGround(void);
void SidehopperIdleCeiling(void);
void Sidehopper(void);

#endif /* SIDEHOPPER_AI_H */
