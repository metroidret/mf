#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#include "types.h"
#include "constants/sprite.h"

#define GET_PSPRITE_HEALTH(id) sPrimarySpriteStats[(id)][0]
#define GET_SSPRITE_HEALTH(id) sSecondarySpriteStats[(id)][0]

#define GET_PSPRITE_DAMAGE(id) sPrimarySpriteStats[(id)][1]
#define GET_SSPRITE_DAMAGE(id) sSecondarySpriteStats[(id)][1]

#define GET_PSPRITE_SUIT_REDUCTION(id) sPrimarySpriteStats[(id)][2]
#define GET_SSPRITE_SUIT_REDUCTION(id) sSecondarySpriteStats[(id)][2]

#define GET_PSPRITE_WEAKNESS(id) sPrimarySpriteStats[(id)][3]
#define GET_SSPRITE_WEAKNESS(id) sSecondarySpriteStats[(id)][3]

#define SPRITE_GFX_SIZE(nbrRows) ((nbrRows) * 32 * 256 / 4)

extern const u8 sOamXFlipOffsets[3][4];
extern const u8 sOamYFlipOffsets[3][4];

extern const u8 sRandomNumberTable[32];
extern const u16 sSuitDamageReductionPercent[SDRT_END][SDR_END];

extern const s16 sSpritesFallingSpeedHovering[20];
extern const s16 sSpritesFallingSpeedMissileHatchDebris[16];
extern const s16 sSpritesFallingSpeed_2e499c[18];
extern const s16 sSpritesFallingSpeedCeiling[16];
extern const s16 sSpritesFallingSpeed[16];
extern const s16 sSpritesFallingSpeedQuickAcceleration[8];
extern const s16 sSpritesFallingSpeedSlow[16];
extern const s16 sSpritesFallingSpeedFast[16];

extern const u32 sSpritesGraphicsLength[PSPRITE_END - 0x10];

extern const u16 sPrimarySpriteStats[PSPRITE_END][7];
extern const u16 sSecondarySpriteStats[SSPRITE_END][4];

#endif /* SPRITE_DATA_H */
