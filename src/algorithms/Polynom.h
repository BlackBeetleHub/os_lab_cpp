//
// Created by kirill on 15.10.17.
//

#ifndef LAB_OS_1_POLYNOM_H
#define LAB_OS_1_POLYNOM_H

#include <string>
#include <vector>
#include <stdexcept>
#include "Algorithm.h"
#include <boost/algorithm/string.hpp>

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <complex>
#include <easylogging++.h>

using namespace std;

class Polynom {
    typedef vector<double>* confs;
public:
    Polynom(vector<double> &c);
    double operator[](int index) {
        return (*c)[index];
    }

    size_t getLength() const {
        return c->size();
    }
    ~Polynom();
    static Polynom multiple(Polynom& a, Polynom& b);
    void show(){
        for (double item : *c){
            LOG(INFO) << item;
        }
    }

private:
    confs c;
};

#endif //LAB_OS_1_POLYNOM_H
