/*
Write a program that prints this message at the beginning of the program (I explain what each option should do):
"P - Print Numbers"
"A - Add Numbers"
"M - Display The Average Of Numbers"
"S - Display The Smallest Number"
"L - Display The Largest Number"
"E - Display The Sum Of Numbers"
"C - Clear The List"
"F - Find The Number"
"Q - Quit"

P - Should print the numbers available in the vector. If the vector is empty, the program should print "[] - The list is empty.".
If the vector is not empty, the numbers should be printed in this manner, for example like this: "[23, 14.23, 78.56, 12]"
A - Should add numbers to your vector based on your input. If the number that you enter already exists in the vector, the
program should print "(number) is already on the list." and then goes back to the selection input.
M - Should print the average of the numbers. This is very obvious :)))
S - Display The Smallest Number. Again, very obvious :)))
L - Display The Largest Number
E - Display The Sum Of Numbers
C - Clears the list completely, making it empty.
F - This option should ask for your input. If the number doesn't exist in the vector, it should print out this message:
"(number) Does Not Exist!" and then goes back to the menu selection input. If the number is available, the program should
print this message: "(number) is available!" and then after that, it should print the index for which this number exists in that vector.
Q - Quits the program. To spice things up and make things interesting with this challenge, I want the program upon quitting, to store
the results in a txt file. If the vector is empty, then no txt file shall be created. The results should be stored in this manner, something like this:
Numbers: [15, 23.56, 78, 46.23, 13]
Count: 5
Sum: 175.79
Largest: 78
Smallest: 13
Average: 35.158


Make sure your code is modularized. One thing to note, this program runs until the user enters q to quit. Good luck and happy coding hours

To do list (Divide And Conquer):
1. Printing Main Menu /
2. Clear console (upon user input) /
3. switch case for each possible input (Digging the graves) /
4. Modularization for each option (carrying out each option) /
5. Input validation /
6. File writing
*/

//Header Files
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream> //istringstream
#include <algorithm> //std::find + min_element + max_element
#include <string>
#include <numeric> //std::accumulate
#include <fstream> //std::ofstream

//Functions
void mainMenu() {
    std::cout << "===================\n"
                    << "P - Print Numbers\n"
                    << "A - Add Numbers\n"
                    << "M - Display The Average Of Numbers\n"
                    << "S - Display The Smallest Number\n"
                    << "L - Display The Largest Number\n"
                    << "E - Display The Sum Of Numbers\n"
                    << "C - Clear The List\n"
                    << "F - Find The Number\n"
                    << "Q - Quit\n"
                    << "===================\n"
                    << "Enter Your Choice: ";
}

void clearConsole() {
    //clears the console based on your operating system
    #ifdef _WIN32
        system("cls"); //Windows
    #else
        system("clear"); //Linux and MacOS
    #endif
}

void printNumbers(std::vector <double> numbers_vector) {
    if(numbers_vector.empty())
        std::cout << "[] - The List Is Empty.\n";
    else {
        std::cout << "[";
        for(auto x:numbers_vector)
            std::cout << x << ", ";
        std::cout << "\b\b]\n";
    }
}

bool inputValidation(double &num) {
    //Asking for user input
    std::cout << "Enter Your Number: ";
    std::string input {""};
    std::cin >> input;
    //Input Validation
    std::istringstream iss(input);
    if(iss >> num && iss.eof())
        return true;
    else {
        std::cout << "Please Enter A Valid Number!\n";
        return false;
    }
}

void addNumbers(std::vector <double> &numbers_vector) {
    double number {0};

    //Checking to see if the number exists in our vector or not
    if(inputValidation(number)) {
        auto number_pointer = std::find(numbers_vector.begin(), numbers_vector.end(), number);
        if(number_pointer == numbers_vector.end()) {
            std::cout << "Added " << number << " To The List.\n";
            numbers_vector.push_back(number);
        } else {
            std::cout << number << " Is Already On The List!\n";
        }
    }
}

void displayAverage(std::vector <double> numbers_vector) {
    //Displays the average of all elements
    std::cout << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0) / numbers_vector.size() << '\n';
}

void displaySmallest(std::vector <double> numbers_vector) {
    //Displays the smallest element
    if(!numbers_vector.empty())
        std::cout << *std::min_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
    else
        std::cout << "No elements in the vector!\n";
}

void displayLargest(std::vector <double> numbers_vector) {
    //Displays the largest element
    if(!numbers_vector.empty())
        std::cout << *std::max_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
    else
        std::cout << "No elements in the vector!\n";
}

void displaySum(std::vector <double> numbers_vector) {
    //Displays the sum of all elements
    std::cout << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0) << '\n';
}

void clearVector(std::vector <double> &numbers_vector) {
    //Clears the vector completely
    numbers_vector.clear();
    std::cout << "Cleared The List!\n";
}

void findNumber(std::vector <double> numbers_vector) {
    //Looks for the number from the user input and displays the index if it's available
    double number {0};

    //Checking to see if the number exists in our vector or not
    if(inputValidation(number)) {
        auto number_pointer = std::find(numbers_vector.begin(), numbers_vector.end(), number);
        if(number_pointer != numbers_vector.end()) {
            std::cout << number << " Is Available!\n";
            std::cout << "Index: " << std::distance(numbers_vector.begin(), number_pointer) << '\n';
        } else {
            std::cout << number << " Does Not Exist!\n";
        }
    }
}

void writeToFile(std::vector <double> numbers_vector) {
    //Writes the results to a file if the vector is not empty
    if(!numbers_vector.empty()){
        std::ofstream file;
        std::string text {""};
        file.open("results.txt", std::ios::app);
        //Numbers
        file << "Numbers: [";
        for(auto x:numbers_vector)
            text += std::to_string(x) + ", ";
        text.pop_back();
        text.pop_back();
        file << text << "]\n";
        //Count
        file << "Count: " << numbers_vector.size() << '\n';
        //Sum
        file << "Sum: " << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0) << '\n';
        //Largest
        file << "Largest: " << *std::max_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
        //Smallest
        file << "Smallest: " << *std::min_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
        //Average
        file << "Average: " << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0) / numbers_vector.size() << '\n';
        file << "====================\n";
        file.close();
    }
}

int main() {
    //Variables
    bool state {true};
    char input {'a'};
    std::vector <double> numbers {};

    while(state) {
        mainMenu();
        std::cin >> input;
        clearConsole();
        switch(toupper(input)) {
            case 'P':
                printNumbers(numbers);
                break;
            case 'A':
                addNumbers(numbers);
                break;
            case 'M':
                displayAverage(numbers);
                break;
            case 'S':
                displaySmallest(numbers);
                break;
            case 'L':
                displayLargest(numbers);
                break;
            case 'E':
                displaySum(numbers);
                break;
            case 'C':
                clearVector(numbers);
                break;
            case 'F':
                findNumber(numbers);
                break;
            case 'Q':
                writeToFile(numbers);
                state = false;
                break;
            default:
                std::cout << "Invalid Input! Please Try Again!\n";
        }
    }
    return 0;
}
