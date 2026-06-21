# The "MemAndPointer" application -> ConfigurationType=Application, SubSystem=Console
add_executable(mem_and_pointer src/MemAndPointer.cpp)
target_link_libraries(mem_and_pointer PRIVATE project_warnings)
