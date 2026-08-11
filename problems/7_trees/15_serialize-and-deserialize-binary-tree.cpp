#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Design an algorithm to serialize a tree to a string and deserialize that string
back into the same tree. The encoding format is up to you, so the tests only
check that a round trip preserves the tree.

Example 1:

Input: root = [1,2,3,null,null,4,5]

Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []

Output: []
*/

class Codec {
public:
  string serialize(TreeNode *root) {
  }

  TreeNode *deserialize(string data) {
  }
};

// Serializing and deserializing must reproduce the original shape and values.
void expectRoundTrip(const vector<optional<int>> &values) {
  Codec codec;
  TreeNode *original = buildTreeFromLevelOrder(values);

  TreeNode *restored = codec.deserialize(codec.serialize(original));

  EXPECT_EQ(toPreorderString(restored), toPreorderString(original));
  deleteTree(original);
  deleteTree(restored);
}

TEST(SerializeDeserialize, BalancedTree) {
  expectRoundTrip({1, 2, 3, null, null, 4, 5});
}

TEST(SerializeDeserialize, EmptyTree) {
  Codec codec;

  EXPECT_EQ(codec.deserialize(codec.serialize(nullptr)), nullptr);
}

TEST(SerializeDeserialize, SingleNode) {
  expectRoundTrip({1});
}

TEST(SerializeDeserialize, LeftSpine) {
  expectRoundTrip({1, 2, null, 3, null, 4});
}

TEST(SerializeDeserialize, RightSpine) {
  expectRoundTrip({1, null, 2, null, 3, null, 4});
}

// Negative values and multi-digit values must survive the encoding.
TEST(SerializeDeserialize, NegativeAndMultiDigitValues) {
  expectRoundTrip({-100, -200, 300, null, null, 1000, -1});
}

TEST(SerializeDeserialize, LopsidedTree) {
  expectRoundTrip({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1});
}

// The same values in a different arrangement must not collapse to one encoding.
TEST(SerializeDeserialize, DistinguishesMirroredTrees) {
  Codec codec;
  TreeNode *left = buildTreeFromLevelOrder({1, 2, null});
  TreeNode *right = buildTreeFromLevelOrder({1, null, 2});

  EXPECT_NE(codec.serialize(left), codec.serialize(right));

  deleteTree(left);
  deleteTree(right);
}
