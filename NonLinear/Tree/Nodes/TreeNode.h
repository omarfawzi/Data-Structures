template<typename T>

struct TreeNode {
    TreeNode<T>(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->balanceFactor = 0;
    }

    T data;
    int balanceFactor;
    TreeNode *left;
    TreeNode *right;
};