#include <iostream>

template<typename T>

class MinHeap : public Heap<T> {
public:
    explicit MinHeap(int size) {
        this->size = size;
        this->heap = new T[size];
        this->replaceValue = INT_MIN;
    }

    void siftUp(int index) override {
        int parentIndex = this->parent(index);
        if (parentIndex < 0)
            return;
        T parent = this->heap[parentIndex];
        T item = this->heap[index];
        if (item < parent) {
            std::swap(this->heap[index], this->heap[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void heapify(int i) override {
        int smallest = i;
        int left = this->left(i);
        int right = this->right(i);
        if (left < this->cursor && this->heap[left] < this->heap[i])
            smallest = left;
        if (right < this->cursor && this->heap[right] < this->heap[smallest])
            smallest = right;
        if (smallest != i) {
            std::swap(this->heap[smallest], this->heap[i]);
            heapify(smallest);
        }
    }
};