#include <iostream>
#include <string>

int main() {
    //detecting repeated words

    /*
    string previous = " "; //initialized to space
    string current;
    while(cin>>current){ //read a stream of words
        if(previous == current) //check if the word is the same as last
            cout << "Repeated Word: " << current << '\n';
        previous = current;
    }
    */

    //detecting repeated words and the number of words that were typed

    int number_of_words = 0;
    std::string previous_word = " ";
    std::string current_word;
    while(std::cin>>current_word){
        ++number_of_words;
        if(previous_word == current_word)
            std::cout << "Word number " << number_of_words
                     << " repeated: " << current_word << '\n';
        previous_word = current_word;
    }

    return 0;
}
