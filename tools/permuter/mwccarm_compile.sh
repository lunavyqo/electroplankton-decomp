#!/bin/bash
# decomp-permuter compile wrapper for electroplankton-decomp mwccarm.
# Invoked as:  mwccarm_compile.sh <C_FILE> -o <O_FILE>
# Same canonical compiler+flags as tools/match.py (1.2/sp2p3).
set -e
REPO="$(cd "$(dirname "$0")/../.." && pwd)"
CC="$REPO/tools/mwccarm/1.2/sp2p3/mwccarm.exe"
# Optional wibo (Linux/mac) if present
WIBO="$REPO/tools/bin/wibo"
if [ -f "$REPO/tools/mwccarm/license.dat" ]; then
  export LM_LICENSE_FILE="$REPO/tools/mwccarm/license.dat"
fi
C_FILE="$1"
O_FILE="$3"
LANG="c99"
if head -1 "$C_FILE" | grep -q '^//cpp'; then LANG="c++"; fi
FLAGS="-O4,p -enum int -lang $LANG -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
if [ -x "$WIBO" ] && [ "$(uname -s)" != "Windows_NT" ]; then
  # Many EP setups run mwccarm.exe via wibo on Unix
  if ! "$CC" $FLAGS -c -o "$O_FILE" "$C_FILE" 2>/dev/null; then
    "$WIBO" "$CC" $FLAGS -c -o "$O_FILE" "$C_FILE"
  fi
else
  "$CC" $FLAGS -c -o "$O_FILE" "$C_FILE"
fi
