#ifndef SAVE_FILE_STRUCT_H
#define SAVE_FILE_STRUCT_H

#include "types.h"
#include "gba/memory.h"

#define EWRAM_SRAM (EWRAM_BASE + 0x38000)
#define SRAM_HEADER_SIZE 0x80
#define SRAM_FULL_HEADER_SIZE (SRAM_HEADER_SIZE * 2)

struct SaveFile {
    u8 todo[0x1200];
};

extern u8 gMostRecentSaveFile;

#endif /* SAVE_FILE_STRUCT_H */
