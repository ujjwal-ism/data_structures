#include "RhymeBot.h"


/** Inserting Words **/

void RhymeBot::insertWithPronunciation(string word, vector<Sound> pronunciation){
    // TODO

    // The following lines should be removed. They are here to show what is being added to you data structures
    cout << word << ": ";
    for(int i=0; i<pronunciation.size(); i++){
        cout << pronunciation.at(i) << " ";
    }
    cout << endl;

}

void RhymeBot::addPartOfSpeech(string word, PART_OF_SPEECH partOfSpeech){
    // TODO

    // The following line should be removed. They are here to show what is being added to you data structures
    cout << word << ": " << partOfSpeech << endl;

}


/** Helper Functions **/

// returns the number of syllables in word
int RhymeBot::countSyllables(string word){
    // TODO
    return 0;
}

// returns the number of rhyming syllables in the two words. This is defined as the number of vowel sounds in the
//  largest rhyming suffix.
//
// Words are considered a rhyme if they have the same last vowel sound as well as the same sounds following
//  the last vowel. Note: These are syllabic rhymes since the matching vowels might not both be stressed
int RhymeBot::rhymingSyllables(string word1, string word2){
    // TODO
    return 0;
}

// returns the number of identical sounds in the largest matching prefix of the two words.
//
// Words are considered an alliteration if they have the same first sound
int RhymeBot::alliterationSounds(string word1, string word2){
    // TODO
    return 0;
}


/** Search for Rhymes and Alliterations **/

// returns all words that rhyme at least 1 syllable with the input word
// returns the empty vector if no rhymes are found or if the given word is not in the dictionary
vector<string>* RhymeBot::getAllRhymes(string word){
    vector<string>* rhymingWords = new vector<string>;
    // TODO
    return rhymingWords;
}

// returns all words that form an alliteration of at least 1 sound with the input word
// returns the empty vector if no rhymes are found or the given word is not known
vector<string>* RhymeBot::getAllAlliterations(string word){
    vector<string>* alliterationWords = new vector<string>;
    // TODO
    return alliterationWords;
}


/** Finding the Perfect Word **/

// returns the best word with the specified number of syllables and part of speech that rhymes with the given word.
// Best is defined by the maximum number of rhyming syllables.
string RhymeBot::findBestRhyme(int numberOfSyllables, string rhymesWith){
    // TODO
    return "";
}
string RhymeBot::findBestRhyme(PART_OF_SPEECH, string rhymesWith){
    // TODO
    return "";
}
string RhymeBot::findBestRhyme(int numberOfSyllables, PART_OF_SPEECH, string rhymesWith){
    // TODO
    return "";
}

// returns the best word with the specified number of syllables and part of speech that forms an alliteration with
// the given word. Best is defined by the number of maximum number of alliterating sounds.
string RhymeBot::findBestAlliteration(int numberOfSyllables, string alliterationWith){
    // TODO
    return "";
}
string RhymeBot::findBestAlliteration(PART_OF_SPEECH, string alliterationWith){
    // TODO
    return "";
}
string RhymeBot::findBestAlliteration(int numberOfSyllables, PART_OF_SPEECH, string alliterationWith){
    // TODO
    return "";
}

// Combine findBestRhyme and findBestAlliteration. Best is defined by the sum of the number of rhyming syllables
//  and the number of alliterating sounds.
string RhymeBot::findPerfectWord(int numberOfSyllables, PART_OF_SPEECH, string rhymesWith, string alliterationWith){
    // TODO
    return "";
}