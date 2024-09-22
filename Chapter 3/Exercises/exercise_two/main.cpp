#include <iostream>
using namespace std;

int main() {
    double miles {0};
    cout << "Enter the number of miles: ";
    while(cin >> miles)
        cout << miles << " = " << miles*1.609 << " kilometers" <<'\n';
    return 0;
}
