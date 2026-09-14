#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

#include "structs/block.h"

void BgClipCheckTouchingSpecialClipdata(void);
void BgClipCheckWalkingOnCrumbleBlock(void);
void BgClipCheckTouchingTransitionOnElevator(void);
void BgClipCheckTouchingTransitionOrTank(void);
void BgClipFinishCollectingTank(void);
void BgClipCheckOnCrumbleBlock(u16 yPosition, u16 xPosition);
void BgClipClearClipAndBg1BlockValue(u16 yPosition, u16 xPosition);
void BgClipSetBg1BlockValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetBg1BlockValueCommon(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetBg1TilemapValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipUpdateHatches(void);
void BgClipUpdateHatchAnimation(s32 slot);
void BgClipCheckGrabbingCrumbleBlock(boolu8 dontDestroy);
bools32 BgClipCheckProjectileHitHatch(u16 xPosition, u16 yPosition);
bools32 BgClipRevealHiddenTank(struct ClipdataBlockData* pBlock);
void BgClipUpdateSaXElevatorCutscene(boolu8 doorShot);
void BgClipSetTankAsCollected(u16 xPosition, u16 yPosition, u8 tankType);
s32 BgClipCountTanksWithinScreen(u16 xPosition, u16 yPosition);
void BgClipRemoveCollectedTanks(void);

#endif /* BG_CLIP_H */
