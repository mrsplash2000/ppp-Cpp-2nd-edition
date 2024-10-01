#include <iostream>
#include <exception>
#include <cmath>
#include "./sieve.h"

int main(int argc, char* argv[]) {
    try {
        int n{};
        if (argc == 3) {
            std::vector<int> primes;
            n = std::stoi(argv[1], nullptr);
            if (((std::string) argv[2]) == "max") {
                primes = sieve(n);
                std::cout << "Max prime less than or equal to " << n << ":" << std::endl;
                for (int e : primes)
                    std::cout << e << " ";
                std::cout << std::endl;
            }
            else {
                primes = sieve(ceil(n * log(n) * log(n) + n * log(n)));
                std::cout << "First " << n << " primes:" << std::endl; 
                for (int i=0; i < n; i++)
                    std::cout << primes[i] << " ";
                std::cout << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}