#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Example 1:

Input: root = [3,9,20,null,null,15,7]

Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = []

Output: []
*/

vector<vector<int>> levelOrder(TreeNode *root) {
}

TEST(LevelOrderTraversal, GroupsNodesByLevel) {
  TreeNode *root = buildTreeFromLevelOrder({3, 9, 20, null, null, 15, 7});

  EXPECT_EQ(levelOrder(root), (vector<vector<int>>{{3}, {9, 20}, {15, 7}}));
  deleteTree(root);
}

TEST(LevelOrderTraversal, EmptyTreeHasNoLevels) {
  EXPECT_EQ(levelOrder(nullptr), (vector<vector<int>>{}));
}

TEST(LevelOrderTraversal, SingleNode) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(levelOrder(root), (vector<vector<int>>{{1}}));
  deleteTree(root);
}

// Node 4 and node 5 sit on the same level despite hanging off different parents.
TEST(LevelOrderTraversal, PairsNodesFromDifferentParents) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, 5});

  EXPECT_EQ(levelOrder(root), (vector<vector<int>>{{1}, {2, 3}, {4, 5}}));
  deleteTree(root);
}

TEST(LevelOrderTraversal, RightSpineIsOnePerLevel) {
  TreeNode *root = buildTreeFromLevelOrder({1, null, 2, null, 3});

  EXPECT_EQ(levelOrder(root), (vector<vector<int>>{{1}, {2}, {3}}));
  deleteTree(root);
}

TEST(LevelOrderTraversal, PreservesLeftToRightOrder) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3, 4, 5, 6, 7});

  EXPECT_EQ(levelOrder(root), (vector<vector<int>>{{1}, {2, 3}, {4, 5, 6, 7}}));
  deleteTree(root);
}
