/*
Write a program that prompts the user to enter three integer values, and
then outputs the values in numerical sequence separated by commas. So,
if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
values are the same, they should just be ordered together. So, the input
4 5 4 should give 4, 4, 5.
*/

#include <iostream>
#include <algorithm> //for using the sort() function

int main() {
    //Method 1: using multiple ifs
    std::cout << "Enter Three Integers: ";
    int a {0}, b {0}, c {0};
    std::cin >> a >> b >> c;
    if(a<=b && b<=c)
        std::cout << a << ", " << b << ", " << c << '\n';
    else if(a<=c && c<=b)
        std::cout << a << ", " << c << ", " << b << '\n';
    else if(b<=a && a<=c)
        std::cout << b << ", " << a << ", " << c << '\n';
    else if(b<=c && c<=a)
        std::cout << b << ", " << c << ", " << a << '\n';
    else if(c<=a && a<=b)
        std::cout << c << ", " << a << ", " << b << '\n';
    else if(c<=b && b<=a)
        std::cout << c << ", " << b << ", " << a << '\n';

    //Method 2: Using Arrays
    std::cout << "Enter Three Integers: ";
    int  numbers [3] {0};
    for(int i{0}; i<3; i++) {
        std::cin >> numbers[i];
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
        std::cout << numbers[i] << ", ";
    std::cout << '\n';

    //Method 3: Using sort() Function
    std::cout << "Enter Three Integers: ";
    int numbers_sorted[3] {0};
    for(int i{0}; i<3; i++)
        std::cin >> numbers_sorted[i];
    std::sort(numbers_sorted, numbers_sorted + 3);
    for (int i{0}; i<3; i++)
        std::cout << numbers_sorted[i] << ", ";

    return 0;
}
