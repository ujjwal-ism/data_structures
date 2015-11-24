#include <iostream>
#include "RhymeBot.h"
#include "FileParser.h"


using namespace std;

int main(){

    RhymeBot rhymeBot;

    Sound::init();

    string dictionaryFile = "data/cmudict-0.7b-onlyA"; // Testing dictionary. Contains only words that start with 'a'
//    string dictionaryFile = "data/cmudict-0.7b"; // Full dictionary

    pronunciationParser(rhymeBot, dictionaryFile);

    // Uncomment the following line when working on parts of speech
//    parseAllPartsOfSpeech(rhymeBot);

    string input;
    string option = "0";

    while(true){
        cout << "\nEnter a word: ";
        if(getline(cin,input)){
            while(option != "1" && option != "2") {
                cout << "\nEnter an Option\n" << "1-Rhymes\n" << "2-Allitertions\n";
                cout << ":";
                if (getline(cin, option)) {
                    if(option == "1"){
                        vector<string>* rhymes = rhymeBot.getAllRhymes(input);
                        cout << endl << input << " rhymes with:\n";
                        for(vector<string>::iterator it = rhymes->begin(); it != rhymes->end(); it++){
                            cout << *it << endl;
                        }
                        delete rhymes;
                    }else if(option == "2"){
                        vector<string>* alliterations = rhymeBot.getAllAlliterations(input);
                        cout << endl << input << " alliterations with:\n";
                        for(vector<string>::iterator it = alliterations->begin(); it != alliterations->end(); it++){
                            cout << *it << endl;
                        }
                        delete alliterations;
                    }else{
                        cout << "\ntry again";
                    }
                }
            }
        }
    }

    return 0;
}
