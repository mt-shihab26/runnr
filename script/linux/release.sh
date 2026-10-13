#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

script/linux/generate.sh

make config=release -j"$(nproc)" "$@"
