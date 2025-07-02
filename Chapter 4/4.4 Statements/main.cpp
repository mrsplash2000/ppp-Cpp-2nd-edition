#include <iostream>

int main() {
    //======Statements======
    //When statements follow each other, the computer executes them in the order in which they are written.
    //Here the declaration, with its initialization, is executed before the output expression statement.
    int a = 7;
    std::cout << a << '\n';
    std::cout << "===============1\n";

    //In general, we want a statement to have some effect. Statements without effect are typically useless.
    //Such statements without effects are typically logical errors, and compilers often warn against them.
    //warning: statement has no effect [-Wunused-value]|
    1+2; //do an addition but don't use the sum
    a*3; //do a multiplication but don't use the product

    //The Empty Statement
    //In other words, the if-statement doesn’t matter; y is going to get the value 5 regardless.
    int x {2};
    int y {3}; //warning: this 'if' clause does not guard... [-Wmisleading-indentation]|
    if (x==3);
    {y = 5;} //note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'if'
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << "===============2\n";
    //======Statements======

    //======if Statements======
    //Example 1: Simple Demonstration
    int c {0};
    int d {0};
    std::cout << "Please Enter Two Integers: ";
    std::cin >> c >> d;
    if(c<d) //condtion
        //1st alternative (taken if the condition is true)
        std::cout << "max(" << c << "," << d << ") is " << d << "\n";
    else
        //2nd alternative (taken if condition is false)
        std::cout << "max(" << c << "," << d << ") is " << c << "\n";
    std::cout << "===============3\n";

    //Example 2: We should always test for bad input
    constexpr double cm_per_inch {2.54}; //number of centimeters in an inch
    double length {1};
    char unit {0};
    std::cout << "Please Enter A Length Followed By a Unit (c or i): ";
    std::cin >> length >> unit;
    if(unit == 'i')
        std::cout << length << "in==" << cm_per_inch*length << "cm\n";
    else
        std::cout << length << "cm==" << length/cm_per_inch << "in\n";
    std::cout << "===============4\n";

    //Improved Version
    constexpr double cm_per_inch_two {2.54}; //number of centimeters in an inch
    double length_two {1};
    char unit_two {' '};
    std::cout << "Please Enter A Length Followed By a Unit (c or i): ";
    std::cin >> length_two >> unit_two;
    if(unit_two == 'i')
        std::cout << length_two << "in==" << cm_per_inch_two*length_two << "cm\n";
    else if(unit_two == 'c')
        std::cout << length_two << "cm==" << length_two/cm_per_inch_two << "in\n";
    else
        std::cout << "Sorry, I don't know a unit called ' " << unit_two << " '\n";
    std::cout << "===============5\n";

    /*
    NOTE: It may look as if we used an “else-if-statement,” but there is no such thing in C++.
    Instead, we combined two if-statements. What we did was to use an if-statement as the
    else part of an if-statement
    */

    /*
    NOTE: A sequence of statements delimited by curly braces { and } is called a block or a
    compound statement.
    */

    //Example 3: The empty block { } is sometimes useful for expressing that nothing is to be done.
    int num_one {45};
    int num_two {12};
    std::cout << "num_one = " << num_one << '\n';
    std::cout << "num_two = " << num_two << '\n';
    if(num_one <= num_two){
    }
    else {
        int t {num_one};
        num_one = num_two;
        num_two = t;
        std::cout << "t = " << t << '\n';
        std::cout << "num_one = " << num_one << '\n';
        std::cout << "num_two = " << num_two << '\n';
    }
    std::cout << "===============6\n";
    //======if Statements======

    //======switch Statements======
    //A selection based on comparison of a value against several constants.
    //Such selection is so common that C++ provides a special statement for it: the switch-statement.
    //The switch-statement syntax is archaic but still clearer than nested if-statements, especially when
    //we compare against many constants.
    constexpr double cm_per_inch_three {2.54}; //number of centimeters in an inch
    double length_three {1};
    char unit_three {'a'};
    std::cout << "Please Enter A Length Followed By a Unit (c or i): ";
    std::cin >> length_three >> unit_three;
    switch(unit_three){
        case 'i':
            std::cout << length_three << "in==" << cm_per_inch_three*length_three << "cm\n";
            break;
        case 'c':
            std::cout << length_three << "cm==" << length_three/cm_per_inch_three << "in\n";
            break;
        default:
            std::cout << "Sorry, I don't know a unit called ' " << unit_three << " '\n";
            break;
    }
    std::cout << "===============7\n";

    //NOTE: Don’t forget to end each case with a break. Unfortunately, the compiler probably won’t warn
    //you if you forget.
    //NOTE: To select based on a string you have to use an if-statement or a map.
    //NOTE: case label values must be constants and distinct.
    //You can label a single action by a set of case labels.
    std::cout << "Please Enter A Digit: ";
    char digit {0};
    std::cin >> digit;
    switch(digit) {
        case '0': case '2': case '4': case '6': case '8':
            std::cout << "is even.\n";
            break;
        case '1': case '3': case '5': case '7': case '9':
            std::cout << "is odd.\n";
            break;
        default:
            std::cout << "is not a digit.\n";
            break;
    }
    std::cout << "===============8\n";
    //======switch Statements======

    return 0;
}
