
#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/AbstractFactory.h"
#include "Linear/Stack.h"

using namespace std;

int main() {
    AbstractFactory<int> *abstractFactory;
    Factory<int> *listFactory = abstractFactory->getFactory("List");
    try {
        auto *stack = new Stack<DoubleLinkedList<string>, string >();
    } catch (exception const &ex) {
        cout << ex.what();
    }
}