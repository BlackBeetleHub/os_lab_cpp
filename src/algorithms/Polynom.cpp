//
// Created by kirill on 15.10.17.
//

#include "Polynom.h"
#include "Predictor.h"

Polynom::~Polynom() {

}


typedef complex<double> ci;
typedef vector<ci> pol;

pol FastTransform(const pol &as) {
    int n = as.size();

    if (n == 1) return pol(1, as[0]);

    pol w(n);
    for (int i = 0; i < n; i++) {
        double alpha = 2 * M_PI * i / n;
        w[i] = ci(cos(alpha), sin(alpha));
    }

    pol A(n / 2), B(n / 2);
    for (int i = 0; i < n / 2; i++) {
        A[i] = as[i * 2];
        B[i] = as[i * 2 + 1];
    }
    pol Av = FastTransform(A);
    pol Bv = FastTransform(B);
    pol res(n);
    for (int i = 0; i < n; i++)
        res[i] =   Av[i % (n / 2)] +
                   w[i] * Bv[i % (n / 2)];
    return res;
}

pol RevFastTransform(const pol &as) {
    pol res = FastTransform(as);
    for (int i = 0; i < (int)res.size(); i++) res[i] /= as.size();
    reverse(res.begin() + 1, res.end());
    return res;
}

Polynom Polynom::multiple(Polynom &a, Polynom &b) {

    size_t sizeA = a.getLength();
    size_t sizeB = b.getLength();

    std::vector<double> *res = new std::vector<double>(sizeA + sizeB);
    AddPredicate(1);
    AddPredicate(2);
    AddPredicate(3);
    AddPredicate(4);
    AddPredicate(5);

    for (int i = 0; CheckPredicate(1, i < sizeA); i++) {
        if (CheckPredicate(2, a[i] == 0.0)) {
            continue;
        }

        for (int j = 0; CheckPredicate(3, j < sizeB); j++) {
            if (CheckPredicate(4, b[j] == 0.0)) {
                continue;
            }
            if (CheckPredicate(5, (*res)[i + j] != 0.0)) {
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

