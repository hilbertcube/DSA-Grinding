#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <path-without-extension>"
  exit 1
fi

# Resolve paths against the repo root, so the script works from any directory.
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(dirname "$script_dir")"

p="$1"
source_path="${p#problems/}"
source_path="${source_path%.cpp}"
source_file="$repo_root/problems/$source_path.cpp"
GTEST_DIR="$repo_root/third_party/googletest/googletest"
INCLUDES="-I $repo_root/include -I $GTEST_DIR/include"
CXXFLAGS="-std=c++17"
BIN_DIR="$repo_root/bin"
output="$BIN_DIR/$(basename "$source_path")"

if [ "$2" = "--test" ]; then
  echo "Note: --test is no longer needed, every run is a test run."
fi

if [ ! -f "$source_file" ]; then
  echo "No such file: $source_file"
  exit 1
fi

mkdir -p "$BIN_DIR"

# Build the gtest objects once, reuse after that. gtest_main supplies main(),
# so problem files contain nothing but the solution and its tests.
if [ ! -f "$BIN_DIR/gtest-all.o" ] || [ ! -f "$BIN_DIR/gtest_main.o" ]; then
  echo "Building gtest..."
  g++ $CXXFLAGS -pthread -I "$GTEST_DIR/include" -I "$GTEST_DIR" \
    -c "$GTEST_DIR/src/gtest-all.cc" -o "$BIN_DIR/gtest-all.o" || exit 1
  g++ $CXXFLAGS -pthread -I "$GTEST_DIR/include" -I "$GTEST_DIR" \
    -c "$GTEST_DIR/src/gtest_main.cc" -o "$BIN_DIR/gtest_main.o" || exit 1
fi

if ! g++ $CXXFLAGS -pthread $INCLUDES "$source_file" \
  "$BIN_DIR/gtest-all.o" "$BIN_DIR/gtest_main.o" -o "$output"; then
  echo "Compilation failed"
  exit 1
fi

log="$(mktemp)"
trap 'rm -f "$log"' EXIT

set -o pipefail
"$output" 2>&1 | tee "$log"
status=$?

# A file with no tests still links and exits 0, so call that out explicitly.
if grep -q "Running 0 tests" "$log"; then
  echo
  echo "Note: $source_path defines no tests yet."
fi

exit $status

# Make executable: chmod +x problems/x.sh
# Run: ./problems/x.sh 1_arrays-and-hashing/01_contains-duplicate
