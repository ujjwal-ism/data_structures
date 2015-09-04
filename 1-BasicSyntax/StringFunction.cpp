#include <iostream>

std::string spaceOut(std::string);

int main(){

    std::cout << "enter a word: ";
    std::string userInput;
//    std::cin >> userInput;
    std::getline(std::cin, userInput);
    std::cout << '\n' << spaceOut(userInput);
    std::cout << "\nAfter function call, userInput is: " << userInput;
    return 0;
}

std::string spaceOut(std::string input){
    int n = input.length();
    std::string spacedOut;
    spacedOut.resize(2*n);
    for(int i=0; i<n; i++){
        spacedOut[2*i] = input[i];
        spacedOut[2*i+1] = ' ';
        input[i] = ' ';
    }
    std::cout << "In function call, input is: " << input << '\n';
    return spacedOut;
}