#include <iostream>

//using namespace std;

int main() {

    std::string hello = "Hello World!";
    std::cout <<  "\n\n" << hello << "\n\n";
   
    std::string aString = "This is a string and later will be an int "; 
    int p = 27;

    std::cout << aString << p;

    int n=0;
    int sum=0;
    for(int i=10; i<n; i++){
        if(i%4 == 0){
            std::cout << "i is divisible by 4: " << i << '\n';
            sum += i;
        } else {
            std::cout << i << "\n";
        }
    }

    std::cout << "\nsum = " << sum << "\n";

    int r;

    std::cout << "r= " << r << "\n";

    return 0;
}
