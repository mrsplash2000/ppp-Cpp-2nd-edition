#include "../std_lib_facilities.h"
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cctype>
#include <tuple>
#include <algorithm>
#include <sstream>

char getOperator() {
    std::string input;
    std::string valid_operators{"+-*/"};
    if (std::cin >> input && input.length() == 1 && valid_operators.find(input) != std::string::npos) {
        return (char) input[0];
    }
    else {
        throw std::runtime_error("Invalid operator. Only +,-,*,/ are allowed");
    }
}

double getDouble() {
    double v;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    if (ss >> v && ss.eof()) {
        return v;
    } else {
       throw std::runtime_error("Invalid input. Only double allowed."); 
    }
}

std::tuple<char, double, double> getInput() {
    return std::tuple<char, double, double>{getOperator(), getDouble(), getDouble()};
}

int compute(char op, double a, double b) {
    int res{0};
    switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
    }
    return res;
}

int main() {
    char op;
    double a, b;
    try {
        std::cout << "Enter operator followed by two double numbers. If more numbers are entered they will be ignored." << std::endl;
        std::tuple<char, double, double> t = getInput();
        // alternatively could also do auto [op, a, b] = getInput(); This is called structured binding, and is similar to how I do in Python with unpacking elements from collections
        op = std::get<0>(t);
        a = std::get<1>(t);
        b = std::get<2>(t);
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    } 
    std::cout << compute(op, a, b) << std::endl;
}