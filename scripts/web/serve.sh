#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

scripts/web/release.sh

bunx http-server .build/web-wasm32/bin/release -p 8080 -o runnr.html "$@"
