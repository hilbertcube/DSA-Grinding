// Starting point for a new problem. Copy into problems/<category>/ and edit.
//
//   ./problems/x.sh 1_arrays-and-hashing/01_contains-duplicate
//
// What this file demonstrates:
//
//   - No main(). GoogleTest's gtest_main supplies it, so a problem file is
//     just the solution followed by its tests.
//   - Several solutions to one problem: name them solve1, solve2, ... and let
//     SELECT_IMPL pick the live one. With only one solution, name it plainly
//     and delete the SELECT_IMPL block entirely.
//   - Tree problems include "tree_helpers.h" instead of "headers.h"; it
//     pulls in headers.h plus TreeNode and buildTreeFromLevelOrder().

#include "headers.h"
#include <gtest/gtest.h>

/*
Return how many values in nums are even.

Example 1:

Input: nums = [1,2,3,4]

Output: 2

Example 2:

Input: nums = []

Output: 0
*/

// counting loop
int countEvens1(const vector<int> &nums) {
  int count = 0;
  for (int n : nums) {
    if (n % 2 == 0)
      ++count;
  }
  return count;
}

// same thing via <algorithm>
int countEvens2(const vector<int> &nums) {
  return static_cast<int>(count_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; }));
}

// Which implementation the tests run.
constexpr int IMPL = 1;
SELECT_IMPL(IMPL, countEvens, countEvens1, countEvens2);

TEST(CountEvens, CountsEvenValues) {
  EXPECT_EQ(countEvens({1, 2, 3, 4}), 2);
}

TEST(CountEvens, EmptyInput) {
  EXPECT_EQ(countEvens({}), 0);
}

TEST(CountEvens, NoEvens) {
  EXPECT_EQ(countEvens({1, 3, 5}), 0);
}

TEST(CountEvens, ZeroAndNegativesAreEven) {
  EXPECT_EQ(countEvens({-2, -1, 0}), 2);
}
