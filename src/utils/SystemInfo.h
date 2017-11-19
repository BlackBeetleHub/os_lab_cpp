//
// Created by kirill on 08.11.17.
//

#ifndef LAB_OS_1_SYSTEMINFO_H
#define LAB_OS_1_SYSTEMINFO_H

#include <string>

struct InfoStruct {
    InfoStruct(unsigned number){
        __get_cpuid(number, &eax, &ebx, &ecx, &edx);
    }
    unsigned eax;
    unsigned ebx;
    unsigned edx;
    unsigned ecx;
};

class SystemInfo {
public:
    SystemInfo();
    static bool isSupportSSE();
    static unsigned getCountProcessors();
    static std::string GetProcessorTypeName();

private:
    static InfoStruct infoName;
    static InfoStruct infoCPU;
};


#endif //LAB_OS_1_SYSTEMINFO_H
