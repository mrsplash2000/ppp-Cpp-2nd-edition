#include <catch2/catch_test_macros.hpp>
#include "../fib.h"
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdint>
#include <iostream>
#include <cmath>


bool compare_float(double a, double b, double epsilon = 1e-9) {
    return fabs(a - b) < epsilon;
}

// trim trailing and leading white spaces
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return ""; // All whitespace
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

std::vector<double> extract_fib_from_file(std::string filename) {
    std::ifstream file(filename);
    std::vector<double> fibonacci;
    try {
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line, ',')) {
                std::string trimmed = trim(line);
                if (!trimmed.empty()) {
                    double number = std::stod(trimmed);
                    fibonacci.push_back(number);
                }
            }
            file.close();
        }
        else {
            std::cerr << "Unable to open file." << std::endl;
        }

        return fibonacci;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

TEST_CASE("Test correctness of fibonacci", "[fib]") {
    std::vector<double> fibonacci = extract_fib_from_file("../fibonacci.txt");
    double epsilon = 1e-9;
    REQUIRE(compare_float(fibonacci[0], fib(0), epsilon));
    REQUIRE(compare_float(fibonacci[1], fib(1), epsilon));
    REQUIRE(compare_float(fibonacci[2], fib(2), epsilon));
    REQUIRE(compare_float(fibonacci[3], fib(3), epsilon));
    REQUIRE(compare_float(fibonacci[46], fib(46), epsilon));
    REQUIRE(compare_float(fibonacci[999], fib(999), epsilon));
}