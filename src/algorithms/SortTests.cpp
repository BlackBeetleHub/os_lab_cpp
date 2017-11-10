//
// Created by kirill on 06.10.17.
//

#include "test/Test.h"

#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/RdtscTimer.h"
#include "timers/OmpTimer.h"
#include "CustomArray.h"

TEST_F(Test, OmpTimerSort) {
    setCommands([](){std::cout<<"hello"<<std::endl;});
    setTimer(std::make_shared<OmpTimer>());
}


TEST_F(Test, OmpTimerSort1) {
    setCommands([](){
        CustomArray<int> a(4096*4096);
        CustomArray<int> b(4096*4096);
        CustomArray<int>::pointer c = a + b;
    });
    setTimer(std::make_shared<OmpTimer>());
}