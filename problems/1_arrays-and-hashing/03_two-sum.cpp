#include "headers.hpp"

// brute force
vector<int> twoSum1(const vector<int> &nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target)
        return {i, j};
    }
  }
  return {};
}

// hash map
vector<int> twoSum2(const vector<int> &nums, int target) {
  unordered_map<int, int> seen;

  for (int i{0}; i < nums.size(); ++i) {
    int need = target - nums[i];
    if(seen.count(need)) 
      return {seen[need], i};
    seen[nums[i]] = i;
  }
  return {};
}

vector<int> twoSum(const vector<int> &nums, int target)
{
  return twoSum1(nums, target);
}

#ifdef TESTING
#include <gtest/gtest.h>

TEST(TwoSum, BasicCase) {
  vector<int> nums = {2, 7, 11, 15};
  EXPECT_EQ(twoSum(nums, 9), (vector<int>{0, 1}));
}

TEST(TwoSum, NegativeNumbers) {
  vector<int> nums = {-1, -2, -3, -4, -5};
  EXPECT_EQ(twoSum(nums, -8), (vector<int>{2, 4}));
}

TEST(TwoSum, LargerArray) {
  vector<int> nums = {1, 3, 4, 2};
  EXPECT_EQ(twoSum(nums, 6), (vector<int>{2, 3}));
}

TEST(TwoSum, AnswerAtEnd) {
  vector<int> nums = {3, 2, 4};
  EXPECT_EQ(twoSum(nums, 6), (vector<int>{1, 2}));
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
