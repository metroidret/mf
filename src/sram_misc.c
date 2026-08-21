#include "sram_misc.h"

#include "gba.h"
#include "sram/sram.h"
#include "types.h"

#include "data/generic_data.h"
#include "data/sram_pointers.h"

#include "structs/save_file.h"

/**
 * @brief c28 | 38 | Erases all save files, excluding the SRAM header (unused)
 *
 */
void EraseSram_Unused(void)
{
    BitFill(3, USHORT_MAX, EWRAM_SRAM + SRAM_FULL_HEADER_SIZE, SRAM_SIZE - SRAM_FULL_HEADER_SIZE, 16);
    SramWrite((u8*)EWRAM_SRAM + SRAM_FULL_HEADER_SIZE, SRAM_BASE + SRAM_FULL_HEADER_SIZE,
        SRAM_SIZE - SRAM_FULL_HEADER_SIZE);
}

/**
 * @brief c60 | 38 | Fully erases all the contents of SRAM
 *
 */
void EraseSram(void)
{
    BitFill(3, USHORT_MAX, EWRAM_SRAM, SRAM_SIZE, 16);
    SramWrite((u8*)EWRAM_SRAM, SRAM_BASE, SRAM_SIZE);
}

/**
 * @brief c98 | 40 | To document
 *
 */
void unk_c98(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM, (u8*)SRAM_BASE, 0x80);
    DMA3_COPY_16(EWRAM_SRAM, EWRAM_SRAM + 0x7100, 0x40);
    SramWriteChecked((u8*)EWRAM_SRAM + 0x7100, (u8*)SRAM_BASE + 0x7100, 0x80);
}

/**
 * @brief cd8 | 18 | To document
 *
 */
void unk_cd8(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM + SRAM_HEADER_SIZE, (u8*)SRAM_BASE + SRAM_HEADER_SIZE, SRAM_HEADER_SIZE);
}

/**
 * @brief cf0 | 18 | To document
 *
 */
void unk_cf0(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM + 0x7100, (u8*)SRAM_BASE + 0x7100, 0x80);
}

/**
 * @brief d08 | 2c | To document
 *
 */
void WriteMostRecentFileToSram(void)
{
    SramWrite((u8*)sSaveDataEwramPointers[gMostRecentSaveFile], (u8*)sSaveDataSramPointers[gMostRecentSaveFile],
        sizeof(struct SaveFile));
}

/**
 * @brief d34 | 2c | To document
 *
 */
void WriteMostRecentFileBackupToSram(void)
{
    SramWrite((u8*)sSaveDataEwramBackupPointers[gMostRecentSaveFile],
        (u8*)sSaveDataSramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile));
}

/**
 * @brief d60 | 1c | To document
 *
 */
void ReadAllFilesToEwram(void)
{
    SramWriteUnchecked((u8*)SRAM_BASE + 0x200, (u8*)EWRAM_SRAM + 0x200, 0x7e00);
}

/**
 * @brief d7c | 2c | To document
 *
 */
void ReadMostRecentFileToEwram(void)
{
    SramWriteUnchecked((u8*)sSaveDataSramPointers[gMostRecentSaveFile],
        (u8*)sSaveDataEwramPointers[gMostRecentSaveFile], sizeof(struct SaveFile));
}

/**
 * @brief da8 | 2c | To document
 *
 */
void ReadSramHeaderToEwram(void)
{
    SramWriteUnchecked((u8*)SRAM_BASE, (u8*)EWRAM_SRAM, 0x100);
    SramWriteUnchecked((u8*)SRAM_BASE + 0x7100, (u8*)EWRAM_SRAM + 0x7100, 0x80);
}

/**
 * @brief dd4 | 18 | To document
 *
 */
void unk_dd4(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM + 0x7000, (u8*)SRAM_BASE + 0x7000, 0x40);
}

/**
 * @brief dec | 28 | To document
 *
 */
void unk_dec(u8 param0)
{
    SramWriteChecked((u8*)sUnk_582280[param0], (u8*)sUnk_a5270[param0], 0x40);
}

/**
 * @brief e14 | 18 | To document
 *
 */
void unk_e14(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM + 0x7ff0, (u8*)SRAM_BASE + 0x7ff0, 0x10);
}

/**
 * @brief e2c | 1c | To document
 *
 */
void unk_e2c(void)
{
    SramWriteChecked((u8*)EWRAM_SRAM + 0x7800, (u8*)SRAM_BASE + 0x7800, 0x400);
}
