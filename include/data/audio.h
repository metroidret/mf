#ifndef AUDIO_DATA_H
#define AUDIO_DATA_H

#include "constants/audio.h"
#include "structs/audio.h"

extern const u16 sUnk_a5278[128];
extern const u8 sClockTable[49];
extern const u8 sNoiseTable[60];
extern const u8 sCgb3Vol[16];
extern const u8 sUnk_a53f5[19];

extern const u32 sNativeSampleRate[SOUND_MODE_FREQ_END];
extern const u32 sMusicPitchData[SOUND_MODE_FREQ_END];
extern const u16 sPcmSamplesPerVBlankTable[SOUND_MODE_FREQ_END];

extern const u8 sArray_a548a[512];

extern void* const sDma1ControlPointer;
extern const u32 sDma1ControlValue;

extern const MusicFunc_T sMusicCommandFunctionPointers[30];

extern const struct TrackGroupRomData sMusicTrackDataRom[8];

extern const struct SoundEntry sSoundDataEntries[745];

#endif /* AUDIO_DATA_H */
