#include <iostream>

using namespace std;

int foo();

int main(){

    int* things = new int[10];
    cout << "0: " << things[0] << endl;
    cout << "-1: " << things[-1] << endl;

//    std::cout << foo();
    return 0;
}

int foo(){
    return 6;
}