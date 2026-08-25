#ifndef SA_X_MONSTER_AI_H
#define SA_X_MONSTER_AI_H

#include "types.h"

void SaXMonsterSyncSubSprites(void);
void SaXMonsterProjectilesCollision(void);
bools32 SaXMonsterCheckScream(boolu8 airborne);
void SaXMonsterXMovement(boolu8 checkSamusPosition);
void SaXMonsterSetSideHitboxes(void);
void SaXMonsterFallingMovement(void);
void SaXMonsterSpawningFromX(void);
void SaXMonsterInit(void);
void SaXMonsterDroppingInit(void);
void SaXMonsterDropping(void);
void SaXMonsterIdleInit(void);
void SaXMonsterIdle(void);
void SaXMonsterJumpWarningInit(void);
void SaXMonsterJumpWarning(void);
void SaXMonsterJumping(void);
void SaXMonsterFallingInit(void);
void SaXMonsterFalling(void);
void SaXMonsterLandingInit(void);
void SaXMonsterLanding(void);
void SaXMonsterTurningAroundInit(void);
void SaXMonsterTurningAround(void);
void SaXMonsterScreamingAirborneInit(void);
void SaXMonsterScreamingAirborne(void);
void SaXMonsterScreamingGroundedInit(void);
void SaXMonsterScreamingGrounded(void);
void SaXMonsterPanting(void);
void SaXMonsterDying(void);
void SaXMonsterTurningIntoCoreX(void);

void SaXMonsterPartInit(void);
void SaXMonsterPartIdle(void);

void SaXMonster(void);
void SaXMonsterPart(void);

#endif /* SA_X_MONSTER_AI_H */
