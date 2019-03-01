#include <bits/stdc++.h>

#include "Factory/ListFactory.h"

using namespace std;

int main() {
    ListFactory<int> *listFactory;
    try {
        List<int> *list = listFactory->getList("LinkedList");
    } catch (exception const &ex) {
        cout << ex.what();
    }
}