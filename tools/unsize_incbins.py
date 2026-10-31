#!/usr/bin/env python3
"""Let INCBIN arrays take their size from the file they include.

    const u32 sFoo[830] = INCBIN_U32("data/foo.gfx.lz");
 -> const u32 sFoo[] = INCBIN_U32("data/foo.gfx.lz");

and drop the size from matching `extern` declarations in include/. The
emitted bytes are identical (the ROM still matches); the point is that an
edited asset which compresses to a different size no longer breaks the
build. Symbols used with sizeof/ARRAY_SIZE outside their defining file
keep their size; pass them with --keep.

usage: unsize_incbins.py [--keep SYM ...]
"""
import re
import sys
from pathlib import Path

DEF = re.compile(r"(\b(?:static\s+)?(?:const\s+)?[us](?:8|16|32)\s+(\w+))\[[^\]\n]+\](\s*=\s*INCBIN_)")


def main() -> int:
    keep = set(sys.argv[sys.argv.index("--keep") + 1:]) if "--keep" in sys.argv else set()
    changed_syms = set()
    for f in sorted(Path("src").rglob("*.c")):
        text = f.read_text()

        def sub(m):
            if m.group(2) in keep:
                return m.group(0)
            changed_syms.add(m.group(2))
            return f"{m.group(1)}[]{m.group(3)}"

        new = DEF.sub(sub, text)
        if new != text:
            f.write_text(new)
    ext = re.compile(r"(extern\s+(?:const\s+)?[us](?:8|16|32)\s+(\w+))\[[^\]\n]+\];")
    for f in sorted(Path("include").rglob("*.h")):
        text = f.read_text()
        new = ext.sub(lambda m: f"{m.group(1)}[];" if m.group(2) in changed_syms else m.group(0), text)
        if new != text:
            f.write_text(new)
    print(f"unsized {len(changed_syms)} arrays")
    return 0


if __name__ == "__main__":
    sys.exit(main())
