#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Enter Two Integer Values: ";
    double val1 {0};
    double val2 {0};
    double ratio_result {0};
    cin >> val1 >> val2;

    if(val1 == val2) {
        cout << "val1=" << val1 << " == val2=" << val2 << '\n';
        ratio_result = val1/val2;
    }
    else if(val1>val2) {
        cout << "val1=" << val1 << " > val2=" << val2 << '\n';
        ratio_result = (val2*1.0) / (val1*1.0);
    }
    else {
        cout << "val1=" << val1 << " < val2=" << val2 << '\n';
        ratio_result = (val1*1.0) / (val2*1.0);
    }


    cout << "Sum = " << val1+val2 << '\n';
    cout << "Difference = " << abs(val1-val2) << '\n';
    cout << "Product = " << val1*val2 << '\n';
    cout << "Ratio = " << ratio_result << '\n';



    return 0;
}
