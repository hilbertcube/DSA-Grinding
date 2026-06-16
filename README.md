# DSA Crunching

Personal repo for grinding LeetCode / NeetCode problems in C++.

## Running a problem

```bash
./run.sh 1_arrays-and-hashing/01_contains-duplicate
```

## Running tests

Tests live at the bottom of each problem file under `#ifdef TESTING`.

```bash
./run.sh 1_arrays-and-hashing/01_contains-duplicate --test
```

`gtest-all.o` is built once into `bin/` on first `--test` run and reused after that.

## Adding tests to a new problem file

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

## Project structure

```text
.
├── include/
│   └── headers.hpp       # common STL includes used across all problems
├── neetcode-problems/
│   └── 1_arrays-and-hashing/
│       ├── 01_contains-duplicate.cpp
│       └── ...
├── third_party/
│   └── googletest/       # cloned at depth 1, do not edit
└── run.sh
```

## Format

```
find ./problems -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
find ./include -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
```
