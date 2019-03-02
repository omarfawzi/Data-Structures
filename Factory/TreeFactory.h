#include <string>
#include <stdexcept>
#include "../NonLinear/Tree/Tree.h"
#include "../NonLinear/Tree/BST.h"

template<typename T>

class TreeFactory {
public:
    Tree<T> *getTree(const std::string &tree) {
        if (tree == "BST") {
            return new BST<T>();
        } else {
            throw std::out_of_range("Invalid Tree Type : " + tree);
        }
    }
};