#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>



class Employee{
	public:
		Employee();
		Employee(std::string  fileLine);
		
		void setField(DATA_FIELDS dataField, std::string value);

		std::string name_;
		std::string status_;
		double salary_;
		std::string payBasis_;
		std::string positionTitle_;

	friend std::ostream& operator<<(std::ostream&, const Employee&);

};

class CompareClass
{
public:
   CompareClass(DATA_FIELDS dataField, bool isAscending=true) : dataField_(dataField), isAscending_(isAscending){}
   // TODO: Part2: implement the overloaded () operator. 
   bool operator() (Employee *pX, Employee *pY) {

      return true;
   }
private:
   DATA_FIELDS dataField_;
   bool isAscending_;
};

std::ostream& operator<<(std::ostream &strm, const Employee &emp);

std::string getEmployeeFileHeader();

enum DATA_FIELDS
{
	NAME, STATUS, SALARY, PAY_BASIS, POSITION
};


#endif
