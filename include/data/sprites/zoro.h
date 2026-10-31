#ifndef ZORO_DATA_H
#define ZORO_DATA_H

#include "macros.h"
#include "oam.h"

extern const u32 sZoroGfx[];
extern const u32 sBlueZoroGfx[];
extern const u16 sZoroPal[];
extern const u16 sBlueZoroPal[];

extern const struct FrameData sZoroOam_CrawlingHorizontal[7];
extern const struct FrameData sZoroOam_TurningAroundHorizontal1[3];
extern const struct FrameData sZoroOam_TurningAroundHorizontal2[3];
extern const struct FrameData sZoroOam_CrawlingVertical[7];
extern const struct FrameData sZoroOam_TurningAroundVertical1[3];
extern const struct FrameData sZoroOam_TurningAroundVertical2[3];

#endif /* ZORO_DATA_H */
