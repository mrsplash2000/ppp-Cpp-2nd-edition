/*
Write a program that takes an operation followed by two operands and
outputs the result. For example:
+ 100 3.14
* 4 5
Read the operation into a string called operation and use an
if-statement to figure out which operation the user wants, for example,
if (operation=="+"). Read the operands into variables of type double.
Implement this for operations called +, –, *, /, plus, minus, mul, and div
with their obvious meanings.
*/

#include <iostream>

int main() {
    char operation {'+'};
    double value1 {0}, value2 {0};
    std::cout << "Enter your operation symbol and two values: ";
    std::cin >> operation >> value1 >> value2;
    switch(operation) {
        case '+':
            std::cout << value1 + value2 << '\n';
            break;
        case '-':
            std::cout << value1 - value2 << '\n';
            break;
        case '*':
            std::cout << value1 * value2 << '\n';
            break;
        case '/':
            std::cout << value1 / value2 << '\n';
            break;
        default:
            std::cout << "Unknown Operation!" << '\n';
    }
    return 0;
}
