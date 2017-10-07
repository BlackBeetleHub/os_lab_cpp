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
        timer->start();
        algorithm->execute();
        timer->end();
        LOG(INFO) << "Time: " << timer->show();
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

TEST_F(SpeedTest, ChronoTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<ChronoTimer>());
}

TEST_F(SpeedTest, RdtscTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<RdtscTimer>());
}

TEST_F(SpeedTest, OmpTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<OmpTimer>());
}