#include "headers.hpp"

bool hasDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (auto num : nums)
    {
        if (set.count(num))
            return true;
        set.insert(num);
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<int> num1 = {1, 2, 3, 3};
    print_bool(hasDuplicate(num1));

    return 0;
}

// ./run.sh 01_contains_duplicate