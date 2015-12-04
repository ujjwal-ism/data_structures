#include "SetExample.h"

using namespace std;



int getRandomInt(int maxValue){
    return rand()%maxValue;
}

vector<int>* getRandomVector(int n, int maxValue){
//    vector<int>* vectorOfIntegers = new vector<int>(n);
//    for(vector<int>::const_iterator it = vectorOfIntegers->begin(); it != vectorOfIntegers->end(); it++){
//        vectorOfIntegers->insert(it,getRandomInt());
//    }

    vector<int>* vectorOfIntegers = new vector<int>;
    for(int i=0; i<n; i++){
        vectorOfIntegers->push_back(getRandomInt(maxValue));
    }
    return vectorOfIntegers;
}

set<int>* getRandomSet(int n, int maxValue){
    set<int>* setOfIntegers = new set<int>;
    for(int i=0; i<n; i++){
        setOfIntegers->insert(getRandomInt(maxValue));
    }
    return setOfIntegers;
}


void setExample(){
    set<int> intSet;
    cout << "size: " << intSet.max_size() << endl;
}



vector<int>* vectorUnion(vector<int>* vector1, vector<int>* vector2){
    vector<int>* unionOfVectors = new vector<int>;
    unionOfVectors->insert(unionOfVectors->end(), vector1->begin(), vector1->end());
    unionOfVectors->insert(unionOfVectors->end(), vector2->begin(), vector2->end());
    sort(unionOfVectors->begin(), unionOfVectors->end());
    int previous = -1;
    for(vector<int>::const_iterator it = unionOfVectors->begin();
        it < unionOfVectors->end();
        it++){
        if(*it == previous){
            it = unionOfVectors->erase(it);
            it--;
        }else{
            previous = *it;
        }
    }
    return unionOfVectors;
}

vector<int>* vectorUnionAlt(vector<int>* vector1, vector<int>* vector2){
    vector<int>* unionOfVectors = new vector<int>;

    for(vector<int>::const_iterator it = vector1->begin();
        it != vector1->end();
        it++){
        if(!binary_search(unionOfVectors->begin(), unionOfVectors->end(), *it)){
            unionOfVectors->insert(
                    upper_bound(unionOfVectors->begin(),
                                unionOfVectors->end(), *it),
                    *it);
        }
    }

    for(vector<int>::const_iterator it = vector2->begin();
        it != vector2->end();
        it++){
        if(!binary_search(unionOfVectors->begin(), unionOfVectors->end(), *it)){
            unionOfVectors->insert(
                    upper_bound(unionOfVectors->begin(),
                                unionOfVectors->end(), *it),
                    *it);
        }
    }
    return unionOfVectors;
}


set<int>* setUnion(set<int>* set1, set<int>* set2){
    set<int>* unionOfSets = new set<int>;
    unionOfSets->insert(set1->begin(), set1->end());
    unionOfSets->insert(set2->begin(), set2->end());
    return unionOfSets;
}


vector<int>* vectorIntersection(vector<int>* vector1, vector<int>* vector2){
    vector<int>* intersectionOfVectors = new vector<int>;
    sort(vector1->begin(), vector1->end());
    sort(vector2->begin(), vector2->end());
    int previous = -1;
    for(vector<int>::const_iterator it = vector1->begin();
        it < vector1->end();
        it++){
        if(*it == previous){
            continue;
        }
        previous = *it;
        if(binary_search(vector2->begin(), vector2->end(), *it)){
            intersectionOfVectors->push_back(*it);
        }
    }
    return intersectionOfVectors;
}


set<int>* setIntersection(set<int>* set1, set<int>* set2){
    set<int>* intersectionOfSets = new set<int>;
    for(set<int>::const_iterator it = set1->begin();
        it != set1->end();
        it++){
        if(set2->count(*it) == 1){
            intersectionOfSets->insert(*it);
        }
    }
    return intersectionOfSets;
}



void printVector(vector<int>* vectorOfIntegers){
    cout << "vector" << endl;
    for(vector<int>::const_iterator it = vectorOfIntegers->begin();
        it < vectorOfIntegers->end();
        it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printSet(set<int>* setOfIntegers){
    cout << "set" << endl;
    for(set<int>::const_iterator it = setOfIntegers->begin();
        it != setOfIntegers->end();
        it++){
        cout << *it << " ";
    }
    cout << endl;
}

void unionExample(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
                         set<int>* setOfIntegers1, set<int>* setOfIntegers2){

    cout << "union example:" << endl;
    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    startTime = clock();
    vector<int>* unionOfVectors = vectorUnionAlt(vectorOfIntegers1, vectorOfIntegers2);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms vectorUnion\n";

    startTime = clock();
    set<int>* unionOfSets = setUnion(setOfIntegers1, setOfIntegers2);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms setUnion\n";

    //printVector(unionOfVectors);
    //printSet(unionOfSets);

    cout << unionOfVectors->size() << " elements in unionOfVectors" << endl;
    cout << unionOfSets->size() << " elements in unionOfSets" << endl;

    delete unionOfVectors;
    delete unionOfSets;
}


void intersectionExample(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
                         set<int>* setOfIntegers1, set<int>* setOfIntegers2){

    cout << "intersection example:" << endl;
    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    startTime = clock();
    vector<int>* intersectionOfVectors = vectorIntersection(vectorOfIntegers1, vectorOfIntegers2);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms vectorIntersection\n";

    startTime = clock();
    set<int>* intersectionOfSets = setIntersection(setOfIntegers1, setOfIntegers2);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms setIntersection\n";

    //printVector(intersectionOfVectors);
    //printSet(intersectionOfSets);

    cout << intersectionOfVectors->size() << " elements in intersectionOfVectors" << endl;
    cout << intersectionOfSets->size() << " elements in intersectionOfSets" << endl;

    delete intersectionOfVectors;
    delete intersectionOfSets;
}


void printData(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
               set<int>* setOfIntegers1, set<int>* setOfIntegers2){
    cout << endl << "vectorOfIntegers1, setOfIntegers1" << endl;
    printVector(vectorOfIntegers1);
    printSet(setOfIntegers1);
    cout << endl << "vectorOfIntegers2, setOfIntegers2" << endl;
    printVector(vectorOfIntegers2);
    printSet(setOfIntegers2);
}



