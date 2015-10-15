#ifndef CSE250_FALL2015_CARSORTERS_H
#define CSE250_FALL2015_CARSORTERS_H

#include "Car.h"

bool compareHP(Car car1, Car car2);


class compareHPFunctor{
public:
    bool operator()(const Car &car1, const Car &car2) const{
        return car1.getHP() < car2.getHP();
    }
};

class compareWeightFunctor{
public:
    bool operator()(const Car &car1, const Car &car2) const{
        return car1.getWeight() < car2.getWeight();
    }
};

class compareMakeAndModelFunctor{
public:
    bool operator()(const Car &car1, const Car &car2) const{
        return car1.getMake() + " " + car1.getModel() < car2.getMake() + " " + car2.getModel();
    }
};

class comparePowerToWeightFunctor{
public:
    bool operator()(const Car &car1, const Car &car2) const{
        return car1.powerToWeightRatio() < car2.powerToWeightRatio();
    }
};

class compareMakeFunctor{
public:
    bool operator()(const Car &car1, const Car &car2) const{
        return car1.getMake() < car2.getMake();
    }
};

#endif //CSE250_FALL2015_CARSORTERS_H
