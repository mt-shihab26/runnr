#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

command -v emcc >/dev/null || export PATH="$PATH:/usr/lib/emscripten"

premake5 --file=build.lua --os=emscripten gmake "$@"

emmake make config=release -j"$(nproc)" "$@"
