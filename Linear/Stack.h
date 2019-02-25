template<class T , typename scalar>

class Stack {
private:
    T *list;
public:
    Stack()
    {
       list = new T;
    }

    void push(scalar item){
        list->insertFirst(item);
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