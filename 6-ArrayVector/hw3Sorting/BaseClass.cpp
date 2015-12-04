#include "BaseClass.h"


BaseClass::BaseClass() {
}

BaseClass::BaseClass(int* values, int numberOfValues) {
    this->values = values;
    this->numberOfValues = numberOfValues;
}


int BaseClass::getSum(){
    return numberOfValues > 2 ? values[0]+(*values) : numberOfValues;
}

int BaseClass::getMultiplication(){
    return numberOfValues < 5 ? numberOfValues*numberOfValues : values[0]*values[1]*values[2];
}

int BaseClass::evaluateAsPolynomial(int x){
    return x*numberOfValues;
}
