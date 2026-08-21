#ifndef GENESIS_DATA_H
#define GENESIS_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGenesisGfx[512 * 2];
extern const u16 sGenesisPal[16 * 2];

extern const struct FrameData sGenesisOam_Walking[7];
extern const struct FrameData sGenesisOam_Running[7];
extern const struct FrameData sGenesisOam_37c3d0[4];
extern const struct FrameData sGenesisOam_37c3f0[4];
extern const struct FrameData sGenesisOam_37c410[4];
extern const struct FrameData sGenesisOam_37c430[4];
extern const struct FrameData sGenesisOam_Waiting[5];
extern const struct FrameData sGenesisOam_Skidding[2];
extern const struct FrameData sGenesisOam_TurningAround[2];
extern const struct FrameData sGenesisOam_Spitting[22];
extern const struct FrameData sGenesisSpitOam_Hanging[2];
extern const struct FrameData sGenesisSpitOam_Splashing[4];

#endif /* GENESIS_DATA_H */
