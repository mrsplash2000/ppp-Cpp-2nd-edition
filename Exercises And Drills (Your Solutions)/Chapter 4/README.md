# Notes on exercises
## How to run
**Exercise 13-15**

In chapter 4 folder run `make 13`, which will compile `13.out` executable file to run the program for exercise 13 (sieve). It takes as arguments $n$, which is the limit for the sieve algorithm i.e. to generate primes less than or equal to $n$, and the string max or first, to solve exericse 14 and 15. Furthermore, I didn't include the file containing 100000 first primes, since it was around 2mb. It's only used for the test suite to compare the sieve output with the correct prime values. The site to download the first 100k primes is [here](https://naturalnumbers.org/primes.html).

**Run the test suite for the sieve method**

Need to install [Catch2](https://github.com/catchorg/Catch2), which is a testing framework for c++, there are also other popular ones like [google test](https://github.com/google/googletest) which offers more advanced testing features than Catch2, but I just needed a simple one so I opted for Catch2. If you choose google test, then the test suite will need to be rewritten in accordance to the google test api. Depending on installation choice, the relevant library files might be different, for me it was 

```
libCatch2Main.a and libCatch2.a
```

But in other instances it might be just

```
libCatch2WithMain.a
```

Furthermore, in the `CMakeLists.txt` the compiler path might be different to yours. For me it's `/usr/bin/g++`. If you are in the `chap4` folder then build the tests in a `build` folder in the `tests` folder by doing

```
cd tests
mkdir build
cd build
cmake .. .
make
```

After building the test suite and when running it successfully it should print out something like this 
```c++
Randomness seeded to: 4294967295
===============================================================================
All tests passed (5 assertions in 1 test case)
```

## Sieve
The overall idea for the sieve is to set everything up to $n$ as a prime (boolean true) and then only focus on removing the ones that are not prime (set to false). This makes it easier as can just skip the primality test, and jump straight to weeding out the ones that are fake primes by removing multiples of primes up to $n$ each time. The result of the algorithm is all primes up to number $n$.

A faster algorithm and less memory heavy, both in $\mathcal{O}(n)$, is [sieve of atkins (2003)](https://en.wikipedia.org/wiki/Sieve_of_Atkin), but I don't have time to look at it, so I will skip.

### **Intuition**
This section is just to give an intuition on why sieve works. Unfortunately, this entire section feels like a mouthful of something that can be shown in a few paragraphs. **Note that this is in no way a rigorous proof of the correctness of sieve, it's just to give an intuition.**

#### **All non-prime numbers are factors of primes or multiples of primes.**
A prime is a number that has no other divisor (numbers that can evenly divide it with no remainders) other than itself and 1. For instance, 7 is a prime, since only 7 and 1 are divisors to it, other numbers trying to divide it such as 3,4,5,6 would have given a non-zero remainder. Consequently, numbers that are non-prime must be composites (a product of more than 1 factor) of primes, because they are divisible by other numbers that are not themselves or 1, since if they weren't then they would just be primes as well. However, we know that there exists non-prime numbers, so it must be true that non-primes are composites of primes. For instance 16 is not a prime and it's composition is $16 = 8 \cdot 2 = 2 \cdot 2 \cdot 2 \cdot 2$. One could object here and say that 8 is not a prime, and since 16 is a composition of 2 and 8, then the argument is invalid, but since 8 is not a prime it means that it can also be decomposed into prime numbers, which can be seen in the latter expression $8 = 2 \cdot 2 \cdot 2$, so this should give intuition to the fact that all non-prime numbers can be prime factorized, and are therefore a composition of primes.

Why is this theorem important to know about? Because it's what the inner loop of sieve is based on, the fact that non-primes are just multiples of primes makes it possible to weed these out by simply computing the multiples of a prime less than n and set these to false in the bool array of primes.

#### **Every composite number n has a divisor less than or equal to $\sqrt{n}$.**
The idea is $\sqrt{n} * \sqrt{n} = n$ and is the maximum composition or closest composition you can get to the number n without going over. If both positive integer numbers, let's call them $a$ and $b$ were bigger than $\sqrt{n}$, then by definition their product would be bigger than n 

$$a,b > \sqrt{n} \implies a \cdot b > n$$

so therefore one divisor has to be less than or equal to $\sqrt{n}$, while the other has to be greater than or equal, because otherwise by definition the product will be less than n if both a and b are less than $\sqrt{n}$ 

$$
a,b < \sqrt{n} \implies a \cdot b < n
$$

This can naturally be extended to multiple numbers with modification to nth root instead of square root.
The point of utilizing this theorem is to find a point where we can end the loop earlier, rather than going through all the way up to n. This goes hand in hand with the inner loop, where $i$ starts from $i^2$, because we won't miss any potential starting prime values ($\text{prime} \cdot \text{multiplier}$) that are needed to identify the fake primes that are multiples of them, since we can expect them to be less than or equal to $\sqrt{n}$. If they are bigger than $\sqrt{n}$, then we would start to go over $n$, which is unecessary because we just want to find all primes up to $n$.

#### **Why start from $i^2$ in the inner loop?**
Because for a given $i$, multiples of it, say by positive numbers $k > 1$ such that $i \cdot k$, will be checked in each iteration in the inner loop. That means that the previous $i$ values will have already checked for multiples lower than $i$ i.e. $k < i$, so therefore to avoid double checking something that has already been checked we need to start from $i^2$. This is much easier to see with an example. Let's assume $n=16$. Then for $i=2$, $i=3$ and $i=4$ we have for the inner loop (note that values going over n would never be computed, but I include them for illustrative purposes)

$$
\begin{array}{l|l|l}
i=2 & i=3 & i=4 \\
2 \cdot 2 = 4  & \textcolor{green}{3 \cdot 2}  = 6 & \textcolor{pink}{4 \cdot 2} = 8 \\
\textcolor{green}{2 \cdot 3} = 6  & 3 \cdot 3 = 9 & \textcolor{orange}{4 \cdot 3} = 12 \\
\textcolor{pink}{2 \cdot 4} = 8  & \textcolor{orange}{3 \cdot 4}  = 12 & 4 \cdot 4 = 16 \\
2 \cdot 5 = 10 & 3 \cdot 5 = 15 & 4 \cdot 5 = 20 \\
\end{array}
$$

So we can clearly see here that the pattern is the same for subsequent $i$, that all the previous multiples $k < i$ will have been computed already in the previous $i$ values for a given $i$. For instance looking at $4 \cdot k$, we can see that for $k < 4$, i.e. $4 \cdot 3$, $4 \cdot 2$, these values have already been computed in previous iterations in the outer loop, meaning these positions in the bool array have already been set to false, so long as they are less than or equal to n. If they are bigger than n, then obviously $i^2$ would also be too big, and we wouldn't even look at it. Therefore, there is no need to iterate over these values, and instead we should start from $i^2$ in the inner loop.

Why is this insight important? In combination with the last theorem

> Every composite number n has a divisor less than or equal to $\sqrt{n}$.

From this section we showed that we can be sure that for a current $i^2$ in the inner loop, $i \cdot k$, where $ 1 < k < i$ will already have been computed (set to false), so we need to only focus on $i^2 + i \cdot k$, where $ 1 \leq k$, but only so far as $i^2 + i \cdot k \leq n$, where $i \leq \sqrt{n}$, otherwise we would go over $n$. This together with the insight of the current section will guarantee to catch all the necessary non-primes less than or equal to $n$.

#### **Putting it together - why does Sieve work?**
First theorem established that we only need to look at multiple of primes to identify non-primes that we can set to false. Second theorem guarantees a bound to stop early instead of looping up to $n$. This bound in addition to how the inner loop works is sufficient to catch all the non-primes. The last observation explains why we can just start from $i^2$ in the inner loop, because multiples of the current $i$ will have already been computed. These two theorems and the observation together should give an intuition to the correctness of sieve. Why? Because if there were non-primes less than or equal to $n$ that still haven't been computed the loop would still be going until we compute them. We can be sure of this because the second theorem says

> Every composite number n has a divisor less than or equal to $\sqrt{n}$.

so a non-prime that is less than or equal to $n$ will be set to false eventually, because one of it's prime factors cannot be bigger than $\sqrt{n}$, and the outer loop will check all such numbers less than or equal to $\sqrt{n}$, so the inner loop of sieve will always be able to reach the non-prime number since the only condition to end the inner loop is when it's bigger than $n$.



### **Time complexity**
It's stated as $\mathcal{O}(n \log \log n)$. The outer loop may be looping from 2 to $\sqrt{n}$, but only the ones that are prime will be evaluated in the inner loop. We can directly compute the total number of operations that will be done over the entire algorithm. The inner loop is $\mathcal{O}\left(\dfrac{n}{i}\right)$, where $i$ is a prime, so in total over all iterations we have $$\mathcal{O}\left(n \sum_{p \leq \sqrt{n}}\dfrac{1}{p}\right) = \text{Using the divergence of the sum of the reciprocals of the primes} = \mathcal{O}\left(n \log \log \sqrt{n}\right) = \mathcal{O}\left(n \log \left(\frac{1}{2}\log n \right) \right) = \mathcal{O}\left(n \log \log n \right)$$

The initialization of the boolean array and extracting the primes at the end both needs $\mathcal{O}(n)$, but asymptotically $n \log \log n$ is the dominating term, so therefore $\mathcal{O}(n)$ has no effect. The divergence of the sum of the reciprocals of the primes can be found [here](https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes).


### **Modify the sieve code to find first n primes**
Because the sieve itself doesn't generate n primes per se, instead it generates primes up to a limit n, then a small modification is needed if we want to find the n first primes instead. A super naive way would be to use generate a big enough table to extract it, and expand it if it's not big enough. However, there's a tigther upper-bound one can use, instead of guessing, by utilizing a corollary of [Rosser's theorem](https://projecteuclid.org/journals/illinois-journal-of-mathematics/volume-6/issue-1/Approximate-formulas-for-some-functions-of-prime-numbers/10.1215/ijm/1255631807.full) page 6 equation (3.13) (page 69 in the page number of the pdf as it's extracted from a journal) for the nth prime $p_n$

$$p_n < n \ln \ln n + n \ln n$$

for $n \geq 6$. Unfortunately I don't understand the proof, so I will skip that. Anyways, using this bound as the new limit will ensure that we can generate just enough primes to extract the nth prime or the nth first primes.