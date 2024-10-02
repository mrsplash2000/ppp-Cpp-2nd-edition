# Notes

## How to run
In Chapter 5 folder to run exercise 11
```
make 11
./11
```

To run the tests assuming you have Catch2 installed and is in Chapter 5 folder
```
cd tests
mkdir build
cd build
cmake .. .
make
./11test
```

And if run successfully should show something like
```c++
Randomness seeded to: 4294967295
===============================================================================
All tests passed (6 assertions in 1 test case)
```

## 11
Apparently one can compute this mathematically, credits to [Paolo Leonetti](https://math.stackexchange.com/questions/2655762/finding-index-of-closest-fibonacci-number-to-a-given-value).
Using [Binet's formula](https://en.wikipedia.org/wiki/Fibonacci_sequence#Closed-form_expression) for computing a closed-form expression of fibonacci number 

$$F_n = \dfrac{\phi^n - \psi^n }{\sqrt{5}}$$

where $\phi = \dfrac{1 + \sqrt{5}}{2}$ called the [golden ratio](https://en.wikipedia.org/wiki/Golden_ratio) and $\psi = \dfrac{1 - \sqrt{5}}{2}$ is the conjugate to the golden ratio.
We can observe that $|\psi| < 1$ and therefore asymptotically leads to $\mathcal{o}(1)$ as n grows, meaning it will never grow bigger than 1, so it has no impact. This means we have

$$F_n = \dfrac{\phi^n}{\sqrt{5}} + \mathcal{o}(1)$$

To find the closest value to a given integer x that is fibonacci we need to minimize the following expression by setting it to zero

$$\left|\dfrac{\phi^n}{\sqrt{5}} - x\right| = 0$$

Solving for n gives us

$$n = \dfrac{\ln (x\sqrt{5})}{\ln \phi}$$

The biggest value $x$ as an int in c++ is 2147483647. Inserting this into the formula above gives us 

$$n = \left \lfloor{\dfrac{\ln (2147483647 \cdot \sqrt{5})}{\ln \phi}}\right \rfloor = 46$$

This means that the 46th fibonacci number is closest to the higest possible int value in c++, this number is precisely 1836311903 taken from a fibonacci table on the internet. This seems to be correct, given that the table is correct, since the 47th fibonacci is 2971215073, which is higher than the highest possible int.

Otherwise a simple solution is to just compute the fibonacci using the regular recursive formula 

$$F_n = F_{n-1} + F_{n-2}$$

where $F_0 = 0$ and $F_1 = 1$, since we have confirmed that the answer is the 46th fibonacci, this can be computed fairly fast if we use the trick where we don't need to store anything other than two variables. Bottom-up or top-down DP fibonacci would also work.

```c++
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
```

Running this program gives the same answer, and should confirm that it's correct, unless both are wrong, which I highly doubt.