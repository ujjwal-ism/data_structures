#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "SetExample.h"

int main(){

    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    int maxValue = 10000000;
    int n=500000;

    cout << n << " elements per set with max value of " << maxValue << endl;

    vector<int>* vectorOfIntegers1 = getRandomVector(n, maxValue);
    vector<int>* vectorOfIntegers2 = getRandomVector(n, maxValue);

    set<int>* setOfIntegers1 = new set<int>;
    setOfIntegers1->insert(vectorOfIntegers1->begin(),
                           vectorOfIntegers1->end() );
    set<int>* setOfIntegers2 = new set<int>;
    setOfIntegers2->insert(vectorOfIntegers2->begin(),
                           vectorOfIntegers2->end() );

    //printData(vectorOfIntegers1, vectorOfIntegers2,
    //setOfIntegers1, setOfIntegers2);

    cout << endl;

    //unionExample(vectorOfIntegers1, vectorOfIntegers2,
    // setOfIntegers1, setOfIntegers2);

    cout << endl;

    intersectionExample(vectorOfIntegers1, vectorOfIntegers2,
                        setOfIntegers1, setOfIntegers2);

    cout << endl;

    delete vectorOfIntegers1;
    delete setOfIntegers1;
    delete vectorOfIntegers2;
    delete setOfIntegers2;

    return 0;
}