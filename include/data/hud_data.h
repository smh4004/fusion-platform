#ifndef HUD_DATA_H
#define HUD_DATA_H

#include "types.h"
#include "oam.h"
#include "macros.h"

extern const u16 sCommonSpritesPal[];
extern const u8 sCommonSpritesGfx[14 * 32 * 32];

extern const u8 sMissileIconGfx[];
extern const u8 sPowerBombIconGfx[];
extern const u8 sAmmoDigitsGfx[];
extern const u8 sEnergyDigitsGfx[];
extern const u8 sEnergyTanksGfx_Full[];
extern const u8 sEnergyTanksGfx_Empty[];
extern const u8 sEnergyTankGfx_OneFull[];
extern const u8 sEnergyTankGfx_OneFullOneEmpty[1 * 32];

extern const u16 sEscapeDigitsPal[];
extern const u8 sEscapeDigitsGfx[2048];
extern const u16 sEscapeDigitsOam[OAM_DATA_SIZE(8)];
extern const struct FrameData sEscapeTimerFrameData[2];

#endif /* HUD_DATA_H */
