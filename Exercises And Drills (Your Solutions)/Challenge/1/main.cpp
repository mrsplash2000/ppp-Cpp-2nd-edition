#include "../data_structure/vector/my_vector.h"
#include "../data_structure/vector/my_vector_utility.h"
#include "../data_structure/my_iterator.h"
#include <ncurses.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <functional>

const char* return_prompt = "Press any key to return to the menu";
const char* try_again_prompt = "Press any key to try again";
const char* empty_list_prompt = "This list is empty.";
const size_t max_len = 100;

void display_return_prompt() {
    mvprintw(LINES - 1, 0, return_prompt);
    getch(); // Wait for user input before returning to menu
}

std::string prompt_and_get_user_input(std::string prompt) {
    clear();
    mvprintw(0, 0, prompt.c_str());
    curs_set(1);  // Turn on cursor 
    char str[max_len];
    echo();
    wgetnstr(stdscr, str, sizeof(str));
    noecho();
    curs_set(0);  // Turn off cursor
    str[max_len - 1] = '\0';
    return std::string(str);
}

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
    if (numbers.empty()) {
        mvprintw(0, 0, "The list is empty.");
    } else {
        mvprintw(0, 0, "The list contains:");
        std::string output = "[";
        
        for (size_t i = 0; i < numbers.size(); ++i) {
            output += std::to_string(numbers[i]);
            if (i != numbers.size() - 1) output += ", ";
        }
        output += "]";
        mvprintw(1, 0, "%s", output.c_str());
    }

    display_return_prompt();
}

void add_numbers(challenge_ds::Vector<double>& numbers) {
    bool allValid = false;

    while (!allValid) {
        std::string str = prompt_and_get_user_input("Enter numbers separated by spaces (e.g., 100 200 300): ");
        std::istringstream iss(str);
        std::string token;
        challenge_ds::Vector<double> tempNumbers;
        
        allValid = true;
        while (iss >> token || token == "") {
            std::istringstream tokenstream(token);
            double num;

            if (!(tokenstream >> num) || !tokenstream.eof()) {
                allValid = false;
                clear();
                mvprintw(0, 0, "Invalid input: '%s'. Only doubles are allowed.", token.c_str());
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                break;
            }
            tempNumbers.push_back(num);  // Add the valid number to the temporary vector
        }

        if (allValid) {
            for (double e : tempNumbers) numbers.push_back(e);
            clear();
            mvprintw(0, 0, "Numbers added successfully.");
        }
    }

    display_return_prompt();
}

void display_vector_statistic(const challenge_ds::Vector<double>& numbers, std::string type_of_stat, 
std::function<double(const challenge_ds::Vector<double>&)> func) {
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        mvprintw(0, 0, (type_of_stat + ":").c_str());
        mvprintw(1, 0, "%.2f", func(numbers));
    }

    display_return_prompt();
}

void clear_list(challenge_ds::Vector<double>& numbers) {
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        numbers.clear();
        mvprintw(0, 0, "Successfully cleared list.");
    }

    display_return_prompt();
}

void find_number(const challenge_ds::Vector<double>& numbers) {
    if (numbers.empty()) mvprintw(0, 0, empty_list_prompt);
    else {
        bool valid = false;
        while (!valid) {
            std::string str = prompt_and_get_user_input("Enter a number to find: ");
            std::istringstream iss(str);
            double num;
            valid = true;
            std::string check_no_more_tokens;
            // expect only one double, no more than that
            if (!(iss >> num) || iss >> check_no_more_tokens) {
                valid = false;
                clear();
                mvprintw(0, 0, "Invalid input. Only one double is allowed.");
                mvprintw(LINES - 1, 0, try_again_prompt);
                getch();  // Wait for user to acknowledge the error
                continue;
            }
            auto res = challenge_ds::find(numbers, num);
            if (res) {
                clear();
                mvprintw(0, 0, (std::to_string(num) + " is available. At index: " + std::to_string(res->first)).c_str());
            }
            else {
                clear();
                mvprintw(0, 0, (std::to_string(num) + " does not exist.").c_str());
            }
            break;
        }
    }
    
    display_return_prompt();
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
    curs_set(0);
    
    while (1) {
        choice = display_menu(menuOptions, highlight, commandKeys);
        clear();
        switch (choice) {
            case 'p':  // Print Numbers
                print_numbers(numbers);
                break;
            case 'a':  // Add Numbers
                add_numbers(numbers);
                break;
            case 'm':  // Average
                display_vector_statistic(numbers, "Average", [](const challenge_ds::Vector<double>& numbers) -> double {return challenge_ds::avg(numbers);});
                break;
            case 's':  // Min
                display_vector_statistic(numbers, "Min", [](const challenge_ds::Vector<double>& numbers) -> double {return challenge_ds::min(numbers);});
                break;
            case 'l':  // Max
                display_vector_statistic(numbers, "Max", [](const challenge_ds::Vector<double>& numbers) -> double {return challenge_ds::max(numbers);});
                break;
            case 'e':  // Sum
                display_vector_statistic(numbers, "Sum", [](const challenge_ds::Vector<double>& numbers) -> double {return challenge_ds::sum(numbers);});
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
