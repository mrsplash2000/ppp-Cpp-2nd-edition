#include "./11utils.h"
#include <iostream>
#include <map>
#include <tuple>
#include <map>
#include <stack>
#include <vector>
#include <exception>
#include <sstream>
#include <format>

/*
Last exercise in chapter 3, although different, reminded me of this project euler problem 31 (https://projecteuler.net/problem=31):

In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Answer:  73682
*/

int coins[8] {1, 2, 5, 10, 20, 50, 100, 200};

int topDownRecursiveNoDP(int target, int previous) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    int count{0};
    for (int coin : coins) {
        if (coin >= previous)
            count += topDownRecursiveNoDP(target - coin, coin);
    }
    
    return count;
}

int topDownIterativeNoDP(int target) {
    std::stack<std::tuple<int, int>> func_calls;
    int res{0}; // global bookkeeper of function results

    // here is the main loop that emulates the function calls and executing the code in the function
    func_calls.push(std::tuple(target, 0));
    while (!func_calls.empty()) {
        std::tuple<int, int> curr = func_calls.top();
        auto [target, prev] = curr;
        func_calls.pop();

        if (target == 0) res += 1;
        else if (target < 0) res += 0;
        else {
            for (int coin : coins) {
                if (coin >= prev)
                    func_calls.push(std::tuple<int, int>(target - coin, coin)); // this one here is to emulate the function call ordering by using a stack FIFO ordering
            }
        }
    }
    return res; 
}

std::map<std::tuple<int, int>, int> memoize; // ((target, prev), count)
int topDownRecursiveDP(int target, int previous) {
    if (target == 0)
        return 1;
    if (target < 0) 
        return 0;

    std::tuple<int, int> t{target, previous};
    if (memoize.find(t) != memoize.end()) {
        return memoize[t];
    }

    int count{0};
    for (int coin : coins) {
        if (coin >= previous)
            count += topDownRecursiveDP(target - coin, coin);
    }

    memoize[std::tuple<int, int> {target, previous}] = count;

    return count;
}

// This one failed, just a direct translation to iterative approach with a stack, which obviously doesn't work since res is global over all the subproblems
int topDownIterativeDPFAIL(int target) {
   std::stack<std::tuple<int, int>> func_calls;
   int res{0};
   std::map<std::tuple<int, int>, int> cache;

   func_calls.push(std::tuple<int, int>(target, 0));
   while(!func_calls.empty()) {
    auto [target, prev] = func_calls.top();
    func_calls.pop();

    if (target == 0) {
        res += 1;
        continue;
    }
    if (target < 0) {
        continue;
    }
    
    std::tuple<int,int> t{target,prev};
    if (cache.find(t) != cache.end()) {
        res+= cache[t];
        continue;
    }

    for (int coin : coins) {
        if (coin >= prev)
            func_calls.push(std::tuple<int,int>{target - coin, coin});
    }
    cache[std::tuple<int, int>{target, prev}] = res;
   }
   return res;
}

int main() {
    //int target{200};
    try {
        std::unordered_map<std::string, int> userBalance = Utils11::process_user_input_cents();
        int target = Utils11::computeTotalCents(userBalance);
        std::cout << std::format("You total balance in cents is: {}", target) << std::endl;
        std::cout << topDownRecursiveNoDP(target, 0) << std::endl;
        std::cout << topDownRecursiveDP(target, 0) << std::endl;
        std::cout << topDownIterativeNoDP(target) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}