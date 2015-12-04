#include "CarSorters.h"

bool compareHP(Car car1, Car car2){
    return car1.getHP() < car2.getHP();
}

bool compareHPFunctor::operator()(const Car &car1, const Car &car2) const{
    return car1.getHP() < car2.getHP();
}