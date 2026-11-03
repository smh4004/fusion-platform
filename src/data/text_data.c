#include "macros.h"

const u8 sCharactersGfx[] = INCBIN_U8("data/text_characters.gfx");

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_6b2fac_72eee0[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_6b2fac_72eee0\n\
sBlob_6b2fac_72eee0:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x0, 0x6b260\n\
    .global sAddr_71e20c\n\
sAddr_71e20c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6b260, 0x2d8\n\
    .global sAddr_71e4e4\n\
sAddr_71e4e4:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6b538, 0x19a\n\
    .global sAddr_71e67e\n\
sAddr_71e67e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6b6d2, 0x196\n\
    .global sAddr_71e814\n\
sAddr_71e814:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6b868, 0x1a2\n\
    .global sAddr_71e9b6\n\
sAddr_71e9b6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ba0a, 0x17e\n\
    .global sAddr_71eb34\n\
sAddr_71eb34:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6bb88, 0x178\n\
    .global sAddr_71ecac\n\
sAddr_71ecac:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6bd00, 0x316\n\
    .global sAddr_71efc2\n\
sAddr_71efc2:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c016, 0x4d6\n\
    .global sAddr_71f498\n\
sAddr_71f498:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c4ec, 0x94\n\
    .global sAddr_71f52c\n\
sAddr_71f52c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c580, 0x40\n\
    .global sAddr_71f56c\n\
sAddr_71f56c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c5c0, 0x90\n\
    .global sAddr_71f5fc\n\
sAddr_71f5fc:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c650, 0x5a\n\
    .global sAddr_71f656\n\
sAddr_71f656:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c6aa, 0xc4\n\
    .global sAddr_71f71a\n\
sAddr_71f71a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c76e, 0xb2\n\
    .global sAddr_71f7cc\n\
sAddr_71f7cc:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c820, 0xca\n\
    .global sAddr_71f896\n\
sAddr_71f896:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c8ea, 0xf4\n\
    .global sAddr_71f98a\n\
sAddr_71f98a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6c9de, 0xa8\n\
    .global sAddr_71fa32\n\
sAddr_71fa32:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ca86, 0x60\n\
    .global sAddr_71fa92\n\
sAddr_71fa92:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6cae6, 0x42\n\
    .global sAddr_71fad4\n\
sAddr_71fad4:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6cb28, 0x61a\n\
    .global sAddr_7200ee\n\
sAddr_7200ee:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6d142, 0x222\n\
    .global sAddr_720310\n\
sAddr_720310:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6d364, 0x218\n\
    .global sAddr_720528\n\
sAddr_720528:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6d57c, 0x220\n\
    .global sAddr_720748\n\
sAddr_720748:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6d79c, 0x202\n\
    .global sAddr_72094a\n\
sAddr_72094a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6d99e, 0x200\n\
    .global sAddr_720b4a\n\
sAddr_720b4a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6db9e, 0x5cc\n\
    .global sAddr_721116\n\
sAddr_721116:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6e16a, 0x818\n\
    .global sAddr_72192e\n\
sAddr_72192e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6e982, 0xe4\n\
    .global sAddr_721a12\n\
sAddr_721a12:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ea66, 0xa4\n\
    .global sAddr_721ab6\n\
sAddr_721ab6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6eb0a, 0x172\n\
    .global sAddr_721c28\n\
sAddr_721c28:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ec7c, 0xea\n\
    .global sAddr_721d12\n\
sAddr_721d12:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ed66, 0x20e\n\
    .global sAddr_721f20\n\
sAddr_721f20:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6ef74, 0x148\n\
    .global sAddr_722068\n\
sAddr_722068:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f0bc, 0x1d0\n\
    .global sAddr_722238\n\
sAddr_722238:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f28c, 0x200\n\
    .global sAddr_722438\n\
sAddr_722438:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f48c, 0x118\n\
    .global sAddr_722550\n\
sAddr_722550:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f5a4, 0xa8\n\
    .global sAddr_7225f8\n\
sAddr_7225f8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f64c, 0xa8\n\
    .global sAddr_7226a0\n\
sAddr_7226a0:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x6f6f4, 0x976\n\
    .global sAddr_723016\n\
sAddr_723016:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7006a, 0x30e\n\
    .global sAddr_723324\n\
sAddr_723324:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x70378, 0x300\n\
    .global sAddr_723624\n\
sAddr_723624:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x70678, 0x334\n\
    .global sAddr_723958\n\
sAddr_723958:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x709ac, 0x28a\n\
    .global sAddr_723be2\n\
sAddr_723be2:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x70c36, 0x262\n\
    .global sAddr_723e44\n\
sAddr_723e44:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x70e98, 0x91a\n\
    .global sAddr_72475e\n\
sAddr_72475e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x717b2, 0xb68\n\
    .global sAddr_7252c6\n\
sAddr_7252c6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7231a, 0x14c\n\
    .global sAddr_725412\n\
sAddr_725412:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x72466, 0xd8\n\
    .global sAddr_7254ea\n\
sAddr_7254ea:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7253e, 0x1ee\n\
    .global sAddr_7256d8\n\
sAddr_7256d8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7272c, 0x146\n\
    .global sAddr_72581e\n\
sAddr_72581e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x72872, 0x242\n\
    .global sAddr_725a60\n\
sAddr_725a60:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x72ab4, 0x134\n\
    .global sAddr_725b94\n\
sAddr_725b94:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x72be8, 0x218\n\
    .global sAddr_725dac\n\
sAddr_725dac:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x72e00, 0x290\n\
    .global sAddr_72603c\n\
sAddr_72603c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x73090, 0x18a\n\
    .global sAddr_7261c6\n\
sAddr_7261c6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7321a, 0xe4\n\
    .global sAddr_7262aa\n\
sAddr_7262aa:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x732fe, 0xe2\n\
    .global sAddr_72638c\n\
sAddr_72638c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x733e0, 0x71a\n\
    .global sAddr_726aa6\n\
sAddr_726aa6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x73afa, 0x258\n\
    .global sAddr_726cfe\n\
sAddr_726cfe:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x73d52, 0x206\n\
    .global sAddr_726f04\n\
sAddr_726f04:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x73f58, 0x202\n\
    .global sAddr_727106\n\
sAddr_727106:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7415a, 0x20e\n\
    .global sAddr_727314\n\
sAddr_727314:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x74368, 0x20e\n\
    .global sAddr_727522\n\
sAddr_727522:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x74576, 0x5e6\n\
    .global sAddr_727b08\n\
sAddr_727b08:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x74b5c, 0x7b4\n\
    .global sAddr_7282bc\n\
sAddr_7282bc:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x75310, 0xea\n\
    .global sAddr_7283a6\n\
sAddr_7283a6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x753fa, 0xc0\n\
    .global sAddr_728466\n\
sAddr_728466:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x754ba, 0x1a2\n\
    .global sAddr_728608\n\
sAddr_728608:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7565c, 0xe0\n\
    .global sAddr_7286e8\n\
sAddr_7286e8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7573c, 0x1d2\n\
    .global sAddr_7288ba\n\
sAddr_7288ba:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7590e, 0x158\n\
    .global sAddr_728a12\n\
sAddr_728a12:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x75a66, 0x1ea\n\
    .global sAddr_728bfc\n\
sAddr_728bfc:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x75c50, 0x24e\n\
    .global sAddr_728e4a\n\
sAddr_728e4a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x75e9e, 0x14c\n\
    .global sAddr_728f96\n\
sAddr_728f96:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x75fea, 0xb8\n\
    .global sAddr_72904e\n\
sAddr_72904e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x760a2, 0xae\n\
    .global sAddr_7290fc\n\
sAddr_7290fc:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x76150, 0x696\n\
    .global sAddr_729792\n\
sAddr_729792:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x767e6, 0x2dc\n\
    .global sAddr_729a6e\n\
sAddr_729a6e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x76ac2, 0x216\n\
    .global sAddr_729c84\n\
sAddr_729c84:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x76cd8, 0x2a0\n\
    .global sAddr_729f24\n\
sAddr_729f24:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x76f78, 0x200\n\
    .global sAddr_72a124\n\
sAddr_72a124:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x77178, 0x20c\n\
    .global sAddr_72a330\n\
sAddr_72a330:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x77384, 0x5c6\n\
    .global sAddr_72a8f6\n\
sAddr_72a8f6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7794a, 0x84c\n\
    .global sAddr_72b142\n\
sAddr_72b142:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78196, 0x112\n\
    .global sAddr_72b254\n\
sAddr_72b254:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x782a8, 0x74\n\
    .global sAddr_72b2c8\n\
sAddr_72b2c8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7831c, 0x17e\n\
    .global sAddr_72b446\n\
sAddr_72b446:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7849a, 0x128\n\
    .global sAddr_72b56e\n\
sAddr_72b56e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x785c2, 0x238\n\
    .global sAddr_72b7a6\n\
sAddr_72b7a6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x787fa, 0x140\n\
    .global sAddr_72b8e6\n\
sAddr_72b8e6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7893a, 0x1ce\n\
    .global sAddr_72bab4\n\
sAddr_72bab4:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78b08, 0x20e\n\
    .global sAddr_72bcc2\n\
sAddr_72bcc2:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78d16, 0xf6\n\
    .global sAddr_72bdb8\n\
sAddr_72bdb8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78e0c, 0x92\n\
    .global sAddr_72be4a\n\
sAddr_72be4a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78e9e, 0xae\n\
    .global sAddr_72bef8\n\
sAddr_72bef8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x78f4c, 0x7a4\n\
    .global sAddr_72c69c\n\
sAddr_72c69c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x796f0, 0x256\n\
    .global sAddr_72c8f2\n\
sAddr_72c8f2:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x79946, 0x210\n\
    .global sAddr_72cb02\n\
sAddr_72cb02:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x79b56, 0x290\n\
    .global sAddr_72cd92\n\
sAddr_72cd92:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x79de6, 0x270\n\
    .global sAddr_72d002\n\
sAddr_72d002:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7a056, 0x210\n\
    .global sAddr_72d212\n\
sAddr_72d212:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7a266, 0x60c\n\
    .global sAddr_72d81e\n\
sAddr_72d81e:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7a872, 0x89a\n\
    .global sAddr_72e0b8\n\
sAddr_72e0b8:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b10c, 0xfe\n\
    .global sAddr_72e1b6\n\
sAddr_72e1b6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b20a, 0x6a\n\
    .global sAddr_72e220\n\
sAddr_72e220:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b274, 0x1b2\n\
    .global sAddr_72e3d2\n\
sAddr_72e3d2:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b426, 0x118\n\
    .global sAddr_72e4ea\n\
sAddr_72e4ea:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b53e, 0x220\n\
    .global sAddr_72e70a\n\
sAddr_72e70a:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b75e, 0x13e\n\
    .global sAddr_72e848\n\
sAddr_72e848:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7b89c, 0x1d8\n\
    .global sAddr_72ea20\n\
sAddr_72ea20:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7ba74, 0x1d6\n\
    .global sAddr_72ebf6\n\
sAddr_72ebf6:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7bc4a, 0x15a\n\
    .global sAddr_72ed50\n\
sAddr_72ed50:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7bda4, 0xcc\n\
    .global sAddr_72ee1c\n\
sAddr_72ee1c:\n\
    .incbin \"data/Blob_6b2fac_72eee0.bin\", 0x7be70, 0xc4\n\
    .popsection\n\
");

