# Fusion platform

This fork of the [Metroid Fusion decompilation](https://github.com/metroidret/mf) is turning it into a base for ROM hacks, mods and new games built on the Fusion engine.

The `platform` branch is the one to use. `main` mirrors upstream untouched. Other branches hold self-contained fixes meant to go back upstream. See [PROGRESS.md](PROGRESS.md) for status and what's next.

## What you get on top of upstream

- **Editable assets.** `tools/fusiontool` turns graphics and palettes into PNG and JASC files and back. Untouched files rebuild byte-for-byte. See [tools/fusiontool/README.md](tools/fusiontool/README.md).
- **Assets can change size.** Arrays filled from data files take their size from the file, so an edited graphic that compresses differently still builds.
- **Rebuilds that notice edits.** Changing a header or anything in `data/` rebuilds exactly the files that use it.
- **Symbols instead of addresses.** Every enemy's AI function and most sprite graphics/palettes are referenced by name, so tables can be extended like normal code.
- **Shiftable ROM.** Hard-coded addresses have been replaced with symbols across code, data, music and graphics tables.
- **Automated play test.** `make smoke` boots the game in headless mGBA, starts a new file, plays the intro and checks Samus is in the first room.
- **More decompiled code**, starting with the gunship ending.

## Quick start

Follow the upstream setup in [README.md](README.md) (agbcc, binutils, your own `mf_us_baserom.gba`), then:

```sh
git checkout platform
python3 tools/extractor.py && make -j$(nproc) && make check   # must print "mf_us.gba: OK"
pip install pillow
PYTHONPATH=tools/fusiontool python3 -m fusiontool extract    # editable copies in assets/
```

Edit files in `assets/`, run `PYTHONPATH=tools/fusiontool python3 -m fusiontool build`, then `make`.

## Rules

- **Never commit ROMs or anything extracted from one.** `data/`, `assets/` and `*.gba` are git-ignored. Share mods as patches (BPS/IPS) against the player's own US ROM, or as source changes.
- **Keep `make check` passing** on `main`-based branches. Platform changes that intentionally change the ROM must be behind an option and off by default.
- **Clean room.** The upstream rule applies: don't consult Nintendo's code, leaked or otherwise. See [CONTRIBUTING.md](CONTRIBUTING.md).

## Moving things around

Everything after the ROM header can change size or move: code, data and assets. Inserting padding anywhere from the startup code onward, or growing an edited graphic, still plays from boot through the intro into the first room (`make shift-test`). The test doesn't yet cover saves, other sectors or late-game events, so report anything that breaks after a size change. See PROGRESS.md for details.

## Credits

Built on the work of the metroidret decompilation contributors, biospark (MAGE and the Fusion data maps), and the MAGConst and Metroid Construction communities.
