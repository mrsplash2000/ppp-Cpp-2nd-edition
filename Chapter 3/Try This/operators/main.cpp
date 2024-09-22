#include "std_lib_facilities.h"
//simple program to exercise operators
int main() {
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

    cout << "Please Enter An Integer Value: ";
    int r;
    cin >> r;
    cout << "n == " << r
             << "\nn+1 == " << r+1
             << "\nthree times n == " << r*3
             << "\ntwice n == " << r+r
             << "\nn squared == " << r*r
             << "\nhalf of n == " << r/2
             << "\nsquare root of n == " << sqrt(r)
             << "\n";   //another name for newline in output

    cout << "Please Enter Two Integer Values: ";
    int a, b;
    cin >> a >> b;
    cout << "a/b * b + a%b == " << a/b*b+a%b << "\n";
    return 0;
}
