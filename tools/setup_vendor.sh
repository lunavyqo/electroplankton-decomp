#!/bin/bash
# One-time local deps for permuter + m2c (gitignored under vendor/).
# Prefer copying from a sibling SM64DS checkout if present; else shallow clone.
set -euo pipefail
REPO="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO"
mkdir -p vendor

SM64_CANDIDATES=(
  "$REPO/../SM64DS"
  "$REPO/../../SM64DS"
  "$(dirname "$REPO")/SM64DS"
)

find_sm64() {
  for d in "${SM64_CANDIDATES[@]}"; do
    if [ -d "$d/vendor/decomp-permuter" ]; then
      echo "$d"
      return 0
    fi
  done
  return 1
}

install_one() {
  local name="$1" url="$2"
  if [ -e "vendor/$name/permuter.py" ] || [ -e "vendor/$name/m2c.py" ]; then
    echo "ok  vendor/$name (already present)"
    return 0
  fi
  if SM64="$(find_sm64 2>/dev/null)"; then
    echo "copy vendor/$name from $SM64"
    rm -rf "vendor/$name"
    cp -R "$SM64/vendor/$name" "vendor/$name"
  else
    echo "clone $url -> vendor/$name"
    git clone --depth 1 "$url" "vendor/$name"
  fi
  echo "ok  vendor/$name"
}

install_one decomp-permuter https://github.com/simonlindholm/decomp-permuter
install_one m2c https://github.com/matt-kempster/m2c

python3 -m pip install -q toml pcpp pycparser capstone pyelftools 2>/dev/null || true
echo "done. Try: python3 tools/permuter/import_func.py --name <func> --base seed.c"
