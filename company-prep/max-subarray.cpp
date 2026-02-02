#include "headers.hpp"

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    
    int max_so_far = nums[0];
    int max_ending_here = 0;
    for(const int& num : nums) {
        max_ending_here += num;

        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;

        // if the sum is negative, discardd it
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {


    return 0;
}