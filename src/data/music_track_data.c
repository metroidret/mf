#include "types.h"
#include "macros.h"

#include "structs/audio.h"

// FIXME: Replace pointers
const struct TrackGroupRomData sMusicTrackDataRom[8] = {
    [0] = {
        .pTrack = &gTrackData0,
        .pVariables = gTrack0Variables,
        .maxAmountOfTracks = 10,
        .unk_A = 0
    },
    [1] = {
        .pTrack = &gTrackData1,
        .pVariables = gTrack1Variables,
        .maxAmountOfTracks = 10,
        .unk_A = 1
    },
    [2] = {
        .pTrack = &gTrackData2,
        .pVariables = gTrack2Variables,
        .maxAmountOfTracks = 2,
        .unk_A = 1
    },
    [3] = {
        .pTrack = &gTrackData3,
        .pVariables = gTrack3Variables,
        .maxAmountOfTracks = 2,
        .unk_A = 0
    },
    [4] = {
        .pTrack = &gTrackData4,
        .pVariables = gTrack4Variables,
        .maxAmountOfTracks = 2,
        .unk_A = 1
    },
    [5] = {
        .pTrack = &gTrackData5,
        .pVariables = gTrack5Variables,
        .maxAmountOfTracks = 2,
        .unk_A = 1
    },
    [6] = {
        .pTrack = &gTrackData6,
        .pVariables = gTrack6Variables,
        .maxAmountOfTracks = 3,
        .unk_A = 0
    },
    [7] = {
        .pTrack = &gTrackData7,
        .pVariables = gTrack7Variables,
        .maxAmountOfTracks = 1,
        .unk_A = 1
    }
};
