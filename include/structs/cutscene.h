#ifndef CUTSCENE_STRUCT_H
#define CUTSCENE_STRUCT_H

#include "types.h"

struct SpecialCutsceneOam {
    s16 spawnX;
    s16 spawnY;
    s16 unk_4;
    s16 scaling;
    s16 unk_8;
    u16 unk_A;
    s16 xPosition;                // 0xC
    s16 yPosition;                // 0xE
    u8 type;                       // 0x10
    u8 currentAnimationFrame;      // 0x11
    u8 animationDurationCounter;   // 0x12
    u8 timer;                      // 0x13
    u8 stage;                      // 0x14
    u8 rotation;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18_0 : 1;
    u32 affineMode : 2;         // Can't be u8
    u8 unk_18_3 : 2;
    u8 unk_18_5 : 1;
    u8 unk_19;
    u8 unk_1A_0 : 2;
    u8 priority : 2;
    u8 unk_1A_4 : 4;
    u8 unk_1B;
    const struct FrameData* pOam;  // 0x1C
    void* pFunction;               // 0x20
};

struct CutsceneOam {
    s16 xPosition;
    s16 yPosition;
    s16 scaling;
    s16 spawnX;
    s16 spawnY;
    s16 unk_A;
    s16 unk_C;
    u16 unk_E;
    u8 type;                       // 0x10
    u8 currentAnimationFrame;      // 0x11
    u8 animationDurationCounter;   // 0x12
    u8 timer;                      // 0x13
    u8 stage;                      // 0x14
    u8 rotation;                   // 0x15
    u8 enabled : 1;                // 0x16
    u32 affineMode : 2;            // Can't be u8
    u8 unk_16_3 : 2;
    u8 unk_16_5 : 1;
    u8 xFlip : 1;
    u8 unk_16_7 : 1;
    u8 unk_17;
    u8 unk_18_0 : 2;
    u8 priority : 2;
    u8 unk_18_4 : 4;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    const struct FrameData* pOam;  // 0x1C
    void (*pFunction)(struct CutsceneOam* pOam); // 0x20
};

struct CutsceneMonologueOam {
    s16 xPosition;
    s16 yPosition;
    u8 type;
    u8 enabled;
    u8 currentAnimationFrame;
    u8 animationDurationCounter;
    u8 unk_8;
    u8 stage;
    u8 objMode;
    u8 priority;
    u8 xFlip;
    u8 paletteOffset;
    u16 tileOffset;
    const struct FrameData* pOam;
    void (*pFunction)(struct CutsceneMonologueOam* pOam);
};

struct CutsceneMonologueData {
    u8 textIndent;
    u8 unk_19[3];
    u8 characterFade[252];
    u8 characterFadeTimer[252];
    struct CutsceneMonologueOam oam[5];
};

struct CutsceneData {
    u16 textColumn;
    u16 textLine;
    u16 fadeColumn;
    u16 fadeLine;
    u16 stage;
    u16 unk_A;
    const u16* pText;
    u16 timer;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 textState;
    union {
        struct CutsceneMonologueData monologue;
        struct CutsceneOam oam[16];
    } u;
};

#endif /* CUTSCENE_STRUCT_H */
