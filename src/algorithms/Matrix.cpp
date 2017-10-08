//
// Created by kirill on 08.10.17.
//

#include "Matrix.h"





void SumArray::execute() {
    long long res = 0;
    for(int i = 0; i < size; i++){
        res += array[i];
    }
}

SumArray::SumArray(size_t size) : size(size) {
    array = new int[size];
    for(int i = 0; i < size; i++){
        array[i] = random() % size;
    }
}

SumArray::~SumArray() {
    delete[] array;
}

