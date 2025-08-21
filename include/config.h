#ifndef CONFIG_H
#define CONFIG_H

/**
 * @brief Enables debug features, mainly the boot debug menu and the pause debug menu, among other things
 * 
 * (see docs/debug.md for more details)
 * 
 */
// #define DEBUG

/**
 * @brief Indicates that the game is being compiled using a modern compiler
 * This enables certain features that agbcc lacks
 * 
 */
// #define MODERN

/**
 * @brief Enables various fixes to known bugs, issues, or bad code.
 * 
 * (see docs/bugs_and_glitches.md for reference)
 * 
 */
// #define BUGFIX

/**
 * @brief Enables the use of actual symbols instead of hardcoded pointers for things in Ewram
 * 
 */
// #define USE_EWRAM_SYMBOLS

#endif /* CONFIG_H*/
