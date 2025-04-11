#!/bin/bash
set -xeu

# Get absolute path to the script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# List of source files (one per binary)
sources=("example_1.c" "example_2.c")

# Compile each source file to two binaries: debug and release
for src in "${sources[@]}"; do
  base="$(basename "$src" .c)"  # e.g., "example_1"

  src_path="$SCRIPT_DIR/$src"
  test_src_path="$SCRIPT_DIR/test_${src}"
  debug_out="$SCRIPT_DIR/test_${base}"
  release_out="$SCRIPT_DIR/$base"

  # Debug build
  gcc -DENABLE_MOCKS "$src_path" "$test_src_path" -o "$debug_out"

  # Normal build
  gcc "$src_path" -o "$release_out"
done
