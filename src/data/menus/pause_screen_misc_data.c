#include "data/menus/pause_screen_misc_data.h"

#include "macros.h"
#include "constants/menus/pause_screen.h"

// TODO: The start of this file needs to be 4-byte aligned, but sPauseScreenAreaNameOamIds is not.
// When this blob is removed, sPauseScreenAreaNameOamIds cannot be the first item
static const u8 sBlob_5760e8_576142[] = INCBIN_U8("data/Blob_5760e8_576142.bin");

const u8 sPauseScreenAreaNameOamIds[AREA_NORMAL_COUNT][2] = {
    [AREA_MAIN_DECK] = { PAUSE_OAM_ID_MAIN_DECK_TEXT, PAUSE_OAM_ID_MAIN_DECK_TEXT_APPEARING },
    [AREA_SECTOR_1] = { PAUSE_OAM_ID_SECTOR_1_TEXT, PAUSE_OAM_ID_SECTOR_1_TEXT_APPEARING },
    [AREA_SECTOR_2] = { PAUSE_OAM_ID_SECTOR_2_TEXT, PAUSE_OAM_ID_SECTOR_2_TEXT_APPEARING },
    [AREA_SECTOR_3] = { PAUSE_OAM_ID_SECTOR_3_TEXT, PAUSE_OAM_ID_SECTOR_3_TEXT_APPEARING },
    [AREA_SECTOR_4] = { PAUSE_OAM_ID_SECTOR_4_TEXT, PAUSE_OAM_ID_SECTOR_4_TEXT_APPEARING },
    [AREA_SECTOR_5] = { PAUSE_OAM_ID_SECTOR_5_TEXT, PAUSE_OAM_ID_SECTOR_5_TEXT_APPEARING },
    [AREA_SECTOR_6] = { PAUSE_OAM_ID_SECTOR_6_TEXT, PAUSE_OAM_ID_SECTOR_6_TEXT_APPEARING }
};

const u8 sPauseScreenSecurityLevelOamInfo[SECURITY_LEVEL_COUNT - 1][2] = {
    [SECURITY_LEVEL_1 - 1] = { PAUSE_OAM_IDX_L1_STATUS, PAUSE_OAM_ID_L1_LOCK },
    [SECURITY_LEVEL_2 - 1] = { PAUSE_OAM_IDX_L2_STATUS, PAUSE_OAM_ID_L2_LOCK },
    [SECURITY_LEVEL_3 - 1] = { PAUSE_OAM_IDX_L3_STATUS, PAUSE_OAM_ID_L3_LOCK },
    [SECURITY_LEVEL_4 - 1] = { PAUSE_OAM_IDX_L4_STATUS, PAUSE_OAM_ID_L4_LOCK }
};

const u8 sPauseScreenMapArrowOamInfo[4][PAUSE_OAM_INFO_COUNT] = {
    [0] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_MAP_RIGHT_ARROW,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_MAP_RIGHT_ARROW,
        [PAUSE_OAM_X_POSITION] = 222,
        [PAUSE_OAM_Y_POSITION] = 76
    },
    [1] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_MAP_LEFT_ARROW,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_MAP_LEFT_ARROW,
        [PAUSE_OAM_X_POSITION] = 10,
        [PAUSE_OAM_Y_POSITION] = 76
    },
    [2] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_MAP_UP_ARROW,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_MAP_UP_ARROW,
        [PAUSE_OAM_X_POSITION] = 116,
        [PAUSE_OAM_Y_POSITION] = 14
    },
    [3] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_MAP_DOWN_ARROW,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_MAP_DOWN_ARROW,
        [PAUSE_OAM_X_POSITION] = 116,
        [PAUSE_OAM_Y_POSITION] = 142
    }
};

const u8 sPauseDebugBeamFlags[5] = {
    [0] = BF_CHARGE_BEAM,
    [1] = BF_WIDE_BEAM,
    [2] = BF_PLASMA_BEAM,
    [3] = BF_WAVE_BEAM,
    [4] = BF_ICE_BEAM,
};

const u8 sPauseDebugMissileFlags[4] = {
    [0] = MBF_MISSILES,
    [1] = MBF_SUPER_MISSILES,
    [2] = MBF_ICE_MISSILES,
    [3] = MBF_DIFFUSION_MISSILES,
};

const u8 sPauseDebugBombFlags[2] = {
    [0] = MBF_BOMBS,
    [1] = MBF_POWER_BOMBS,
};

const u8 sPauseDebugSuitFlags[2] = {
    [0] = SMF_VARIA_SUIT,
    [1] = SMF_GRAVITY_SUIT,
};

const u8 sPauseDebugMiscFlags[5] = {
    [0] = SMF_MORPH_BALL,
    [1] = SMF_HIGH_JUMP,
    [2] = SMF_SPEED_BOOSTER,
    [3] = SMF_SPACE_JUMP,
    [4] = SMF_SCREW_ATTACK,
};

const u8 sStatusScreenSectionSizes[5] = {
    [0] = ARRAY_SIZE(sPauseDebugBeamFlags),
    [1] = ARRAY_SIZE(sPauseDebugMissileFlags),
    [2] = ARRAY_SIZE(sPauseDebugBombFlags),
    [3] = ARRAY_SIZE(sPauseDebugSuitFlags),
    [4] = ARRAY_SIZE(sPauseDebugMiscFlags),
};

const u16 sPauseDebugNumbersIncrementValues[5] = {
    1, 10, 100, 1000, 10000,
};

const u16 sPauseDebugNumbersMaxValues[3] = {
    [PAUSE_DEBUG_AMMO_TYPE_HEALTH] = MAX_ENERGY_AMOUNT,
    [PAUSE_DEBUG_AMMO_TYPE_MISSILES] = MAX_MISSILE_AMOUNT,
    [PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS] = MAX_POWER_BOMB_AMOUNT,
};

const u8 sMinimapHudColorMapping_Low[MINIMAP_TILE_TYPE_COUNT][PAL_ROW] = {
    [MINIMAP_TILE_TYPE_UNEXPLORED] = {
        0x00, 0x01, 0x01, 0x0C, 0x0E, 0x05, 0x0C, 0x07,
        0x01, 0x01, 0x01, 0x01, 0x0C, 0x0C, 0x0C, 0x0C,
    },
    [MINIMAP_TILE_TYPE_NORMAL] = {
        0x00, 0x01, 0x0D, 0x0D, 0x0E, 0x05, 0x01, 0x07,
        0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
    },
    [MINIMAP_TILE_TYPE_HIDDEN] = {
        0x00, 0x01, 0x03, 0x03, 0x0E, 0x05, 0x01, 0x07,
        0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
    }
};

const u8 sMinimapHudColorMapping_High[MINIMAP_TILE_TYPE_COUNT][PAL_ROW] = {
    [MINIMAP_TILE_TYPE_UNEXPLORED] = {
        0x00, 0x10, 0x10, 0xC0, 0xE0, 0x50, 0xC0, 0x70,
        0x10, 0x10, 0x10, 0x10, 0xC0, 0xC0, 0xC0, 0xC0,
    },
    [MINIMAP_TILE_TYPE_NORMAL] = {
        0x00, 0x10, 0xD0, 0xD0, 0xE0, 0x50, 0x10, 0x70,
        0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
    },
    [MINIMAP_TILE_TYPE_HIDDEN] = {
        0x00, 0x10, 0x30, 0x30, 0xE0, 0x50, 0x10, 0x70,
        0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
    }
};

const void* const sMapScreenTimeTankVramAddresses[MAP_SCREEN_TANK_TIME_COUNT] = {
    [MAP_SCREEN_CURR_ENERGY_IDX] = VRAM_OBJ + 0x3700 + 0x60 * 1,
    [MAP_SCREEN_TOTAL_ENERGY_IDX] = VRAM_OBJ + 0x3700 + 0x60 * 2,
    [MAP_SCREEN_CURR_MISSILE_IDX] = VRAM_OBJ + 0x3B00 + 0x60 * 1,
    [MAP_SCREEN_TOTAL_MISSILE_IDX] = VRAM_OBJ + 0x3B00 + 0x60 * 2,
    [MAP_SCREEN_CURR_POWER_BOMB_IDX] = VRAM_OBJ + 0x3F00 + 0x60 * 1,
    [MAP_SCREEN_TOTAL_POWER_BOMB_IDX] = VRAM_OBJ + 0x3F00 + 0x60 * 2,
    [MAP_SCREEN_IGT_HOURS_IDX] = VRAM_OBJ + 0x3300 + 0x60 * 1,
    [MAP_SCREEN_IGT_MINUTES_IDX] = VRAM_OBJ + 0x3300 + 0x60 * 2,
};

const u8 sMaintainedInputDelays[7] = {
    15, 10, 6, 4, 4, 4, 2,
};

static const u8 sPadding_576217[1] = { 0 };

const u8 sMainDeckElevatorMapPositions[AREA_NORMAL_COUNT][2] = {
    [AREA_MAIN_DECK] = { 0, 0 },
    [AREA_SECTOR_1] = { 5, 16 },
    [AREA_SECTOR_2] = { 9, 16 },
    [AREA_SECTOR_3] = { 4, 16 },
    [AREA_SECTOR_4] = { 10, 16 },
    [AREA_SECTOR_5] = { 3, 16 },
    [AREA_SECTOR_6] = { 11, 16 }
};

const u8 sSectorElevatorMapPositions[AREA_NORMAL_COUNT][2] = {
    [AREA_MAIN_DECK] = { 0, 0 },
    [AREA_SECTOR_1] = { 2, 1 },
    [AREA_SECTOR_2] = { 3, 2 },
    [AREA_SECTOR_3] = { 5, 2 },
    [AREA_SECTOR_4] = { 21, 4 },
    [AREA_SECTOR_5] = { 1, 2 },
    [AREA_SECTOR_6] = { 1, 2 }
};

const u8 sCharacterWidths[1184] = {
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 6, 7, 7, 7, 8, 8, 4, 5, 5, 7, 7, 4, 8, 4, 7,
    7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 4, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 7, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 6, 8, 4, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 3, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 6, 8, 4, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};

static const u8 sBlob_5766D4_5766e0[] = INCBIN_U8("data/Blob_5766D4_5766e0.bin");

const u8 sNavConversationTextBoxCursorYPositions[NAV_TEXT_BOX_COUNT][2] = {
    [NAV_TEXT_BOX_BOTTOM] = { 128, 150 },
    [NAV_TEXT_BOX_TOP] = { 25, 47 }
};

const struct NavConversationTarget sNavConversationTargets[33] = {
    [0] = { NAV_CONVO_GO_TO_QUARANTINE_BAY, NAV_TARGET_LOC_MAIN_DECK, 9, 10, NAV_TARGET_TEXT_LEFT },
    [1] = { NAV_CONVO_QUARANTINE_BAY_IS_AHEAD, NAV_TARGET_LOC_MAIN_DECK, 9, 10, NAV_TARGET_TEXT_LEFT },
    [2] = { NAV_CONVO_3, NAV_TARGET_LOC_NONE, 9, 10, NAV_TARGET_TEXT_ABOVE },
    [3] = { NAV_CONVO_UNLOCKED_LEVEL_0_HATCHES, NAV_TARGET_LOC_MAIN_DECK, 25, 9, NAV_TARGET_TEXT_BELOW },
    [4] = { NAV_CONVO_GO_TO_MISSILES_DATA_ROOM, NAV_TARGET_LOC_OPERATIONS_DECK, 16, 2, NAV_TARGET_TEXT_LEFT },
    [5] = { NAV_CONVO_MISSILES_DATA_ROOM_JUST_AHEAD, NAV_TARGET_LOC_OPERATIONS_DECK, 16, 2, NAV_TARGET_TEXT_LEFT },
    [6] = { NAV_CONVO_FIND_WAY_TO_ARACHNUS, NAV_TARGET_LOC_MAIN_DECK, 25, 9, NAV_TARGET_TEXT_BELOW },
    [7] = { NAV_CONVO_GO_TO_SRX1, NAV_TARGET_LOC_SECTOR_1, 3, 2, NAV_TARGET_TEXT_RIGHT },
    [8] = { NAV_CONVO_GO_TO_TRO1, NAV_TARGET_LOC_SECTOR_2, 4, 3, NAV_TARGET_TEXT_BELOW },
    [9] = { NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_BOMBS, NAV_TARGET_LOC_SECTOR_2, 2, 5, NAV_TARGET_TEXT_LEFT },
    [10] = { NAV_CONVO_LEVEL_1_UNLOCKED_GO_DOWNLOAD_BOMBS, NAV_TARGET_LOC_SECTOR_2, 2, 5, NAV_TARGET_TEXT_LEFT },
    [11] = { NAV_CONVO_GO_TO_AQA1, NAV_TARGET_LOC_SECTOR_4, 20, 5, NAV_TARGET_TEXT_LEFT },
    [12] = { NAV_CONVO_GO_DEFEAT_SERRIS, NAV_TARGET_LOC_SECTOR_4, 8, 3, NAV_TARGET_TEXT_ABOVE },
    [13] = { NAV_CONVO_GO_TO_PYR1, NAV_TARGET_LOC_SECTOR_3, 6, 3, NAV_TARGET_TEXT_BELOW },
    [14] = { NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_SUPER_MISSILES, NAV_TARGET_LOC_SECTOR_3, 19, 4, NAV_TARGET_TEXT_BELOW },
    [15] = { NAV_CONVO_LEVEL_2_UNLOCKED_GO_DOWNLOAD_SUPER_MISSILES, NAV_TARGET_LOC_SECTOR_3, 19, 4, NAV_TARGET_TEXT_BELOW },
    [16] = { NAV_CONVO_GO_TO_NOC1, NAV_TARGET_LOC_SECTOR_6, 2, 3, NAV_TARGET_TEXT_BELOW },
    [17] = { NAV_CONVO_FEDERATION_MONITOR_SAMUS, NAV_TARGET_LOC_SECTOR_6, 2, 3, NAV_TARGET_TEXT_BELOW },
    [18] = { NAV_CONVO_GO_TO_NOC1_AFTER_FEDERATION, NAV_TARGET_LOC_SECTOR_6, 2, 3, NAV_TARGET_TEXT_BELOW },
    [19] = { NAV_CONVO_GO_DOWNLOAD_VARIA_SUIT, NAV_TARGET_LOC_SECTOR_6, 10, 12, NAV_TARGET_TEXT_BELOW },
    [20] = { NAV_CONVO_GO_TO_ARC1, NAV_TARGET_LOC_SECTOR_5, 2, 3, NAV_TARGET_TEXT_BELOW },
    [21] = { NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_ICE_MISSILES, NAV_TARGET_LOC_SECTOR_5, 13, 6, NAV_TARGET_TEXT_BELOW },
    [22] = { NAV_CONVO_LEVEL_3_UNLOCKED_GO_DOWNLOAD_ICE_MISSILES, NAV_TARGET_LOC_SECTOR_5, 13, 6, NAV_TARGET_TEXT_RIGHT },
    [23] = { NAV_CONVO_GO_TO_THE_MAIN_BOILER, NAV_TARGET_LOC_SECTOR_3, 4, 9, NAV_TARGET_TEXT_BELOW },
    [24] = { NAV_CONVO_GO_TO_THE_HABITATION_DECK, NAV_TARGET_LOC_HABITATION_DECK, 10, 3, NAV_TARGET_TEXT_ABOVE },
    [25] = { NAV_CONVO_GO_TO_ARC2, NAV_TARGET_LOC_SECTOR_5, 13, 6, NAV_TARGET_TEXT_RIGHT },
    [26] = { NAV_CONVO_GO_DOWNLOAD_POWER_BOMBS, NAV_TARGET_LOC_SECTOR_5, 13, 6, NAV_TARGET_TEXT_RIGHT },
    [27] = { NAV_CONVO_RETURN_TO_YOUR_SHIP, NAV_TARGET_LOC_DOCKING_BAYS, 21, 14, NAV_TARGET_TEXT_BELOW },
    [28] = { NAV_CONVO_REACTIVATE_THE_AUXILIARY_POWER_SYSTEM, NAV_TARGET_LOC_REACTOR_SILO, 21, 20, NAV_TARGET_TEXT_ABOVE },
    [29] = { NAV_CONVO_GO_TO_ARC3, NAV_TARGET_LOC_SECTOR_5, 2, 3, NAV_TARGET_TEXT_BELOW },
    [30] = { NAV_CONVO_GO_TO_NOC2, NAV_TARGET_LOC_SECTOR_6, 2, 3, NAV_TARGET_TEXT_BELOW },
    [31] = { NAV_CONVO_GO_TO_OPERATIONS_ROOM, NAV_TARGET_LOC_OPERATIONS_DECK, 16, 1, NAV_TARGET_TEXT_LEFT },
    [32] = { NAV_CONVO_GO_TO_OPERATIONS_ROOM_2, NAV_TARGET_LOC_OPERATIONS_DECK, 16, 1, NAV_TARGET_TEXT_LEFT }
};

const u8 sNavConversationTargetTextOamIds[4] = {
    [NAV_TARGET_TEXT_ABOVE] = PAUSE_OAM_ID_MAP_TARGET_ABOVE,
    [NAV_TARGET_TEXT_BELOW] = PAUSE_OAM_ID_MAP_TARGET_BELOW,
    [NAV_TARGET_TEXT_LEFT] = PAUSE_OAM_ID_MAP_TARGET_LEFT,
    [NAV_TARGET_TEXT_RIGHT] = PAUSE_OAM_ID_MAP_TARGET_RIGHT
};

const u8 sNavConversationPortraitOamIds[6][3] = {
    [0] = {
        PAUSE_OAM_ID_SAMUS_TEXT_BOX_EDGE,
        PAUSE_OAM_ID_UNK_81,
        PAUSE_OAM_ID_SAMUS_PORTRAIT_STILL
    },
    [1] = {
        PAUSE_OAM_ID_SAMUS_TEXT_BOX,
        PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND,
        PAUSE_OAM_ID_SAMUS_PORTRAIT_OPENING
    },
    [2] = {
        PAUSE_OAM_ID_SAMUS_TEXT_BOX_CLOSING,
        PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND_CLOSING,
        PAUSE_OAM_ID_SAMUS_PORTRAIT_CLOSING
    },
    [3] = {
        PAUSE_OAM_ID_FED_TEXT_BOX_EDGE,
        PAUSE_OAM_ID_UNK_87,
        PAUSE_OAM_ID_FEDERATION_PORTRAIT_STILL
    },
    [4] = {
        PAUSE_OAM_ID_FED_TEXT_BOX_OUTLINE,
        PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND,
        PAUSE_OAM_ID_FEDERATION_PORTRAIT_OPENING
    },
    [5] = {
        PAUSE_OAM_ID_FED_TEXT_BOX_CLOSING,
        PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND_CLOSING,
        PAUSE_OAM_ID_FEDERATION_PORTRAIT_CLOSING
    }
};

static const u8 sBlob_576802_57bbc4[] = INCBIN_U8("data/Blob_576802_57bbc4.bin");

const u8 sNavConversationPopUpAnim_57bbc4[6 * 2] = {
    0, 20,
    1, 10,
    2, 10,
    3, 13,
    2, 13,
    1, 13
};

const u8 sNavConversationPopUpAnim_57bbd0[16 * 2] = {
    0, 3,
    1, 3,
    2, 3,
    3, 3,
    4, 3,
    5, 3,
    6, 3,
    7, 3,
    8, 3,
    9, 3,
    10, 3,
    11, 3,
    12, 3,
    13, 3,
    14, 3,
    15, 3
};

const u8 sNavConversationPopUpAnim_57bbf0[48 * 2] = {
    0, 8,
    1, 8,
    2, 8,
    1, 8,
    0, 8,
    1, 8,
    2, 8,
    1, 8,
    0, 8,
    3, 8,
    4, 8,
    3, 8,
    0, 8,
    3, 8,
    4, 8,
    5, 8,
    6, 8,
    9, 8,
    10, 8,
    9, 8,
    6, 8,
    7, 8,
    8, 8,
    7, 8,
    6, 8,
    11, 8,
    12, 8,
    11, 8,
    6, 8,
    7, 8,
    8, 8,
    7, 8,
    6, 8,
    5, 8,
    4, 8,
    3, 8,
    0, 8,
    13, 8,
    14, 8,
    15, 8,
    16, 8,
    17, 8,
    18, 8,
    17, 8,
    16, 8,
    15, 8,
    14, 8,
    13, 8
};

const struct NavConversationPopUp sNavConversationPopUps[5] = {
    [0] = {
        .pAnimation = sNavConversationPopUpAnim_57bbc4,
        .animationLength = 6,
        .pPalette = (const u16*)0x8576804,
        .pFlashingPalette = (const u16*)0x8576824,
        .flashingPaletteDelay = 0,
        .rows = 6,
        .vramRow = 0,
        .size = 8,
        .unk_12_4 = 0,
        .pGraphics = (const u32*)0x8576904
    },
    [1] = {
        .pAnimation = sNavConversationPopUpAnim_57bbc4,
        .animationLength = 6,
        .pPalette = (const u16*)0x8576804,
        .pFlashingPalette = (const u16*)0x8576824,
        .flashingPaletteDelay = 0,
        .rows = 6,
        .vramRow = 0,
        .size = 8,
        .unk_12_4 = 0,
        .pGraphics = (const u32*)0x8576904
    },
    [2] = {
        .pAnimation = sNavConversationPopUpAnim_57bbd0,
        .animationLength = 16,
        .pPalette = (const u16*)0x8576844,
        .pFlashingPalette = (const u16*)0x8576864,
        .flashingPaletteDelay = 0,
        .rows = 4,
        .vramRow = 1,
        .size = 4,
        .unk_12_4 = 2,
        .pGraphics = (const u32*)0x8577024
    },
    [3] = {
        .pAnimation = sNavConversationPopUpAnim_57bbf0,
        .animationLength = 48,
        .pPalette = (const u16*)0x8576884,
        .pFlashingPalette = (const u16*)0x85768A4,
        .flashingPaletteDelay = 0,
        .rows = 6,
        .vramRow = 0,
        .size = 8,
        .unk_12_4 = 0,
        .pGraphics = (const u32*)0x8578750
    },
    [4] = {
        .pAnimation = sNavConversationPopUpAnim_57bbd0,
        .animationLength = 16,
        .pPalette = (const u16*)0x85768C4,
        .pFlashingPalette = (const u16*)0x85768E4,
        .flashingPaletteDelay = 0,
        .rows = 4,
        .vramRow = 1,
        .size = 4,
        .unk_12_4 = 2,
        .pGraphics = (const u32*)0x8577024
    }
};

const struct NavConversationPopUpSet sNavConversationPopUpSets[3] = {
    [0] = { NAV_CONVO_UNLOCKED_LEVEL_0_HATCHES, { 2, 1, 0 } },
    [1] = { NAV_CONVO_GO_DOWNLOAD_VARIA_SUIT, { 4, 0, 0 } },
    [2] = { NAV_CONVO_REACTIVATE_THE_AUXILIARY_POWER_SYSTEM, { 3, 0, 0 } }
};

const u16 sNavConversationPal_57bcd4[16] = {
    0x7C1F, 0x701B, 0x6017, 0x701B, 0x7C1F, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

const u16 sNavConversationPal_57bcf4[2][16] = {
    [0] = {
        0x3704, 0x32A4, 0x2A25, 0x32A4, 0x3704, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    },
    [1] = {
        0x108F, 0x14B3, 0x18D7, 0x14B3, 0x108F, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    }
};

const u16 sNavConversationPal_57bd34[4][16] = {
    [0] = {
        0x0000, 0x0000, 0x0080, 0x04C0, 0x1545, 0x29CA, 0x362D, 0x46B1,
        0x1752, 0x5314, 0x0000, 0x0000, 0x6BFF, 0x47BD, 0x2BB7, 0x1B93
    },
    [1] = {
        0x0000, 0x0000, 0x0080, 0x04C0, 0x1545, 0x29CA, 0x362D, 0x46B1,
        0x1752, 0x5314, 0x0000, 0x0000, 0x47BD, 0x2BB7, 0x1B93, 0x6BFF
    },
    [2] = {
        0x0000, 0x0000, 0x0080, 0x04C0, 0x1545, 0x29CA, 0x362D, 0x46B1,
        0x1752, 0x5314, 0x0000, 0x0000, 0x2BB7, 0x1B93, 0x6BFF, 0x47BD
    },
    [3] = {
        0x0000, 0x0000, 0x0080, 0x04C0, 0x1545, 0x29CA, 0x362D, 0x46B1,
        0x1752, 0x5314, 0x0000, 0x0000, 0x1B93, 0x6BFF, 0x47BD, 0x2BB7
    }
};

const u16 sNavConversationPal_57bdb4[8][16] = {
    [0] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x0252, 0x0172, 0x0052, 0x43E2, 0x3704, 0x34C3
    },
    [1] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x06B5, 0x05D5, 0x04B5, 0x3BA1, 0x2AC3, 0x38E4
    },
    [2] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x0F39, 0x0E59, 0x0D19, 0x2F41, 0x2262, 0x3D05
    },
    [3] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x179C, 0x16BC, 0x159C, 0x2700, 0x1621, 0x4526
    },
    [4] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x1FFF, 0x1F3F, 0x1DFF, 0x1AA0, 0x0DC0, 0x4968
    },
    [5] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x179C, 0x16BC, 0x159C, 0x2700, 0x1621, 0x4526
    },
    [6] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x0F39, 0x0E59, 0x0D19, 0x2F41, 0x2262, 0x3D05
    },
    [7] = {
        0x0000, 0x7FFF, 0x66D5, 0x4DEE, 0x3969, 0x2CE6, 0x24A4, 0x1841,
        0x7FF6, 0x7FE0, 0x06B5, 0x05D5, 0x04B5, 0x3BA1, 0x2AC3, 0x38E4
    }
};

const u8 sNavConversationPalTimers_57beb4[4] = { 32, 16, 16, 16 };

const u8 sNavConversationPalTimers_57beb8[4] = { 7, 7, 7, 7 };

const u8 sNavConversationPalTimers_57bebc[8] = { 8, 8, 8, 8, 8, 8, 8, 8 };

static const u8 sBlob_57bec4_581510[] = INCBIN_U8("data/Blob_57bec4_581510.bin");

const u8 sPauseDebugEventNames[EVENT_END][EVENT_NAME_SIZE] = {
    [EVENT_NONE] = SHIFT_JIS("TOHOKANKO   トクベツホカンコヘ ムカエ  "),
    [EVENT_NAVIGATION_ROOM_BEFORE_QUARANTINE_BAY] = SHIFT_JIS("TOHOKANKO2  トクベツホカンコノ チョウサ "),
    [EVENT_QUARANTINE_BAY_HORNOAD_DEAD] = SHIFT_JIS("HOKANKO     ナビヘ モドレ       "),
    [EVENT_NAVIGATION_ROOM_AFTER_QUARANTINE_BAY] = SHIFT_JIS("TOMARUKARA  キョダイセイブツヲ タオセ "),
    [EVENT_NAVIGATION_ROOM_BEFORE_ELEVATOR] = SHIFT_JIS("TOMISSILE   ミサイルヲ ニュウシュセヨ   "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_1] = SHIFT_JIS("DATA3       トナリノ ヘヤヘ        "),
    [EVENT_ENTERED_MISSILE_DATA_ROOM] = SHIFT_JIS("TODATA      データルームニ ハイル    "),
    [EVENT_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("MISSILE     データルームデ ミサイルヲ "),
    [EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE] = SHIFT_JIS("DOWNENE     デンゲンガ オチタ    "),
    [EVENT_NAVIGATION_ROOM_AFTER_MISSILES] = SHIFT_JIS("TOMARUKARA2 キョダイセイブツヲ タオセ2"),
    [EVENT_MORPH_BALL_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS1   ナビヘ ムカエ        "),
    [EVENT_NAVIGATION_ROOM_AFTER_MORPH_BALL] = SHIFT_JIS("TOKUTYOU    SR388ヘ ムカエ      "),
    [EVENT_ENTERED_ELEVATOR_ROOM] = SHIFT_JIS("ELESTART    エレデモ SR388ヘムカエ "),
    [EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS] = SHIFT_JIS("ELEEND      デモエンド SR388ヘ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_SRX] = SHIFT_JIS("TOKUTYOU2   クウチョウメロンヲ タオセ   "),
    [EVENT_CHARGE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("POWERB      コアXゴ ノコリハカイセヨ  "),
    [EVENT_ALL_STABILIZERS_ONLINE] = SHIFT_JIS("KUTYOU      ハカイゴ ナビヘ ムカエ  "),
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX] = SHIFT_JIS("TOBOM       ボムヲ ニュウシュセヨ    "),
    [EVENT_NAVIGATION_ROOM_ENTERING_TRO] = SHIFT_JIS("TOLV1KEY    レベル1ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_1_UNLOCKED] = SHIFT_JIS("LV1KEY      レベル1カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_2] = SHIFT_JIS("TOBOM2      カイジョゴ ボムデータヘ"),
    [EVENT_ENTERING_BOMB_DATA_ROOM] = SHIFT_JIS("DATATRO     データルームニ ハイル    "),
    [EVENT_BOMB_DATA_DOWNLOADED] = SHIFT_JIS("BOM         ネッタイカラ ダッシュツセヨ "),
    [EVENT_SA_X_QUAKE] = SHIFT_JIS("BOMQUAKE    ボムゴ ジシン      "),
    [EVENT_LEFT_SA_X_QUAKE_ROOM] = SHIFT_JIS("BOMQUAKE2   ジシン シュウリョウ     "),
    [EVENT_HIGH_JUMP_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS2   ボスノノチ ダッシュツ   "),
    [EVENT_ESCAPED_TRO_1_SA_X] = SHIFT_JIS("TROSAX      SAXカラ ニゲル      "),
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO] = SHIFT_JIS("TOWATER     スイチュウセクションヘ     "),
    [EVENT_NAVIGATION_ROOM_ENTERING_AQA] = SHIFT_JIS("WATER       スイイヲ サゲロ       "),
    [EVENT_SPEED_BOOSTER_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS3   ボスノノチ スイイヲサゲロ "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_3] = SHIFT_JIS("TOWATSWITCH ダッシュノ セツメイ     "),
    [EVENT_ENTERED_PUMP_CONTROL_UNIT] = SHIFT_JIS("WATSWTROOM  スイイヘンコウヘヤ       "),
    [EVENT_WATER_LEVEL_LOWERED] = SHIFT_JIS("WATSWITCH   スイイヘンコウ         "),
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA] = SHIFT_JIS("TOPWMISSILE パワーミサイルヲ テニイレロ "),
    [EVENT_NAVIGATION_ROOM_ENTERING_PYR] = SHIFT_JIS("TOLV2KEY    レベル2ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_2_UNLOCKED] = SHIFT_JIS("LV2KEY      レベル2カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_4] = SHIFT_JIS("TOPWMISSILE2Pミサイルヘ カイジョゴ  "),
    [EVENT_ENTERED_SUPER_MISSILE_DATA_ROOM] = SHIFT_JIS("DATABUR     データルームニ ハイル    "),
    [EVENT_SUPER_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("PWMISSILE   パワーミサイル カンリョウ  "),
    [EVENT_TRIGGERED_BOX_RUMBLE] = SHIFT_JIS("DOTADOTA    オートデモゴニ モドレ  "),
    [EVENT_BOX_DEFEATED] = SHIFT_JIS("DOWNBOSSA1  ボスA タオス        "),
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR] = SHIFT_JIS("TOENEGAS    アンコクセクションヘ ムカエ  "),
    [EVENT_LEFT_NAVIGATION_ROOM] = SHIFT_JIS("ADAMRENPO   アダム レンポウ      "),
    [EVENT_SECRET_CONVERSATION] = SHIFT_JIS("ADAMRENPODEMOアダムレンポウチュ    "),
    [EVENT_SECRET_CONVERSATION_OVER] = SHIFT_JIS("ADAMRENPOENDアダムレンポエンド    "),
    [EVENT_SKIPPED_BY_USING_NOC_NAVIGATION_ROOM] = SHIFT_JIS("TOANKOKU    アンコク イガイデ コウシン"),
    [EVENT_ENTERED_NOC_NAVIGATION_ROOM] = SHIFT_JIS("DARNAVI     アンコクナビニ ハイル    "),
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC] = SHIFT_JIS("TOENEGAS2   ボス4ヲ タオセ       "),
    [EVENT_NOC_SA_X_ENCOUNTER] = SHIFT_JIS("DARSAX      SAXニ アウ         "),
    [EVENT_ESCAPED_NOC_SA_X] = SHIFT_JIS("DARSAXESC   SAXカラ ニゲキル     "),
    [EVENT_NOC_DATA_ROOM_DESTROYED] = SHIFT_JIS("BARILOSS    バリア スワレル       "),
    [EVENT_VARIA_SUIT_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS4   ナビヘ モドレ       "),
    [EVENT_REACHED_TOP_OF_ROOM_AFTER_VARIA] = SHIFT_JIS("CXESCAPE    コールドX ニゲル     "),
    [EVENT_NAVIGATION_ROOM_LEAVING_NOC] = SHIFT_JIS("TOFREEZEM   ゴッカンセクションヘ ムカエ "),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC] = SHIFT_JIS("TOLV3KEY    レベル3ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_3_UNLOCKED] = SHIFT_JIS("LV3KEY      レベル3カイジョ      "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_5] = SHIFT_JIS("TOFREEZEM2  アイスミサイルヲ ニュウシュセヨ"),
    [EVENT_ENTERED_ICE_MISSILE_DATA_ROOM] = SHIFT_JIS("DATAFRI     データルームニ ハイル    "),
    [EVENT_ICE_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("FREEZEM     アイスミサイル カンリョウ   "),
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC] = SHIFT_JIS("TOENEBALL   ネツボウソウ カイシ     "),
    [EVENT_WIDE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("WIDEB       コンソールヲ オセ       "),
    [EVENT_COOLING_UNIT_OPERATIONAL] = SHIFT_JIS("ENEBALL     ナビヘ モドレ       "),
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR_2] = SHIFT_JIS("TOETEKON    キョジュウクヘ ムカエ    "),
    [EVENT_ANIMALS_RELEASED] = SHIFT_JIS("ETEKON      ナビヘ キュウシュツゴ   "),
    [EVENT_NAVIGATION_ROOM_AFTER_ANIMALS] = SHIFT_JIS("TOPBOM      パワーボムヲ ニュウシュセヨ"),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_2] = SHIFT_JIS("TOPBOM2     ゴッカン コウシン      "),
    [EVENT_POWER_BOMB_DATA_DOWNLOADED] = SHIFT_JIS("PBOM        パワーボム カンリョウ   "),
    [EVENT_ARC_SA_X_ENCOUNTER] = SHIFT_JIS("FRISAX      SAXニ デアウ       "),
    [EVENT_ESCAPED_ARC_SA_X] = SHIFT_JIS("FRISAXESC   SAXカラ ニゲキル     "),
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC_2] = SHIFT_JIS("TOSTARSHIP  スペースシップヘ ムカエ  "),
    [EVENT_POWER_OUTAGE] = SHIFT_JIS("ENGDOWN     スペースシップヘムカエ   "),
    [EVENT_ENTERED_SHIP] = SHIFT_JIS("TODOURYOKU  ホジョ デンゲンヲ イレロ"),
    [EVENT_ENTERED_YAKUZA_ROOM] = SHIFT_JIS("BOSS5ROOM   ボス ヘヤ          "),
    [EVENT_SPACE_JUMP_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS5   ホジョデンゲンヲイレロ  "),
    [EVENT_AUXILARY_POWER_ENGAGED] = SHIFT_JIS("SUBENG      ホジョデンゲン カンリョウ"),
    [EVENT_NAVIGATION_ROOM_AFTER_YAKUZA] = SHIFT_JIS("TOPLASMAB   ネッタイセクションヘ ムカエ  "),
    [EVENT_ENGAGED_TRO_2_SA_X] = SHIFT_JIS("TROSAX2     SAXニ デアウ       "),
    [EVENT_ESCAPED_TRO_2_SA_X] = SHIFT_JIS("TROSAX2ESC  SAXカラ ニゲキル     "),
    [EVENT_PLASMA_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("PLASMAB     ドウリョク カイフク ナビヘ"),
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO_2] = SHIFT_JIS("TOGOKAN     ゴッカン ボスヲ タオセ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_3] = SHIFT_JIS("TOGOKAN2    ゴッカンナビデ コウシン "),
    [EVENT_GRAVITY_SUIT_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS6   ボス タオス ナビヘ    "),
    [EVENT_ENTERED_LEVEL_4_SECURITY_ROOM] = SHIFT_JIS("TOLV4KEY    レベル4ヲ カイジョセヨ  "),
    [EVENT_SECURITY_LEVEL_4_UNLOCKED] = SHIFT_JIS("LV4KEY      レベル4カイジョ      "),
    [EVENT_SECRET_MESSAGE_2] = SHIFT_JIS("TOKAKUSAN2  カクサンヲ ニュウシュセヨ2  "),
    [EVENT_ENTERED_DIFFUSION_MISSILE_DATA_ROOM] = SHIFT_JIS("DATAWAT     データルームニ ハイル    "),
    [EVENT_DIFFUSION_MISSILE_DATA_DOWNLOADED] = SHIFT_JIS("KAKUSAN     カクサン ニュウシュ ナビヘ "),
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA_2] = SHIFT_JIS("TOANKOKUOKU アンコク カクシヲ サガセ  "),
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC_2] = SHIFT_JIS("TOSHUTTER   アンコクナビデ コウシン  "),
    [EVENT_RESTRICTED_ZONE_WARNING] = SHIFT_JIS("SHUTTER     アンコクノ オクヘ       "),
    [EVENT_TRIGGERED_BOX_2_RUMBLE] = SHIFT_JIS("SHUTTER2    シャッター ジシン      "),
    [EVENT_WAVE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("WAVEB       アンコクノ オクヘ2      "),
    [EVENT_RESTRICTED_LABORATORY_EXPLOSION] = SHIFT_JIS("TOGOKUHIKEN ゴクヒ デモ        "),
    [EVENT_60_SECONDS_TO_DETACHMENT] = SHIFT_JIS("RANSHA      ランシャ アンド タイマー  "),
    [EVENT_ESCAPED_RESTRICTED_LABORATORY] = SHIFT_JIS("TOKIRIHANA  キリハナシ           "),
    [EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY] = SHIFT_JIS("KIRIHANA    カサイゴ コウシン      "),
    [EVENT_SCREW_ATTACK_ABILITY_RECOVERED] = SHIFT_JIS("DOWNBOSS7   ボス7 タオシ ダッシュツ "),
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX_2] = SHIFT_JIS("TOOPE       シンジツ           "),
    [EVENT_END_OF_FIRST_CONVERSATION] = SHIFT_JIS("TOOPEMONO   モノローグ          "),
    [EVENT_SECOND_CONVERSATION] = SHIFT_JIS("TOOPE2      キドウヲ カエロ       "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6] = SHIFT_JIS("TOOPE3      アダム サイド コウシン  "),
    [EVENT_ENTERED_OPERATION_DECK] = SHIFT_JIS("INTOOPE     オペレーションニ ハイル   "),
    [EVENT_SA_X_DEFEATED] = SHIFT_JIS("DOWNSAX     SAXヲ タオス        "),
    [EVENT_ORBIT_CHANGE_IMPLEMENTED] = SHIFT_JIS("KIDOUKAE    キドウヲ カエル       "),
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7] = SHIFT_JIS("ESCAPE      キドウヘンコウゴ コウシン "),
    [EVENT_ENTERED_SHIP_ROOM] = SHIFT_JIS("OMEGA       メトロイド ト セントウ   "),
    [EVENT_SA_X_KILLED_BY_OMEGA_METROID] = SHIFT_JIS("DOWNSAX2    オメガ SAXヲ タオス   "),
    [EVENT_ICE_BEAM_ABILITY_RECOVERED] = SHIFT_JIS("ICEBEAM     アイスビーム カクトク    "),
    [EVENT_OMEGA_METROID_DEFEATED] = SHIFT_JIS("DOWNOMEGA   メトロイド ヲ タオス    "),
    [EVENT_ESCAPED_ON_SHIP] = SHIFT_JIS("END         エンド            "),
};

const u8 sDebugLocationSectionInfo[2][2] = {
    [0] = {
        [0] = 12,
        [1] = 17,
    },
    [1] = {
        [0] = 13,
        [1] = 17,
    }
};

const u8 sDebugSectionInfo[PAUSE_DEBUG_SECTION_END][5] = {
    [PAUSE_DEBUG_SECTION_BEAM] = {
        [0] = 4,
        [1] = 4 + ARRAY_SIZE(sPauseDebugBeamFlags) - 1,
        [2] = 1,
        [3] = 7,
        [4] = PAUSE_DEBUG_SECTION_BEAM,
    },
    [PAUSE_DEBUG_SECTION_MISSILE] = {
        [0] = 11,
        [1] = 11 + ARRAY_SIZE(sPauseDebugMissileFlags) - 1,
        [2] = 1,
        [3] = 7,
        [4] = PAUSE_DEBUG_SECTION_MISSILE,
    },
    [PAUSE_DEBUG_SECTION_BOMB] = {
        [0] = 3,
        [1] = 3 + ARRAY_SIZE(sPauseDebugBombFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_BOMB,
    },
    [PAUSE_DEBUG_SECTION_SUIT] = {
        [0] = 7,
        [1] = 7 + ARRAY_SIZE(sPauseDebugSuitFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_SUIT,
    },
    [PAUSE_DEBUG_SECTION_MISC] = {
        [0] = 11,
        [1] = 11 + ARRAY_SIZE(sPauseDebugMiscFlags) - 1,
        [2] = 9,
        [3] = 15,
        [4] = PAUSE_DEBUG_SECTION_MISC,
    },
    [PAUSE_DEBUG_SECTION_ENERGY_CURRENT] = {
        [0] = 2,
        [1] = 2,
        [2] = 25,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ENERGY_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_ENERGY_MAX] = {
        [0] = 3,
        [1] = 3,
        [2] = 25,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ENERGY_MAX,
    },
    [PAUSE_DEBUG_SECTION_SUPPLY] = {
        [0] = UCHAR_MAX,
        [1] = UCHAR_MAX,
        [2] = 1,
        [3] = 1,
        [4] = PAUSE_DEBUG_SECTION_SUPPLY,
    },
    [PAUSE_DEBUG_SECTION_MISSILE_CURRENT] = {
        [0] = 5,
        [1] = 5,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_MISSILE_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_MISSILE_MAX] = {
        [0] = 6,
        [1] = 6,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_MISSILE_MAX,
    },
    [PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT] = {
        [0] = 7,
        [1] = 7,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT,
    },
    [PAUSE_DEBUG_SECTION_POWER_BOMB_MAX] = {
        [0] = 8,
        [1] = 8,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_POWER_BOMB_MAX,
    },
    [PAUSE_DEBUG_SECTION_ABILITY_COUNT] = {
        [0] = 9,
        [1] = 9,
        [2] = 27,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_ABILITY_COUNT,
    },
    [PAUSE_DEBUG_SECTION_SECURITY] = {
        [0] = 15,
        [1] = 15,
        [2] = 24,
        [3] = 24 + SECURITY_LEVEL_4,
        [4] = PAUSE_DEBUG_SECTION_SECURITY,
    },
    [PAUSE_DEBUG_SECTION_MAP] = {
        [0] = 18,
        [1] = 18,
        [2] = 1,
        [3] = 1 + AREA_NORMAL_LAST,
        [4] = PAUSE_DEBUG_SECTION_MAP,
    },
    [PAUSE_DEBUG_SECTION_EVENT] = {
        [0] = 10,
        [1] = 10,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_EVENT,
    },
    [PAUSE_DEBUG_SECTION_SOUND_EVENT] = {
        [0] = 13,
        [1] = 13,
        [2] = 26,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_SOUND_EVENT,
    },
    [PAUSE_DEBUG_SECTION_IN_GAME_TIME] = {
        [0] = 18,
        [1] = 18,
        [2] = 23,
        [3] = 28,
        [4] = PAUSE_DEBUG_SECTION_IN_GAME_TIME,
    },
    [PAUSE_DEBUG_SECTION_QUICK_SAVE] = {
        [0] = 15,
        [1] = 15,
        [2] = 17,
        [3] = 21,
        [4] = PAUSE_DEBUG_SECTION_QUICK_SAVE,
    },
};

static const u8 sBlob_58217b_58225c[] = INCBIN_U8("data/Blob_58217b_58225c.bin");
