#include "Car.h"

using namespace std;

Car::Car(string make, string model, double weight, int hp) :
        make(make), model(model), weight(weight), hp(hp) {}

string Car::getMake() const{
    return make;
}

string Car::getModel() const{
    return model;
}

double Car::getWeight() const{
    return weight;
}

int Car::getHP() const{
    return hp;
}

double Car::powerToWeightRatio() const{
    return hp/weight;
}


ostream& operator<<(ostream &stream, const Car &car) {
    return stream << car.getMake() << " " << car.getModel() << ": " << car.getWeight() << "kg " << car.getHP() << "hp";
}