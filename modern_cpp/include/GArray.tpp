#pragma once

// #ifndef MODERNCPP_GARRAY_H
// #include "GArray.h"
// #endif

namespace basics {
    template<typename T>
    GArray<T>::GArray() : data(new T[8]), size(0), capacity(8) {
    }

    template<typename T>
    GArray<T>::GArray(std::initializer_list<T> init_list)
        : data(nullptr), size(static_cast<int>(init_list.size())) {
        if (size == 0) {
            capacity = 8;
            data = new T[capacity];
            return;
        }

        capacity = size * 2;
        data = new T[capacity];
        int index = 0;
        for (const T &value: init_list) {
            data[index++] = value;
        }
        size = index;
    }

    template<typename T>
    GArray<T>::~GArray() {
        delete[] data;
    }

    template<typename T>
    GArray<T>::GArray(const GArray &other) : data(nullptr), size(other.size), capacity(other.capacity) {
        if (size == 0) {
            data = new T[8];
            capacity = 8;
            return;
        }

        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        size = other.size;
        capacity = other.capacity;
    }

    template<typename T>
    GArray<T> &GArray<T>::operator=(const GArray &other) {
        if (this == &other) {
            return *this;
        }

        T *new_data = new T[other.capacity];
        for (int i = 0; i < other.size; ++i) {
            new_data[i] = other.data[i];
        }

        delete[] data;
        capacity = other.capacity;
        data = new_data;
        size = other.size;
        return *this;
    }


    template<typename T>
    GArray<T>::GArray(GArray &&other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
    }

    template<typename T>
    GArray<T> &GArray<T>::operator=(GArray &&other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        return *this;
    }

    template<typename T>
    void GArray<T>::push(T elem) {
        if (size >= capacity) {
            // Resize the array
            capacity *= 2;
            T *new_data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = elem;
    }

    template<typename T>
    T GArray<T>::pop() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        T val = data[size - 1];
        size--;
        resize_array();

        return val;
    }

    template<typename T>
    bool GArray<T>::try_remove(T val) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == val) {
                for (int j = i; j < size - 1; ++j) {
                    data[j] = data[j + 1];
                }
                size--;
                resize_array();
                return true;
            }
        }
        return false;
    }
    template<typename T>
    void GArray<T>::resize_array() {
        if (capacity > 8 && size > 0 && size == capacity / 4) {
            // Leave doubled available spaces compared to occupancy.
            capacity /= 2;
            T *new_data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
    }

    template<typename T>
    int GArray<T>::get_size() const {
        return size;
    }

    template<typename T>
    int GArray<T>::get_capacity() const {
        return capacity;
    }
} // namespace basics
