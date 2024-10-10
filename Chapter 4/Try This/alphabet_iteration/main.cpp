#include <iostream>
using namespace std;

int main() {
    int i {0};
    while (i<100) {
        cout << char('a'+i) << '\t' << int('a'+i) << '\n';
        i++;
    }

    cout << "\n===============\n\n";
    //Rewriting using a for loop
    for(int i{0}; i<100; ++i)
        cout << char('a'+i) << '\t' << int('a'+i) << '\n';

    cout << "\n===============\n\n";

    //Rewriting using a for loop and also displaying capital letters
    for(int i{0}; i<100; ++i)
        cout << char('A'+i) << '\t' << int('A'+i) << '\n';

    return 0;
}
