#include "Q3.h"

using namespace std;


void Q3Run(){

    vector<int> vectorOfInts;
    for(int i=0; i<8; i++){
        vectorOfInts.push_back(10-(2*i));
    }
    vectorOfInts.push_back(4);
    vectorOfInts.insert(vectorOfInts.begin(), -10);
    reverse(vectorOfInts.begin(), vectorOfInts.end());

    printVector(vectorOfInts);

    vector<int> otherInts;
    otherInts.push_back(300);
    otherInts.push_back(50);
    otherInts.push_back(-60);
    otherInts.push_back(0);
    vectorOfInts.insert(vectorOfInts.end()-5, otherInts.begin(), otherInts.end());
    sort(vectorOfInts.begin(), vectorOfInts.end());
    swap(vectorOfInts[1], vectorOfInts[10]);
    swap(vectorOfInts[7], vectorOfInts[4]);
    swap(vectorOfInts[12], vectorOfInts[4]);
    vectorOfInts.erase(vectorOfInts.begin()+2, vectorOfInts.begin()+10);

    printVector(vectorOfInts);

    swap(*(vectorOfInts.end()-4), *(vectorOfInts.end()-2));
    vectorOfInts.insert(vectorOfInts.begin()+4, 120);
    vectorOfInts.insert(vectorOfInts.begin()+2, 56);
    vectorOfInts.insert(vectorOfInts.end()-6, 101);
    int numbers[3];
    numbers[2] = 7;
    numbers[1] = 5;
    numbers[0] = 3;
    vectorOfInts.insert(vectorOfInts.begin()+4, numbers, numbers+2);


   printVector(vectorOfInts);

}



void printVector(const vector<int>& values){
    for(int i=0; i<values.size(); i++){
        cout << values[i] << " ";
    }
    cout << endl;
}


int main(){
    Q3Run();
    return 0;
}