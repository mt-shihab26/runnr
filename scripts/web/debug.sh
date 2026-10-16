#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

command -v emcc >/dev/null || export PATH="$PATH:/usr/lib/emscripten"

scripts/web/generate.sh

emmake make config=debug -j"$(nproc)" "$@"
