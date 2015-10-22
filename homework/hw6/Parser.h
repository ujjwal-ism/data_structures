#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string>& tokenize(string line, string delimiter);
string getNextSymbol(string& line);
void updateFirst(const string&, const string&, int&, string&);
int isNumber(const string&);

#endif //UNTITLED_PARSER_H
