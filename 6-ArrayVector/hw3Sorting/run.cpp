#include "run.h"

using namespace std;

const int MAX_VALUE=100;
const int MIN_VALUE=-100;

int main(){

    int arraySize=5;
    int termsInPolynomial = 10;
    int evaluationPoint = 4;

    BaseClass* objectInstances = new DerivedClass[n];

    for(int i=0; i<arraySize; i++){
        int* polynomialTerms = new int[termsInPolynomial];
        for(int j=0; j<termsInPolynomial; j++){
            polynomialTerms[j] = randomTerm();
        }
        objectInstances[i] = DerivedClass(polynomialTerms, termsInPolynomial);
    }

    printPolyEvals(objectInstances, arraySize, evaluationPoint);
}


void printPolyEvaluations(BaseClass* objectsArray, int arraySize, int evaluationPoint){
    for(int i=0; i<arraySize; i++){
        cout << *(objectsArray+i)->evaluateAsPolynomial(evaluationPoint) << endl;
    }
    cout << endl;
}

int randomTerm(){
    return rand()%(MAX_VALUE-MIN_VALUE) + MIN_VALUE;
}