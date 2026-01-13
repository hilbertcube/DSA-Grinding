#include "headers.hpp"

/*
Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
*/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> res;

    // count the frequency
    for (auto s : strs)
    {
        vector<int> freq(0, 26);
        for (auto c : s)
        {
            ++freq[c - 'a'];
        }
    }
}

int main(int argc, char *argv[])
{
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    groupAnagrams(strs);
    return 0;
}
