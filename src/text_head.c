#include "globals.h"
#include "new_file_intro.h"

#include "structs/event.h"
#include "structs/samus.h"

#include "data/event_data.h"

#include "data/menus/pause_debug.h"

u8 GetCharacterWidth(u16 idx) 
{
    if (idx >= ARRAY_SIZE(sCharacterWidths))
        return 10; 
    return sCharacterWidths[idx];
}

