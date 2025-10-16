#ifndef WAVER_AI_H
#define WAVER_AI_H

#include "types.h"

u8 WaverCheckSamusInRange(void);
void WaverSetFlyingGFX(void);
void WaverInit(void);
void WaverFlyingInit(void);
void WaverFlying(void);
void WaverCharging(void);
void WaverCrashingInit(void);
void WaverCrashing(void);
void WaverBackingOut(void);
void WaverCheckBackingOutAnimEnded(void);
void WaverCheckTurningAnimNearEnded(void);
void WaverDebrisInit(void);
void WaverDebrisFalling(void);
void WaverDebrisExploding(void);
void Waver(void);
void WaverExplosion(void);

#endif /* WAVER_AI_H */