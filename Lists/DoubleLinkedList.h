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
        DoubleLinkedListNode<T> * newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr){
            this->head = newNode ;
            this->tail = newNode ;
        }else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void insertAfter(T item ,int index) override {
        DoubleLinkedListNode<T> * newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr){
            this->head = newNode ;
            this->tail = newNode ;
        }
        else if (index > this->size / 2){
            int i = this->size;
            DoubleLinkedListNode<T> * current = this->tail;
            while (current != nullptr)
            {
                if (index == i){
                    newNode->prev = current;
                    newNode->next = current->next;
                    current->next = newNode;
                    break;
                }
                current = current->prev;
                i--;
            }
        }else {
            int i = 1;
            DoubleLinkedListNode<T> * current = this->head;
            while (current != nullptr)
            {
                if (index == i){
                    newNode->prev = current;
                    newNode->next = current->next;
                    current->next = newNode;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        this->size++;

    }

    void insertFirst(T item) override {
        DoubleLinkedListNode<T> * newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr){
            this->head = newNode ;
            this->tail = newNode ;
        }
        else {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void update(int index, T updateValue) override {

    }

    void removeByIndex(int index) override {

    }

    void removeByValue(T value) override {

    }

    void print() override {
        if (this->head == nullptr)
            return;
        DoubleLinkedListNode<T> *current = this->head;
        if (this->size == 1) {
            std::cout << this->head->data;
        } else {
            while (current->next != nullptr) {
                std::cout << current->data << "->";
                current = current->next;
            }
            std::cout << current->data;
        }
        std::cout << "\n";
    }

    int getSize() override {
        return 0;
    }

    int getValueIndex(T value) override {
        return 0;
    }
};