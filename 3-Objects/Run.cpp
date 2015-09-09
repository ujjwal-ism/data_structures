#include "FirstClass.h"

#include <iostream>

using namespace std;

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
}