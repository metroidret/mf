#ifndef PAUSE_SCREEN_DATA_H
#define PAUSE_SCREEN_DATA_H

#include "types.h"
#include "gba/memory.h"
#include "oam.h"

extern const u8 sMinimapTilesGfx[32 * 14 * TILE_SIZE];
extern const u16 sMinimapTilesPal[3 * PAL_ROW];

extern const u16 sPauseScreenBgPal_565808[13 * PAL_ROW];
extern const u16 sPauseScreenBgPal_5659a8[13 * PAL_ROW];
extern const u16 sPauseScreenObjPal_565b48[16 * PAL_ROW];
extern const u16 sNavConversationSamusPal[3 * PAL_ROW];

extern const struct FrameData sPauseScreenOam_BlinkingSquare[3];
extern const struct FrameData sPauseScreenOam_YesNoCursor[5];
extern const struct FrameData sPauseScreenOam_NavTextArrow[5];
extern const struct FrameData sPauseScreenOam_MapPreviewPoint[7];
extern const struct FrameData sPauseScreenOam_MapUpArrow[5];
extern const struct FrameData sPauseScreenOam_MapDownArrow[5];
extern const struct FrameData sPauseScreenOam_MapLeftArrow[5];
extern const struct FrameData sPauseScreenOam_MapRightArrow[5];
extern const struct FrameData sPauseScreenOam_PauseDebugCursorArrows[5];
extern const struct FrameData sPauseScreenOam_PauseDebugCursorDownArrow[5];
extern const struct FrameData sPauseScreenOam_NavTextCursor[2];
extern const struct FrameData sPauseScreenOam_NavTextCursorBlinking[3];
extern const struct FrameData sPauseScreenOam_Unk13[2];
extern const struct FrameData sPauseScreenOam_MapElevatorUpArrows[8];
extern const struct FrameData sPauseScreenOam_MapElevatorDownArrows[8];
extern const struct FrameData sPauseScreenOam_DownloadScanLineTrailing[5];
extern const struct FrameData sPauseScreenOam_DownloadScanLineLeading[2];
extern const struct FrameData sPauseScreenOam_MapTargetAbove[33];
extern const struct FrameData sPauseScreenOam_MapTargetBelow[33];
extern const struct FrameData sPauseScreenOam_MapTargetLeft[33];
extern const struct FrameData sPauseScreenOam_MapTargetRight[33];
extern const struct FrameData sPauseScreenOam_BslDiagramTargetAbove[5];
extern const struct FrameData sPauseScreenOam_BslDiagramTargetBelow[5];
extern const struct FrameData sPauseScreenOam_BslDiagramStartAbove[5];
extern const struct FrameData sPauseScreenOam_BslDiagramStartBelow[5];
extern const struct FrameData sPauseScreenOam_MainDeckText[2];
extern const struct FrameData sPauseScreenOam_Sector1Text[2];
extern const struct FrameData sPauseScreenOam_Sector2Text[2];
extern const struct FrameData sPauseScreenOam_Sector3Text[2];
extern const struct FrameData sPauseScreenOam_Sector4Text[2];
extern const struct FrameData sPauseScreenOam_Sector5Text[2];
extern const struct FrameData sPauseScreenOam_Sector6Text[2];
extern const struct FrameData sPauseScreenOam_AreaTextAppearing[10];
extern const struct FrameData sPauseScreenOam_SleepButton[7];
extern const struct FrameData sPauseScreenOam_StatusButton[7];
extern const struct FrameData sPauseScreenOam_SleepButtonSelected[5];
extern const struct FrameData sPauseScreenOam_StatusButtonSelected[5];
extern const struct FrameData sPauseScreenOam_L1Lock[2];
extern const struct FrameData sPauseScreenOam_L2Lock[2];
extern const struct FrameData sPauseScreenOam_L3Lock[2];
extern const struct FrameData sPauseScreenOam_L4Lock[2];
extern const struct FrameData sPauseScreenOam_L1Open[2];
extern const struct FrameData sPauseScreenOam_L2Open[2];
extern const struct FrameData sPauseScreenOam_L3Open[2];
extern const struct FrameData sPauseScreenOam_L4Open[2];
extern const struct FrameData sPauseScreenOam_ObjectiveButton[2];
extern const struct FrameData sPauseScreenOam_CollectedEnergyTanks[2];
extern const struct FrameData sPauseScreenOam_CollectedMissileTanks[2];
extern const struct FrameData sPauseScreenOam_CollectedPowerBombTanks[2];
extern const struct FrameData sPauseScreenOam_InGameTimer[2];
extern const struct FrameData sPauseScreenOam_EnergyTankCheckMark[2];
extern const struct FrameData sPauseScreenOam_MissileTankCheckMark[2];
extern const struct FrameData sPauseScreenOam_PowerBombTankCheckMark[2];
extern const struct FrameData sPauseScreenOam_NavigationPad[5];
extern const struct FrameData sPauseScreenOam_NavigationPadWithSamus[5];
extern const struct FrameData sPauseScreenOam_LockedHatchLeft[2];
extern const struct FrameData sPauseScreenOam_LockedHatchRight[2];

extern const struct FrameData sPauseScreenOam_PopUpWindow[10];
extern const struct FrameData sPauseScreenOam_PopUpWindowClosing[10];
extern const struct FrameData sPauseScreenOam_AdamTextBoxOutline[13];
extern const struct FrameData sPauseScreenOam_AdamTextBoxOutlineClosing[13];
extern const struct FrameData sPauseScreenOam_AdamTextBoxBackground[13];
extern const struct FrameData sPauseScreenOam_AdamTextBoxBackgroundClosing[13];
extern const struct FrameData sPauseScreenOam_AdamTextBoxLightOpening[5];
extern const struct FrameData sPauseScreenOam_AdamTextBoxLightClosing[5];
extern const struct FrameData sPauseScreenOam_AdamTextBoxLightOff[2];
extern const struct FrameData sPauseScreenOam_SamusTextBox[11];
extern const struct FrameData sPauseScreenOam_SamusTextBoxClosing[11];
extern const struct FrameData sPauseScreenOam_SamusTextBoxBackground[11];
extern const struct FrameData sPauseScreenOam_SamusTextBoxBackgroundClosing[11];
extern const struct FrameData sPauseScreenOam_FedTextBoxBackground[11];
extern const struct FrameData sPauseScreenOam_FedTextBoxBackgroundClosing[11];
extern const struct FrameData sPauseScreenOam_FedTextBoxOutline[11];
extern const struct FrameData sPauseScreenOam_FedTextBoxClosing[11];
extern const struct FrameData sPauseScreenOam_SamusPortraitStill[2];
extern const struct FrameData sPauseScreenOam_SamusPortraitAnimated[3];
extern const struct FrameData sPauseScreenOam_FederationPortraitStill[2];
extern const struct FrameData sPauseScreenOam_FederationPortraitAnimating[3];
extern const struct FrameData sPauseScreenOam_SamusPortraitOpening[8];
extern const struct FrameData sPauseScreenOam_SamusPortraitClosing[8];
extern const struct FrameData sPauseScreenOam_FederationPortraitOpening[8];
extern const struct FrameData sPauseScreenOam_FederationPortraitClosing[8];
extern const struct FrameData sPauseScreenOam_AdamTextBoxLightFlashing[6];
extern const struct FrameData sPauseScreenOam_FederationPortraitFlickering[3];

extern const struct FrameData sPauseScreenOam_BslDiagram0Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram10Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram20Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram30Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram40Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram50Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram60Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram70Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram80Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram90Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram100Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram110Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram120Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram130Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram140Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram150Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram160Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram170Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram180Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram190Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram200Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram210Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram220Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram230Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram240Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram250Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram260Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram270Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram280Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram290Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram300Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram310Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram320Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram330Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram340Degrees[2];
extern const struct FrameData sPauseScreenOam_BslDiagram350Degrees[2];

extern const u32 sPauseScreenBgGfx[2437];
extern const u32 sNavConversationRoomGfx[1414];
extern const u32 sNavConversationShipGfx[1575];
extern const u32 sPauseScreenObjGfx[3404];

extern const u32 sBlankMinimap[63];
extern const u32 sMainDeckMinimap[149];
extern const u32 sSector1Minimap[120];
extern const u32 sSector3Minimap[122];
extern const u32 sSector6Minimap[117];
extern const u32 sSector4Minimap[132];
extern const u32 sSector2Minimap[133];
extern const u32 sSector5Minimap[126];
extern const u32 sMainDeckNoLabMinimap[148];

extern const u32 sUnk_573da4[63];
extern const u32 sPauseDebugTilemap[151];
extern const u32 sMapScreenOutlineTilemap[123];
extern const u32 sNavConversationTextBoxesTilemap[176];
extern const u32 sPauseScreenSleepTilemap[193];
extern const u32 sStatusScreenTilemap[295];
extern const u32 sNavConversationRoomTilemap[359];
extern const u32 sPauseScreen_5752e4[65];
extern const u32 sNavConversationShipTilemap[414];

#endif /* PAUSE_SCREEN_DATA_H */
