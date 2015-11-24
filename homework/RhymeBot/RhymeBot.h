#ifndef UNTITLED_RHYMEBOT_H
#define UNTITLED_RHYMEBOT_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "Sound.h"

using namespace std;

enum PART_OF_SPEECH{
    ADJECTIVE, ADVERB, NOUN, SENSE, VERB
};

class RhymeBot {

private:
    // all the data structures you want to use

public:

    /** Inserting Words **/

    void insertWithPronunciation(string word, vector<Sound> pronunciation);
    void addPartOfSpeech(string word, PART_OF_SPEECH partOfSpeech);


    /** Helper Functions **/

    // returns the number of syllables in word
    int countSyllables(string word);

    // returns the number of rhyming syllables in the two words. This is defined as the number of vowel sounds in the
    //  largest rhyming suffix.
    //
    // Words are considered a rhyme if they have the same last vowel sound as well as the same sounds following
    //  the last vowel. Note: These are syllabic rhymes since the matching vowels might not both be stressed
    int rhymingSyllables(string word1, string word2);

    // returns the number of identical sounds in the largest matching prefix of the two words.
    //
    // Words are considered an alliteration if they have the same first sound
    int alliterationSounds(string word1, string word2);


    /** Search for Rhymes and Alliterations **/

    // returns all words that rhyme with the input word
    // returns the empty vector if no rhymes are found or if the given word is not in the dictionary
    vector<string>* getAllRhymes(string word);

    // returns all words that form alliterations with the input word
    // returns the empty vector if no rhymes are found or the given word is not known
    vector<string>* getAllAlliterations(string word);


    /** Finding the Perfect Word **/

    // returns the best word with the specified number of syllables and part of speech that rhymes with the given word.
    // Best is defined by the maximum number of rhyming syllables.
    string findBestRhyme(int numberOfSyllables, string rhymesWith);
    string findBestRhyme(PART_OF_SPEECH, string rhymesWith);
    string findBestRhyme(int numberOfSyllables, PART_OF_SPEECH, string rhymesWith);

    // returns the best word with the specified number of syllables and part of speech that forms an alliteration with
    // the given word. Best is defined by the number of maximum number of alliterating sounds.
    string findBestAlliteration(int numberOfSyllables, string alliterationWith);
    string findBestAlliteration(PART_OF_SPEECH, string alliterationWith);
    string findBestAlliteration(int numberOfSyllables, PART_OF_SPEECH, string alliterationWith);

    // Combine findBestRhyme and findBestAlliteration. Best is defined by the sum of the number of rhyming syllables
    //  and the number of alliterating sounds.
    string findPerfectWord(int numberOfSyllables, PART_OF_SPEECH, string rhymesWith, string alliterationWith);

};



#endif //UNTITLED_RHYMEBOT_H
