// class TwoDimArr {
//
//     static void init() {
//
//     }
// };
//

#include "TwoDimArr.h"
#include <iostream>

void init_print(int arr[2][3]) { // does not belong to ay class,  ___free function__

    TwoDimArr::init(arr);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void TwoDimArr::init(int arr[2][3]) {

    //int **p = arr;
    // pointer to an array of 3 integers
    int(*ptr)[3] = arr;
    ptr[0][0] = 10;
    (*ptr)[1] = 20;
    **ptr = 10; // write to first row, first column
    **(ptr + 1) = 30; // write to second row, first column // first dimension is row, donc on décale d'un row
}
