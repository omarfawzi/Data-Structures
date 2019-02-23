#include "Nodes/DoubleLinkedListNode.h"

//
// Created by salama on 2/23/19.
//
template<typename T>

class DoubleLinkedList : public ListInterface<T> {
private :
    DoubleLinkedListNode<T> *head;
    DoubleLinkedListNode<T> *tail;
public:
    void insertLast(T item) override {
        DoubleLinkedListNode<T> * current = this->head;
    }

    void insertAfter(T item ,int index) override {
    }

    void insertFirst(T item) override {

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