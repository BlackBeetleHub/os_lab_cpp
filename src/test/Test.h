//
// Created by kirill on 08.11.17.
//

#ifndef LAB_OS_1_TEST_H
#define LAB_OS_1_TEST_H


#include <functional>
#include <gtest/gtest.h>

#include <timers/Timer.h>

class Test: public ::testing::Test {
public:

    void SetUp() override {}

    void TearDown() override;

    void setTimer(std::shared_ptr<Timer> timer);

    void setCommands(std::function<void()> commands);

private:
    std::function<void()> commands;
    std::shared_ptr<Timer> timer;
};

#endif //LAB_OS_1_TEST_H
