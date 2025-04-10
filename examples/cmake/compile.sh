#!/bin/bash
set -xeu

# Configuration
BUILD_DIR="build"

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure CMake project
cmake ..

# Build
cmake --build .
