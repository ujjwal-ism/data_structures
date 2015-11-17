#include <iostream>
#include <math.h>

using namespace std;

int randomOperand(){
    return (rand()%100);
}

char randomOperator(){
    int operatorIndex = rand()%4;
    switch(operatorIndex){
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return '*';
        case 3:
            return '/';
    }
    return ' ';
}

int main() {
    srand(time(NULL));

    int openParens = 0;
    int n=50;

    cout << randomOperand();

    for (int i = 0; i < n; i++) {
        while (openParens > 0 && (rand() % 100) < 60) {
            openParens--;
            cout << ')';
        }

        cout << randomOperator();

        while((rand() % 100) < 40) {
            openParens++;
            cout << '(';
        }
        cout << randomOperand();
    }

    while(openParens>0){
        openParens--;
        cout << ')';
    }
    cout << endl;
}

