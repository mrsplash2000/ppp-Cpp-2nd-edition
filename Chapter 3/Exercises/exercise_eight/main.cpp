#include <iostream>
using namespace std;

int main() {
    int number {0};
    cout << "Enter An Integer: ";
    cin >> number;
    if(number%2 == 0)
        cout << number << " is an even number." << '\n';
    else
        cout << number << " is an odd number." << '\n';
    return 0;
}
