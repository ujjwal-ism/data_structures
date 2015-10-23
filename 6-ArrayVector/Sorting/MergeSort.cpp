#include "MergeSort.h"

using namespace std;



void mergeSort(std::vector<int>& values){
    vector<int> workingCopy(values);

    if(values.size() <=1){
        return;
    }

    int middle = values.size()/2;

    vector<int> left(values.begin(), values.begin()+middle);
    vector<int> right(values.begin()+middle, values.end());

    mergeSort(left);
    mergeSort(right);

    vector<int> tmp = merge(left, right);
    values = tmp;


}


vector<int> merge(vector<int>& left, vector<int>& right){
    vector<int> temp;

    int leftPointer = 0;
    int rightPointer = 0;

    while(leftPointer < left.size() && rightPointer < right.size()){
        if(left[leftPointer] < right[rightPointer]){
            temp.push_back(left[leftPointer++]);
        }else{
            temp.push_back(right[rightPointer++]);
        }
    }

    while(leftPointer < left.size()){
        temp.push_back(left[leftPointer++]);
    }
    while(rightPointer < right.size()){
        temp.push_back(right[rightPointer++]);
    }

//     left.clear();
//     left.insert(left.begin(), temp.begin(), temp.begin()+leftPointer);
// 
//     right.clear();
//     right.insert(right.begin(), temp.begin()+leftPointer, temp.end());

    return temp;
}