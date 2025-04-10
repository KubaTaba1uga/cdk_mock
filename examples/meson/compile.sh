#!/bin/bash

set -xeu

# Configuration
BUILD_DIR="build"

rm -rf $BUILD_DIR

# Setup (only if build dir doesn't exist)
if [ ! -d "$BUILD_DIR" ]; then
  meson setup "$BUILD_DIR"
fi

# Build
ninja -C "$BUILD_DIR"
