//
// Created by kirill on 08.11.17.
//

#include <cstring>
#include <cpuid.h>
#include <iostream>
#include "SystemInfo.h"

InfoStruct SystemInfo::infoName = InfoStruct(0);
InfoStruct SystemInfo::infoCPU = InfoStruct(1);

SystemInfo::SystemInfo() {

}

std::string SystemInfo::GetProcessorTypeName() {
    auto *str = new char[13];
    str[12] = '\0';
    memcpy(str, &infoName.ebx, 4);
    memcpy(str + 4, &infoName.edx, 4);
    memcpy(str + 8, &infoName.ecx, 4);
    return std::string(str);
}


/*
 *
 *  x87 FPU on chip                        = true
      virtual-8086 mode enhancement          = true
      debugging extensions                   = true
      page size extensions                   = true
      time stamp counter                     = true
      RDMSR and WRMSR support                = true
      physical address extensions            = true
      machine check exception                = true
      CMPXCHG8B inst.                        = true
      APIC on chip                           = true
      SYSENTER and SYSEXIT                   = true
      memory type range registers            = true
      PTE global bit                         = true
      machine check architecture             = true
      conditional move/compare instruction   = true
      page attribute table                   = true
      page size extension                    = true
      processor serial number                = false 19
      CLFLUSH instruction                    = true 20
      debug store                            = true 21
      thermal monitor and clock ctrl         = true 22
      MMX Technology                         = true 23
      FXSAVE/FXRSTOR                         = true 24
      SSE extensions                         = true 25
      SSE2 extensions                        = true 26
      self snoop                             = true  27
      hyper-threading / multi-core supported = true  28
      therm. monitor                         = true  29
      IA64                                   = false 30
      pending break event                    = 31


      PNI/SSE3: Prescott New Instructions     = true 1
      PCLMULDQ instruction                    = true 2
      64-bit debug store                      = true 3
      MONITOR/MWAIT                           = true 4
      CPL-qualified debug store               = true 5
      VMX: virtual machine extensions         = true 6
      SMX: safer mode extensions              = false 7
      Enhanced Intel SpeedStep Technology     = true 8
      thermal monitor 2                       = true 9
      SSSE3 extensions                        = true 10
      context ID: adaptive or shared L1 data  = false 11
      FMA instruction                         = true 12
      CMPXCHG16B instruction                  = true 13
      xTPR disable                            = true 14
      perfmon and debug                       = true 15
      process context identifiers             = true 16
      direct cache access                     = false 17
      SSE4.1 extensions                       = true 18
      SSE4.2 extensions                       = true 19
      extended xAPIC support                  = true 20
      MOVBE instruction                       = true 21
      POPCNT instruction                      = true 22
      time stamp counter deadline             = true 23
      AES instruction                         = true 24
      XSAVE/XSTOR states                      = true 25
      OS-enabled XSAVE/XSTOR                  = true 26
      AVX: advanced vector extensions         = true 27
      F16C half-precision convert instruction = true 28
      RDRAND instruction                      = true 29
      hypervisor guest status                 = false 30 31

 */
bool SystemInfo::isSupportSSE() {
    // about sse, sse2, sse4.1, sse4.2
    // warning: I have not sse5 and sse4a :(
    std::cout << ((infoCPU.edx & (1 << 25)) == (1 << 25)) << std::endl; // sse
    std::cout << ((infoCPU.edx & (1 << 26)) == (1 << 26)) << std::endl; // sse2
    std::cout << ((infoCPU.ecx & (1 << 19)) == (1 << 19)) << std::endl; // sse4.1
    std::cout << ((infoCPU.ecx & (1 << 20)) == (1 << 20)) << std::endl; // sse4.2

    std::cout << ((infoCPU.edx & (1 << 0)) == (1 << 0)) << std::endl; // sse3
    std::cout << ((infoCPU.edx & (1 << 9)) == (1 << 9)) << std::endl; // ssse3
    std::cout << ((infoCPU.ecx & (1 << 27)) == (1 << 27)) << std::endl; //AVX

    return true;
}

unsigned SystemInfo::getCountProcessors() {
    return ((infoCPU.ecx >> 26) & 0x3f) + 1;
}
