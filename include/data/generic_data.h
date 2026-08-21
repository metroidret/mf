#ifndef GENERIC_DATA_H
#define GENERIC_DATA_H

#include "types.h"
#include "macros.h"

extern const s16 sSineTable[Q_8_8(1.f) + PI / 2];

extern const void* const sSaveDataSramPointers[3];
extern const void* const sSaveDataSramBackupPointers[3];
extern const void* const sUnk_a5270[2];

#endif /* GENERIC_DATA_H */
