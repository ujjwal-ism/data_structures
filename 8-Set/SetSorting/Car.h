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

    Car();
    Car(string, string, double, int);
    Car(const Car& otherCar);
    Car& operator=(const Car& otherCar);
    ~Car();

    string getMake() const;
    string getModel() const;
    double getWeight() const;
    int getHP() const;
    double powerToWeightRatio() const;


};

bool operator<(const Car& c1, const Car& c2);

ostream& operator<<(ostream &stream, const Car &car);


#endif //CSE250_FALL2015_CAR_H
