/*
Write a program in C++ that converts from miles to kilometers. Your
program should have a reasonable prompt for the user to enter a number
of miles. Hint: There are 1.609 kilometers to the mile.
*/

#include <iostream>

int main() {
    double miles {0};
    std::cout << "Enter the number of miles: ";
    while(std::cin >> miles)
        std::cout << miles << " = " << miles*1.609 << " kilometers" <<'\n';
    return 0;
}
