#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

#include "constants/color_fading.h"

// Structs

struct ColorFading {
   ColorFadingEffect type;
   u8 stage;
   u8 fadeTimer;
   u8 unk_3;
   ColorFadingStatus status;
   bools8 useSecondColorSet; // Possibly part of a bit field
   u16 workTimer;
};

// Globals

extern struct ColorFading gColorFading;

#endif /* COLOR_EFFECTS_STRUCT_H */
