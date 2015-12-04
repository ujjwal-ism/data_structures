#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int getRandomInt(int);
vector<int>* getRandomVector(int, int);
set<int>* getRandomSet(int, int);
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