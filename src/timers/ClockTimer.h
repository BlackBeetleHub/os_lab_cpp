//
// Created by kirill on 04.10.17.
//

#ifndef LAB_OS_1_CLOCKTIMER_H
#define LAB_OS_1_CLOCKTIMER_H


#include "Timer.h"

class ClockTimer : public Timer {
public:
    int start() final;
    int end() final;
};


#endif //LAB_OS_1_CLOCKTIMER_H
