#include "PalindromeFinder.h"
#include <string>
#include <iostream>

using namespace std;


PalindromeFinder::PalindromeFinder(){}

string PalindromeFinder::toString(){
    return "largest palindrome seen so far is \"" + this->getLargestPalindromeFound() +
            "\" with size " + to_string(this->getSizeOfLargestPalindromeFound());
}

string PalindromeFinder::getLargestPalindromeFound(){
    return this->largestPalindromeFound;
}

int PalindromeFinder::getSizeOfLargestPalindromeFound(){
    return this->largestPalindromeFound.length();
}

//returns true if input is a palindrome, false otherwise. If it is a palindrome and
// it is the largest seen so far, it should be stored in largestPalindromeFound.
bool PalindromeFinder::isPalindrome(string input){
    //TODO define isPalindrome with the desired functionality
    return false;
}

//Returns the largest palindrome in the string array inputStrings. If this is the
// the largest palindrome seen, this instance of the class should store it in
// largestPalindromeFound.
string PalindromeFinder::getLargestPalindrome(string* inputStrings, int numberOfStrings){
    //TODO Debug getLargestPalindrome so it outputs the proper string and updates largestPalindromeFound
    string largestPalindrome = "";
    for(int i=0; i<numberOfStrings; i++){
        if(this->isPalindrome(*(inputStrings+i))){
            largestPalindrome = *(inputStrings);
        }
    }
    this->largestPalindromeFound = largestPalindrome;
    return largestPalindrome;
}

//truncates the input string to its largest substring that is a palindrome.
// If this palindrome is the biggest seen so far, the class should store it
// in largestPalindromeFound.
void PalindromeFinder::truncateToLargestPalindrome(string& inputString){
    //TODO define truncateToLargestPalindrome with the proper functionality
}

