#include "data/rooms/test_rooms_data.h"
#include "macros.h"
#include "gba/display.h"

const u8 sTest3_0_Clipdata[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test3_0_clipdata.rle")
};

const u8 sTest3_0_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest3_0_Bg2[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test3_0_bg2.rle")
};

const u8 sTest3_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 105, SPRITESET_IDX(5),
	9, 32, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest3_0_Bg1[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test3_0_bg1.rle")
};

const u8 sTest3_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 105, SPRITESET_IDX(5),
	9, 32, SPRITESET_IDX(0),
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest3_0_Bg0[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test3_0_bg0.rle")
};

const u8 sTest12_0_Clipdata[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test12_0_clipdata.rle")
};

const u8 sTest12_0_Bg2[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test12_0_bg2.rle")
};

const u8 sTest12_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 105, SPRITESET_IDX(5),
	9, 32, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest12_0_Bg1[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test12_0_bg1.rle")
};

const u8 sTest12_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 105, SPRITESET_IDX(5),
	9, 32, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest12_0_Bg0[] = {
    142, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/test/test12_0_bg0.rle")
};

const u8 sTest123_1_Clipdata[] = {
    24, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/test/test123_1_clipdata.rle")
};

const u8 sTest123_1_Bg2[] = {
    24, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/test/test123_1_bg2.rle")
};

const u8 sTest123_1_Bg1[] = {
    24, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/test/test123_1_bg1.rle")
};

const u8 sTest123_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest123_2_Clipdata[] = {
    52, // Room width
    29, // Room height
    _INCBIN_U8("data/rooms/test/test123_2_clipdata.rle")
};

const u8 sTest123_2_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest123_2_Bg2[] = {
    52, // Room width
    29, // Room height
    _INCBIN_U8("data/rooms/test/test123_2_bg2.rle")
};

const u8 sTest123_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTest123_2_Bg1[] = {
    52, // Room width
    29, // Room height
    _INCBIN_U8("data/rooms/test/test123_2_bg1.rle")
};

const u8 sTest123_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

static const u8 padding[3] = {0,0,0};

const u8 sTest123_3_Clipdata[] = {
    42, // Room width
    23, // Room height
    _INCBIN_U8("data/rooms/test/test123_3_clipdata.rle")
};

const u8 sTest123_3_Bg2[] = {
    42, // Room width
    23, // Room height
    _INCBIN_U8("data/rooms/test/test123_3_bg2.rle")
};

const u8 sTest123_3_Bg1[] = {
    42, // Room width
    23, // Room height
    _INCBIN_U8("data/rooms/test/test123_3_bg1.rle")
};

const u8 sTest123_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

static const u8 sPadding_3f21a1[3] = { 0, 0, 0 };

const u8 sDoorTransitionTilemap[] = INCBIN_U8("data/rooms/door_transition.tm.rle");

const u32 sBg3_Empty[64] = {
    BGCNT_SIZE_256x256,
    _INCBIN_U32("data/rooms/bg3_empty.tm.lz")
};

const u8 sBg0_TestWater[] = INCBIN_U8("data/rooms/test/test_water_bg0.tm.lz");

const u32 sBg3_TestRoom[224] = {
    BGCNT_SIZE_256x256,
    _INCBIN_U32("data/rooms/test/test_room_bg3.tm.lz")
};

// Move to separate file?
const u8 sCommonTilesGfx[4096] = INCBIN_U8("data/common/common_tiles.gfx");
