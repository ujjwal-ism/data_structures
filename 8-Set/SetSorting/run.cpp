
#include <iostream>
#include <String>
#include <set>
#include <vector>
#include <algorithm>

#include "Car.h"
#include "CarSorters.h"

using namespace std;

template <typename T> void printSet(T const& cars){
//    cout << T << endl;
    for(typename T::const_iterator it = cars.begin();
        it != cars.end();
        it++){
        cout << *it << "\n";
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


    printSet<vector<Car> >(carsVec);
    sort(carsVec.begin(), carsVec.end(), compareHP);
    printSet<vector<Car> >(carsVec);

    set<Car, compareMakeAndModelFunctor> carsByMakeAndModel;
    carsByMakeAndModel.insert(carsVec.begin(), carsVec.end());
    printSet<set<Car, compareMakeAndModelFunctor> >(carsByMakeAndModel);

    set<Car, compareWeightFunctor> carsByWeight;
    carsByWeight.insert(carsVec.begin(), carsVec.end());
    printSet<set<Car, compareWeightFunctor> >(carsByWeight);

    set<Car, compareHPFunctor> carsByHP;
    carsByHP.insert(carsVec.begin(), carsVec.end());
    printSet<set<Car, compareHPFunctor> >(carsByHP);


    set<Car, comparePowerToWeightFunctor> carsByPowerToWeightRatio;
    carsByPowerToWeightRatio.insert(carsVec.begin(), carsVec.end());
    printSet<set<Car, comparePowerToWeightFunctor> >(carsByPowerToWeightRatio);


    set<Car, compareMakeFunctor> carsByMake;
    carsByMake.insert(carsVec.begin(), carsVec.end());
    printSet<set<Car, compareMakeFunctor> >(carsByMake);

    multiset<Car, compareMakeFunctor> carsByMakeMultiset;
    carsByMakeMultiset.insert(carsVec.begin(), carsVec.end());
    printSet<multiset<Car, compareMakeFunctor> >(carsByMakeMultiset);


    //query
    set<Car, compareMakeAndModelFunctor> carsSubset;
    carsSubset.insert(carsByHP.upper_bound(Car("","",0,200)), carsByHP.upper_bound(Car("","",0,300)));
    printSet<set<Car, compareMakeAndModelFunctor> >(carsSubset);


    return 0;
}