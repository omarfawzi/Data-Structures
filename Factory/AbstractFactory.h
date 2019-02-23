//
// Created by salama on 2/23/19.
//

#include <string>
#include <stdexcept>

template<typename T>

class AbstractFactory {
public:
    Factory<T> *getFactory(const std::string &factory) {
        if (factory == "List") {
            return new ListFactory<T>();
        } else {
            throw std::out_of_range("Invalid Factory type : " + factory);
        }
    }
};