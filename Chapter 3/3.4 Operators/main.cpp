#include <iostream>
#include <string>
//#include "std_lib_facilities.h" // In order to use the sqrt() function

int main() {
    //simple program to exercise operators
    std::cout << "Please Enter A Floating-Point Value: ";
    double n;
    std::cin >> n;
    std::cout << "n == " << n
             << "\nn+1 == " << n+1
             << "\nthree times n == " << n*3
             << "\ntwice n == " << n+n
             << "\nn squared == " << n*n
             << "\nhalf of n == " << n/2
             << "\nsquare root of n == " << sqrt(n)
             << "\n";   //another name for newline in output

    //read first and second name
    std::cout << "Please Enter Your First And Second Name: ";
    std::string first;
    std::string second;
    std::cin >> first >> second; //read two strings
    std::string name = first + ' ' + second; //concatenate strings
    std::cout << "Hello, " << name << '\n';

    //read and compare strings
    std::cout << "Please Enter Two Names: ";
    std::string first_name;
    std::string second_name;
    std::cin >> first_name >> second_name;
    if(first_name == second_name)
        std::cout << "That's the same name twice.\n";
    if(first_name<second_name)
        std::cout << first_name << " is alphabetically before " << second_name << '\n';
    if(first_name>second_name)
        std::cout << first_name << " is alphabetically after " << second_name << '\n';
    return 0;
}
