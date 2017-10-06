cmake_minimum_required(VERSION 3.8)
project(lab_os_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/logging)

file(GLOB SOURCE_H */**/*.h)

file(GLOB SOURCE_CPP **/*.cpp **/**/*.cpp **/**/*.cc)

set(SOURCE_FILES ${SOURCE_H} ${SOURCE_CPP})

add_executable(lab_os_1 ${SOURCE_FILES})