
#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/AbstractFactory.h"

using namespace std;

int main() {
    AbstractFactory<int> *abstractFactory;
    Factory<int> *listFactory = abstractFactory->getFactory("List");
    try {
        ListInterface<int> *linkedList = listFactory->getList("LinkedList");
    } catch (exception const &ex) {
        cout << ex.what();
    }
}