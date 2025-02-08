/*
If we define the median of a sequence as “a number so that exactly as
many elements come before it in the sequence as come after it,” fix the
program in §4.6.3 so that it always prints out a median. Hint: A median
need not be an element of the sequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector <double> numbers{};
    for(double temp{}; std::cin >> temp;)
        numbers.push_back(temp);

    sort(numbers.begin(), numbers.end());

    if(numbers.size()%2 == 1)
        std::cout << "Median = " << numbers[numbers.size()/2] << '\n';
    else
        std::cout << "Median = " << (numbers[numbers.size()/2] + numbers[(numbers.size()/2)-1]) / 2.0 << '\n';
    return 0;
}
