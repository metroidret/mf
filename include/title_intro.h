#ifndef TITLE_INTRO_H
#define TITLE_INTRO_H

#include "types.h"

#include "structs/cutscene.h"

void unk_9209c(void);
boolu32 TitleIntroSamusInShipProcess(void);
void TitleIntroShipAlertInit(void);
boolu32 TitleIntroShipAlertProcess(void);
void TitleIntroSamusDriftingOutInit(void);
boolu32 TitleIntroSamusDriftingOutProcess(void);
boolu32 TitleIntroSamusShipCrashing(void);
void unk_92d0c(struct SpecialCutsceneOam* pOam);
void TitleIntroProcessDriftingShip(struct SpecialCutsceneOam* pOam);

u8 TitleIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);

#endif /* TITLE_INTRO_H */
