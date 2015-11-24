#ifndef UNTITLED_SOUND_H
#define UNTITLED_SOUND_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

enum VOWEL_SOUND {
    AA,AE,AH,AO,AW,AY,EH,ER,EY,IH,IY,OW,OY,UH,UW
};

enum SOUNDS{
    B,CH,D,DH,F,G,HH,JH,K,L,M,N,NG,P,R,S,SH,T,TH,V,W,Y,Z,ZH
};


class Sound {

    friend class SoundFactory;

private:
    bool vowel;
    string sound;
    int pronunciationNumber; // 0 for non-vowels

public:

    Sound(string);
    bool isVowel();
    string getSound();
    int getPronunciationNumber();
};


class SoundFactory{
private:
    set<string> vowelSounds;
    set<string> nonVowelSounds;

//    bool isVowel(string);
//    bool isNonVowel(string);

public:

    SoundFactory();
    void init();

    static Sound makeSound(string);

};



#endif //UNTITLED_SOUND_H