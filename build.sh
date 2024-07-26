#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Remove the build directory if it exists
rm -rf build

# Create a new build directory
mkdir -p build

# Navigate to the build directory
cd build

# Configure the project with coverage enabled
cmake .. -DENABLE_COVERAGE=ON

# Build the project
cmake --build .

# Run the tests
ctest

# Generate the coverage report
cmake --build . --target coverage
