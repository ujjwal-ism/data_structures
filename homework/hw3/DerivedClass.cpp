#include <algorithm>
#include "DerivedClass.h"
#include "BaseClass.h"

int DerivedClass::findClosestToZero() {
    return this->findClosestToZero(this->numberOfValues-1);
}

int DerivedClass::findClosestToZero(int n) {
    int distance = std::max(this->values[n], -this->values[n]);
    int closestDistance;
    if(distance < this->findClosestToZero(n)){
        closestDistance = distance;
    }else{
        closestDistance = this->findClosestToZero(n);
    }
    return closestDistance;
}