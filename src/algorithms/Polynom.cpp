//
// Created by kirill on 15.10.17.
//

#include "Polynom.h"

Polynom::~Polynom() {

}

Polynom Polynom::multiple(Polynom &a, Polynom &b) {

    size_t sizeA = a.getLength();
    size_t sizeB = b.getLength();

    std::vector<double> *res = new std::vector<double>(sizeA + sizeB);

    for (int i = 0; i < sizeA; i++) {
        if (a[i] == 0) {
            continue;
        }

        for (int j = 0; j < sizeB; j++) {
            if (b[j] == 0) {
                continue;
            }
            if ((*res)[i + j] != 0) {
                (*res)[i + j] += a[i] * b[j];
            } else {
                (*res)[i + j] = a[i] * b[j];
            }
        }
    }

    return Polynom(*res);
}

Polynom::Polynom(vector<double> &c) {
    this->c = &c;
}
