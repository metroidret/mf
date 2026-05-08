#ifndef NEW_FILE_INTRO_H
#define NEW_FILE_INTRO_H

#include "types.h"

#include "constants/game_state.h"

extern u16** sLocationTextPointers[LANGUAGE_COUNT];
extern u16** sMessageTextPointers[LANGUAGE_COUNT];

boolu32 IntroHandler(void);
boolu32 NewFileIntroHandler(void);
boolu32 unk_87920(void);
void NewFileIntroSamusShipFlyingVblank(void);

#endif /* NEW_FILE_INTRO_H */
