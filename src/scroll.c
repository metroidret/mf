#include "scroll.h"

#include "globals.h"
#include "macros.h"

#include "data/rooms/main_deck_rooms_data.h"
#include "data/rooms/sector_1_rooms_data.h"
#include "data/rooms/sector_2_rooms_data.h"
#include "data/rooms/sector_3_rooms_data.h"
#include "data/rooms/sector_4_rooms_data.h"
#include "data/rooms/sector_5_rooms_data.h"
#include "data/rooms/sector_6_rooms_data.h"

#include "data/scroll_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/room.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/color_effects.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/menus/boot_debug.h"
#include "structs/sa_x.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"

#define SCROLL_VELOCITY_CAP BLOCK_TO_SUB_PIXEL(.75f)

static const u8* sScrollPointer_Empty[] = {
    sScroll_Empty
};

static const u8* sMainDeckScrolls[] = {
	sMainDeck_7_Scrolls,
	sMainDeck_10_Scrolls,
	sMainDeck_12_Scrolls,
	sMainDeck_13_Scrolls,
	sMainDeck_17_Scrolls,
	sMainDeck_19_Scrolls,
	sMainDeck_20_Scrolls,
	sMainDeck_21_Scrolls,
	sMainDeck_23_Scrolls,
	sMainDeck_24_Scrolls,
	sMainDeck_25_Scrolls,
	sMainDeck_26_Scrolls,
	sMainDeck_27_Scrolls,
	sMainDeck_28_Scrolls,
	sMainDeck_29_Scrolls,
	sMainDeck_30_Scrolls,
	sMainDeck_38_Scrolls,
	sMainDeck_40_Scrolls,
	sMainDeck_46_Scrolls,
	sMainDeck_47_Scrolls,
	sMainDeck_60_Scrolls,
	sMainDeck_61_Scrolls,
	sMainDeck_67_Scrolls,
	sMainDeck_69_Scrolls,
	sMainDeck_74_Scrolls,
	sMainDeck_75_Scrolls,
	sMainDeck_76_Scrolls,
	sMainDeck_77_Scrolls,
	sMainDeck_78_Scrolls,
	sMainDeck_79_Scrolls,
	sMainDeck_82_Scrolls,
	sMainDeck_85_Scrolls,
    sScroll_Empty
};

static const u8* sSector1Scrolls[] = {
	sSector1_0_Scrolls,
	sSector1_10_Scrolls,
	sSector1_20_Scrolls,
	sSector1_21_Scrolls,
	sSector1_22_Scrolls,
	sSector1_31_Scrolls,
	sSector1_36_Scrolls,
	sSector1_38_Scrolls,
	sSector1_39_Scrolls,
	sSector1_40_Scrolls,
	sSector1_41_Scrolls,
    sScroll_Empty
};

static const u8* sSector2Scrolls[] = {
	sSector2_5_Scrolls,
	sSector2_6_Scrolls,
	sSector2_9_Scrolls,
	sSector2_10_Scrolls,
	sSector2_17_Scrolls,
	sSector2_18_Scrolls,
	sSector2_19_Scrolls,
	sSector2_20_Scrolls,
	sSector2_21_Scrolls,
	sSector2_22_Scrolls,
	sSector2_24_Scrolls,
	sSector2_26_Scrolls,
	sSector2_27_Scrolls,
	sSector2_29_Scrolls,
	sSector2_31_Scrolls,
	sSector2_33_Scrolls,
	sSector2_34_Scrolls,
	sSector2_36_Scrolls,
	sSector2_44_Scrolls,
	sSector2_47_Scrolls,
	sSector2_51_Scrolls,
	sSector2_57_Scrolls,
	sSector2_58_Scrolls,
    sScroll_Empty
};

static const u8* sSector3Scrolls[] = {
	sSector3_3_Scrolls,
	sSector3_6_Scrolls,
	sSector3_8_Scrolls,
	sSector3_11_Scrolls,
	sSector3_12_Scrolls,
	sSector3_18_Scrolls,
	sSector3_19_Scrolls,
	sSector3_20_Scrolls,
	sSector3_22_Scrolls,
	sSector3_23_Scrolls,
	sSector3_24_Scrolls,
	sSector3_28_Scrolls,
	sSector3_30_Scrolls,
	sSector3_34_Scrolls,
    sScroll_Empty
};

static const u8* sSector5Scrolls[] = {
	sSector5_0_Scrolls,
	sSector5_4_Scrolls,
	sSector5_7_Scrolls,
	sSector5_9_Scrolls,
	sSector5_10_Scrolls,
	sSector5_15_Scrolls,
	sSector5_19_Scrolls,
	sSector5_20_Scrolls,
	sSector5_21_Scrolls,
	sSector5_22_Scrolls,
	sSector5_24_Scrolls,
	sSector5_25_Scrolls,
	sSector5_30_Scrolls,
	sSector5_36_Scrolls,
	sSector5_42_Scrolls,
	sSector5_43_Scrolls,
	sSector5_46_Scrolls,
	sSector5_50_Scrolls,
    sScroll_Empty
};

static const u8* sSector4Scrolls[] = {
	sSector4_8_Scrolls,
	sSector4_13_Scrolls,
	sSector4_17_Scrolls,
	sSector4_21_Scrolls,
	sSector4_23_Scrolls,
	sSector4_24_Scrolls,
	sSector4_27_Scrolls,
	sSector4_33_Scrolls,
	sSector4_34_Scrolls,
	sSector4_35_Scrolls,
	sSector4_36_Scrolls,
	sSector4_42_Scrolls,
    sScroll_Empty
};

static const u8* sSector6Scrolls[] = {
	sSector6_0_Scrolls,
	sSector6_5_Scrolls,
	sSector6_7_Scrolls,
	sSector6_8_Scrolls,
	sSector6_9_Scrolls,
	sSector6_12_Scrolls,
	sSector6_13_Scrolls,
	sSector6_14_Scrolls,
	sSector6_16_Scrolls,
	sSector6_17_Scrolls,
	sSector6_18_Scrolls,
	sSector6_19_Scrolls,
	sSector6_24_Scrolls,
	sSector6_26_Scrolls,
	sSector6_27_Scrolls,
	sSector6_28_Scrolls,
	sSector6_30_Scrolls,
	sSector6_31_Scrolls,
	sSector6_33_Scrolls,
    sScroll_Empty
};

static const u8** sAreaScrollPointers[AREA_END] = {
    [AREA_MAIN_DECK] = sMainDeckScrolls,
    [AREA_SECTOR_1] = sSector1Scrolls,
    [AREA_SECTOR_2] = sSector2Scrolls,
    [AREA_SECTOR_3] = sSector3Scrolls,
    [AREA_SECTOR_4] = sSector4Scrolls,
    [AREA_SECTOR_5] = sSector5Scrolls,
    [AREA_SECTOR_6] = sSector6Scrolls,
    [AREA_TEST_1] = sScrollPointer_Empty,
    [AREA_TEST_2] = sScrollPointer_Empty,
    [AREA_TEST_3] = sScrollPointer_Empty
};

static s8 sWaterLoopCounterArray[8][2] = {
    [0] = {
        0, 9
    },
    [1] = {
        1, 9
    },
    [2] = {
        2, 21
    },
    [3] = {
        1, 9
    },
    [4] = {
        0, 9
    },
    [5] = {
        -1, 12
    },
    [6] = {
        -2, 99
    },
    [7] = {
        -1, 12
    }
};

static s8 sNightmareShadowYVelocityOffsets[16] = {
	0, 2, 4, 0, 0, 2, 4, -4,
	-4, 0, 0, 0, -2, 0, 0, -2
};


/**
 * @brief 69b04 | 64 | Processes the current scrolls
 *
 * @param pCoords Coordinates pointer
 */
void ScrollProcess(struct RawCoordsX* pCoords)
{
    s32 screenX;
    s32 screenY;
    struct Scroll* pScroll;

    ScrollUpdateCurrent();

    do {
    screenX = gCamera.xPosition;
    screenY = gCamera.yPosition;
    } while (0);

    pScroll = gCurrentScrolls;
    if (pScroll->within != SCROLL_NOT_WITHIN_FLAG)
    {
        screenX = ScrollProcessX(pScroll, pCoords);
        screenY = ScrollProcessY(pScroll, pCoords);
    }

    pScroll++;
    if (pScroll->within != SCROLL_NOT_WITHIN_FLAG)
    {
		// Get positions, compute middle between previous and new positions
        // This merges the results of this scroll with the previous one
        screenX = DIV_SHIFT(screenX + ScrollProcessX(pScroll, pCoords), 2);
        screenY = DIV_SHIFT(screenY + ScrollProcessY(pScroll, pCoords), 2);
    }

    ScrollScreen(screenX, screenY);
}

/**
 * @brief 69b68 | f4 | Scrolls the screen to the provided position
 *
 * @param screenX Screen X
 * @param screenY Screen Y
 */
void ScrollScreen(u16 screenX, u16 screenY)
{
    s32 velocity;
    s32 screenDiff;

    gCamera.xPosition = screenX;
    gCamera.yPosition = screenY;

    if (gSubGameMode1 == 0)
        return;

    if (screenY != gBg1YPosition)
    {
        velocity = gSamusData.yPosition - gPreviousYPosition;
        screenDiff = screenY - gBg1YPosition;

        if (screenDiff > 0)
        {
            if (screenDiff > SCROLL_VELOCITY_CAP)
                screenDiff = SCROLL_VELOCITY_CAP;

            if (velocity >= 0)
            {
                velocity += PIXEL_TO_SUB_PIXEL(1);
                if (screenDiff < velocity)
                    velocity = screenDiff;
            }
            else
            {
                velocity = 0;
            }
        }
        else
        {
            if (screenDiff < -SCROLL_VELOCITY_CAP)
                screenDiff = -SCROLL_VELOCITY_CAP;

            if (velocity <= 0)
            {
                velocity -= PIXEL_TO_SUB_PIXEL(1);
                if (screenDiff > velocity)
                    velocity = screenDiff;
            }
            else
            {
                velocity = 0;
            }
        }

        gCamera.yVelocity = velocity;
        gBg1YPosition += velocity;
    }
    else
    {
        gCamera.yVelocity = 0;
    }

    if (screenX != gBg1XPosition)
    {
        velocity = gSamusData.xPosition - gPreviousXPosition;
        screenDiff =screenX - gBg1XPosition;

        if (screenDiff > 0)
        {
            if (screenDiff > SCROLL_VELOCITY_CAP)
                screenDiff = SCROLL_VELOCITY_CAP;

            if (velocity >= 0)
            {
                velocity += PIXEL_TO_SUB_PIXEL(1);
                if (screenDiff < velocity)
                    velocity = screenDiff;
            }
            else
            {
                velocity = 0;
            }
        }
        else
        {
            if (screenDiff < -SCROLL_VELOCITY_CAP)
                screenDiff = -SCROLL_VELOCITY_CAP;
            
            if (velocity <= 0)
            {
                velocity -= PIXEL_TO_SUB_PIXEL(1);
                if (screenDiff > velocity)
                    velocity = screenDiff;
            }
            else
            {
                velocity = 0;
            }
        }

        gCamera.xVelocity = velocity;
        gBg1XPosition += velocity;
    }
    else
    {
        gCamera.xVelocity = 0;            
    }
}

/**
 * @brief 69c5c | 40 | Processes the X scrolling
 *
 * @param pScroll Scroll pointer
 * @param pCoords Coordinates pointer
 * @return s32 Screen X
 */
s32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
	// Check is on the far left of the scroll, i.e. if the distance between the start and the coords X is smaller than the anchor
    if (pCoords->x < pScroll->xStart + SCROLL_X_ANCHOR)
    {
        // Screen should be at the left limit of the scroll then
        return pScroll->xStart;
    }

    // Check isn't on the far right of the scroll, i.e. if the distance between the end and the coords X is smaller than the anchor
    if (pCoords->x <= pScroll->xEnd - SCROLL_X_ANCHOR)
    {
        // In the middle of the scroll otherwhise, set the position to the coords - anchor
        return pCoords->x - SCROLL_X_ANCHOR;
    }

    // Screen should "stop" before the right limit, so set it to right - screen size
    return pScroll->xEnd - SCREEN_SIZE_X_SUB_PIXEL;
}

/**
 * @brief 69c9c | 54 | Processes the Y scrolling
 *
 * @param pScroll Scroll pointer
 * @param pCoords Coordinates pointer
 * @return s32 Screen Y
 */
s32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    if (pScroll->within == SCROLL_WITHIN_FLAG)
    {
        // Check is above the scroll Y anchor, i.e. the distance between the start and the coords Y is smaller than the anchor
        if (pCoords->y < pScroll->yStart + SCROLL_Y_ANCHOR)
        {
            // Stop the screen at the top of the scroll
            return pScroll->yStart;
        }

        // Check is below the scroll Y anchor, i.e. the distance between the end and the coords Y is smaller than the difference between the total size and the anchor
        if (pCoords->y > pScroll->yEnd - (SCREEN_SIZE_Y_SUB_PIXEL - SCROLL_Y_ANCHOR))
        {
            if (pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL < pScroll->yStart)
                return pScroll->yStart;

            // Stop the screen at the bottom of the scroll
            return pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL;
        }

        // In the middle of the scroll otherwise, set the position to the coords - anchor
        return pCoords->y - SCROLL_Y_ANCHOR;
    }

    return pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL;
}

/**
 * @brief 69cf0 | 60 | Loads the scrolls for the current room
 *
 */
void ScrollLoad(void)
{
    const u8** ppSrc;

    ppSrc = sAreaScrollPointers[gCurrentArea];

    // Loop through every scroll of the area
    for (; ; ppSrc++)
    {
        if (**ppSrc == gCurrentRoom)
        {
            // Found room, set pointer and flag
            gCurrentRoomScrollDataPointer = *ppSrc;
            gCurrentRoomEntry.scrollsFlag = ROOM_SCROLLS_FLAG_HAS_SCROLLS;
            break;
        }
        
        if (**ppSrc == UCHAR_MAX)
        {
            // Reached terminator
            gCurrentRoomScrollDataPointer = *ppSrc;
            break;
        }
    }
}

/**
 * @brief 69d50 | 180 | Updates the current scrolls
 *
 */
void ScrollUpdateCurrent(void)
{
    u16 xPosition;
    u16 yPosition;
    const u8* src;
    const u8* data;
    s32 nbrScrolls;
    s32 i;
    s32 bounds[4];
    s32 position;

    // Reset 2 scrolls
    gCurrentScrolls[0].within = SCROLL_NOT_WITHIN_FLAG;
    gCurrentScrolls[1].within = SCROLL_NOT_WITHIN_FLAG;

    xPosition = SUB_PIXEL_TO_BLOCK(gSamusData.xPosition);
    yPosition = SUB_PIXEL_TO_BLOCK(gSamusData.yPosition);

    src = gCurrentRoomScrollDataPointer;

    // Ignore room id field
    src++;

    // Fetch total number of scrolls in the current room
    nbrScrolls = *src;

    // Get pointer to the start of the scroll sub data
    data = src + 1;

    // Loop over each scroll in the room
    for (i = 0; nbrScrolls != 0; data += SCROLL_SUB_DATA_COUNT, nbrScrolls--)
    {
        // Won't need to process if the current scroll is already filled
        if (i == ARRAY_SIZE(gCurrentScrolls))
            return;

        // Initialize bound indexes for the scroll, the default bounds are used, but that can change
        bounds[SCROLL_SUB_DATA_X_START] = SCROLL_SUB_DATA_X_START;
        bounds[SCROLL_SUB_DATA_X_END] = SCROLL_SUB_DATA_X_END;
        bounds[SCROLL_SUB_DATA_Y_START] = SCROLL_SUB_DATA_Y_START;
        bounds[SCROLL_SUB_DATA_Y_END] = SCROLL_SUB_DATA_Y_END;

        // Check for breakable block
        if (data[SCROLL_SUB_DATA_BREAKABLE_X] != UCHAR_MAX && data[SCROLL_SUB_DATA_EXTENDED_VALUE] != UCHAR_MAX)
        {
            // Get breakable block position
            position = data[SCROLL_SUB_DATA_BREAKABLE_Y] * gBackgroundsData.clipdataWidth + data[SCROLL_SUB_DATA_BREAKABLE_X];

            // Check for clipdata, and that the extended direction is valid
            if (gBackgroundsData.pClipDecomp[position] == 0 && data[SCROLL_SUB_DATA_EXTENDED_DIRECTION] != UCHAR_MAX)
            {
                // Change the bound of the extended direction to use the extended value
                bounds[data[SCROLL_SUB_DATA_EXTENDED_DIRECTION]] = SCROLL_SUB_DATA_EXTENDED_VALUE;
            }
        }
        else
        {
            // Check for extended bound without a breakable block, can only work when samus is using an elevator
            if (gSamusData.pose == SPOSE_USING_ELEVATOR && data[SCROLL_SUB_DATA_EXTENDED_VALUE] != UCHAR_MAX)
            {
                // An elevator extended bound can only be vertical
                if ((data[SCROLL_SUB_DATA_EXTENDED_DIRECTION] == SCROLL_SUB_DATA_Y_START || data[SCROLL_SUB_DATA_EXTENDED_DIRECTION] == SCROLL_SUB_DATA_Y_END))
                {
                    // Change the bound of the extended direction to use the extended value
                    bounds[data[SCROLL_SUB_DATA_EXTENDED_DIRECTION]] = SCROLL_SUB_DATA_EXTENDED_VALUE;
                }
            }
        }

        // Check is within the bounds
        if (data[bounds[SCROLL_SUB_DATA_X_START]] <= xPosition && xPosition <= data[bounds[SCROLL_SUB_DATA_X_END]] &&
            data[bounds[SCROLL_SUB_DATA_Y_START]] <= yPosition && yPosition <= data[bounds[SCROLL_SUB_DATA_Y_END]])
        {
            if (gCurrentScrolls[i].within)
            {
                // This scroll already exists, abort processing
                continue;
            }

            // Set X start (left bound), check isn't below the X screen padding
            {
                s32 upper = BLOCK_TO_SUB_PIXEL(data[bounds[SCROLL_SUB_DATA_X_START]]);
                
                gCurrentScrolls[i].xStart = gScreenBlockPadding.left < upper ? upper : gScreenBlockPadding.left;
            }

            // Set X end (right bound), check isn't after the size of the room
            {
                s32 upper = position = BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth) - gScreenBlockPadding.right;
                s32 lower = BLOCK_TO_SUB_PIXEL(data[bounds[SCROLL_SUB_DATA_X_END]] + 1);
                
                gCurrentScrolls[i].xEnd = lower >= position ? upper : lower;
            }
            
            EMPTY_DO_WHILE

            // Set Y start (top bound), check isn't below the Y screen padding
            {
                s32 upper = BLOCK_TO_SUB_PIXEL(data[bounds[SCROLL_SUB_DATA_Y_START]]);
                
                gCurrentScrolls[i].yStart = gScreenBlockPadding.top < upper ? upper : gScreenBlockPadding.top;
            } 

            // Set Y end (bottom bound), check isn't after the size of the room
            {
                s32 upper = position = BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight) - gScreenBlockPadding.bottom;
                s32 lower = BLOCK_TO_SUB_PIXEL(data[bounds[SCROLL_SUB_DATA_Y_END]] + 1);
                
                gCurrentScrolls[i].yEnd = lower >= position ? upper : lower;
            }
            
            EMPTY_DO_WHILE
            
            gCurrentScrolls[i].within = SCROLL_WITHIN_FLAG;
            i++;
        }
    }

    if (!gCurrentScrolls[0].within && !gCurrentScrolls[1].within)
    {
        gCurrentScrolls[0].within = SCROLL_NOT_WITHIN_FLAG;
        gCurrentScrolls[0].xEnd = 0;
        gCurrentScrolls[0].xStart = 0;
        gCurrentScrolls[0].yStart = 0;
        gCurrentScrolls[0].yEnd = 0;
    }
}

/**
 * @brief 69ed0 | ec |  Processes the general scrolling
 *
 */
void ScrollProcessGeneral(void)
{
    struct RawCoordsX coords;

    if (gColorFading.stage != 0)
        return;

    coords.x = gSamusData.xPosition;
    coords.y = gSamusData.yPosition + ONE_SUB_PIXEL;

    // Unclear what this check is for, since it wouldn't be true unless
    // Samus is way out of bounds
    if (coords.y & 0x8000)
        coords.y = 0;

    if (gDisableScrolling == 0)
    {
        if (gUnk_3000064 != 0 && gSubGameMode1 == 6)
            ScrollNoClipUnlockedCamera(&coords);
        else if (gCurrentRoomEntry.scrollsFlag == 3)
            ScrollProcess(&coords);
        else
            ScrollWithNoScrolls(&coords);

        gBg2XPosition = gBg1XPosition;
        gBg2YPosition = gBg1YPosition;

        if (gBg0Movement.type != 0)
            ScrollAutoBg0();

        ScrollUpdateEffectAndHazePosition(&coords);
        ScrollBg3();
        ScrollAutoBg3();
    }
    else if (gDisableScrolling == 2)
    {
        if (gBg0Movement.type != 0)
            ScrollAutoBg0();

        ScrollUpdateEffectAndHazePosition(&coords);
        ScrollBg3();
        ScrollAutoBg3();
    }
}

/**
 * @brief 69fbc | 9c | Handles the automatic scrolling in a room with no scrolls
 *
 * @param pCoords Coordinates pointer
 */
void ScrollWithNoScrolls(struct RawCoordsX* coords)
{
    s32 cameraY;
    s32 maxY;
    s32 yVelocity;

    if (gBootDebugOptions.frontWideCamera == 0)
    {
        ScrollWithNoScrollsX(coords);
    }
    else
    {
        ScrollFrontWideComputeBase(coords);
        ScrollFrontWideComputeTarget(coords);
        ScrollFrontWideApplyVelocity();
    }

    if (coords->y < gScreenBlockPadding.top + SCROLL_Y_ANCHOR)
    {
        cameraY = gScreenBlockPadding.top;
    }
    else
    {
        maxY = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].height) -
            (BLOCK_TO_SUB_PIXEL(4) + gScreenBlockPadding.bottom);
        if (coords->y > maxY)
            cameraY = maxY - SCROLL_Y_ANCHOR;
        else
            cameraY = coords->y - SCROLL_Y_ANCHOR;
    }

    gCamera.yPosition = cameraY;
    yVelocity = cameraY - gBg1YPosition;
    if (yVelocity > 0)
    {
        if (yVelocity > SCROLL_VELOCITY_CAP)
            yVelocity = SCROLL_VELOCITY_CAP;
    }
    else
    {
        if (yVelocity < -SCROLL_VELOCITY_CAP)
            yVelocity = -SCROLL_VELOCITY_CAP;
    }

    gCamera.yVelocity = yVelocity;
    gBg1YPosition += yVelocity;
}

/**
 * @brief 6a058 | 84 | Handles the automatic X scrolling in a room with no scrolls
 *
 * @param pCoords Coordinates pointer
 */
void ScrollWithNoScrollsX(struct RawCoordsX* coords)
{
    s32 cameraX;
    s32 maxX;
    s32 xVelocity;
    
    if (coords->x < gScreenBlockPadding.left + SCROLL_X_ANCHOR)
    {
        cameraX = gScreenBlockPadding.left;
    }
    else
    {
        maxX = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) -
            (SCROLL_X_ANCHOR + gScreenBlockPadding.right);
        if (coords->x > maxX)
        {
            cameraX = maxX;
            cameraX -= SCROLL_X_ANCHOR;
        }
        else
        {
            cameraX = coords->x;
            cameraX -= SCROLL_X_ANCHOR;
        }
    }

    gCamera.xPosition = cameraX;
    xVelocity = cameraX - gBg1XPosition;
    if (xVelocity > 0)
    {
        if (xVelocity > SCROLL_VELOCITY_CAP)
            xVelocity = SCROLL_VELOCITY_CAP;
    }
    else
    {
        if (xVelocity < -SCROLL_VELOCITY_CAP)
            xVelocity = -SCROLL_VELOCITY_CAP;
    }

    gCamera.xVelocity = xVelocity;
    gBg1XPosition += xVelocity;
    gCamera.frontWideXVelocity = 0;
}

/**
 * @brief 6a0dc | 78 | Computes the base X position and velocity for the front wide camera
 *
 */
void ScrollFrontWideComputeBase(struct RawCoordsX* coords)
{
    s32 xOffset;
    s32 maxX;
    
    if (coords->x < gScreenBlockPadding.left + SCROLL_X_ANCHOR)
    {
        xOffset = gScreenBlockPadding.left;
    }
    else
    {
        maxX = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) -
            (SCROLL_X_ANCHOR + gScreenBlockPadding.right);
        if (coords->x > maxX)
        {
            xOffset = maxX;
            xOffset -= SCROLL_X_ANCHOR;
        }
        else
        {
            xOffset = coords->x;
            xOffset -= SCROLL_X_ANCHOR;
        }
    }

    gCamera.xPosition = xOffset;
    xOffset = xOffset - gCamera.prevXPosition;
    if (xOffset > 0)
    {
        if (xOffset > SCROLL_VELOCITY_CAP)
            xOffset = SCROLL_VELOCITY_CAP;
    }
    else
    {
        if (xOffset < -SCROLL_VELOCITY_CAP)
            xOffset = -SCROLL_VELOCITY_CAP;
    }

    gCamera.xVelocity = xOffset;
    gCamera.prevXPosition = gCamera.xPosition;
}

/**
 * @brief 6a154 | 128 | Computes the target X position and extra velocity for the front wide camera
 *
 */
void ScrollFrontWideComputeTarget(struct RawCoordsX* coords)
{
    s32 targetX;
    s32 maxTargetX;
    s32 xVelocity;

    gCamera.frontWideDirection = FRONT_WIDE_NONE;
    if (gSamusData.direction & KEY_RIGHT)
        gCamera.frontWideDirection = FRONT_WIDE_RIGHT;
    else if (gSamusData.direction & KEY_LEFT)
        gCamera.frontWideDirection = FRONT_WIDE_LEFT;

    if (gSamusData.pose == SPOSE_HANGING_FROM_VERTICAL_LADDER)
    {
        if (gCamera.frontWideDirection != FRONT_WIDE_NONE)
            gCamera.frontWideDirection ^= FRONT_WIDE_RIGHT | FRONT_WIDE_LEFT;
        gCamera.ladderFrontWideDirection = gCamera.frontWideDirection;
    }

    gCamera.frontWideTargetXPosition = gCamera.xPosition;

    if (gCamera.frontWideDirection == FRONT_WIDE_RIGHT)
    {
        if (coords->x < BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) - gScreenBlockPadding.right - SCROLL_X_ANCHOR &&
            gScreenBlockPadding.left + SCROLL_X_ANCHOR < coords->x)
        {
            targetX = gCamera.xPosition + FRONT_WIDE_CAMERA_DISTANCE;
            if (targetX < gScreenBlockPadding.left)
            {
                targetX = gScreenBlockPadding.left;
            }
            else
            {
				// Written this way to produce matching ASM
                maxTargetX = (BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) << 1 >> 1) -
                    (SCREEN_SIZE_X_SUB_PIXEL + gScreenBlockPadding.right);
                if (targetX > maxTargetX)
                    targetX = maxTargetX;
            }
        }
        else
        {
            targetX = gCamera.xPosition;
        }
    }
    else if (gCamera.frontWideDirection == FRONT_WIDE_LEFT)
    {
        if (coords->x < BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) - gScreenBlockPadding.right - SCROLL_X_ANCHOR &&
             gScreenBlockPadding.left + SCROLL_X_ANCHOR < coords->x)
        {
            targetX = gCamera.xPosition - FRONT_WIDE_CAMERA_DISTANCE;
            if (targetX < gScreenBlockPadding.left)
            {
                targetX = gScreenBlockPadding.left;
            }
            else
            {
				// Written this way to produce matching ASM
				maxTargetX = (BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) << 1 >> 1) -
                    (SCREEN_SIZE_X_SUB_PIXEL + gScreenBlockPadding.right);
                if (targetX > maxTargetX)
                    targetX = maxTargetX;
            }
        }
        else
        {
            targetX = gCamera.xPosition;
        }
    }
    else
    {
        targetX = gCamera.xPosition;
    }

    gCamera.frontWideTargetXPosition = targetX;

    if (gCamera.frontWideTargetXPosition != gBg1XPosition)
        xVelocity = gCamera.frontWideTargetXPosition - (gCamera.xVelocity + gBg1XPosition);
    else
        xVelocity = 0;

    if (xVelocity > 0)
    {
        if (xVelocity > 4)
            xVelocity = 4;
    }
    else if (xVelocity < 0)
    {
        if (xVelocity < -4)
            xVelocity = -4;
    }

    gCamera.frontWideXVelocity = xVelocity;
}

/**
 * @brief 6a27c | 78 | Updates X position and checks to reset velocity for the front wide camera
 *
 */
void ScrollFrontWideApplyVelocity(void)
{
    s32 bgXPosition;
    s32 edgeX;

    if (gCamera.frontWideTargetXPosition < gScreenBlockPadding.left)
        gCamera.xVelocity = 0;

    if (gCamera.frontWideTargetXPosition > BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) -
        (SCREEN_SIZE_X_SUB_PIXEL + gScreenBlockPadding.right))
    {
        gCamera.xVelocity = 0;
    }

    bgXPosition = gCamera.xVelocity + gCamera.frontWideXVelocity + gBg1XPosition;
    edgeX = gScreenBlockPadding.left;
    if (bgXPosition < edgeX)
    {
        bgXPosition = edgeX;
        gCamera.xVelocity = 0;
        gCamera.frontWideXVelocity = 0;
    }
    else
    {
        edgeX = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width) -
            (SCROLL_X_ANCHOR + gScreenBlockPadding.right) - SCROLL_X_ANCHOR;
        if (bgXPosition > edgeX)
        {
            bgXPosition = edgeX;
            gCamera.xVelocity = 0;
            gCamera.frontWideXVelocity = 0;
        }
    }

    gBg1XPosition = bgXPosition;
}

/**
 * @brief 6a2f4 | 2f0 | Updates the haze and effect position
 *
 * @param pCoords Coordinates pointer
 */
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* coords)
{
    bools32 bg0Set;
    u16 bgPosition;
    s32 position;
    s32 waterOffset;

    gWaterMovement.unk_1++;
    bg0Set = FALSE;

    if (gCurrentRoomEntry.bg0Prop & BG_PROP_RLE_COMPRESSED)
    {
        if (gCurrentRoomEntry.bg0Prop == BG_PROP_11)
        {
            gBg0XPosition = gBg1XPosition / 2;
            gBg0YPosition = gBg1YPosition;
            bg0Set = TRUE;
        }
    }
    else
    {
        if (gCurrentRoomEntry.effectY != USHORT_MAX)
        {
            gBg0XPosition = gBg1XPosition;
            position = gWaterMovement.unk_8 + gCurrentRoomEntry.effectY;
            position = DIV_SHIFT(position, 4) - DIV_SHIFT(gBg1YPosition, 4);
            waterOffset = 0;

            if (gWaterMovement.moving == 1)
            {
                if (gWaterMovement.unk_1 >= sWaterLoopCounterArray[gWaterMovement.stage][1] && gPreventMovementTimer == 0)
                {
                    gWaterMovement.stage++;
                    if (gWaterMovement.stage > 7)
                        gWaterMovement.stage = 0;

                    gWaterMovement.unk_1 = 0;
                }

                waterOffset = sWaterLoopCounterArray[gWaterMovement.stage][0];
            }

            gWaterMovement.yOffset = (waterOffset - 8) * 4;
            position += waterOffset;

            if (position < 0)
            {
                if ((gIoRegisters.unk_10 & 0xC000) && (gIoRegisters.bg0Cnt & 0xC000))
                {
                    gIoRegisters.unk_10 &= ~0xC000;
                    WRITE_16(REG_BG0CNT, gIoRegisters.unk_10);
                }
            }
            else
            {
                if (!(gIoRegisters.unk_10 & 0xC000) && (gIoRegisters.bg0Cnt & 0xC000))
                {
                    gIoRegisters.unk_10 |= (gIoRegisters.bg0Cnt & 0xC000);
                    WRITE_16(REG_BG0CNT, READ_16(REG_BG0CNT) | gIoRegisters.unk_10);
                }
            }

            if (position > 0x100)
                position = 0x100;
            
            gBg0YPosition = -position * 4;
            bg0Set = TRUE;
        }
        else
        {
            bg0Set = TRUE;

            switch (gCurrentRoomEntry.bg0Prop)
            {
                case BG_PROP_NIGHTMARE_ROOM:
                    gBg0XPosition = 0;
                    gBg0YPosition = 0;
                    break;

                case BG_PROP_DARK_ROOM:
                case BG_PROP_DIM_ROOM:
                    gBg0XPosition = gBg1XPosition - gSamusData.xPosition;
                    gBg0YPosition = gBg1YPosition - gSamusData.yPosition + BLOCK_TO_SUB_PIXEL(1);
                    break;

                case BG_PROP_SA_X_ROOM:
                    position = FALSE;
                    gBg0XPosition = gBg1XPosition - gSaXSpawnPosition.x + BLOCK_TO_SUB_PIXEL(32);
                    gBg0YPosition = gBg1YPosition - gSaXSpawnPosition.y + BLOCK_TO_SUB_PIXEL(17);

                    bgPosition = gBg1XPosition - gSaXSpawnPosition.x + BLOCK_TO_SUB_PIXEL(20);
                    if (bgPosition > BLOCK_TO_SUB_PIXEL(24))
                        position = TRUE;

                    bgPosition = gBg1YPosition - gSaXSpawnPosition.y + BLOCK_TO_SUB_PIXEL(13);
                    if (bgPosition > BLOCK_TO_SUB_PIXEL(12))
                        position = TRUE;

                    if (position)
                        gBg0XPosition = BLOCK_TO_SUB_PIXEL(8);
                    break;
                
                case BG_PROP_FOG:
                    gBg0YPosition = gBg1YPosition;
                    gBg0XPosition = gBg1XPosition;
                    break;
                
                case BG_PROP_SR388:
                    ScrollSr388Planet();
                    break;

                case BG_PROP_NIGHTMARE_SHADOW:
                    ScrollNightmareShadow();
                    break;

                default:
                    bg0Set = FALSE;
                    break;
            }
        }
    }

    if (!bg0Set)
    {
        gBg0YPosition = gBg1YPosition;
        gBg0XPosition = gBg1XPosition;
    }

    if (gCurrentRoomEntry.effectY == USHORT_MAX)
    {
        gEffectYPosition = 0;
    }
    else
    {
        position = gWaterMovement.yOffset + gCurrentRoomEntry.effectY + gWaterMovement.unk_8;
        if (position < 0)
            position = 0;
    
        gEffectYPosition = position;
    }
}

/**
 * @brief 6a5e4 | 60 | Handles the automatic scrolling of background 0
 *
 */
void ScrollAutoBg0(void)
{
    if (gBg0Movement.type == BG0_MOVEMENT_WATER)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.xOffset++;
    }
    else if (gBg0Movement.type == BG0_MOVEMENT_2)
    {
        if (MOD_AND(gBg0Movement.counter, 4) == 0)
            gBg0Movement.xOffset++;
    }
    else if (gBg0Movement.type == BG0_MOVEMENT_FOG)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.yOffset++;
    }
    else if (gBg0Movement.type == BG0_MOVEMENT_SNOWFLAKES)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.yOffset--;
    }

    gBg0Movement.counter++;
}

/**
 * @brief 6a644 | 80 | Gets the BG3 scrolling type
 *
 * @return u32 Types (y << 16 | x)
 */
u32 ScrollGetBg3Scroll(void)
{
    u32 xScroll;
    u32 yScroll;

    xScroll = BG3_SCROLLING_TYPE_NONE;
    yScroll = BG3_SCROLLING_TYPE_NONE;

    switch (gCurrentRoomEntry.bg3Scroll)
    {
        case 0:
            break;

        case 1:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_NONE;
            break;

        case 2:
            xScroll = BG3_SCROLLING_TYPE_NONE;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 3:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 4:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 5:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_NORMAL;
            break;

        case 6:
        case 10:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_NORMAL;
            break;
        
        case 9:
            xScroll = BG3_SCROLLING_TYPE_QUARTERED;
            yScroll = BG3_SCROLLING_TYPE_NONE;
            break;

        case 7:
        case 8:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_NONE;
            break;
    }

    return C_32_2_16(yScroll, xScroll);
}

/**
 * @brief 6a6c4 | f0 | Scrolls background 3
 *
 */
void ScrollBg3(void)
{
    s32 yScrolling;
    s32 xScrolling;
    s32 xVelocity;

    yScrolling = ScrollGetBg3Scroll();
    xScrolling = LOW_BYTE(yScrolling);
    yScrolling = HIGH_SHORT(yScrolling);

    if (xScrolling == BG3_SCROLLING_TYPE_NONE)
        gBg3XPosition += gCamera.frontWideXVelocity;
    else if (xScrolling == BG3_SCROLLING_TYPE_NORMAL)
        gBg3XPosition = gBg1XPosition;
    else if (xScrolling == BG3_SCROLLING_TYPE_HALVED)
        gBg3XPosition += (gCamera.xVelocity / 2) + gCamera.frontWideXVelocity;
    else if (xScrolling == BG3_SCROLLING_TYPE_QUARTERED)
        gBg3XPosition += (gCamera.xVelocity / 4) + gCamera.frontWideXVelocity;

    if (yScrolling == BG3_SCROLLING_TYPE_NONE)
    {
        if (gCurrentArea > AREA_NORMAL_LAST)
            gBg3YPosition = yScrolling;
        else 
            gBg3YPosition = -SCREEN_Y_BLOCK_PADDING;
    }
    else if (yScrolling == BG3_SCROLLING_TYPE_NORMAL)
    {
        gBg3YPosition = gBg1YPosition - SCREEN_Y_BLOCK_PADDING;
    }
    else
    {
        gBg3YPosition = (gBg1YPosition / 2) - SCREEN_Y_BLOCK_PADDING;
    }
}

/**
 * @brief 6a7b4 | 6c | Sets the initial BG3 position when a room is loaded
 *
 */
void ScrollSetInitialBg3Position(void)
{
    u32 xScroll;

    xScroll = LOW_BYTE(ScrollGetBg3Scroll());
    
    if (xScroll == BG3_SCROLLING_TYPE_NONE)
    {
        if (gCurrentArea > AREA_NORMAL_LAST)
            gBg3XPosition = 0;
        else
            gBg3XPosition = -SCREEN_X_BLOCK_PADDING;
    }
    else if (xScroll == BG3_SCROLLING_TYPE_HALVED)
    {
        gBg3XPosition = gBg1XPosition / 2;
    }
    else if (xScroll == BG3_SCROLLING_TYPE_QUARTERED)
    {
        gBg3XPosition = gBg1XPosition / 4;
    }
}

/**
 * @brief 6a820 | b0 | Handles the automatic scrolling of background 3
 *
 */
void ScrollAutoBg3(void)
{
    if (gBg3Movement.direction == 0)
        return;

    switch (gBg3Movement.direction)
    {
        case 1:
            if (MOD_AND(gBg3Movement.timer, 8) == 0)
                gBg3Movement.xOffset++;
            break;

        case 2:
            if (MOD_AND(gBg3Movement.timer, 8) == 0)
                gBg3Movement.xOffset--;
            break;

        case 3:
            if (gBg3Movement.leftToRightStage == 0)
            {
                if (MOD_AND(gBg3Movement.timer, 8) == 0)
                    gBg3Movement.xOffset++;
            }
            else if (gBg3Movement.leftToRightStage == 1)
            {
                gBg3Movement.timer = 0;
                gBg3Movement.leftToRightStage++;
            }
            else if (gBg3Movement.leftToRightStage == 2)
            {
                if (gBg3Movement.timer & 1)
                    gBg3Movement.xOffset += sBg3LeftToRightMovement[gBg3Movement.timer >> 1];

                if (gBg3Movement.timer == UCHAR_MAX)
                {
                    gBg3Movement.timer = 0;
                    gBg3Movement.leftToRightStage++;
                }
            }
            else
            {
                if (MOD_AND(gBg3Movement.timer, 8) == 0)
                    gBg3Movement.xOffset--;
            }
            break;
    }

    gBg3Movement.timer++;
}

/**
 * @brief 6a8d0 | a8 | Handles scrolling during no-clip when the camera is unlocked
 *
 */
void ScrollNoClipUnlockedCamera(struct RawCoordsX* pCoords)
{
    u16 x;
    u16 y;
    s32 size;

    if (pCoords->x < SCROLL_X_ANCHOR)
    {
        gBg1XPosition = 0;
    }
    else
    {
        x = pCoords->x;
        size = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].width);
        if (x > size - SCROLL_X_ANCHOR)
            gBg1XPosition = size - SCREEN_SIZE_X_SUB_PIXEL;
        else
            gBg1XPosition = x - SCROLL_X_ANCHOR;
    }

    if (pCoords->y < SCROLL_Y_ANCHOR)
    {
        gBg1YPosition = 0;
    }
    else
    {
        y = pCoords->y;
        size = BLOCK_TO_SUB_PIXEL(gBackgroundsData.backgrounds[1].height);
        if (y > size - BLOCK_TO_SUB_PIXEL(3))
            gBg1YPosition = size - BLOCK_TO_SUB_PIXEL(9);
        else
            gBg1YPosition = y - SCROLL_Y_ANCHOR;
    }
}

/**
 * @brief 6a978 | 29c | Handles Nightmare's shadow moving in the background
 *
 */
void ScrollNightmareShadow(void)
{
    s32 tmp;
    s32 xOffset;

    if (gUnk_3004e30.unk_0 > 4 && gScreenShakeX.timer < 8)
        ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 0);

    gUnk_3004e30.unk_6++;

    switch (gUnk_3004e30.unk_0)
    {
        case 0:
            gBg0XPosition = sNightmareShadowPositions[1][0];
            gBg0YPosition = sNightmareShadowPositions[1][1];
            gUnk_3004e30.unk_4 = 0;
            gUnk_3004e30.unk_3 = 0;
            gUnk_3004e30.unk_1 = 0;
            gUnk_3004e30.unk_2 = 0;
            gUnk_3004e30.unk_6 = 0;

            if (gEventCounter == EVENT_ICE_MISSILE_DATA_DOWNLOADED)
            {
                gUnk_3004e30.unk_0 = 1;
                gUnk_3004e30.unk_6 = CONVERT_SECONDS(5);
            }
            else if (gEventCounter > EVENT_ICE_MISSILE_DATA_DOWNLOADED)
            {
                gUnk_3004e30.unk_2 = 1;
                gUnk_3004e30.unk_0 = 2;
                gUnk_3004e30.unk_6 = CONVERT_SECONDS(4);
            }
            else
            {
                gUnk_3004e30.unk_0 = 4;
            }
            break;
        
        case 1:
            if (gUnk_3004e30.unk_3 > 1)
            {
                gUnk_3004e30.unk_0 = 4;
                gBg0XPosition = sNightmareShadowPositions[1][0];
                gBg0YPosition = sNightmareShadowPositions[1][1];
            }
            else if (gUnk_3004e30.unk_6 > CONVERT_SECONDS(6))
            {
                gUnk_3004e30.unk_0 = 3;
                gUnk_3004e30.unk_6 = 0;
                gUnk_3004e30.unk_5 = 0;
                gUnk_3004e30.unk_3++;
            }
            break;
        
        case 2:
            if (gUnk_3004e30.unk_6 > CONVERT_SECONDS(6))
            {
                gUnk_3004e30.unk_0 = 3;
                gUnk_3004e30.unk_6 = 0;
                gUnk_3004e30.unk_5 = 0;
                gUnk_3004e30.unk_3++;
            }
            break;
        
        case 3:
            if (gUnk_3004e30.unk_1 == 5)
            {
                gUnk_3004e30.unk_0 = 6;
            }
            else if (gUnk_3004e30.unk_1 == 6)
            {
                gUnk_3004e30.unk_0 = 5;
            }
            else
            {
                if (gSamusData.direction == KEY_RIGHT)
                    gUnk_3004e30.unk_0 = 5;
                else
                    gUnk_3004e30.unk_0 = 6;
            }

            tmp = MOD_AND(gFrameCounter8Bit + (gFrameCounter16Bit >> 3), ARRAY_SIZE(sNightmareShadowYVelocityOffsets));
            gUnk_3004e30.unk_5 = sNightmareShadowYVelocityOffsets[tmp];

            if (gUnk_3004e30.unk_0 == 5)
                gUnk_3004e30.unk_4 = 1;
            else if (gUnk_3004e30.unk_0 == 6)
                gUnk_3004e30.unk_4 = 2;
            else
                gUnk_3004e30.unk_4 = 0;

            gBg0XPosition = sNightmareShadowPositions[gUnk_3004e30.unk_4][0];
            gBg0YPosition = sNightmareShadowPositions[gUnk_3004e30.unk_4][1];
            SoundPlay(SOUND_NIGHTMARE_SHADOW_MOVING);
            gUnk_3004e30.unk_6 = 0;
            break;
        
        case 5:
            xOffset = gUnk_3004e30.unk_6;
            if (xOffset > BLOCK_TO_SUB_PIXEL(.625f))
                xOffset = BLOCK_TO_SUB_PIXEL(.625f);

            gBg0XPosition -= xOffset;
            tmp = (((sNightmareShadowPositions[gUnk_3004e30.unk_4][0] - gBg0XPosition) >> 8) + 2) * 3;
            gBg0YPosition += gUnk_3004e30.unk_5 + tmp;

            if (gBg0XPosition < BLOCK_TO_SUB_PIXEL(16))
            {
                if (gUnk_3004e30.unk_1 != 0)
                    gUnk_3004e30.unk_1 = 0;
                else
                    gUnk_3004e30.unk_1 = gUnk_3004e30.unk_0;

                gUnk_3004e30.unk_6 = 0;
                gUnk_3004e30.unk_0 = gUnk_3004e30.unk_2 != 0 ? 2 : 1;
            }
            break;

        case 6:
            xOffset = gUnk_3004e30.unk_6;
            if (xOffset > BLOCK_TO_SUB_PIXEL(.625f))
                xOffset = BLOCK_TO_SUB_PIXEL(.625f);

            gBg0XPosition += xOffset;
            tmp = (((gBg0XPosition - sNightmareShadowPositions[gUnk_3004e30.unk_4][0]) >> 8) + 2) * 3;
            gBg0YPosition += gUnk_3004e30.unk_5 + tmp;

            if (gBg0XPosition > BLOCK_TO_SUB_PIXEL(41))
            {
                if (gUnk_3004e30.unk_1 != 0)
                    gUnk_3004e30.unk_1 = 0;
                else
                    gUnk_3004e30.unk_1 = gUnk_3004e30.unk_0;

                gUnk_3004e30.unk_6 = 0;
                gUnk_3004e30.unk_0 = gUnk_3004e30.unk_2 != 0 ? 2 : 1;
            }
            break;

        case 7:
            if (gChangedInput & KEY_SELECT)
                gUnk_3004e30.unk_0 = gUnk_3004e30.unk_2 != 0 ? 2 : 1;
            break;
    }
}

/**
 * @brief 6ac14 | a8 | Handles SR388 moving in the background
 *
 */
void ScrollSr388Planet(void)
{
    s32 xOffset;

    gUnk_3004e30.unk_6++;

    switch (gUnk_3004e30.unk_0)
    {
        case 0:
            gEffectYPosition = 0;
            gUnk_3004e30.unk_4 = 0;
            gUnk_3004e30.unk_2 = 0;
            gUnk_3004e30.unk_6 = 0;
            gUnk_3004e30.unk_1 = 0;
            gUnk_3004e30.unk_0 = 1;

            gBg0YPosition = BLOCK_TO_SUB_PIXEL(2);
            gBg0XPosition = BLOCK_TO_SUB_PIXEL(28);
            break;

        case 1:
            if (gDisableDrawingSamusAndScrollingFlag)
            {
                gUnk_3004e30.unk_0 = 2;
                gUnk_3004e30.unk_6 = 0;
            }
            break;

        case 2:
            xOffset = (gBg0XPosition - BLOCK_TO_SUB_PIXEL(20)) >> 7;
            if (xOffset > 5)
                xOffset = 5;
            else if (xOffset <= 0)
                xOffset = 1;

            gBg0XPosition -= xOffset;

            if (gBg0XPosition <= BLOCK_TO_SUB_PIXEL(20))
                gUnk_3004e30.unk_0 = 3;
            break;
    }
}
