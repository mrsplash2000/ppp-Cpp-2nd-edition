#include <iostream>

/*
Programming languages provide convenient ways of doing something several times.
This is called repetition or — especially when you do something to a series of elements of a
data structure — iteration.

As an example of iteration, consider the first program ever to run on a stored-program computer
(the EDSAC). It was written and run by David Wheeler in the computer laboratory in Cambridge
University, England, on May 6, 1949, to calculate and print a simple list of squares
*/

int main() {
    //======while Statements======
    //Example 1: calculating and printing a table of squares 0–99
    int i{0};
    while(i<100){ //the loop condition
        std::cout << i << '\t' << i*i << '\n';
        ++i; //increment the loop variable i
    }
    std::cout << "===============1\n";
    /*
    NOTE: The loop variable for a while-statement must be defined and initialized outside (and before)
    the while-statement. If we fail to define it, the compiler will give us an error. If we define it, but
    fail to initialize it, most compilers will warn us, saying something like “local variable i not set,”
    but would be willing to let us execute the program if we insisted. Don’t insist! Compilers are
    almost certainly right when they warn about uninitialized variables.
    */

     /*
    NOTE: A sequence of statements delimited by curly braces { and } is called a block or a
    compound statement.
    */
    //======while Statements======

    //======for Statements======
    /*
    Iterating over a sequence of numbers is so common that C++, like most other programming languages,
    has a special syntax for it. A for-statement is like a while-statement except that the management of the
    control variable is concentrated.
    */
    for(int i{0}; i<100; ++i)
        std::cout << i << '\t' << i*i << '\n';
    std::cout << "===============2\n";
    //NOTE: Never modify the loop variable inside the body of a for-statement. That would violate every reader’s
    //reasonable assumption about what a loop is doing.
    for(int i{0}; i<100; ++i) {
        std::cout << i << '\t' << i*i << '\n';
        ++i; //what's going on here? It smells like an error!
    }
    std::cout << "===============3\n";
    //If you want to increment by 2, say so
    for(int i{0}; i<100; i+=2)
        std::cout << i << '\t' << i*i << '\n';
    std::cout << "===============4\n";
    //======for Statements======
    return 0;
}
