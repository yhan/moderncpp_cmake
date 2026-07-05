//
// Created by hanyi on 7/4/2026.
//

#ifndef MODERNCPP_GARRAY_H
#define MODERNCPP_GARRAY_H

#include <initializer_list>
#include <stdexcept>

namespace basics {

    template<typename T>
    class GArray {
    public:
        GArray();

        GArray(std::initializer_list<T> init_list);

        // Rule of Five
        ~GArray();

        GArray(const GArray &other);

        // copy ctor
        GArray<T> &operator=(const GArray &other);

        void push(T elem);
        T pop();

        bool try_remove(T val);

        /// Move ctor: transfer data pointer and size, O(1)
        GArray(GArray &&other) noexcept;

        /// Move assignment
        GArray &operator=(GArray &&other) noexcept;

    private:
        T *data;
        int size;
        int capacity;
        void resize_array();
    };

}

#endif //MODERNCPP_GARRAY_H
