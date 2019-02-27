
#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/AbstractFactory.h"
#include "Linear/Queue.h"

using namespace std;

int main() {
    AbstractFactory<int> *abstractFactory;
    Factory<int> *listFactory = abstractFactory->getFactory("List");
    try {
        auto *queue = new Queue<DoubleLinkedList<int>, int >();

    } catch (exception const &ex) {
        cout << ex.what();
    }
}