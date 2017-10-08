//
// Created by kirill on 03.10.17.
//

#ifndef LAB_OS_1_TIMER_H
#define LAB_OS_1_TIMER_H

#include <string>
#include <easylogging++.h>

class Timer {
public:
    virtual void start() = 0;
    virtual void end() = 0;
    virtual std::string show() = 0;
};

#endif //LAB_OS_1_TIMER_H
