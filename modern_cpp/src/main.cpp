#include <iostream>
#include <array>
#include <span>


void print_and_delete_array() {
    //-------------------------------
    int *p = new int[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        std::cout << *(p++) << ' ';
    }
    delete[] (p); // -1073740940 (0xC0000374) Windows damaged Heap: deleting a pointer that was not returned by new / new[]

    // for (int i = 0; i < 5; ++i) {
    //     std::cout << *(p++) << ' ';
    // }

    // //-------------------------------
    // int *p2 = new int[5]{1, 2, 3, 4, 5};
    // int *original = p2;
    // for (int i = 0; i < 5; ++i) {
    //     std::cout << *p2++ << ' ';
    // }
    //
    // delete[] original;
}

int main() {
    int *p = new int[5]{1, 2, 3, 4, 5};
    int *p_temp = new int[10];
    std::copy(p, p + 5, p_temp);

    for (int i = 0; i < 10; ++i) {
        std::cout << p_temp[i] << ' ';
    }

    delete[] p;
    delete[] p_temp;
}
