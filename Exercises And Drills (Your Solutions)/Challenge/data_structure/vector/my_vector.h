#pragma once
#include <initializer_list>
#include <algorithm>
#include <new>
#include <type_traits>
#include <stdexcept>
#include <string>
#include "../my_iterator.h"

namespace challenge_ds {
    template<typename T>
    class Vector {
        public:
            // default constructor
            Vector();
            // constructor for given size
            template<typename S>
            explicit Vector(S in_size);
            // constructor for initialization of n size with a default value
            template<typename S>
            Vector(S in_size, T x);
            // constructor for initializer list e.g. {1,2,3,4} <--- this is an initializer list
            Vector(std::initializer_list<T> lst);
            // constructor for existing vector
            Vector(Iterator<T> start, Iterator<T> end);
            // copy constructor, note has to be a reference argument, otherwise infinite recursion
            Vector(Vector<T>& v);
            // move constructor
            Vector(Vector<T>&& v);
            
            // iterators
            Iterator<T> begin();
            Iterator<T> end();

            Iterator<T> begin() const;
            Iterator<T> end() const;

            
            // capacity
            size_t size();
            size_t size() const;
            size_t capacity();
            bool empty();
            bool empty() const;
            template<typename S>
            void reserve(S new_cap);

            // element access
            template<typename S>
            T& at(S n);
            T& front();
            T& back();
            T* data();

            // modifiers
            void clear();
            void push_back(T x);
            template<typename S>
            void resize(S count);
            void pop_back();

            // operator overloads
            template<typename S>
            T& operator[](S n);
            template<typename S>
            T& operator[](S n) const;
            Vector<T>& operator=(Vector<T>& other);
            Vector<T>& operator=(Vector<T>&& other);

            // destructor
            ~Vector();

        private:
            size_t capacity_;
            size_t size_;
            T* elements;

            // private helper methods for the class, not for users to invoke
            void copy(Iterator<T> begin, Iterator<T> end, Iterator<T> dest);
            size_t distance(Iterator<T> begin, Iterator<T> end);
            T* allocate_memory(size_t size);
            template<typename S>
            void check_positive_integral_type(S s);
            template<typename S>
            void check_positive_integral_type(S s) const;
            //friend class my_class;
    };

}

#include "my_vector.tpp"