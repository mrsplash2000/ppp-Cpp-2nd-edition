#include <iostream>
using namespace std;

int main() {

    int pennies {0};
    cout << "How many pennies do you have? ";
    cin >> pennies;

    int nickles {pennies/5};
    int dimes {pennies/10};
    int quarter {pennies/25};
    int half_dollars {pennies/50};

    if(pennies > 0) {

        if(pennies != 1)
            cout << "You Have " << pennies << " Pennies." << '\n';   //Pennies
        else
            cout << "You Have " << pennies << " Penny." << '\n';   //Pennies

        if(nickles != 1)
            cout << "You Have " << nickles << " Nickles." << '\n';  //Nickles
        else
            cout << "You Have " << nickles << " Nickle." << '\n';  //Nickles

        if(dimes != 1)
            cout << "You Have " << dimes << " Dimes." << '\n';  //Dimes
        else
            cout << "You Have " << dimes << " Dime." << '\n';  //Dimes

        if(quarter != 1)
            cout << "You Have " << quarter << " Quarters." << '\n';  //Quarters
        else
            cout << "You Have " << quarter << " Quarter." << '\n';  //Quarters

        if(half_dollars != 1)
            cout << "You Have " << half_dollars << " Half Dollars." << '\n';  //Half Dollars
        else
            cout << "You Have " << half_dollars << " Half Dollar." << '\n';  //Half Dollars

        if(pennies != 1)
            cout << "You Have " << pennies << " Cents." << '\n';  //Cents
        else
            cout << "You Have " << pennies << " Cent." << '\n';  //Cents

        cout << "=========================" << '\n';
        cout << "TOTAL: $" << pennies*1.0/100 << '\n';
    }
    else
        cout << "You can't have negative pennies. THAT'S IMPOSSIBLE!!!" << '\n';

    return 0;
}
