#include "data/color_fading_data.h"

static const u8 sColorFadingSpeedFaster[8] = {
    3, 7, 11, 15, 19, 23, 27, 32
};

static const u8 sColorFadingSpeedFast[16] = {
    2, 4, 6, 8, 10, 12, 14, 16,
    18, 20, 22, 24, 26, 28, 30, 32
};

static const u8 sColorFadingSpeedNormal[32] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32
};

static const u8 sColorFadingSpeedSlow[60] = {
    1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7,
    7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 10, 11, 11, 12, 12, 13,
    13, 14, 14, 15, 15, 16, 16, 17,
    17, 18, 19, 20, 21, 22, 23, 24,
    26, 28, 30, 32,
};

const struct ColorFadingColorInfo sColorFadingSpeeds[COLOR_FADING_SPEED_COUNT] = {
    [COLOR_FADING_SPEED_FASTER] = {
        .colorArray = sColorFadingSpeedFaster,
        .size = ARRAY_SIZE(sColorFadingSpeedFaster)
    },
    [COLOR_FADING_SPEED_FAST] = {
        .colorArray = sColorFadingSpeedFast,
        .size = ARRAY_SIZE(sColorFadingSpeedFast)
    },
    [COLOR_FADING_SPEED_NORMAL] = {
        .colorArray = sColorFadingSpeedNormal,
        .size = ARRAY_SIZE(sColorFadingSpeedNormal)
    },
    [COLOR_FADING_SPEED_SLOW] = {
        .colorArray = sColorFadingSpeedSlow,
        .size = ARRAY_SIZE(sColorFadingSpeedSlow)
    },
};

const struct ColorMultiplier sMonochromeMultiplier = {
    .red = 1,
    .green = 1,
    .blue = 1
};
