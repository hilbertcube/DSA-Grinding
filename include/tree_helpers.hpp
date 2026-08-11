#ifndef TREE_HELPERS
#define TREE_HELPERS

#include "headers.hpp"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Marks a missing child in a level-order list, mirroring LeetCode's `null`.
inline const optional<int> null = nullopt;

// Builds a tree from a LeetCode-style level-order list, e.g. {3, 9, 20, null, null, 15, 7}.
inline TreeNode *buildTreeFromLevelOrder(const vector<optional<int>> &values) {
  if (values.empty() || !values[0].has_value())
    return nullptr;

  TreeNode *root = new TreeNode(*values[0]);
  queue<TreeNode *> pending;
  pending.push(root);

  size_t i = 1;
  while (!pending.empty() && i < values.size()) {
    TreeNode *node = pending.front();
    pending.pop();

    if (i < values.size() && values[i].has_value()) {
      node->left = new TreeNode(*values[i]);
      pending.push(node->left);
    }
    ++i;

    if (i < values.size() && values[i].has_value()) {
      node->right = new TreeNode(*values[i]);
      pending.push(node->right);
    }
    ++i;
  }
  return root;
}

// Preorder with '#' for null, so a single string compares both shape and values.
inline string toPreorderString(TreeNode *root) {
  if (!root)
    return "#";
  return to_string(root->val) + "," + toPreorderString(root->left) + "," + toPreorderString(root->right);
}

// Level-order values, skipping missing children. Useful for BFS-shaped answers.
inline vector<int> toLevelOrder(TreeNode *root) {
  vector<int> values;
  if (!root)
    return values;

  queue<TreeNode *> pending;
  pending.push(root);
  while (!pending.empty()) {
    TreeNode *node = pending.front();
    pending.pop();
    values.push_back(node->val);
    if (node->left)
      pending.push(node->left);
    if (node->right)
      pending.push(node->right);
  }
  return values;
}

// First node holding `value`, searched in preorder. Returns nullptr if absent.
inline TreeNode *findNode(TreeNode *root, int value) {
  if (!root)
    return nullptr;
  if (root->val == value)
    return root;
  if (TreeNode *found = findNode(root->left, value))
    return found;
  return findNode(root->right, value);
}

inline void deleteTree(TreeNode *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

#endif
