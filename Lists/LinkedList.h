//
// Created by salama on 2/22/19.
//
#include "../Interface/ListInterface.h"
#include "Nodes/LinkedListNode.h"

template<typename T>

class LinkedList : public ListInterface<T> {
private:
    LinkedListNode<T> *listNode;
public:
    void insert(T item) override {
        LinkedListNode<T> *current = this->listNode;
        if (current == nullptr) {
            this->listNode = new LinkedListNode<T>(item);
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new LinkedListNode<T>(item);
        }
        this->size++;
    }

    void insertAfter(T item, int index) override {
        if (index < 1)
            return;
        if (index >= this->size)
            this->insert(item);
        else {
            int i = 1 ;
            LinkedListNode<T> *current = this->listNode;
            while (current != nullptr) {
                if (index == i){
                    LinkedListNode<T> *temp = current->next;
                    current->next = new LinkedListNode<T>(item);
                    current->next->next = temp;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        this->size++;
    }

    void update(int index, T updateValue) override {
        if (this->size == 0)
            return;
        int i = 0;
        LinkedListNode<T> *current = this->listNode;
        while (current != nullptr) {
            if (index - 1 == i) {
                current->data = updateValue;
                break;
            }
            current = current->next;
            i++;
        }
    }

    void removeByValue(T value) override {
        if (this->size == 0)
            return;
        int i = 0;
        LinkedListNode<T> *current = this->listNode;
        if (this->size == 1) {
            delete this->listNode;
        } else if (value == this->listNode->data) {
            this->listNode = this->listNode->next;
        } else {
            LinkedListNode<T> *prev = current;
            while (current != nullptr) {
                if (current->data == value) {
                    prev->next = current->next;
                    break;
                }
                prev = current;
                current = current->next;
                i++;
            }
        }
        this->size--;
    }

    void removeByIndex(int index) override {
        if (this->size == 0 || index > this->size)
            return;
        int i = 0;
        LinkedListNode<T> *current = this->listNode;
        if (this->size == 1) {
            delete this->listNode;
        } else if (index == 1) {
            this->listNode = this->listNode->next;
        } else {
            while (current != nullptr) {
                if (index - 1 == i + 1) {
                    current->next = current->next->next;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        this->size--;
    }

    void print() override {
        if (this->size == 0)
            return;
        LinkedListNode<T> *current = this->listNode;
        if (this->size == 1) {
            std::cout << this->listNode->data;
        } else {
            while (current->next != nullptr) {
                std::cout << current->data << "->";
                current = current->next;
            }
            std::cout << current->data;
        }
        std::cout << "\n";
    }

    int getValueIndex(T value) override {
        if (this->size == 0)
            return -1;
        int i = 1;
        LinkedListNode<T> *current = this->listNode;
        int searchResult = -1;
        while (current != nullptr) {
            if (current->data == value) {
                searchResult = i;
                break;
            }
            current = current->next;
            i++;
        }
        return searchResult;
    }

    int getSize() override {
        return this->size;
    }
};