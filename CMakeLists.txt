cmake_minimum_required(VERSION 3.8)
project(lab_os_1)

set(CMAKE_CXX_STANDARD 11)

#For Debug
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -pthread")
#For Release
set(CMAKE_C_FLAGS_RELEASE "-g -O2")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O2 -pthread")
#For MaxOptz
set(CMAKE_C_FLAGS_MAXOPTZ "-g -O3")
set(CMAKE_CXX_FLAGS_MAXOPTZ "-g -O3 -pthread")
#For Fast
set(CMAKE_C_FLAGS_FAST "-g -Ofast")
set(CMAKE_CXX_FLAGS_FAST "-g -Ofast -pthread")

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