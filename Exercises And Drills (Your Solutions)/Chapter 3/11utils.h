#pragma once
#include <string>
#include <unordered_map>

namespace Utils11 {
    extern std::string prompts[6];
    extern std::unordered_map<std::string, int> money2cents;
    std::string formatMoney(std::string type, int amount);
    int computeTotalCents(std::unordered_map<std::string, int> balance);
    std::unordered_map<std::string, int> process_user_input_cents();
}