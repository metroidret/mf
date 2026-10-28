#ifndef INTRO_H
#define INTRO_H

#include "types.h"

#include "structs/cutscene.h"

void unk_9209c(void);
boolu32 IntroSamusInShipProcess(void);
void IntroShipAlertInit(void);
boolu32 IntroShipAlertProcess(void);
void IntroSamusDriftingOutInit(void);
boolu32 IntroSamusDriftingOutProcess(void);
boolu32 IntroSamusShipCrashing(void);
void unk_92d0c(struct SpecialCutsceneOam* pOam);
void IntroProcessDriftingShip(struct SpecialCutsceneOam* pOam);

u8 IntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);

#endif /* INTRO_H */
