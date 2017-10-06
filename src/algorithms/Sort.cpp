//
// Created by kirill on 04.10.17.
//

#include <random>
#include "Sort.h"

void Sort::execute() {
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i-1;

        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}

Sort::Sort(size_t size) : size(size) {
    array = new int[size];
    for(int i = 0; i < size; i++){
        array[i] = random();
    }
}

Sort::~Sort() {
    delete[] array;
}
