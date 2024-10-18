/*
Write a program that converts spelled-out numbers such as “zero” and
“two” into digits, such as 0 and 2. When the user inputs a number, the
program should print out the corresponding digit. Do it for the values 0,
1, 2, 3, and 4 and write out not a number I know if the user enters something
that doesn’t correspond, such as stupid computer!.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string value {""};
    int number {0};
    std::vector <std::string> numbers {"zero", "one", "two", "three", "four"};
    std::cout << "Enter The Value: ";
    while(std::cin >> value) {
        std::istringstream iss(value);
        //Input Validation
        if(iss >> number && number<numbers.size())
            std::cout << numbers[number] << '\n';
        else {
            auto number_pointer = std::find(numbers.begin(), numbers.end(), value);
            if(number_pointer != numbers.end())
                std::cout << std::distance(numbers.begin(), number_pointer) << '\n';
            else
                std::cout << "Not a number I know!\n";
        }
    }

    return 0;
}
