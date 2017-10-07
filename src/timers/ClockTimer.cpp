//
// Created by kirill on 04.10.17.
//

#include <ctime>
#include "ClockTimer.h"

void ClockTimer::start() {
    startTime = clock();
}

void ClockTimer::end() {
    endTime = clock();
}

std::string ClockTimer::show() {
    return std::to_string(endTime - startTime) + " microseconds";
}
