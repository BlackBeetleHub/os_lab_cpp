//
// Created by kirill on 07.10.17.
//

#ifndef LAB_OS_1_OMPTIMER_H
#define LAB_OS_1_OMPTIMER_H


#include <omp.h>
#include "Timer.h"

class OmpTimer : public Timer {
public:
    void start() final;
    void end() final;
    std::string show() final;

private:
    double startTime;
    double endTime;
};

#endif //LAB_OS_1_OMPTIMER_H
