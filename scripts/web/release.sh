#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

scripts/web/generate.sh

emmake make config=release -j"$(nproc)" "$@"
