#ifndef CONNECTION_STRUCTS_H
#define CONNECTION_STRUCTS_H

#include "types.h"
#include "constants/connection.h"

struct HatchData {
    u8 exists:1;
    u8 currentAnimation:3;
    u8 facingRight:1;
    u8 lockType:3;
    u8 state:2;
    u8 locked:1;
    u8 unk_1_3:5;
    u8 xPosition;
    u8 yPosition;
};

struct Door {
    u8 type;
    u8 srcRoom;
    u8 xStart;
    u8 xEnd;
    u8 yStart;
    u8 yEnd;
    u8 dstDoor;
    s8 xExit;
    s8 yExit;
};

struct ElevatorRoomPair {
    u8 area1;
    u8 room1;
    u8 area2;
    u8 room2;
};

struct ElevatorDisabledEvent {
    u8 eventStart;
    u8 eventEnd;
    u8 disabledElevators[ELEVATOR_END];
};

struct NavigationRoomHatchLockEvent {
    // 0
    u8 event;
    // 1
    u8 room1LeftHatch:1;
    u8 room1RightHatch:1;
    u8 room2LeftHatch:1;
    u8 room2RightHatch:1;
    u8 room3LeftHatch:1;
    u8 room3RightHatch:1;
    u8 room4LeftHatch:1;
    u8 room4RightHatch:1;
    // 2
    u8 room5LeftHatch:1;
    u8 room5RightHatch:1;
    u8 room6LeftHatch:1;
    u8 room6RightHatch:1;
    u8 room7LeftHatch:1;
    u8 room7RightHatch:1;
    u8 room8LeftHatch:1;
    u8 room8RightHatch:1;
    // 3
    u8 room9LeftHatch:1;
    u8 room9RightHatch:1;
    u8 room10LeftHatch:1;
    u8 room10RightHatch:1;
    u8 room11LeftHatch:1;
    u8 room11RightHatch:1;
};

struct HatchLockEvent {
    u8 event;
    u8 area;
    u8 room;
    u8 hatch0:1;
    u8 hatch1:1;
    u8 hatch2:1;
    u8 hatch3:1;
    u8 hatch4:1;
    u8 hatch5:1;
};

enum DimEventField {
    DIM_EVENT_FIELD_EVENT,
    DIM_EVENT_FIELD_FLAG,

    DIM_EVENT_FIELD_COUNT
};

enum AreaConnectionField {
    AREA_CONNECTION_FIELD_SOURCE_AREA,
    AREA_CONNECTION_FIELD_SOURCE_DOOR,
    AREA_CONNECTION_FIELD_DESTINATION_AREA,

    AREA_CONNECTION_FIELD_COUNT
};

enum EventBasedConnectionField {
    EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA,
    EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR,
    EVENT_BASED_CONNECTION_FIELD_EVENT,
    EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR,

    EVENT_BASED_CONNECTION_FIELD_COUNT
};

extern u8 gCurrentArea;
extern u8 gPreviousArea;
extern u8 gDestinationRoom;
extern u8 gCurrentRoom;
extern u8 gLastDoorUsed;
extern u8 gLastDoorProperties;
extern u8 gCurrentNavigationRoom;

#define MAX_AMOUNT_OF_HATCHES 6

extern struct HatchData gHatchData[MAX_AMOUNT_OF_HATCHES];
extern u8 gHatchDoorIds[MAX_AMOUNT_OF_HATCHES];
extern struct RawCoordsX gDoorPositionStart;
extern u8 gLockedHatches;
extern s16 gSamusDoorPositionOffset;

#endif /* CONNECTION_STRUCTS_H */
