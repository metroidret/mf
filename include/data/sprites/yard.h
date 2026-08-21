#ifndef YARD_DATA_H
#define YARD_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sYardGfx[512 * 3];
extern const u16 sYardPal[16 * 3];

extern const struct FrameData sYardOam_CrawlingHorizontal[4];
extern const struct FrameData sYardOam_ChargingHorizontal[6];
extern const struct FrameData sYardOam_ShootingHorizontal[7];
extern const struct FrameData sYardOam_RecoilHorizontal[4];
extern const struct FrameData sYardOam_StartledHorizontal[7];
extern const struct FrameData sYardOam_TurningAroundHorizontal1[4];
extern const struct FrameData sYardOam_TurningAroundHorizontal2[4];
extern const struct FrameData sYardOam_CrawlingVertical[4];
extern const struct FrameData sYardOam_ChargingVertical[6];
extern const struct FrameData sYardOam_ShootingVertical[7];
extern const struct FrameData sYardOam_RecoilVertical[4];
extern const struct FrameData sYardOam_StartledVertical[7];
extern const struct FrameData sYardOam_TurningAroundVertical1[4];
extern const struct FrameData sYardOam_TurningAroundVertical2[4];
extern const struct FrameData sYardProjectileOam_Moving[5];
extern const struct FrameData sYardOam_UninfectedHorizontal[2];
extern const struct FrameData sYardOam_UninfectedVertical[2];
extern const struct FrameData sYardProjectileOam_Exploding[4];

#endif /* YARD_DATA_H */
