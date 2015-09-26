#ifndef CSE250_FALL2015_OBJECTSEARCH_H
#define CSE250_FALL2015_OBJECTSEARCH_H

#include "BaseClass.h"
#include "DerivedClass.h"

bool findEqualPolyEval(BaseClass*, int, BaseClass*, int);
bool findEqualPolyEvalSlow(BaseClass*, int, BaseClass*, int);
bool binarySearch(BaseClass*, int, int, int, int);


#endif //CSE250_FALL2015_OBJECTSEARCH_H
