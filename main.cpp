#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/HeapFactory.h"
#include "Factory/TreeFactory.h"

using namespace std;

int main() {
    TreeFactory<int> *treeFactory;
    try {
        Tree<int> *tree = treeFactory->getTree("BST");
        tree->setRoot(tree->insert(1, nullptr));
        tree->insert(2, tree->getRoot());
        tree->insert(4, tree->getRoot());
        tree->insert(3, tree->getRoot());
        tree->insert(5, tree->getRoot());
        std::cout << tree->search(6, tree->getRoot())->data;
    } catch (exception const &ex) {
        cout << ex.what();
    }
}