#include "headers.hpp"

/*
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
*/

// implementation 1: 
vector<vector<string>> groupAnagrams(vector<string> &strs) {
  // {sorted string, list of corresponding strings}
  unordered_map<string, vector<string>> res; 
  vector<vector<int>> output;

  for(auto& str : strs) {
    string sorted_str = str;
    sort(sorted_str.begin(), sorted_str.end());
    res[sorted_str].push_back(str);
  }

  for(auto& list : output) {
    
  }

}

int main(int argc, char *argv[]) {

  return 0;
}