//
// Created by salama on 2/22/19.
//

#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include "DSInterface.h"
#include "LinkedList.h"

template<typename T>

class Factory {
public:
    DSInterface<T>* getDataStructure(const std::string &dataStructure) {
        if (dataStructure == "LinkedList") {
            return new LinkedList<T>();
        } else {
            throw std::out_of_range("Invalid DataStructure");
        }
    }
};

#endif //UNTITLED_FACTORY_H
