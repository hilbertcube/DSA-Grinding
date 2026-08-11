#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
A tree is balanced when, for every node, the heights of its two subtrees
differ by at most one.

Example 1:

Input: root = [3,9,20,null,null,15,7]

Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]

Output: false
*/

bool isBalanced(TreeNode *root) {
}

TEST(BalancedBinaryTree, BalancedTree) {
  TreeNode *root = buildTreeFromLevelOrder({3, 9, 20, null, null, 15, 7});

  EXPECT_TRUE(isBalanced(root));
  deleteTree(root);
}

TEST(BalancedBinaryTree, UnbalancedTree) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 2, 3, 3, null, null, 4, 4});

  EXPECT_FALSE(isBalanced(root));
  deleteTree(root);
}

TEST(BalancedBinaryTree, EmptyTreeIsBalanced) {
  EXPECT_TRUE(isBalanced(nullptr));
}

TEST(BalancedBinaryTree, SingleNodeIsBalanced) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_TRUE(isBalanced(root));
  deleteTree(root);
}

TEST(BalancedBinaryTree, HeightGapOfTwoAtRoot) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, null, 3});

  EXPECT_FALSE(isBalanced(root));
  deleteTree(root);
}

TEST(BalancedBinaryTree, StaggeredButWithinTolerance) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, 5});

  EXPECT_TRUE(isBalanced(root));
  deleteTree(root);
}

// The root's subtree heights match, but node 3 has a three-deep left arm and no
// right arm. Catches solutions that only check the root.
TEST(BalancedBinaryTree, ImbalanceHiddenBelowRoot) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, null, null, 4, null, 5});

  EXPECT_FALSE(isBalanced(root));
  deleteTree(root);
}
