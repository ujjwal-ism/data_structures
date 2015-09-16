//
// Created by jesse hartloff on 9/14/15.
//

#include "Run.h"
#include <iostream>

using namespace std;

class Animal{
public:
    virtual string makeNoise()=0;
};


class Dog : public Animal{
public:
    string makeNoise(){return "woof";}
};

int main(){
    Animal* myDog = new Dog();
    cout << myDog->makeNoise() << endl;
    return 0;
}