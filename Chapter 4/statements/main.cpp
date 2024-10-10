#include <iostream>
using namespace std;

int main() {
    //======Statements======
    //When statements follow each other, the computer executes them in the order in which they are written.
    //Here the declaration, with its initialization, is executed before the output expression statement.
    int a = 7;
    cout << a << '\n';

    //In general, we want a statement to have some effect. Statements without effect are typically useless.
    //Such statements without effects are typically logical errors, and compilers often warn against them.
    1+2; //do an addition but don't use the sum
    a*3; //do a multiplication but don't use the product

    //The Empty Statement
    //In other words, the if-statement doesn’t matter; y is going to get the value 5 regardless.
    int x {2};
    int y {3};
    if (x==3);
    { y = 5;}
    cout << x << '\n';
    cout << y << '\n';
    //======Statements======

    //======if Statements======
    //Example 1: Simple Demonstration
    int c {0};
    int d {0};
    cout << "Please Enter Two Integers: ";
    cin >> c >> d;
    if(c<d) //condtion
        //1st alternative (taken if the condition is true)
        cout << "max(" << c << "," << d << ") is " << d << "\n";
    else
        //2nd alternative (taken if condition is false)
        cout << "max(" << c << "," << d << ") is " << c << "\n";

    //Example 2: We should always test for bad input
    constexpr double cm_per_inch {2.54}; //number of centimeters in an inch
    double length {1};
    char unit {0};
    cout << "Please Enter A Length Followed By a Unit (c or i): ";
    cin >> length >> unit;
    if(unit == 'i')
        cout << length << "in==" << cm_per_inch*length << "cm\n";
    else
        cout << length << "cm==" << length/cm_per_inch << "in\n";
    //Improved Version
    constexpr double cm_per_inch_two {2.54}; //number of centimeters in an inch
    double length_two {1};
    char unit_two {' '};
    cout << "Please Enter A Length Followed By a Unit (c or i): ";
    cin >> length_two >> unit_two;
    if(unit_two == 'i')
        cout << length_two << "in==" << cm_per_inch_two*length_two << "cm\n";
    else if(unit_two == 'c')
        cout << length_two << "cm==" << length_two/cm_per_inch_two << "in\n";
    else
        cout << "Sorry, I don't know a unit called ' " << unit_two << " '\n";

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
    if(num_one <= num_two){
    }
    else {
        int t {num_one};
        num_one = num_two;
        num_two = t;
    }
    //======if Statements======

    //======switch Statements======
    //A selection based on comparison of a value against several constants.
    //Such selection is so common that C++ provides a special statement for it: the switch-statement.
    //The switch-statement syntax is archaic but still clearer than nested if-statements, especially when
    //we compare against many constants.
    constexpr double cm_per_inch_three {2.54}; //number of centimeters in an inch
    double length_three {1};
    char unit_three {'a'};
    cout << "Please Enter A Length Followed By a Unit (c or i): ";
    cin >> length_three >> unit_three;
    switch(unit_three){
        case 'i':
            cout << length_three << "in==" << cm_per_inch_three*length_three << "cm\n";
            break;
        case 'c':
            cout << length_three << "cm==" << length_three/cm_per_inch_three << "in\n";
            break;
        default:
            cout << "Sorry, I don't know a unit called ' " << unit_three << " '\n";
            break;
    }
    //NOTE: Don’t forget to end each case with a break. Unfortunately, the compiler probably won’t warn
    //you if you forget.
    //NOTE: To select based on a string you have to use an if-statement or a map.
    //NOTE: case label values must be constants and distinct.
    //You can label a single action by a set of case labels.
    cout << "Please Enter A Digit: ";
    char digit {0};
    cin >> digit;
    switch(digit) {
        case 0: case 2: case 4: case 6: case 8:
            cout << "is even.\n";
            break;
        case 1: case 3: case 5: case 7: case 9:
            cout << "is odd.\n";
            break;
        default:
            cout << "is not a digit.\n";
            break;
    }
    //======switch Statements======

    return 0;
}
