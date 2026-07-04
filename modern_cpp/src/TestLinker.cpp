#pragma once

#include <iostream>

#include "./utils.cpp"
#include "../include/GArray.h"
#include "../include/TestLinker.h"

int *hello() {
    std::cout << "hello world" << '\n';
    std::initializer_list<int> init_list = {1, 2, 3};
    auto data = new int[5];
    auto begin = init_list.begin();
    auto end = init_list.end();
    copy_array3(begin, end, data);
    return data;
}