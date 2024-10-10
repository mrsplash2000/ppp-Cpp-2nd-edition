/*
Write a program that consists of a while-loop that (each time around the
loop) reads in two ints and then prints them. Exit the program when a
terminating '|' is entered.
*/

/*
Change the program to write out the smaller value is: followed by the
smaller of the numbers and the larger value is: followed by the larger
value.
*/

/*
Augment the program so that it writes the line the numbers are equal
(only) if they are equal.
*/

/*
Change the program so that it uses doubles instead of ints.
*/

/*
Change the program so that it writes out the numbers are almost equal
after writing out which is the larger and the smaller if the two numbers
differ by less than 1.0/100.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int main() {
    while(true) {
        std::string input {""};
        double n1{0}, n2{0};
        std::getline(std::cin, input); //Read the entire line
        if(input == "|")
            break;
        std::istringstream iss(input);
        if(!(iss >> n1 >> n2)) {
            std::cout << "Must be two integers!\n";
            continue;
        }
        std::cout << n1 << " " << n2 << '\n';

        //Checking which one is bigger or smaller
        if(n1>n2)
            std::cout << "Smaller value is: " << n2 << "\nLarger value is: " << n1 << '\n';
        else if(n1<n2)
            std::cout << "Smaller value is: " << n1 << "\nLarger value is: " << n2 << '\n';
        else
            std::cout << "The numbers are equal.\n";

        //Checking if they're almost equal if that is the difference between them is less than 0.01
        if(std::abs(n1-n2) < 0.01)
            std::cout << "The numbers are almost equal.\n";
    }
    return 0;
}
