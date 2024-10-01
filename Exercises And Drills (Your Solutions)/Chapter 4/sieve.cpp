#include <cmath>
#include <vector>
#include <algorithm>
#include "./sieve.h"

std::vector<int> sieve(int limit) {
    // we skip entry on index 0 and 1
    std::vector<bool> A(limit + 1, true);
    for (int i=2; i <= (int) sqrt(limit); ++i) {
        if (A[i]) {
            for (int j=pow(i, 2); j <= limit; j+= i) {
                A[j] = false;
            }
        }
    }
    std::vector<int> primes{};
    for (int i=0; i < A.size(); ++i) {
        // skip entry on index 0 and 1
        if (A[i] && i > 1)
            primes.push_back(i);
    }

    return primes;
}