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


TEST(VeriableTest, VeriableTestToString) {
    vector<double> c1 = {0, 1, 2};
    vector<double> c2 = {0, 0, 3};

    Polynom p1(c1);
    Polynom p2(c2);
    LOG(INFO) << p1[1];
    auto result = Polynom::multiple(p1, p2);
    result.show();
}