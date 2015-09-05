#include <iostream>
#include "hw1.h"

int main(){
    std::cout << '\n' << getCustomString() << '\n';
    std::cout << countChars("This is a sentence", 't') << '\n';
    std::cout << countCharsCustom('f') << '\n';

    return 0;
}
