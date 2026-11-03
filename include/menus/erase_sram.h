#ifndef ERASE_SRAM_MENU_H
#define ERASE_SRAM_MENU_H

#include "types.h"

u32 EraseSramMenuHandler(void);
u32 EraseSramProcessInput(void);
void EraseSramApplyInput(void);
u32 EraseSramCheckForInput(void);
void EraseSramMenuInit(void);
void EraseSramResetOam(void);
void EraseSramUpdateCursorPosition(void);
void EraseSramVBlank(void);
void EraseSramLoadingVBlank(void);
void EraseSramProcessOam(void);

#endif /* ERASE_SRAM_MENU_H */
