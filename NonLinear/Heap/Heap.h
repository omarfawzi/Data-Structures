template<typename T>

class Heap {
protected:
    T *heap;
    int size = 0;
    int cursor = 0;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

public:
    Heap() = default;

    void push(T item) {
        this->heap[this->cursor] = item;
        this->cursor++;
        siftUp(this->cursor - 1);
    };

    virtual T pop() = 0;

    virtual void siftUp(int index) = 0;

    virtual void heapify(int i) = 0;

    void remove(int i) {
        this->replace(i, INT_MIN);
        this->pop();
    }

    void replace(int i, T item) {
        this->heap[i] = item;
        siftUp(i);
    }

    void print() {
        for (int i = 0; i < this->cursor; i++) {
            std::cout << this->heap[i] << ' ';
        }
        std::cout << "\n";
    }
};