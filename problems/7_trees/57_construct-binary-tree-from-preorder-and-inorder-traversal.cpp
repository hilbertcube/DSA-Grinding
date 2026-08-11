#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
Values are unique.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]

Output: [-1]
*/

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
}

TEST(ConstructFromPreorderInorder, RebuildsBalancedTree) {
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toPreorderString(root), "3,9,#,#,20,15,#,#,7,#,#");
  deleteTree(root);
}

TEST(ConstructFromPreorderInorder, SingleNode) {
  vector<int> preorder = {-1};
  vector<int> inorder = {-1};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toPreorderString(root), "-1,#,#");
  deleteTree(root);
}

TEST(ConstructFromPreorderInorder, EmptyInputYieldsNull) {
  vector<int> preorder = {};
  vector<int> inorder = {};

  EXPECT_EQ(buildTree(preorder, inorder), nullptr);
}

// Reversed inorder means every node hangs off its parent's left.
TEST(ConstructFromPreorderInorder, LeftSpine) {
  vector<int> preorder = {1, 2, 3};
  vector<int> inorder = {3, 2, 1};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toPreorderString(root), "1,2,3,#,#,#,#");
  deleteTree(root);
}

// Matching preorder and inorder means every node hangs off its parent's right.
TEST(ConstructFromPreorderInorder, RightSpine) {
  vector<int> preorder = {1, 2, 3};
  vector<int> inorder = {1, 2, 3};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toPreorderString(root), "1,#,2,#,3,#,#");
  deleteTree(root);
}

TEST(ConstructFromPreorderInorder, ThreeNodeBalancedTree) {
  vector<int> preorder = {1, 2, 3};
  vector<int> inorder = {2, 1, 3};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toPreorderString(root), "1,2,#,#,3,#,#");
  deleteTree(root);
}

TEST(ConstructFromPreorderInorder, LargerLopsidedTree) {
  vector<int> preorder = {1, 2, 4, 5, 3, 6};
  vector<int> inorder = {4, 2, 5, 1, 6, 3};

  TreeNode *root = buildTree(preorder, inorder);

  EXPECT_EQ(toLevelOrder(root), (vector<int>{1, 2, 3, 4, 5, 6}));
  EXPECT_EQ(toPreorderString(root), "1,2,4,#,#,5,#,#,3,6,#,#,#");
  deleteTree(root);
}
