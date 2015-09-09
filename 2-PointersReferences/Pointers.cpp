#include "Pointers.h"

using namespace std;

int main() {

    int number=12;
    int* numberPointer = &number;

    cout << endl << "int pointer value: " << *numberPointer << endl;
    cout << "int pointer   : " << numberPointer << endl;
    cout << "int pointer+1 : " << numberPointer+1 << endl;
    cout << "size of int: " << sizeof(number) << endl << endl;

    long longNumber=12;
    long* longNumberPointer = &longNumber;

    cout << "long pointer value: " << *longNumberPointer << endl;
    cout << "long pointer   : " << longNumberPointer << endl;
    cout << "long pointer+1 : " << longNumberPointer+1 << endl;
    cout << "size of long: " << sizeof(longNumber) << endl << endl;

    int n=4;
    int* numbers = new int[n]; // allocates memory for 4 consecutive ints
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 5;

    cout << "numbers: " << numbers << endl;

    for(int i=0; i<n; i++){
        cout << "numbers[" << i << "]  : " << numbers[i] << endl;
        cout << "*(numbers+" << i << "): " << *(numbers+i) << endl;
    }

	cout << endl << "numbers[0]  : " << numbers[0] << endl;

    return 0;
}