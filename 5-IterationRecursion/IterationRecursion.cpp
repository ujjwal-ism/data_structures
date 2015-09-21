#include "IterationRecursion.h"

int gcd(int a, int b) {
    if(b==0){
        return a;
    }
    return this->gcd(b, a%b);
}