#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
A path is any sequence of nodes connected by edges; it need not pass through the
root, and it must contain at least one node.

Example 1:

Input: root = [1,2,3]

Output: 6

Example 2:

Input: root = [-10,9,20,null,null,15,7]

Output: 42
*/

int maxPathSum(TreeNode *root) {
}

TEST(MaxPathSum, WholeSmallTree) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3});

  EXPECT_EQ(maxPathSum(root), 6);
  deleteTree(root);
}

// The best path is 15-20-7 and skips the negative root.
TEST(MaxPathSum, SkipsNegativeRoot) {
  TreeNode *root = buildTreeFromLevelOrder({-10, 9, 20, null, null, 15, 7});

  EXPECT_EQ(maxPathSum(root), 42);
  deleteTree(root);
}

TEST(MaxPathSum, SingleNode) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(maxPathSum(root), 1);
  deleteTree(root);
}

// With every value negative the answer is the least-bad single node.
TEST(MaxPathSum, SingleNegativeNode) {
  TreeNode *root = buildTreeFromLevelOrder({-3});

  EXPECT_EQ(maxPathSum(root), -3);
  deleteTree(root);
}

TEST(MaxPathSum, AllNegativeValues) {
  TreeNode *root = buildTreeFromLevelOrder({-2, -1});

  EXPECT_EQ(maxPathSum(root), -1);
  deleteTree(root);
}

// Adding the negative child would only shrink the total, so it is dropped.
TEST(MaxPathSum, DropsNegativeChild) {
  TreeNode *root = buildTreeFromLevelOrder({2, -1});

  EXPECT_EQ(maxPathSum(root), 2);
  deleteTree(root);
}

// Best path is 7-11-4-5-8-13, bending through the root.
TEST(MaxPathSum, PathBendsThroughRoot) {
  TreeNode *root = buildTreeFromLevelOrder({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1});

  EXPECT_EQ(maxPathSum(root), 48);
  deleteTree(root);
}
