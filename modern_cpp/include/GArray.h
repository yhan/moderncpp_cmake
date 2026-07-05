#pragma once

#include <initializer_list>
#include <stdexcept>

namespace basics {

    template<typename T>
    class GArray {
    public:
        GArray();

        GArray(std::initializer_list<T> init_list);

        /// destructor
        ~GArray();

        /// Copy ctor
        GArray(const GArray &other);

        /// copy assignment
        GArray &operator=(const GArray &other);

        /// Move ctor: transfer data pointer and size, O(1)
        GArray(GArray &&other) noexcept;

        /// Move assignment
        GArray &operator=(GArray &&other) noexcept;

        void push(T elem);
        T pop();

        bool try_remove(T val);

        [[nodiscard]] int get_size() const;
        [[nodiscard]] int get_capacity() const;

    private:
        T *data;
        int size;
        int capacity;
        void resize_array();
    };

}

#include "GArray.tpp"

