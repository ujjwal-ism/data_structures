#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include "RhymeBot.h"
#include "FileParser.h"

using namespace std;

string getSpeech(int input);

/////////

bool countSyllablesCase(string word, int expected, RhymeBot& rhymeBot){
    int computed = rhymeBot.countSyllables(word);
    if(computed != expected){
        cout << "Computed \"" << word << "\" to have " << computed << " syllables" << endl;
        cout << "Expected: " << expected << endl;
        return false;
    }
    return true;
}

int countSyllablesTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    testPassed &= countSyllablesCase("word", 1, rhymeBot);
    testPassed &= countSyllablesCase("credibility", 5, rhymeBot);
    testPassed &= countSyllablesCase("sonnenschein", 3, rhymeBot);
    testPassed &= countSyllablesCase("mahone", 2, rhymeBot);
    testPassed &= countSyllablesCase("sera", 2, rhymeBot);
    testPassed &= countSyllablesCase("rance", 1, rhymeBot);
    testPassed &= countSyllablesCase("lueck", 2, rhymeBot);
    testPassed &= countSyllablesCase("mattucci", 3, rhymeBot);
    testPassed &= countSyllablesCase("pertamina", 4, rhymeBot);
    testPassed &= countSyllablesCase("lomax", 2, rhymeBot);
    testPassed &= countSyllablesCase("editorializing", 7, rhymeBot);
    testPassed &= countSyllablesCase("carmouche", 2, rhymeBot);
    testPassed &= countSyllablesCase("inquiry", 3, rhymeBot);
    testPassed &= countSyllablesCase("capitalize", 4, rhymeBot);
    testPassed &= countSyllablesCase("undeserving", 4, rhymeBot);
    testPassed &= countSyllablesCase("unadulterated", 6, rhymeBot);
    testPassed &= countSyllablesCase("spam", 1, rhymeBot);
    testPassed &= countSyllablesCase("selenite", 3, rhymeBot);
    testPassed &= countSyllablesCase("christening", 3, rhymeBot);
    testPassed &= countSyllablesCase("compaq's", 2, rhymeBot);
    testPassed &= countSyllablesCase("seabrooks", 2, rhymeBot);
    testPassed &= countSyllablesCase("furiously", 4, rhymeBot);
    testPassed &= countSyllablesCase("ilalis", 3, rhymeBot);

    if(testPassed){
        cout << "passed count syllables test" << endl;
    }

    return testPassed ? 10 : 0;
}

/////////

bool rhymingSyllablesCase(string word1, string word2, int expected, RhymeBot& rhymeBot){
    int computed = rhymeBot.rhymingSyllables(word1,word2);
    if(computed != expected){
        cout << "Computed \'" << word1 << "\" and \"" << word2 << "\" to rhyme " << computed << " syllables" << endl;
        cout << "Expected: " << expected << endl;
        return false;
    }
    return true;
}

int rhymingSyllablesTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    testPassed &= rhymingSyllablesCase("bleeker", "gruff", 0, rhymeBot);
    testPassed &= rhymingSyllablesCase("eidson", "sled", 0, rhymeBot);
    testPassed &= rhymingSyllablesCase("sugared", "thrift", 0, rhymeBot);
    testPassed &= rhymingSyllablesCase("grandiloquent", "zouabri", 0, rhymeBot);
    testPassed &= rhymingSyllablesCase("clipping", "palm-springs", 0, rhymeBot);
    testPassed &= rhymingSyllablesCase("word","absurd", 1, rhymeBot);
    testPassed &= rhymingSyllablesCase("sparling", "raising", 1, rhymeBot);
    testPassed &= rhymingSyllablesCase("exploration", "misidentification", 2, rhymeBot);
    testPassed &= rhymingSyllablesCase("patterson", "zeman", 1, rhymeBot);
    testPassed &= rhymingSyllablesCase("dokken", "hillson", 1, rhymeBot);
    testPassed &= rhymingSyllablesCase("possessive", "tentative", 1, rhymeBot);
    testPassed &= rhymingSyllablesCase("meteorology", "psychology", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("fischel", "judicial", 2, rhymeBot);
    testPassed &= rhymingSyllablesCase("gamello", "celo", 2, rhymeBot);
    testPassed &= rhymingSyllablesCase("explainable", "unsustainable", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("mesmerizing", "pasteurizing", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("vulgarity", "insularity", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("repository", "investigatory", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("ophthalmology", "scientology", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("toxicological", "pedagogical", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("expansionism", "organism", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("availability", "malleability", 4, rhymeBot);
    testPassed &= rhymingSyllablesCase("cobler", "dobler", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("impressively", "aggressively", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("accelerometer", "odometer", 3, rhymeBot);
    testPassed &= rhymingSyllablesCase("regulation", "deregulation", 4, rhymeBot);
    testPassed &= rhymingSyllablesCase("capability", "irritability", 4, rhymeBot);



    if(testPassed){
        cout << "passed rhyming syllables test" << endl;
    }

    return testPassed ? 10 : 0;
}

/////////

bool alliterationSoundsCase(string word1, string word2, int expected, RhymeBot& rhymeBot){
    int computed = rhymeBot.alliterationSounds(word1,word2);
    if(computed != expected){
        cout << "Computed \'" << word1 << "\" and \"" << word2 << "\" to alliterate " << computed << " sounds" << endl;
        cout << "Expected: " << expected << endl;
        return false;
    }
    return true;
}

int alliterationSoundsTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    testPassed &= alliterationSoundsCase("salvation", "ghostly", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("striving", "preserves", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("birds", "kwik", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("medlin", "bringing", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("guglielmo", "morrow", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("folktale", "selection", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("breadbox", "cosic", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("zimdars", "paced", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("inconstancy", "mertes", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("trudge", "detrimental", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("marchesani", "turbo", 0, rhymeBot);
    testPassed &= alliterationSoundsCase("kerlin", "connect", 1, rhymeBot);
    testPassed &= alliterationSoundsCase("filling", "falsehoods", 1, rhymeBot);
    testPassed &= alliterationSoundsCase("pillaging", "pechacek", 1, rhymeBot);
    testPassed &= alliterationSoundsCase("sixths", "cilag", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("houle", "houze", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("incur", "incurable", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("products'", "predicate", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("styled", "stricklen", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("unreliable", "unimagined", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("camshaft", "cabinetry", 2, rhymeBot);
    testPassed &= alliterationSoundsCase("dismantle", "disbanded", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("harbors", "harmon", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("sensed", "sentell", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("cort", "coroners", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("gravley", "graffam", 3, rhymeBot);
    testPassed &= alliterationSoundsCase("haimovitch", "heyman", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("bilicki", "bielinski", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("kammerzell", "camerer", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("stancliff", "standards", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("microcircuit", "micron", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("prizant", "prison's", 4, rhymeBot);
    testPassed &= alliterationSoundsCase("censer", "sensors", 5, rhymeBot);
    testPassed &= alliterationSoundsCase("cycle", "cyclists", 5, rhymeBot);
    testPassed &= alliterationSoundsCase("rosendale", "rosengren", 5, rhymeBot);
    testPassed &= alliterationSoundsCase("invesco", "investor's", 5, rhymeBot);
    testPassed &= alliterationSoundsCase("tumbling", "tumbles", 6, rhymeBot);
    testPassed &= alliterationSoundsCase("kristallnacht", "christon", 6, rhymeBot);
    testPassed &= alliterationSoundsCase("salesmanship", "salesman's", 7, rhymeBot);
    testPassed &= alliterationSoundsCase("marginalize", "marginally", 8, rhymeBot);
    testPassed &= alliterationSoundsCase("procrastinate", "procrastinating", 12, rhymeBot);


    if(testPassed){
        cout << "passed alliteration sounds test" << endl;
    }

    return testPassed ? 10 : 0;
}

/////////

bool allRhymesCase(string word, unordered_set<string>& expected, RhymeBot &rhymeBot) {
    vector<string>* computed = rhymeBot.getAllRhymes(word);
    bool result = true;
    for(vector<string>::iterator it = computed->begin(); it != computed->end(); it++){
        if(*it != word && expected.count(*it) == 0){
            cout << "\"" << word << "\" does not rhymes with \"" << *it;
            cout << "\" which was returned by getAllRhymes(\"" << word << "\")" << endl;
            result = false;
        }
    }

    sort(computed->begin(), computed->end());

    for(unordered_set<string>::iterator it = expected.begin(); it != expected.end(); it++){
        if(*it != word && !binary_search(computed->begin(),computed->end(),*it)){
            cout << "\"" << word << "\" rhymes with \"" << *it;
            cout << "\" which was not returned by getAllRhymes(\"" << word << "\")" << endl;
            result = false;
        }
    }


    return result;
}

int allRhymesTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    unordered_set<string> expected;
    string word;

    word = "dower";
    expected.insert("blauer");
    expected.insert("bour");
    expected.insert("dessauer");
    expected.insert("krauer");
    expected.insert("lour");
    expected.insert("n'dour");
    testPassed &= allRhymesCase(word, expected, rhymeBot);

    expected.clear();
    word = "conflicts";
    expected.insert("addicts");
    expected.insert("afflicts");
    expected.insert("contradicts");
    expected.insert("depicts");
    expected.insert("inflicts");
    expected.insert("picts");
    expected.insert("predicts");
    expected.insert("restricts");
    expected.insert("richts");
    testPassed &= allRhymesCase(word, expected, rhymeBot);

    expected.clear();
    word = "defunct";
    expected.insert("debunked");
    expected.insert("dunked");
    expected.insert("flunked");
    expected.insert("junked");
    expected.insert("plunked");
    expected.insert("spelunked");
    testPassed &= allRhymesCase(word, expected, rhymeBot);

    expected.clear();
    word = "dog's";
    expected.insert("blogs");
    expected.insert("boggs");
    expected.insert("dogs'");
    expected.insert("fogs");
    expected.insert("logs");
    testPassed &= allRhymesCase(word, expected, rhymeBot);

    expected.clear();
    word = "nerds";
    expected.insert("bird's");
    expected.insert("birds");
    expected.insert("birds'");
    expected.insert("byrd's");
    expected.insert("gerdes");
    expected.insert("gerdes'");
    expected.insert("girds");
    expected.insert("herds");
    expected.insert("kurds");
    expected.insert("n_words");
    expected.insert("third's");
    expected.insert("thirds");
    expected.insert("two-thirds");
    expected.insert("twothirds");
    expected.insert("word's");
    expected.insert("words");
    expected.insert("words'");
    testPassed &= allRhymesCase(word, expected, rhymeBot);

    if(testPassed){
        cout << "passed all rhymes test" << endl;
    }

    return testPassed ? 15 : 0;
}

/////////

bool allAlliterationsCase(string word, unordered_set<string>& expected, RhymeBot &rhymeBot) {
    vector<string>* computed = rhymeBot.getAllAlliterations(word);
    bool result = true;
    for(vector<string>::iterator it = computed->begin(); it != computed->end(); it++){
        if(*it != word && expected.count(*it) == 0){
            cout << "\"" << word << "\" does not alliterate with \"" << *it;
            cout << "\" which was returned by getAllAlliterations(\"" << word << "\")" << endl;
            result = false;
        }
    }

    sort(computed->begin(), computed->end());

    for(unordered_set<string>::iterator it = expected.begin(); it != expected.end(); it++){
        if(*it != word && !binary_search(computed->begin(),computed->end(), *it)){
            cout << "\"" << word << "\" alliterates with \"" << *it;
            cout << "\" which was not returned by getAllAlliterations(\"" << word << "\")" << endl;
            result = false;
        }
    }


    return result;
}

int allAlliterationsTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    unordered_set<string> expected;
    string word;

    word = "ourso";
    expected.insert("earl");
    expected.insert("earl's");
    expected.insert("earldom");
    expected.insert("earle");
    expected.insert("earlene");
    expected.insert("earles");
    expected.insert("earley");
    expected.insert("earlie");
    expected.insert("earlier");
    expected.insert("earlier's");
    expected.insert("earliest");
    expected.insert("earline");
    expected.insert("earll");
    expected.insert("earls");
    expected.insert("early");
    expected.insert("earlywine");
    expected.insert("earn");
    expected.insert("earned");
    expected.insert("earner");
    expected.insert("earners");
    expected.insert("earnest");
    expected.insert("earnestly");
    expected.insert("earnestness");
    expected.insert("earney");
    expected.insert("earnhardt");
    expected.insert("earnhart");
    expected.insert("earnheart");
    expected.insert("earning");
    expected.insert("earnings");
    expected.insert("earnings'");
    expected.insert("earns");
    expected.insert("earnshaw");
    expected.insert("earp");
    expected.insert("earth");
    expected.insert("earth's");
    expected.insert("earth-like");
    expected.insert("eartha");
    expected.insert("earthbound");
    expected.insert("earthen");
    expected.insert("earthenware");
    expected.insert("earthling");
    expected.insert("earthlings");
    expected.insert("earthly");
    expected.insert("earthmoving");
    expected.insert("earthquake");
    expected.insert("earthquake's");
    expected.insert("earthquakes");
    expected.insert("earths");
    expected.insert("earthshaking");
    expected.insert("earthshine");
    expected.insert("earthstar");
    expected.insert("earthwork");
    expected.insert("earthworm");
    expected.insert("earthworms");
    expected.insert("earthy");
    expected.insert("earvin");
    expected.insert("ehrlich");
    expected.insert("ehrlich's");
    expected.insert("ehrlichman");
    expected.insert("erb");
    expected.insert("erbacher");
    expected.insert("erbamont");
    expected.insert("erbamont's");
    expected.insert("erbe");
    expected.insert("erber");
    expected.insert("erbes");
    expected.insert("erby");
    expected.insert("erceg");
    expected.insert("erck");
    expected.insert("ercros");
    expected.insert("erdahl");
    expected.insert("erdman");
    expected.insert("erdmann");
    expected.insert("erdos");
    expected.insert("erdrich");
    expected.insert("ergle");
    expected.insert("ergo");
    expected.insert("ergot");
    expected.insert("ergot's");
    expected.insert("ergotism");
    expected.insert("ergots");
    expected.insert("erhardt");
    expected.insert("erhart");
    expected.insert("erk");
    expected.insert("erker");
    expected.insert("erkkila");
    expected.insert("erl");
    expected.insert("erlach");
    expected.insert("erland");
    expected.insert("erlandson");
    expected.insert("erlene");
    expected.insert("erler");
    expected.insert("erlich");
    expected.insert("erlichman");
    expected.insert("erlick");
    expected.insert("erline");
    expected.insert("erling");
    expected.insert("erly");
    expected.insert("erma");
    expected.insert("erma's");
    expected.insert("erman");
    expected.insert("ermer");
    expected.insert("ermin");
    expected.insert("ermine");
    expected.insert("erminie");
    expected.insert("ermis");
    expected.insert("erna");
    expected.insert("ernaline");
    expected.insert("erne");
    expected.insert("ernest");
    expected.insert("ernest's");
    expected.insert("ernestine");
    expected.insert("ernests");
    expected.insert("erney");
    expected.insert("ernie");
    expected.insert("ernsberger");
    expected.insert("ernst");
    expected.insert("ernster");
    expected.insert("erny");
    expected.insert("erpelding");
    expected.insert("erps");
    expected.insert("ers");
    expected.insert("ershad");
    expected.insert("erskin");
    expected.insert("erskine");
    expected.insert("erstwhile");
    expected.insert("erte");
    expected.insert("ertel");
    expected.insert("ertha");
    expected.insert("ertl");
    expected.insert("ertle");
    expected.insert("ertman");
    expected.insert("ertz");
    expected.insert("erven");
    expected.insert("ervin");
    expected.insert("erving");
    expected.insert("erway");
    expected.insert("erwin");
    expected.insert("eure");
    expected.insert("herb");
    expected.insert("herb's");
    expected.insert("herbal");
    expected.insert("herbalife");
    expected.insert("herbalist");
    expected.insert("herbalist's");
    expected.insert("herbalists");
    expected.insert("herbalists'");
    expected.insert("herbicides");
    expected.insert("herbs");
    expected.insert("irby");
    expected.insert("irk");
    expected.insert("irked");
    expected.insert("irks");
    expected.insert("irksome");
    expected.insert("irlbeck");
    expected.insert("irma");
    expected.insert("irma's");
    expected.insert("irv");
    expected.insert("irve");
    expected.insert("irvin");
    expected.insert("irvine");
    expected.insert("irving");
    expected.insert("irving's");
    expected.insert("irwin");
    expected.insert("irwindale");
    expected.insert("ur");
    expected.insert("urbach");
    expected.insert("urban");
    expected.insert("urban's");
    expected.insert("urbanism");
    expected.insert("urbanite");
    expected.insert("urbanites");
    expected.insert("urbanize");
    expected.insert("urbanized");
    expected.insert("urbas");
    expected.insert("urchin");
    expected.insert("urchins");
    expected.insert("urda");
    expected.insert("urdiales");
    expected.insert("urfer");
    expected.insert("urge");
    expected.insert("urged");
    expected.insert("urgen");
    expected.insert("urgen's");
    expected.insert("urgency");
    expected.insert("urgent");
    expected.insert("urgently");
    expected.insert("urges");
    expected.insert("urging");
    expected.insert("urgings");
    expected.insert("urgo");
    expected.insert("urkel");
    expected.insert("urman");
    expected.insert("urn");
    expected.insert("urness");
    expected.insert("urquhart");
    expected.insert("ursa");
    expected.insert("urschel");
    expected.insert("ursery");
    expected.insert("ursie");
    expected.insert("ursin");
    expected.insert("urso");
    expected.insert("urson");
    expected.insert("urstadt");
    expected.insert("ursula");
    expected.insert("ursus");
    expected.insert("ursy");
    expected.insert("urton");
    expected.insert("urwin");
    testPassed &= allAlliterationsCase(word, expected, rhymeBot);

    if(testPassed){
        cout << "passed all alliteration test" << endl;
    }

    return testPassed ? 15 : 0;
}

/////////


bool bestRhymesCaseSyllables(string word, int syllables, unordered_set<string>& expected, RhymeBot &rhymeBot) {
    string computed = rhymeBot.findBestRhyme(syllables, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best rhyme for \"" << word;
        cout << "\" with " << syllables << " syllables" << endl;
        result = false;
    }
    return result;
}

bool bestRhymesCaseSpeech(string word, PART_OF_SPEECH partOfSpeech,
                          unordered_set<string>& expected, RhymeBot &rhymeBot) {

    string computed = rhymeBot.findBestRhyme(partOfSpeech, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best rhyming " << getSpeech(partOfSpeech) << " for \"" << word << "\"" << endl;
        result = false;
    }
    return result;
}

bool bestRhymesCaseCombined(string word, int syllables, PART_OF_SPEECH partOfSpeech, unordered_set<string>& expected, RhymeBot &rhymeBot) {

    string computed = rhymeBot.findBestRhyme(syllables, partOfSpeech, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best rhyming " << getSpeech(partOfSpeech) << " for \"" << word;
        cout << "\" with " << syllables << " syllables" << endl;
        result = false;
    }
    return result;
}

int bestRhymeTest(RhymeBot& rhymeBot){
    bool syllablesTestPassed = true;
    bool speechTestPassed = true;
    bool combinedTestPassed = true;

//    testPassed &= Case("word","absurd", 1, rhymeBot);
    string word;
    int syllables;
    PART_OF_SPEECH partOfSpeech;
    unordered_set<string> expectedSyllables;
    unordered_set<string> expectedSpeech;
    unordered_set<string> expectedCombined;

    word = "alabama";
    syllables = 2;
    partOfSpeech = VERB;
    expectedSyllables.insert("gamma");
    expectedSyllables.insert("grama");
    expectedSyllables.insert("jama");
    expectedSpeech.insert("concertina");
    expectedSpeech.insert("conga");
    expectedSpeech.insert("henna");
    expectedSpeech.insert("samba");
    expectedSpeech.insert("subpoena");
    expectedSpeech.insert("visa");
    expectedCombined.insert("conga");
    expectedCombined.insert("henna");
    expectedCombined.insert("samba");
    expectedCombined.insert("visa");

    syllablesTestPassed &= bestRhymesCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestRhymesCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestRhymesCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);

    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "alabama";
    syllables = 2;
    partOfSpeech = ADVERB;
    expectedSyllables.insert("gamma");
    expectedSyllables.insert("grama");
    expectedSyllables.insert("jama");
    expectedSpeech.insert("asea");
    expectedSpeech.insert("infra");
    expectedSpeech.insert("kinda");
    expectedSpeech.insert("supra");
    expectedCombined.insert("infra");
    expectedCombined.insert("kinda");
    expectedCombined.insert("supra");

    syllablesTestPassed &= bestRhymesCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestRhymesCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestRhymesCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);


    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "speculated";
    syllables = 3;
    partOfSpeech = VERB;
    expectedSyllables.insert("donated");
    expectedSyllables.insert("frustrated");
    expectedSyllables.insert("hydrated");
    expectedSyllables.insert("located");
    expectedSpeech.insert("invalid");
    expectedCombined.insert("invalid");

    syllablesTestPassed &= bestRhymesCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestRhymesCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestRhymesCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);

    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "mckittrick";
    syllables = 2;
    partOfSpeech = ADJECTIVE;
    expectedSyllables.insert("citric");
    expectedSyllables.insert("dittrich");
    expectedSyllables.insert("sitrick");
    expectedSyllables.insert("vitric");
    expectedSpeech.insert("citric");
    expectedCombined.insert("citric");


    syllablesTestPassed &= bestRhymesCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestRhymesCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestRhymesCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);


    if(syllablesTestPassed && speechTestPassed && combinedTestPassed){
        cout << "passed best rhyme tests" << endl;
    }

    int result = 0;
    result += syllablesTestPassed ? 3 : 0;
    result += speechTestPassed ? 3 : 0;
    result += combinedTestPassed ? 4 : 0;
    return result;
}

/////////


bool bestAlliterationCaseSyllables(string word, int syllables, unordered_set<string>& expected, RhymeBot &rhymeBot) {
    string computed = rhymeBot.findBestAlliteration(syllables, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best alliteration for \"" << word;
        cout << "\" with " << syllables << " syllables" << endl;
        result = false;
    }
    return result;
}

bool bestAlliterationCaseSpeech(string word, PART_OF_SPEECH partOfSpeech,
                                unordered_set<string>& expected, RhymeBot &rhymeBot) {

    string computed = rhymeBot.findBestAlliteration(partOfSpeech, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best alliterating " << getSpeech(partOfSpeech) << " for \"" << word << "\"" << endl;
        result = false;
    }
    return result;
}

bool bestAlliterationCaseCombined(string word, int syllables, PART_OF_SPEECH partOfSpeech,
                                  unordered_set<string>& expected, RhymeBot &rhymeBot) {

    string computed = rhymeBot.findBestAlliteration(syllables, partOfSpeech, word);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not the best alliterating " << getSpeech(partOfSpeech) << " for \"" << word;
        cout << "\" with " << syllables << " syllables" << endl;
        result = false;
    }
    return result;
}

int bestAlliterationTest(RhymeBot& rhymeBot){
    bool syllablesTestPassed = true;
    bool speechTestPassed = true;
    bool combinedTestPassed = true;

    string word;
    int syllables;
    PART_OF_SPEECH partOfSpeech;
    unordered_set<string> expectedSyllables;
    unordered_set<string> expectedSpeech;
    unordered_set<string> expectedCombined;

    word = "bastow";
    syllables = 1;
    partOfSpeech = VERB;
    expectedSyllables.insert("bast");
    expectedSpeech.insert("bask");
    expectedSpeech.insert("basset");
    expectedCombined.insert("bask");

    syllablesTestPassed &= bestAlliterationCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestAlliterationCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestAlliterationCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);

    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "bastow";
    syllables = 1;
    partOfSpeech = ADVERB;
    expectedSyllables.insert("bast");
    expectedSpeech.insert("backward");
    expectedSpeech.insert("backwards");
    expectedSpeech.insert("badly");
    expectedCombined.insert("big");
    expectedCombined.insert("bright");
    expectedCombined.insert("but");
    expectedCombined.insert("by");

    syllablesTestPassed &= bestAlliterationCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestAlliterationCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestAlliterationCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);


    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "siskind";
    syllables = 1;
    partOfSpeech = NOUN;
    expectedSyllables.insert("sisk");
    expectedSpeech.insert("siskin");
    expectedCombined.insert("cyst");
    expectedCombined.insert("sis");

    syllablesTestPassed &= bestAlliterationCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestAlliterationCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestAlliterationCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);

    expectedSyllables.clear();
    expectedSpeech.clear();
    expectedCombined.clear();

    word = "barlettesville";
    syllables = 2;
    partOfSpeech = ADJECTIVE;
    expectedSyllables.insert("barlage");
    expectedSyllables.insert("barlett");
    expectedSyllables.insert("barley");
    expectedSyllables.insert("barlow");
    expectedSyllables.insert("barlowe");
    expectedSpeech.insert("barbarous");
    expectedSpeech.insert("barbecued");
    expectedSpeech.insert("barbed");
    expectedSpeech.insert("barred");
    expectedCombined.insert("balmy");
    expectedCombined.insert("bodied");
    expectedCombined.insert("bonkers");
    expectedCombined.insert("bonnie");
    expectedCombined.insert("bonny");
    expectedCombined.insert("bothered");
    expectedCombined.insert("bottomed");
    expectedCombined.insert("boxy");


    syllablesTestPassed &= bestAlliterationCaseSyllables(word, syllables, expectedSyllables, rhymeBot);
    speechTestPassed &= bestAlliterationCaseSpeech(word, partOfSpeech, expectedSyllables, rhymeBot);
    combinedTestPassed &= bestAlliterationCaseCombined(word, syllables, partOfSpeech, expectedSyllables, rhymeBot);


    if(syllablesTestPassed && speechTestPassed && combinedTestPassed){
        cout << "passed best alliteration tests" << endl;
    }

    int result = 0;
    result += syllablesTestPassed ? 3 : 0;
    result += speechTestPassed ? 3 : 0;
    result += combinedTestPassed ? 4 : 0;
    return result;
}

/////////

bool perfectWordCase(string rhymeWord, string alliterateWord, int syllables, PART_OF_SPEECH partOfSpeech,
                                   unordered_set<string>& expected, RhymeBot &rhymeBot) {

    string computed = rhymeBot.findPerfectWord(syllables, partOfSpeech, rhymeWord, alliterateWord);
    bool result = true;
    if(expected.count(computed) == 0){
        cout << "\"" << computed << "\" is not a perfect " << getSpeech(partOfSpeech) << " rhyming with \"" << rhymeWord;
        cout << "\" and alliterting with \"" << alliterateWord << "\" with " <<  syllables << " syllables" << endl;
        result = false;
    }
    return result;
}


int perfectWordTest(RhymeBot& rhymeBot){
    bool testPassed = true;

    string rhymeWord;
    string alliterateWord;
    int syllables;
    PART_OF_SPEECH partOfSpeech;
    unordered_set<string> expected;

    rhymeWord = "rogalski";
    alliterateWord = "kacer";
    syllables = 2;
    partOfSpeech = VERB;
    expected.insert("caddy");
    expected.insert("candy");
    expected.insert("carry");
    expected.insert("colly");
    expected.insert("copy");
    expected.insert("curry");
    expected.insert("curtsy");
    expected.insert("quarry");
    expected.insert("query");


    testPassed &= perfectWordCase(rhymeWord, alliterateWord, syllables, partOfSpeech, expected, rhymeBot);

    expected.clear();

    rhymeWord = "malinski";
    alliterateWord = "liggins";
    syllables = 2;
    partOfSpeech = ADVERB;
    expected.insert("lamely");
    expected.insert("largely");
    expected.insert("lastly");
    expected.insert("lately");
    expected.insert("lightly");
    expected.insert("likely");
    expected.insert("loosely");
    expected.insert("loudly");

    testPassed &= perfectWordCase(rhymeWord, alliterateWord, syllables, partOfSpeech, expected, rhymeBot);

    expected.clear();


    rhymeWord = "redundancy";
    alliterateWord = "spasmodic";
    syllables = 2;
    partOfSpeech = ADJECTIVE;
    expected.insert("spacey");
    expected.insert("sparkly");
    expected.insert("spicy");
    expected.insert("spiffy");
    expected.insert("spiky");
    expected.insert("spiny");
    expected.insert("splashy");
    expected.insert("spongy");
    expected.insert("spooky");
    expected.insert("sporty");
    expected.insert("spotty");
    expected.insert("sprightly");
    expected.insert("spunky");

    testPassed &= perfectWordCase(rhymeWord, alliterateWord, syllables, partOfSpeech, expected, rhymeBot);

    expected.clear();

    rhymeWord = "petronella";
    alliterateWord = "barrus";
    syllables = 2;
    partOfSpeech = NOUN;
    expected.insert("babka");

    testPassed &= perfectWordCase(rhymeWord, alliterateWord, syllables, partOfSpeech, expected, rhymeBot);

    expected.clear();

    rhymeWord = "ajami";
    alliterateWord = "numbed";
    syllables = 2;
    partOfSpeech = ADVERB;
    expected.insert("namely");
    expected.insert("nearly");
    expected.insert("neatly");
    expected.insert("newly");
    expected.insert("nicely");
    expected.insert("nightly");
    expected.insert("nimbly");
    expected.insert("nobly");

    testPassed &= perfectWordCase(rhymeWord, alliterateWord, syllables, partOfSpeech, expected, rhymeBot);



    if(testPassed){
        cout << "passed perfect word test" << endl;
    }

    return testPassed ? 5 : 0;
}

/////////

string getSpeech(int input){
    switch(input){
        case 0:
            return "adjective";
        case 1:
            return "adverb";
        case 2:
            return "noun";
        case 3:
            return "sense";
        case 4:
            return "verb";
    }
    return "";
}



/////////

int main(){

    RhymeBot rhymeBot;
    Sound::init();
    string dictionaryFile = "data/cmudict-0.7b";

    pronunciationParser(rhymeBot, dictionaryFile);
    parseAllPartsOfSpeech(rhymeBot);


    int tentativeScore = 0;

    tentativeScore += countSyllablesTest(rhymeBot);
    tentativeScore += rhymingSyllablesTest(rhymeBot);
    tentativeScore += alliterationSoundsTest(rhymeBot);
    tentativeScore += allRhymesTest(rhymeBot);
    tentativeScore += allAlliterationsTest(rhymeBot);
    tentativeScore += bestRhymeTest(rhymeBot);
    tentativeScore += bestAlliterationTest(rhymeBot);
    tentativeScore += perfectWordTest(rhymeBot);

    cout << endl << "Tentative Score: " << tentativeScore << endl;
    cout << endl << "This score may change when tested with the grading test cases" << endl;
    cout << "Note: The 15 efficiency points will be verified manually during grading" << endl << endl;

    return 0;
}
