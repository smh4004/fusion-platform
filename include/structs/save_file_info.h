#ifndef SAVE_FILE_INFO_STRUCT_H
#define SAVE_FILE_INFO_STRUCT_H

#include "types.h"

// Summary of one save file, shown on the file select screen
struct SaveFileInfo {
    u8 exists;
    u8 corruptionFlag;
    u8 currentArea;
    u8 eventCounter;
    u16 currentEnergy;
    u16 maxEnergy;
    u16 currentMissiles;
    u16 maxMissiles;
    u8 weaponsStatus;
    u8 igtHours;
    u8 igtMinutes;
    u8 hasSaved;
    s8 completedGame;
    s8 introPlayed;
    u8 unk_12;
    u8 unk_13;
};

#endif /* SAVE_FILE_INFO_STRUCT_H */
