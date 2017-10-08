//
// Created by kirill on 08.10.17.
//

#ifndef LAB_OS_1_MATRIX_H
#define LAB_OS_1_MATRIX_H

#include "easylogging++.h"
#include "Algorithm.h"


template <typename T>
class Matrix {
public:
    Matrix(size_t size);
    ~Matrix();

    Matrix<T> operator*(Matrix<T> const & second);
    void show();

private:
    T **m1;
    size_t sizeM1;
};

template <typename T>
T **multiply(T **first, size_t firstSize, T **second, size_t secondSize) {
    T **result = new T *[firstSize];
    for (int i = 0; i < firstSize; i++) {
        result[i] = new T[secondSize];

        for (int j = 0; j < secondSize; j++) {
            T resElement = 0;
            for (int r = 0; r < secondSize; r++) {
                resElement += first[i][r] * second[r][j];
            }
            result[i][j] = resElement;
        }
    }
    return result;
}

template <typename T>
void showMatrix(T **matrix, size_t size) {
    for (int i = 0; i < size; i++) {
        std::string resRow = "|";
        for (int j = 0; j < size; j++) {
            resRow += " " + std::to_string(matrix[i][j]);
        }
        LOG(INFO) << resRow + " |";
    }
}

template <typename T>
T **randomMatrix(size_t size) {
    T **result = new T *[size];
    for (int i = 0; i < size; i++) {
        result[i] = new T[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = rand() % size;
        }
    }
    return result;
}

template <typename T>
Matrix<T>::Matrix(size_t size) : sizeM1(size){
    m1 = randomMatrix<T>(size);
}

template <typename T>
Matrix<T>::~Matrix() {

}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> const& second) {
    Matrix<T> m(1);
    m.m1 = multiply<T>(this->m1, this->sizeM1, second.m1, second.sizeM1);
    m.sizeM1 = second.sizeM1;
    return m;
}

class SumArray : public Algorithm {
public:
    void execute();
    SumArray(size_t size);
    ~SumArray();
private:
    int *array;
    size_t size;
};

#endif //LAB_OS_1_MATRIX_H
