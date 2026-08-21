#ifndef ANIMATED_GRAPHICS_STRUCT_H
#define ANIMATED_GRAPHICS_STRUCT_H

#include "types.h"

struct AnimatedPaletteAndTileset {
    u8 animatedPalette;
    u8 animatedTileset;
};

struct AnimatedPaletteTiming {
    u8 timer1;
    s8 row1;
    u8 timer2;
    s8 row2;
};

struct HatchFlashAnimation {
    u8 coloredAnimTimer;
    s8 coloredAnimState;
    u8 unlockedAnimTimer;
    s8 unlockedAnimState;
};

extern u8 gUseAlternateAnimatedTilesetFlags[5];

extern struct AnimatedPaletteTiming gAnimatedPaletteTiming;

extern struct HatchFlashAnimation gHatchFlashAnimation;

extern struct AnimatedPaletteAndTileset gAnimatedPaletteAndTileset;

extern u8 gDisableAnimatedGraphicsTimer;

#endif /* ANIMATED_GRAPHICS_STRUCT_H */
