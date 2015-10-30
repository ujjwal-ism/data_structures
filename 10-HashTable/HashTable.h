#ifndef CSE250_FALL2015_HASHTABLE_H
#define CSE250_FALL2015_HASHTABLE_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <functional>

using namespace std;



int modHash(string input, int n){

    int hashValue = 0;

    for(int i=0; i<input.size(); i++){
        hashValue <<= 7;
        hashValue += (int)input.at(i);
    }

    hashValue = hashValue < 0 ? -hashValue : hashValue;
    return hashValue % n;
}




int sumHash(string input, int n){

    int hashValue = 0;

    for(int i=0; i<input.size(); i++){
        hashValue += (int)input.at(i);
    }

    hashValue = hashValue < 0 ? -hashValue : hashValue;
    return hashValue % n;
}




int xorHash(string input, int n){

    int hashValue = 0;

    for(int i=0; i<input.size(); i++){
        hashValue <<= 1;
        hashValue ^= (int)input.at(i);
    }

    hashValue = hashValue < 0 ? -hashValue : hashValue;
    return hashValue % n;
}




int stdHash(string input, int n){

    hash<string> hasher;
    int hashValue = hasher(input);

    hashValue = hashValue < 0 ? -hashValue : hashValue;
    return hashValue % n;
}



class HashTable {
public:
    virtual void insert(string) =0;
    virtual bool find(string) =0;

};




class BinarySearchVector : public HashTable {
private:
    vector<string> table;
    int numberOfBins;

public:

    BinarySearchVector(){}

    BinarySearchVector(int n){
        numberOfBins = n;
    }

    void insert(string toAdd){
        table.insert(upper_bound(table.begin(), table.end(), toAdd), toAdd);
    }

    bool find(string toFind){
        return binary_search(table.begin(), table.end(), toFind);
    }

};



class BinarySearchTree : public HashTable {
private:
    set<string> table;
    int numberOfBins;

public:

    BinarySearchTree(){}

    BinarySearchTree(int n){
        numberOfBins = n;
    }

    void insert(string toAdd){
        table.insert(toAdd);
    }

    bool find(string toFind){
        return table.find(toFind) != table.end();
    }

};





class CSEHashTable : public HashTable {
private:
    vector<vector<string> > table;
    int numberOfBins;
    int (*hashFunction)(string input,int bins);

public:

    CSEHashTable(int n, int inputHashFunction(string,int)){
        table.resize(n);
        numberOfBins = n;
        hashFunction = inputHashFunction;
    }

    void insert(string toAdd){
        table.at(hashFunction(toAdd, numberOfBins)).push_back(toAdd);
    };

    bool find(string toFind){
        vector<string> thisBin = table.at(hashFunction(toFind, numberOfBins));

        int binSize = thisBin.size();
        for (int i = 0; i < binSize; i++) {
            if (thisBin.at(i) == toFind) {
                return true;
            }
        }
        return false;
    }

};



class FancyCSEHashTable : public HashTable {
private:
    vector<BinarySearchVector> table;
    int numberOfBins;
    int (*hashFunction)(string input,int bins);

public:

    FancyCSEHashTable(int n, int inputHashFunction(string,int)){
        table.resize(n);
        numberOfBins = n;
        hashFunction = inputHashFunction;
    }

    void insert(string toAdd){
        table.at(hashFunction(toAdd, numberOfBins)).insert(toAdd);
    };

    bool find(string toFind){
        return table.at(hashFunction(toFind, numberOfBins)).find(toFind);
    }

};


#endif //CSE250_FALL2015_HASHTABLE_H
