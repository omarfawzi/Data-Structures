#include <string>
#include "../NonLinear/Heap/Heap.h"
#include "../NonLinear/Heap/MinHeap.h"
#include "../NonLinear/Heap/MaxHeap.h"

template<typename T>

class HeapFactory {
public:
    Heap<T> *getHeap(const std::string &heap, int size) {
        if (heap == "MinHeap") {
            return new MinHeap<T>(size);
        } else if (heap == "MaxHeap") {
            return new MaxHeap<T>(size);
        } else {
            throw std::out_of_range("Invalid Heap Type : " + heap);
        }
    }
};