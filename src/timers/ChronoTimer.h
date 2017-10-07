//
// Created by kirill on 07.10.17.
//

#ifndef LAB_OS_1_CHRONOTIMER_H
#define LAB_OS_1_CHRONOTIMER_H


#include <chrono>
#include "Timer.h"

class ChronoTimer  : public Timer {
public:
    void start() final;
    void end() final;
    std::string show() final;

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
};


#endif //LAB_OS_1_CHRONOTIMER_H
