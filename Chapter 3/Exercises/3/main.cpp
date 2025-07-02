/*
Write a program that doesn’t do anything, but declares a number of variables
with legal and illegal names (such as int double = 0;), so that you can see how
the compiler reacts.
*/

#include <iostream>

int main() {
    double 45 {12.3}; //error: expected unqualified-id before numeric constant
    int g {5.3}; //error: narrowing conversion of '5.2999999999999998e+0' from 'double' to 'int' [-Wnarrowing]
    char c {g}; //warning: narrowing conversion of 'g' from 'int' to 'char' [-Wnarrowing]
    return 0;
}
