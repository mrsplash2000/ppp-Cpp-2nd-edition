/*
Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure
out what the number is (e.g., “Is the number you are thinking of less than
50?”). Your program should be able to identify the number after asking
no more than seven questions. Hint: Use the < and <= operators and the
if-else construct.
*/

#include <iostream>

int main() {
    int low {1};
    int high {100};
    int guess {0};
    char response {'y'};

    std::cout << "Think of a number between " << low << " and " << high << '\n';

    for (int i = 0; i < 7; ++i) {
        //Make a guess
        guess = (low + high) / 2;

        std::cout << "Is your number less than or equal to " << guess << "? (y/n): ";
        std::cin >> response;

        //Narrowing down the range
        if (response == 'y' || response == 'Y')
            high = guess;
        else
            low = guess + 1;

        //If low and high converge, we've found the number
        if (low == high) {
            std::cout << "Your number is " << low << '\n';
            break;
        }
    }

    return 0;
}

