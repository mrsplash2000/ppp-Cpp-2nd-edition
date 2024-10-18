#pragma once

namespace challenge_ds {
    template<typename T>
    Iterator<T>::Iterator(T* ptr_): ptr{ptr_} {}

    template<typename T>
    T& Iterator<T>::operator*() {
        return *ptr;  // we return the address that it points to by returning the content of the memory address and then doing & operator on it
    }

    template<typename T>
    Iterator<T>& Iterator<T>::operator++() {
        ++ptr;
        return *this;
    }

    template<typename T>
    Iterator<T>& Iterator<T>::operator--() {
        --ptr;
        return *this;
    }

    template<typename T>
    bool Iterator<T>::operator==(const Iterator<T>& other) const {
        return ptr == other.ptr;
    }

    template<typename T>
    bool Iterator<T>::operator!=(const Iterator<T>& other) const {
        return ptr != other.ptr;
    }

}
