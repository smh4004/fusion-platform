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
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x0, 0x584c\n\
    .global sAddr_739a78\n\
sAddr_739a78:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x584c, 0x2e0\n\
    .global sAddr_739d58\n\
sAddr_739d58:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x5b2c, 0x6d8\n\
    .global sAddr_73a430\n\
sAddr_73a430:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x6204, 0x6f8\n\
    .global sAddr_73ab28\n\
sAddr_73ab28:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x68fc, 0x7e0\n\
    .global sAddr_73b308\n\
sAddr_73b308:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x70dc, 0x7a4\n\
    .global sAddr_73baac\n\
sAddr_73baac:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x7880, 0x7c8\n\
    .global sAddr_73c274\n\
sAddr_73c274:\n\
    .4byte sBlob_73422c_73dac4 + 0x7fec\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x804c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8036\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8054, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x803e\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x805c, 0x4\n\
    .4byte sBlob_73422c_73dac4 + 0x8036\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8064, 0xc\n\
    .global sAddr_73c29c\n\
sAddr_73c29c:\n\
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
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x80ac, 0xc\n\
    .global sAddr_73c2e4\n\
sAddr_73c2e4:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x80b8, 0x200\n\
    .global sAddr_73c4e4\n\
sAddr_73c4e4:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x82b8, 0x200\n\
    .global sAddr_73c6e4\n\
sAddr_73c6e4:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x84b8, 0x5c4\n\
    .global sAddr_73cca8\n\
sAddr_73cca8:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8a7c, 0x304\n\
    .global sAddr_73cfac\n\
sAddr_73cfac:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x8d80, 0x3d4\n\
    .global sAddr_73d380\n\
sAddr_73d380:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x9154, 0x26c\n\
    .global sAddr_73d5ec\n\
sAddr_73d5ec:\n\
    .incbin \"data/Blob_73422c_73dac4.bin\", 0x93c0, 0x4d8\n\
    .popsection\n\
");

const u16 sFileSelectBackdropColors[6] = {
    0x5AC0, 0x0000, 0x7FFF, 0x39CE, 0x03DF, 0x20CC
};

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_73dad0_73dba4[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_73dad0_73dba4\n\
sBlob_73dad0_73dba4:\n\
    .incbin \"data/Blob_73dad0_73dba4.bin\", 0x0, 0xb4\n\
    .global sAddr_73db84\n\
sAddr_73db84:\n\
    .incbin \"data/Blob_73dad0_73dba4.bin\", 0xb4, 0x20\n\
    .popsection\n\
");

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
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x0, 0xc\n\
    .global sAddr_73dbd8\n\
sAddr_73dbd8:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0xc, 0x6\n\
    .global sAddr_73dbde\n\
sAddr_73dbde:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x12, 0x6\n\
    .global sAddr_73dbe4\n\
sAddr_73dbe4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x18, 0x6\n\
    .global sAddr_73dbea\n\
sAddr_73dbea:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x1e, 0xc\n\
    .global sAddr_73dbf6\n\
sAddr_73dbf6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2a, 0x6\n\
    .global sAddr_73dbfc\n\
sAddr_73dbfc:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30, 0x6\n\
    .global sAddr_73dc02\n\
sAddr_73dc02:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x36, 0x6\n\
    .global sAddr_73dc08\n\
sAddr_73dc08:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3c, 0xc\n\
    .global sAddr_73dc14\n\
sAddr_73dc14:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x48, 0xc\n\
    .global sAddr_73dc20\n\
sAddr_73dc20:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x54, 0x2ad8\n\
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
    .global sAddr_7407c0\n\
sAddr_7407c0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x17fe\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2bf8, 0xc\n\
    .global sAddr_7407d0\n\
sAddr_7407d0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1824\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c08, 0xc\n\
    .global sAddr_7407e0\n\
sAddr_7407e0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x183e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c18, 0xc\n\
    .global sAddr_7407f0\n\
sAddr_7407f0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1864\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c28, 0xc\n\
    .global sAddr_740800\n\
sAddr_740800:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1e14\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c38, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1eb8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c40, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1f5c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c48, 0xc\n\
    .global sAddr_740820\n\
sAddr_740820:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2000\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c58, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x20a4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c60, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2148\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2c68, 0xc\n\
    .global sAddr_740840\n\
sAddr_740840:\n\
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
    .global sAddr_7408c0\n\
sAddr_7408c0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x18f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2cf8, 0xc\n\
    .global sAddr_7408d0\n\
sAddr_7408d0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1996\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d08, 0xc\n\
    .global sAddr_7408e0\n\
sAddr_7408e0:\n\
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
    .global sAddr_740940\n\
sAddr_740940:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a4a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2d78, 0xc\n\
    .global sAddr_740950\n\
sAddr_740950:\n\
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
    .global sAddr_7409a0\n\
sAddr_7409a0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1acc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2dd8, 0xc\n\
    .global sAddr_7409b0\n\
sAddr_7409b0:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1aa6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2de8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a8c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2df0, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2df8, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1a64\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e00, 0xc\n\
    .global sAddr_7409d8\n\
sAddr_7409d8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e10, 0xc\n\
    .global sAddr_7409e8\n\
sAddr_7409e8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e20, 0xc\n\
    .global sAddr_7409f8\n\
sAddr_7409f8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b28\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e30, 0xc\n\
    .global sAddr_740a08\n\
sAddr_740a08:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b36\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e40, 0xc\n\
    .global sAddr_740a18\n\
sAddr_740a18:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b44\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e50, 0xc\n\
    .global sAddr_740a28\n\
sAddr_740a28:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b52\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e60, 0xc\n\
    .global sAddr_740a38\n\
sAddr_740a38:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b60\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e70, 0xc\n\
    .global sAddr_740a48\n\
sAddr_740a48:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1b6e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e88, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b22\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e90, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2e98, 0xc\n\
    .global sAddr_740a70\n\
sAddr_740a70:\n\
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
    .global sAddr_740ab8\n\
sAddr_740ab8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1bc6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ef0, 0xc\n\
    .global sAddr_740ac8\n\
sAddr_740ac8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1c64\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f00, 0xc\n\
    .global sAddr_740ad8\n\
sAddr_740ad8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1d02\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f10, 0xc\n\
    .global sAddr_740ae8\n\
sAddr_740ae8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x23d8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f20, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x247c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f28, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2520\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f30, 0xc\n\
    .global sAddr_740b08\n\
sAddr_740b08:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x25c4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f40, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2668\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f48, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x270c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f50, 0xc\n\
    .global sAddr_740b28\n\
sAddr_740b28:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x27b0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f60, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2854\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f68, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x28f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f70, 0xc\n\
    .global sAddr_740b48\n\
sAddr_740b48:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1dec\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f80, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1df4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f88, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1dfc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f90, 0x4\n\
    .4byte sBlob_73dbcc_7478a0 + 0x1df4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2f98, 0xc\n\
    .global sAddr_740b70\n\
sAddr_740b70:\n\
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
    .global sAddr_740ba8\n\
sAddr_740ba8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29a4\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2fe0, 0xc\n\
    .global sAddr_740bb8\n\
sAddr_740bb8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29b2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x2ff0, 0xc\n\
    .global sAddr_740bc8\n\
sAddr_740bc8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29c0\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3000, 0xc\n\
    .global sAddr_740bd8\n\
sAddr_740bd8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29ce\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3010, 0xc\n\
    .global sAddr_740be8\n\
sAddr_740be8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29dc\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3020, 0xc\n\
    .global sAddr_740bf8\n\
sAddr_740bf8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29ea\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3030, 0xc\n\
    .global sAddr_740c08\n\
sAddr_740c08:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x29f8\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3040, 0xc\n\
    .global sAddr_740c18\n\
sAddr_740c18:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a06\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3050, 0xc\n\
    .global sAddr_740c28\n\
sAddr_740c28:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a1a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3060, 0xc\n\
    .global sAddr_740c38\n\
sAddr_740c38:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a2e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3070, 0xc\n\
    .global sAddr_740c48\n\
sAddr_740c48:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a42\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3080, 0xc\n\
    .global sAddr_740c58\n\
sAddr_740c58:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a56\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3090, 0xc\n\
    .global sAddr_740c68\n\
sAddr_740c68:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a6a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30a0, 0xc\n\
    .global sAddr_740c78\n\
sAddr_740c78:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a7e\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30b0, 0xc\n\
    .global sAddr_740c88\n\
sAddr_740c88:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a86\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30c0, 0xc\n\
    .global sAddr_740c98\n\
sAddr_740c98:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2a9a\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30d0, 0xc\n\
    .global sAddr_740ca8\n\
sAddr_740ca8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2aae\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30e0, 0xc\n\
    .global sAddr_740cb8\n\
sAddr_740cb8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2ac2\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x30f0, 0xc\n\
    .global sAddr_740cc8\n\
sAddr_740cc8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2ad6\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3100, 0xc\n\
    .global sAddr_740cd8\n\
sAddr_740cd8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2aea\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3110, 0xc\n\
    .global sAddr_740ce8\n\
sAddr_740ce8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2afe\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3120, 0xc\n\
    .global sAddr_740cf8\n\
sAddr_740cf8:\n\
    .4byte sBlob_73dbcc_7478a0 + 0x2b0c\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3130, 0xc\n\
    .global sAddr_740d08\n\
sAddr_740d08:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x313c, 0x200\n\
    .global sAddr_740f08\n\
sAddr_740f08:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x333c, 0x32\n\
    .global sAddr_740f3a\n\
sAddr_740f3a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x336e, 0x2a\n\
    .global sAddr_740f64\n\
sAddr_740f64:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3398, 0x1e\n\
    .global sAddr_740f82\n\
sAddr_740f82:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x33b6, 0x42\n\
    .global sAddr_740fc4\n\
sAddr_740fc4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x33f8, 0x30\n\
    .global sAddr_740ff4\n\
sAddr_740ff4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3428, 0x42\n\
    .global sAddr_741036\n\
sAddr_741036:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x346a, 0x42\n\
    .global sAddr_741078\n\
sAddr_741078:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x34ac, 0x42\n\
    .global sAddr_7410ba\n\
sAddr_7410ba:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x34ee, 0x42\n\
    .global sAddr_7410fc\n\
sAddr_7410fc:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3530, 0x42\n\
    .global sAddr_74113e\n\
sAddr_74113e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3572, 0x42\n\
    .global sAddr_741180\n\
sAddr_741180:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x35b4, 0x16\n\
    .global sAddr_741196\n\
sAddr_741196:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x35ca, 0x8\n\
    .global sAddr_74119e\n\
sAddr_74119e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x35d2, 0x14\n\
    .global sAddr_7411b2\n\
sAddr_7411b2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x35e6, 0x28\n\
    .global sAddr_7411da\n\
sAddr_7411da:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x360e, 0x20\n\
    .global sAddr_7411fa\n\
sAddr_7411fa:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x362e, 0x14\n\
    .global sAddr_74120e\n\
sAddr_74120e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3642, 0x4a\n\
    .global sAddr_741258\n\
sAddr_741258:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x368c, 0x28\n\
    .global sAddr_741280\n\
sAddr_741280:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x36b4, 0x4e\n\
    .global sAddr_7412ce\n\
sAddr_7412ce:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3702, 0x1e\n\
    .global sAddr_7412ec\n\
sAddr_7412ec:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3720, 0x22\n\
    .global sAddr_74130e\n\
sAddr_74130e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3742, 0x26\n\
    .global sAddr_741334\n\
sAddr_741334:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3768, 0x18\n\
    .global sAddr_74134c\n\
sAddr_74134c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3780, 0x18\n\
    .global sAddr_741364\n\
sAddr_741364:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3798, 0x34\n\
    .global sAddr_741398\n\
sAddr_741398:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x37cc, 0x36\n\
    .global sAddr_7413ce\n\
sAddr_7413ce:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3802, 0x42\n\
    .global sAddr_741410\n\
sAddr_741410:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3844, 0x56\n\
    .global sAddr_741466\n\
sAddr_741466:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x389a, 0x36\n\
    .global sAddr_74149c\n\
sAddr_74149c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x38d0, 0x5a\n\
    .global sAddr_7414f6\n\
sAddr_7414f6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x392a, 0x5a\n\
    .global sAddr_741550\n\
sAddr_741550:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3984, 0x5a\n\
    .global sAddr_7415aa\n\
sAddr_7415aa:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x39de, 0x64\n\
    .global sAddr_74160e\n\
sAddr_74160e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3a42, 0x64\n\
    .global sAddr_741672\n\
sAddr_741672:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3aa6, 0x64\n\
    .global sAddr_7416d6\n\
sAddr_7416d6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b0a, 0x16\n\
    .global sAddr_7416ec\n\
sAddr_7416ec:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b20, 0x1e\n\
    .global sAddr_74170a\n\
sAddr_74170a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b3e, 0x14\n\
    .global sAddr_74171e\n\
sAddr_74171e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b52, 0x28\n\
    .global sAddr_741746\n\
sAddr_741746:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b7a, 0x20\n\
    .global sAddr_741766\n\
sAddr_741766:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3b9a, 0x14\n\
    .global sAddr_74177a\n\
sAddr_74177a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3bae, 0x4a\n\
    .global sAddr_7417c4\n\
sAddr_7417c4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3bf8, 0x2a\n\
    .global sAddr_7417ee\n\
sAddr_7417ee:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3c22, 0x26\n\
    .global sAddr_741814\n\
sAddr_741814:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3c48, 0x1c\n\
    .global sAddr_741830\n\
sAddr_741830:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3c64, 0x2a\n\
    .global sAddr_74185a\n\
sAddr_74185a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3c8e, 0x2a\n\
    .global sAddr_741884\n\
sAddr_741884:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3cb8, 0x30\n\
    .global sAddr_7418b4\n\
sAddr_7418b4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3ce8, 0x28\n\
    .global sAddr_7418dc\n\
sAddr_7418dc:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3d10, 0x3c\n\
    .global sAddr_741918\n\
sAddr_741918:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3d4c, 0x2e\n\
    .global sAddr_741946\n\
sAddr_741946:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3d7a, 0x38\n\
    .global sAddr_74197e\n\
sAddr_74197e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3db2, 0x56\n\
    .global sAddr_7419d4\n\
sAddr_7419d4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3e08, 0x40\n\
    .global sAddr_741a14\n\
sAddr_741a14:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3e48, 0x62\n\
    .global sAddr_741a76\n\
sAddr_741a76:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3eaa, 0x62\n\
    .global sAddr_741ad8\n\
sAddr_741ad8:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3f0c, 0x62\n\
    .global sAddr_741b3a\n\
sAddr_741b3a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3f6e, 0x5e\n\
    .global sAddr_741b98\n\
sAddr_741b98:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x3fcc, 0x5e\n\
    .global sAddr_741bf6\n\
sAddr_741bf6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x402a, 0x5e\n\
    .global sAddr_741c54\n\
sAddr_741c54:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4088, 0x1a\n\
    .global sAddr_741c6e\n\
sAddr_741c6e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x40a2, 0x22\n\
    .global sAddr_741c90\n\
sAddr_741c90:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x40c4, 0x22\n\
    .global sAddr_741cb2\n\
sAddr_741cb2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x40e6, 0x2a\n\
    .global sAddr_741cdc\n\
sAddr_741cdc:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4110, 0x2e\n\
    .global sAddr_741d0a\n\
sAddr_741d0a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x413e, 0x1e\n\
    .global sAddr_741d28\n\
sAddr_741d28:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x415c, 0x28\n\
    .global sAddr_741d50\n\
sAddr_741d50:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4184, 0x32\n\
    .global sAddr_741d82\n\
sAddr_741d82:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x41b6, 0x30\n\
    .global sAddr_741db2\n\
sAddr_741db2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x41e6, 0x24\n\
    .global sAddr_741dd6\n\
sAddr_741dd6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x420a, 0x1c\n\
    .global sAddr_741df2\n\
sAddr_741df2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4226, 0x32\n\
    .global sAddr_741e24\n\
sAddr_741e24:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4258, 0x24\n\
    .global sAddr_741e48\n\
sAddr_741e48:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x427c, 0x3a\n\
    .global sAddr_741e82\n\
sAddr_741e82:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x42b6, 0x42\n\
    .global sAddr_741ec4\n\
sAddr_741ec4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x42f8, 0x2a\n\
    .global sAddr_741eee\n\
sAddr_741eee:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4322, 0x44\n\
    .global sAddr_741f32\n\
sAddr_741f32:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4366, 0x4e\n\
    .global sAddr_741f80\n\
sAddr_741f80:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x43b4, 0x3e\n\
    .global sAddr_741fbe\n\
sAddr_741fbe:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x43f2, 0x6c\n\
    .global sAddr_74202a\n\
sAddr_74202a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x445e, 0x6c\n\
    .global sAddr_742096\n\
sAddr_742096:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x44ca, 0x6c\n\
    .global sAddr_742102\n\
sAddr_742102:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4536, 0x60\n\
    .global sAddr_742162\n\
sAddr_742162:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4596, 0x60\n\
    .global sAddr_7421c2\n\
sAddr_7421c2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x45f6, 0x60\n\
    .global sAddr_742222\n\
sAddr_742222:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4656, 0x22\n\
    .global sAddr_742244\n\
sAddr_742244:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4678, 0x2c\n\
    .global sAddr_742270\n\
sAddr_742270:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x46a4, 0x2c\n\
    .global sAddr_74229c\n\
sAddr_74229c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x46d0, 0x24\n\
    .global sAddr_7422c0\n\
sAddr_7422c0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x46f4, 0x32\n\
    .global sAddr_7422f2\n\
sAddr_7422f2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4726, 0x26\n\
    .global sAddr_742318\n\
sAddr_742318:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x474c, 0x36\n\
    .global sAddr_74234e\n\
sAddr_74234e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4782, 0x14\n\
    .global sAddr_742362\n\
sAddr_742362:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4796, 0x24\n\
    .global sAddr_742386\n\
sAddr_742386:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x47ba, 0x24\n\
    .global sAddr_7423aa\n\
sAddr_7423aa:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x47de, 0x2a\n\
    .global sAddr_7423d4\n\
sAddr_7423d4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4808, 0x22\n\
    .global sAddr_7423f6\n\
sAddr_7423f6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x482a, 0x2a\n\
    .global sAddr_742420\n\
sAddr_742420:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4854, 0x2c\n\
    .global sAddr_74244c\n\
sAddr_74244c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4880, 0x3a\n\
    .global sAddr_742486\n\
sAddr_742486:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x48ba, 0x3a\n\
    .global sAddr_7424c0\n\
sAddr_7424c0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x48f4, 0x3e\n\
    .global sAddr_7424fe\n\
sAddr_7424fe:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4932, 0x50\n\
    .global sAddr_74254e\n\
sAddr_74254e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4982, 0x38\n\
    .global sAddr_742586\n\
sAddr_742586:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x49ba, 0x6c\n\
    .global sAddr_7425f2\n\
sAddr_7425f2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4a26, 0x6c\n\
    .global sAddr_74265e\n\
sAddr_74265e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4a92, 0x6c\n\
    .global sAddr_7426ca\n\
sAddr_7426ca:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4afe, 0x64\n\
    .global sAddr_74272e\n\
sAddr_74272e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4b62, 0x64\n\
    .global sAddr_742792\n\
sAddr_742792:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4bc6, 0x64\n\
    .global sAddr_7427f6\n\
sAddr_7427f6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4c2a, 0x16\n\
    .global sAddr_74280c\n\
sAddr_74280c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4c40, 0x20\n\
    .global sAddr_74282c\n\
sAddr_74282c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4c60, 0x14\n\
    .global sAddr_742840\n\
sAddr_742840:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4c74, 0x2a\n\
    .global sAddr_74286a\n\
sAddr_74286a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4c9e, 0x34\n\
    .global sAddr_74289e\n\
sAddr_74289e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4cd2, 0x26\n\
    .global sAddr_7428c4\n\
sAddr_7428c4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4cf8, 0x46\n\
    .global sAddr_74290a\n\
sAddr_74290a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4d3e, 0x2e\n\
    .global sAddr_742938\n\
sAddr_742938:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4d6c, 0x2c\n\
    .global sAddr_742964\n\
sAddr_742964:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4d98, 0x1e\n\
    .global sAddr_742982\n\
sAddr_742982:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4db6, 0x2a\n\
    .global sAddr_7429ac\n\
sAddr_7429ac:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4de0, 0x30\n\
    .global sAddr_7429dc\n\
sAddr_7429dc:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4e10, 0x24\n\
    .global sAddr_742a00\n\
sAddr_742a00:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4e34, 0x28\n\
    .global sAddr_742a28\n\
sAddr_742a28:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4e5c, 0x3e\n\
    .global sAddr_742a66\n\
sAddr_742a66:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4e9a, 0x28\n\
    .global sAddr_742a8e\n\
sAddr_742a8e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4ec2, 0x32\n\
    .global sAddr_742ac0\n\
sAddr_742ac0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4ef4, 0x58\n\
    .global sAddr_742b18\n\
sAddr_742b18:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4f4c, 0x38\n\
    .global sAddr_742b50\n\
sAddr_742b50:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4f84, 0x5a\n\
    .global sAddr_742baa\n\
sAddr_742baa:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x4fde, 0x5a\n\
    .global sAddr_742c04\n\
sAddr_742c04:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5038, 0x5a\n\
    .global sAddr_742c5e\n\
sAddr_742c5e:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5092, 0x5c\n\
    .global sAddr_742cba\n\
sAddr_742cba:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x50ee, 0x5c\n\
    .global sAddr_742d16\n\
sAddr_742d16:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x514a, 0x5e\n\
    .global sAddr_742d74\n\
sAddr_742d74:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x51a8, 0x16\n\
    .global sAddr_742d8a\n\
sAddr_742d8a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x51be, 0x18\n\
    .global sAddr_742da2\n\
sAddr_742da2:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x51d6, 0x26\n\
    .global sAddr_742dc8\n\
sAddr_742dc8:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x51fc, 0x1c\n\
    .global sAddr_742de4\n\
sAddr_742de4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5218, 0x14\n\
    .global sAddr_742df8\n\
sAddr_742df8:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x522c, 0x20\n\
    .global sAddr_742e18\n\
sAddr_742e18:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x524c, 0x34\n\
    .global sAddr_742e4c\n\
sAddr_742e4c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5280, 0x30\n\
    .global sAddr_742e7c\n\
sAddr_742e7c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x52b0, 0x20\n\
    .global sAddr_742e9c\n\
sAddr_742e9c:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x52d0, 0x2a\n\
    .global sAddr_742ec6\n\
sAddr_742ec6:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x52fa, 0x28\n\
    .global sAddr_742eee\n\
sAddr_742eee:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5322, 0x26\n\
    .global sAddr_742f14\n\
sAddr_742f14:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5348, 0x2e\n\
    .global sAddr_742f42\n\
sAddr_742f42:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x5376, 0x24\n\
    .global sAddr_742f66\n\
sAddr_742f66:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x539a, 0x14\n\
    .global sAddr_742f7a\n\
sAddr_742f7a:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x53ae, 0x3a\n\
    .global sAddr_742fb4\n\
sAddr_742fb4:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x53e8, 0x412c\n\
    .global sAddr_7470e0\n\
sAddr_7470e0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x9514, 0x5c0\n\
    .global sAddr_7476a0\n\
sAddr_7476a0:\n\
    .incbin \"data/Blob_73dbcc_7478a0.bin\", 0x9ad4, 0x200\n\
    .popsection\n\
");
