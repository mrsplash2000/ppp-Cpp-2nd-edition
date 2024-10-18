#include "../data_structure/vector/my_vector.h"
#include "../data_structure/vector/my_vector_utility.h"
#include "../data_structure/my_iterator.h"
#include <ncurses.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iomanip>

const char* return_prompt = "Press any key to return to the menu.";
const char* try_again_prompt = "Press any key to try again.";
const char* empty_list_prompt = "This list is empty.";

char display_menu(const std::unordered_map<char, std::string>& options, int& highlight, const challenge_ds::Vector<char>& commandKeys) {
    int c;
    
    clear();
    while (1) {
        // Print the menu options
        int i = 0;
        for (const char command: commandKeys) {
            std::string description = options.at(command);
            if (i == highlight) {
                attron(A_REVERSE);  // Highlight the selected option
                mvprintw(i, 0, description.c_str());
                attroff(A_REVERSE);
            } else {
                mvprintw(i, 0, description.c_str());
            }
            i++;
        }

        c = getch();  // Get user input
        c = std::tolower(c);

        // Check if the key pressed matches one of the command keys
        if (challenge_ds::find(commandKeys.begin(), commandKeys.end(), (char) c) != commandKeys.end()) {
            return c;
        }

        // Handle arrow keys for navigation
        switch (c) {
            case KEY_UP:
                highlight = (highlight == 0) ? options.size() - 1 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == options.size() - 1) ? 0 : highlight + 1;
                break;
            case 10:  // Enter key
                return commandKeys[highlight];  // Return the command of the selected option
            default:
                break;
        }
    }
}

void print_numbers(const challenge_ds::Vector<double>& numbers) {
    clear();

    if (numbers.empty()) {
        mvprintw(0, 0, "The list is empty.");
    } else {
        mvprintw(0, 0, "The list contains:");
        std::string output = "[";
        
        for (size_t i = 0; i < numbers.size(); ++i) {
            output += std::to_string(numbers[i]);
            
            if (i != numbers.size() - 1) {
                output += ", "; 
            }
        }
        output += "]"; 
        mvprintw(1, 0, "%s", output.c_str());
    }

    mvprintw(LINES - 1, 0, return_prompt);
    getch();  // Wait for user input before returning to menu
}

bool is_valid_double(const std::string& str) {
    // Check for an optional leading '-' for negative numbers
    size_t start = 0;
    if (str[0] == '-') {
        start = 1;
    }

    bool decimalPointFound = false;

    // Check each character
    for (size_t i = start; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (decimalPointFound) {
                return false;  // Invalid if more than one decimal point is found
            }
            decimalPointFound = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }

    return !str.empty() && (start < str.size()) && !(str == "-" || str == ".");  // Ensure it's not empty and valid
}

void add_numbers(challenge_ds::Vector<double>& numbers) {
    bool allValid = false;

    while (!allValid) {
        clear();
        mvprintw(0, 0, "Enter numbers separated by spaces (e.g., 100 200 300): ");
        
        char str[100];
        echo();  // Turn on echo to show user input
        wgetnstr(stdscr, str, sizeof(str));  // Capture input from the user
        noecho();  // Turn off echo again


        std::istringstream iss(str);
        std::string token;
        challenge_ds::Vector<double> tempNumbers;
        allValid = true;

        while (iss >> token || token == "") {
            if (!is_valid_double(token)) {
                allValid = false;
                mvprintw(1, 0, "Invalid input: '%s'. Only doubles are allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                break;
            }
            try {
                double num = std::stod(token); 
                tempNumbers.push_back(num);  // Add the valid number to the temporary vector
            } catch (std::invalid_argument& e) {
                allValid = false;
                mvprintw(1, 0, "Invalid input: '%s'. Only doubles are allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                break;
            } catch (std::out_of_range& e) {
                allValid = false;
                mvprintw(1, 0, "Number out of range: '%s'.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                break;
            }
        }

        if (allValid) {
            // If all tokens are valid, add the numbers to the main vector
            // insert currently not implemented so need to loop through
            for (double e : tempNumbers) {
                numbers.push_back(e);
            }
            clear();
            mvprintw(0, 0, "Numbers added successfully.");
        }
    }

    mvprintw(LINES - 1, 0, return_prompt);
    getch();  // Wait for user input before returning to the menu
}

void display_avg(const challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        mvprintw(0, 0, "Average:");
        mvprintw(1, 0, "%.2f", challenge_ds::avg(numbers));
    }
    mvprintw(LINES - 1, 0, return_prompt);
    getch();
}

void display_smallest(const challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        mvprintw(0, 0, "Smallest number:");
        mvprintw(1, 0, "%.2f", challenge_ds::min(numbers));
    }
    mvprintw(LINES - 1, 0, return_prompt);
    getch();
}

void display_largest(const challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        mvprintw(0, 0, "Greatest number:");
        mvprintw(1, 0, "%.2f", challenge_ds::max(numbers));
    }
    mvprintw(LINES - 1, 0, return_prompt);
    getch();
}

void display_sum(const challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        mvprintw(0, 0, "Sum:");
        mvprintw(1, 0, "%.2f", challenge_ds::sum(numbers));
    }
    mvprintw(LINES - 1, 0, return_prompt);
    getch();
}

void clear_list(challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        numbers.clear();
        mvprintw(0, 0, "Successfully cleared list.");
    }
    mvprintw(LINES - 1, 0, return_prompt);
    getch();
}

void find_number(const challenge_ds::Vector<double>& numbers) {
    clear();
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        bool valid = false;
        while (!valid) {
            clear();
            mvprintw(0, 0, "Enter a number to find: ");
            
            char str[100];
            echo();
            wgetnstr(stdscr, str, sizeof(str));
            noecho();

            std::istringstream iss(str);
            std::string token;
            valid = true;

            iss >> token;
            std::string check_no_more_tokens;
            // expect only one double, no more than that
            if (iss >> check_no_more_tokens) {
                valid = false;
                mvprintw(1, 0, "Invalid input: '%s'. Only one double is allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                continue;
            }
            if (!is_valid_double(token)) {
                valid = false;
                mvprintw(1, 0, "Invalid input: '%s'. Only one double is allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                continue;
            }
            try {
                double num = std::stod(token); 
                auto res = challenge_ds::find(numbers, num);
                if (res) {
                    clear();
                    mvprintw(0, 0, (token + " is available. At index: " + std::to_string(res->first)).c_str());
                }
                else {
                    clear();
                    mvprintw(0, 0, (token + " does not exist.").c_str());
                }
                break;
            } catch (std::invalid_argument& e) {
                valid = false;
                mvprintw(1, 0, "Invalid input: '%s'. Only one double is allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();
                continue; 
            } catch (std::out_of_range& e) {
                valid = false;
                mvprintw(1, 0, "Number out of range: '%s'.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();
                continue; 
            }
        }
    }
    
    mvprintw(LINES - 1, 0, return_prompt);
    getch();  // Wait for user input before returning to the menu
}

void write_content_to_file(const challenge_ds::Vector<double> numbers) {
    // Open a file in write mode
    if (numbers.empty()) return;
    std::ofstream outfile("output.txt");
    if (outfile.is_open()) {
        // write the number content
        outfile << "Numbers: [";
        size_t count{};
        for (size_t i=0; i < numbers.size(); ++i) {
            outfile << std::setprecision(2) << numbers[i];
            if (i < numbers.size() - 1) outfile << ", ";
            ++count;
        }
        outfile << "]" << std::endl;

        // write the number of elements
        outfile << "Count: " << count << std::endl;

        // write sum
        outfile << "Sum: " << std::setprecision(2) << challenge_ds::sum(numbers) << std::endl;

        // write largest
        outfile << "Largest: " << challenge_ds::max(numbers) << std::endl;

        // write smallest
        outfile << "Smallest: " << challenge_ds::min(numbers) << std::endl;

        // write average
        outfile << "Average: " << challenge_ds::avg(numbers);

        outfile.close();
    }
}

int main() {
    challenge_ds::Vector<double> numbers;
    std::unordered_map<char, std::string> menuOptions = {
        {'p', "P - Print Numbers"},
        {'a', "A - Add Numbers"},
        {'m', "M - Display The Average Of Numbers"},
        {'s', "S - Display The Smallest Number"},
        {'l', "L - Display The Largest Number"},
        {'e', "E - Display The Sum Of Numbers"},
        {'c', "C - Clear The List"},
        {'f', "F - Find The Number"},
        {'q', "Q - Quit"}
    };

    challenge_ds::Vector<char> commandKeys = {'p', 'a', 'm', 's', 'l', 'e', 'c', 'f', 'q'};

    int highlight = 0;
    int choice = 0;

    initscr();  // Start ncurses mode
    noecho();   // Disable echoing of characters
    cbreak();   // Disable line buffering
    keypad(stdscr, TRUE);  // Enable special keys like arrow keys
    
    while (1) {
        choice = display_menu(menuOptions, highlight, commandKeys);
        
        switch (choice) {
            case 'p':  // Print Numbers
                print_numbers(numbers);
                break;
            case 'a':  // Add Numbers
                add_numbers(numbers);
                break;
            case 'm':  // Average
                display_avg(numbers);
                break;
            case 's':  // Min
                display_smallest(numbers);
                break;
            case 'l':  // Max
                display_largest(numbers);
                break;
            case 'e':  // Sum
                display_sum(numbers);
                break;
            case 'c':  // clear list
                clear_list(numbers);
                break;
            case 'f':  // find number
                find_number(numbers);
                break;
            case 'q':  // Quit
                endwin();  // End ncurses mode
                write_content_to_file(numbers);
                return 0;
            default:
                break;
        }
    }

    endwin();  // End ncurses mode
    return 0;
}
