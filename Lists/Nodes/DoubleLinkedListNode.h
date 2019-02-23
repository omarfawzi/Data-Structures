//
// Created by salama on 2/23/19.
//

template<typename T>

struct DoubleLinkedListNode {
public:

    DoubleLinkedListNode<T>(T data) {
        this->data = data;
    }

    T data;
    struct DoubleLinkedListNode *next;
    struct DoubleLinkedListNode *prev;

};