#include "headers.hpp"

bool isAnagram(string s, string t) {
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

#ifdef TESTING
#include <gtest/gtest.h>

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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

int main() {
  return 0;
}

#endif
