#include "headers.hpp"

bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for(auto num: nums) {
        if(set.count(num))
            return true;
        set.insert(num);
    }
    return false;
}

int main(int argc, char *argv[])
{

    return 0;
}