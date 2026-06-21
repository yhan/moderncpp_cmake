# Header-only library exposing MyTest.h so both the app and the tests can reuse it
# (in the MSVC solution the test project #included "../Modern Cpp/MyTest.h" directly).
add_library(modern_cpp_lib INTERFACE)
target_include_directories(modern_cpp_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Pick up all app source files under src/ automatically.
# CONFIGURE_DEPENDS asks CMake to re-run configure when matching files are added/removed.
file(GLOB MODERN_CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# The "Modern Cpp" application -> ConfigurationType=Application, SubSystem=Console
add_executable(modern_cpp ${MODERN_CPP_SOURCES}
        src/std_array.cpp
        #        src/static_array.cpp
#        include/static_array.h
)
target_link_libraries(modern_cpp PRIVATE modern_cpp_lib project_warnings)
