#ifndef PAUSE_DEBUG_STRUCTS_H
#define PAUSE_DEBUG_STRUCTS_H

#include "types.h"
#include "oam.h"

struct PauseDebugOptions {
    union {
        struct {
            u16 cnt;
            u8 alpha_evb;
            u8 alpha_eva;
        } split;
        struct {
            u16 cnt;
            u16 alpha;
        } whole;
    } bld;
    u8 bldalpha_evy;
    u8 frontWideCamera;
    u8 sectionCursor;
    u8 sectionSelector;
    u8 downloadedMaps;
    u8 securityHatchLevel;
    u8 mapScanLRAndStereo;
};

extern struct PauseDebugOptions gPauseDebugOptions;

#endif /* PAUSE_DEBUG_STRUCTS_H */
