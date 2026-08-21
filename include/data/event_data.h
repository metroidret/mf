#ifndef EVENT_DATA_H
#define EVENT_DATA_H

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/samus.h"

#include "structs/event.h"

extern const struct EventLocationAndNavigationInfo sEventLocationAndNavigationInfo[EVENT_END];

extern const u8 sNumberOfTanksPerArea[AREA_NORMAL_COUNT + 1][TANK_COUNT];

extern const u8 sObtainItemEvents[ABILITY_COUNT_END + 1];
extern const struct AbilityRamValue sAbilityRamValues[ABILITY_COUNT_END];

extern const u8 sNavigationRoomLocations[NAV_ROOM_COUNT][2];
extern const u8 sNavigationTargetLocationAreas[NAV_TARGET_LOC_END];

extern const u8 sEvent_576073[AREA_END];
extern const u8 sEvent_57607D[13];
extern const u8 sEvent_57608A[13];

extern const struct MonologueEvent sMonologueEvents[6];
extern const struct SecurityUnlockEvent sSecurityUnlockEvents[SECURITY_LEVEL_END - 1];

#endif /* EVENT_DATA_H */
