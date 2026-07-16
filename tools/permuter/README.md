# decomp-permuter integration (electroplankton-decomp)

Wiring [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) to
this repo’s **mwccarm 1.2/sp2p3** toolchain — same idea as sm64ds-decomp
`tools/permuter/`.

- **Semantics** (correct C): you / agent / near-miss tip  
- **Codegen** (regalloc / order): permuter brute-force, free  

## One-time setup

```bash
# From decomp root (vendor/ is gitignored)
git clone https://github.com/simonlindholm/decomp-permuter vendor/decomp-permuter
python -m pip install toml pcpp pycparser capstone pyelftools
```

Need: unpacked ROM (`arm9/arm9.bin`), `tools/mwccarm/1.2/sp2p3/mwccarm.exe`.

On **Windows**, decomp-permuter may need small local patches (see sm64ds-decomp
`tools/permuter/README.md`). On **macOS/Linux**, bash `compile.sh` + wine/wibo
or native paths as you already use for `match.py`.

## Single function

```bash
# Seed from nearmiss tip DB
python tools/permuter/import_func.py --name func_02050928 --from-nearmiss

# Or seed from a file
python tools/permuter/import_func.py --name func_02050928 --base scratch/try.c

# Run (after import prints the path)
python vendor/decomp-permuter/permuter.py \
  vendor/decomp-permuter/work/func_02050928 --stop-on-zero -j 4

# Always re-verify before banking
python tools/match.py --c vendor/decomp-permuter/work/func_02050928/output.c \
  --func func_02050928 --addr 0x02050928 --size 0x... --version 1.2/sp2p3
```

## Batch from near-miss DB

```bash
# List candidates
python tools/permuter/batch.py --from-nearmiss --max-div 12 --limit 10 --dry-run

# Permute (oracle-check each win)
python tools/permuter/batch.py --from-nearmiss --max-div 8 --limit 5 --secs 120

# Optional: bank wins (still runs match.py first)
python tools/permuter/batch.py --from-nearmiss --max-div 6 --limit 3 --secs 180 --bank
```

Seeds JSONL (any source):

```json
{"name": "func_02050928", "c_source": "/* C */\n..."}
```

```bash
python tools/permuter/batch.py --seeds my_seeds.jsonl --secs 90
```

## Files (repo-owned glue)

| File | Role |
|------|------|
| `mwccarm_compile.sh` | Compile wrapper (same flags as `match.py`) |
| `cap_objdump.py` | Capstone scorer (no arm-none-eabi-objdump) |
| `import_func.py` | Build one permuter work dir from symbols + ROM + seed |
| `batch.py` | Sweep seeds / nearmiss tips |

`vendor/decomp-permuter/` is **not** committed (see root `.gitignore` `vendor/`).
