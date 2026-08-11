#include "tree_helpers.h"
#include <gtest/gtest.h>

/*
Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]

Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]

Output: false
*/

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
}

TEST(SubtreeOfAnotherTree, MatchesInnerSubtree) {
  TreeNode *root = buildTreeFromLevelOrder({3, 4, 5, 1, 2});
  TreeNode *subRoot = buildTreeFromLevelOrder({4, 1, 2});

  EXPECT_TRUE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

// The candidate must match all the way down, not just the top few nodes.
TEST(SubtreeOfAnotherTree, PartialMatchIsNotEnough) {
  TreeNode *root = buildTreeFromLevelOrder({3, 4, 5, 1, 2, null, null, null, null, 0});
  TreeNode *subRoot = buildTreeFromLevelOrder({4, 1, 2});

  EXPECT_FALSE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

TEST(SubtreeOfAnotherTree, WholeTreeCountsAsSubtree) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3});
  TreeNode *subRoot = buildTreeFromLevelOrder({1, 2, 3});

  EXPECT_TRUE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

TEST(SubtreeOfAnotherTree, SingleNodeMatchesLeaf) {
  TreeNode *root = buildTreeFromLevelOrder({1, 1});
  TreeNode *subRoot = buildTreeFromLevelOrder({1});

  EXPECT_TRUE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

TEST(SubtreeOfAnotherTree, ValueMissingFromRoot) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3});
  TreeNode *subRoot = buildTreeFromLevelOrder({4});

  EXPECT_FALSE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

// Node 2 exists in root but is a leaf there, so the shapes differ.
TEST(SubtreeOfAnotherTree, MatchingValueWithExtraChild) {
  TreeNode *root = buildTreeFromLevelOrder({1, 2, 3});
  TreeNode *subRoot = buildTreeFromLevelOrder({2, null, 4});

  EXPECT_FALSE(isSubtree(root, subRoot));
  deleteTree(root);
  deleteTree(subRoot);
}

TEST(SubtreeOfAnotherTree, EmptyRootHasNoSubtree) {
  TreeNode *subRoot = buildTreeFromLevelOrder({1});

  EXPECT_FALSE(isSubtree(nullptr, subRoot));
  deleteTree(subRoot);
}
