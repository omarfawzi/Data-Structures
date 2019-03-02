template<typename T>

struct TreeNode {
    TreeNode<T>(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    T data;
    TreeNode *left;
    TreeNode *right;
};