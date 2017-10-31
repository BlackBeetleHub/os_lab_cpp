//
// Created by kirill on 04.10.17.
//

#include <random>
#include "Sort.h"

void Sort::execute() {
    bubbleSort(array, size);
}

Sort::Sort(size_t size) : size(size) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = random() % size;
    }
}

Sort::~Sort() {
    delete[] array;
}

bool Sort::check() {
    return isSorted(array, size);
}

int sievePositives(int *unsievedArray, size_t length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        count += unsievedArray[i] >> 31;
    }
    return static_cast<int>(length + count);
}

void bubbleSort(int *array, size_t length) {
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

bool isSorted(int *array, size_t length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) return false;
    }
    return true;
}

void initRandomArray(int *array, size_t length) {
    int tmp = 0;
    for (int i = 0; i < length; i++) {
        tmp = rand() % 2*length;
        tmp -= length;
        array[i] = tmp;
    }
}
