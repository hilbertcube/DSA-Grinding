#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
Every value in the left subtree must be strictly less than the node, and every
value in the right subtree strictly greater.

Example 1:

Input: root = [2,1,3]

Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]

Output: false
*/

bool isValidBST(TreeNode *root) {
}

TEST(ValidateBST, SimpleValidTree) {
  TreeNode *root = buildTreeFromLevelOrder({2, 1, 3});

  EXPECT_TRUE(isValidBST(root));
  deleteTree(root);
}

TEST(ValidateBST, RightChildSmallerThanRoot) {
  TreeNode *root = buildTreeFromLevelOrder({5, 1, 4, null, null, 3, 6});

  EXPECT_FALSE(isValidBST(root));
  deleteTree(root);
}

TEST(ValidateBST, EmptyTreeIsValid) {
  EXPECT_TRUE(isValidBST(nullptr));
}

TEST(ValidateBST, SingleNodeIsValid) {
  TreeNode *root = buildTreeFromLevelOrder({1});

  EXPECT_TRUE(isValidBST(root));
  deleteTree(root);
}

TEST(ValidateBST, LargerValidTree) {
  TreeNode *root = buildTreeFromLevelOrder({8, 4, 12, 2, 6, 10, 14});

  EXPECT_TRUE(isValidBST(root));
  deleteTree(root);
}

// Each node beats its own parent, but 6 violates the root's lower bound of 10.
TEST(ValidateBST, ViolationOnlyVisibleAgainstAncestorBound) {
  TreeNode *root = buildTreeFromLevelOrder({10, 5, 15, null, null, 6, 20});

  EXPECT_FALSE(isValidBST(root));
  deleteTree(root);
}

TEST(ValidateBST, DuplicateValueIsInvalid) {
  TreeNode *root = buildTreeFromLevelOrder({2, 2});

  EXPECT_FALSE(isValidBST(root));
  deleteTree(root);
}

// Bounds must use a wider type or explicit optionals to survive INT_MIN/INT_MAX.
TEST(ValidateBST, HandlesExtremeIntValues) {
  TreeNode *root = buildTreeFromLevelOrder({INT_MAX});

  EXPECT_TRUE(isValidBST(root));
  deleteTree(root);

  TreeNode *other = buildTreeFromLevelOrder({INT_MIN, null, INT_MAX});

  EXPECT_TRUE(isValidBST(other));
  deleteTree(other);
}
