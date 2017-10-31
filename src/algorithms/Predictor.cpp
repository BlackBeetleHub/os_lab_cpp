//
// Created by kirill on 29.10.17.
//

#include "Predictor.h"

std::vector<int> Predictor::table = std::vector<int>(100);

int Predictor::errors = 0;
int Predictor::success = 0;

void AddPredicate(int index){
    Predictor::table[index] = TT;
}

bool CheckPredicate(int index, bool predict){

    if(Predictor::table[index] == TT) {
        if (predict) {
            Predictor::success += 1;
            return predict;
        }
        Predictor::errors += 1;
        Predictor::table[index] = TN;
        return predict;
    }

    if(Predictor::table[index] == TN) {
        if (!predict) {
            Predictor::success += 1;
            Predictor::table[index] = NN;
            return predict;
        }
        Predictor::errors += 1;
        Predictor::table[index] = TT;
        return predict;
    }

    if(Predictor::table[index] == NT) {
        if (predict) {
            Predictor::success += 1;
            Predictor::table[index] = TT;
            return predict;
        }
        Predictor::errors += 1;
        Predictor::table[index] = TN;
        return predict;
    }
    if(Predictor::table[index] == NN) {
        if (!predict) {
            Predictor::success += 1;
            return predict;
        }
        Predictor::errors += 1;
        Predictor::table[index] = NT;
        return predict;
    }
}