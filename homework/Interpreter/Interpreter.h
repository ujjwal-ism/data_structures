#ifndef UNTITLED_INTERPRETER_H
#define UNTITLED_INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "UserFunction.h"
#include "Parser.h"

using namespace std;

class Interpreter {

private:
    // suggestions:
    map<string, double> variableMap; // a map of variable names to Variable values
    map<string, UserFunction> functionMap; // a map of user defined functions
    // stack to remember nesting of if blocks

public:

    void interpretScript(ifstream&, ofstream&);

    // suggestions:
    double computeInfix(string); // separate function for computing infix notation
    // Other helper functions

};


#endif //UNTITLED_INTERPRETER_H
