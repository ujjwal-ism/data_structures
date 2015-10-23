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
//    keywords: return,if,else,for,Integer,Double,break,continue
//    symbols: +,-,*,/,(,),{,},=,<,>,;,,
//    implied: ==,<=,>=

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
    keywordsAndSymbols.push_back("for");
    keywordsAndSymbols.push_back("Integer");
    keywordsAndSymbols.push_back("Double");
    keywordsAndSymbols.push_back("break");
    keywordsAndSymbols.push_back("continue");
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

    for(int i=0; i<keywordsAndSymbols.size(); i++){
        updateFirst(line, keywordsAndSymbols.at(i), minPos, minString);
    }
    if(minPos == 0) {
        line.erase(0, minString.size());
        return minString;
    }else{
        string toReturn = line.substr(0, minPos);
        line.erase(0, minPos);
        while(toReturn.size() != 0 && isspace(line.back())){
            line.erase(line.end()-1, line.end());
        }
        return toReturn;
    }
}

// Returns -1 if input is the empty string
// Returns 0 if input is not a number
// Returns 1 if input is a well-formed integer
// Returns 2 if input is a well-formed double
int isNumber(const string& input){
    if(input.size() == 0){
        return -1;
    }
    bool foundDecimal = false;
    for(int i=0; i<input.size(); i++){
        if(!isnumber(input.at(i))){
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

    return foundDecimal ? 2 : 1;

}