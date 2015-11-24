#ifndef UNTITLED_FILEPARSER_H
#define UNTITLED_FILEPARSER_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "RhymeBot.h"
#include "Sound.h"

using namespace std;

//need to handle multiple pronunciations for some RhymeBot

void pronunciationParser(RhymeBot);
void parsePartOfSpeech(RhymeBot, string, PART_OF_SPEECH);
void parseAllPartsOfSpeech(RhymeBot);

vector<string>& tokenize(string line, string delimiter);

#endif //UNTITLED_FILEPARSER_H
