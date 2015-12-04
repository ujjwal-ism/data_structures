#include "SelectionSort.h"

using namespace std;

void selectionSort(vector<int>& values){

    int n=values.size();

    for(int i=0; i<n; i++){
        int minValue = values[i];
        int indexOfMin = i;

        for(int j=i+1; j<n; j++){
            if(values[j] < minValue){
                minValue = values[j];
                indexOfMin = j;
            }
        }

        swap(values[i],values[indexOfMin]);
    }

}