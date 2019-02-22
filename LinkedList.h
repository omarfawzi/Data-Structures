//
// Created by salama on 2/22/19.
//
template<typename T>

struct node {
public:
    explicit node<T>(T data) {
        this->data = data;
    }

    T data;
    struct node *next;
};

template<typename T>

class LinkedList : public DSInterface<T> {
private:
    node<T> *list;
public:
    void insert(T item) override {
        node<T> *current = list;
        if (current == nullptr) {
            list = new node<T>(item);
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new node<T>(item);
        }
        this->size++;
    }

    void update(int index, T updateValue) override {
        if (this->size == 0)
            return;
        int i = 0;
        node<T> *current = list;
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
        node<T> *current = list;
        if (this->size == 1) {
            delete list;
        } else if (value == list->data) {
            list = list->next;
        } else {
            node<T> *prev = current;
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
        node<T> *current = list;
        if (this->size == 1) {
            delete list;
        } else if (index == 1) {
            list = list->next;
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
        node<T> *current = list;
        if (this->size == 1) {
            std::cout << list->data;
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
        node<T> *current = list;
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