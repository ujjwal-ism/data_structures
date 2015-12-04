#ifndef UNTITLED_SOUND_H
#define UNTITLED_SOUND_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class Sound {

private:

    bool vowel;
    string sourceString; // ex: "IY1" "M" "UW2"
    string soundSymbol; // ex: "IY" "M" "UW"
    int variationNumber; // ex: 1 0 2     note: 0 for all non-vowels
    string type; // ex: "vowel" "stop" "fricative"

    Sound(); // private constructor

    static map<string, Sound> knownSounds;

    static map<string, string> parseTypes();

public:

    static const Sound& getSound(string);

    // These will be the most useful functions for RhymeBot
    const bool& isVowel() const;
    bool operator==(const Sound &that) const;
    bool operator!=(const Sound &that) const;

    // These functions can be used if needed
    const string& getSourceString() const;
    const string& getSoundSymbol() const;
    const int& getVariationNumber() const;
    const string& getType() const;


    static void init();
};


ostream& operator<<(ostream &stream, const Sound &sound);

#endif //UNTITLED_SOUND_H
