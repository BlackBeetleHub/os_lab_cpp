//
// Created by kirill on 06.10.17.
//

#include <gtest/gtest.h>
#include <memory>
#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "algorithms/Sort.h"
#include "easylogging++.h"

class SpeedTest : public ::testing::Test {
public:

    void setAlgorithm(std::shared_ptr<Algorithm> algorithm){
        this->algorithm = algorithm;
    }

    void setTimer(std::shared_ptr<Timer> timer){
        this->timer = timer;
    }

    virtual void SetUp() { }

    virtual void TearDown() {
        LOG(INFO) << "Start testing...";
        time_t start = timer->start();
        algorithm->execute();
        time_t end =  timer->end();
        LOG(INFO) << "Time: " << end - start;
    }

    std::shared_ptr<Algorithm> algorithm;
    std::shared_ptr<Timer> timer;
};

TEST_F(SpeedTest, ClockTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<ClockTimer>());
}

TEST_F(SpeedTest, CommonTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<CommonTimer>());
}