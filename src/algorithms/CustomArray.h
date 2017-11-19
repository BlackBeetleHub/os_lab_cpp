//
// Created by kirill on 10.11.17.
//

#ifndef LAB_OS_1_CUSTOMARRAY_H
#define LAB_OS_1_CUSTOMARRAY_H

#include <cstddef>
#include <random>
#include <memory>
#include <easylogging++.h>
#include <timers/OmpTimer.h>

template<typename T>
class CustomArray {
public:
    explicit CustomArray(size_t size) : size(size) {
        array = new T[size];
    }

    void randInit(){
        for (int i = 0; i < size; i++) {
            array[i] = random() % 10000;
        }
    }

    typedef std::shared_ptr<CustomArray<T>> pointer;

    pointer operator+(CustomArray& second) {
        pointer result = std::make_shared<CustomArray<T>>(second.size);
        timer->start();
        for (int i = 0; i < second.size; i++) {
            result->array[i] = second[i] + (*this)[i];
        }
        timer->end();
        LOG(INFO) << timer->show();
        return result;
    }

    template<typename S>
    pointer SIMDAddition(CustomArray& second, S (*add)(S,S)) {
        if(second.size != this->size) {
            throw std::runtime_error("array not equal size");
        }
        auto *ma = (S*)second.array;
        auto *mb = (S*)this->array;
        pointer result = std::make_shared<CustomArray<T>>(second.size);
        size_t del = sizeof(T);
        size_t len = second.size / (16 / del);
        auto *mout = new S[len];
        timer->start();
        for (int i = 0; i < len; i++) {
            mout[i] = add(ma[i], mb[i]);
        }
        timer->end();
        LOG(INFO) << timer->show();
        result->array = (T*)mout;
        return result;
    }

    pointer fastSIMDAddition(CustomArray& second){
        if(second.size != this->size) {
            throw std::runtime_error("array not equal size");
        }
        __m128i *ma = (__m128i*)second.array;
        __m128i *mb = (__m128i*)this->array;
        pointer result = std::make_shared<CustomArray<T>>(second.size);
        size_t del = sizeof(T);
        size_t len = second.size / (16 / del);
        __m128i *mout = new __m128i[len];
        timer->start();
        for (int i = 0; i < len; i++) {
            mout[i] = _mm_add_epi64(ma[i], mb[i]);
        }
        timer->end();
        LOG(INFO) << timer->show();
        result->array = (T*)mout;
        return result;
    }

    pointer Sqrt(){
        pointer result = std::make_shared<CustomArray<T>>(size);
        timer->start();
        for (int i = 0; i < size; i++) {
            result->array[i] = sqrt((*this)[i]);
        }
        timer->end();
        LOG(INFO) << timer->show();
        return result;
    }

    template<typename S>
    pointer SIMDSqrt(S (*sqrt_mm)(S)) {
        auto *ma = (S*)this->array;
        pointer result = std::make_shared<CustomArray<T>>(size);
        size_t del = sizeof(T);
        size_t len = size / (16 / del);
        auto *mout = new S[len];
        timer->start();
        for (int i = 0; i < len; i++) {
            mout[i] = sqrt_mm(ma[i]);
        }
        timer->end();
        LOG(INFO) << timer->show();
        result->array = (T*)mout;
        return result;
    }

    T getSum(){
        T res = 0;
        for(size_t i = 0; i < this->size; i++) {
            res+= (*this)[i];
        }
        return res;
    }


    T operator[](int index) {
        return this->array[index];
    }

    ~CustomArray() {
        delete[] array;
    }

private:
    T *array;
    size_t size;
    std::shared_ptr<Timer> timer = std::make_shared<OmpTimer>();
};


#define SHL128(v, n) \
({ \
    __m128i v1, v2; \
 \
    if ((n) >= 64) \
    { \
        v1 = _mm_slli_si128(v, 8); \
        v1 = _mm_slli_epi64(v1, (n) - 64); \
    } \
    else \
    { \
        v1 = _mm_slli_epi64(v, n); \
        v2 = _mm_slli_si128(v, 8); \
        v2 = _mm_srli_epi64(v2, 64 - (n)); \
        v1 = _mm_or_si128(v1, v2); \
    } \
    v1; \
})

#define SHR128(v, n) \
({ \
    __m128i v1, v2; \
 \
    if ((n) >= 64) \
    { \
        v1 = _mm_srli_si128(v, 8); \
        v1 = _mm_srli_epi64(v1, (n) - 64); \
    } \
    else \
    { \
        v1 = _mm_srli_epi64(v, n); \
        v2 = _mm_srli_si128(v, 8); \
        v2 = _mm_slli_epi64(v2, 64 - (n)); \
        v1 = _mm_or_si128(v1, v2); \
    } \
    v1; \
})


#endif //LAB_OS_1_CUSTOMARRAY_H
