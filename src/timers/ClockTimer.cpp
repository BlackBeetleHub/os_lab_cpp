//
// Created by kirill on 04.10.17.
//

#include <ctime>
#include "ClockTimer.h"

int ClockTimer::start() {
    clock_t c = clock();
    return c;
}

int ClockTimer::end() {
    clock_t c = clock();
    return c;
}
