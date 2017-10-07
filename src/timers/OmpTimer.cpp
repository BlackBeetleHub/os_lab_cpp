//
// Created by kirill on 07.10.17.
//

#include "OmpTimer.h"

void OmpTimer::start() {
    startTime = omp_get_wtime();
}

void OmpTimer::end() {
    endTime = omp_get_wtime();
}

std::string OmpTimer::show() {
    return std::to_string(endTime - startTime) + " seconds";
}
