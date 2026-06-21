#include <span>
#include <iostream>
#include <array>
//
// Created by hanyi on 6/21/2026.
//
void print_noCOPY(std::span<const int> arr) { // NO COPY
    // for (int x: arr) std::cout << x << ' ';
    // std::cout << '\n';

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';


    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << ' ';
    }

    for (const int &x: arr) std::cout << x << ' ';// x is reference to each element ( not address of )
    for (int x: arr) std::cout << x << ' ';// x is a copy of each element
}

void print_no_copy(std::array<int, 5>& arr) { // & => so a reference to array, so no COPY?
    for (int x: arr) std::cout << x << ' ';
    std::cout << '\n';
}

void unpractical_print_with_copy(std::array<int, 5> arr) { // size is fixed
    for (int x: arr) std::cout << x << ' ';
    std::cout << '\n';
}