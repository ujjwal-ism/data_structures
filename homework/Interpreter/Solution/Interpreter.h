#ifndef UNTITLED_INTERPRETER_H
#define UNTITLED_INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
#include <stack>

#include "UserFunction.h"
#include "Parser.h"

using namespace std;

enum INFIX_SYMBOL{
    PLUS,MINUS,TIMES,DIVIDE,OPEN,CLOSE,OTHER
};

class UserFunction;


class Interpreter {

    // Gives UserFunction access to all the Interpreter private functions
    friend class UserFunction;

private:
    map<string, double> variableMap; // a map of variable names to Variable values
    map<string, UserFunction> functionMap; // a map of user defined functions

    // stack to remember nesting of if blocks
    // 0: Condition for current block is false
    // 1: Condition for current block is true
    // 2: Current block is being skipped
    stack<int> ifStack;
    bool lineSkipping = false;

    ofstream* outFile;
    ifstream* inFile;

    double toReturn = 0.0;
    bool foundReturn = false;

    void interpretLine(string);

    void defineVarLine(string);
    void userDefinedLine(string);
    void docWriteLine(string);

    void functionDefLine(string);
    virtual void returnLine(string);
    void endBlockLine(string);

    void ifLine(string);
    void elseLine(string);
    void elseIfLine(string);


    bool computeIf(string);

    bool isFunctionCall(string);
    double callFunction(string);

    double computeInfix(string);
    queue<string> infixToPostfix(string);
    double evaluatePostfix(queue<string>);

public:

    void interpretScript(ifstream&, ofstream&);

};

INFIX_SYMBOL infixEnum(string);
void printVariables(map<string, double>);

#endif //UNTITLED_INTERPRETER_H
