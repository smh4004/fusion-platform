#include "data/sa_x_close_up.h"
#include "macros.h"
#include "constants/game_state.h"

const u16 sSaXCloseUpPal[16 * 16] = INCBIN_U16("data/sa_x_close_up/palette.pal");
const u16 sSaXCloseUpPalGrayscale[] = INCBIN_U16("data/sa_x_close_up/palette_grayscale.pal");
const u32 sSaXCloseUpGfx[] = INCBIN_U32("data/sa_x_close_up/graphics.gfx.lz");
const u32 sSaXCloseUpTileTable1[] = INCBIN_U32("data/sa_x_close_up/first.tt.lz");
const u32 sSaXCloseUpTileTable2[] = INCBIN_U32("data/sa_x_close_up/second.tt.lz");

const u8 sSaXCloseUpDurations[2] = { 25, 60 };

const u8 sBlob_73421e_734220[] = INCBIN_U8("data/Blob_73421e_734220.bin");

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

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_73422c_73dac4[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_73422c_73dac4\n\
sBlob_73422c_73dac4:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x0, 0x8048\n\
    .4byte sBlob_73422c_73dac4 + 0x7fec\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x804c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8036\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8054, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x803e\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x805c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8036\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8064, 0xc\n\
    .4byte sBlob_73422c_73dac4 + 0x7fec\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8074, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x7ff4\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x807c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x7ffc\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8084, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8004\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x808c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x800c\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8094, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x801a\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x809c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8028\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x80a4, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8004\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x80ac, 0x17ec\n\
    .popsection\n\
");

const u16 sFileSelectBackdropColors[6] = {
    0x5AC0, 0x0000, 0x7FFF, 0x39CE, 0x03DF, 0x20CC
};

const u8 sBlob_73dad0_73dba4[] = INCBIN_U8("data/Blob_73dad0_73dba4.bin");

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

const u8 sFileSelectCopyArrowXPositions[LANGUAGE_COUNT][2] = {
    [0] = { 120, 160 },
    [1] = { 120, 160 },
    [2] = { 119, 166 },
    [3] = { 119, 164 },
    [4] = { 119, 164 },
    [5] = { 119, 159 },
    [6] = { 119, 159 }
};

const u8 sFileSelectEraseArrowXPositions[LANGUAGE_COUNT][2] = {
    [0] = { 120, 160 },
    [1] = { 120, 160 },
    [2] = { 119, 166 },
    [3] = { 119, 164 },
    [4] = { 119, 164 },
    [5] = { 119, 159 },
    [6] = { 119, 159 }
};

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_73dbcc_7478a0[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_73dbcc_7478a0\n\
sBlob_73dbcc_7478a0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x0, 0x2b2c\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1668\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b30, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x16a6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b40, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x16e4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b50, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1722\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b60, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1760\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b70, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x179e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b88, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17ac\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2b98, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ba0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17ba\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bb0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bb8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17c8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bc8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bd0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17d6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2be0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2be8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17fe\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bf8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1824\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c08, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x183e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c18, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1864\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c28, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e14\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c38, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1eb8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c40, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1f5c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c48, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2000\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c58, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x20a4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c60, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2148\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c68, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x21ec\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c78, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2290\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2334\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c88, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18a8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c98, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18bc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ca8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18d0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cb8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18d8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cc0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18e0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cc8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18d8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cd0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18e8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ce0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18f0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ce8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cf8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1996\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d08, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x19c2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d18, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17e4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d28, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1db8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d30, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1dd2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d38, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1db8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d40, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x19ee\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d50, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x19fc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d58, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a0a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d60, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a24\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d68, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a4a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d78, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a24\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d88, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a0a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d90, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x19fc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d98, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x19ee\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2da0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a64\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2db0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2db8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a8c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2dc0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1aa6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2dc8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1acc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2dd8, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1aa6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2de8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a8c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2df0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2df8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a64\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e00, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e10, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e20, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b28\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e30, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b36\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e40, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b44\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e50, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b52\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e60, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b60\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e70, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b6e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e88, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b22\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e90, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e98, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b6e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ea8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b76\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2eb0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2eb8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b86\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ec0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b8e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ec8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b9c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ed0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1baa\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ed8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b86\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ee0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1bc6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ef0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1c64\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f00, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1d02\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f10, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x23d8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f20, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x247c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f28, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2520\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f30, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x25c4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f40, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2668\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f48, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x270c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f50, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x27b0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f60, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2854\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f68, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x28f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f70, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1dec\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1df4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f88, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1dfc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f90, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1df4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f98, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fa8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fb0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e04\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fb8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fc0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x299c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fd0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29a4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fe0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29b2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ff0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29c0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3000, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29ce\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3010, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29dc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3020, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29ea\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3030, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3040, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a06\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3050, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3060, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a2e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3070, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a42\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3080, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a56\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3090, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a6a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30a0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30b0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a86\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30c0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a9a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30d0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2aae\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30e0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2ac2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30f0, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2ad6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3100, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2aea\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3110, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2afe\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3120, 0xc\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3130, 0x6ba4\n\
    .popsection\n\
");
