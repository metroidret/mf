#ifndef ROOM_EFFECT_H
#define ROOM_EFFECT_H

#include "types.h"

void RoomEffectSetTransparency(void);
u32 RoomEffectGetBgSizeFlag(u8 bgProp);
u32 unk_62cb4(void);

bools32 RoomEffectCheckRoomIsDim(void);
bools32 RoomEffectCheckMainElevatorIsActive(void);
bools32 RoomEffectCheckSetMeltdownEffect(void); 
bools32 RoomEffectCheckRoomIsDark(void);

bools32 RoomEffectFade(u8 arg0);

void RoomEffectStartHatchLockAnimation(u8 hatch, u8 arg1, u8 newState);
void RoomEffectLockHatches(u8 hatchesToLock);
void RoomEffectLockHatchesWithTimer(u8 hatchesToLock);

void RoomEffectRecoveringSuitInit(void);

void RoomEffectSetCurrentNavigationRoom(u8 room);
bools32 RoomEffectDetermineNavigationRoomHatchesToLock(void);

void RoomEffectCheckSetCurrentEventBased(void);
void RoomEffectSetCurrentEventBased(u8 effect);
void RoomEffectSetupCurrentEventBased(void);
void RoomEffectStartStopEventBased(u8 effect);
void RoomEffectUpdateEventBased(void);
void RoomEffectCheckStopEventBased(void);
void RoomEffectProcessEventBased(void);

void RoomEffectCheckUnlockHatches(void);
bools32 RoomEffectCheckHatchLockEvents(void);
void RoomEffectCheckLockHatchesWithTimer(void);
void RoomEffectCheckUnlockProximityHatches(void);

bools32 RoomEffectRecoveringSuitCutscene(void);
u16 RoomEffectCalculateSuitFlashOffset(u8 maxDist, u8 pos1, u8 pos2);

bools32 RoomEffectProcessOperationsRoom(void);
void RoomEffectProcessOmegaMetroidRoom(void);

#endif /* ROOM_EFFECT_H */
