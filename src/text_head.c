#include "globals.h"
#include "new_file_intro.h"

#include "structs/event.h"
#include "structs/samus.h"

#include "data/event_data.h"

#include "data/menus/pause_debug.h"

extern const u8 sCharacterWidths[1184];

u8 GetCharacterWidth(u16 idx) {
    if (idx >= sizeof(sCharacterWidths))
        return 10; 
    return sCharacterWidths[idx];
}

