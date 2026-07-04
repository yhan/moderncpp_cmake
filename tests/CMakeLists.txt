# ---- GoogleTest ----
# The original MSVC project linked gtest/gtest_main from vcpkg
# (x64-windows-static triplet). We first try a config-mode find_package, which
# works with a vcpkg toolchain or a system install. If GTest isn't found, we
# fall back to fetching it so the project builds anywhere.
find_package(GTest CONFIG QUIET)

if(NOT GTest_FOUND)
    message(STATUS "GTest not found via find_package - fetching with FetchContent")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2
    )
    # Match MSVC static runtime linkage used by the x64-windows-static triplet.
    set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(modern_cpp_tests ModernCppTests.cpp MemoryTests.cpp)
target_link_libraries(modern_cpp_tests PRIVATE
    modern_cpp_lib
    GTest::gtest
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(modern_cpp_tests)
