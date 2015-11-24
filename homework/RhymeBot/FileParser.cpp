#include "FileParser.h"

using namespace std;

void pronunciationParser(RhymeBot rhymeBot){

    string filename = "data/cmudict-0.7b";
    ifstream dataFile;
    dataFile.open(filename);

    string line;
    while(!dataFile.eof()) {
        getline(dataFile, line);
        if(line.size() == 0 || !isalpha(line.at(0))){
            continue;
        }

        vector<string> parts = tokenize(line, " ");
        string word = parts.at(0);

        vector<Sound> pronounce;

        for(vector<string>::iterator it = parts.begin()+1; it < parts.end(); it++){
            if((*it) != "") {
                pronounce.push_back(SoundFactory::makeSound(*it));
            }
        }

        if(word.find_first_of("(") != string::npos){
            word = word.substr(0,word.find_first_of("("));
        }

        rhymeBot.insertWithPronunciation(word, pronounce);

    }
}



void parsePartsOfSpeech(RhymeBot rhymeBot, string filename, PART_OF_SPEECH partOfSpeech){

    ifstream dataFile;
    dataFile.open(filename);

    string line;
    while(!dataFile.eof()) {
        getline(dataFile, line);
        if (line.length() != 0 && isalpha(line.at(0)) && line.find_first_of(" ") != string::npos) {
            string word = line.substr(0, line.find_first_of(" "));

//            use the following line and modify RhymeBot to utilize multi-word parts of speech
//            vector<string> words = tokenize(word,"_");

            // extract only single words
            if(word.find_first_of("_") != string::npos){
                continue;
            }

            rhymeBot.addPartOfSpeech(word, partOfSpeech);
        }
    }
}

void parseAllPartsOfSpeech(RhymeBot rhymeBot){
    parsePartsOfSpeech(rhymeBot, "data/index.adj", ADJECTIVE);
    parsePartsOfSpeech(rhymeBot, "data/index.adv", ADVERB);
    parsePartsOfSpeech(rhymeBot, "data/index.noun", NOUN);
    parsePartsOfSpeech(rhymeBot, "data/index.sense", SENSE);
    parsePartsOfSpeech(rhymeBot, "data/index.verb", VERB);
}

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


