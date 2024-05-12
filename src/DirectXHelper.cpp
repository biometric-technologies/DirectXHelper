#include "DirectXHelper.h"
#include "dxgi.h"
#include <wrl/client.h>

int GetBestGpuIndex() {
    Microsoft::WRL::ComPtr<IDXGIFactory1> factory;
    HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&factory));
    if (FAILED(hr)) {
        return -1;
    }

    Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter;
    DXGI_ADAPTER_DESC1 desc;
    SIZE_T maxDedicatedMemory = 0;
    int bestIndex = -1;
    int currentIndex = 0;

    while (factory->EnumAdapters1(currentIndex, &adapter) != DXGI_ERROR_NOT_FOUND) {
        adapter->GetDesc1(&desc);
        if (desc.DedicatedVideoMemory > maxDedicatedMemory && !(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)) {
            maxDedicatedMemory = desc.DedicatedVideoMemory;
            bestIndex = currentIndex;
        }

        adapter.Reset();
        currentIndex++;
    }

    return bestIndex;
}
