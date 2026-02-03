#include "headers.hpp"

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

*/

int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());

    int curr_len = 1;
    int max_len = 1;

    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i-1])
            continue;
        else if(nums[i] - nums[i-1] == 1)
            curr_len++;
        else
            curr_len = 1;
        max_len = max(curr_len, max_len);
    }
    return max_len;
}

int main() {


}