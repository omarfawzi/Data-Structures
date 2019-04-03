#include "Nodes/TreeNode.h"

template<typename T>

class Tree {
protected:
    TreeNode<T> *root;
public:
    virtual TreeNode<T> *insert(T value, TreeNode<T> *node) = 0;

    TreeNode<T> *getRoot() {
        return this->root;
    };

    void setRoot(TreeNode<T> *node) {
        this->root = node;
    }

    void printInOrder(TreeNode<T> *root) {
        if (root != nullptr) {
            printInOrder(root->left);
            std::cout << root->data << ' ';
            printInOrder(root->right);
        }
    }

    TreeNode<T> *search(T value, TreeNode<T> *node) {
        if (node == nullptr) {
            throw std::out_of_range("Value not found at BST : " + std::to_string(value));
        }
        if (node->data == value) {
            return node;
        } else {
            if (value > node->data) {
                return search(value, node->right);
            } else {
                return search(value, node->left);
            }
        }
    }
};