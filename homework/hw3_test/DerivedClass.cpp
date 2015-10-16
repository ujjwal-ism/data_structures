#include <algorithm>
#include "DerivedClass.h"
#include "BaseClass.h"

int DerivedClass::findClosestToZero() {
   return findClosestToZero(numberOfValues-1);
}

int DerivedClass::findClosestToZero(int n) {

   int distance = std::max(values[n], -values[n]);
   if (n ==0) {
      return distance;
   }
   int closestDistance = findClosestToZero(n - 1);

   if(distance < closestDistance){
      closestDistance = distance;
      return closestDistance;
   }
}

