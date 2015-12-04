#include <iostream>
#include "BaseClass.h"
#include "DerivedClass.h"
#include "ObjectSearch.h"


using namespace std;

int main(){

    int n=5;
    BaseClass* objectInstances = new DerivedClass[n];

    for(int i=0; i<n-1; i++){
        int* ints = new int[3];
        ints[0] = i;
        ints[1] = i+20;
        ints[2] = i-12;
        objectInstances[i] = DerivedClass(ints, 3);
    }


    int* iiInts = new int[3];
    iiInts[0] = 72;
    iiInts[1] = 10;
    iiInts[2] = 0;

    objectInstances[n-1] = DerivedClass(iiInts, 3);




    int* moreInts = new int[3];
    moreInts[0] = 6;
    moreInts[1] = -3;
    moreInts[2] = 4;

    DerivedClass toFind(moreInts, 3);


    cout << "closest to zero: " << toFind.findClosestToZero() << '\n';

    cout << "sum: " << toFind.getSum() << "   expected: 7" << endl;
    cout << "mul: " << toFind.getMultiplication() <<  "   expected: -72" << endl;
    cout << "pol: " << toFind.evaluateAsPolynomial(7) <<  "   expected: 181" << endl;

    // Note: objectInstances is not guaranteed to be sorted by polyEval as n and polyEvalPoint are adjusted
    cout << endl << "found? " << findEqualPolyEval(objectInstances, n, &toFind, 6) << '\n';

}



