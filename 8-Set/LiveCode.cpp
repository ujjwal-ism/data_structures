
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void printSet(set<int>* setOfIntegers){
    cout << "set" << endl;
    for(set<int>::const_iterator it = setOfIntegers->begin();
        it != setOfIntegers->end();
        it++){
        cout << *it << " ";
    }
    cout << endl;
}


void printSet(multiset<int>* setOfIntegers){
    cout << "set" << endl;
    for(multiset<int>::const_iterator it = setOfIntegers->begin();
        it != setOfIntegers->end();
        it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    set<int> things;
    
    things.insert(5);
    things.insert(5);
    things.insert(3);
    things.insert(6);
    things.insert(10);
    things.insert(12);
    things.insert(5);
    things.insert(15);
    things.insert(18);
    things.insert(1);
    
    set<int>::iterator itLower = things.find(3);
    set<int>::iterator itUpper = things.find(12);
    
    for(set<int>::iterator it = itLower; it != itUpper; it++){
        cout << *it << " ";
	}
	cout << endl;
    
    //printSet(&things);
    

    return 0;
}