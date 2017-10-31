//
// Created by kirill on 06.10.17.
//

#include <gtest/gtest.h>
#include <memory>
#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/RdtscTimer.h"
#include "timers/OmpTimer.h"
#include "algorithms/Sort.h"
#include "Polynom.h"
#include "Predictor.h"

class SpeedTest : public ::testing::Test {
public:

    void setAlgorithm(std::shared_ptr<Algorithm> algorithm) {
        this->algorithm = algorithm;
    }

    void setTimer(std::shared_ptr<Timer> timer) {
        this->timer = timer;
    }

    virtual void SetUp() {}

    virtual void TearDown() {
        LOG(INFO) << "Start testing...";
        timer->start();
        algorithm->execute();
        timer->end();
        ASSERT_TRUE(algorithm->check());
        LOG(INFO) << "Time: " << timer->show();
    }

    std::shared_ptr<Algorithm> algorithm;
    std::shared_ptr<Timer> timer;
};

TEST_F(SpeedTest, OmpTimerSort) {
    setAlgorithm(std::make_shared<Sort>(1000));
    setTimer(std::make_shared<OmpTimer>());
}

TEST(PossitiveCountTest, PossitiveCount) {
    const int size = 1000;
    int *array = new int[size];
    initRandomArray(array, size);
    LOG(INFO) << sievePositives(array, size);
}

TEST(SortTests, BubbleSortTest) {
    const int size = 1000;
    int *array = new int[size];
    initRandomArray(array, size);
    bubbleSort(array, size);
    ASSERT_TRUE(isSorted(array, size));
}

void onlyTrue(){
    AddPredicate(1);
    AddPredicate(2);
    AddPredicate(3);
    for(int i = 0 ; CheckPredicate(1,i < 100); i++) {
        if(CheckPredicate(2, true)){

        }

        if(CheckPredicate(3, false)){

        }
    }
}

TEST(AdaptTests, ForTest) {

    onlyTrue();

    LOG(INFO) << Predictor::errors;
    LOG(INFO) << Predictor::success;

}

TEST(MultiplePolyTest, SimpleVersion) {
    vector<double> c1 = {1.0, 2.0, 1.0, 0.0, 1.0};
    vector<double> c2 = {0.0, 3.0, 0.0, 0.0, 1.0};
    Polynom p1(c1);
    Polynom p2(c2);
    LOG(INFO) << p1[1];
    auto result = Polynom::multiple(p1, p2);
    result.show();
    LOG(INFO) << Predictor::errors;
    LOG(INFO) << Predictor::success;

}


TEST(MultiplePolyTest, Faster) {
    vector<complex<double>> c1 = {3.0, 1.0, 1.0};
    vector<complex<double>> c2 = {1.0, 3.0, 3.0};

    auto a = FastTransform(c1);
    auto b = FastTransform(c2);

    vector<complex<double>> c(a.size());

    for (int i = 0; i < a.size(); i++)
        c[i] = a[i] * b[i];

    auto rc = RevFastTransform(c);

    for (auto item : rc){
        LOG(INFO) << item;
    }
}