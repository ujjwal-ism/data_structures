#include "FirstClass.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void firstTasteOfSTL();

int main(){

    int size = 12;

    //Pointer to an object
    FirstClass* firstObject = new FirstClass(size);
    cout << endl << "size of firstObject is: " << firstObject->getSize() << endl;
    cout << "firstObject location: " << firstObject << endl;

    //Object without pointer
    FirstClass secondObject;
    secondObject.setSize(size);
    cout << endl << "size of secondObject is: " << secondObject.getSize() << endl;
    cout << "secondObject location: " << &secondObject << endl;

//    firstTasteOfSTL();

    return 0;
}

void firstTasteOfSTL(){
    vector<FirstClass*>* objectsVector = new vector<FirstClass*>();
    int vectorSize=10;
    for(int i=0; i<vectorSize; i++){
        objectsVector->push_back(new FirstClass(random()));
    }

    for(int i=0; i<vectorSize; i++){
        cout << objectsVector->at(i)->getSize() << endl;
    }
    cout << endl << endl;
    sort(objectsVector->begin(), objectsVector->end());

    for(int i=0; i<vectorSize; i++){
        cout << objectsVector->at(i)->getSize() << endl;
    }
    cout << endl;

}