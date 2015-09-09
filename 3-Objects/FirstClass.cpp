//
// Created by jesse hartloff on 9/7/15.
//

#include "FirstClass.h"

FirstClass::FirstClass(int n) { this->size = n; }
FirstClass::FirstClass() {}

int FirstClass::getSize() {
    return this->size;
}

void FirstClass::setSize(int n){
    this->size = n;
}