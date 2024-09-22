#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Method 1: using multiple ifs
    cout << "Enter Three Integers: ";
    int a {0}, b {0}, c {0};
    cin >> a >> b >> c;
    if(a<=b && b<=c)
        cout << a << ", " << b << ", " << c << '\n';
    else if(a<=c && c<=b)
        cout << a << ", " << c << ", " << b << '\n';
    else if(b<=a && a<=c)
        cout << b << ", " << a << ", " << c << '\n';
    else if(b<=c && c<=a)
        cout << b << ", " << c << ", " << a << '\n';
    else if(c<=a && a<=b)
        cout << c << ", " << a << ", " << b << '\n';
    else if(c<=b && b<=a)
        cout << c << ", " << b << ", " << a << '\n';
    //Method 2: Using Arrays
    cout << "Enter Three Integers: ";
    int  numbers [3] {0};
    for(int i{0}; i<3; i++) {
        cin >> numbers[i];
        if(i != 0) {
            for(int j{i}; j>0; j--){
                int temp {0};
                if(numbers[j] < numbers[j-1]) {
                    temp = numbers[j-1];
                    numbers[j-1] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
    }
    for(int i{0}; i<3; i++)
        cout << numbers[i] << ", ";
    cout << '\n';

    //Method 3: Using sort() Function
    int numbers_sorted[3] {0};
    for(int i{0}; i<3; i++)
        cin >> numbers_sorted[i];
    sort(numbers_sorted, numbers_sorted + 3);
    for (int i{0}; i<3; i++)
        cout << numbers_sorted[i] << ", ";
    return 0;
}
