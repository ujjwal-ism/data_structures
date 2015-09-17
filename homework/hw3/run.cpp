#include <iostream>
#include "BaseClass.h"
#include "DerivedClass.h"
#include "ObjectSearch.h"


using namespace std;

int main(){

    int n=5;
    BaseClass* objectInstances = new DerivedClass[n];

    for(int i=0; i<n; i++){
        int* ints = new int[3];
        ints[0] = i;
        ints[1] = i+20;
        ints[2] = i-12;
        objectInstances[i] = DerivedClass(ints, 3);
    }

    int* moreInts = new int[3];
    moreInts[0] = 6;
    moreInts[1] = -3;
    moreInts[2] = 4;

    DerivedClass toFind(moreInts, 3);

    cout << toFind.findClosestToZero() << '\n';

    cout << findEqualPolyEval(objectInstances, n, &toFind, 6) << '\n';

}