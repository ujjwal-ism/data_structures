#include <iostream>

std::string getCustomString();
int countChars(std::string, char);
int countCharsCustom(char);


std::string getCustomString(){
    return "Jesse Hartloff and then some more words";
}


int countChars(std::string words, char character){
    int count=0;
    for(int i=0; i<words.length(); i++){
        if(words[i] == character){
            count++;
        }
    }
    return count;
}


int countCharsCustom(char character){
    return countChars(getCustomString(), character);
}