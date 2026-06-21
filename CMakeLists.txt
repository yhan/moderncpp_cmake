cmake_minimum_required(VERSION 3.20)

project(ModernCpp
    VERSION 1.0.0
    DESCRIPTION "Modern C++ Udemy course projects (CMake port of the MSVC solution)"
    LANGUAGES CXX)

# ---- Global C++ settings (mirrors the MSVC <LanguageStandard>stdcpp20</...>) ----
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Put all binaries in a single predictable place.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Default to a Debug build if the user didn't pick one (single-config generators).
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Warning level roughly equivalent to the MSVC /W3 + /permissive- in the .vcxproj.
add_library(project_warnings INTERFACE)
if(MSVC)
    target_compile_options(project_warnings INTERFACE /W3 /permissive-)
else()
    target_compile_options(project_warnings INTERFACE -Wall -Wextra)
endif()

# ---- Testing ----
include(CTest)            # defines BUILD_TESTING (default ON)
enable_testing()

# ---- Targets ----
add_subdirectory(modern_cpp)
add_subdirectory(mem_and_pointer)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
