#ifndef SCROLL_STRUCT_H
#define SCROLL_STRUCT_H

#include "types.h"
#include "macros.h"

enum ScrollSubData {
    // Left bound
    SCROLL_SUB_DATA_X_START,
    // Right bound
    SCROLL_SUB_DATA_X_END,
    // Top bound
    SCROLL_SUB_DATA_Y_START,
    // Bottom bound
    SCROLL_SUB_DATA_Y_END,
    // Breakable block X position
    SCROLL_SUB_DATA_BREAKABLE_X,
    // Breakable block Y position
    SCROLL_SUB_DATA_BREAKABLE_Y,
    // Which direction 
    SCROLL_SUB_DATA_EXTENDED_DIRECTION,
    SCROLL_SUB_DATA_EXTENDED_VALUE,

    SCROLL_SUB_DATA_COUNT
};

#define SCROLL_DATA_SIZE(nbrScrolls) (2 + SCROLL_SUB_DATA_COUNT * nbrScrolls)

#define SCROLL_NOT_WITHIN_FLAG 0
#define SCROLL_WITHIN_FLAG 2

enum Bg3ScrollingType {
    BG3_SCROLLING_TYPE_NONE,
    BG3_SCROLLING_TYPE_NORMAL,
    BG3_SCROLLING_TYPE_HALVED,
    BG3_SCROLLING_TYPE_QUARTERED,
};

#define SCROLL_X_ANCHOR (SCREEN_SIZE_X_SUB_PIXEL / 2)
#define SCROLL_Y_ANCHOR ((s32)(SCREEN_SIZE_Y_SUB_PIXEL * .6f))

struct Scroll {
    u8 within;
    u16 xEnd;
    u16 xStart;
    u16 yStart;
    u16 yEnd;
};

#define FRONT_WIDE_CAMERA_DISTANCE BLOCK_TO_SUB_PIXEL(2)

enum FrontWideCameraDirection {
    FRONT_WIDE_NONE = 0,
    FRONT_WIDE_RIGHT = 1 << 0,
    FRONT_WIDE_LEFT = 1 << 1
};

struct Camera {
    u16 xPosition;
    u16 prevXPosition;
    u16 yPosition;
    s8 xVelocity;
    s8 yVelocity;
    s8 frontWideDirection;
    s8 ladderFrontWideDirection;
    s8 frontWideXVelocity;
    u16 frontWideTargetXPosition;
};

struct LockScreen {
    u8 lock;
    u16 xPositionCenter;
    u16 yPositionCenter;
};

struct CameraScrollVelocityCaps {
    s16 leftCap;
    s16 rightCap;
    s16 upCap;
    s16 downCap;
};


extern u8 gDisableScrolling;
// TODO: Copied from mzm, delete any that aren't needed
// extern u16 gSlowScrollingTimer;
// extern u8 gSkipDoorTransition;
extern struct Scroll gCurrentScrolls[2];
extern struct Camera gCamera;
// extern struct LockScreen gLockScreen;
// extern s8 gScreenYOffset;
// extern s16 gScreenXOffset;

// extern u8 gNoClipLockCamera;
// extern struct CameraScrollVelocityCaps gScrollingVelocityCaps;
extern const u8* gCurrentRoomScrollDataPointer;

#endif /* SCROLL_STRUCT_H */
