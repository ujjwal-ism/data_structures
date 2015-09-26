#include "ObjectSearch.h"


bool findEqualPolyEval(BaseClass* instancesToCheck, int numberOfInstances,
                       BaseClass* instanceToFind, int polyEvalPoint){

    int evalToFind = instanceToFind->evaluateAsPolynomial(polyEvalPoint);
    return binarySearch(instancesToCheck, 0, numberOfInstances-1, evalToFind, polyEvalPoint);
}


bool binarySearch(BaseClass* instancesToCheck, int lowerBound, int upperBound,
                  int evalToFind, int polyEvalPoint){

    if(upperBound - lowerBound <=1){
        return evalToFind == instancesToCheck[lowerBound].evaluateAsPolynomial(polyEvalPoint) ||
               evalToFind == instancesToCheck[upperBound].evaluateAsPolynomial(polyEvalPoint);
    }

    int midPoint = (lowerBound+upperBound)/2;
    int currentEval = instancesToCheck[midPoint].evaluateAsPolynomial(polyEvalPoint);
    if(currentEval == evalToFind){
        return true;
    }else if(currentEval < evalToFind){
        return binarySearch(instancesToCheck, midPoint, upperBound, evalToFind, polyEvalPoint);
    }else{
        return binarySearch(instancesToCheck, lowerBound, midPoint, evalToFind, polyEvalPoint);
    }

}