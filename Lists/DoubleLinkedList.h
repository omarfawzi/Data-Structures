#include "Nodes/DoubleLinkedListNode.h"

//
// Created by salama on 2/23/19.
//
template<typename T>

class DoubleLinkedList : public ListInterface<T> {
private :
    DoubleLinkedListNode<T> *listNode;
public:
    void insert(T item) override {

    }

    void insertAfter(T item ,int index) override {

    }

    void update(int index, T updateValue) override {

    }

    void removeByIndex(int index) override {

    }

    void removeByValue(T value) override {

    }

    void print() override {

    }

    int getSize() override {
        return 0;
    }

    int getValueIndex(T value) override {
        return 0;
    }
};