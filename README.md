# DSA Grinding

C++ practice repo for data structures, algorithms, and interview-style problems.

## Layout

- `problems/`: categorized LeetCode-style solutions
- `company-prep/`: one-off interview prep problems
- `data-structures/`: custom implementations and tests
- `include/headers.hpp`: shared STL includes used by problem files
- `include/tree_helpers.hpp`: `TreeNode` plus tree build/compare helpers for `problems/7_trees/`
- `third_party/googletest/`: vendored GoogleTest
- `problems/x.sh`: compile-and-run helper for single problem files

## Prerequisites

- `g++` with C++17 support
- `bash`

## Run a Problem

The runner compiles a single file from `problems/` and runs its tests. Every run
is a test run — there is no separate mode and no flag.

```bash
./problems/x.sh 1_arrays-and-hashing/01_contains-duplicate
```

These forms also work:

```bash
./problems/x.sh problems/1_arrays-and-hashing/01_contains-duplicate
./problems/x.sh problems/1_arrays-and-hashing/01_contains-duplicate.cpp
```

Paths resolve against the repo root, so the script also runs from any working
directory (e.g. `../x.sh 7_trees/45_invert-binary-tree` from inside a category).

Compiled binaries are written to `bin/`.

On the first run, the repo builds `bin/gtest-all.o` and `bin/gtest_main.o` from
vendored GoogleTest and reuses them on later runs.

## Test File Pattern

GoogleTest's `gtest_main` supplies `main()`, so no problem file defines one. A
file is just the solution followed by its tests:

```cpp
#include "headers.hpp"
#include <gtest/gtest.h>

bool hasDuplicate(vector<int> &nums) {
    // ...
}

TEST(SuiteName, CaseName) {
    // ...
}
```

A file with no tests yet still compiles and runs; it reports `0 tests` and the
runner prints a reminder.

## Multiple Implementations

When a problem has more than one solution, name them `solve1`, `solve2`, ... and
let `selectImpl` (from `headers.hpp`) pick the one the tests run:

```cpp
TreeNode *invertTree1(TreeNode *root) { /* recursive */ }
TreeNode *invertTree2(TreeNode *root) { /* BFS */ }
TreeNode *invertTree3(TreeNode *root) { /* iterative DFS */ }

// Which implementation the tests run.
constexpr int IMPL = 1;
constexpr auto invertTree = selectImpl<IMPL>(invertTree1, invertTree2, invertTree3);
```

The tests keep calling `invertTree`, so switching is a one-digit edit. `IMPL` is
1-indexed to match the names, every variant is compiled whichever one is
selected so none of them rot, and an out-of-range `IMPL` is a compile error.

## Tree Problems

Files in `problems/7_trees/` include `tree_helpers.hpp` instead of `headers.hpp`,
which pulls in `headers.hpp` along with `TreeNode` and these helpers:

- `buildTreeFromLevelOrder({3, 9, 20, null, null, 15, 7})`: builds a tree from a
  LeetCode-style level-order list, where `null` marks a missing child
- `toPreorderString(root)`: preorder with `#` for null, so one string comparison
  covers both shape and values
- `toLevelOrder(root)`: level-order values, skipping missing children
- `findNode(root, value)`: first node holding `value`
- `deleteTree(root)`: frees the tree

## Formatting

```bash
find ./problems -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
find ./include -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
find ./data-structures -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i --style=file:./.clang-format
```
