//
// Created by kirill on 07.10.17.
//

#include "ChronoTimer.h"

void ChronoTimer::start() {
    startTime =  std::chrono::high_resolution_clock::now();
}

void ChronoTimer::end() {
    endTime =  std::chrono::high_resolution_clock::now();
}

std::string ChronoTimer::show() {
    auto tmp = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    return std::to_string(tmp.count()) + " nanoseconds";
}
