#ifndef SAVE_FILE_STRUCT_H
#define SAVE_FILE_STRUCT_H

#include "types.h"
#include "macros.h"
#include "gba/memory.h"

#include "constants/connection.h"

#include "globals.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/save_file_info.h"

#define EWRAM_SRAM (EWRAM_BASE + 0x38000)
#define SRAM_HEADER_SIZE 0x80
#define SRAM_FULL_HEADER_SIZE (SRAM_HEADER_SIZE * 2)

#define SRAM_TEXT_SIZE 16
#define SRAM_END_TEXT_SIZE 8
#define SRAM_VERSION_TEXT_SIZE 20

#define SRAM_GET_CHECKSUM_SIZE(type, iteration, checksumType) ((s32)(sizeof(type) / iteration / sizeof(checksumType)))

// struct SaveFileInfo is in structs/save_file_info.h

struct SaveMusicInfo {
    u16 musicTrack;
    u16 unk_2;
    u8 unk_4;
    u8 priority;
    u16 unk_6;
};

struct SaveFile {
    u8 MetroidEpisode4A_Text[SRAM_TEXT_SIZE];
    s32 checksum;
    s32 notChecksum;

    struct GameCompletion gameCompletion; // 0x18
    u8 hasSaved; // 0x1C
    u8 currentArea;
    u8 currentRoom;
    u8 lastDoorUsed;
    u8 abilityCount; // 0x20
    u8 eventCounter;
    u8 previousNavigationConversation;
    u8 previousCutscene;
    u8 mapX; // 0x24
    u8 mapY;
    u16 soundEventCounter;
    u16 previousSoundEvent; // 0x28
    u8 unk_2A;
    u8 securityHatchLevelBackup;

    struct Camera camera; // 0x2C
    u16 bg0XPosition; // 0x40
    u16 bg0YPosition;
    u16 bg1XPosition;
    u16 bg1YPosition;
    u16 bg2XPosition;
    u16 bg2YPosition;
    u16 bg3XPosition;
    u16 bg3YPosition;

    u8 numberOfNeverReformBlocksBroken[MAX_AMOUNT_OF_AREAS]; // 0x50
    u8 numberOfItemsCollected[MAX_AMOUNT_OF_AREAS]; // 0x58

    struct SamusData samusData; // 0x60
    struct SamusAnimationInfo samusAnimationInfo; // 0x8C
    struct SamusEcho samusEcho; // 0x98
    struct SamusEnvironmentalEffect environmentalEffects[2]; // 0xA4
    struct Equipment equipment; // 0xC4
    u16 preventMovementTimer; // 0xD4
    u8 disableDrawingSamusAndScrolling; // 0xD6
    u8 unk_D7;

    u16 atmosphericStabilizersOnline; // 0xD8
    u16 missileGeronsDestroyed;
    u16 superMissileGeronsDestroyed;
    u16 powerBombGeronsDestroyed;
    u16 gadorasDestroyed; // 0xE0
    u8 missileHatchDestroyed;
    u8 waterLowered;
    struct InGameTime inGameTimer; // 0xE4
    struct SaveMusicInfo musicInfo; // 0xE8

    u8 SAVE_END_Text[SRAM_END_TEXT_SIZE]; // 0xF0
    u8 freeSpace[0x1200 - 0xF8];
};

struct SramHeader {
    s32 checksum;
    s32 notChecksum;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 versionText[SRAM_VERSION_TEXT_SIZE];
    u8 padding_20[0x60];
};

struct SaveValue {
    u8 magicNumber;
    u8 counter;
    u16 checksum;
    u16 notChecksum;

    u8 startText[SRAM_TEXT_SIZE];
    u8 value;
    u8 endText[SRAM_TEXT_SIZE];

    u8 padding_27[25];
};

struct Sram {
    struct SramHeader header; // 0x0
    struct SramHeader headerBackup; // 0x80
    u8 unk_100[0x100];
    struct SaveFile files[6]; // 0x200, file 0, backup 0, file 1, backup 1...
    u8 unk_6E00[0x200];
    struct SaveValue mostRecentFileSave; // 0x7000
    struct SaveValue languageSaves[2]; // 0x7040
    u8 unk_70C0[0x40];
    struct SramHeader headerBackup2; // 0x7100
    u8 unk_7180[0xE80];
};

extern u8 gMostRecentSaveFile;

extern u8 gSramHeaderUnk_3000010;
extern u8 gSramCorruptFlag;
extern u8 gHasSaved;
extern struct SaveFileInfo gSaveFilesInfo[3];
extern u8 gNavConversationTargetLocation;
extern u8 gFlashingSectorNumber;

#define gSram (*(struct Sram*)EWRAM_SRAM)

#endif /* SAVE_FILE_STRUCT_H */
