/*
Make a vector holding the ten string values "zero", "one", . . . "nine".
Use that in a program that converts a digit to its corresponding
spelled-out value; e.g., the input 7 gives the output seven. Have the same
program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> //std::find

int main() {

    for(std::string input {""}; std::cin >> input;) {

        //Variables
        int number {0};
        std::vector <std::string> numbers {
            "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"
        };
        std::istringstream iss(input);

        //Input Validation
        if(iss >> number && number<numbers.size())
            std::cout << numbers[number] << '\n';
        else {
            auto number_pointer = std::find(numbers.begin(), numbers.end(), input);
            if(number_pointer != numbers.end()) {
                int index {std::distance(numbers.begin(), number_pointer)};
                std::cout << index << '\n';
            }
            else
                std::cout << "Number Not Found!\n";
        }
    }
    return 0;
}
