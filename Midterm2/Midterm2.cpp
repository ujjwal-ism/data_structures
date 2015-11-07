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

double multiply(int a, int b) {
    return 1.0*((a+b)*a*b)/(a+b);
}


/*** Creates a vector and inserts value into it. Returns true if
 *    value was successfully added to the vector, false otherwise ***/

bool insertAndFind(int value) {
    vector<int> numbers(101);
    for(int i=-50; i<50; i++){
        numbers.push_back(i);
    }
    numbers.insert(numbers.begin(), value);
    return binary_search(numbers.begin(), numbers.end(), value);
}

/*** Creates a set and adds toInsert into it n times. Returns true if
 *    toInsert was successfully added to the set, false otherwise ***/

int setInsertions(int n, int toInsert) {
    set<int> setOfInts;
    int timeRunner = 0;
    for(int i=0; i<n; i++){
        setOfInts.insert(toInsert);
        for(int j=0; j<setOfInts.size(); j++){
            timeRunner++;
        }
    }
    return true;
}

/*** checks if the input is a proper IP address in the format
 *    "192.168.0.0". More specifically, it must be 4 integers
 *    that can range from 0-255 and separated by '.'***/

bool parseIP(string ip)
{
    for(int i=0; i<3; i++){
        int firstDot = ip.find_first_of(".");
        string value = ip.substr(0,firstDot);
        for(int j=0; j<value.length(); j++){
            if(!isdigit(value[j])){
                return false;
            }
        }
        if(stoi(value) > 255 || stoi(value) < 0){
            return false;
        }
        ip.erase(0, firstDot+1);
    }

    for(int j=0; j<ip.length(); j++){
        if(!isdigit(ip[j])){
            return false;
        }
    }
    return !(stoi(ip) > 255 || stoi(ip) < 0);
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
            int value = stoi(input.substr(0,input.find_first_of(" ")));
            bool result = insertAndFind(value);
//            cout << "expected: " << value << endl;
            cout << "result:   " << result << endl;
//            printDataStructure<vector<int> >(result);
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
    string ip;
    while (getline(cin, ip)){
        cout << (parseIP(ip) ? "true" : "false") << endl;
    }
}




class Employee{
public:
    Employee(string name, int salary) :
            name_(name), salary_(salary){}

    string name_;
    int salary_;
};

bool operator<(const Employee& employee1, const Employee& employee2){
    return employee1.name_ < employee2.name_;
}

ostream& operator<<(ostream &stream, const Employee &employee) {
    return stream << employee.name_ << ": " << employee.salary_;
}

class SalaryComparator{
public:
    bool operator()(const Employee &employee1, const Employee &employee2){
        return employee1.salary_ < employee2.salary_;
    }
};




void sample3a(){
    cout << "3a: " << endl;


    set<Employee> employees;

    employees.insert(Employee("Zhang Li", 1250000));
    employees.insert(Employee("Anaya", 45000));
    employees.insert(Employee("Jacqueline",45000));
    employees.insert(Employee("Anaya", 55000));
    employees.insert(Employee("Rachel",125000));
    employees.insert(Employee("Anaya", 65000));
    employees.insert(Employee("Myra", 80000));
    employees.insert(Employee("Zhang Li", 125000));

    printDataStructure<set<Employee> >(employees);
}

void sample3b(){
    cout << "3b: " << endl;

    set<Employee, SalaryComparator> employees;

    employees.insert(Employee("Zhang Li", 1250000));
    employees.insert(Employee("Anaya", 45000));
    employees.insert(Employee("Jacqueline",45000));
    employees.insert(Employee("Anaya", 55000));
    employees.insert(Employee("Rachel",125000));
    employees.insert(Employee("Anaya", 65000));
    employees.insert(Employee("Myra", 80000));
    employees.insert(Employee("Zhang Li", 125000));

    printDataStructure<set<Employee, SalaryComparator> >(employees);
}

void sample3c(){
    cout << "3c: " << endl;

    map<int, Employee> employees;

    employees.insert(make_pair(1250000,Employee("Zhang Li", 1250000)));
    employees.insert(make_pair(45000,Employee("Anaya", 45000)));
    employees.insert(make_pair(45000,Employee("Jacqueline",45000)));
    employees.insert(make_pair(55000,Employee("Anaya", 55000)));
    employees.insert(make_pair(125000,Employee("Rachel",125000)));
    employees.insert(make_pair(65000,Employee("Anaya", 65000)));
    employees.insert(make_pair(80000,Employee("Myra", 80000)));
    employees.insert(make_pair(125000,Employee("Zhang Li", 125000)));

    printMap<map<int, Employee> >(employees);
}

int main() {

    sample2a();
//    sample2b();
//    sample2c();
//    sample2d();

//    sample3a();
//    sample3b();
//    sample3c();

    return 0;
}