#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

scripts/web/debug.sh

# the page fetches runnr.wasm and runnr.data, so it has to be served over http, not opened as a file
exec emrun .build/emscripten-wasm32/bin/debug/runnr.html "$@"
