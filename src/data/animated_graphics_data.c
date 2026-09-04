#include "data/animated_graphics_data.h"

#include "macros.h"

#include "data/animated_tiles_data.h"

const struct AnimatedGraphicsData sAnimatedGraphicsEntries[ANIMATED_GFX_ID_COUNT] = {
    [ANIMATED_GFX_ID_CRYSTAL] = {
        .type = ANIMATED_GFX_TYPE_NONE,
        .framesPerState = 0,
        .numberOfStates = 0,
        .pGraphics = &sAnimatedTilesGfx[0 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_SURFACE] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[134 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_DEPTH_1] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[138 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_DEPTH_2] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[142 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_DEPTH_3] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[146 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_LAVA_SURFACE_HAZE] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedLiquidsGfx[0 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_LAVA_BUBBLES] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedLiquidsGfx[16 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_HEAT_HAZE] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedLiquidsGfx[24 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_LEAK_ON_FLOOR] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 6,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[150 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_LEAK_POURING] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 6,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[154 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_WATER_LEAK_SPLASHING] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 6,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[158 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_MELTDOWN_FLASHING] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 4,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGfx[126 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[66 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[86 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_3] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[90 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_4] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[94 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_5] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[98 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_6] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[102 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_7] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[106 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_8] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[110 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_9] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[114 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_10] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[70 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_11] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[74 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_12] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[78 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_13] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[82 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_SNOW] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGfx[226 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_OPERATIONS_DECK_GLOW_SOLID] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 4,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGfx[38 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_OPERATIONS_DECK_GLOW_EDGE] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 4,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGfx[46 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_ELEVATOR] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[54 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[66 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[86 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_3] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[90 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_4] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[94 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_5] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[98 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_6] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[102 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_7] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[106 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_8] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[110 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_9] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[114 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_10] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[70 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_11] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[74 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_12] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[78 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_13] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 3,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[82 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_LAVA_SURFACE] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedLiquidsGfx[8 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BG_BUBBLES_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[118 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_BG_BUBBLES_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[122 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_REACTOR_CORE_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[18 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_REACTOR_CORE_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[22 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_REACTOR_CORE_3] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[26 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_REACTOR_CORE_4] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[30 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_REACTOR_CORE_5] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[34 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_RESTRICTED_LAB_TUBE_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 1,
        .numberOfStates = 2,
        .pGraphics = &sAnimatedTilesGfx[58 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_RESTRICTED_LAB_TUBE_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 1,
        .numberOfStates = 2,
        .pGraphics = &sAnimatedTilesGfx[60 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_RESTRICTED_LAB_WINDOW_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 1,
        .numberOfStates = 2,
        .pGraphics = &sAnimatedTilesGfx[62 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_RESTRICTED_LAB_WINDOW_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 1,
        .numberOfStates = 2,
        .pGraphics = &sAnimatedTilesGfx[64 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_ACID_SURFACE] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[210 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_ACID_LAYER_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[214 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_ACID_LAYER_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[218 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_ACID_LAYER_3] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[222 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_1] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 14,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[162 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_2] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 14,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[178 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_3] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 13,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[182 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_4] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 13,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[186 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_5] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 15,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[190 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_6] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 15,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[194 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_7] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[198 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_8] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[202 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_9] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[206 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_10] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 16,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[166 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_11] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 16,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[170 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_VINE_12] = {
        .type = ANIMATED_GFX_TYPE_NORMAL,
        .framesPerState = 16,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGfx[174 * ANIMATED_GFX_SIZE]
    },
    [ANIMATED_GFX_ID_SECURITY_CAMERA] = {
        .type = ANIMATED_GFX_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numberOfStates = 14,
        .pGraphics = &sAnimatedTilesGfx[4 * ANIMATED_GFX_SIZE]
    }
};

// Every 3 bytes:
// 0: default animated graphics ID
// 1: index into gUseAlternateAnimatedTilesetFlags
// 2: alternate animated graphics ID
const u8 sAnimatedTilesetEntries[14][48] = {
    [0] = {
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
    },
    [1] = {
        ANIMATED_GFX_ID_WATER_LEAK_ON_FLOOR, 0, FALSE,
        ANIMATED_GFX_ID_WATER_LEAK_POURING, 0, FALSE,
        ANIMATED_GFX_ID_WATER_LEAK_SPLASHING, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_WATER_SURFACE, 0, FALSE,
        ANIMATED_GFX_ID_WATER_DEPTH_1, 0, FALSE,
        ANIMATED_GFX_ID_WATER_DEPTH_2, 0, FALSE,
        ANIMATED_GFX_ID_WATER_DEPTH_3, 0, FALSE,
    },
    [2] = {
        ANIMATED_GFX_ID_MELTDOWN_FLASHING, 0, FALSE,
        ANIMATED_GFX_ID_SECURITY_CAMERA, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_LAVA_SURFACE_HAZE, 0, FALSE,
        ANIMATED_GFX_ID_LAVA_BUBBLES, 0, FALSE,
        ANIMATED_GFX_ID_HEAT_HAZE, 0, FALSE,
    },
    [3] = {
        ANIMATED_GFX_ID_ELEVATOR, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_MELTDOWN_FLASHING, 0, FALSE,
    },
    [4] = {
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_1, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_2, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_3, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_4, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_5, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_6, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_7, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_8, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_9, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_10, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_11, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_12, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_SLOW_13, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_MELTDOWN_FLASHING, 0, FALSE,
    },
    [5] = {
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_SNOW, 0, FALSE,
    },
    [6] = {
        ANIMATED_GFX_ID_OPERATIONS_DECK_GLOW_SOLID, 0, FALSE,
        ANIMATED_GFX_ID_OPERATIONS_DECK_GLOW_EDGE, 0, FALSE,
        ANIMATED_GFX_ID_ELEVATOR, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
    },
    [7] = {
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_1, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_2, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_3, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_4, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_5, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_6, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_7, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_8, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_9, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_10, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_11, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_12, 0, FALSE,
        ANIMATED_GFX_ID_BOILER_ROOM_GEAR_FAST_13, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_MELTDOWN_FLASHING, 0, FALSE,
    },
    [8] = {
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_LAVA_SURFACE, 0, FALSE,
        ANIMATED_GFX_ID_LAVA_BUBBLES, 0, FALSE,
        ANIMATED_GFX_ID_HEAT_HAZE, 0, FALSE,
    },
    [9] = {
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_BG_BUBBLES_1, 0, FALSE,
        ANIMATED_GFX_ID_BG_BUBBLES_2, 0, FALSE,
        ANIMATED_GFX_ID_MELTDOWN_FLASHING, 0, FALSE,
    },
    [10] = {
        ANIMATED_GFX_ID_REACTOR_CORE_1, 0, FALSE,
        ANIMATED_GFX_ID_REACTOR_CORE_2, 0, FALSE,
        ANIMATED_GFX_ID_REACTOR_CORE_3, 0, FALSE,
        ANIMATED_GFX_ID_REACTOR_CORE_4, 0, FALSE,
        ANIMATED_GFX_ID_REACTOR_CORE_5, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
    },
    [11] = {
        ANIMATED_GFX_ID_RESTRICTED_LAB_TUBE_1, 0, FALSE,
        ANIMATED_GFX_ID_RESTRICTED_LAB_TUBE_2, 0, FALSE,
        ANIMATED_GFX_ID_RESTRICTED_LAB_WINDOW_1, 0, FALSE,
        ANIMATED_GFX_ID_RESTRICTED_LAB_WINDOW_2, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
    },
    [12] = {
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_ACID_SURFACE, 0, FALSE,
        ANIMATED_GFX_ID_ACID_LAYER_1, 0, FALSE,
        ANIMATED_GFX_ID_ACID_LAYER_2, 0, FALSE,
        ANIMATED_GFX_ID_ACID_LAYER_3, 0, FALSE,
    },
    [13] = {
        ANIMATED_GFX_ID_VINE_1, 0, FALSE,
        ANIMATED_GFX_ID_VINE_2, 0, FALSE,
        ANIMATED_GFX_ID_VINE_3, 0, FALSE,
        ANIMATED_GFX_ID_VINE_4, 0, FALSE,
        ANIMATED_GFX_ID_VINE_5, 0, FALSE,
        ANIMATED_GFX_ID_VINE_6, 0, FALSE,
        ANIMATED_GFX_ID_VINE_7, 0, FALSE,
        ANIMATED_GFX_ID_VINE_8, 0, FALSE,
        ANIMATED_GFX_ID_VINE_9, 0, FALSE,
        ANIMATED_GFX_ID_VINE_10, 0, FALSE,
        ANIMATED_GFX_ID_VINE_11, 0, FALSE,
        ANIMATED_GFX_ID_VINE_12, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
        ANIMATED_GFX_ID_CRYSTAL, 0, FALSE,
    }
};

// TODO: Move these

const u8 sScroll_Empty[11] = {
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX
};

static const u8 sBlob_3c923b_3c94d0[] = INCBIN_U8("data/Blob_3c923b_3c94d0.bin");

const s8 sEndingSamusPosingSineTable[128] = {
    0, 6, 12, 19, 25, 31, 37, 43,
    49, 54, 60, 65, 71, 76, 81, 85,
    90, 94, 98, 102, 106, 109, 112, 115,
    117, 120, 122, 123, 125, 126, 126, 127,
    127, 127, 126, 126, 125, 123, 122, 120,
    117, 115, 112, 109, 106, 102, 98, 94,
    90, 85, 81, 76, 71, 65, 60, 54,
    49, 43, 37, 31, 25, 19, 12, 6,
    0, -6, -12, -19, -25, -31, -37, -43,
    -49, -54, -60, -65, -71, -76, -81, -85,
    -90, -94, -98, -102, -106, -109, -112, -115,
    -117, -120, -122, -123, -125, -126, -126, -127,
    -127, -127, -126, -126, -125, -123, -122, -120,
    -117, -115, -112, -109, -106, -102, -98, -94,
    -90, -85, -81, -76, -71, -65, -60, -54,
    -49, -43, -37, -31, -25, -19, -12, -6,
};

static const u8 sBlob_3c9550_3e392c[] = INCBIN_U8("data/Blob_3c9550_3e392c.bin");

