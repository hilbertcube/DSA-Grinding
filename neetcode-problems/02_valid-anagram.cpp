#include "headers.hpp"

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int n = s.length();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; ++i)
    {
        ++freq[s[i] - 'a'];
        --freq[t[i] - 'a'];
    }
    for (int c : freq)
        if (c != 0)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    print_bool(isAnagram("racecar", "carrace"));
    print_bool(isAnagram("car", "jar"));
    return 0;
}

// ./run.sh 02_valid_anagram