#pragma once
#include "my_vector.h"
#include <utility>
#include <optional>
#include <iostream>
#include <string>
#include <type_traits>
#include <stdexcept>

// this doesn't work on every type so watch out, mostly only for numeric ones in mind
namespace challenge_ds {
    
    template<typename T>
    T& max(const Vector<T>& a); 

    template<typename T>
    T& min(const Vector<T>& a);

    template<typename T>
    T sum(const Vector<T>& a);

    template<typename T>
    T avg(const Vector<T>& a);

    template<typename T>
    const std::optional<std::pair<size_t,size_t>>& find(const Vector<T>& a, const T& x);

    template<typename T>
    Iterator<T> find(Iterator<T> a, Iterator<T> b, const T& x);

    template<typename T>
    void print_number_vector(const Vector<T>& a);
}

#include "my_vector_utility.tpp"