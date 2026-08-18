#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Example 1:

Input: root = [4,2,7,1,3,6,9]

Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]

Output: [2,3,1]
*/

// Recursive DFS
TreeNode *invertTree1(TreeNode *root) {
  if (!root)
    return nullptr;
  swap(root->left, root->right);
  invertTree1(root->left);
  invertTree1(root->right);
  return root;
}

// BFS
TreeNode *invertTree2(TreeNode *root) {
  if (!root)
    return nullptr;
  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    TreeNode *node = queue.front();
    queue.pop();
    swap(node->left, node->right);  // process node
    if (node->left)
      queue.push(node->left);
    if (node->right)
      queue.push(node->right);
  }
  return root;
}

// Iterative DFS
TreeNode *invertTree3(TreeNode *root) {
  if (!root)
    return nullptr;
  stack<TreeNode *> stack;
  stack.push(root);
  while (!stack.empty()) {
    TreeNode *node = stack.top();
    stack.pop();
    swap(node->left, node->right);  // process node
    if (node->left)
      stack.push(node->left);
    if (node->right)
      stack.push(node->right);
  }
  return root;
}

// Which implementation the tests run.
SELECT_IMPL(2, invertTree, invertTree1, invertTree2, invertTree3);

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
