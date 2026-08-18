#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
The diameter is the length (in edges) of the longest path between any two nodes.
The path does not have to pass through the root.

Example 1:

Input: root = [1,2,3,4,5]

Output: 3

Example 2:

Input: root = [1,2]

Output: 1
*/

// preorder dfs
int dfs(TreeNode* root, int& height) {
  if(!root) return 0;

  int left_height = dfs(root->left, height);
  int right_height = dfs(root->right, height);
  height = max(height, left_height + right_height);
  return 1 + max(left_height, right_height);
}

// DFS
int diameterOfBinaryTree1(TreeNode *root) {
  int height = 0;
  dfs(root, height);
  return height;
}



// Which implementation the tests run.
SELECT_IMPL(1, diameterOfBinaryTree, diameterOfBinaryTree1);

TEST(DiameterOfBinaryTree, PathThroughRoot) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, 5});

  EXPECT_EQ(diameterOfBinaryTree(root), 3);
  deleteTree(root);
}

TEST(DiameterOfBinaryTree, TwoNodes) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2});

  EXPECT_EQ(diameterOfBinaryTree(root), 1);
  deleteTree(root);
}

TEST(DiameterOfBinaryTree, SingleNodeHasNoEdges) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(diameterOfBinaryTree(root), 0);
  deleteTree(root);
}

TEST(DiameterOfBinaryTree, EmptyTreeHasNoEdges) {
  EXPECT_EQ(diameterOfBinaryTree(nullptr), 0);
}

TEST(DiameterOfBinaryTree, StraightLineIsItsOwnDiameter) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, null, 3, null, 4});

  EXPECT_EQ(diameterOfBinaryTree(root), 3);
  deleteTree(root);
}

// Longest path is 7-4-2-5-9, which never reaches the root.
TEST(DiameterOfBinaryTree, PathNotThroughRoot) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, null, 4, 5, 7, null, null, 9});

  EXPECT_EQ(diameterOfBinaryTree(root), 4);
  deleteTree(root);
}
