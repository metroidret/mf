#ifndef IN_GAME_TIMER_STRUCT_H
#define IN_GAME_TIMER_STRUCT_H

#include "types.h"

struct InGameTimer {
    u8 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

extern u8 gMaxInGameTimeFlag;
extern struct InGameTimer gInGameTimer;

#endif /* IN_GAME_TIMER_STRUCT_H */