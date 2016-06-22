#include "PalindromeFinder.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void truncate(string& input){

    for (int i = 0, len = input.length(); i < len; i++)
    {
        if (ispunct(input[i]))
        {
            input.erase(i--, 1);
            len = input.length();
        }
    }

    for (int i = 0, len = input.length(); i < len; i++)
    {
        if (input[i] ==' ')
        {
            input.erase(i--, 1);
            len = input.length();
        }
    }

   transform(input.begin(), input.end(), input.begin(), ::tolower);

}

PalindromeFinder::PalindromeFinder(){}

/*string PalindromeFinder::toString(){
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
*/
//returns true if input is a palindrome, false otherwise. If it is a palindrome and
// it is the largest seen so far, it should be stored in largestPalindromeFound.
bool PalindromeFinder::isPalindrome(string input){
    
    truncate(input);
    int n = input.length();

    for (int i = 0; i < (n/2); ++i)
    {
        if(input.at(i) != input.at(n-i-1))
            return false;
    }
    return true;
    
}
/*
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
*/
int main(int argc, char const *argv[])
{
    PalindromeFinder *baba;
    string str;

    cout<< "Enter a string>>>>"<<endl;
    getline(cin,str);

    cout<< baba->isPalindrome(str)<<endl;
    
    return 0;
}