#include "headers.hpp"

/*
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.

*/

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    // make an array of chars to store frequency of each char
    std::vector<int> freq(26, 0);
    for(int i{0}; i < s.size(); ++i) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for(int var : freq) {
        if(var != 0) return false;
    }
    return true;
}

bool isAnagram2(string s, string t) {
    if(s.size() != t.size()) return false;

    unordered_map<char, int> countS;
    unordered_map<char, int> countT;

    for(int i{0}; i < s.size(); ++i) {
        countS[s[i]]++;
        countT[t[i]]++;
    }
    return countS == countT;
}

int main(int argc, char *argv[])
{

    return 0;
}