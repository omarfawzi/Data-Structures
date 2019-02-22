//
// Created by salama on 2/22/19.
//

template<typename T>

class DSInterface {
protected:
    int size = 0 ;
public:
    virtual void insert(T item) = 0;

    virtual void update(int index , T updateValue) = 0;

    virtual void removeByIndex(int index) = 0;

    virtual void removeByValue(T value) = 0;

    virtual void print() = 0;

    virtual int getSize() = 0;

    virtual int getValueIndex(T value) = 0;
};