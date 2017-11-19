//
// Created by kirill on 06.10.17.
//

#include "timers/CommonTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/OmpTimer.h"
#include "CustomArray.h"

#include <gtest/gtest.h>

TEST(Testa, OmpTimerSorta) {
#pragma omp parallel
    {
        std::cout << "Hello World!\n";
    }
}

TEST(Testa, OmpTimerSorta1) {

}

TEST(Testa, OmpTimerSorta2) {

}

TEST(Testa, OmpTimerSorta3) {

}

