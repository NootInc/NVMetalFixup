//  Copyright © 2022-2023 ChefKiss Inc. Licensed under the Thou Shalt Not Profit License version 1.0. See LICENSE for
//  details.

#ifndef kern_nvmf_hpp
#define kern_nvmf_hpp
#include <Headers/kern_patcher.hpp>
#include <IOKit/IOService.h>
#include <IOKit/ndrvsupport/IONDRVFramebuffer.h>

class NVMF {
    public:
    static NVMF *callback;

    void init();

    private:
    void processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size);

    mach_vm_address_t orgSharedUCNewResource {0};
    static void *wrapSharedUCNewResource(void *that, void *param1, void *param2, uint64_t param3, uint32_t *param4);

    mach_vm_address_t orgNewResourceWithOptions {0};
    static void *wrapNewResourceWithOptions(void *accel, void *accelShared, uint32_t resType, IOByteCount count,
        IOOptionBits options, IOByteCount param6, mach_vm_address_t *param7, uint32_t namespaceId);
};

#endif /* kern_nvmf.hpp */
