#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_59_Clipdata[] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_59_clipdata.rle")
};

const u8 sMainDeck_59_Bg2[] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_59_bg2.rle")
};

const u8 sMainDeck_59_Bg1[] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_59_bg1.rle")
};

const u8 sMainDeck_59_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_59_Bg0[] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_59_bg0.rle")
};

