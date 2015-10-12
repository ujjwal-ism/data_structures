#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

enum DATA_FIELDS
{
	NAME, STATUS, SALARY, PAY_BASIS, POSITION
};

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

std::ostream& operator<<(std::ostream &strm, const Employee &emp);

std::string getEmployeeFileHeader();
#endif
