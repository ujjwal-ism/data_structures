// ============================================================================
// HW1.h
// ~~~~~~~
// author : David Dobmeier
// - a simple program to practice simple C++ syntax
// ============================================================================
#ifndef _HW1_H
#define _HW1_H
#include <string>
   // returns a string that starts with your name (in any format) followed by
   // any characters you choose. ex. "Jesse Hartloff and then some more words"
   std::string getCustomString(); 

   // takes a string and char returning the number of occurrences of the char
   // in the string. ex. countChars("This is a sentence", 't') == 1
   int countChars(std::string, char);

   // returns the number of occurrences of a char in your custom string. 
   // ex. using my custom string above: countCharsCustom('f') == 2
   int countCharsCustom(char);

//End Header
#endif
