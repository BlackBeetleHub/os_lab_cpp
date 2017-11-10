//
// Created by kirill on 10.11.17.
//

#ifndef LAB_OS_1_CUSTOMARRAY_H
#define LAB_OS_1_CUSTOMARRAY_H

#include <cstddef>
#include <random>
#include <memory>

template<typename T>
class CustomArray {
public:
    explicit CustomArray(size_t size) : size(size) {
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = random() % 100;
        }
    }

    typedef std::shared_ptr<CustomArray<T>> pointer;

    pointer operator+(CustomArray& second) {
        pointer result = std::make_shared<CustomArray<T>>(second.size);
        for (int i = 0; i < second.size; i++) {
            result->array[i] = second[i] + (*this)[i];
        }
        return result;
    }

    T operator[](int index) {
        return this->array[index];
    }

    ~CustomArray() {
        delete[] array;
    }

private:
    T *array;
    size_t size;
};


#endif //LAB_OS_1_CUSTOMARRAY_H
