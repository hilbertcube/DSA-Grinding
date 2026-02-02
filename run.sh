#!/bin/bash

# Check for required argument
if [ -z "$1" ]; then
  echo "Usage: $0 <filename-without-extension>"
  exit 1
fi

p="$1"

# Ensure bin/ exists
mkdir -p bin

# Compile
g++ -Iinclude "neetcode-problems/$p.cpp" -o "bin/$p"
if [ $? -ne 0 ]; then
  echo "Compilation failed (g++ exited with code $?)"
  exit $?
fi

# Run
./bin/"$p"

# Make an executable: chmod +x run.sh
# Run: ./run.sh your_cpp_filename