#include "Sound.h"

using namespace std;

map<string, Sound> Sound::knownSounds;

const Sound& Sound::getSound(string input){
    try {
        return Sound::knownSounds.at(input);
    } catch (out_of_range e) {
        cout << input << " is not a known sound\n";
        exit(0);
    }
}

const bool& Sound::isVowel() const {
    return vowel;
}

const string& Sound::getSourceString() const{
    return sourceString;
}

const string& Sound::getSoundSymbol() const {
    return soundSymbol;
}

const int& Sound::getVariationNumber() const {
    return variationNumber;
}

const string& Sound::getType() const {
    return type;
}

bool Sound::operator==(const Sound &that) const {
    return this->getSourceString() == that.getSourceString();
}

bool Sound::operator!=(const Sound &that) const {
    return !(*this == that);
}

Sound::Sound() { }


map<string, string> Sound::parseTypes() {
    string filename = "data/cmudict-0.7b.phones";
    ifstream dataFile;
    dataFile.open(filename);

    if (!dataFile.is_open()) {
        cout << "Could not open " << filename << "\n";
        exit(0);
    }

    map<string, string> types;

    string line;
    while (!dataFile.eof()) {
        getline(dataFile, line);
        if (line.length() != 0) {
            string phone = line.substr(0, line.find_first_of("\t"));
            string type = line.substr(line.find_last_of("\t") + 1);
            types.insert(make_pair(phone, type));
        }
    }

    dataFile.close();
    return types;
}


void Sound::init() {

    map <string, string> types = Sound::parseTypes();

    string symbolsFilename = "data/cmudict-0.7b.symbols";
    ifstream symbolsFile;
    symbolsFile.open(symbolsFilename);

    if (!symbolsFile.is_open()) {
        cout << "Could not open " << symbolsFilename << "\n";
        exit(0);
    }

    string symbol;
    while (!symbolsFile.eof()) {
        getline(symbolsFile, symbol);
        if (symbol.length() != 0) {
            Sound sound;
            sound.sourceString = symbol;

            int foundNumber = symbol.find_first_of("012");
            if(foundNumber != string::npos){
                sound.variationNumber = stoi(symbol.substr(foundNumber, foundNumber+1));
                symbol = symbol.substr(0,foundNumber);
            }else{
                sound.variationNumber = 0;
            }

            sound.soundSymbol = symbol;
            sound.type = types.at(symbol);
            sound.vowel = sound.getType() == "vowel";

            Sound::knownSounds.insert(make_pair(sound.getSourceString(), sound));
        }
    }

    symbolsFile.close();
}


ostream& operator<<(ostream& stream, const Sound& sound) {
    return stream << "(" << sound.getSoundSymbol() << "," << sound.getVariationNumber() << "," << sound.getType() << ")";
}