//
// Created by salama on 2/23/19.
//

#include "DSInterface.h"

template<typename T>

class ListInterface : public DSInterface<T> {

public:

    virtual void update(int index, T updateValue) = 0;

    virtual void remove(int index) = 0;

    virtual int search(T value) = 0;

    virtual void insertAfter(T item , int index) = 0;

    virtual void insertFirst(T item) = 0;

};
