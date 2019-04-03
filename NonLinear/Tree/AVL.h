template<typename T>

class AVL : public Tree<T> {
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

};