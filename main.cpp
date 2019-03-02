#include <bits/stdc++.h>

#include "Factory/ListFactory.h"
#include "Factory/HeapFactory.h"

using namespace std;

int main() {
    ListFactory<int> *listFactory;
    HeapFactory<int> *heapFactory;
    try {
        List<int> *list = listFactory->getList("LinkedList");
        Heap<int> *heap = heapFactory->getHeap("MaxHeap", 10);
        heap->push(5);
        heap->push(3);
        heap->push(2);
        heap->push(1);
        heap->push(4);
        heap->print();
        std::cout << heap->pop() << "\n";
        std::cout << heap->pop() << "\n";
        std::cout << heap->pop() << "\n";
        std::cout << heap->pop() << "\n";
        std::cout << heap->pop() << "\n";
    } catch (exception const &ex) {
        cout << ex.what();
    }
}