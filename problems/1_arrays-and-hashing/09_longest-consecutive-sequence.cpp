#include "headers.hpp"

int longestConsecutive(vector<int> &nums) {
  if (nums.empty())
    return 0;
  sort(nums.begin(), nums.end());

  int curr_len = 1;
  int max_len = 1;

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1])
      continue;
    else if (nums[i] - nums[i - 1] == 1)
      curr_len++;
    else
      curr_len = 1;
    max_len = max(curr_len, max_len);
  }
  return max_len;
}

int main(int argc, char *argv[]) {

  return 0;
}