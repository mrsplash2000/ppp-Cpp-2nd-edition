/*
Write a program that performs as a very simple calculator. Your calculator
should be able to handle the four basic math operations — add, subtract,
multiply, and divide — on two input values. Your program should prompt
the user to enter three arguments: two double values and a character to
represent an operation. If the entry arguments are 35.6, 24.1, and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6
we look at a much more sophisticated simple calculator.
*/

#include <iostream>
#include <cmath>

int main() {
    //Variables
    double num_one {0}, num_two {0};
    char operation {'+'};

    //Prompt for user input
    std::cout << "Enter two numbers followed by the operator: ";
    std::cin >> num_one >> num_two >> operation;

    switch(operation) {
        case '+':
            std::cout << "The sum of " << num_one << " and " << num_two << " is " << num_one+num_two << '\n';
            break;
        case '-':
            std::cout << "The difference between " << num_one << " and " << num_two << " is " << std::abs(num_one-num_two) << '\n';
            break;
        case '/':
            std::cout << num_one << " divided by " << num_two << " is " << num_one/num_two << '\n';
            break;
        case '*':
            std::cout << num_one << " times " << num_two << " is " << num_one*num_two << '\n';
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
