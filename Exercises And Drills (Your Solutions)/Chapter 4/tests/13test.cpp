#include <catch2/catch_test_macros.hpp>
#include "../sieve.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <exception>

std::vector<int> get_primes_up_to_n(std::vector<int> primes, int limit) {
  std::vector<int> true_values;
  for (int i=0; i < primes.size(); ++i) {
    if (primes[i] > limit)
      break;
    true_values.push_back(primes[i]);
  }
  return true_values;
}

std::vector<int> extract_primes_from_file(std::string filename) {
  std::ifstream file(filename);
  std::vector<int> primes;
  try {
      if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
          std::stringstream ss(line);
          std::string temp;

          int counter{};
          int offset{1};
          while (std::getline(ss, temp, ',')) {
            if (counter == offset) {
              primes.push_back(std::stoi(temp));
              offset += 3;
            }
            ++counter;
          }
        }
      file.close();
      }
      else {
        std::cerr << "Unable to open file." << std::endl;
      }

      return primes;
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

TEST_CASE("Testing primes up to n", "[sieve]") {
  // usually the caller should wrap around with try and catch, but whatever
  std::vector<int> primes = extract_primes_from_file("../P-100000.txt");
  REQUIRE(sieve(10) == get_primes_up_to_n(primes, 10));
  REQUIRE(sieve(50) == get_primes_up_to_n(primes, 50));
  REQUIRE(sieve(80) == get_primes_up_to_n(primes, 80));
  REQUIRE(sieve(100) == get_primes_up_to_n(primes, 100));
  REQUIRE(sieve(100000) == get_primes_up_to_n(primes, 100000));
}
