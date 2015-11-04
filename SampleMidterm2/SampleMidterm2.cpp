#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

template <typename T> void printDataStructure(T const &cars){
    for(typename T::const_iterator it = cars.begin();
        it != cars.end();
        it++){
        cout << *it << "\n";
    }
    cout << endl;
}

template <typename T> void printMap(T const &cars){
    for(typename T::const_iterator it = cars.begin();
        it != cars.end();
        it++){
        cout << "[" << (*it).first << "] " << (*it).second << "\n";
    }
    cout << endl;
}



/*** Returns the product of a and b ***/
int multiply(int a, int b) {
    int result = 0;
    for(int i=0; i<b; i++){
        result += a;
    }
    return result;
}


/*** Returns a vector with 1’s in every position except at index it contains value.
 * Functionality is considered proper if a vector is returned with value at index
 * and 1’s in all other positions regardless of the size of the vector. ***/

vector<int> mostlyOnes(int index, int value) {
    int n = index + 10; // make sure there’s enough room in the vector
    vector<int> lotsOfOnes;
    for(int i=0; i<n; i++){
        lotsOfOnes.push_back(1);
    }
    lotsOfOnes.insert(lotsOfOnes.begin()+index, value);
    return lotsOfOnes;
}

/*** Inserts values into a set and returns the size of the set. ***/

int setInsertions(int n, int toInsert) {
    set<int> setOfInts;
    setOfInts.insert(toInsert);
    int sizeOfSet = 1;
    for(int i=-15; i<n; i++){
        setOfInts.insert(i);
        sizeOfSet++;
    }
    cout << "expected: " << setOfInts.size() << endl;
    return sizeOfSet;
}

/*** checks if the input is a proper month in the format "MM/YYYY" ***/
bool parseDate(string date)
{
    if(date.length() != 7){
        return false;
    }
    int firstSlash = date.find_first_of("/");
    int lastSlash = date.find_last_of("/");
    if(firstSlash == -1 || lastSlash == -1 || firstSlash != lastSlash){
        return false;
    }

    string monthString = date.substr(firstSlash-2, 2);
    if(!(isdigit(monthString[0]) && isdigit(monthString[1]))){
        return false;
    } else if(stoi(monthString) > 12 || stoi(monthString) == 0){
        return false;
    }

    string yearString = date.substr(lastSlash+1, 4);
    if(!(isdigit(yearString[0]) && isdigit(yearString[1])
         && isdigit(yearString[2]) && isdigit(yearString[3]))){
        return false;
    }

    return true;
}

void sample2a(){
    cout << "2a: " << endl;
    string input;
    while (getline(cin, input)){
        try{
            int a = stoi(input.substr(0,input.find_first_of(" ")));
            int b = stoi(input.substr(input.find_first_of(" ")+1));
            cout << "expected: " << (a*b) << endl;
            cout << "result:   " << multiply(a, b) << endl;
        }
        catch (const exception& ex) {
            cout << "invalid input: this does not count as breaking the function" << endl;
        }
    }
}

void sample2b(){
    cout << "2b: " << endl;
    string input;
    while (getline(cin, input)){
        try{
            int index = stoi(input.substr(0,input.find_first_of(" ")));
            int value = stoi(input.substr(input.find_first_of(" ")+1));
            vector<int> result = mostlyOnes(index, value);
            cout << "result: " << endl;
            printDataStructure<vector<int> >(result);
        }
        catch (const exception& ex) {
            cout << "invalid input: this does not count as breaking the function" << endl;
        }
    }
}


void sample2c(){
    cout << "2c: " << endl;
    string input;
    while (getline(cin, input)){
        try{
            int n = stoi(input.substr(0,input.find_first_of(" ")));
            int toInsert = stoi(input.substr(input.find_first_of(" ")+1));
            int result = setInsertions( n, toInsert);
            cout << "ouput: " << result << endl;
        }
        catch (const exception& ex) {
            cout << "invalid input: this does not count as breaking the function" << endl;
        }
    }
}

void sample2d(){
    cout << "2d: " << endl;
    string date;
    while (getline(cin, date)){
        cout << (parseDate(date) ? "true" : "false") << endl;
    }
}


class Car {
public:
    string make;
    double weight;
    int hp;

    Car(string make, double weight, int hp) :
            make(make), weight(weight), hp(hp) {}
};

bool operator<(const Car& car1, const Car& car2){
    return car1.make < car2.make;
}

ostream& operator<<(ostream &stream, const Car &car) {
    return stream << car.make << ": " << car.weight << "kg " << car.hp << "hp";
}

class WeightComparator{
public:
    bool operator()(const Car &car1, const Car &car2){
        return car1.hp < car2.hp;
    }
};

class HPComparator{
public:
    bool operator()(const Car &car1, const Car &car2){
        return car1.hp < car2.hp;
    }
};



void sample3a(){
    cout << "3a: " << endl;
    set<Car> cars;

    cars.insert(Car("Subaru", 1480, 415));
    cars.insert(Car("Toyota", 980, 188));
    cars.insert(Car("Audi", 1620, 415));
    cars.insert(Car("Toyota", 950, 152));
    cars.insert(Car("Acura", 1480, 188));
    cars.insert(Car("Audi", 1650, 622));

    printDataStructure<set<Car> >(cars);
}

void sample3b(){
    cout << "3b: " << endl;
    set<Car, HPComparator> cars;

    cars.insert(Car("Subaru", 1480, 415));
    cars.insert(Car("Toyota", 980, 188));
    cars.insert(Car("Audi", 1620, 415));
    cars.insert(Car("Toyota", 950, 152));
    cars.insert(Car("Acura", 1480, 188));
    cars.insert(Car("Audi", 1650, 622));

    printDataStructure<set<Car, HPComparator> >(cars);
}

void sample3c(){
    cout << "3c: " << endl;
    map<Car, int> cars;

    cars.insert(make_pair(Car("Subaru", 1480, 415), 415));
    cars.insert(make_pair(Car("Toyota", 980, 188), 188));
    cars.insert(make_pair(Car("Audi", 1620, 415), 415));
    cars.insert(make_pair(Car("Toyota", 950, 152), 152));
    cars.insert(make_pair(Car("Acura", 1480, 188), 188));
    cars.insert(make_pair(Car("Audi", 1650, 622), 622));

    printMap<map<Car, int> >(cars);
}

int main(){

    sample2a();
//    sample2b();
//    sample2c();
//    sample2d();

//    sample3a();
//    sample3b();
//    sample3c();

    return 0;
}