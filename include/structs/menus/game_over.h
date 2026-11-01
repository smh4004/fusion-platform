#ifndef GAME_OVER_STRUCTS_H
#define GAME_OVER_STRUCTS_H

#include "types.h"
#include "oam.h"

#define GAME_OVER_DATA gNonGameplayRam.gameOver

struct GameOverOam;
typedef void (*GameOverOamFunc_T)(struct GameOverOam*);

struct GameOverOam {
    u16 xPosition;
    s16 yPosition;
    u8 type;
    u8 isDrawn;
    u8 currentAnimationFrame;
    u8 animationDurationCounter;
    u8 unk_8;
    u8 selected;
    u8 objMode;
    u8 priority;
    u8 xFlip;
    u8 paletteOffset;
    u16 tileOffset;
    const struct FrameData* pOam;
    GameOverOamFunc_T pHandler;
};

struct GameOverData {
    u8 unk_0;
    u8 optionChosen;
    u8 timer;
    u8 optionSelected;
    struct GameOverOam oam[3];
};

#endif /* GAME_OVER_STRUCTS_H */
