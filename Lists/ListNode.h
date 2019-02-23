//
// Created by salama on 2/23/19.
//

template<typename T>

struct ListNode {
public:

    ListNode() {

    }

    ListNode<T>(T data) {
        this->data = data;
    }

    T data;
    struct ListNode *next;
};
