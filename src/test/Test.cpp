//
// Created by kirill on 08.11.17.
//

#include "Test.h"

void Test::setCommands(std::function<void()> commands) {
    this->commands = commands;
}

void Test::setTimer(std::shared_ptr<Timer> timer) {
    this->timer = timer;
}

void Test::TearDown() {
    LOG(INFO) << "Start testing...";
    timer->start();
    commands();
    timer->end();
    LOG(INFO) << "Time: " << timer->show();
}
