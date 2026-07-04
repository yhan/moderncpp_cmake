#include "../include/GArray.h"
#include "utils.cpp"

namespace basics {

    template<typename T>
    GArray<T>::GArray(std::initializer_list<T> init_list) {
        size = init_list.size();
        data = new T[size];
        copy_array(init_list.begin(), init_list.end(), data);
    }
}
