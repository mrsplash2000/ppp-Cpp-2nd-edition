#include "std_lib_facilities.h"

int main() {
    cout << "Enter the name of the person you want to write to: ";
    string first_name {""};
    cin >> first_name;

    cout << "Enter Your Friend's name: ";
    string friend_name {""};
    cin >> friend_name;

    cout << "Is your friend male or female? Enter m or f: ";
    char friend_sex {0};
    cin >> friend_sex;

    cout << "Enter Your Friend's Age: ";
    int age {0};
    cin >> age;
    if(age <= 0 || age >= 110)
        simple_error("you're kidding!");

    cout << "\tDear " << first_name << ","
             << "\nHow are you? I am fine. I miss you."
             << "I've been thinking about the times \nwe were together lately."
             << "By the way, Have you seen " << friend_name << " lately?\n";
    if(friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    else
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if(age < 12)
        cout << "Next year you will be " << age+1 << ".\n";
    if(age == 17)
        cout << "Next year you will be able to vote.\n";
    if(age >= 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Yours sincerely.\n\n";
    cout << "Armin\n";
    return 0;
}
