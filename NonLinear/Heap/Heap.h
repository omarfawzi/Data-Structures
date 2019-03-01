template<typename T>

class Heap {
protected:
    T *heap;
    int size = 0;
public:
    Heap() = default;

    Heap(T *heap, int size) {
        this->heap = new T(size);
        this->size = size;
    }

    virtual void push(T item) = 0;

    virtual void pop(T item) = 0;

    virtual void heapify() = 0;

    virtual int search(T item) = 0;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }
};