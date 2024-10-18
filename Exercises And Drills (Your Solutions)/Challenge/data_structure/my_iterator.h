#pragma once

namespace challenge_ds {
    // they say that iterator usually is within the container class, but I chose to just do a separate one completely
    // this is basically a wrapper around a pointer
    template<typename T>
    class Iterator {
        public:
            Iterator(T* ptr_);

            T& operator*(); 

            Iterator<T>& operator++(); 

            Iterator<T>& operator--();

            bool operator==(const Iterator<T>& other) const; 

            bool operator!=(const Iterator<T>& other) const;
            
        private:
            T* ptr;
    };
}

#include "my_iterator.tpp"