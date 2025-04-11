#!/bin/bash

set -xeu

# Absolute paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"
SUBPROJECT_DIR="$SCRIPT_DIR/subprojects/c_minilib_mock"

# Cleanup
rm -rf "$BUILD_DIR"
rm -rf "$SUBPROJECT_DIR"

# Setup
if [ ! -d "$BUILD_DIR" ]; then
  meson setup "$BUILD_DIR" "$SCRIPT_DIR"
fi

# Build
ninja -C "$BUILD_DIR"
