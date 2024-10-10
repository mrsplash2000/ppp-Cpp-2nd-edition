#include <iostream>
using namespace std;
//converts yen, euros, and pounds into dollars.
int main() {
    //======VARIABLES======
    constexpr double dollar_per_yen {0.0069};
    constexpr double dollar_per_euro {1.11};
    constexpr double dollar_per_pound {1.31};
    double value {0};
    char unit {' '};
    //======VARIABLES======

    //Using if statements
    cout << "Y - Yen\nE - Euro\nP - Pound\n";
    cout << "Please Enter A Value Followed By The Unit: ";
    cin >> value >> unit;
    if (unit == 'y' || unit == 'Y')
        cout << value << " Yen = " << value*dollar_per_yen << "$\n";
    else if(unit == 'e' || unit == 'E')
        cout << value << " Euro = " << value*dollar_per_euro << "$\n";
    else if(unit == 'p' || unit == 'P')
        cout << value << " Pound = " << value*dollar_per_pound << "$\n";
    else
        cout << "' " << unit << " ' is an unknown unit!\n";

    //Rewriting using switch statement
    cout << "Y - Yen\nE - Euro\nP - Pound\n";
    cout << "Please Enter A Value Followed By The Unit: ";
    cin >> value >> unit;
    switch(unit){
        case 'y': case 'Y':
            cout << value << " Yen = " << value*dollar_per_yen << "$\n";
            break;
        case 'e': case 'E':
            cout << value << " Euro = " << value*dollar_per_euro << "$\n";
            break;
        case 'p': case 'P':
            cout << value << " Pound = " << value*dollar_per_pound << "$\n";
            break;
        default:
            cout << "' " << unit << " ' is an unknown unit!\n";
            break;
    }

    return 0;
}
