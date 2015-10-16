#include "Car.h"

using namespace std;

Car::Car() :
        make("default"), model("default"), weight(0.0), hp(0) {}

Car::Car(string make, string model, double weight, int hp) :
        make(make), model(model), weight(weight), hp(hp) {}

Car::Car(const Car& otherCar):
        make(otherCar.getMake()), model(otherCar.getModel()), weight(otherCar.getWeight()), hp(otherCar.getHP()) {}

Car& Car::operator=(const Car& otherCar){
    make = otherCar.getMake();
    model = otherCar.getModel();
    weight = otherCar.getWeight();
    hp = otherCar.getHP();
    return *this;
}

Car::~Car(){}

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

bool operator<(const Car& car1, const Car& car2){
    return car1.getMake() + " " + car1.getModel() < car2.getMake() + " " + car2.getModel();
}

ostream& operator<<(ostream& stream, const Car& car) {
    return stream << car.getMake() << " " << car.getModel() << ": " << car.getWeight() << "kg " << car.getHP() << "hp";
}