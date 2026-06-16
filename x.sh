#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <path-without-extension> [--test]"
  exit 1
fi

p="$1"
source_path="${p#problems/}"
source_path="${source_path%.cpp}"
source_file="problems/$source_path.cpp"
GTEST_DIR="third_party/googletest/googletest"
INCLUDES="-I include"
CXXFLAGS="-std=c++17"

mkdir -p bin

if [ "$2" = "--test" ]; then
  # Build gtest-all.o once, reuse after that
  if [ ! -f "bin/gtest-all.o" ]; then
    echo "Building gtest..."
    g++ $CXXFLAGS -pthread -I "$GTEST_DIR/include" -I "$GTEST_DIR" \
      -c "$GTEST_DIR/src/gtest-all.cc" -o bin/gtest-all.o
  fi

  g++ $CXXFLAGS -pthread $INCLUDES -I "$GTEST_DIR/include" \
    -DTESTING "$source_file" bin/gtest-all.o -o "bin/$(basename "$source_path")"
else
  g++ $CXXFLAGS $INCLUDES "$source_file" -o "bin/$(basename "$source_path")"
fi

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi

./bin/$(basename "$source_path")

# Make executable: chmod +x x.sh
# Run:  ./x.sh 1_arrays-and-hashing/01_contains-duplicate
# Test: ./x.sh 1_arrays-and-hashing/01_contains-duplicate --test
