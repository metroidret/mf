#ifndef ANIMALS_DATA_H
#define ANIMALS_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const s16 sAnimalsLeavingEnclosureYSpeeds[13];

extern const u32 sAnimalsGfx[512 * 4];
extern const u16 sAnimalsPal[PAL_ROW * 4];

extern const struct FrameData sEtecoonOam_Standing_Foreground_Still[2];
extern const struct FrameData sEtecoonOam_Standing_Foreground[5];
extern const struct FrameData sEtecoonOam_Standing[2];
extern const struct FrameData sEtecoonOam_Running[5];
extern const struct FrameData sEtecoonOam_Turning[2];
extern const struct FrameData sEtecoonOam_TurningHead[9];
extern const struct FrameData sEtecoonOam_JumpingOnGlass[11];
extern const struct FrameData sEtecoonOam_JumpingToTire[11];
extern const struct FrameData sEtecoonOam_Hanging_Start[5];
extern const struct FrameData sEtecoonOam_Hanging[5];
extern const struct FrameData sEtecoonOam_HangingAndTurning[5];
extern const struct FrameData sEtecoonOam_FallingFromTire[5];

extern const struct FrameData sTireSwingOam_Idle[2];
extern const struct FrameData sTireSwingOam_Bobbing_Fast[4];
extern const struct FrameData sTireSwingOam_Bobbing_Slow[4];
extern const struct FrameData sTireSwingOam_EtecoonLeaving[10];

extern const struct FrameData sDachoraOam_Standing[2];
extern const struct FrameData sDachoraOam_Running[7];
extern const struct FrameData sDachoraOam_Turning_Start[3];
extern const struct FrameData sDachoraOam_Turning_End[3];
extern const struct FrameData sDachoraOam_Bowing[8];
extern const struct FrameData sDachoraOam_Blinking[4];
extern const struct FrameData sDachoraOam_TiltingHead[3];
extern const struct FrameData sDachoraOam_TurningHead[4];

extern const struct FrameData sBabyDachoraOam_Standing[2];
extern const struct FrameData sBabyDachoraOam_Walking[5];
extern const struct FrameData sBabyDachoraOam_Blinking[4];

extern const struct FrameData sHabitationGateLightOam_Idle[2];

extern const struct FrameData sHabitationGateOam_Idle[2];
extern const struct FrameData sHabitationGateOam_Opening[7];

extern const struct FrameData sDachoraOam_Waiting[5];
extern const struct FrameData sBabyDachoraOam_Waiting[5];
extern const struct FrameData sEtecoonOam_Waiting[5];
extern const struct FrameData sHabitationGateLightOam_Flashing[3];

#endif /* ANIMALS_DATA_H */
