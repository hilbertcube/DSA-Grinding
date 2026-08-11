#include "headers.h"
#include <gtest/gtest.h>

bool hasDuplicate1(vector<int> &nums) {
  unordered_set<int> set;
  for (auto num : nums) {
    if (set.count(num))
      return true;
    set.insert(num);
  }
  return false;
}

bool hasDuplicate2(vector<int> &num) {
  vector<int> freq;

  return false;
}

// Which implementation the tests run.
SELECT_IMPL(1, hasDuplicate, hasDuplicate1, hasDuplicate2);

TEST(ContainsDuplicate, HasDuplicate) {
  vector<int> nums = {1, 2, 3, 1};
  EXPECT_TRUE(hasDuplicate(nums));
}

TEST(ContainsDuplicate, NoDuplicate) {
  vector<int> nums = {1, 2, 3, 4};
  EXPECT_FALSE(hasDuplicate(nums));
}

TEST(ContainsDuplicate, SingleElement) {
  vector<int> nums = {7};
  EXPECT_FALSE(hasDuplicate(nums));
}

TEST(ContainsDuplicate, Empty) {
  vector<int> nums = {};
  EXPECT_FALSE(hasDuplicate(nums));
}

TEST(ContainsDuplicate, AllSame) {
  vector<int> nums = {5, 5, 5, 5};
  EXPECT_TRUE(hasDuplicate(nums));
}
