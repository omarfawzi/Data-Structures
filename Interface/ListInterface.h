//
// Created by salama on 2/23/19.
//

#include "DSInterface.h"
#include "../Lists/ListNode.h"

template<typename T>

class ListInterface : public DSInterface<T> {
protected:
    ListNode<T> *listNode;
public:

    virtual void update(int index, T updateValue) = 0;

    virtual void removeByIndex(int index) = 0;

    virtual void removeByValue(T value) = 0;

    virtual int getValueIndex(T value) = 0;
};
