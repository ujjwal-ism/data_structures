#include "VectorExamples.h"

using namespace std;


void checkCapacity(){
    vector<string> strings;
    printSizeCapacity(strings);

    for(int i=0; i<25; i++) {
        strings.push_back("string");
        printSizeCapacity(strings);
    }

    printVector(strings);
}

void checkWithInitialCapacity(){

    vector<string> withInitialCapacity(100);
    printSizeCapacity(withInitialCapacity);

    for(int i=0; i<102; i++) {
        withInitialCapacity.push_back("string");
        if(i>97){
            printSizeCapacity(withInitialCapacity);
        }
    }
//    withInitialCapacity[30] = "where am I?";
    printVector(withInitialCapacity);

}


void printSizeCapacity(const vector<string>& values){
    cout << "size: " << values.size();
    if(values.size()/10 == 0){cout << ' ';}
    cout << " | capacity: " << values.capacity() << endl;
}


void movingStrings(){

    vector<string> strings;

    strings.push_back("going");
    strings.push_back("out");
    strings.push_back("talk");
    strings.insert(strings.begin(), "after");
    strings.push_back("given");
    strings.push_back("someone");

//    printVector(strings);

    reverse(strings.begin(), strings.end());

//    printVector(strings);

    vector<string> moreStrings;
    moreStrings.push_back("on");
    moreStrings.push_back("talk");
    moreStrings.push_back("let");
    moreStrings.push_back("don't");
    moreStrings.push_back("yours");

//    printVector(moreStrings);

    sort(moreStrings.begin(), moreStrings.end());

//    printVector(moreStrings);

    strings.insert(strings.end(), moreStrings.begin(), moreStrings.end());

//    printVector(strings);

    strings.erase(strings.begin()+2);

//    printVector(strings);

    swap(strings[0], strings[5]);
    swap(strings[1], strings[6]);
    swap(strings[2], strings[5]);

//    printVector(strings);

    strings.insert(strings.begin()+3, "who");
    swap(strings[4], strings[7]);
    swap(strings[5], strings[8]);
    swap(strings[6], strings[9]);
    swap(strings[7], strings[9]);
    swap(*(strings.end()-2), *(strings.end()-3));

//    printVector(strings);

    strings.insert(strings.begin()+4, "has");
    strings.insert(strings.begin()+6, "up");

//    printVector(strings);

    string words[2];
    words[1] = "dreams";
    words[0] = "their";
    strings.insert(strings.begin()+8, words, words+2);

//    printVector(strings);

    strings.insert(strings.end()-3, "of");
    strings.insert(strings.end()-5, "you");
    (strings.end()-1)->push_back('.');

    char mysteryChar = 45;
    string u = "unknown";
    u.insert(u.begin(), mysteryChar);
    strings.push_back(u);


//    printVector(strings);

}

void printVector(const vector<string>& values){
    for(int i=0; i<values.size(); i++){
        cout << values[i] << " ";
    }
    cout << endl;
}