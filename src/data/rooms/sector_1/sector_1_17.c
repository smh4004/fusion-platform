#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_17_Clipdata[] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_17_clipdata.rle")
};

const u8 sSector1_17_Bg2[] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_17_bg2.rle")
};

const u8 sSector1_17_Bg1[] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_17_bg1.rle")
};

const u8 sSector1_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_17_Bg0[] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_17_bg0.rle")
};

