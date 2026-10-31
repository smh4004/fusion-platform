#!/bin/sh
# Shiftability check: insert padding before chosen objects in the ROM, build
# (the ROM will no longer match), and run the new-game smoke test on each.
#
#   tools/smoketest/shift_test.sh [padding] [object ...]
#
# Default padding is 0x100 bytes. Each object is a linker.ld entry such as
# "src/data/rooms_data.o(.rodata)". linker.ld is restored afterwards.
set -u
PAD=${1:-0x100}
[ $# -gt 0 ] && shift
POINTS="$*"
[ -z "$POINTS" ] && POINTS="src/data/generic_data.o(.rodata) src/data/rooms_data.o(.rodata) src/sprites_AI/gunship_end.o(.text) src/data/intro_data.o(.rodata)"

ROOT=$(cd "$(dirname "$0")/../.." && pwd)
cd "$ROOT" || exit 2
cp linker.ld linker.ld.shift-backup
trap 'mv -f linker.ld.shift-backup linker.ld; touch linker.ld; make -s >/dev/null 2>&1' EXIT

status=0
for point in $POINTS; do
    cp linker.ld.shift-backup linker.ld
    if ! python3 - "$point" "$PAD" <<'PY'
import sys
point, pad = sys.argv[1], sys.argv[2]
lines = open("linker.ld").read().split("\n")
for i, l in enumerate(lines):
    if l.strip() == point + ";":
        indent = l[: len(l) - len(l.lstrip())]
        lines.insert(i, f"{indent}. = . + {pad};")
        open("linker.ld", "w").write("\n".join(lines))
        sys.exit(0)
sys.exit(1)
PY
    then
        echo "SKIP $point (not in linker.ld)"
        continue
    fi
    if ! make -s -j"$(nproc)" >/dev/null 2>&1; then
        echo "BUILD FAIL  $point"
        status=1
        continue
    fi
    name=$(printf '%s' "$point" | tr '/().' '____')
    if python3 tools/smoketest/run.py --out "smoke_out/shift_$name" >"smoke_out/shift_$name.log" 2>&1; then
        echo "PASS  +$PAD before $point"
    else
        echo "FAIL  +$PAD before $point  ($(grep -m1 FAIL "smoke_out/shift_$name.log"))"
        status=1
    fi
done
exit $status
