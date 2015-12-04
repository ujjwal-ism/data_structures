#ifndef CSE250_FALL2015_BASECLASS_H
#define CSE250_FALL2015_BASECLASS_H

#include <iostream>

class BaseClass {
protected:
    int* values;
    int numberOfValues;

public:

    BaseClass();
    BaseClass(int*, int);

    virtual int findClosestToZero()=0;

    virtual int getSum();
    virtual int getMultiplication();
    virtual int evaluateAsPolynomial(int);

};


#endif //CSE250_FALL2015_BASECLASS_H
