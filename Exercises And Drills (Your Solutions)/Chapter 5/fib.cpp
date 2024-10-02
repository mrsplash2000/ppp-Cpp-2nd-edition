#include "./fib.h"
#include <limits>
#include <cstdint>
#include <stdexcept>

double fib(int n) {
    double f1 = 0;
    double f2 = 1;
    if (n < 0) throw std::invalid_argument("Negative input not allowed!");
    if (n == 0) return f1;
    if (n == 1) return f2;
    int count{1};
    bool isf1 = false;
    while (count < n) {
        if (count < n) {
            f1 += f2;
            ++count;
            isf1 = true;
        }
        if (count < n) {
            f2 += f1;
            ++count;
            isf1 = false;
        }
    }
    return isf1 ? f1 : f2;
}