#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    //======Text example======
    //simple dictionary: list of sorted words
    std::vector <std::string> words {};
    for(std::string temp {}; std::cin >> temp;)
        words.push_back(temp);

    std::cout << "Number of words: " << words.size() << '\n';

    /*
    This chunk of code first sorts the words alphabetically in the vector. Then,
    the loop prints out the words being pushed in the vector but eliminates
    repeated words in the process.
    EXAMPLE:
    Input: bass/guitar/drums/keyboard/piano/flute/bass
    Output: bass/drums/flute/guitar/keyboard/piano
    */

    /*
    One small note about the sort() function is that it can't sort properly when there's
    a mixture of small and capital letters invovled.
    */

    sort(words.begin(), words.end());
    for(int i{0}; i<words.size(); ++i)
        if(i==0 || words[i-1]!=words[i])
            std::cout << words[i] << '\n';
    //======Text example======

    return 0;
}
