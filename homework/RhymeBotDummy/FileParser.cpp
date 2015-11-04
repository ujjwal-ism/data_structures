#include "FileParser.h"

using namespace std;

int hashString(string input, int n){

//    int hashValue = 0;
//
//    for(int i=0; i<input.size(); i++){
//        hashValue += (int)input.at(i);
//    }

    hash<string> hasher;
    int hashValue = hasher(input);

    hashValue = hashValue < 0 ? -hashValue : hashValue;
    return hashValue % n;
}




void pronunciationParser(){

    int n = 1024;
    vector<vector<string> > hashTable(n);

    int insert = 0;

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

        hashTable.at(hashString(word, n)).push_back(word);

        vector<string> thisBin = hashTable.at(hashString(word, n));
        for(int i=0; i<thisBin.size(); i++){
            if(thisBin.at(i) == word){
                thisBin.erase()
            }
        }
        return false;

        insert++;
//        cout << word;
//        string pronounce = line.substr(line.find_first_of(" ")+1, line.length()-line.find_first_of(" ")-1);
//        cout <<  ": " << pronounce << endl;
//        vector<string> pronouncing;
//        int index = 0;
//        for(int i=0; i<pronounce.length(); i++){
//            if(isspace(pronounce[i]) || i == pronounce.length()-1){
//                string thisOne = pronounce.substr(index, i-index);
//                index = i;
//                if(thisOne != " "){
//                    pronouncing.push_back(thisOne);
//                }
//            }
//        }

//        cout << word << ": ";
//        for(int i=0; i<pronouncing.size(); i++){
//            cout << pronouncing[i] << " ";
//        }
//        cout << endl;

//        wordsAndPronunciation.insert(make_pair(word, pronouncing));
    }

//    vector<string> pro = wordsAndPronunciation.at("MAX");

//    cout << endl << endl;

    int max = 0;
    int total = 0;
    int bins = 0;
    for(int i=0; i<n; i++){
        if(hashTable.at(i).size() != 0){ bins++;}
        if(hashTable.at(i).size() == 56){ continue;}
        max = max > hashTable.at(i).size() ? max : hashTable.at(i).size();
        if(hashTable.at(i).size() == 56){
            cout << 0 << endl; // artifact correction?
        }else{
//            cout << hashTable.at(i).size() << endl;
        }


    }


//    for(int i=0; i<pro.size(); i++){
//        cout << pro[i] << " ";
//    }
//

//    cout << endl << "count: " << insert << endl;
//
//    cout << endl << "total: " << total << endl;
    cout << endl << "max: " << max << endl;
    cout << endl << "bins: " << bins << endl;
    cout << endl;
}