#include "Parser.h"

using namespace std;

vector<string>& tokenize(string line, string delimiter){
    vector<string>* allSplits = new vector<string>;
    string lineCopy = line;
    while(lineCopy.size() != 0){
        int location = lineCopy.find(delimiter);
        if(location == string::npos){
            allSplits->push_back(lineCopy);
            break;
        }
        allSplits->push_back(lineCopy.substr(0, location));
        lineCopy.erase(0,location + delimiter.size());
    }
    return *allSplits;
}

void updateFirst(const string& input, const string& toFind, int& minPos, string& minString){
    if(input.find(toFind) < minPos){
        minPos = input.find(toFind);
        minString = toFind;
    }
}

string getNextSymbol(string& line){
//    keywords: return,if,else,var,function,document.write
//    symbols: +,-,*,/,(,),{,},=,<,>,,,;

    while(line.size() != 0 && isspace(line.at(0))){
        line.erase(0,1);
    }

    if(line.size() == 0){
        return "";
    }

    int minPos = line.size();
    string minString;

    vector<string> keywordsAndSymbols;
    keywordsAndSymbols.push_back("return");
    keywordsAndSymbols.push_back("if");
    keywordsAndSymbols.push_back("else");
    keywordsAndSymbols.push_back("var");
    keywordsAndSymbols.push_back("function");
    keywordsAndSymbols.push_back("document.write");
    keywordsAndSymbols.push_back("+");
    keywordsAndSymbols.push_back("-");
    keywordsAndSymbols.push_back("*");
    keywordsAndSymbols.push_back("/");
    keywordsAndSymbols.push_back("(");
    keywordsAndSymbols.push_back(")");
    keywordsAndSymbols.push_back("{");
    keywordsAndSymbols.push_back("}");
    keywordsAndSymbols.push_back("=");
    keywordsAndSymbols.push_back("<");
    keywordsAndSymbols.push_back(">");
    keywordsAndSymbols.push_back(";");
    keywordsAndSymbols.push_back(",");
    keywordsAndSymbols.push_back("\"");

    for(int i=0; i<keywordsAndSymbols.size(); i++){
        updateFirst(line, keywordsAndSymbols.at(i), minPos, minString);
    }
    if(minPos == 0) {
        line.erase(0, minString.size());
        return minString;
    }else{
        string toReturn = line.substr(0, minPos);
        line.erase(0, minPos);
        while(toReturn.size() != 0 && isspace(toReturn.back())){
            toReturn.erase(toReturn.end()-1, toReturn.end());
        }
        return toReturn;
    }
}

// Returns -1 if input is the empty string
// Returns 0 if input is not a number
// Returns 1 if input is a well-formed number
int isNumber(const string& input){
    if(input.size() == 0){
        return -1;
    }
    bool foundDecimal = false;
    for(int i=0; i<input.size(); i++){
        if(!isdigit(input.at(i))){
            if(input.at(i) == '.'){
                if(foundDecimal){
                    return 0;
                }else{
                    foundDecimal = true;
                    // allows trailing and leading decimal. ex: .1, 10.
                }
            }else{
                return 0;
            }
        }
    }

    return 1;

}


LINE_TYPE getLineType(string& line){

    string lineCopy = line;
    string firstSymbol = getNextSymbol(lineCopy);

    if(firstSymbol == ""){
        return BLANK_LINE;
    }else if(firstSymbol == "var") {
        return DEFINE_VAR;
    }else if(firstSymbol == "document.write"){
        return DOC_WRITE;
    }else if(firstSymbol == "function"){
    return FUNCTION_DEF;
    }else if(firstSymbol == "return"){
        return RETURN;
    }else if(firstSymbol == "if"){
        return IF;
    }else if(firstSymbol == "}") {
        string secondSymbol = getNextSymbol(lineCopy);
        if (secondSymbol == "") {
            return END_BLOCK;
        } else if (secondSymbol == "else") {
            return getNextSymbol(lineCopy) == "if" ? ELSE_IF : ELSE;
        }else{
            return END_BLOCK; // should never hit this
        }
    }else{
        return USER_DEFINED;
    }
}