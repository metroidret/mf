#include "text.h"

#include "data/menus/pause_debug.h"

u8 GetCharacterWidth(u16 idx)
{
    if (idx >= ARRAY_SIZE(sCharacterWidths))
        return 10;
    return sCharacterWidths[idx];
}
