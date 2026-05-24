#ifndef BOX_2_DATA_H
#define BOX_2_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sBox2BonkingSpeed[20];

enum Box2Oam {
    Box2Oam_395348,
    Box2Oam_3953c8,
    Box2Oam_395400,
    Box2Oam_395410,
    Box2Oam_395420,
    Box2Oam_395430,
    Box2Oam_395440,
    Box2Oam_395450,
    Box2Oam_395460,
    Box2Oam_395470,
    Box2Oam_395480,
    Box2Oam_395490,
    Box2Oam_3954a0,
    Box2Oam_3954b0,
    Box2Oam_395530,
    Box2Oam_395568,
    Box2Oam_395578,
    Box2Oam_395588,
    Box2Oam_395598,
    Box2Oam_3955a8,
    Box2Oam_3955b8,
    Box2Oam_3955c8,
    Box2Oam_3955d8,
    Box2Oam_3955e8,
    Box2Oam_3955f8,
    Box2Oam_395608,
    Box2Oam_395618,
    Box2Oam_395628,
    Box2Oam_395638,
    Box2Oam_395648,
    Box2Oam_395658,
    Box2Oam_3956b8,
    Box2Oam_3956f0,
    Box2Oam_395718,
    Box2Oam_395728,
    Box2Oam_395758,
    Box2Oam_395778,
    Box2Oam_395798,
    Box2Oam_3957a8,
    Box2Oam_3957b8,
    Box2Oam_3957c8,
    Box2Oam_3957d8,
    Box2Oam_3957e8,
    Box2Oam_395808,
    Box2Oam_395868,
    Box2Oam_3958c8,

    BOX_2_OAM_END
};

extern const u32 sBox2Oam_395348[32];
extern const u32 sBox2Oam_3953c8[14];
extern const u32 sBox2Oam_395400[4];
extern const u32 sBox2Oam_395410[4];
extern const u32 sBox2Oam_395420[4];
extern const u32 sBox2Oam_395430[4];
extern const u32 sBox2Oam_395440[4];
extern const u32 sBox2Oam_395450[4];
extern const u32 sBox2Oam_395460[4];
extern const u32 sBox2Oam_395470[4];
extern const u32 sBox2Oam_395480[4];
extern const u32 sBox2Oam_395490[4];
extern const u32 sBox2Oam_3954a0[4];
extern const u32 sBox2Oam_3954b0[32];
extern const u32 sBox2Oam_395530[14];
extern const u32 sBox2Oam_395568[4];
extern const u32 sBox2Oam_395578[4];
extern const u32 sBox2Oam_395588[4];
extern const u32 sBox2Oam_395598[4];
extern const u32 sBox2Oam_3955a8[4];
extern const u32 sBox2Oam_3955b8[4];
extern const u32 sBox2Oam_3955c8[4];
extern const u32 sBox2Oam_3955d8[4];
extern const u32 sBox2Oam_3955e8[4];
extern const u32 sBox2Oam_3955f8[4];
extern const u32 sBox2Oam_395608[4];
extern const u32 sBox2Oam_395618[4];
extern const u32 sBox2Oam_395628[4];
extern const u32 sBox2Oam_395638[4];
extern const u32 sBox2Oam_395648[4];
extern const u32 sBox2Oam_395658[24];
extern const u32 sBox2Oam_3956b8[14];
extern const u32 sBox2Oam_3956f0[10];
extern const u32 sBox2Oam_395718[4];
extern const u32 sBox2Oam_395728[12];
extern const u32 sBox2Oam_395758[8];
extern const u32 sBox2Oam_395778[8];
extern const u32 sBox2Oam_395798[4];
extern const u32 sBox2Oam_3957a8[4];
extern const u32 sBox2Oam_3957b8[4];
extern const u32 sBox2Oam_3957c8[4];
extern const u32 sBox2Oam_3957d8[4];
extern const u32 sBox2Oam_3957e8[8];
extern const u32 sBox2Oam_395808[24];
extern const u32 sBox2Oam_395868[24];
extern const u32 sBox2Oam_3958c8[4];

#define BOX2_OAM(name) ((const struct FrameData*)(name))

#endif /* BOX_2_DATA_H */