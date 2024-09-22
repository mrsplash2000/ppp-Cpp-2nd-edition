#include "../std_lib_facilities.h"
#include <map>
#include <functional>
#include <exception>
#include <sstream>

void first_sol(std::string input) {
    if (input == "zero") {
        std::cout << 0 << std::endl;
    }
    else if (input == "one") {
        std::cout << 1 << std::endl;
    }
    else if (input == "two") {
        std::cout << 2 << std::endl;
    }
    else if (input == "three") {
        std::cout << 3 << std::endl;
    }
    else if (input == "four") {
        std::cout << 4 << std::endl;
    }
    else if (input == "five") {
        std::cout << 5 << std::endl;
    }
    else if (input == "six") {
        std::cout << 6 << std::endl;
    }
    else if (input == "seven") {
        std::cout << 7 << std::endl;
    }
    else if (input == "eight") {
        std::cout << 8 << std::endl;
    }
    else if (input == "nine") {
        std::cout << 9 << std::endl;
    }
    else {
        std::cout << "Not a number I know" << std::endl;
    }
}

void second_sol(std::string input) {
    // could make this global, so that don't need to intiailize it everytime, but doesn't matter in this case
    // because I think the map is stored in the stack, and once the function has returned then
    // the memory will be released from the stack?
    // there are different solutions here though, global (if okay with exposing it)
    // or use static, it will be instantiated once and preserved throughout the calls
    static std::unordered_map<std::string, int> string2digit{
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };
    if (string2digit.find(input) != string2digit.end())
        std::cout << string2digit[input] << std::endl;
    else {
        std::cout << "Not a number I know" << std::endl;
    }
}

int getValidApproach() {
    std::string input;
    int value;
    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (ss >> value && (value == 1 || value == 2) && ss.eof()) {
            return value;
        }
        else {
            std::cout << "Not a valid approach, try again!" << std::endl;
        }
    }
}

int main() {
    std::string input;
    int chosen_approach{1}; // use first solution by default
    std::unordered_map<int, std::function<void(std::string)>> approaches = {
        {1, [](std::string input) {first_sol(input);}},
        {2, [](std::string input) {second_sol(input);}}
    };
    
    std::cout << "Enter an approach integer 1 or 2: ";
    try {
        chosen_approach = getValidApproach();
        std::cout << "Enter spelling of number, i.e. nine for 9, eight for 8 etc..." << std::endl;
        while (std::cin >> input) {
            approaches[chosen_approach](input);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}