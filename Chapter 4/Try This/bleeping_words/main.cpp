/*
Write a program that “bleeps” out words that you don’t like; that is, you
read in words using cin and print them again on cout. If a word is among a
few you have defined, you write out BLEEP instead of that word. Start with
one “disliked word” such as:
string disliked = “Broccoli”;
When that works, add a few more.
*/

#include <iostream>
#include <vector>
#include <cstring> //for using toupper() or tolower() functions

int main() {
    //Sorry in advance for these bad words.
    std::vector <std::string> bad_words {"shit", "fuck", "broccoli"};
    bool profanity_check {false};

    for(std::string input {""}; std::cin >> input;){
        //checking if the word is in the bad words category.
        for(std::string x : bad_words) {
            std::string temp {input};
            temp[0] = tolower(temp[0]);
            if(temp == x)
                profanity_check = true;
        }

        //checking if prfanity is true or not
        if(profanity_check)
            std::cout << "BLEEP" << '\n';
        else
            std::cout << input << '\n';

        //reseting profanity check
        profanity_check = false;
    }
    return 0;
}
