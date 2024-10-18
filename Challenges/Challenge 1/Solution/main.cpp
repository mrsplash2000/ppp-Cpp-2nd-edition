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
*/

#include <iostream>
#include <vector>
#include <string> //for std::to_string
#include <cstdlib> //for system calls
#include <sstream> //for input validation
#include <algorithm> //for std::find + min_element + max_element
#include <numeric> //for using std::accumulate function calculating sum of values
#include <fstream> //for reading and writing to files

//=========Functions=========
void displayMenu() {
    //Displays the menu
    std::cout << "======================\n";
    std::cout << "P - Print Numbers\n";
    std::cout << "A - Add Numbers\n";
    std::cout << "M - Display The Average Of Numbers\n";
    std::cout << "S - Display The Smallest Number\n";
    std::cout << "L - Display The Largest Number\n";
    std::cout << "E - Display The Sum Of Numbers\n";
    std::cout << "C - Clear The List\n";
    std::cout << "F - Find The Number\n";
    std::cout << "Q - Quit\n";
    std::cout << "======================\n";
    std::cout << "Enter Your Choice: ";
}

void clearConsole() {
    //clears the console based on the operating system
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux and other Unix-like systems
    #endif
}

bool validInput(double &num) {
    //Asks for input
    std::string input {""};
    std::cout << "Enter The Number: ";
    std::cin >> input;

    //Checks if the input is valid or not
    std::istringstream iss(input);
    if(iss >> num)
        return true;
    else {
        std::cout << "Please Try Again And Enter A Number!\n";
        return false;
    }
}

void printElements(std::vector <double> numbers_vector) {
    //Checking if the list is empty or not
    if(numbers_vector.empty())
        std::cout << "[] - The list is empty.\n";
    //Printing the elements if the list is not empty
    else {
        std::cout << "[";
        for(double x:numbers_vector)
            std::cout << x << ", ";
        std::cout << "\b\b]\n";
    }
}

void addElements(std::vector <double> &numbers_vector) {
    //Adds numbers based on user's input to the vector
    double number {0};

    //Input validation + Checks to see if the number exists in the list or not
    if(validInput(number)) {
        auto number_finder = std::find(numbers_vector.begin(), numbers_vector.end(), number);
        if(number_finder == numbers_vector.end()) {
            numbers_vector.push_back(number);
            std::cout << "Added " << number << " To The List\n";
        } else
            std::cout << number << " Is Already On The List!\n";
    }
}

void displayAverage(std::vector <double> &numbers_vector) {
    //Displays the mean of all elements in the vector
    std::cout << "Average: " << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0)/numbers_vector.size() << '\n';
}

void displaySmallest(std::vector <double> &numbers_vector) {
    //Displays the smallest number in the vector
    //Need to check by vector's size because otherwise the program throws an error and crashes
    if(!numbers_vector.empty())
        std::cout << "Smallest: " << *std::min_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
    else
        std::cout << "No Elements In The List To Show The Smallest!\n";
}

void displayLargest(std::vector <double> &numbers_vector) {
    //Displays the largest number in the vector
    //Need to check by vector's size because otherwise the program throws an error and crashes
    if(!numbers_vector.empty())
        std::cout << "Largest: " << *std::max_element(numbers_vector.begin(), numbers_vector.end()) << '\n';
    else
        std::cout << "No Elements In The List To Show The Largest!\n";
}

void displaySum(std::vector <double> &numbers_vector) {
    //Displays the sum of numbers present in the vector
    std::cout << "Sum: " << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0) << '\n';
}

void clearVector(std::vector <double> &numbers_vector) {
    //Clears the vector completely
    numbers_vector.clear();
    std::cout << "Cleared The List!\n";
}

void findNumber(std::vector <double> numbers_vector) {
    //Finds number based on user input
    double number {0};

    if(validInput(number)){
        auto number_finder = std::find(numbers_vector.begin(), numbers_vector.end(), number);
        if(number_finder != numbers_vector.end()) {
            std::cout << *number_finder << " Is Available!\n";
            std::cout << "Index: " << std::distance(numbers_vector.begin(), number_finder) << '\n';
        } else
            std::cout << number << " Does Not Exist!\n";
    }
}

void writeToFile(std::vector <double> numbers_vector) {
    if(!numbers_vector.empty()) {
        std::ofstream file;
        std::string text {""};
        file.open("results.txt", std::ios::app);
        //Numbers
        file << "Numbers: [";
        for(double x:numbers_vector)
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
        file << "Average: " << std::accumulate(numbers_vector.begin(), numbers_vector.end(), 0.0)/numbers_vector.size() << '\n';
        file << "=======================\n";
        file.close();
    }
}
//=========Functions=========

int main() {
    //=========Variables=========
    char choice {'a'};
    bool state {true};
    std::vector <double> numbers {};
    //=========Variables=========

    while(state) {
        displayMenu();
        std::cin >> choice;
        clearConsole();
        switch(toupper(choice)) {
            case 'P':
                printElements(numbers);
                break;
            case 'A':
                addElements(numbers);
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
                std::cout << "Invalid Choice! Please Try Again!\n";
        }
    }
    return 0;
}
