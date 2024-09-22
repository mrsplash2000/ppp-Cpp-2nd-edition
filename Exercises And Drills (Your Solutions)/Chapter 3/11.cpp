#include "../std_lib_facilities.h"
#include "./11utils.h"
#include <map>
#include <sstream>
#include <format>
#include <exception>

double convertToDollars(int balance) {
    return (double) balance / 100;
}

int main() {
    try {
        std::unordered_map<std::string, int> userBalance = Utils11::process_user_input_cents();
        double dollars = convertToDollars(Utils11::computeTotalCents(userBalance));
        std::cout << std::format("The value of all your coins is ${}.", dollars) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
}