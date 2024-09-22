#include "std_lib_facilities.h"

int main() {
    //simple program to exercise operators
    cout << "Please Enter A Floating-Point Value: ";
    double n;
    cin >> n;
    cout << "n == " << n
             << "\nn+1 == " << n+1
             << "\nthree times n == " << n*3
             << "\ntwice n == " << n+n
             << "\nn squared == " << n*n
             << "\nhalf of n == " << n/2
             << "\nsquare root of n == " << sqrt(n)
             << "\n";   //another name for newline in output

    //read first and second name
    cout << "Please Enter Your First And Second Name: ";
    string first;
    string second;
    cin >> first >> second; //read two strings
    string name = first + ' ' + second; //concatenate strings
    cout << "Hello, " << name << '\n';

    //read and compare strings
    cout << "Please Enter Two Names: ";
    string first_name;
    string second_name;
    cin >> first_name >> second_name;
    if(first_name == second_name)
        cout << "That's the same name twice.\n";
    if(first_name<second_name)
        cout << first_name << " is alphabetically before " << second_name << '\n';
    if(first_name>second_name)
        cout << first_name << " is alphabetically after " << second_name << '\n';
    return 0;
}
