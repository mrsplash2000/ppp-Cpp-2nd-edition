/*
Write a program that prompts the user to enter some number of pennies
(1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters
(25-cent coins), half dollars (50-cent coins), and one-dollar coins
(100-cent coins). Query the user separately for the number of each size
coin, e.g., “How many pennies do you have?” Then your program should
print out something like this:
You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.
Make some improvements: if only one of a coin is reported, make the
output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes).
Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.
*/

#include <iostream>

int main() {

    int pennies {0};
    std::cout << "How many pennies do you have? ";
    std::cin >> pennies;

    int nickles {pennies/5};
    int dimes {pennies/10};
    int quarter {pennies/25};
    int half_dollars {pennies/50};

    if(pennies > 0) {

        if(pennies != 1)
            std::cout << "You Have " << pennies << " Pennies." << '\n';   //Pennies
        else
            std::cout << "You Have " << pennies << " Penny." << '\n';   //Pennies

        if(nickles != 1)
            std::cout << "You Have " << nickles << " Nickles." << '\n';  //Nickles
        else
            std::cout << "You Have " << nickles << " Nickle." << '\n';  //Nickles

        if(dimes != 1)
            std::cout << "You Have " << dimes << " Dimes." << '\n';  //Dimes
        else
            std::cout << "You Have " << dimes << " Dime." << '\n';  //Dimes

        if(quarter != 1)
            std::cout << "You Have " << quarter << " Quarters." << '\n';  //Quarters
        else
            std::cout << "You Have " << quarter << " Quarter." << '\n';  //Quarters

        if(half_dollars != 1)
            std::cout << "You Have " << half_dollars << " Half Dollars." << '\n';  //Half Dollars
        else
            std::cout << "You Have " << half_dollars << " Half Dollar." << '\n';  //Half Dollars

        if(pennies != 1)
            std::cout << "You Have " << pennies << " Cents." << '\n';  //Cents
        else
            std::cout << "You Have " << pennies << " Cent." << '\n';  //Cents

        std::cout << "=========================" << '\n';
        std::cout << "TOTAL: $" << pennies*1.0/100 << '\n';
    }
    else
        std::cout << "You can't have negative pennies. THAT'S IMPOSSIBLE!!!" << '\n';

    return 0;
}
