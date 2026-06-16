#include "headers.hpp"

bool hasDuplicate(vector<int> &nums) {
  unordered_set<int> set;
  for (auto num : nums) {
    if (set.count(num))
      return true;
    set.insert(num);
  }
  return false;
}

#ifdef TESTING
#include <gtest/gtest.h>

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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

int main() {
  return 0;
}

#endif
