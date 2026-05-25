#ifndef PAUSE_DEBUG_DATA_H
#define PAUSE_DEBUG_DATA_H

#include "types.h"
#include "oam.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/menus/pause_debug.h"

#define PAUSE_DEBUG_SECTION_INFO_TOP(section) (sDebugSectionInfo[(section)][0])
#define PAUSE_DEBUG_SECTION_INFO_BOTTOM(section) (sDebugSectionInfo[(section)][1])
#define PAUSE_DEBUG_SECTION_INFO_LEFT(section) (sDebugSectionInfo[(section)][2])
#define PAUSE_DEBUG_SECTION_INFO_RIGHT(section) (sDebugSectionInfo[(section)][3])
#define PAUSE_DEBUG_SECTION_INFO_SECTION(section) (sDebugSectionInfo[(section)][4])
#define PAUSE_DEBUG_SECTION_INFO_HSIZE(section) (PAUSE_DEBUG_SECTION_INFO_RIGHT((section)) - PAUSE_DEBUG_SECTION_INFO_LEFT((section)))

extern const u8 sPauseDebugBeamFlags[5];
extern const u8 sPauseDebugMissileFlags[4];
extern const u8 sPauseDebugBombFlags[2];
extern const u8 sPauseDebugSuitFlags[2];
extern const u8 sPauseDebugMiscFlags[5];

extern const u8 sStatusScreenSectionSizes[5];

extern const u8 sBlob_58217b_58225c[];

extern const u16 sPauseDebugNumbersIncrementValues[5];
extern const u16 sPauseDebugNumbersMaxValues[3];

// ... 

#define EVENT_NAME_SIZE 28
extern const u8 sPauseDebugEventNames[EVENT_END][EVENT_NAME_SIZE];

extern const u8 sDebugLocationSectionInfo[2][2];
extern const u8 sDebugSectionInfo[PAUSE_DEBUG_SECTION_END][5];

#endif /* PAUSE_DEBUG_DATA_H */
