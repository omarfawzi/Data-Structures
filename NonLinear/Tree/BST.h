template<typename T>

class BST : public Tree<T> {
public:
    TreeNode<T> *insert(T value, TreeNode<T> *node) override {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        } else {
            if (value <= node->data) {
                node->left = insert(value, node->left);
            }
            if (value > node->data) {
                node->right = insert(value, node->right);
            }
        }
        return node;
    }

    TreeNode<T> *search(T value, TreeNode<T> *node) override {
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