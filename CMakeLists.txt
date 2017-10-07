cmake_minimum_required(VERSION 3.8)
project(lab_os_1)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DINITIALIZE_EASYLOGGINGPP)

add_subdirectory(lib/googletest)
include_directories(src)
include_directories(lib/logging)
include_directories(lib/googletest/googletest/include)

file(GLOB SOURCE_H */**/*.h)

file(GLOB SOURCE_CPP **/**/*.cpp **/**/*.cc)

set(SOURCE_FILES ${SOURCE_H} ${SOURCE_CPP})
set(SOURCE_FILES_EXE ${SOURCE_FILES} src/main.cpp)

add_executable(lab_os_1 ${SOURCE_FILES_EXE})

add_executable(test_lab_os_1 ${SOURCE_FILES} )

target_link_libraries(lab_os_1 gtest gtest_main -fopenmp)
target_link_libraries(test_lab_os_1 gtest gtest_main -fopenmp)