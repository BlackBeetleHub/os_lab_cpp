cmake_minimum_required(VERSION 3.8)
project(lab_os_1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/timers/Timer.cpp src/timers/Timer.h src/timers/CommonTimer.cpp src/timers/CommonTimer.h)
add_executable(lab_os_1 ${SOURCE_FILES})