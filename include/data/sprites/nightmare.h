#ifndef NIGHTMARE_DATA_H
#define NIGHTMARE_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum NightmareOam {
    NIGHTMARE_OAM_PART_BODY,
    NIGHTMARE_OAM_PART_EYE_SLUDGE,
    NIGHTMARE_OAM_PART_EYE_SLUDGE_DROPPING_TO_CHIN,
    NIGHTMARE_OAM_PART_CHIN_SLUDGE,
    NIGHTMARE_OAM_BEAM,
    NIGHTMARE_OAM_EXPLOSION_UNUSED,
    NIGHTMARE_OAM_PART_EYE_NOT_DROOPING,
    NIGHTMARE_OAM_PART_MOUTH_NOT_DROOPING,
    NIGHTMARE_OAM_PART_EYE_DROOPING_SLIGHTLY,
    NIGHTMARE_OAM_PART_MOUTH_DROOPING_SLIGHTLY,
    NIGHTMARE_OAM_PART_EYE_DROOPING_MORE,
    NIGHTMARE_OAM_PART_MOUTH_DROOPING_MORE,
    NIGHTMARE_OAM_PART_EYE_AND_MOUTH_DROOPING_SLIGHTLY,
    NIGHTMARE_OAM_PART_EYE_AND_MOUTH_DROOPING_MORE,
    NIGHTMARE_OAM_PART_X,
    NIGHTMARE_OAM_PART_GENERATOR_STATIONARY,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_VERY_FAST,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_FAST,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_SLIGHTLY_FAST,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_SLIGHTLY_SLOW,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_SLOW,
    NIGHTMARE_OAM_PART_GENERATOR_SPINNING_VERY_SLOW,
    NIGHTMARE_OAM_PART_RIGHT_ARM_TOP,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_1_IDLE,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_2_IDLE,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_3_IDLE,
    NIGHTMARE_OAM_PART_RIGHT_ARM_BOTTOM,
    NIGHTMARE_OAM_PART_LEFT_TURRET_1_IDLE,
    NIGHTMARE_OAM_PART_LEFT_TURRET_2_IDLE,
    NIGHTMARE_OAM_PART_LEFT_TURRET_3_IDLE,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_1_FIRING,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_2_FIRING,
    NIGHTMARE_OAM_PART_RIGHT_TURRET_3_FIRING,
    NIGHTMARE_OAM_PART_LEFT_TURRET_1_FIRING,
    NIGHTMARE_OAM_PART_LEFT_TURRET_2_FIRING,
    NIGHTMARE_OAM_PART_LEFT_TURRET_3_FIRING,
    NIGHTMARE_OAM_SLUDGE_FALLING,
    NIGHTMARE_OAM_SLUDGE_EXPLODING,

    NIGHTMARE_OAM_END
};

enum NightmarePart {
    NIGHTMARE_PART_CHIN_SLUDGE,
    NIGHTMARE_PART_EYE_SLUDGE,
    NIGHTMARE_PART_EYE,
    NIGHTMARE_PART_MOUTH,
    NIGHTMARE_PART_RIGHT_ARM_TOP,
    NIGHTMARE_PART_RIGHT_TURRET_1,
    NIGHTMARE_PART_RIGHT_TURRET_2,
    NIGHTMARE_PART_RIGHT_TURRET_3,
    NIGHTMARE_PART_RIGHT_ARM_BOTTOM,
    NIGHTMARE_PART_GENERATOR,
    NIGHTMARE_PART_BODY,
    NIGHTMARE_PART_LEFT_TURRET_1,
    NIGHTMARE_PART_LEFT_TURRET_2,
    NIGHTMARE_PART_LEFT_TURRET_3,

    NIGHTMARE_PART_END
};

enum NighmareFallingPart {
    NIGHTMARE_FALLING_PART_RIGHT_ARM_TOP,
    NIGHTMARE_FALLING_PART_RIGHT_TURRET_1,
    NIGHTMARE_FALLING_PART_RIGHT_TURRET_2,
    NIGHTMARE_FALLING_PART_RIGHT_TURRET_3,
    NIGHTMARE_FALLING_PART_RIGHT_ARM_BOTTOM,
    NIGHTMARE_FALLING_PART_LEFT_TURRET_1,
    NIGHTMARE_FALLING_PART_LEFT_TURRET_2,
    NIGHTMARE_FALLING_PART_LEFT_TURRET_3,

    NIGHTMARE_FALLING_PART_END
};

extern const s16 sNightmarePhase2XSpeed[13];
extern const s16 sNightmarePhase2YSpeed[32];
extern const u8 sNightmareGeneratorGlowingPaletteRow[8];

extern const struct MultiSpriteData sNightmareMultiSpriteData_3b82fc[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b8344[3];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b835c[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b83a4[3];
extern const struct MultiSpriteData sNightmareMultiSpriteData[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b8404[3];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b841c[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b8464[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b84ac[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b84f4[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b853c[9];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b8584[3];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b859c[3];
extern const struct MultiSpriteData sNightmareMultiSpriteData_3b85b4[3];

extern const u32 sNightmareGfx[512 * 8];
extern const u16 sNightmarePal[16 * 8];

extern const struct FrameData sNightmarePartBodyOam[2];
extern const struct FrameData sNightmarePartOam_EyeSludge[6];
extern const struct FrameData sNightmarePartOam_EyeSludgeDroppingToChin[11];
extern const struct FrameData sNightmarePartOam_ChinSludge[5];
extern const struct FrameData sNightmareBeamOam[2];
extern const struct FrameData sNightmareExplosionOam_Unused[5];
extern const struct FrameData sNightmarePartEyeOam_NotDrooping[5];
extern const struct FrameData sNightmarePartMouthOam_NotDrooping[11];
extern const struct FrameData sNightmarePartEyeOam_DroopingSlightly[5];
extern const struct FrameData sNightmarePartMouthOam_DroopingSlightly[11];
extern const struct FrameData sNightmarePartEyeOam_DroopingMore[5];
extern const struct FrameData sNightmarePartMouthOam_DroopingMore[11];
extern const struct FrameData sNightmarePartEyeAndMouthOam_DroopingSlightly[3];
extern const struct FrameData sNightmarePartEyeAndMouthOam_DroopingMore[3];
extern const struct FrameData sNightmarePartOam_X[2];
extern const struct FrameData sNightmarePartGeneratorOam_Stationary[2];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningVeryFast[4];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningFast[4];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningSlightlyFast[4];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningSlightlySlow[4];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningSlow[4];
extern const struct FrameData sNightmarePartGeneratorOam_SpinningVerySlow[4];
extern const struct FrameData sNightmarePartOam_RightArmTop[2];
extern const struct FrameData sNightmarePartOam_RightTurret1Idle[2];
extern const struct FrameData sNightmarePartOam_RightTurret2Idle[2];
extern const struct FrameData sNightmarePartOam_RightTurret3Idle[2];
extern const struct FrameData sNightmarePartOam_RightArmBottom[2];
extern const struct FrameData sNightmarePartOam_LeftTurret1Idle[2];
extern const struct FrameData sNightmarePartOam_LeftTurret2Idle[2];
extern const struct FrameData sNightmarePartOam_LeftTurret3Idle[2];
extern const struct FrameData sNightmarePartOam_RightTurret1Firing[15];
extern const struct FrameData sNightmarePartOam_RightTurret2Firing[15];
extern const struct FrameData sNightmarePartOam_RightTurret3Firing[15];
extern const struct FrameData sNightmarePartOam_LeftTurret1Firing[15];
extern const struct FrameData sNightmarePartOam_LeftTurret2Firing[15];
extern const struct FrameData sNightmarePartOam_LeftTurret3Firing[15];
extern const struct FrameData sNightmareSludgeOam_Falling[2];
extern const struct FrameData sNightmareSludgeOam_Exploding[5];
extern const struct FrameData sNightmarePartOam_RightTurret1NotFiring[15];
extern const struct FrameData sNightmarePartOam_RightTurret2NotFiring[15];
extern const struct FrameData sNightmarePartOam_RightTurret3NotFiring[15];
extern const struct FrameData sNightmarePartOam_LeftTurret1NotFiring[15];
extern const struct FrameData sNightmarePartOam_LeftTurret2NotFiring[15];
extern const struct FrameData sNightmarePartOam_LeftTurret3NotFiring[15];

#endif /* NIGHTMARE_DATA_H */
