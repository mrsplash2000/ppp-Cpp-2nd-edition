#include <iostream>

//An expression computes a value from a number of operands.

int main() {
    //======Expressions======
    //compute area
    int length {10}; //a literal integer (used to initialize a variable)
    int width {20};
    int area {length*width}; //multiplication

    std::cout << "Area: " << area << '\n';

    length = 99; //assign 99 to length

    //We can make more complicated expressions by combining expressions. When needed, we
    //can use parentheses to group expressions:
    int perimeter {(length+width)*2}; //add then multiply
    //Without parentheses, we’d have had to say:
    int perimeter_two {length*2 + width*2};
    //which is clumsy, and we might even have made this mistake (which is a logical error and
    //the compiler can't recognize it):
    int perimeter_three {length+width*2}; //add width*2 to length
    //NOTE: The usual mathematical rules of operator precedence apply.

    std::cout << "Perimeter: " << perimeter << '\n';
    std::cout << "Perimeter: " << perimeter_two << '\n';
    std::cout << "Perimeter: " << perimeter_three << '\n';
    std::cout << "================\n";

    //======Constant Expressions======
    //C++ offers the notion of a symbolic constant, that is, a named object to which you can’t
    //give a new value after it has been initialized.
    constexpr double pi {3.14159265359};
    //pi = 7; //error: assignment to constant
    double c {2*pi*4}; //OK: we just read pi; we don’t try to change it
    std::cout << c << '\n';

    //A constexpr symbolic constant must be given a value that is known at compile time.
    //Try this code outside main function.
    /*
    constexpr int maximum = 100;
    void use(int n) {
        constexpr int c1 {maximum+7}; //OK: c1 is 107
        constexpr int c2 {n+7}; //error: we don't know the value of c2
    }
    */



    //To handle cases where the value of a “variable” that is initialized with a value that
    //is not known at compile time but never changes after initialization, C++ offers a
    //second form of constant (a const)
    //Try this code outside main function.
    /*
    constexpr int maximum_two {100};
    void use(int n) {
        constexpr int c1 = maximum+7; //OK: c1 is 107
        const int c2 = n+7; //OK: but don't try to change the value of c2
        c2 = 7; // error: c2 is a const
    }
    */


    /*
    In other words, the difference between const and constexpr is that:
    You can initialize a const variable to a value within a function through its argument
    But, you can't do that with constexpr.
    The similarity between both of them is that:
    AFTER INITIALIZING A CONSTANT VARIABLE, YOU CAN'T CHANGE IT AFTERWARDS.
    */
    std::cout << "================\n";

    //======Conversions======
    //The type{value} notation prevents narrowing, but the type(value) notation does not.
    double d = 2.5;
    int i = 2;
    double d2 = d/i;  //d2 == 1.25
    int i2 = d/i;  //i2 == 1
    //int i3 {d/i}; //error: double -> int conversion may narrow
    std::cout << d << '\n';
    std::cout << i << '\n';
    std::cout << d2 << '\n';
    std::cout << i2 << '\n';
    std::cout << "================\n";


    //NOTE: it is easy to forget about integer division in an expression that also contains
    //floating-point operands.
    //Example: Consider the usual formula for converting degrees Celsius to degrees Fahrenheit:
    //f = 9/5 * c + 32.
    double dc {0};
    std::cin >> dc;
    double df = 9/5*dc+32; //beware
    double degfr = 9.0/5*dc+32; //better
    std::cout << df << '\n';
    std::cout << degfr << '\n';
    std::cout << "================\n";

    return 0;
}
