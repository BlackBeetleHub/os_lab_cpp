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

class Veriable {
public:
    Veriable(std::string name, int exponent) : name(name), exponent(exponent) {
    }

    int exponent;
    std::string name;

    std::string toString() {
        std::string res = name;
        if(exponent != 1){
            res += "^" +std::to_string(exponent);
        }
        return res;
    }
};


class Monomial {

public:
    Monomial(int c, std::string str) : c(c) {
        for (int i = 0; i < str.size(); i++) {

            int ex = 1;

            if ((i + 2) >= str.size()) {
                veriables.push_back(Veriable(&str[i], 1));
                return;
            }

            if (isalpha(str[i])) {
                if (isdigit(str[i + 2])) {
                    veriables.push_back(Veriable(&str[i], atoi(&str[i + 2])));
                    i += 2;
                }else{
                    veriables.push_back(Veriable(&str[i], 1));
                }

            }

        }
    }

    std::string toString() {
        std::string res = std::to_string(c);
        for (auto v : veriables) {
            res += v.toString();
        }
        return res;
    }

    int c;
    std::vector<Veriable> veriables;
};


class Polynom {
public:
    void addMonomial(Monomial monomial) {
        monomials.push_back(monomial);
    }

    std::string toString() {
        std::string res;
        for (auto item : monomials) {
            res += item.toString() + " ";
        }
        return res;
    }

private:
    std::vector<Monomial> monomials;
};

#endif //LAB_OS_1_POLYNOM_H
