#include "run.h"

using namespace std;

int main(){

    int n=10000000;
    int maxValue = 10000;

    clock_t startTime;
    clock_t endTime;
    double elapsedTime;


    vector<int>* values = new vector<int>;

    srand(time(0));
    for(int i=0; i<n; i++){
        values->push_back(rand()%maxValue);
    }



 //   cout << endl <<//  "selection sort" << endl;
// //     printVector(*values);
// 
//     startTime = clock();
//     selectionSort(*values);
// //     printVector(*values);
//     elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
//     cout << elapsedTime << "ms selectionSort\n";

    ///////

//     random_shuffle(values->begin(), values->end());
// 
//     cout << endl << "merge sort" << endl;
// //     printVector(*values);
// 
//     startTime = clock();
//     mergeSort(*values);
// //     printVector(*values);
//     elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
//     cout << elapsedTime << "ms mergeSort\n";

    ///////

    random_shuffle(values->begin(), values->end());

    cout << endl << "std::sort" << endl;
//     printVector(*values);

    startTime = clock();
    sort(values->begin(), values->end());
//     printVector(*values);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms std::sort\n";


    delete values;
    return 0;
}

void printVector(const vector<int>& values){

    for(int i=0; i<values.size(); i++){
        cout << values[i] << " ";
    }
    cout << endl;
}