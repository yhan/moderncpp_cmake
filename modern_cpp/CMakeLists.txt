# Pick up all module files automatically.
# CONFIGURE_DEPENDS asks CMake to re-run configure when matching files are added/removed.
file(GLOB MODERN_CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB MODERN_CPP_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

# Exclude main.cpp so the static library can be linked by both the app and tests
# without a duplicate main() symbol.
list(FILTER MODERN_CPP_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Static library — compiled once, reused by app and tests.
add_library(modern_cpp_lib STATIC
    ${MODERN_CPP_SOURCES}
    ${MODERN_CPP_HEADERS})
target_include_directories(modern_cpp_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(modern_cpp_lib PUBLIC project_warnings)

# Convenience alias (modern_cpp -> modern_cpp_lib)
add_library(modern_cpp ALIAS modern_cpp_lib)

# App target: library + its own main.cpp
add_executable(modern_cpp_app
    src/main.cpp
    src/TestLinkerWrapper.cpp)
target_link_libraries(modern_cpp_app PRIVATE
    modern_cpp_lib
    project_warnings)
