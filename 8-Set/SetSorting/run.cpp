
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "Car.h"
#include "CarSorters.h"
#include "../SetExample.h"

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


    printDataStructure<vector<Car> /* need an extra space here to avoid compile error with >> */ >(carsVec);

    // sort vector with a custom function
    sort(carsVec.begin(), carsVec.end(), compareHP);
    printDataStructure<vector<Car> >(carsVec);

    // sort using operator<
    set<Car> carsByDefault;
    carsByDefault.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car> >(carsByDefault);


    // sort a set using different functors
    set<Car, compareMakeAndModelFunctor> carsByMakeAndModel;
    carsByMakeAndModel.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car, compareMakeAndModelFunctor> >(carsByMakeAndModel);

    set<Car, compareWeightFunctor> carsByWeight;
    carsByWeight.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car, compareWeightFunctor> >(carsByWeight);

    set<Car, compareHPFunctor> carsByHP;
    carsByHP.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car, compareHPFunctor> >(carsByHP);

    // sort by a derived value
    set<Car, comparePowerToWeightFunctor> carsByPowerToWeightRatio;
    carsByPowerToWeightRatio.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car, comparePowerToWeightFunctor> >(carsByPowerToWeightRatio);


    // duplicates are removed based on functor
    // sorting by make allows only 1 car per make
    set<Car, compareMakeFunctor> carsByMake;
    carsByMake.insert(carsVec.begin(), carsVec.end());
    printDataStructure<set<Car, compareMakeFunctor> >(carsByMake);


    // use a multiset if you want to keep duplicates
    multiset<Car, compareMakeFunctor> carsByMakeMultiset;
    carsByMakeMultiset.insert(carsVec.begin(), carsVec.end());
    printDataStructure<multiset<Car, compareMakeFunctor> >(carsByMakeMultiset);


    // Can execute queries on ranges. Use functions like upper_bound and lower_bound
    //  since find(value) returns end() if the value is not found
    set<Car, compareMakeAndModelFunctor> carsSubset;
    carsSubset.insert(carsByHP.upper_bound(Car("","",0,200)), carsByHP.upper_bound(Car("","",0,300)));
    printDataStructure<set<Car, compareMakeAndModelFunctor> >(carsSubset);

    set<Car, compareMakeAndModelFunctor> carsSubset2;
    carsSubset2.insert(carsByMakeAndModel.upper_bound(Car("T","",0,200)), carsByMakeAndModel.end());
    printDataStructure<set<Car, compareMakeAndModelFunctor> >(carsSubset2);

    // set union
    set<Car> carsSubset3;
    carsSubset3.insert(carsSubset.begin(), carsSubset.end());
    carsSubset3.insert(carsSubset2.begin(), carsSubset2.end());
    printDataStructure<set<Car> >(carsSubset3);

    // set intersection
    //  to use set_intersection with vector: initialize to proper size, write default constructor for Car
    vector<Car> carsSubset4(carsSubset.size() + carsSubset2.size() - carsSubset3.size());
     set_intersection(carsSubset.begin(), carsSubset.end(),
                      carsSubset2.begin(), carsSubset2.end(),
                      carsSubset4.begin());
    printDataStructure<vector<Car> >(carsSubset4);

    return 0;
}