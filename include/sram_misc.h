#ifndef SRAM_MISC_H
#define SRAM_MISC_H

#include "types.h"

void EraseSram_Unused(void);
void EraseSram(void);
void unk_c98(void);
void unk_cd8(void);
void unk_cf0(void);
void WriteMostRecentFileToSram(void);
void WriteMostRecentFileBackupToSram(void);
void ReadAllFilesToEwram(void);
void ReadMostRecentFileToEwram(void);
void ReadSramHeaderToEwram(void);
void unk_dd4(void);
void unk_dec(u8 param0);
void unk_e14(void);
void unk_e2c(void);

#endif /* SRAM_MISC_H */
