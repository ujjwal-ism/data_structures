#ifndef CSE250_FALL2015_CAR_H
#define CSE250_FALL2015_CAR_H

#include <string>
#include <iostream>

using namespace std;

class Car {

private:

    string make;
    string model;
    double weight;
    int hp;

public:

    Car(string, string, double, int);

    string getMake() const;
    string getModel() const;
    double getWeight() const;
    int getHP() const;
    double powerToWeightRatio() const;


};


ostream& operator<<(ostream &stream, const Car &car);


#endif //CSE250_FALL2015_CAR_H
