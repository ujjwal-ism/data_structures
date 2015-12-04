#ifndef CSE250_FALL2015_USERFUNCTION_H
#define CSE250_FALL2015_USERFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
#include <stack>

#include "Interpreter.h"

using namespace std;

//class Interpreter;

class UserFunction{

public:

    vector<string> functionDefinition;
    vector<string> parameterNames;

    double call(vector<double>& arguments,
                map<string, double>& variableMap,
                map<string, UserFunction>& functionMap,
                ofstream* outFile);

};


#endif //CSE250_FALL2015_USERFUNCTION_H
