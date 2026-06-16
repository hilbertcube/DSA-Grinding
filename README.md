# DSA Grinding

C++ practice repo for data structures, algorithms, and interview-style problems.

## Layout

- `problems/`: categorized LeetCode-style solutions
- `company-prep/`: one-off interview prep problems
- `data-structures/`: custom implementations and tests
- `include/headers.hpp`: shared STL includes used by problem files
- `third_party/googletest/`: vendored GoogleTest
- `x.sh`: compile-and-run helper for single problem files

## Prerequisites

- `g++` with C++17 support
- `bash`

## Run a Problem

The runner compiles a single file from `problems/` and executes the result.

```bash
./x.sh 1_arrays-and-hashing/01_contains-duplicate
```

These forms also work:

```bash
./x.sh problems/1_arrays-and-hashing/01_contains-duplicate
./x.sh problems/1_arrays-and-hashing/01_contains-duplicate.cpp
```

Compiled binaries are written to `bin/`.

## Run Tests

Most problem tests live at the bottom of each file under `#ifdef TESTING`.

```bash
./x.sh 1_arrays-and-hashing/01_contains-duplicate --test
```

On the first test run, the repo builds `bin/gtest-all.o` from vendored GoogleTest and reuses it on later runs.

## Test File Pattern

Use this structure inside a problem file:

```cpp
#ifdef TESTING
#include <gtest/gtest.h>

TEST(SuiteName, CaseName) {
    // ...
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

int main() {
    return 0;
}

#endif
```

## Formatting

```bash
find ./problems -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
find ./include -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
find ./data-structures -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
```
