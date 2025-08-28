#!/bin/bash
set -xeu


# Get absolute path to the script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cd $SCRIPT_DIR
rm -rf build
mkdir -p build
cd build


# List of source files (one per binary)
sources=("example_1.c" "example_2.c")

for src in "${sources[@]}"; do
  idx="$(basename "$src" .c | sed 's/example_//g')"  # e.g., "1"
  src_path="$SCRIPT_DIR/$src"
  test_src_path="$SCRIPT_DIR/mock_$idx.c"

  # Normal build
  gcc -I../../../include "$src_path" -o "example_$idx"

  # Mocked build
  gcc -I../../../include -DCDK_MOCK_ENABLE "$src_path" "$test_src_path" -o "example_${idx}_test"
done
