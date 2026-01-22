#ifndef ZOZORO_DATA_H
#define ZOZORO_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sZozoroGfx[2 * 512];
extern const u16 sZozoroPal[1 * 16];

extern const struct FrameData sZozoroOam_CrawlingGround[6];
extern const struct FrameData sZozoroOam_CrawlingGroundFast[7];
extern const struct FrameData sZozoroOam_TurningAroundGround[5];
extern const struct FrameData sZozoroOam_CrawlingWall[6];
extern const struct FrameData sZozoroOam_CrawlingWallFast[7];
extern const struct FrameData sZozoroOam_TurningAroundWall[5];
extern const struct FrameData sZozoroOam_CrawlingSlightUpwardsSlope[6];
extern const struct FrameData sZozoroOam_CrawlingSlightUpwardsSlopeFast[6];
extern const struct FrameData sZozoroOam_CrawlingSlightDownwardsSlope[6];
extern const struct FrameData sZozoroOam_CrawlingSlightDownwardsSlopeFast[6];
extern const struct FrameData sZozoroOam_CrawlingSteepUpwardsSlope[6];
extern const struct FrameData sZozoroOam_CrawlingSteepUpwardsSlopeFast[6];
extern const struct FrameData sZozoroOam_CrawlingSteepDownwardsSlope[6];
extern const struct FrameData sZozoroOam_CrawlingSteepDownwardsSlopeFast[6];
extern const struct FrameData sZozoroOam_IdleGround[6];
extern const struct FrameData sZozoroOam_IdleWall[6];
extern const struct FrameData sZozoroOam_StartFalling[5];
extern const struct FrameData sZozoroOam_Landing[5];

#endif /* ZOZORO_DATA_H */
