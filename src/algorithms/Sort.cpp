//
// Created by kirill on 04.10.17.
//

#include <random>
#include "Sort.h"

void Sort::execute() {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

Sort::Sort(size_t size) : size(size) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = random();
    }
}

Sort::~Sort() {
    delete[] array;
}

int sievePositives(int *unsievedArray, size_t length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (unsievedArray[i] > 0) count++;
    }

    return count;
}

void bubbleSort(int *array, size_t length) {
    int temp;
    for(int i = 0; i < length; i++) {
        for (int j = 0; j < length - (i+1); j++) {
            if (array[i] < array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

bool isSorted(int *array, size_t length) {
    for (int i = 0; i < length-1; i++) {
        if(array[i] > array[i+1]) return false;
    }
    return true;
}

void initRandomArray(int *array, size_t length) {
    for(int i = 0; i < length; i++) {
        array[i] = rand() % length;
    }
}
