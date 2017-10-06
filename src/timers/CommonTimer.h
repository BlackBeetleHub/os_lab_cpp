//
// Created by kirill on 04.10.17.
//

#ifndef LAB_OS_1_COMMONTIMER_H
#define LAB_OS_1_COMMONTIMER_H

#include <time.h>

#include "Timer.h"

class CommonTimer : public Timer {
public:
    int start() final;
    int end() final;
};


#endif //LAB_OS_1_COMMONTIMER_H
