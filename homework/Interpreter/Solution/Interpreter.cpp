#include "Interpreter.h"



void Interpreter::interpretScript(ifstream& inputFile, ofstream& outputFile){

    outFile = &outputFile;
    inFile = &inputFile;
    string lineFromFile;

    while (getline(*inFile, lineFromFile))
    {
        interpretLine(lineFromFile);
    }
}

void Interpreter::interpretLine(string line){

    LINE_TYPE lineType = getLineType(line);

    switch (lineType){
        case BLANK_LINE:
            break;
        case DEFINE_VAR:
            if(ifStack.empty() || ifStack.top() == 1) {
                defineVarLine(line);
            }
            break;
        case USER_DEFINED:
            if(ifStack.empty() || ifStack.top() == 1) {
                userDefinedLine(line);
            }
            break;
        case DOC_WRITE:
            if(ifStack.empty() || ifStack.top() == 1) {
                docWriteLine(line);
            }
            break;

        case FUNCTION_DEF:
            if(ifStack.empty() || ifStack.top() == 1) {
                functionDefLine(line);
            }
            break;
        case RETURN:
            if(ifStack.empty() || ifStack.top() == 1) {
                returnLine(line);
            }
            break;

        case END_BLOCK:
            endBlockLine(line);
            break;
        case IF:
            ifLine(line);
            break;
        case ELSE:
            elseLine(line);
            break;
        case ELSE_IF:
            elseIfLine(line);
            break;
    }

}

void Interpreter::defineVarLine(string line){
    vector<string> sides = tokenize(line, "=");
    if(sides.size() != 2){
        cout << "everything is broken" << endl;
        return;
    }
    string lhs = sides[0];
    string rhs = sides[1];

    getNextSymbol(lhs); // var

    string newVariableName = getNextSymbol(lhs);
    double newVariableValue = isFunctionCall(rhs) ? callFunction(rhs) : computeInfix(rhs);

    variableMap.insert(make_pair(newVariableName,newVariableValue));
}

void Interpreter::userDefinedLine(string line){

    vector<string> sides = tokenize(line, "=");
    if(sides.size() == 2) {
        // var assignment
        string lhs = sides[0];
        string rhs = sides[1];

        string oldVariableName = getNextSymbol(lhs);
        double newVariableValue = isFunctionCall(rhs) ? callFunction(rhs) : computeInfix(rhs);

        variableMap.erase(oldVariableName);
        variableMap.insert(make_pair(oldVariableName, newVariableValue));

    }else if(sides.size() == 1) {
        // function call for side effects
        callFunction(sides[0]);

    }else {
        cout << "everything is broken" << endl;
    }
}

void Interpreter::docWriteLine(string line){
    getNextSymbol(line); // document.write
    getNextSymbol(line); // (
    int foundQuote = line.find_first_of("\"");
    if(foundQuote == 0){
        int secondQuote = line.find_last_of("\"");
        string toPrint = line.substr(foundQuote+1, secondQuote-(foundQuote+1));
        (*outFile) << toPrint;
    }else{
        string varName = getNextSymbol(line);
        double value = variableMap.at(varName);
        (*outFile) << value;
    }
}


void Interpreter::functionDefLine(string line){
    UserFunction newFunction;
    getNextSymbol(line); // function
    string functionName = getNextSymbol(line);
    string inList = getNextSymbol(line); // (
    while(inList != ")"){
        if(inList != "," && inList != "("){
            newFunction.parameterNames.push_back(inList);
        }
        inList = getNextSymbol(line);
    }
    // line should == "{"
    string lineFromFile;
    while (getline(*inFile, lineFromFile)){
        if(ifStack.empty() && getLineType(lineFromFile) == END_BLOCK){
            break;
        }else if(getLineType(lineFromFile) == IF) {
            ifStack.push(3);
        }else if(getLineType(lineFromFile) == END_BLOCK){
            ifStack.pop();
        }
        newFunction.functionDefinition.push_back(lineFromFile);
    }
    functionMap.insert(make_pair(functionName,newFunction));
}


void Interpreter::returnLine(string line){
    getNextSymbol(line); // return
    string returnVar = getNextSymbol(line);
    this->toReturn = isNumber(returnVar) ? stof(returnVar) : variableMap.at(returnVar);
    this->foundReturn = true;
}


bool Interpreter::computeIf(string line){
    getNextSymbol(line); // if
    getNextSymbol(line); // (
    string leftVar = getNextSymbol(line);
    string comparison = getNextSymbol(line);
    string rightVar = getNextSymbol(line);

    double leftValue = isNumber(leftVar) ? stof(leftVar) : variableMap.at(leftVar);
    double rightValue = isNumber(rightVar) ? stof(rightVar) : variableMap.at(rightVar);

    return comparison == ">" ? leftValue > rightValue : leftValue < rightValue;
}


void Interpreter::endBlockLine(string line){
    ifStack.pop();
}

void Interpreter::ifLine(string line){
    if(!ifStack.empty() && (ifStack.top() == 0 || ifStack.top() == 2)){
        ifStack.push(2);
    }else if(computeIf(line)) {
        ifStack.push(1);
    } else{
        ifStack.push(0);
    }
}

void Interpreter::elseLine(string line){
    if(ifStack.top() == 0){
        ifStack.pop();
        ifStack.push(1);
    }else if(ifStack.top() == 1){
        ifStack.pop();
        ifStack.push(2);
    }
}

void Interpreter::elseIfLine(string line){
    if(ifStack.top() == 0) {
        getNextSymbol(line); // }
        getNextSymbol(line); // else
        ifStack.pop();
        if(computeIf(line)) {
            ifStack.push(1);
        } else{
            ifStack.push(0);
        }
    } else if(ifStack.top() == 1){
        ifStack.pop();
        ifStack.push(2);
    }
}



bool Interpreter::isFunctionCall(string expression){
    int foundOperator = expression.find_first_of("+-*/");
    int foundOpen = expression.find_first_of("(");
    return foundOperator == string::npos && foundOpen != string::npos;
}


double Interpreter::callFunction(string functionCall){
    string functionName = getNextSymbol(functionCall);
    vector<double> arguments;
    string inList = getNextSymbol(functionCall); // (
    while(inList != ")" && inList != ""){
        if(inList != "," && inList != "("){
            arguments.push_back(isNumber(inList) ? stof(inList) : variableMap.at(inList));
        }
        inList = getNextSymbol(functionCall);
    }
    UserFunction calledFunction = functionMap.at(functionName);
    return calledFunction.call(arguments, variableMap, functionMap, outFile);
}



double Interpreter::evaluatePostfix(queue<string> postfixExpression){
    stack<double> operands;
    while(!postfixExpression.empty()) {
        string nextThing = postfixExpression.front();
        postfixExpression.pop();
        if(nextThing != "+" && nextThing != "-" && nextThing != "*" && nextThing != "/"){
            // operand
            operands.push(isNumber(nextThing) ? stof(nextThing) : variableMap.at(nextThing));
        }else{
            // operator
            double second = operands.top();
            operands.pop();
            double first = operands.top();
            operands.pop();
            switch(infixEnum(nextThing)){
                case PLUS:
                    operands.push(first+second);
                    break;
                case TIMES:
                    operands.push(first*second);
                    break;
                case MINUS:
                    operands.push(first-second);
                    break;
                case DIVIDE:
                    operands.push(first/second);
                    break;
                default:
                    cout << "I shouldn't be here" << endl;
                    break;
            }
        }
    }
    if(operands.size() != 1){
        cout << "not 1 operand" << endl;
    }
    return operands.top();
}


queue<string> Interpreter::infixToPostfix(string infixExpression){

    queue<string> postfixExpression;
    stack<string> workingStack;

    while(infixExpression != ""){
        string symbol = getNextSymbol(infixExpression);
        switch(infixEnum(symbol)){
            case PLUS:
            case MINUS:
                while(!workingStack.empty() && workingStack.top() != "("){
                    postfixExpression.push(workingStack.top());
                    workingStack.pop();
                }
                workingStack.push(symbol);
                break;
            case TIMES:
            case DIVIDE:
                while(!workingStack.empty() &&
                        workingStack.top() != "(" &&
                        workingStack.top() != "+" &&
                        workingStack.top() != "-"){
                    postfixExpression.push(workingStack.top());
                    workingStack.pop();
                }
                workingStack.push(symbol);
                break;
            case OPEN:
                workingStack.push(symbol);
                break;
            case CLOSE:
                while(workingStack.top() != "("){
                    postfixExpression.push(workingStack.top());
                    workingStack.pop();
                }
                workingStack.pop();
                break;
            case OTHER:
                postfixExpression.push(symbol);
                break;
        }
    }

    while(!workingStack.empty()){
        postfixExpression.push(workingStack.top());
        workingStack.pop();
    }

    return postfixExpression;
}

double Interpreter::computeInfix(string expression){
    return evaluatePostfix(infixToPostfix(expression));
}


INFIX_SYMBOL infixEnum(string input){
    if(input == "+"){
        return PLUS;
    } else if(input == "-"){
        return MINUS;
    } else if(input == "*"){
        return TIMES;
    } else if(input == "/"){
        return DIVIDE;
    } else if(input == "("){
        return OPEN;
    } else if(input == ")"){
        return CLOSE;
    }else{
        return OTHER;
    }
}


void printVariables(map<string, double> varMap){
    cout << endl;
    for(map<string, double>::iterator it = varMap.begin(); it != varMap.end(); it++){
        cout << (*it).first << ": " << (*it).second << endl;
    }
}