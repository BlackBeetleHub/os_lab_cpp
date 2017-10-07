//
// Created by kirill on 04.10.17.
//

#ifndef LAB_OS_1_CLOCKTIMER_H
#define LAB_OS_1_CLOCKTIMER_H


#include "Timer.h"

class ClockTimer : public Timer {
public:
    void start() final;
    void end() final;
    std::string show() final;

private:
    clock_t startTime;
    clock_t endTime;
};


#endif //LAB_OS_1_CLOCKTIMER_H
