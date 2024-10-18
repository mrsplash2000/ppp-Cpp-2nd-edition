#pragma once

namespace challenge_ds {
   // default constructor
   template<typename T>
   Vector<T>::Vector(): size_{0}, capacity_{0}, elements{nullptr} {}

   // constructor for given size
   template<typename T>
   template<typename S>
   Vector<T>::Vector(S in_size) {
      check_positive_integral_type(in_size);
      size_ = in_size;
      capacity_ = in_size;        
      elements = allocate_memory(capacity_);
      for (size_t i=0; i < capacity_; ++i) {
         new (&elements[i]) T{};
      }
   }

   // constructor for initialization of n size with a default value
   template<typename T>
   template<typename S>
   Vector<T>::Vector(S in_size, T x) {
      check_positive_integral_type(in_size);
      size_ = in_size;
      capacity_ = in_size;
      elements = allocate_memory(capacity_);
      Iterator<T> start = begin();
      Iterator<T> stop = end();
      while (start != stop) {
         new (&(*start)) T(x);
         ++start;
      }
   }

   // constructor for initializer list e.g. Vector<T> t = {1,2,3,4} <--- this is an initializer list 
   template<typename T>
   Vector<T>::Vector(std::initializer_list<T> lst) {
      size_ = lst.size();
      capacity_ = lst.size();
      elements = allocate_memory(capacity_);
      // need to convert to my own custom Iterator class, don't want to derive original Iterator class for now
      // to keep it simple
      copy(Iterator((T*) lst.begin()), Iterator((T*) lst.end()), begin());
   }

   // constructor for existing vector with iterators
   template<typename T>
   Vector<T>::Vector(Iterator<T> start, Iterator<T> end) {
      size_ = distance(start, end);
      capacity_ = size_;
      elements = allocate_memory(capacity_);
      copy(start, end, begin());
   }

   // copy constructor, note has to be a reference argument, otherwise infinite recursion
   // this will be called when doing Vector<T> v = v2; or Vector<T> v(v2); or in a function when passing object
   // by value such as foo(Vector<T> v) {} here the sheer act of passing it by value will invoke the constructor
   template<typename T>
   Vector<T>::Vector(Vector<T>& v) {
      size_ = v.size();
      capacity_ = size_;
      elements = allocate_memory(capacity_);
      copy(v.begin(), v.end(), begin());
   }

   // move constructor
   template<typename T>
   Vector<T>::Vector(Vector<T>&& v) {
      // expect an rvalue (I think), can be done by std::move() to convert objects to rvalue objects
      // so you can do Vector(std::move(vector_to_move)) to initialize a vector with move semantics
      size_ = v.size();
      capacity_ = size_;
      elements = v.data();

      // nullify the existing vector v
      v.size_ = 0;
      v.capacity_ = 0;
      v.elements = nullptr;
   }
   
   template<typename T>
   Iterator<T> Vector<T>::begin() {
      return Iterator(elements);  // it's fine to return a copy of the Iterator class, they are lightweight
   }

   template<typename T>
   Iterator<T> Vector<T>::end() {
      return Iterator(elements + size_);
   }

   template<typename T>
   Iterator<T> Vector<T>::begin() const {
      return Iterator(elements);  // it's fine to return a copy of the Iterator class, they are lightweight
   }

   template<typename T>
   Iterator<T> Vector<T>::end() const {
      return Iterator(elements + size_);
   }

   // capacity
   template<typename T>
   size_t Vector<T>::size() {
      return size_;
   }

   template<typename T>
   size_t Vector<T>::size() const {
      return size_;
   }

   template<typename T>
   size_t Vector<T>::capacity() {
      return capacity_;
   }

   template<typename T>
   bool Vector<T>::empty() {
      return size_ == 0;
   }

   template<typename T>
   bool Vector<T>::empty() const {
      return size_ == 0;
   }

   template<typename T>
   template<typename S>
   void Vector<T>::reserve(S new_cap) {
      check_positive_integral_type(new_cap);
      if (new_cap <= capacity_) return;
      T* ptr = allocate_memory(new_cap);
      copy(begin(), end(), Iterator(ptr));
      size_t size_tmp = size_;
      // deallocate and clean old data
      this->~Vector();
      // make our empty vector point to allocated and initialized memory
      // essentially filling our vector now with the old elements but in the new memory location
      size_ = size_tmp;
      capacity_ = new_cap;
      elements = ptr;
   }

   // element access
   template<typename T>
   template<typename S>
   T& Vector<T>::at(S n) {
      check_positive_integral_type(n);
      if (n >= size_) throw std::out_of_range("Index out of range!");
      return elements[n];  // the function expects zero indexed adherence for input n
   }

   template<typename T>
   T& Vector<T>::front() {
      return elements[0];
   }
   
   template<typename T>
   T& Vector<T>::back() {
      size_t n = size_;
      if (size_ != 0) --n;
      return elements[n];
   }

   template<typename T>
   T* Vector<T>::data() {
      return elements;
   }

   // modifiers
   template<typename T>
   void Vector<T>::clear() {
      // only clear the elements, but do not deallocate the memory. If primitive type then the values stays. 
      // If not then they are destroyed.
      if (elements != nullptr) {
            // check type T is not a primitive type (like int, double, float etc), because they have no destructor         
            if constexpr (!std::is_trivially_destructible<T>::value) {
               for (size_t i=0; i < size_; ++i) {
                  elements[i].~T();
               }
            }
      }
      size_ = 0;
   }

   template<typename T>
   void Vector<T>::push_back(T x) {
      // if no space then need to reallocate memory
      if (size_ == capacity_) {
         size_t new_capacity = capacity_ > 0 ? 2 * capacity_ : 1;
         T* ptr = allocate_memory(new_capacity);
         // copy over the old data to new memory
         copy(begin(), end(), Iterator(ptr));
         // add the new input element x to the back of our new memory
         new (&ptr[size_]) T(x);
         size_t size_tmp = size_ + 1;
         this->~Vector();
         size_ = size_tmp;
         capacity_ = new_capacity;
         elements = ptr;
      }
      else {
         new (&elements[size_]) T(x);
         ++size_;
      }
   }

   template<typename T>
   template<typename S>
   void Vector<T>::resize(S new_cap) {
      check_positive_integral_type(new_cap);
      if (new_cap == size_) return;
      if (new_cap < size_) {
         // shrink memory
         // destroy until we reach the new new_cap, primitives we leave alone as they have no destructors
         // note that we don't deallocate the memory here no matter what
         if constexpr (!std::is_trivially_destructible<T>::value) {
            for (int i=size_; i > new_cap; --i) {
               elements[i - 1].~T();
            }
         }
      }
      else {
         // check if allocated memory is enough, otherwise need to reallocate
         if (new_cap <= capacity_) {
            for (int i=size_; i <= new_cap; ++i) {
               // TODO:
               // primitives are fine, since they don't have destructors
               // but custom classes are not, this is only true if size*2 behavior is implemented because then it allows
               // situations were the memory locations between size_ and capacity_ to be initialized by default values
               // and if we ever expand again we will overwrite these, without destroying the objects properly, leading to memory leak
               // luckily I skipped implementing size*2 behavior, so this scenario described below is not possible
               /*
               Initialize: std::vector<int> t(8)
               1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
                             |		    
                        size, capacity
               Default initialized from 1 to 8.

               Expand: t.resize(11)
               1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
                                    |              |		    
                                 size         capacity
               Default initialized from 1 to 16.

               Shrink: t.resize(5)
               1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
                       |                            |		    
                     size                       capacity
               Destroyed objects stored between 6 and 11.

               Expand: t.resize(13)
               1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
                                          |         |
                                        size    capacity
               
               Reinitialize objects stored in 6 to 13. But 12 and 13 were already initialized (when we did t.resize(11)), 
               so we are overwriting them, but not properly destroying them (invoking their destructors), which causes memory leak.
               */
               new (&elements[i - 1]) T{};
            }
         }
         else {
            T* ptr = allocate_memory(new_cap);
            Iterator<T> start = begin();
            for (int i=0; i < new_cap; ++i) {
               // need to initialize the original data up to size_, after that need to default initialize
               // that's why I have divided it up into two cases
               if (i < size_) new (&(ptr[i])) T(*start);
               else {new (&(ptr[i])) T{};}

               ++start;
            }
            this->~Vector(); 
            capacity_ = new_cap;  // for resize capacity only changes when reallocation of memory is done (expanding it) when it's not enough
            elements = ptr;
         }
      }
      size_ = new_cap;
   }

   template<typename T>
   void Vector<T>::pop_back() {
      // once again for primitives we ignore since they have no destructors, just decrement size and don't let user access to it
      if (size_ == 0) throw std::runtime_error("Trying to pop an empty container.");
      if constexpr (!std::is_trivially_destructible<T>::value) elements[size_ - 1].~T();
      --size_;
   }

   // operator overloads
   template<typename T>
   template<typename S>
   T& Vector<T>::operator[](S n) {
      check_positive_integral_type(n);
      return elements[n];
   }

   template<typename T>
   template<typename S>
   T& Vector<T>::operator[](S n) const {
      check_positive_integral_type(n);
      return elements[n];
   }

   template<typename T>
   Vector<T>& Vector<T>::operator=(Vector<T>& other) {
      if(other.size_ == size_) {
         for (int i=0; i < other.size_; ++i) {
            // destroy the object first
            if constexpr (!std::is_trivially_destructible<T>::value) elements[i].~T();
            // now assign it elements from the other vector
            elements[i] = other.elements[i];
         }
      }
      else if (other.size_ < size_) {
         // destroy objects in current memory allocation
         if constexpr (!std::is_trivially_destructible<T>::value) {
            for (int i=size_; i > 0; --i) {
               elements[i - 1].~T();
            }
         }
         
         // copy over the elements from other to current vector
         for (int i=0; i < other.size_; ++i) {
            elements[i] = other.elements[i];
         }
         size_ = other.size_;
      }
      else {
         // other.size_ is bigger need to reallocate new memory
         // personally feel like moving the ptr entirely (like a move semantics) to the other vector in this case would be most 
         // efficient don't have to reallocate memory, can just reuse the already allocated in the other vector
         T* ptr = allocate_memory(other.size_);
         for (int i=0; i < other.size_; ++i) {
            new (&ptr[i]) T(other.elements[i]);
         }
         this->~Vector();
         size_ = other.size_;
         capacity_ = other.size_;
         elements = ptr;
      }
      return *this;
   }

   template<typename T>
   Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
      this->~Vector();
      size_ = other.size_;
      capacity_ = other.capacity_;
      elements = other.elements;

      // nullify the existing vector other, we don't use destructor because we are litterally
      // reusing the exact same pointer to other (the address it points to), only that we have moved it our own vector
      other.size_ = 0;
      other.capacity_ = 0;
      other.elements = nullptr;
      return *this;
   }

   // destructor
   template<typename T>
   Vector<T>::~Vector() {
      if (elements != nullptr) {
         // check type T is not a primitive type (like int, double, float etc), because they have no destructor         
         if constexpr (!std::is_trivially_destructible<T>::value) {
            for (size_t i=0; i < size_; ++i) {
               elements[i].~T();
            }
         }
         ::operator delete(elements);
      }
      size_ = 0;
      capacity_ = 0;
      elements = nullptr;  // get rid of dangling pointer (pointer to address that is not allocated anymore)
   }

   // private methods
   
   // only use this copy if dest is pointing to uninitialized memory (allocated but not initialized with objects)
   // because otherwise copy will overwrite them, but not destroy them leading to memory leak
   template<typename T>
   void Vector<T>::copy(Iterator<T> begin, Iterator<T> end, Iterator<T> dest) {
      size_t size__ = distance(begin, end);
      for (int i=0; i < size__; ++i) {
         // allocate memory on heap at the address pointed to by dest[i] and construct the object of type T
         // initialized as the data in begin[i], basically copying it
         // because don't want to expose the pointer in iterator need to dereference the pointer to get the value and then
         // do & operator to get the address of the value, this is a longer version of just directly accessing the pointer in iterator
         new (&(*dest)) T(*begin);
         ++dest;
         ++begin;
      }
   }

   template<typename T>
   size_t Vector<T>::distance(Iterator<T> begin, Iterator<T> end) {
      // should check for max size for size_t and stop if going over
      size_t dist{0};
      while (begin != end) {
         ++dist;
         ++begin;
      }
      return dist;
   }

   template<typename T>
   T* Vector<T>::allocate_memory(size_t size) {
      // static cast needed because ::operator new returns void*
      // ::operator new allocates memory but doesn't initialize the objects of type T
      // new allocates + initializes the objects by calling their constructor (I think default constructor)
      return static_cast<T*>(::operator new(size * sizeof(T)));
   }

   template<typename T>
   template<typename S>
   void Vector<T>::check_positive_integral_type(S s) {
      std::string prompt = "Only positive integral values allowed.";
      // compile-time checking
      static_assert(std::is_integral<S>::value, prompt);
      // run-time checking and positive integral
      if (s != static_cast<S>(s) || s < 0)
         throw std::invalid_argument(prompt);
   }

   template<typename T>
   template<typename S>
   void Vector<T>::check_positive_integral_type(S s) const {
      std::string prompt = "Only positive integral values allowed.";
      // compile-time checking
      static_assert(std::is_integral<S>::value, prompt);
      // run-time checking and positive integral
      if (s != static_cast<S>(s) || s < 0)
         throw std::invalid_argument(prompt);
   }
}