//
// Created by salama on 2/22/19.
//
#include "List.h"
#include "Nodes/LinkedListNode.h"

template<typename T>

class LinkedList : public List<T> {
private:
    LinkedListNode<T> *head;
public:
    void push(T item) override {
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
            this->push(item);
            return ;
        }
        LinkedListNode<T> *first = new LinkedListNode<T>(item);
        first->next = this->head;
        this->head = first;
        this->size++;
    }

    void insertAfter(T item, int index) override {
        if (this->head == nullptr) {
            this->push(item);
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

    void pop() override {
        if (this->head == nullptr) {
            return;
        }
        if (this->head->next == nullptr) {
            this->head = nullptr;
            delete this->head;
        }
        else {
            this->head = this->head->next;
        }
        this->size--;
    }

    void remove(int index) override {
        if (index < 1 || index > this->size)
            return;
        if (this->head == nullptr) {
            return ;
        }
        int i = 0;
        LinkedListNode<T> *current = this->head;
        if (this->head->next == nullptr) {
            this->head = nullptr;
            delete this->head;
        } else if (index == 1) {
            this->pop();
            return;
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

    int search(T value) override {
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
};