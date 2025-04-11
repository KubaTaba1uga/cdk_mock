#!/bin/bash
set -xeu

# List of source files (one per binary)
sources=("example_1.c" "example_2.c")

# Compile each source file to two binaries: debug and release
for src in "${sources[@]}"; do
  base="$(basename "$src" .c)"  # e.g., "example_1"

  # Debug build
  gcc -DDEBUG "$src" "test_${src}" -o "test_${base}"

  # Normal build
  gcc "$src" -o "$base"
done
