#include "Nodes/DoubleLinkedListNode.h"

//
// Created by salama on 2/23/19.
//
template<typename T>

class DoubleLinkedList : public List<T> {
private :
    DoubleLinkedListNode<T> *head;
    DoubleLinkedListNode<T> *tail;
public:
    void push(T item) override {
        DoubleLinkedListNode<T> *newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void insertAfter(T item, int index) override {
        DoubleLinkedListNode<T> *newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        } else if (index > this->size / 2) {
            int i = this->size;
            DoubleLinkedListNode<T> *current = this->tail;
            while (current != nullptr) {
                if (index == i) {
                    newNode->prev = current;
                    newNode->next = current->next;
                    current->next = newNode;
                    break;
                }
                current = current->prev;
                i--;
            }
        } else {
            int i = 1;
            DoubleLinkedListNode<T> *current = this->head;
            while (current != nullptr) {
                if (index == i) {
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
        DoubleLinkedListNode<T> *newNode = new DoubleLinkedListNode<T>(item);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void update(int index, T updateValue) override {
        if (this->head == nullptr) {
            return;
        } else if (index > this->size / 2) {
            int i = this->size;
            DoubleLinkedListNode<T> *current = this->tail;
            while (current != nullptr) {
                if (index == i) {
                    current->data = updateValue;
                    break;
                }
                current = current->prev;
                i--;
            }
        } else {
            int i = 1;
            DoubleLinkedListNode<T> *current = this->head;
            while (current != nullptr) {
                if (index == i) {
                    current->data = updateValue;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        this->size++;
    }

    void pop() override {
        if (this->head == nullptr) {
            return;
        }
        if (this->head->next == nullptr) {
            this->head = nullptr;
            delete this->head;
        } else {
            DoubleLinkedListNode<T> *current = this->head;
            current->next->prev = nullptr;
            this->head = current->next;
            delete current;
        }
        this->size--;
    }

    void remove(int index) override {
        if (index < 1 || index > this->size)
            return;
        if (this->head == nullptr) {
            return;
        } else if (index == 1) {
            this->pop();
            return;
        } else if (index == this->size) {
            DoubleLinkedListNode<T> *current = this->tail;
            current->prev->next = nullptr;
            this->tail = current->prev;
        } else if (index > this->size / 2) {
            int i = this->size;
            DoubleLinkedListNode<T> *current = this->tail;
            while (current != nullptr) {
                if (index == i) {
                    //1 2 3
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    delete current;
                    break;
                }
                current = current->prev;
                i--;
            }
        } else {
            int i = 1;
            DoubleLinkedListNode<T> *current = this->head;
            while (current != nullptr) {
                if (index == i) {
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    delete current;
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

    int search(T value) override {
        if (this->head == nullptr)
            return -1;
        int i = 1;
        DoubleLinkedListNode<T> *current = this->head;
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