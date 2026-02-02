#pragma once

#include <iostream>
#include <queue>

class BinaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = new Node(value);
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (!current->left) {
                current->left = new Node(value);
                return;
            } else {
                q.push(current->left);
            }

            if (!current->right) {
                current->right = new Node(value);
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void inorder() const {
        inorderHelper(root);
        std::cout << std::endl;
    }

    void preorder() const {
        preorderHelper(root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorderHelper(root);
        std::cout << std::endl;
    }

private:
    void inorderHelper(Node* node) const {
        if (!node) return;
        inorderHelper(node->left);
        std::cout << node->value << " ";
        inorderHelper(node->right);
    }

    void preorderHelper(Node* node) const {
        if (!node) return;
        std::cout << node->value << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(Node* node) const {
        if (!node) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        std::cout << node->value << " ";
    }
};
