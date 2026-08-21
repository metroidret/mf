#ifndef CONNECTION_DATA_H
#define CONNECTION_DATA_H

#include "types.h"

#include "constants/clipdata.h"
#include "constants/connection.h"

#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/escape.h"

extern const u8 sDimLightingEvents[4][DIM_EVENT_FIELD_COUNT];

extern const struct NavigationRoomHatchLockEvent sNavigationRoomHatchLockEvents[89];
extern const struct HatchLockEvent sHatchLockEvents[75];

extern const struct EscapeDigits sEscapeDigits_9Minutes;

extern const u8 sAreaConnections[36][AREA_CONNECTION_FIELD_COUNT];
extern const struct ElevatorRoomPair sElevatorRoomPairs[ELEVATOR_END];
extern const struct ElevatorDisabledEvent sElevatorDisabledEvents[4];
extern const u8 sEventBasedConnections[60][EVENT_BASED_CONNECTION_FIELD_COUNT];

#endif /* CONNECTION_DATA_H */
