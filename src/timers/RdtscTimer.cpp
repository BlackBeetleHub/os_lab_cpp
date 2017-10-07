//
// Created by kirill on 07.10.17.
//

#include <x86intrin.h>
#include "RdtscTimer.h"

void RdtscTimer::start() {
    startTime = __rdtsc();
}

void RdtscTimer::end() {
    endTime = __rdtsc();
}

std::string RdtscTimer::show() {
    return std::to_string(endTime - startTime) + " ticks";
}
