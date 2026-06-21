//
// Created by hanyi on 6/21/2026.
//

#ifndef MODERNCPP_STATIC_ARRAY_H
#define MODERNCPP_STATIC_ARRAY_H
#include <algorithm>
#include <iostream>
#include <random>
#include <span>


class static_array {
public:
    void print(int *ptr, int size);
};

template<typename T, int size> // can't use this technique if the array is dynamically allocated (e.g., int* arr = new int[5];)
void print(T (&arr)[size]);

void print(std::span<const int> arr);

template<typename T, int size>
void shuffle_array(T (&arr)[size]);

int test();

#endif //MODERNCPP_STATIC_ARRAY_H
