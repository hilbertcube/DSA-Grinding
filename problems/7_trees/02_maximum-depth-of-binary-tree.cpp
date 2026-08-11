#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Example 1:

Input: root = [3,9,20,null,null,15,7]

Output: 3

Example 2:

Input: root = []

Output: 0
*/

int maxDepth1(TreeNode *root) {
  if (!root)
    return 0;
  return 0;
}

// DFS
int maxDepth2(TreeNode *root) {
  if (!root)
    return 0;
  return 0;
}

// Which implementation the tests run.
SELECT_IMPL(1, maxDepth, maxDepth1, maxDepth2);

TEST(MaximumDepth, CountsLevelsOfBalancedTree) {
  TreeNode *root = buildTreeFromLevelOrder({3, 9, 20, null, null, 15, 7});

  EXPECT_EQ(maxDepth(root), 3);
  deleteTree(root);
}

TEST(MaximumDepth, EmptyTreeHasDepthZero) {
  EXPECT_EQ(maxDepth(nullptr), 0);
}

TEST(MaximumDepth, SingleNodeHasDepthOne) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(maxDepth(root), 1);
  deleteTree(root);
}

TEST(MaximumDepth, FollowsRightSpine) {
  TreeNode *root = buildTreeFromLevelOrder({1, null, 2, null, 3});

  EXPECT_EQ(maxDepth(root), 3);
  deleteTree(root);
}

TEST(MaximumDepth, TakesDeeperOfTwoSubtrees) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, 5});

  EXPECT_EQ(maxDepth(root), 3);
  deleteTree(root);
}
