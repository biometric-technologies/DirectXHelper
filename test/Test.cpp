#include <iostream>
#include "DirectXHelper.h"

int main() {
    int gpuIndex = GetBestGpuIndex();
    std::cout << "Best GPU Index: " << gpuIndex << std::endl;
    return 0;
}