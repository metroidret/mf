#include "menus/status_screen.h"

#include "menus/pause_debug.h"
#include "globals.h"
#include "gba.h"
#include "macros.h"
#include "event.h"

#include "data/menus/pause_debug.h"
#include "data/event_data.h"

#include "constants/menus/pause_debug.h"
#include "constants/connection.h"
#include "constants/samus.h"

#include "structs/menus/pause_debug.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/*
 * Scaffold for the StatusScreen* cluster.
 * Decompiled functions land here, one at a time, in baserom
 * address order. Each function added must also be removed from
 * the corresponding asm/disasm_*.s and verified with
 * tools/agent/compile_and_view_assembly.py before commit.
 */
