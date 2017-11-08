//
// Created by kirill on 08.11.17.
//

#ifndef LAB_OS_1_SYSTEMINFO_H
#define LAB_OS_1_SYSTEMINFO_H

#include <string>

class SystemInfo {
public:
    SystemInfo();
    static std::string GetProcessorTypeName();
    static bool isSupportSSE();
};


#endif //LAB_OS_1_SYSTEMINFO_H
