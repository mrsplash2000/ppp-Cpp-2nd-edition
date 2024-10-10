#include <iostream>
using namespace std;
/*
Function: A function is a named sequence of statements.
Return Value: A function can return a result.
Parameter list: The list of arguments required by the function.
Parameters: its elements are called parameters (or formal arguments).
NOTE: The standard library provides a lot of useful functions, such as the square root function sqrt().
NOTE: The type of the result always comes first in a function declaration.
NOTE: The list of parameters can be empty.
NOTE: if we don’t want to return a result we give void (meaning “nothing”) as the return type.
NOTE: Programs are usually easier to write and to understand if each function performs a single
logical action.
*/

int square(int x) {
    return x*x;
}

void write_sorry() {
    cout << "Sorry\n";
}

int main() {
    cout << square(3) << '\n';
    cout << square(235) << '\n';
    square(3); //Probably a mistake, unused return value
    /*
    int v_one {square()}; //error: argument missing
    int v_two {square}; //error: parentheses missing
    int v_three {square(1,2)}; //error: too many arguments
    int v_four {square("two")}; //error: wrong type of argument - int expected
    */
    write_sorry();
    int square(int);
    return 0;
}
