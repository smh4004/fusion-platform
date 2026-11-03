#ifndef FILE_SELECT_STRUCTS_H
#define FILE_SELECT_STRUCTS_H

#include "types.h"
#include "oam.h"
#include "structs/save_file_info.h"

#define FILE_SELECT_DATA gNonGameplayRam.fileSelect


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
    u16 textX;
    u16 textY;
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
    u8 textIndent;
    u8 corruptedStage;
    u8 corruptedFile;
    u8 padding_16[2];
    struct FileSelectOam oam[23];
    struct SaveFileInfo emptyFileInfo;
};

#endif /* FILE_SELECT_STRUCTS_H */
