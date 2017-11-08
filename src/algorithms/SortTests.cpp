//
// Created by kirill on 06.10.17.
//

#include "test/Test.h"

#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/RdtscTimer.h"
#include "timers/OmpTimer.h"

TEST_F(Test, OmpTimerSort) {
    setCommands([](){std::cout<<"hello"<<std::endl;});
    setTimer(std::make_shared<OmpTimer>());
}