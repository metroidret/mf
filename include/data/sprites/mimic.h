#ifndef MIMIC_DATA_H
#define MIMIC_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMimicFlyingYMovement[65];

extern const u32 sMimicEnergyTankGfx[1 * 512];
extern const u16 sMimicEnergyTankPal[1 * 16];

extern const struct FrameData sMimicEnergyTankOam_Idle[5];
extern const struct FrameData sMimicEnergyTankOam_WakingUp[7];
extern const struct FrameData sMimicEnergyTankOam_Flying[5];

extern const u32 sMimicMissileTankGfx[1 * 512];
extern const u16 sMimicMissileTankPal[1 * 16];

extern const struct FrameData sMimicMissileTankOam_Idle[5];
extern const struct FrameData sMimicMissileTankOam_WakingUp[8];
extern const struct FrameData sMimicMissileTankOam_Flying[5];

#endif /* MIMIC_DATA_H */
