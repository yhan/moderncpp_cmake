//
// Created by hanyi on 6/21/2026.
//

#include "static_array.h"

void static_array::print(int *ptr, int size) {
    for (int i = 0; i < size; ++i) {
        //std::cout << ptr[i] << ' ';
        std::cout << *(ptr + i) << ' ';
    }
    std::cout << '\n';
}


//int size is a non-type template parameter:
//the array length is part of the type at compile time.
// !!! An array's size is part of its type. int[5] and int[4] are genuinely different types
template<typename T, int size>
void print(T (&arr)[size]) {
    // reference to an array of N elements of type T
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
}


void print(std::span<const int> arr) {
    for (int x: arr) std::cout << x << ' ';
    std::cout << '\n';
}


template<typename T, int size>
void shuffle_array(T (&arr)[size]) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(arr), std::end(arr), g);
}

template<typename T, int size>
T *begin(T (&ref)[size]) {
    return (T *) ref;
}

template<typename T, int size>
T *end(T (&ref)[size]) {
    //return (T*)ref + size;

    return (T *) &ref[0] + size;
}


int test() {
    int arr4[]{1, 2, 3, 4, 5};
    int (&ref)[5] = arr4; // reference to an array of 5 integers

    int *begin_ptr = begin(ref);
    begin_ptr[0] = 10; // modify the first element of the array through the pointer
    std::cout << "begin @= " << begin_ptr << " value=" << *begin_ptr << '\n';
    std::cout << "end @= " << end(ref) << " value=" << *(end(ref) - 1) << '\n';


    //int &ref[5] would parse as "array of 5 references," which is illegal
    // print(ref);
    //
    // //
    // print(std::span{arr4});
    //
    // //
    // std::vector<int> v{1, 2, 3};
    // print(v);
    //
    //
    // // Shuffle arr4 to random order
    // shuffle_array(arr4);
    // std::cout << "Shuffled array: ";
    // print(arr4);
    //
    //
    // std::sort(std::begin(arr4), std::end(arr4));
    // std::cout << "Sorted array: ";
    // print(arr4);


    int *p = arr4;

    shuffle_array(arr4);
    std::sort(p, p + 5);

    static_array arr_utils;
    arr_utils.print(p, 5);
    return 0;
}
