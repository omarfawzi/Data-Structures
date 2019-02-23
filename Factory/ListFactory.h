//
// Created by salama on 2/22/19.
//

#include "../Linear/Lists/LinkedList.h"
#include "../Linear/Lists/DoubleLinkedList.h"
#include "Factory.h"

template<typename T>

class ListFactory : public Factory<T> {
public:
    ListInterface<T> *getList(const std::string &list) {
        if (list == "LinkedList") {
            return new LinkedList<T>();
        }
        if (list == "DoubleLinkedList") {
            return new DoubleLinkedList<T>();
        } else {
            throw std::out_of_range("Invalid List Type : " + list);
        }
    }
};