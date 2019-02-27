template<class T , typename scalar>

class Queue {
private:
    T *list;
public:
    Queue()
    {
        list = new T;
    }

    void push(scalar item){
        list->push(item);
    }

    void pop()
    {
        list->pop();
    }

    void print()
    {
        list->print();
    }

};