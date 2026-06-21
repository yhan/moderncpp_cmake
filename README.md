# Modern C++ — CMake build

CMake port of the Visual Studio (MSVC) solution in `../Modern Cpp`. Same
sources, same C++20 standard, same GoogleTest dependency — now buildable with
plain CMake on any platform/compiler.

## Layout

```
moderncpp_cmake/
├── CMakeLists.txt          # top-level project, C++20, warnings, CTest
├── CMakePresets.json       # default / vcpkg / msvc presets
├── vcpkg.json              # manifest declaring the gtest dependency
├── modern_cpp/             # "Modern Cpp" app  (Source.cpp -> src/main.cpp)
│   ├── include/MyTest.h     # shared header (exposed as modern_cpp_lib)
│   └── src/main.cpp
├── mem_and_pointer/        # "MemAndPointer" app
│   └── src/MemAndPointer.cpp
└── tests/                  # "ModernCppTests" (GoogleTest)
    └── ModernCppTests.cpp
```

## Project mapping (MSVC -> CMake target)

| MSVC project    | Type        | CMake target        |
|-----------------|-------------|---------------------|
| Modern Cpp      | Application | `modern_cpp`        |
| MemAndPointer   | Application | `mem_and_pointer`   |
| ModernCppTests  | Application | `modern_cpp_tests`  |

`MyTest.h` is shared through the header-only `modern_cpp_lib` interface library,
replacing the test project's `#include "../Modern Cpp/MyTest.h"`.

## Build

> If a `build\` folder already exists with a stale cache, delete it first:
> `rmdir /s /q build` (Windows) or `rm -rf build` (Unix).

### Windows + Visual Studio 2022 (recommended)

Uses your installed VS toolchain; GoogleTest is downloaded via git the first time.

```bat
cmake --preset msvc
cmake --build --preset msvc
ctest --preset msvc
```

### Windows + vcpkg (matches the original .vcxproj static triplet)

Requires `VCPKG_ROOT` to be set and `gtest` installed via vcpkg
(`vcpkg install gtest:x64-windows-static`). No download needed.

```bat
cmake --preset msvc-vcpkg
cmake --build --preset msvc-vcpkg
ctest --preset msvc-vcpkg
```

### Any platform (Ninja, GoogleTest fetched)

```sh
cmake --preset default
cmake --build --preset default
ctest --preset default
```

### Without presets

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Binaries are written to `build/<preset>/bin/`.

## GoogleTest

`tests/CMakeLists.txt` first tries `find_package(GTest CONFIG)` (works with a
vcpkg toolchain or a system install). If GTest isn't found, it falls back to
`FetchContent` and downloads it, so the project builds even without vcpkg.
