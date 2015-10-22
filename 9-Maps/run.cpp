#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "../8-Set/SetSorting/Car.h"
#include "MapExample.h"

using namespace std;

template <typename T> void printDataStructure(T const &cars){
//    cout << typeid(T).name() << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    for(typename T::const_iterator it = cars.begin();
        it != cars.end();
        it++){
        cout << *it << "\n";
    }
    cout << endl;
}

template <typename T> void printMap(T const &cars){
//    cout << typeid(T).name() << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    for(typename T::const_iterator it = cars.begin();
        it != cars.end();
        it++){
        cout << "[" << (*it).first << "] " << (*it).second << "\n";
    }
    cout << endl;
}



int main(){

    vector<Car> carsVec;

    // data from gt6: http://www.kudosprime.com/gt6/carlist.php?start=50
    carsVec.push_back(Car("Acura", "HSC", 1150, 315));
    carsVec.push_back(Car("Acura", "NSX", 1430, 290));
    carsVec.push_back(Car("Audi", "R8", 1620, 518));
    carsVec.push_back(Car("Honda", "Civic", 1270, 222));
    carsVec.push_back(Car("MINI", "Cooper", 720, 61));
    carsVec.push_back(Car("Mazda", "RX8", 1310, 207));
    carsVec.push_back(Car("Nissan", "CUBE X", 970, 81));
    carsVec.push_back(Car("Subaru", "IMPREZA WRX STI", 1490, 304));
    carsVec.push_back(Car("Tesla Motors", "Model S", 2018, 415));
    carsVec.push_back(Car("Toyota", "SUPRA RZ", 1510, 276));
    carsVec.push_back(Car("Toyota", "Yaris RS Turbo", 980, 148));
    carsVec.push_back(Car("Volkswagen", "Sambabus", 1095, 34));

    double weight = 716;
//    double trimmedWeight = 0.1;
//    for(int i=0; i<10; i++){
//        weight -= trimmedWeight;
//    }

    carsVec.push_back(Car("IndyCar", "", 715, 700));
    carsVec.push_back(Car("IndyCar", "", weight, 700));

    printDataStructure<vector<Car> >(carsVec);
    random_shuffle(carsVec.begin(), carsVec.end());
    printDataStructure<vector<Car> >(carsVec);

    map<string, Car> carMap;

    for(vector<Car>::const_iterator it = carsVec.begin();
            it != carsVec.end(); it++){
        Car currentCar = *it;
        carMap.insert(make_pair(currentCar.getMakeAndModel(), currentCar));
    }
    printMap<map<string, Car> >(carMap);


    carMap.clear();

    for(vector<Car>::const_iterator it = carsVec.begin();
            it != carsVec.end(); it++){
        Car currentCar = *it;
        carMap.insert(make_pair(currentCar.getMake(), currentCar));
    }
    printMap<map<string, Car> >(carMap);





    /*** DANGER ZONE ***/
    // Implicit equality check using doubles
    map<double, Car> carMapDouble;

    for(vector<Car>::const_iterator it = carsVec.begin();
        it != carsVec.end(); it++){
        Car currentCar = *it;
        carMapDouble.insert(make_pair(currentCar.powerToWeightRatio(), currentCar));
    }

    printMap<map<double, Car> >(carMapDouble);


    return 0;
}