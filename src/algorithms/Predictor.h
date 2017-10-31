//
// Created by kirill on 29.10.17.
//

#ifndef LAB_OS_1_PREDICTOR_H
#define LAB_OS_1_PREDICTOR_H

#include <set>
#include <vector>

const int TT = 0;
const int TN = 1;
const int NN = 2;
const int NT = 3;

class Predictor {
public:

    Predictor () = default;

    static int errors;
    static int success;

    static std::vector<int > table;
};

void AddPredicate(int index);
bool CheckPredicate(int index, bool predict);

#endif //LAB_OS_1_PREDICTOR_H
