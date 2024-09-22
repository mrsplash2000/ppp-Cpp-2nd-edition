#include "./11utils.h"
#include <string>
#include <iostream>
#include <format>
#include <sstream>
#include <unordered_map>


namespace Utils11{
    std::string prompts[6]{
        "penny",
        "nickel",
        "dime",
        "quarter",
        "half dollar",
        "one dollar"
    };

    std::unordered_map<std::string, int> money2cents{
        {"penny", 1},
        {"nickel", 5},
        {"dime", 10},
        {"quarter", 25},
        {"half dollar", 50},
        {"one dollar", 100}
    };


    std::string formatMoney(std::string type, int amount) {
        if (amount > 1) {
            if (type == "penny")
                return "pennies";
            return type + "s";
        }
        return type;
    }

    int computeTotalCents(std::unordered_map<std::string, int> balance) {
        int total{0};
        for (const auto& pair : balance)
            total +=  money2cents[pair.first] * pair.second;
        return total;
    }

    std::unordered_map<std::string, int> process_user_input_cents() {
        std::string input;
        std::unordered_map<std::string, int> userBalance;
        std::cout << "Please enter your money: " << std::endl;
        for (std::string p : prompts) {
            int amount;
            std::cout << std::format("{}: ", formatMoney(p, 2));
            while (true) {
                std::getline(std::cin, input);
                std::stringstream ss(input); // if concerned with initializing stringstream everytime user input is invalid, then can initialize it outside to reuse it and clear it after each iteration
                if (ss >> amount && ss.eof() && amount >= 0) {
                    userBalance[p] = amount;
                    break;
                }
                std::cout << "Invalid input. Please enter a valid integer!" << std::endl;
                std::cout << std::format("{}: ", p);
            }
        }
        for (std::string p : prompts) {
                std::cout << std::format("You have {} {}.", userBalance[p], formatMoney(p, userBalance[p])) << std::endl;
        }
        
        return userBalance;
    }
}