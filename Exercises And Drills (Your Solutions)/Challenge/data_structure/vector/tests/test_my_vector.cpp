#include "../my_vector.h"
#include <iostream>
#include <cassert>
#include <utility>
/*
class my_class {
    public:
        template<typename T>
        size_t get_size(challenge_ds::Vector<T>& v) {return v.size_;}
        template<typename T>
        size_t get_capacity(challenge_ds::Vector<T>& v) {return v.capacity;}
        template<typename T>
        T* get_ptr(challenge_ds::Vector<T>& v) {return v.elements;}
};*/

int main() {
    // test default constructor
    challenge_ds::Vector<int> t1;
    assert(t1.size() == 0);

    // test constructor with size init
    //challenge_ds::Vector<int> t2(10.5);  // this gave error as expected
    challenge_ds::Vector<int> t2(10);
    assert(t2.size() == 10);
    assert(t2[0] == 0);
    assert(t2[9] == 0);
    //assert(t2[10] == 0);  // throws out of range

    // test constructor for given size and default value
    challenge_ds::Vector<int> t8(5, 3);
    assert(t8.size() == 5);
    assert(t8[3] == 3);
    assert(t8[2] == 3);

    // test initializer list constructor
    challenge_ds::Vector<int> t3{1,2,3,4};
    assert(t3.size() == 4);
    assert(t3[3] == 4);
    assert(t3[2] == 3);

    // test initializer list constructor
    challenge_ds::Vector<int> t4 = {5,6,7,8};
    assert(t4.size() == 4);
    assert(t4[3] == 8);
    assert(t4[2] == 7);

    // test constructor for existing vector with iterators
    challenge_ds::Vector<int> t5(t3.begin(), t3.end());
    assert(t5.size() == 4);
    assert(t5[3] == 4);
    assert(t5[2] == 3);

    // test copy constructor
    challenge_ds::Vector<int> t6(t3);
    assert(t6.size() == 4);
    assert(t6[3] == 4);
    assert(t6[2] == 3);

    // test move constructor
    challenge_ds::Vector<int> t7(std::move(t4));
    assert(t7.size() == 4);
    assert(t7[3] == 8);
    assert(t7[2] == 7);
    assert(t4.empty());
    assert(t4.size() == 0);
    assert(t4.capacity() == 0);
    assert(t4.data() == nullptr);
    
    // test size() const
    const challenge_ds::Vector<int> ct1{1,2,3,4,5,6};
    assert(ct1.size() == 6);

    // test empty()
    std::cout << "check if t1 is empty: " << t1.empty() << std::endl;
    std::cout << "check if t2 is empty: " << t2.empty() << std::endl;

    // test reserve()
    challenge_ds::Vector<int> t9{1,2,3,4,5,6};
    t9.reserve(3);  // nothing should happen according to reserve() documentation
    t9.reserve(10);
    assert(t9.size() == 6);
    assert(t9.capacity() == 10);
    assert(t9[3] == 4);
    assert(t9[2] == 3);
    assert(t9[5] == 6);
    t9.reserve(20);
    assert(t9.capacity() == 20);
    assert(t9.size() == 6);

    // test at()
    challenge_ds::Vector<int> t10{1,2,3,4,5,6,7};
    assert(t10.at(0) == 1);
    assert(t10.at(4) == 5);
    assert(t10.at(6) == 7);
    //assert(t10.at(7) == 7); // should throw an out of range error

    // test front()
    challenge_ds::Vector<int> t11;
    // int t = t11.front(); // should give a segmentation fault or undefined behavior
    assert(t10.front() == 1);
    
    // test back()
    //int tt = t11.back();  // should give segmentation faulr or undefined behavior
    assert(t10.back() == 7);

    // test data()
    int* ptr1 = t10.data();
    assert(ptr1[0] == 1);
    assert(ptr1[6] == 7);
    assert(t11.data() == nullptr);

    // test clear()
    t11.clear();  // nothing should happen if it's empty (nullptr)
    t10.clear();
    assert(t10.size() == 0);
    assert(t10.capacity() == 7);
    int t132 = t10[0];  // normally would expect segmentation fault, but primitive types don't get cleared in std::vector<T>::clear()
    std::cout << "first element of t10 after clear(): " << t132 << std::endl;
    assert(t10[0] == 1);

    // test resize()
    challenge_ds::Vector<int> t12{1,2,3,4,5,6};
    t12.resize(10);
    assert(t12.size() == 10);
    assert(t12.capacity() == 10);
    assert(t12[9] == 0);
    assert(t12[0] == 1);
    assert(t12[5] == 6);
    assert(t12[6] == 0);
    challenge_ds::Vector<int> t13;
    t13.resize(10);
    assert(t13.size() == 10);
    assert(t13.capacity() == 10);
    assert(t13[0] == 0);
    assert(t13[5] == 0);
    assert(t13[9] == 0);
    t13.resize(3);
    assert(t13.size() == 3);
    assert(t13.capacity() == 10);
    t13.resize(6);
    assert(t13.size() == 6);
    assert(t13.capacity() == 10);

    // test push_back() 
    challenge_ds::Vector<int> t14{1,2,3,4};
    t14.push_back(100);
    assert(t14.size() == 5);
    assert(t14.capacity() == 8);
    assert(t14[4] == 100);
    assert(t14[0] == 1);
    assert(t14[1] == 2);
    assert(t14[2] == 3);
    std::cout << "t14 with 4 elements and push_back one element gives 5 element in total. Accessing outside this range should give random values or segmentation faul: "
    << t14[5] << std::endl;
    challenge_ds::Vector<int> t15;
    t15.push_back(100);
    assert(t15.size() == 1);
    assert(t15.capacity() == 1);
    t15.push_back(200);
    t15.push_back(300);
    assert(t15.size() == 3);
    assert(t15.capacity() == 4);

    // test pop_back()
    challenge_ds::Vector<int> t16{1,2,3,4};
    t16.pop_back();
    assert(t16.size() == 3);
    assert(t16.capacity() == 4);
    assert(t16[2] == 3);
    std::cout << "t16 after pop_back to a list [1,2,3,4], when trying to access 4 now should get random value or seg fault, but if it's a primitive it will give back the original element since there's no destructor for them: " 
    << t16[3] << std::endl;
    //challenge_ds::Vector<int> t17;
    //t17.pop_back();  // should throw an error, trying to pop an empty container

    // test resize when default values are already initialized, and we overwrite them with newly initialized values.
    challenge_ds::Vector<int> s100{1,2,3,4,5,6};
    s100.resize(10);
    s100.resize(3);
    std::cout << s100[9] << " ";
    std::cout << "s100[10] should access memory outside so random value or seg fault: " << s100[10] << " ";
    s100.resize(11);
    std::cout << "s100[10] after resize(11) should now be default initialized to 0: " << s100[10] << " " << std::endl;

    // test copy assignment
    challenge_ds::Vector<int> s101{1,2,3};
    challenge_ds::Vector<int> s102{100,200,300,400,500,600,700};
    // expansion
    s101 = s102;
    assert(s101.size() == 7);
    assert(s101.capacity() == 7);
    assert(s101[6] == 700);
    std::cout << "s101[7], this should access memory outside so random val or seg fault: " << s101[7] << std::endl;
    // shrink
    challenge_ds::Vector<int> s103{99,100,101};
    s102 = s103;
    assert(s102.size() == 3);
    assert(s102.capacity() == 7);
    assert(s102[3] == 400);

    // test move assignment
    // expansion
    challenge_ds::Vector<int> s104{1,2,3,4,5,6};
    challenge_ds::Vector<int> s105{1,2,3,4,5,6,7,8,9};
    s104 = std::move(s105);
    assert(s104.size() == 9);
    assert(s104.capacity() == 9);
    assert(s104[8] == 9);
    assert(s104[5] == 6);
    std::cout << "s104[9] should give random value or seg fault: " << s104[9] << std::endl;
    // shrink
    challenge_ds::Vector<int> s106{1,2,3,4,5,6};
    challenge_ds::Vector<int> s107{1,2,3,4,5,6,7,8,9};
    s107 = std::move(s106);
    for (int e : s107) {
            std::cout << e << " ";
    }
    assert(s107.size() == 6);
    assert(s107.capacity() == 6);
    assert(s107[5] == 6);
    assert(s107[4] == 5);
    std::cout << "s107[9] should give random val or seg fault: " << s107[9] << std::endl;
    std::cout << "s107[8] should give random val or seg fault: " << s107[8] << std::endl;

    // test if for each loop and operator overload [] works
    challenge_ds::Vector<int> t{100,200,300,400,500,600};
    challenge_ds::Vector<int> true_vals_to_check{0,1,2,3,4,5};
    size_t j = 0;
    for (int e : t) {
        assert(t[j] == e);
        std::cout << "printing element from loop: " << e << std::endl;
        ++j;
    }
    for (int i=0; i < t.size(); ++i) {
        t[i] = i;
    }
    j = 0;
    for (int e : t) {
        assert(true_vals_to_check[j] == e);
        std::cout << "printing element from loop after changing values: " << e << std::endl;
        ++j;
    }
    const challenge_ds::Vector<int> ct2{1,2,3,4,5,6};
    for (int e : ct2) {
       std::cout << "printing element from const vector in a loop: " << e << std::endl; 
    }
}