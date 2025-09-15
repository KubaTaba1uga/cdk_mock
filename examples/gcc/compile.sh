#!/bin/bash
set -xeu

# Get absolute path to the script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cd $SCRIPT_DIR
rm -rf build
mkdir -p build
cd build


# List of source files (one per binary)
sources=("example_1.c" "example_2.c" "example_3.c")

for src in "${sources[@]}"; do
  idx="$(basename "$src" .c | sed 's/example_//g')"  # e.g., "1"
  src_path="$SCRIPT_DIR/$src"
  lib_path="$SCRIPT_DIR/lib_$idx.c"
  test_src_path="$SCRIPT_DIR/mock_$idx.c"

  if [ ! -f "$lib_path" ]; then
    # Normal build
    gcc -I../../../include "$src_path" -o "example_$idx"

    # Mocked build
    gcc -I../../../include -DCDK_MOCK_ENABLE "$src_path" "$test_src_path" -o "example_${idx}_test"
      
  else
    # Normal build
    gcc -I../../../include "$src_path" "$lib_path" -o "example_$idx"

    # Mocked build
    gcc -I../../../include -DCDK_MOCK_ENABLE -Wl,--wrap=add "$src_path" "$lib_path" "$test_src_path" -o "example_${idx}_test"
  fi
    
done
