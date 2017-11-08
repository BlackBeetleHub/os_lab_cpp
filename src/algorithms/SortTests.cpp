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
#include "Algorithm.h"


class SpeedTest : public ::testing::Test {
public:

    void setCommands(std::function<void()> commands) {
        this->commands = commands;
    }

    void setTimer(std::shared_ptr<Timer> timer) {
        this->timer = timer;
    }

    virtual void SetUp() {}

    virtual void TearDown() {
        LOG(INFO) << "Start testing...";
        timer->start();
        commands();
        timer->end();
        LOG(INFO) << "Time: " << timer->show();
    }

    std::function<void()> commands;
    std::shared_ptr<Timer> timer;
};

TEST_F(SpeedTest, OmpTimerSort) {
    setCommands([](){std::cout<<"hello"<<std::endl;});
    setTimer(std::make_shared<OmpTimer>());
}
