template<typename T>

class MaxHeap : public Heap<T> {
public:
    explicit MaxHeap(int size) {
        this->size = size;
        this->heap = new T[size];
    }

    T pop() override {
        if (this->cursor == 0) {
            return INT_MIN;
        }
        if (this->cursor == 1) {
            this->cursor--;
            return this->heap[0];
        }
        T root = this->heap[0];
        this->heap[0] = this->heap[this->cursor - 1];
        this->cursor--;
        this->heapify(0);
        return root;
    }

    void siftUp(int index) override {
        int parentIndex = this->parent(index);
        if (parentIndex < 0)
            return;
        T parent = this->heap[parentIndex];
        T item = this->heap[index];
        if (item > parent) {
            std::swap(this->heap[index], this->heap[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void heapify(int i) override {
        int largest = i;
        int left = this->left(i);
        int right = this->right(i);
        if (left < this->cursor && this->heap[left] > this->heap[i])
            largest = left;
        if (right < this->cursor && this->heap[right] > this->heap[largest])
            largest = right;
        if (largest != i) {
            std::swap(this->heap[largest], this->heap[i]);
            heapify(largest);
        }
    }
};