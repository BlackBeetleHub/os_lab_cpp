//
// Created by kirill on 08.11.17.
//

#include <cpuid.h>
#include "test/Test.h"
#include "utils/SystemInfo.h"

TEST(SimpleTest, SystemInfoTest){
    int a, b, c, d;
    __cpuid (0, a, b, c, d);
    printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, b, c, d);
}

TEST(SystemInformationTests, GetTypeProcessorTest){
    std::string expectTypeName = "GenuineIntel";
    std::string actualTypeName = SystemInfo::GetProcessorTypeName();
    ASSERT_TRUE(expectTypeName == actualTypeName);
    LOG(INFO) << actualTypeName;
}
TEST(SystemInformationTests, IsSupportSSE){

    bool res = SystemInfo::isSupportSSE();
    LOG(INFO) << res;
}

