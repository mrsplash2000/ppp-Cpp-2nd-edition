//Object: An object is a region of memory with a type that specifies what kind of information can be placed in it.
//Variable: A named object is called a variable.
//Definition: A statement that introduces a new name into a program and sets aside memory for a variable.
//Values: The data items we put into variables are called values.
//NOTE: By convention, reading of strings is terminated by what is called whitespace, that is, space, newline, and tab characters.

#include <iostream>

//Read and write a first name
int main() {
    std::cout << "Please Enter Your First Name (followed by 'enter'):\n"; //Prompt
    std::string first_name = "???"; //first_name is a variable of type string
    std::cin >> first_name;              //read characters into first_name (c:character in:input)
    std::cout << "Hello, " << first_name << "!\n";
    return 0;
}
