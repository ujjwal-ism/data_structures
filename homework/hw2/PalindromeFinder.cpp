#include "PalindromeFinder.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void truncateString(string& input){
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());
    transform(input.begin(), input.end(), input.begin(), ::tolower);
}

PalindromeFinder::PalindromeFinder(){}

string PalindromeFinder::toString(){
    stringstream ss;
    ss << "largest palindrome seen so far is \"" << this->getLargestPalindromeFound();
    ss << "\" with size " << this->getSizeOfLargestPalindromeFound();
    return ss.str();
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

    truncateString(input);
    int n = input.length();

    for(int i=0; i<(n/2); i++){
        if(input.at(i) != input.at(n-i-1)){
            return false;
        }
    }

    if(input.length() > this->getSizeOfLargestPalindromeFound()){
        this->largestPalindromeFound = input;
    }
    return true;
}



//Returns the largest palindrome in the string array inputStrings. If this is the
// the largest palindrome seen, this instance of the class should store it in
// largestPalindromeFound.
string PalindromeFinder::getLargestPalindrome(string* inputStrings, int numberOfStrings){

    string largestPalindrome = "";
    int largestSize = 0;

    for(int i=0; i<numberOfStrings; i++){
        string currentString = *(inputStrings+i);
        truncateString(currentString); // needed for proper length comparison

        if(this->isPalindrome(currentString) && (currentString.length() > largestSize) ){
            largestPalindrome = *(inputStrings+i);
            largestSize = currentString.length();
        }

    }

    return largestPalindrome;
}

//truncates the input string to its largest substring that is a palindrome.
// If this palindrome is the biggest seen so far, the class should store it
// in largestPalindromeFound.
void PalindromeFinder::truncateToLargestPalindrome(string& inputString){

    // This is a simple O(n^3) runtime algorithm. This is much too slow to be practical, but it is the
    //  simpler to understand what it's doing than the more efficient algorithms. As the course goes on,
    //  you will have to submit efficient functions.

    truncateString(inputString);

    int largestFound = 0;
    string bestPalindrome = "";
    int n=inputString.length();

    // check every possible substring and track the largest one that is a palindrome
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i+1; j++){
            string subString = inputString.substr(i,j);
            if(this->isPalindrome(subString) && subString.length() > largestFound){
                bestPalindrome = subString;
                largestFound = subString.length();
            }
        }
    }

    inputString = bestPalindrome;
}
