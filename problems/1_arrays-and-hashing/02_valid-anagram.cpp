#include "headers.h"
#include <gtest/gtest.h>

bool isAnagram1(string s, string t) {
  if (s.size() != t.size())
    return false;

  vector<int> frequency(26);
  for (int i{0}; i < s.size(); ++i) {
    frequency[s[i] - 'a']++;
    frequency[t[i] - 'a']--;
  }
  for (auto &ch : frequency) {
    if (ch != 0)
      return false;
  }
  return true;
}

bool isAnagram2(string s, string t) {
  if (s.size() != t.size())
    return false;

  unordered_map<char, int> countS;
  unordered_map<char, int> countT;

  for (int i{0}; i < s.size(); ++i) {
    countS[s[i]]++;
    countT[t[i]]++;
  }
  return countS == countT;
}

// Which implementation the tests run.
SELECT_IMPL(1, isAnagram, isAnagram1, isAnagram2);

TEST(ValidAnagram, IsAnagram) {
  EXPECT_TRUE(isAnagram("racecar", "carrace"));
  EXPECT_TRUE(isAnagram("anagram", "nagaram"));
}

TEST(ValidAnagram, NotAnagram) {
  EXPECT_FALSE(isAnagram("jar", "jam"));
  EXPECT_FALSE(isAnagram("rat", "car"));
}

TEST(ValidAnagram, DifferentLengths) {
  EXPECT_FALSE(isAnagram("abc", "ab"));
}

TEST(ValidAnagram, EmptyStrings) {
  EXPECT_TRUE(isAnagram("", ""));
}

TEST(ValidAnagram, SingleChar) {
  EXPECT_TRUE(isAnagram("a", "a"));
  EXPECT_FALSE(isAnagram("a", "b"));
}
