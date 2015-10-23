#include "FileParser.h"

using namespace std;

void pronunciationParser(){

    map<string, vector<string> > wordsAndPronunciation;

    string filename = "data/cmudict-0.7b";
    ifstream dataFile;
    dataFile.open(filename);

    string line;

    while(getline(dataFile, line)) {
//        cout << line << endl;
        string word = line.substr(0,line.find_first_of(" "));
        if(word == ""){
            continue;
        }
        cout << word;
        string pronounce = line.substr(line.find_first_of(" ")+1, line.length()-line.find_first_of(" ")-1);
//        cout <<  ": " << pronounce << endl;
        vector<string> pronouncing;
        int index = 0;
        for(int i=0; i<pronounce.length(); i++){
            if(isspace(pronounce[i]) || i == pronounce.length()-1){
                string thisOne = pronounce.substr(index, i-index);
                index = i;
//                if(thisOne != " "){
                    pronouncing.push_back(thisOne);
//                }
            }
        }

        cout << word << ": ";
        for(int i=0; i<pronouncing.size(); i++){
            cout << pronouncing[i] << " ";
        }
        cout << endl;

        wordsAndPronunciation.insert(make_pair(word, pronouncing));
    }

    vector<string> pro = wordsAndPronunciation.at("MAX");

    cout << endl << endl;

    for(int i=0; i<pro.size(); i++){
        cout << pro[i] << " ";
    }

    cout << endl;
}