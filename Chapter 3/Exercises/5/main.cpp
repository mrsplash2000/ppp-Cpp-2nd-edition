/*
Write a program that prompts the user to enter two integer values. Store
these values in int variables named val1 and val2. Write your program to
determine the smaller, larger, sum, difference, product, and ratio of these
values and report them to the user.
*/

#include <iostream>

int main() {
    std::cout << "Enter Two Integer Values: ";
    double val1 {0};
    double val2 {0};
    double ratio_result {0};
    double difference {0};
    std::cin >> val1 >> val2;

    //Calculating Ratio Based On The Bigger Value
    if(val1 == val2) {
       std::cout << "val1=" << val1 << " == val2=" << val2 << '\n';
        ratio_result = val1/val2;
    }
    else if(val1>val2) {
        std::cout << "val1=" << val1 << " > val2=" << val2 << '\n';
        ratio_result = val2 / val1;
    }
    else {
        std::cout << "val1=" << val1 << " < val2=" << val2 << '\n';
        ratio_result = val1 / val2;
    }

    //Calculating Difference
    if(val1 > val2)
        difference = val1 - val2;
    else
        difference = val2 - val1;

    //Printing The Results
    std::cout << "Sum = " << val1+val2 << '\n';
    std::cout << "Difference = " << difference << '\n';
    std::cout << "Product = " << val1*val2 << '\n';
    std::cout << "Ratio = " << ratio_result << '\n';



    return 0;
}
