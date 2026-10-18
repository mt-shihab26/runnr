#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")/../.."

# Only our sources, vendor/ keeps its upstream formatting.
git ls-files -z --cached --others --exclude-standard 'src/*.cpp' 'src/*.hpp' | xargs -0 -r clang-format -i "$@"
