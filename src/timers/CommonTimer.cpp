//
// Created by kirill on 04.10.17.
//

#include "CommonTimer.h"

void CommonTimer::start() {
    startTime = time(0);
}

void CommonTimer::end() {
    endTime = time(0);
}

std::string CommonTimer::show() {
    return std::to_string(endTime - startTime) + " seconds";
}
