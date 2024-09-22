#include <iostream>
using namespace std;

int main() {
    string value {""};
    cout << "Enter The Value In English Format: ";
    while(cin >> value) {
        switch(value){
            case "zero":
            case "Zero":
                cout << "0" << '\n';
                break;
            case "one":
            case "One":
                cout << "1" << '\n';
                break;
            case "two":
            case "Two":
                cout << "2" << '\n';
                break;
            case "three":
            case "Three":
                cout << "0" << '\n';
                break;
            case "four":
            case "Four":
                cout << "4" << '\n';
                break;
            default:
                cout << "not a number I know" << '\n';
        }
    }

    return 0;
}
