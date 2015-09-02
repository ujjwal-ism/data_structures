#include <iostream>


int main() {

    std::string hello = "Hello World!";
    std::cout <<  "\n\n" << hello << "\n\n";

    int n=20;
    int sum=0;
    for(int i=0; i<n; i++){
        if(i%4 == 0){
            std::cout << "i is divisible by 4: " << i << "\n";
            sum += i;
        } else {
            std::cout << i << "\n";
        }
    }

    std::cout << "\nsum = " << sum << "\n";

    return 0;
}