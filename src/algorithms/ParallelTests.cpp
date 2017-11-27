//
// Created by kirill on 06.10.17.
//

#include "timers/CommonTimer.h"
#include "timers/ChronoTimer.h"
#include "CustomArray.h"

#include <gtest/gtest.h>

// for
double getPIVallicy(double n) {
    double result = 1;
    for (double i = 1; i < n; i++) {
        result *= ((2 * i) * (2 * i)) / ((2 * i - 1) * (2 * i + 1));
    }
    return result * 2.0d;
}

double getPILeybnic(double n) {
    double result = 1;
    int k = 1;
    for (double i = 1; i < n; i++) {
        k = ((int) i % 2 == 0) ? 1 : -1;
        result += k / (2 * i + 1);
    }
    return result * 4.0d;
}

double getPILeybnicParallel(size_t size) {
    double res = 1;
#pragma omp parallel for reduction(+:res)
    for (int i = 1; i < size; i++) {
        if ( i % 2 == 0 ) {
            res += 1.0d / (2.0d * (double)i + 1.0d);
        }else {

            res -= 1.0d / (2.0d * (double)i + 1.0d);
        }
    }
    return res * 4.0d;
}

TEST(GetPITests, CommonMultipleGetPIVallicy) {
    double number = getPIVallicy(100000000);
    int w = 1, p = 19; // width and scale
    printf("%0*.*f\n", w, p, number);
}

TEST(GetPITests, CommonAdditionGetPILeybnic) {
    double number = getPILeybnic(100000000000);
    int w = 1, p = 19; // width and scale
    printf("%0*.*f\n", w, p, number);
}

TEST(GetPITests, ParallelOmpGeyPiLeybnic) {
    double number = getPILeybnicParallel(100000000000);
    int w = 1, p = 19; // width and scale
    printf("%0*.*f\n", w, p, number);
}

struct RangeInfo {
    int start;
    int end;
    double res = 0;
};

void* routines(void* args) {
    RangeInfo* info = (RangeInfo*)args;

    info->res = 0;

    double sign = (info->start % 2) == 0 ? 1.0d : -1.0d;

    for (int i = info->start; i < info->end; i++) {
        info->res += sign / (2.0d * (double) i + 1.0d);
        sign *= -1.0d;
    }
}

TEST(GetPITests, TestPthres) {
    int n = 10000000;
    int err = 0;
    int countThreads = 8;
    double res = 0;
    pthread_t* threads = new pthread_t[countThreads];
    RangeInfo* results = new RangeInfo[countThreads];

    for (int i = 0; i < countThreads; i++){
        results[i].start = (n / countThreads) * i;
        results[i].end = (n / countThreads) * (i + 1);
        err = pthread_create(&threads[i], nullptr, routines, (void*)&results[i]);
        if (err != 0) {
            throw std::runtime_error("cannot create thread");
        }
    }

    for(int i = 0; i < countThreads; i++){
        pthread_join(threads[i], nullptr);
    }

    for(int i = 0; i < countThreads; i++) {
        res += results[i].res;
    }

    res *= 4.0d;

    LOG(INFO) << res;

    delete [] results;
    delete [] threads;

}