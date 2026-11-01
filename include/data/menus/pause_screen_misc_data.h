#ifndef PAUSE_SCREEN_MISC_DATA_H
#define PAUSE_SCREEN_MISC_DATA_H

#include "types.h"
#include "gba/memory.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/menus/pause_debug.h"
#include "constants/minimap.h"
#include "constants/navigation.h"
#include "constants/samus.h"

#define PAUSE_DEBUG_SECTION_INFO_TOP(section) (sDebugSectionInfo[(section)][0])
#define PAUSE_DEBUG_SECTION_INFO_BOTTOM(section) (sDebugSectionInfo[(section)][1])
#define PAUSE_DEBUG_SECTION_INFO_LEFT(section) (sDebugSectionInfo[(section)][2])
#define PAUSE_DEBUG_SECTION_INFO_RIGHT(section) (sDebugSectionInfo[(section)][3])
#define PAUSE_DEBUG_SECTION_INFO_SECTION(section) (sDebugSectionInfo[(section)][4])
#define PAUSE_DEBUG_SECTION_INFO_HSIZE(section) (PAUSE_DEBUG_SECTION_INFO_RIGHT((section)) - PAUSE_DEBUG_SECTION_INFO_LEFT((section)))

extern const u8 sPauseScreenAreaNameOamIds[AREA_NORMAL_COUNT][2];
extern const u8 sPauseScreenSecurityLevelOamInfo[SECURITY_LEVEL_COUNT - 1][2];

enum PauseOamInfo {
    PAUSE_OAM_INDEX,
    PAUSE_OAM_ID,
    PAUSE_OAM_X_POSITION,
    PAUSE_OAM_Y_POSITION,

    PAUSE_OAM_INFO_COUNT
};

extern const u8 sPauseScreenMapArrowOamInfo[4][PAUSE_OAM_INFO_COUNT];

extern const u8 sPauseDebugBeamFlags[5];
extern const u8 sPauseDebugMissileFlags[4];
extern const u8 sPauseDebugBombFlags[2];
extern const u8 sPauseDebugSuitFlags[2];
extern const u8 sPauseDebugMiscFlags[5];

extern const u8 sStatusScreenSectionSizes[5];

extern const u16 sPauseDebugNumbersIncrementValues[5];
extern const u16 sPauseDebugNumbersMaxValues[3];

extern const u8 sMinimapHudColorMapping_Low[MINIMAP_TILE_TYPE_COUNT][PAL_ROW];
extern const u8 sMinimapHudColorMapping_High[MINIMAP_TILE_TYPE_COUNT][PAL_ROW];

extern const void* const sMapScreenTimeTankVramAddresses[MAP_SCREEN_TANK_TIME_COUNT];

extern const u8 sMaintainedInputDelays[7];

extern const u8 sMainDeckElevatorMapPositions[AREA_NORMAL_COUNT][2];
extern const u8 sSectorElevatorMapPositions[AREA_NORMAL_COUNT][2];

// ...

extern const u8 sCharacterWidths[1184];

// ...

extern const u8 sNavConversationTextBoxCursorYPositions[NAV_TEXT_BOX_COUNT][2];

struct NavConversationTarget {
    s8 conversation;
    u8 location;
    u8 x;
    u8 y;
    u8 textDirection;
    u8 pad_5[3];
};

extern const struct NavConversationTarget sNavConversationTargets[33];
extern const u8 sNavConversationTargetTextOamIds[4];

extern const u8 sNavConversationMosaicTarget;

struct NavConversationPopUp {
    const u8* pAnimation; // Pairs of (frame, duration)
    u8 animationLength;
    const u16* pPalette;
    const u16* pFlashingPalette;
    u8 flashingPaletteDelay;
    u8 rows:4;
    u8 vramRow:4;
    u8 size:4;
    u8 unk_12_4:4;
    const u32* pGraphics;
};

extern const u8 sNavConversationPopUpAnim_57bbc4[6 * 2];
extern const u8 sNavConversationPopUpAnim_57bbd0[16 * 2];
extern const u8 sNavConversationPopUpAnim_57bbf0[48 * 2];
extern const struct NavConversationPopUp sNavConversationPopUps[5];
struct NavConversationPopUpSet {
    s8 conversation;
    u8 popUps[3];
};

extern const struct NavConversationPopUpSet sNavConversationPopUpSets[3];
extern const u16 sNavConversationPal_57bcd4[16];
extern const u16 sNavConversationPal_57bcf4[2][16];
extern const u16 sNavConversationPal_57bd34[4][16];
extern const u16 sNavConversationPal_57bdb4[8][16];
extern const u8 sNavConversationPalTimers_57beb4[4];
extern const u8 sNavConversationPalTimers_57beb8[4];
extern const u8 sNavConversationPalTimers_57bebc[8];

extern const u16 sNavConversationFlashingPal_581300[16][16];

#include "structs/menus/pause_screen.h"

extern const struct BslDiagramData sBslDiagramDataInit;

// ...

extern const u8 sNavConversationPortraitOamIds[6][3];

// ...

#define EVENT_NAME_SIZE 28
extern const u8 sPauseDebugEventNames[EVENT_END][EVENT_NAME_SIZE];

extern const u8 sDebugLocationSectionInfo[2][2];
extern const u8 sDebugSectionInfo[PAUSE_DEBUG_SECTION_END][5];

#endif /* PAUSE_SCREEN_MISC_DATA_H */
