#ifndef ENDING_STRUCT_H
#define ENDING_STRUCT_H

#include "types.h"

#include "constants/ending.h"

struct CreditsEntry {
    CreditLineType type;
    u8 text[35];
};

struct EndingTextLetter {
    u8 unk_0;
    u8 spawnDelay;
    u8 unk_2;
    u16 xPosition;
    u16 yPosition;
    const u16* pOam;
};

struct EndingData {
    u8 unk_0;
    u8 stage;
    u16 unk_2;
    u16 unk_4;
    u16 currentCreditLine;
    u16 unk_8;
    u16 creditLineTilemap_1[32];
    u16 creditLineTilemap_2[32];
    u32 unk_8C;
    u32 unk_90;
    u16 timer;
    u8 unk_96;
    u8 unk_97;
    u8 unk_98;
    u8 unk_99;
    u8 completionPercentage;
    u8 unk_9B;
    u8 unk_9C;
    u8 unk_9D;
    u8 padding2[2];
    u16* unk_A0;
    u8 unk_A4[0x80];
    u8 unk_124[30];
    u8 lettersSpawnDelay[30]; // 142
    u8 unk_160[30];
    u16 oamXPositions[30]; // 17E
    u16 oamYPositions[30]; // 1BA
    u8 padding4[2];
    u16* oamFramePointers[30]; // 1F8
    u8 unk_270[64]; // FIXME find actual length
};

#endif /* ENDING_STRUCT_H */
