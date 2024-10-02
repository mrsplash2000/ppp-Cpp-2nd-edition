#include <iostream>
#include <limits>
#include <cstdint>

int main() {
    std::int64_t f1 = 0;
    std::int64_t f2 = 1;
    while (f1 <= std::numeric_limits<int>::max() && f2 <= std::numeric_limits<int>::max()) {
        f1 += f2;
        f2 += f1;
    }
    int answer = f1 <= std::numeric_limits<int>::max() ? f1 : f2;
    std::cout << "Highest possible fibonacci number in int: " << answer << std::endl;
    
    return 0;
}