/*
Modify the “mini calculator” from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.
*/

#include <iostream>
#include <vector>
#include <cmath> //std::abs
#include <sstream>
#include <algorithm> //std::find


int input_validation() {
    std::string input {""};
    std::vector <std::string> numbers {
            "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"
    };
    int number {0};
    std::cin >> input;

    //Quit mechanism
    if(input == "quit")
        std::exit(0);

    //Input Validation
    std::istringstream iss(input);
    if(iss >> number && number<numbers.size())
        return number;
    else {
        auto number_pointer = std::find(numbers.begin(), numbers.end(), input);
        if(number_pointer != numbers.end()) {
            int index {std::distance(numbers.begin(), number_pointer)};
            return index;
        } else
            throw std::invalid_argument("Error: Invalid number.\n");
    }
}

int main() {

    while(true) {
        //Variables
        char operation {'+'};

        try {
            //Prompt for user input + Input validation
            std::cout << "Enter two numbers followed by the operator: ";
            int num_one {input_validation()};
            int num_two {input_validation()};

            //Operation
            std::cin >> operation;
            switch(operation) {
                case '+':
                    std::cout << "The sum of " << num_one << " and " << num_two << " is " << num_one+num_two << '\n';
                    break;
                case '-':
                    std::cout << "The difference between " << num_one << " and " << num_two << " is " << std::abs(num_one-num_two) << '\n';
                    break;
                case '/':
                    if (num_two == 0)
                        std::cout << "Error: Division by zero is not allowed.\n";
                    else
                        std::cout << num_one << " divided by " << num_two << " is " << num_one * 1.0 / num_two * 1.0 << '\n';
                    break;
                case '*':
                    std::cout << num_one << " times " << num_two << " is " << num_one*num_two << '\n';
                    break;
                default:
                    std::cout << "Invalid choice!\n";
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << "Please try again.\n";
        }
    }

    return 0;
}
