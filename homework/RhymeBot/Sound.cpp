#include "Sound.h"

using namespace std;


Sound::Sound(string){

}

string Sound::getSound(){
    return sound;
}


int Sound::getPronunciationNumber(){
    return pronunciationNumber;
}


SoundFactory::SoundFactory(){
    this->init();
}

void SoundFactory::init(){
    // TODO: Coming Soon
}

Sound SoundFactory::makeSound(string){
    Sound sound("AA");
    // TODO: Coming Soon
    return sound;
}