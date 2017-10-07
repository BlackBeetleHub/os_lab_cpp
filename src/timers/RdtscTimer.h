//
// Created by kirill on 07.10.17.
//

#ifndef LAB_OS_1_RDTSCTIMER_H
#define LAB_OS_1_RDTSCTIMER_H

#include "Timer.h"

class RdtscTimer  : public Timer {
public:
    void start() final;
    void end() final;
    std::string show() final;

private:
    uint64_t startTime;
    uint64_t endTime;
};
#endif //LAB_OS_1_RDTSCTIMER_H
