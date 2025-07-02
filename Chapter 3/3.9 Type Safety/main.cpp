#include <iostream>

int main() {
    //Using a variable before it has been initialized is not considered type-safe
    //NOTE: Always initialize your variables!
    double x; //The value of x is undefined
    double y = x;
    double z = 2.0 + x;
    std::cout << "x=" << x << " y=" << y << " z=" << z << '\n'; //Produces garbage value

    //Safe Conversions: C++ provides indirect ways
    //char to int conversion safe
    char c = 'x';
    int d = c;
    int e = 'x';
    std::cout << c << " " << d << " " << e << '\n';
    char c2 = d;
    std::cout << c << " " << '<<d<<' << " " << c2 << '\n';  //Weird
    /*
    These conversions are safe:
        bool to char
        bool to int
        bool to double
        char to int
        char to double
        int to double
    */
    double number = 2.3;
    double number_two = number + 5; //5 is converted into 5.0 before adding

    //Unsafe Conversions
    //Such conversions are also called “narrowing” conversions, because they put a value into an object that may be too small (“narrow”) to hold it.
    int a = 20001;
    char character = a; //Squeezing a large int into a small char
    int bass = character;
    std::cout << "a=" << a << " character=" << character << " bass=" << bass << '\n';

    /*
    These conversions are unsafe but they are accepted by the compiler:
        double to int
        double to char
        double to bool
        int to char
        int to bool
        char to bool
    */

    //Type Safety Example
    //This program shows you what character (if any) your machine will print for a given integer value.
    double h = 0;
    while(std::cin >> h) {
        int i = h;
        char v = h;
        int i2 = v;
        std::cout << "h==" << h
                 << " i==" << i
                 << " i2==" << i2
                 << " char(" << v <<")\n";
    }

    //IMPORTANT: C++11 introduced an initialization notation that outlaws narrowing conversions. For example, we could (and should)
    //rewrite the troublesome examples above using a {}-list notation, rather than the = notation
    //Use {} initializers to avoid accidents, and when you want a conversion, check the value before assigning as we did in the first
    //example in this section.
    double my_number {2.56};  //OK
    //int y {my_number};              //error: double -> int might narrow
    return 0;
}
