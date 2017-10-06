//
// Created by kirill on 04.10.17.
//

#ifndef LAB_OS_1_SORT_H
#define LAB_OS_1_SORT_H


#include <ctime>
#include "Algorithm.h"

class Sort : public Algorithm {
public:
    Sort(size_t size);
    ~Sort();
    void execute() final;
private:
    int *array;
    size_t size;
};


#endif //LAB_OS_1_SORT_H
