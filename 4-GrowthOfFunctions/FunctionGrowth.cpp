#include "FunctionGrowth.h"

using namespace std;


void constant(long n){
    for(long i=0; i<10000000; i++){
        operation();
    }
}

void log(long n){
    for(long i=1; i<n; i<<=1){
        operation();
    }
}

void linear(long n){
    for(long i=0; i<n; i++){
        operation();
    }
}

void nlogn(long n) {
    if (n > 1) {
        linear(n);
        nlogn(n / 2);
        nlogn(n / 2);
    }
}

void squared(long n){
    for(long i=0; i<n; i++){
        for(long j=0; j<n; j++) {
            operation();
        }
    }
}

void cubed(long n){
    for(long i=0; i<n; i++) {
        for (long j = 0; j < n; j++) {
            for (long k = 0; k < n; k++) {
                operation();
            }
        }
    }
}

void exponential(long n){
    if(n>0){
        exponential(n-1);
        exponential(n-1);
    }else{
        operation();
    }
}

void factorial(long n){
    if(n>0) {
        for (long i = 0; i < n; i++) {
            factorial(n - 1);
        }
    }
    else{
        operation();
    }
}

void operation(){
    //do nothing
}



int main(){
    long n=5;

    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    //run and time each function

    startTime = clock();
    constant(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms constant\n";

    startTime = clock();
    log(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms log\n";

    startTime = clock();
    linear(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms linear\n";

    startTime = clock();
    linear(10000*n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms 10000*linear\n";

    startTime = clock();
    nlogn(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms nlogn\n";

    startTime = clock();
    nlogn(1000*n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms (1000*n)log(1000*n)\n";

    startTime = clock();
    squared(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms squared\n";

    startTime = clock();
    cubed(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms cubed\n";

    startTime = clock();
    exponential(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms exponential\n";

    startTime = clock();
    factorial(n);
    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC)*1000.0;
    cout << elapsedTime << "ms factorial\n";

    return 0;
}