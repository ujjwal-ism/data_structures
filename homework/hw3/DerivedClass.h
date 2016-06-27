#ifndef CSE250_SUMMER2016_DERIVEDCLASS_H
#define CSE250_SUMMER2016_DERIVEDCLASS_H

#include "BaseClass.h"

class DerivedClass : public BaseClass {

private:


public:
    DerivedClass() : BaseClass(){}
    DerivedClass(int* values, int numberOfValues) : BaseClass(values, numberOfValues){}

    int findClosestToZero();
    int findClosestToZero(int);

    int getSum();
    int getMultiplication();
    int evaluateAsPolynomial(int);

};


#endif //CSE250_SUMMER2016_DERIVEDCLASS_H
