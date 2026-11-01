#ifndef FILE_SELECT_STRUCTS_H
#define FILE_SELECT_STRUCTS_H

#include "types.h"
#include "oam.h"

#define FILE_SELECT_DATA gNonGameplayRam.fileSelect

struct SaveFileInfo {
    u8 exists;
    u8 corruptionFlag;
    u8 currentArea;
    u8 unk_3;
    u16 currentEnergy;
    u16 maxEnergy;
    u16 currentMissiles;
    u16 maxMissiles;
    u8 unk_C;
    u8 igtHours;
    u8 igtMinutes;
    u8 hasSaved;
    s8 completedGame;
    s8 introPlayed;
};

extern struct SaveFileInfo gSaveFilesInfo[3];

struct FileSelectOam;
typedef void (*FileSelectOamFunc_T)(struct FileSelectOam*);

struct FileSelectOam {
    u16 xPosition;
    u16 yPosition;
    u8 type;
    u8 isDrawn;
    u8 currentAnimationFrame;
    u8 animationDurationCounter;
    u8 unk_8;
    u8 action;
    u8 objMode;
    u8 priority;
    u8 xFlip;
    u8 paletteOffset;
    u16 tileOffset;
    u32 unk_10;
    const struct FrameData* pOam;
    FileSelectOamFunc_T pHandler;
};

struct FileSelectData {
    u16 timer;
    u16 unk_2;
    const u16* pText;
    u16 textId;
    s16 menuState;
    u8 stage;
    u8 currentFile;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 bgToggle;
    s8 result;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 padding_16[2];
    struct FileSelectOam oam[23];
    struct SaveFileInfo emptyFileInfo;
};

#endif /* FILE_SELECT_STRUCTS_H */
