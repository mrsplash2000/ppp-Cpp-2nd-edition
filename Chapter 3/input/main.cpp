//Object: An object is a region of memory with a type that specifies what kind of information can be placed in it.
//Variable: A named object is called a variable.
//Definition: A statement that introduces a new name into a program and sets aside memory for a variable.
//Values: The data items we put into variables are called values.
//NOTE: By convention, reading of strings is terminated by what is called whitespace, that is, space, newline, and tab characters.

#include "std_lib_facilities.h"

//Read and write a first name
int main() {
    cout << "Please Enter Your First Name (followed by 'enter'):\n"; //Prompt
    string first_name = "???"; //first_name is a variable of type string
    int age = -1; //age is a variable of type int
    cin >> first_name >> age; //read characters into first_name (c:character in:input) and integer into age
    cout << "Hello, " << first_name << " (age " << age << ")\n";
    return 0;
}
