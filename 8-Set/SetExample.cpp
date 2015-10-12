
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int getRandomInt();
vector<int>* getRandomVector(int n);
set<int>* getRandomSet(int n);
vector<int>* vectorUnionLive(vector<int>*, vector<int>*);
vector<int>* vectorUnion(vector<int>*, vector<int>*);
vector<int>* vectorUnionAlt(vector<int>*, vector<int>*);
set<int>* setUnion(set<int>*, set<int>*);
vector<int>* vectorIntersection(vector<int>*, vector<int>*);
set<int>* setIntersection(set<int>*, set<int>*);
void setExample();
void printVector(vector<int>* vectorOfIntegers);
void printSet(set<int>* setOfIntegers);
void unionExample(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
                  set<int>* setOfIntegers1, set<int>* setOfIntegers2);
void intersectionExample(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
                         set<int>* setOfIntegers1, set<int>* setOfIntegers2);
void printData(vector<int>* vectorOfIntegers1, vector<int>* vectorOfIntegers2,
               set<int>* setOfIntegers1, set<int>* setOfIntegers2);

int maxValue = 100000;

int getRandomInt(){
    return rand()%maxValue;
}

vector<int>* getRandomVector(int n){
//    vector<int>* vectorOfIntegers = new vector<int>(n);
//    for(vector<int>::const_iterator it = vectorOfIntegers->begin(); it != vectorOfIntegers->end(); it++){
//        vectorOfIntegers->insert(it,getRandomInt());
//    }

    vector<int>* vectorOfIntegers = new vector<int>;
    for(int i=0; i<n; i++){
        vectorOfIntegers->push_back(getRandomInt());
    }
    return vectorOfIntegers;
}

set<int>* getRandomSet(int n){
    set<int>* setOfIntegers = new set<int>;
    for(int i=0; i<n; i++){
        setOfIntegers->insert(getRandomInt());
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




int main(){

    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    maxValue = 10000000; // bad practice!
    int n=500000;

    cout << n << " elements per set with max value of " << maxValue << endl;

    vector<int>* vectorOfIntegers1 = getRandomVector(n);
    vector<int>* vectorOfIntegers2 = getRandomVector(n);

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