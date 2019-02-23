
#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/AbstractFactory.h"

using namespace std;

int main() {
    AbstractFactory<int> *abstractFactory;
    Factory<int> *listFactory = abstractFactory->getFactory("List");
    try {
        ListInterface<int> *list = listFactory->getList("DoubleLinkedList");
        list->insertFirst(1);
        list->insertFirst(2);
        list->insertFirst(3);

        list->print();
    } catch (exception const &ex) {
        cout << ex.what();
    }
}