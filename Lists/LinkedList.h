//
// Created by salama on 2/22/19.
//
#include "../Interface/ListInterface.h"
#include "Nodes/LinkedListNode.h"

template<typename T>

class LinkedList : public ListInterface<T> {
private:
    LinkedListNode<T> *head;
public:
    void insertLast(T item) override {
        LinkedListNode<T> *current = this->head;
        if (current == nullptr) {
            this->head = new LinkedListNode<T>(item);
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new LinkedListNode<T>(item);
        }
        this->size++;
    }

    void insertFirst(T item) override {
        if (this->head == nullptr) {
            this->insertLast(item);
            return ;
        }
        LinkedListNode<T> *first = new LinkedListNode<T>(item);
        first->next = this->head;
        this->head = first;
        this->size++;
    }

    void insertAfter(T item, int index) override {
        if (this->head == nullptr) {
            this->insertLast(item);
            return ;
        }
        int i = 1;
        LinkedListNode<T> *current = this->head;
        while (current != nullptr) {
            if (index == i) {
                LinkedListNode<T> *temp = current->next;
                current->next = new LinkedListNode<T>(item);
                current->next->next = temp;
                break;
            }
            current = current->next;
            i++;
        }
        this->size++;
    }

    void update(int index, T updateValue) override {
        if (this->head == nullptr) {
            return ;
        }
        int i = 0;
        LinkedListNode<T> *current = this->head;
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
        LinkedListNode<T> *current = this->head;
        if (this->size == 1) {
            delete this->head;
        } else if (value == this->head->data) {
            this->head = this->head->next;
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
        if (this->head == nullptr) {
            return ;
        }
        int i = 0;
        LinkedListNode<T> *current = this->head;
        if (this->size == 1) {
            delete this->head;
        } else if (index == 1) {
            this->head = this->head->next;
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
        if (this->head == nullptr)
            return;
        LinkedListNode<T> *current = this->head;
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

    int getValueIndex(T value) override {
        if (this->head == nullptr) {
            return -1 ;
        }
        int i = 1;
        LinkedListNode<T> *current = this->head;
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