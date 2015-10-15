#include "CarSorters.h"

using namespace std;

bool compareHP(Car car1, Car car2){
    return car1.getHP() < car2.getHP();
}