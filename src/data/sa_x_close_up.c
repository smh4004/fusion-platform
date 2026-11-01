#include "data/sa_x_close_up.h"
#include "macros.h"

const u16 sSaXCloseUpPal[16 * 16] = INCBIN_U16("data/sa_x_close_up/palette.pal");
const u16 sSaXCloseUpPalGrayscale[16 * 16] = INCBIN_U16("data/sa_x_close_up/palette_grayscale.pal");
const u32 sSaXCloseUpGfx[4472] = INCBIN_U32("data/sa_x_close_up/graphics.gfx.lz");
const u32 sSaXCloseUpTileTable1[294] = INCBIN_U32("data/sa_x_close_up/first.tt.lz");
const u32 sSaXCloseUpTileTable2[305] = INCBIN_U32("data/sa_x_close_up/second.tt.lz");

const u8 sSaXCloseUpDurations[2] = { 25, 60 };

static const u8 sBlob_73421e_734220[] = INCBIN_U8("data/Blob_73421e_734220.bin");

const u8 sGameOverOamXFlipOffsets[3][4] = {
    [0] = {
        1, 2, 4, 8
    },
    [1] = {
        2, 4, 4, 8
    },
    [2] = {
        1, 1, 2, 4
    }
};

static const u8 sBlob_73422c_73dac4[] = INCBIN_U8("data/Blob_73422c_73dac4.bin");

const u16 sFileSelectBackdropColors[6] = {
    0x5AC0, 0x0000, 0x7FFF, 0x39CE, 0x03DF, 0x20CC
};

static const u8 sBlob_73dad0_73dba4[] = INCBIN_U8("data/Blob_73dad0_73dba4.bin");

const u8 sFileSelectOamXFlipOffsets[3][4] = {
    [0] = {
        1, 2, 4, 8
    },
    [1] = {
        2, 4, 4, 8
    },
    [2] = {
        1, 1, 2, 4
    }
};

static const u8 sBlob_73dbb0_7478a0[] = INCBIN_U8("data/Blob_73dbb0_7478a0.bin");
