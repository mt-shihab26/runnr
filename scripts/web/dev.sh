#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

command -v emcc >/dev/null || export PATH="$PATH:/usr/lib/emscripten"

scripts/web/debug.sh

emrun .build/web-wasm32/bin/debug/runnr.html "$@" &
server=$!

trap 'kill "$server" 2>/dev/null' EXIT
trap 'exit 130' INT TERM HUP

wait "$server"
