![](.github/readme/banner.svg)

# DirectXHelper

A tiny Windows library with one job: tell you which GPU in the machine is the best one to run AI inference on. It asks DirectX (through DXGI, the part of DirectX that enumerates graphics adapters) for every adapter, skips software renderers, and returns the index of the adapter with the most dedicated video memory. Pass that index to an inference runtime that lets you choose a device and your model lands on the real GPU instead of an integrated chip or a software fallback.

## What it does

- Exports one C function, `int GetBestGpuIndex()`, from a shared library (DLL), so it can be called from C, C++, C# (P/Invoke), Python (ctypes) or anything else that can load a DLL.
- Enumerates adapters with `IDXGIFactory1::EnumAdapters1` and reads `DedicatedVideoMemory` from each.
- Ignores adapters flagged `DXGI_ADAPTER_FLAG_SOFTWARE`, such as the Microsoft Basic Render Driver.
- Returns `-1` when DXGI cannot be created or no hardware adapter with dedicated memory is found.
- Comes with `TestApp`, a console program that prints the chosen index.

## How to build

Windows only; you need CMake 3.10 or newer and a compiler with the Windows SDK (Visual Studio works). The library links against `dxgi.lib`.

```sh
cmake -S . -B build
cmake --build build --config Release
build\Release\TestApp.exe
```

The output is one line, for example `Best GPU Index: 0`. Two targets are built: `DirectXHelper` (the DLL, compiled with `DIRECTXHELPERLIB_EXPORTS` defined) and `TestApp`.

To use it from your own code, add `include/` to your include path and link `DirectXHelper.lib`:

```cpp
#include "DirectXHelper.h"

int gpu = GetBestGpuIndex();   // -1 if nothing suitable was found
```

## Related repositories

- [biometric-sdk](https://github.com/biometric-technologies/biometric-sdk): the Iriscan face, liveness and iris SDK.
- [biometric-converter](https://github.com/biometric-technologies/biometric-converter): fingerprint template conversion.

## License

License: not yet specified.

## Contact

info@iriscan.net, https://www.iriscan.com
