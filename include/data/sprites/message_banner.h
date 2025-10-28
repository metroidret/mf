#ifndef MESSAGE_BANNER_DATA_H
#define MESSAGE_BANNER_DATA_H

#include "macros.h"
#include "oam.h"

extern const u32 sMessageBannerGfx[512 * 2];
extern const u16 sMessageBannerPal[16 * 2];

extern const struct FrameData sMessageBannerYesNoCursorOam[5];
extern const struct FrameData sMessageBannerOam_PopUp[11];
extern const struct FrameData sMessageBannerOam_Removal[11];
extern const struct FrameData sMessageBannerOam_Static[2];

#endif /* MESSAGE_BANNER_DATA_H */
