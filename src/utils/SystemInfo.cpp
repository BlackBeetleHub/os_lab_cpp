//
// Created by kirill on 08.11.17.
//

#include <cstring>
#include <cpuid.h>
#include "SystemInfo.h"

SystemInfo::SystemInfo() {

}

std::string SystemInfo::GetProcessorTypeName() {
    unsigned arr[4];
    auto* str = new char[13];
    str[12] = '\0';
    __get_cpuid(0, &arr[0], &arr[1], &arr[2], &arr[3]);
    memcpy(str, arr + 1, 4);
    memcpy(str + 4, arr + 3, 4);
    memcpy(str + 8, arr + 2, 4);
    return std::string(str);
}
