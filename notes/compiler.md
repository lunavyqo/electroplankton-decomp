# Finding the right mwccarm for Electroplankton

Matching only works when we compile with the **same CodeWarrior ARM (mwccarm)
version + flags** the original developers used. Wrong version → almost nothing
matches even when the C is “right.”

## Current pin (locked in practice)

| Field | Value |
|-------|--------|
| **Version** | **mwccarm `1.2/sp2p3`** |
| **Flags** | `-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc` |
| Evidence | Multiple independent hand-matched functions pass `tools/match.py` with this version (early PRs + banked `src/`) |
| Confidence | **High** for 1.2/sp2p3 on arm9 game code |

Default in `tools/match.py`, PR validation, and Chaos Viewer `compiler` string:
`1.2/sp2p3`. Matching style (C not asm, attempt logging): [matching-style.md](matching-style.md).

`--sweep` remains available if a new module/region ever disagrees with the pin.

## What we already know

| Clue | Value | Source |
|------|--------|--------|
| Platform | Nintendo DS | retail cart |
| Game code | `ATIE` | `header.yaml` (local extract) |
| Title | ELE PLANKTON | header |
| ROM date stamp on dump file | 2006-01-10 | filesystem metadata (weak clue) |
| Overlays | none | `config.yaml` (`arm9_overlays: null`) |
| Code base (ARM9) | `0x02000000` | `arm9/arm9.yaml` |
| Functions found | ~1950 arm9 | `dsd init` → `config/arm9/symbols.txt` |
| Local mwccarm tree | full 1.2 + 2.0 (+ dsi) | `tools/mwccarm` → your SM64DS install |
| wibo (PE runner) | present | `tools/bin/wibo` |

No embedded `"Metrowerks"` / `"CodeWarrior"` / `"mwccarm"` ASCII banner showed up
in a quick `strings` pass of `arm9.bin`. That is normal; many titles strip that.

## How pinning actually works (the reliable method)

You do **not** need Nintendo’s internal docs. You use **empirical matching**:

### Step 1 — Pick “oracle” functions

Choose functions that are tiny and have only one sensible C shape, e.g.:

- `return constant;`
- `return this->field;` / simple getter
- `this->field = x;` / simple setter
- empty destructor / `return;` stub
- `memcpy`-like struct copy of a few words

`dsd` already named BIOS/SDK thunks (`SoftReset`, `CpuSet`, …). Prefer **game**
code (`func_02…`) for pinning; SDK wrappers may be hand-written asm or a
different toolchain.

### Step 2 — Write the obvious C

```c
int func_0200abcd(void) {
    return 0;
}
```

### Step 3 — Sweep compilers

```bash
python tools/match.py --c scratch.c --func func_0200abcd \
  --addr 0x0200abcd --size 0x10 --sweep
```

`match.py` tries every tree under `tools/mwccarm/` (1.2/* and 2.0/*). A true pin
is when **many independent functions** all match the **same** version+flags, not
just one lucky stub.

### Step 4 — Lock it

When confident, update:

1. `tools/match.py` → `CANONICAL` and `DEFAULT_FLAGS`
2. `tools/chaosviewer.config.json` → `compiler` string
3. This file with the evidence (N functions matched, addresses)

## Flags to try (same as most pret/NDS decomps)

Base line (provisional):

```
-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
```

Variants that sometimes matter:

- `-O4,p` vs `-O2,p` vs `-O1,p`
- `-lang c99` vs `-lang c++` (only if mangled names / objects appear)
- `-Cpp_exceptions off` for C++ games
- `-inline on/off`, `-ipa file` (later, for hard functions)

Electroplankton is more likely **C** than heavy C++, but that is not proven.

## Other weak signals (optional research)

1. **Release era** — 2005–2006 JP/US/EU ships often used CodeWarrior **1.2** series;
   some later ports used **2.0**. Sweep covers both.
2. **SDK version** — NitroSDK revision sometimes appears near build info; can narrow
   which CW was bundled with that SDK. Worth a deeper Ghidra pass later.
3. **Codegen fingerprints** — once a few functions match one version, check whether
   `mov r0, #0; bx lr` vs `movs` / stack frame shapes agree on larger funcs.
4. **Community RE** — if anyone has already noted the compiler for this title, use
   that as a prior, still verify with Step 3.

## What you need to do personally

- **Nothing mandatory right now.** The sweep can run on your machine with the
  mwccarm tree already wired.
- Optional later: if a version is missing from `tools/mwccarm/`, re-copy from the
  DS-decomp community mwccarm pack (not redistributable in git).

## What “done” looks like

A short table in this file, for example:

```
Pinned: mwccarm 1.2/sp2p3
Flags:  -O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
Evidence: 12/12 oracle functions matched (list addresses)
Date: YYYY-MM-DD
```

Until that exists, treat every match as **provisional** and re-check after the pin.

## Provisional pin (2026-07-12)

```
Pinned (provisional): mwccarm 1.2/sp2p3
Also matching:        1.2/base, 1.2/sp2 (same codegen on probes)
Flags:  -O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
Evidence (8/8 MATCH via tools/match.py):
  0x02001b44 size 0x28
  0x020078a4 size 0x80
  0x020092ac size 0x54
  0x0200c7ac size 0x40
  0x0201005c size 0x94
  0x02014bf0 size 0xfc
  0x0201c468 size 0x258
  0x02023bfc size 0x68
Date: 2026-07-12
```

`1.2/sp3`, `1.2/sp4`, and `2.0/*` diverged on the simple probe `func_02001b44`.
