#ifndef CSE250_FALL2015_DERIVEDCLASS_H
#define CSE250_FALL2015_DERIVEDCLASS_H

#include "BaseClass.h"

class DerivedClass : public BaseClass {

private:


public:
    DerivedClass() : BaseClass(){}
    DerivedClass(int* values, int numberOfValues) : BaseClass(values, numberOfValues){}

    int findClosestToZero();
    int findClosestToZero(int);
};


#endif //CSE250_FALL2015_DERIVEDCLASS_H
