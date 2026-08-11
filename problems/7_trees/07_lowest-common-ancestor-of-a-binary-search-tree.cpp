#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
A node can be a descendant of itself.

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8

Output: 6

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4

Output: 2
*/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
}

TEST(LowestCommonAncestorBST, SplitsAtRoot) {
  TreeNode *root = buildTreeFromLevelOrder({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 2), findNode(root, 8));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 6);
  deleteTree(root);
}

// p is an ancestor of q, so p is its own lowest common ancestor.
TEST(LowestCommonAncestorBST, AncestorIsItsOwnLCA) {
  TreeNode *root = buildTreeFromLevelOrder({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 2), findNode(root, 4));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

TEST(LowestCommonAncestorBST, RootAndItsOnlyChild) {
  TreeNode *root = buildTreeFromLevelOrder({2, 1});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 2), findNode(root, 1));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 2);
  deleteTree(root);
}

TEST(LowestCommonAncestorBST, BothInLeftSubtree) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 1), findNode(root, 4));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 3);
  deleteTree(root);
}

TEST(LowestCommonAncestorBST, BothInRightSubtree) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 7), findNode(root, 9));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 8);
  deleteTree(root);
}

TEST(LowestCommonAncestorBST, OppositeExtremesMeetAtRoot) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});

  TreeNode *lca = lowestCommonAncestor(root, findNode(root, 1), findNode(root, 9));

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 5);
  deleteTree(root);
}

TEST(LowestCommonAncestorBST, SameNodeTwice) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});
  TreeNode *node = findNode(root, 4);

  TreeNode *lca = lowestCommonAncestor(root, node, node);

  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, 4);
  deleteTree(root);
}
