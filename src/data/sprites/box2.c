#include "data/sprites/box2.h"
#include "macros.h"

/* Box 2 (PSPRITE_BOX_2) frame data.
 * Each array is INCBIN-extracted from baserom; the embedded pFrame
 * pointers inside each FrameData entry remain raw baserom addresses
 * (level-3 OAM frame data is not yet extracted). To be replaced with
 * named pFrame symbols when the underlying OAM frames are decompiled.
 */

const u32 sBox2Oam_395348[32] = INCBIN_U32("data/sprites/box2/Box2Oam_395348.bin");
const u32 sBox2Oam_3953c8[14] = INCBIN_U32("data/sprites/box2/Box2Oam_3953c8.bin");
const u32 sBox2Oam_395400[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395400.bin");
const u32 sBox2Oam_395410[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395410.bin");
const u32 sBox2Oam_395420[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395420.bin");
const u32 sBox2Oam_395430[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395430.bin");
const u32 sBox2Oam_395440[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395440.bin");
const u32 sBox2Oam_395450[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395450.bin");
const u32 sBox2Oam_395460[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395460.bin");
const u32 sBox2Oam_395470[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395470.bin");
const u32 sBox2Oam_395480[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395480.bin");
const u32 sBox2Oam_395490[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395490.bin");
const u32 sBox2Oam_3954a0[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3954a0.bin");
const u32 sBox2Oam_3954b0[32] = INCBIN_U32("data/sprites/box2/Box2Oam_3954b0.bin");
const u32 sBox2Oam_395530[14] = INCBIN_U32("data/sprites/box2/Box2Oam_395530.bin");
const u32 sBox2Oam_395568[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395568.bin");
const u32 sBox2Oam_395578[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395578.bin");
const u32 sBox2Oam_395588[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395588.bin");
const u32 sBox2Oam_395598[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395598.bin");
const u32 sBox2Oam_3955a8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955a8.bin");
const u32 sBox2Oam_3955b8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955b8.bin");
const u32 sBox2Oam_3955c8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955c8.bin");
const u32 sBox2Oam_3955d8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955d8.bin");
const u32 sBox2Oam_3955e8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955e8.bin");
const u32 sBox2Oam_3955f8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3955f8.bin");
const u32 sBox2Oam_395608[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395608.bin");
const u32 sBox2Oam_395618[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395618.bin");
const u32 sBox2Oam_395628[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395628.bin");
const u32 sBox2Oam_395638[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395638.bin");
const u32 sBox2Oam_395648[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395648.bin");
const u32 sBox2Oam_395658[24] = INCBIN_U32("data/sprites/box2/Box2Oam_395658.bin");
const u32 sBox2Oam_3956b8[14] = INCBIN_U32("data/sprites/box2/Box2Oam_3956b8.bin");
const u32 sBox2Oam_3956f0[10] = INCBIN_U32("data/sprites/box2/Box2Oam_3956f0.bin");
const u32 sBox2Oam_395718[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395718.bin");
const u32 sBox2Oam_395728[12] = INCBIN_U32("data/sprites/box2/Box2Oam_395728.bin");
const u32 sBox2Oam_395758[8] = INCBIN_U32("data/sprites/box2/Box2Oam_395758.bin");
const u32 sBox2Oam_395778[8] = INCBIN_U32("data/sprites/box2/Box2Oam_395778.bin");
const u32 sBox2Oam_395798[4] = INCBIN_U32("data/sprites/box2/Box2Oam_395798.bin");
const u32 sBox2Oam_3957a8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3957a8.bin");
const u32 sBox2Oam_3957b8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3957b8.bin");
const u32 sBox2Oam_3957c8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3957c8.bin");
const u32 sBox2Oam_3957d8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3957d8.bin");
const u32 sBox2Oam_3957e8[8] = INCBIN_U32("data/sprites/box2/Box2Oam_3957e8.bin");
const u32 sBox2Oam_395808[24] = INCBIN_U32("data/sprites/box2/Box2Oam_395808.bin");
const u32 sBox2Oam_395868[24] = INCBIN_U32("data/sprites/box2/Box2Oam_395868.bin");
const u32 sBox2Oam_3958c8[4] = INCBIN_U32("data/sprites/box2/Box2Oam_3958c8.bin");

/* Leftover bytes of what used to be sBlob_388224_39f4b0.
 * Lives here so it sits at the right linker position between
 * the Box2 OAM data and electric_water_damage_box2.o(.rodata).
 * Will migrate out as the remaining sprites in this range
 * (frozen_ridley, mega_x, omega_metroid_husk, ...) get decompiled.
 * NOTE: non-static so agbcc does not dead-code-eliminate it.
 */
const u8 sBlob_3958d8_39f4b0[] = INCBIN_U8("data/Blob_3958d8_39f4b0.bin");
