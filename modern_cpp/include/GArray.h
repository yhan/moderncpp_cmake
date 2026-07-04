//
// Created by hanyi on 7/4/2026.
//

#ifndef MODERNCPP_GARRAY_H
#define MODERNCPP_GARRAY_H
#include <initializer_list>

namespace basics {

    template<typename T>
    class GArray {
        T *data;
        int size;

        GArray(std::initializer_list<T> init_list); // manually copy init_list to this
    };

}

#endif //MODERNCPP_GARRAY_H
