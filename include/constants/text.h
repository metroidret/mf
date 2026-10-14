#ifndef TEXT_CONSTANTS_H
#define TEXT_CONSTANTS_H

#include "types.h"

/**
 * @brief Mask to get the parameter type of special text parameters
 * 
 */
#define CHAR_MASK           C_16_2_8(0xFF, 0)

/**
 * @brief Text parameter to add an arbitrary horizontal spacing
 * 
 */
#define CHAR_WIDTH_MASK     C_16_2_8(0x80, 0)

/**
 * @brief Text parameter to change the current horizontal cursor position
 * 
 */
#define CHAR_INDENT_MASK    C_16_2_8(0x83, 0)

/**
 * @brief Indicates that the next page arrow should be displayed
 * 
 */
#define CHAR_NEXT_PAGE_ARROW	C_16_2_8(0xFC, 0)

/**
 * @brief Indicates that the text should change page
 * 
 */
#define CHAR_NEW_PAGE       C_16_2_8(0xFD, 0)

/**
 * @brief Indicates that the text should change line
 * 
 */
#define CHAR_NEW_LINE       C_16_2_8(0xFE, 0)

/**
 * @brief Text terminator
 * 
 */
#define CHAR_TERMINATOR     C_16_2_8(0xFF, 0)

#endif /* TEXT_CONSTANTS_H */
