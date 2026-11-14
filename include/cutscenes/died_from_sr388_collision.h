#ifndef DIED_FROM_SR388_COLLISION_CUTSCENE
#define DIED_FROM_SR388_COLLISION_CUTSCENE

#include "types.h"
#include "macros.h"

#include "structs/cutscene.h"

MAKE_ENUM(u8, DiedOnSr388CollisionStage) {
	DIED_ON_SR388_COLLISION_STAGE_INIT,
	DIED_ON_SR388_COLLISION_STAGE_FADE_IN,
	DIED_ON_SR388_COLLISION_STAGE_PROCESS,
	DIED_ON_SR388_COLLISION_STAGE_FADE_OUT
};

MAKE_ENUM(u8, DiedOnSr388CollisionSubstage) {
	DIED_ON_SR388_COLLISION_SUBSTAGE_FADE_IN,
	DIED_ON_SR388_COLLISION_SUBSTAGE_BSL_FALLING,
	DIED_ON_SR388_COLLISION_SUBSTAGE_EXPLOSION_INIT,
	DIED_ON_SR388_COLLISION_SUBSTAGE_EXPLOSION,
	DIED_ON_SR388_COLLISION_SUBSTAGE_FADE_OUT
};

MAKE_ENUM(u8, DiedOnSr388CollisionOamType) {
	DIED_ON_SR388_COLLISION_OAM_TYPE_NONE,
	DIED_ON_SR388_COLLISION_OAM_TYPE_FALLING_BSL,
	DIED_ON_SR388_COLLISION_OAM_TYPE_REENTRY_PLASMA,
	DIED_ON_SR388_COLLISION_OAM_TYPE_REENTRY_DEBRIS
};

boolu32 DiedOnSr388CollisionHandler(void);
void DiedOnSr388CollisionInit(void);
boolu32 DiedOnSr388CollisionProcess(void);
boolu32 DiedOnSr388Collision(void);
void DiedOnSr388CollisionProcessFallingBsl(struct SpecialCutsceneOam* pOam);
void DiedOnSr388CollisionProcessReentryDebris(struct SpecialCutsceneOam* pOam);
u8 DiedOnSr388CollisionSetupOam(DiedOnSr388CollisionOamType type, s16 xPosition, s16 yPosition, u8 descendingSearch);
void DiedOnSr388CollisionVblank(void);
void DiedOnSr388CollisionVblank_Unused(void);
u8 DiedOnSr388CollisionGetPositionAndSlotOfOamByType(DiedOnSr388CollisionOamType type, s16* pXPosition, s16* pYPosition);
void unk_97dcc(void);

#endif /* DIED_FROM_SR388_COLLISION_CUTSCENE */
