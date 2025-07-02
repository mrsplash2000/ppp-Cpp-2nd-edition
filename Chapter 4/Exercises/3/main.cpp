/*
Read a sequence of double values into a vector. Think of each value as
the distance between two cities along a given route. Compute and print
the total distance (the sum of all distances). Find and print the smallest
and greatest distance between two neighboring cities. Find and print the
mean distance between two neighboring cities.
*/

#include <iostream>
#include <vector>
#include <numeric> //for using accumulate function calculating sum of values
#include <algorithm> //for using min_element and max_element

//NOTE: std::accumulate() takes three arguments: Beginning, End, and an initial value
int main() {
    std::vector <double> numbers {};

    for(double temp{0}; std::cin >> temp;)
        numbers.push_back(temp);

    double maximum {*std::max_element(numbers.begin(), numbers.end())};
    double minimum {*std::min_element(numbers.begin(), numbers.end())};
    double sum {std::accumulate(numbers.begin(), numbers.end(), 0.0)};
    //You can also declare the sum variable like this:
    //double sum {std::accumulate(numbers.begin(), numbers.end(), decltype(numbers)::value_type(0))};
    double average {sum/numbers.size()};

    std::cout << "Maximum Value = " << maximum << '\n';
    std::cout << "Minimum Value = " << minimum << '\n';
    std::cout << "Sum = " << sum << '\n';
    std::cout << "Mean Distance = " << average << '\n';

    return 0;
}
