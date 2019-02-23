
#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/AbstractFactory.h"

using namespace std;

int main() {
    AbstractFactory<int> *abstractFactory;
    Factory<int> *listFactory = abstractFactory->getFactory("List");
    try {
        ListInterface<int> *list = listFactory->getList("DoubleLinkedList");
        list->insertLast(1);
        list->insertLast(2);
        list->insertLast(3);
        list->print();
    } catch (exception const &ex) {
        cout << ex.what();
    }
}