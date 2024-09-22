#include <iostream>
using namespace std;

int main() {
    char operation {'+'};
    double value1 {0}, value2 {0};
    cout << "Enter your operation symbol and two values: ";
    cin >> operation >> value1 >> value2;
    switch(operation) {
        case '+':
            cout << value1 + value2 << '\n';
            break;
        case '-':
            cout << value1 - value2 << '\n';
            break;
        case '*':
            cout << value1 * value2 << '\n';
            break;
        case '/':
            cout << value1 / value2 << '\n';
            break;
        default:
            cout << "Unknown Operation!" << '\n';
    }
    return 0;
}
