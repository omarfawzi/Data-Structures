//
// Created by salama on 2/23/19.
//

#include <string>

template<typename T>

class Factory {
public:
    virtual ListInterface<T> *getList(const std::string &list) = 0;
};


