#ifndef NEW_FILE_INTRO_H
#define NEW_FILE_INTRO_H

#include "types.h"

#include "constants/new_file_intro.h"
#include "constants/game_state.h"

extern const u32* sIntroSamusSittingBgGfxPointers[5];
extern const u32* sTitleIntroCollisionWarningBgGfxPointers[5];
extern const u32* sTitleIntroCollisionWarningObjGfxPointers[6];
extern const u16** sLocationTextPointers[LANGUAGE_COUNT];
extern u16** sMessageTextPointers[LANGUAGE_COUNT];

boolu32 IntroHandler(void);
boolu32 NewFileIntroHandler(void);
boolu32 unk_87920(void);
void NewFileIntroSamusShipFlyingInit(void);
boolu32 NewFileIntroSamusShipFlyingProcess(void);
boolu32 NewFileIntroSamusShipFlying(void);
void NewFileIntroSamusFaintingInit(void);
boolu32 NewFileIntroSamusFaintingProcess(void);
boolu32 NewFileIntroSamusFainting(void);
u8 NewFileIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearchOrder);
boolu32 NewFileIntroSamusDrifting(void);
void NewFileIntroProcessOam_Empty(void);
void NewFileIntroProcessTextCursor(struct SpecialCutsceneOam* pOam);
void NewFileIntroSr388PreviewVblank(void);
u8 NewFileIntroSr388SetupOam(u8 type, s16 xPosition, s16 yPosition);
boolu32 NewFileIntroSr388Preview(void);
void NewFileIntroSetupSr388PreviewAsteroid(u8 type, s16 xPosition, s16 yPosition, s16 arg3);
void NewFileIntroInSr388Vblank(void);
u8 NewFileIntroInSr388SetupOam(IntroInSr388OamType type, s16 xPosition, s16 yPosition);
boolu32 NewFileIntroInSr388(void);
void NewFileIntroGetPositionOfOamByType(IntroInSr388OamType type, s16* pXPosition, s16* pYPosition);
void NewFileIntroSamusGettingCuredVblank(void);
u8 NewFileIntroSamusGettingCuredSetupOam(IntroSamusGettingCuredOamType type, s16 xPosition, s16 yPosition);
void NewFileIntroSamusGettingCuredNervousSystemVblank(void);
boolu32 NewFileIntroSamusGettingCured(void);
void NewFileIntroSamusGettingCuredProcessOam_Empty(struct SpecialCutsceneOam* pOam);
u8 NewFileIntroFindOamByType(IntroSamusGettingCuredOamType type);
u8 NewFileIntroSamusFoundSetupOam(IntroSamusFoundOamType type, s16 xPosition, s16 yPosition);
void NewFileIntroSamusFoundVblank(void);
boolu32 NewFileIntroSamusFound(void);
u8 NewFileIntroSamusCuredSetupOam(IntroSamusCuredOamType type, s16 xPosition, s16 yPosition);
void NewFileIntroSamusCuredVblank(void);
boolu32 NewFileIntroSamusCured(void);
void NewFileIntroSamusCuredProcessOam_Empty(struct SpecialCutsceneOam* pOam);
void NewFileIntroArrivingAtBslVblank(void);
boolu32 NewFileIntroArrivingAtBsl(void);
u8 NewFileIntroArrivingAtBslSetupOam(IntroArrivingAtBslOamType type, s16 xPosition, s16 yPosition);
u8 NewFileIntroGetPositionAndSlotOfOamByType(IntroArrivingAtBslOamType type, s16* pXPosition, s16* pYPosition);
void NewFileIntroArrivingAtBslProcessOam_Empty(struct SpecialCutsceneOam* pOam);
u8 NewFileIntroLandingOnBslSetupOam(IntroLandingOnBslOamType type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void NewFileIntroLandingOnBslVblank(void);
boolu32 NewFileIntroLandingOnBsl(void);
u8 NewFileIntroGetPositionAndSlotOfOamByType_2(IntroLandingOnBslOamType type, s16* pXPosition, s16* pYPosition);

#endif /* NEW_FILE_INTRO_H */
