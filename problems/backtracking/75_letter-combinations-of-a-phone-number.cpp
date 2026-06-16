#include "headers.hpp"

/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = "2"
Output: ["a","b","c"]
*/

vector<string> letterCombinations(string digits) {
  if (digits.empty())
    return {};

  unordered_map<char, string> map = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  // generate conbination
  vector<string> output;
  output.reserve(pow(4, digits.size()));
  output.push_back("");
  for (char c : digits) {
    vector<string> next;
    for (const string &prefix : output) {
      for (char letter : map[c]) {
        next.push_back(prefix + letter);
      }
    }
    output = move(next);
  }
  return output;
}

int main(int argc, char *argv[]) {

  return 0;
}