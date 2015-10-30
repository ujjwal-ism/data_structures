#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "HashTable.h"

using namespace std;


vector<string>* getAllWords(){
    vector<string>* allWords = new vector<string>;

    string filename = "data/cmudict-0.7b";
    ifstream dataFile;
    dataFile.open(filename);
    string line;

    while(getline(dataFile, line)) {
        string word = line.substr(0, line.find_first_of(" "));
        if (word == "") {
            continue;
        }
        allWords->push_back(word);
    }

    return allWords;
}

void insertAllWords(HashTable* hashTable, vector<string>* dictionary){

    for(vector<string>::const_iterator it = dictionary->begin();
        it < dictionary->end();
        it++){

        hashTable->insert(*it);

    }
}

void findAllWords(HashTable* hashTable, vector<string>* dictionary){

    for(vector<string>::const_iterator it = dictionary->begin();
        it < dictionary->end();
        it++){

        if(!hashTable->find(*it)){
            cout << "this word should have been found" << endl;
        }

    }
}

int main(){
    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    vector<string>* dictionary = getAllWords();

    startTime = clock();


    int n=150000;
    HashTable* hashTable = new BinarySearchVector();
//    HashTable* hashTable = new BinarySearchTree();
//    HashTable* hashTable = new CSEHashTable(n, modHash);
//    HashTable* hashTable = new FancyCSEHashTable(n, stdHash);


    insertAllWords(hashTable, dictionary);


    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms to populate\n";
    startTime = clock();


    findAllWords(hashTable, dictionary);


    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms to search\n";

    return 0;
}