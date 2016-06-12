#include "hw1.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int no_of_char;
	int no;

	str = getCustomString();
	cout << str <<endl;

	no_of_char = countChars("Bhaiya ka sab dost naala..",'a');
	cout << no_of_char << endl;

	no = countCharsCustom('a');
	cout << no <<endl;
	return 0;
}

std::string getCustomString(){
    
    return "Ujjwal Kumar 'The SUPREME Leader'";
}


int countChars(std::string words, char character){
    int count=0;
    int i=0;
    while(words[i]!='\0'){
    	if(words[i]==character)
    		count++;
    	i++;
    }
    return count;
}

int countCharsCustom(char character){

	return countChars(getCustomString(),character);    
}

