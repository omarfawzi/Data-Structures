template<typename T>

class ListInterface {
protected:
    int size = 0;
public:

    virtual void update(int index, T updateValue) = 0;

    virtual void remove(int index) = 0;

    virtual int search(T value) = 0;

    virtual void insertAfter(T item, int index) = 0;

    virtual void insertFirst(T item) = 0;

    virtual void push(T item) = 0;

    virtual void pop() = 0;

    virtual void print() = 0;

    int getSize() {
        return this->size;
    };

};
