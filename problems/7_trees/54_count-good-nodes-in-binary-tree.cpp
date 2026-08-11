#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
A node X is good if no node on the path from the root to X has a value greater
than X. The root is always good.

Example 1:

Input: root = [3,1,4,3,null,1,5]

Output: 4

Example 2:

Input: root = [3,3,null,4,2]

Output: 3
*/

int goodNodes(TreeNode *root) {
}

TEST(CountGoodNodes, MixedTree) {
  TreeNode *root = buildTreeFromLevelOrder({3, 1, 4, 3, null, 1, 5});

  EXPECT_EQ(goodNodes(root), 4);
  deleteTree(root);
}

// A node tying the running maximum still counts as good.
TEST(CountGoodNodes, TiesCountAsGood) {
  TreeNode *root = buildTreeFromLevelOrder({3, 3, null, 4, 2});

  EXPECT_EQ(goodNodes(root), 3);
  deleteTree(root);
}

TEST(CountGoodNodes, SingleNodeIsGood) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(goodNodes(root), 1);
  deleteTree(root);
}

TEST(CountGoodNodes, EmptyTree) {
  EXPECT_EQ(goodNodes(nullptr), 0);
}

TEST(CountGoodNodes, DecreasingPathLeavesOnlyRoot) {
  TreeNode *root = buildTreeFromLevelOrder({5, 4, null, 3, null, 2});

  EXPECT_EQ(goodNodes(root), 1);
  deleteTree(root);
}

TEST(CountGoodNodes, IncreasingPathIsAllGood) {
  TreeNode *root = buildTreeFromLevelOrder({1, null, 2, null, 3});

  EXPECT_EQ(goodNodes(root), 3);
  deleteTree(root);
}

TEST(CountGoodNodes, EqualValuesAreAllGood) {
  TreeNode *root = buildTreeFromLevelOrder({2, 2, 2});

  EXPECT_EQ(goodNodes(root), 3);
  deleteTree(root);
}

// Negative values must be handled, so the running maximum cannot start at 0.
TEST(CountGoodNodes, NegativeValues) {
  TreeNode *root = buildTreeFromLevelOrder({-5, -6, -4});

  EXPECT_EQ(goodNodes(root), 2);
  deleteTree(root);
}
