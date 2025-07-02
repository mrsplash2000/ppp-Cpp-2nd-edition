#include <iostream>
#include <algorithm>  //for using the sort() function
#include <cstring>       //for using the toupper() and tolower() functions

//The problem with this code is that when you enter a mixture of capital and small letters, it can't sort them alphabetically
//Example: Your input: Max geralt Nicolai
//Output: Max, Nicolai, geralt
//Solution: I must find a way to convert first letters into the same type (either being small or capital)

int main() {
    //Method 1: using multiple ifs (Not Recommended)
    std::string a{""}, b{""}, c{""};
    std::cout << "Enter Three Words: ";
    std::cin >> a >> b>> c;
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    c[0] = toupper(c[0]);
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
    std::cout << "Enter Three Words: ";
    std::string  words [3] {""};
    for(int i{0}; i<3; i++) {
        std::cin >> words[i];
        words[i][0] = toupper(words[i][0]);
        if(i != 0) {
            for(int j{i}; j>0; j--){
                std::string temp {0};
                if(words[j] < words[j-1]) {
                    temp = words[j-1];
                    words[j-1] = words[j];
                    words[j] = temp;
                }
            }
        }
    }
    for(int i{0}; i<3; i++)
        std::cout << words[i] << ", ";
    std::cout << '\n';

    //Method 3: Using sort() Function
    std::cout << "Enter Three Words: ";
    std::string words_sorted[3] {""};
    for(int i{0}; i<3; i++) {
        std::cin >> words_sorted[i];
        words_sorted[i][0] = toupper(words_sorted[i][0]);
    }
    sort(words_sorted, words_sorted + 3);
    for (int i{0}; i<3; i++)
        std::cout << words_sorted[i] << ", ";
    return 0;
}
