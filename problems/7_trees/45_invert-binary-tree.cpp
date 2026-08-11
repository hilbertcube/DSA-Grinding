#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
Example 1:

Input: root = [4,2,7,1,3,6,9]

Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]

Output: [2,3,1]
*/

TreeNode *invertTree(TreeNode *root) {
  if (!root)
    return nullptr;
  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

TEST(InvertBinaryTree, MirrorsPerfectTree) {
  TreeNode *root = buildTreeFromLevelOrder({4, 2, 7, 1, 3, 6, 9});

  EXPECT_EQ(toPreorderString(invertTree(root)), "4,7,9,#,#,6,#,#,2,3,#,#,1,#,#");
  deleteTree(root);
}

TEST(InvertBinaryTree, MirrorsThreeNodeTree) {
  TreeNode *root = buildTreeFromLevelOrder({2, 1, 3});

  EXPECT_EQ(toPreorderString(invertTree(root)), "2,3,#,#,1,#,#");
  deleteTree(root);
}

TEST(InvertBinaryTree, TurnsLeftSpineIntoRightSpine) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, null, 3});

  EXPECT_EQ(toPreorderString(invertTree(root)), "1,#,2,#,3,#,#");
  deleteTree(root);
}

TEST(InvertBinaryTree, SingleNodeIsUnchanged) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(toPreorderString(invertTree(root)), "1,#,#");
  deleteTree(root);
}

TEST(InvertBinaryTree, HandlesEmptyTree) {
  EXPECT_EQ(invertTree(nullptr), nullptr);
}
