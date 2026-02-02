#include "headers.hpp"

/*
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in 
O
(
n
)
O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]
Example 2:

Input: nums = [-1,0,1,2,3]

Output: [0,-6,0,0,0]
Constraints:

2 <= nums.length <= 1000
-20 <= nums[i] <= 20
*/

/*
observation: 
- if there's 1 zero, then all the other entries are 0 except for the zero
- if there's 2 zeros, then the output'd be all zeroes
- we probably need a zero counter
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1, zero_count = 0;
    vector<int> output(nums.size());
    for(auto elem : nums) {
        if(elem == 0) ++zero_count;
        else product *= elem;
    }

    if(zero_count > 1) return vector<int>(nums.size(), 0);

    for(int i = 0; i < nums.size(); ++i) {
        if(zero_count == 0) 
            output[i] = product / nums[i];
        else
            output[i] = (nums[i] == 0) ? product : 0;
    }
    return output;
}



int main(int argc, char *argv[])
{

    return 0;
}