#include <algorithm>
#include "DerivedClass.h"
#include "BaseClass.h"
#include <math.h>

using namespace std;

// DerivedClass(int* values,int numberOfValues){
// 	this->values = values;
// 	this->numberOfValues = numberOfValues;
// }

int DerivedClass::findClosestToZero() {
    return this->findClosestToZero(this->numberOfValues-1);
}

int DerivedClass::findClosestToZero(int n) {
    
    return  std::min(std::abs(this->values[n]), this->findClosestToZero(n-1));
}

int DerivedClass::getSum(){
	int Sum=0;
	for(int i=0;i<this->numberOfValues;i++){
		Sum += this->values[i];
	}
	return Sum;
}

int DerivedClass::getMultiplication(){
	int product=1;
	for(int i=0; i< this->numberOfValues ; i++){
		product *= this->values[i];
	}
	return product;
}

int DerivedClass::evaluateAsPolynomial(int x){
	int eval=0;
	for (int i = 1; i < this->numberOfValues; ++i)
	{
		eval += (this->values[i])*pow(x,i);
	}
	return eval+this->values[0];
}

int main(int argc, char const *argv[])
{	
	int array[5] = {2,4,3,6,5};
	DerivedClass test(array,5);

	cout<<test.findClosestToZero()<<endl;
	cout<<test.getSum()<<endl;
	cout<<test.getMultiplication()<<endl;
	cout<<test.evaluateAsPolynomial(1);

	return 0;
}
