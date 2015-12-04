#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum LINE_TYPE
{
    BLANK_LINE, // 0: A line that doesn't need to be executed
    DEFINE_VAR, // 1: A variable defined with "def" and assigned a value
    USER_DEFINED, // 2: The line starts with a user-defined variable or function name.
                  // This can be a variable assignment and/or function call.
    DOC_WRITE, // 3: document.write is called. Argument can be a single string or a single variable.
               // Output should be written to the output file
    FUNCTION_DEF, // 4: Beginning of a new user function definition
    RETURN, // 5: return statement of a user-defined function. Will return a single variable
    END_BLOCK, // 6: A single '}' on a line
    IF, // 7: The beginning of an if block. Always ends with '{' on the same line. The condition will
        // be a comparison of 2 variables using '<' or '>' only.
    ELSE, // 8: A line of the form "} else {"
    ELSE_IF // 9: A line of the form "} else if(<condition>) {"
};

// returns a vector of sub-strings of line separated by delimiter.
// ex:
//  line = "var1,var2,var3"
//  delimiter = ','
//  output = {"var1", "var2", "var3"}
vector<string>& tokenize(string line, string delimiter);

// Returns the next symbol in the line. This can be any of the keywords, a character symbol (+,-,(,))
// or a user-defined name (function or variable). This is pass by reference and will modify the input
// so repeated calls can parse the entire string. If you don't want the input to be modified, make a
// copy of the string and pass the copy
string getNextSymbol(string& line);

// Returns -1 if input is the empty string
// Returns 0 if input is not a number
// Returns 1 if input is a well-formed number
int isNumber(const string&);

// Returns the type of the line. See the LINE_TYPE enum above for details on the different line types
LINE_TYPE getLineType(string&);


// internal function to be used by getNextSymbol
void updateFirst(const string&, const string&, int&, string&);

#endif //UNTITLED_PARSER_H
