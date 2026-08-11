#include "tree_helpers.hpp"
#include <gtest/gtest.h>

/*
Example 1:

Input: p = [1,2,3], q = [1,2,3]

Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]

Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]

Output: false
*/

bool isSameTree(TreeNode *p, TreeNode *q) {
}

TEST(SameTree, IdenticalTrees) {
  TreeNode *p = buildTreeFromLevelOrder({1, 2, 3});
  TreeNode *q = buildTreeFromLevelOrder({1, 2, 3});

  EXPECT_TRUE(isSameTree(p, q));
  deleteTree(p);
  deleteTree(q);
}

TEST(SameTree, SameValuesDifferentShape) {
  TreeNode *p = buildTreeFromLevelOrder({1, 2});
  TreeNode *q = buildTreeFromLevelOrder({1, null, 2});

  EXPECT_FALSE(isSameTree(p, q));
  deleteTree(p);
  deleteTree(q);
}

TEST(SameTree, SameShapeDifferentValues) {
  TreeNode *p = buildTreeFromLevelOrder({1, 2, 1});
  TreeNode *q = buildTreeFromLevelOrder({1, 1, 2});

  EXPECT_FALSE(isSameTree(p, q));
  deleteTree(p);
  deleteTree(q);
}

TEST(SameTree, BothEmpty) {
  EXPECT_TRUE(isSameTree(nullptr, nullptr));
}

TEST(SameTree, OneEmpty) {
  TreeNode *q = buildTreeFromLevelOrder({1});

  EXPECT_FALSE(isSameTree(nullptr, q));
  EXPECT_FALSE(isSameTree(q, nullptr));
  deleteTree(q);
}

TEST(SameTree, DifferenceOnlyInDeepestLevel) {
  TreeNode *p = buildTreeFromLevelOrder({1, 2, 3, 4, 5});
  TreeNode *q = buildTreeFromLevelOrder({1, 2, 3, 4, 6});

  EXPECT_FALSE(isSameTree(p, q));
  deleteTree(p);
  deleteTree(q);
}

TEST(SameTree, IdenticalLargerTrees) {
  TreeNode *p = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, 5});
  TreeNode *q = buildTreeFromLevelOrder({1, 2, 3, 4, null, null, 5});

  EXPECT_TRUE(isSameTree(p, q));
  deleteTree(p);
  deleteTree(q);
}
