#ifndef ANIMATED_GRAPHICS_STRUCT_H
#define ANIMATED_GRAPHICS_STRUCT_H

#include "types.h"

struct AnimatedPaletteAndTileset {
    u8 animatedPalette;
    u8 animatedTileset;
};

struct AnimatedTiming {
    u8 timer;
    u8 frame;
    u8 unk_2;
};

struct AnimatedPaletteTiming {
    u8 timer1;
    s8 row1;
    u8 timer2;
    s8 row2;
};

struct AnimatedGraphicsInfo {
    u8 type;
    u8 framesPerState;
    u8 animationDurationCounter;
    u8 numberOfStates;
    s8 currentAnimationFrame;
    u8 graphicsEntry;
    const u8* pGraphics;
};

struct AnimatedGraphicsData {
    u8 type;
    u8 framesPerState;
    u8 numberOfStates;
    const u8* const pGraphics;
};

struct HatchFlashAnimation {
    u8 coloredAnimTimer;
    s8 coloredAnimState;
    u8 unlockedAnimTimer;
    s8 unlockedAnimState;
};

extern u8 gUseAlternateAnimatedTilesetFlags[5];

extern struct AnimatedTiming gTankAnimations[3];
extern struct AnimatedGraphicsInfo gAnimatedGraphicsData[16];
extern struct AnimatedPaletteTiming gAnimatedPaletteTiming;

extern struct HatchFlashAnimation gHatchFlashAnimation;

extern struct AnimatedPaletteAndTileset gAnimatedPaletteAndTileset;

extern u8 gDisableAnimatedGraphicsTimer;
extern u16 gAnimatedGraphicsToUpdate;

#endif /* ANIMATED_GRAPHICS_STRUCT_H */
