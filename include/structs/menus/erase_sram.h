#ifndef ERASE_SRAM_MENU_STRUCTS_H
#define ERASE_SRAM_MENU_STRUCTS_H

#include "types.h"
#include "structs/menus/pause_screen.h"

struct EraseSramData {
    u8 currentOption;
    u8 nextOption;
    u8 language;
    u16 timer;
    u16 bldcnt;
    u8 bldyTarget;
    struct MenuOam oam[3];
};

#endif /* ERASE_SRAM_MENU_STRUCTS_H */
