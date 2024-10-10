/*
Now change the body of the loop so that it reads just one double each
time around. Define two variables to keep track of which is the smallest
and which is the largest value you have seen so far. Each time through
the loop write out the value entered. If it’s the smallest so far, write the
smallest so far after the number. If it is the largest so far, write the largest
so far after the number.
*/

/*
Add a unit to each double entered; that is, enter values such as 10cm,
2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume conversion
factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit
indicator into a string. You may consider 12 m (with a space between the
number and the unit) equivalent to 12m (without a space).
*/

/*
Reject values without units or with “illegal” representations of units, such
as y, yard, meter, km, and gallons.
*/

/*
Keep track of the sum of values entered (as well as the smallest and the
largest) and the number of values entered. When the loop ends, print the
smallest, the largest, the number of values, and the sum of values. Note
that to keep the sum, you have to decide on a unit to use for that sum; use
meters.
*/

/*
Keep all the values entered (converted into meters) in a vector. At the
end, write out those values.
*/

/*
Before writing out the values from the vector, sort them (that’ll make
them come out in increasing order).
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {

    //Variables
    double number {0}, minimum {0}, maximum {0}, sum{0};
    int counter {0};
    std::vector <double> numbers {};
    std::map <std::string, double> conversionFactors {
        {"m", 1.0},
        {"cm", 0.01},
        {"in", 0.0254},
        {"ft", 0.3048}
    };

    while(true) {
        std::string input {""};
        std::string unit_indicator {""};

        //Checking if input is an integer and if so, store it into number variable
        std::getline(std::cin, input);
        if(input == "|")
            break;
        std::istringstream iss(input);
        if(!(iss >> number)) {
            std::cout << "Must be a number!\n";
            continue;
        } else
            iss >> unit_indicator;

        //Checking if the unit entered is valid or not.
        if(unit_indicator.length() == 0)
            std::getline(std::cin, unit_indicator);
        auto unit_pointer = conversionFactors.find(unit_indicator); //If it doesn't find the key value, it points to the end value(address)
        if(unit_pointer != conversionFactors.end()) {
            //Correct key
            sum += number * unit_pointer->second;
            numbers.push_back(number * unit_pointer->second);
        } else {
            //Wrong key
            std::cout << "illegal\n";
            continue;
        }

        //Checking which number is big or small
        if(counter == 0) {
            minimum = number;
            maximum = number;
            ++counter;
            continue;
        } else {
            if(number > maximum)
                maximum = number;
            else if (number < minimum)
                minimum = number;
        }

        //Updating the counter(the number of values)
        ++counter;
    }

    //Printing out the largest, smallest, sum and number of values
    std::cout << "The smallest number: " << minimum << '\n';
    std::cout << "The largest number: " << maximum << '\n';
    std::cout << "Sum of all values: " << sum << '\n';
    std::cout << "Number of values: " << counter << '\n';
    std::cout << "Values(converted into meters):\n";
    sort(numbers.begin(), numbers.end());
    for(double x:numbers)
        std::cout << '\t' << x << '\n';

    return 0;
}
