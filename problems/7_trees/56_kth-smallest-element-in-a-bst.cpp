#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
k is 1-indexed.

Example 1:

Input: root = [3,1,4,null,2], k = 1

Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3

Output: 3
*/

int kthSmallest(TreeNode *root, int k) {
}

TEST(KthSmallestInBST, FirstElement) {
  TreeNode *root = buildTreeFromLevelOrder({3, 1, 4, null, 2});

  EXPECT_EQ(kthSmallest(root, 1), 1);
  deleteTree(root);
}

TEST(KthSmallestInBST, MiddleElement) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 6, 2, 4, null, null, 1});

  EXPECT_EQ(kthSmallest(root, 3), 3);
  deleteTree(root);
}

TEST(KthSmallestInBST, SingleNode) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_EQ(kthSmallest(root, 1), 1);
  deleteTree(root);
}

// Inorder is 1,3,4,5,7,8,9 — walk every position of the same tree.
TEST(KthSmallestInBST, WalksFullInorderSequence) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});
  vector<int> expected = {1, 3, 4, 5, 7, 8, 9};

  for (int k = 1; k <= static_cast<int>(expected.size()); ++k)
    EXPECT_EQ(kthSmallest(root, k), expected[k - 1]) << "k = " << k;

  deleteTree(root);
}

TEST(KthSmallestInBST, LastElement) {
  TreeNode *root = buildTreeFromLevelOrder({5, 3, 8, 1, 4, 7, 9});

  EXPECT_EQ(kthSmallest(root, 7), 9);
  deleteTree(root);
}

TEST(KthSmallestInBST, LeftLeaningTree) {
  TreeNode *root = buildTreeFromLevelOrder({2, 1});

  EXPECT_EQ(kthSmallest(root, 2), 2);
  deleteTree(root);
}

TEST(KthSmallestInBST, NegativeValues) {
  TreeNode *root = buildTreeFromLevelOrder({0, -3, 2, null, -1});

  EXPECT_EQ(kthSmallest(root, 2), -1);
  deleteTree(root);
}
