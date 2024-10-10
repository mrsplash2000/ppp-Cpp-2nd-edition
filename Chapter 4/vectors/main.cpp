#include <iostream>
#include <vector>
#include<algorithm>
//A vector is simply a sequence of elements that you can access by an index.

int main() {
    //======Introduction======
    //a vector is similar to an array in C and other languages. However, you
    //need not specify the size (length) of a vector in advance, and you can
    //add as many elements as you like. As we go along, you’ll find that the
    //C++ standard vector has other useful properties.

    std::vector <int> numbers {3,6,4,8,12};
    std::vector <std::string> names {"Kant", "Plato", "Hume"};
    //Naturally, a vector will only accept elements of its declared element type

    int bass {999};
    names[0] = bass;
    std::cout << names[0] << '\n';

    //[-128,255] is ok. anything outside of this range results in either an error or warning
    names[0] = 256;
    std::cout << names[0] << '\n';
    //numbers[1] = "Aristotle"; //error: trying to assign a string to an int

    //We can also define a vector of a given size without specifying the element values.
    //In that case, we use the (n) notation where n is the number of elements, and the
    //elements are given a default value according to the element type.
    std::vector <int> numbers_two(6); //vector of 6 int initialized to 0
    std::vector <std::string> names_two(4); //vector of 4 strings initialized to ""
    std::cout << numbers_two[3] << '\n'; //output: 0
    std::cout << names_two[2] << '\n'; //output: empty line

    //Please note that you cannot simply refer to a nonexistent element of a vector
    //numbers[24560] = 32; //run-time error
    //======Introduction======

    std::cout << '\n';

    //======Traversing a vector======
    std::vector <int> v {2,9,8,14,420,65};
    //v.size() gives us the ability to access elements of a vector without
    //accidentally referring to an element outside the vector’s range.
    std::cout << "Vector's size: " << v.size() << '\n';
    //A vector knows its size, so we can print the elements of a vector like this
    for(int i{0}; i<v.size(); ++i)
        std::cout << v[i] << '\n';
    std::cout << '\n';
    //A simple loop over all the elements of a sequence, such as the elements of a vector.
    //range for loop
    for (int x : v) //Translation: for each x in v
        std::cout << x << '\n';
    std::cout << '\n';
    //We use the range-for-loop for simple loops over all the elements of a sequence
    //looking at one element at a time.
    //======Traversing a vector======

    //======Growing a vector======
    //Often, we start a vector empty and grow it to its desired size as we read or
    //compute the data we want in it.
    //push_back() adds a new element to the vector.
    //It is called a member function call; push_back() is a member function of vector
    //and must be called using this dot notation.
    std::vector <double> h {}; //start off empty, meaning that bass has no element
    h.push_back(2.7); //h[0] = 2.7
    h.push_back(4.5); //h[1] = 4.5
    h.push_back(7.9); //h[2] = 7.9
    for(double x:h)
        std::cout << x << '\n';
    //======Growing a vector======

    //======Numeric example======
    //YOU CAN UNCOMMENT THE CODE CHUNKS PRESENTED HERE TO SEE THEIR
    //BEHAVIOR
    //There is no limit to the range of computations we might perform on data, but
    //first we need to get it into our computer’s memory.
    //this for-statement will read all the doubles we give it and stop when we give it
    //anything else.

    /*
    std::vector <double> temps{};
    for(double temp{}; std::cin >> temp;)
        temps.push_back(temp);
    */

    //As usual, a for-loop shows what is going on “up front” so that the code is easier
    //to understand and accidental errors are harder to make. To limit the scope of our
    //input variable, temp, to the loop, we used a for-statement, rather than a while-statement.

    /*
    double temp{0.0};
    while(std::cin >> temp)
        temps.push_back(temp);
    */

    //Once we get data into a vector we can easily manipulate it.
    std::vector <double> temps_two {};
    double sum {0};
    for(double temp{0}; std::cin >> temp;) {
        temps_two.push_back(temp);
        sum += temp;
    }
    //compute mean temperature
    std::cout << "Average Temperature = " << sum/temps_two.size() << '\n';

    //compute median temperature
    sort(temps_two.begin(), temps_two.end());
    std::cout << "Median Temperature = " << temps_two[temps_two.size()/2] << '\n';
    //======Numeric example======

    return 0;
}
