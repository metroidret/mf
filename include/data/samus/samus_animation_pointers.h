#include "types.h"
#include "structs/samus.h"
#include "oam.h"
#include "constants/samus.h"

extern const u8 sSamusGenericData_Empty[40];
extern const struct SamusData sSamusData_Empty;
extern const struct Equipment sEquipment_Empty;

extern const struct SamusAnimData* const sSamusAnimPointers_Default[SPOSE_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Standing[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Turning[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Shooting[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Running[ACD_END - 2][2];
extern const struct SamusAnimData* const sSamusAnimPointers_MidAir[ACD_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_TurningMidAir[ACD_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Landing[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Crouching[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_TurningAndCrouching[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_ShootingAndCrouching[ACD_END - 1][2];
extern const struct SamusAnimData* const sSamusAnimPointers_HangingOnLedge[2][2];

extern const struct FrameData* const sArmCannonOamPointers_ScrewAttacking[2];

extern const struct SamusAnimData* const sSamusAnimPointers_Skidding[2][2];
extern const struct SamusAnimData* const sSamusAnimPointers_Shinesparking[3][2];
extern const struct SamusAnimData* const sSamusAnimPointers_DelayAfterShinesparking[3][2];
extern const struct SamusAnimData* const sSamusAnimPointers_ArmOutOnVerticalLadder[ACD_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_ShootingOnVerticalLadder[ACD_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_AfterShootingOnHorizontalLadder[ACD_END][2];
extern const struct SamusAnimData* const sSamusAnimPointers_ShootingOnHorizontalLadder[ACD_END][2];

extern const struct FrameData* const sArmCannonOamPointers_UnlockingSecurity[2];
extern const struct FrameData* const sArmCannonOamPointers_Dying[2];

extern const struct SamusAnimData* const sSamusAnimPointers_HitByOmegaMetroid[2][2];

extern const u8 sSamusCollisionData[SPOSE_END][SCDF_COUNT];

extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Default[SPOSE_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Standing[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Turning[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Shooting[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Running[ACD_END - 2][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_MidAir[ACD_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_TurningMidAir[ACD_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Landing[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Crouching[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_TurningAndCrouching[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_ShootingAndCrouching[ACD_END - 1][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_HangingOnLedge[2][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_Shinesparking[3][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_DelayAfterShinesparking[3][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_OnVerticalLadder[ACD_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_ShootingOnVerticalLadder[ACD_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_AfterShootingOnHorizontalLadder[ACD_END][2];
extern const struct ArmCannonAnimData* const sArmCannonAnimPointers_ShootingOnHorizontalLadder[ACD_END][2];
