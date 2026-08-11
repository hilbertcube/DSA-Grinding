#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Return the values visible when the tree is viewed from the right, top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Example 2:

Input: root = [1,null,3]

Output: [1,3]
*/

vector<int> rightSideView(TreeNode *root) {
}

TEST(RightSideView, SeesRightmostOfEachLevel) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, null, 5, null, 4});

  EXPECT_EQ(rightSideView(root), (vector<int>{1, 3, 4}));
  deleteTree(root);
}

TEST(RightSideView, RightChildOnly) {
  TreeNode *root = buildTreeFromLevelOrder({1, null, 3});

  EXPECT_EQ(rightSideView(root), (vector<int>{1, 3}));
  deleteTree(root);
}

TEST(RightSideView, EmptyTree) {
  EXPECT_EQ(rightSideView(nullptr), (vector<int>{}));
}

TEST(RightSideView, SingleNode) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(rightSideView(root), (vector<int>{1}));
  deleteTree(root);
}

// With no right subtree at all, every node on the left spine is visible.
TEST(RightSideView, LeftSpineIsFullyVisible) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, null, 3});

  EXPECT_EQ(rightSideView(root), (vector<int>{1, 2, 3}));
  deleteTree(root);
}

// Levels 2 and 3 exist only under the left child, so 4 and 5 become visible.
TEST(RightSideView, DeepLeftSubtreeShowsThrough) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, null, 5});

  EXPECT_EQ(rightSideView(root), (vector<int>{1, 3, 4, 5}));
  deleteTree(root);
}
