#ifndef PAUSE_SCREEN_MISC_DATA_H
#define PAUSE_SCREEN_MISC_DATA_H

#include "types.h"
#include "gba/memory.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/menus/pause_debug.h"
#include "constants/minimap.h"
#include "constants/navigation.h"
#include "constants/samus.h"

#define PAUSE_DEBUG_SECTION_INFO_TOP(section) (sDebugSectionInfo[(section)][0])
#define PAUSE_DEBUG_SECTION_INFO_BOTTOM(section) (sDebugSectionInfo[(section)][1])
#define PAUSE_DEBUG_SECTION_INFO_LEFT(section) (sDebugSectionInfo[(section)][2])
#define PAUSE_DEBUG_SECTION_INFO_RIGHT(section) (sDebugSectionInfo[(section)][3])
#define PAUSE_DEBUG_SECTION_INFO_SECTION(section) (sDebugSectionInfo[(section)][4])
#define PAUSE_DEBUG_SECTION_INFO_HSIZE(section) (PAUSE_DEBUG_SECTION_INFO_RIGHT((section)) - PAUSE_DEBUG_SECTION_INFO_LEFT((section)))

extern const u8 sPauseScreenAreaNameOamIds[AREA_NORMAL_COUNT][2];
extern const u8 sPauseScreenSecurityLevelOamInfo[SECURITY_LEVEL_COUNT - 1][2];

enum PauseOamInfo {
    PAUSE_OAM_INDEX,
    PAUSE_OAM_ID,
    PAUSE_OAM_X_POSITION,
    PAUSE_OAM_Y_POSITION,

    PAUSE_OAM_INFO_COUNT
};

extern const u8 sPauseScreenMapArrowOamInfo[4][PAUSE_OAM_INFO_COUNT];

extern const u8 sPauseDebugBeamFlags[5];
extern const u8 sPauseDebugMissileFlags[4];
extern const u8 sPauseDebugBombFlags[2];
extern const u8 sPauseDebugSuitFlags[2];
extern const u8 sPauseDebugMiscFlags[5];

extern const u8 sStatusScreenSectionSizes[5];

extern const u16 sPauseDebugNumbersIncrementValues[5];
extern const u16 sPauseDebugNumbersMaxValues[3];

extern const u8 sMinimapHudColorMapping_Low[MINIMAP_TILE_TYPE_COUNT][PAL_ROW];
extern const u8 sMinimapHudColorMapping_High[MINIMAP_TILE_TYPE_COUNT][PAL_ROW];

extern const void* const sMapScreenTimeTankVramAddresses[MAP_SCREEN_TANK_TIME_COUNT];

extern const u8 sMaintainedInputDelays[7];

// ...

extern const u8 sCharacterWidths[1184];

// ...

extern const u8 sNavConversationTextBoxCursorYPositions[NAV_TEXT_BOX_COUNT][2];

// ...

extern const u8 sNavConversationPortraitOamIds[6][3];

// ...

#define EVENT_NAME_SIZE 28
extern const u8 sPauseDebugEventNames[EVENT_END][EVENT_NAME_SIZE];

extern const u8 sDebugLocationSectionInfo[2][2];
extern const u8 sDebugSectionInfo[PAUSE_DEBUG_SECTION_END][5];

#endif /* PAUSE_SCREEN_MISC_DATA_H */
