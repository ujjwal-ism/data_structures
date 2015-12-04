#include <algorithm>
#include "DerivedClass.h"
#include "BaseClass.h"

int DerivedClass::findClosestToZero() {
    return this->findClosestToZero(this->numberOfValues-1);
}

int DerivedClass::findClosestToZero(int n) {
    if(n<0){
        return INT_MAX;
    }
    return std::min(std::abs(this->values[n]), this->findClosestToZero(n-1));
}


int DerivedClass::getSum(){
    int sum=0;
    for(int i=0; i<this->numberOfValues; i++){
        sum += values[i];
    }
    return sum;
}


int DerivedClass::getMultiplication(){
    int mult=1;
    for(int i=0; i<this->numberOfValues; i++){
        mult *= values[i];
    }
    return mult;
}


int DerivedClass::evaluateAsPolynomial(int x){
    int eval=0;
    for(int i=this->numberOfValues-1; i>=0; i--){
        eval = (x*eval) + this->values[i];
    }
    return eval;
}

