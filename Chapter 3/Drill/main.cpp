#include <iostream>
#include "std_lib_facilities.h"

int main() {
    std::cout << "Enter the name of the person you want to write to: ";
    std::string first_name {""};
    std::cin >> first_name;

    std::cout << "Enter Your Friend's name: ";
    std::string friend_name {""};
    std::cin >> friend_name;

    std::cout << "Is your friend male or female? Enter m or f: ";
    char friend_sex {0};
    std::cin >> friend_sex;

    std::cout << "Enter Your Friend's Age: ";
    int age {0};
    std::cin >> age;
    if(age <= 0 || age >= 110)
        simple_error("you're kidding!");

    std::cout << "\tDear " << first_name << ","
             << "\nHow are you? I am fine. I miss you."
             << "I've been thinking about the times \nwe were together lately."
             << "By the way, Have you seen " << friend_name << " lately?\n";
    if(friend_sex == 'm')
        std::cout << "If you see " << friend_name << " please ask him to call me.\n";
    else
        std::cout << "If you see " << friend_name << " please ask her to call me.\n";
    std::cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if(age < 12)
        std::cout << "Next year you will be " << age+1 << ".\n";
    if(age == 17)
        std::cout << "Next year you will be able to vote.\n";
    if(age >= 70)
        std::cout << "I hope you are enjoying retirement.\n";
    std::cout << "Yours sincerely.\n\n";
    std::cout << "Armin\n";
    return 0;
}
