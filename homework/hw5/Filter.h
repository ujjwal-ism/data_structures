#ifndef __FILTER_H__
#define __FILTER_H__
#include <set>
#include "Employee.h"
#include <vector>
#include <algorithm>

using namespace std;
// NOTE: Don't change the ENUMs. 
// Y
enum SELECTION_CRITERIA
{
	IS_EQUAL,
	BETWEEN,
	GREATER,
	LESS,
};

enum FILTER_TYPE
{
	FIRST,
	OR,
	AND,
	END,

};

class Filter{
public:
   // NOTE: You are not allowed to modify the function signature of the following three functions;
   // constructor
	Filter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit);
	
   /******
    * calls setValues and extractData methods
    * ********/
	void addFilter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit, FILTER_TYPE filterType);
   
   /******
    * Prints the entries stored in pEmpVector_
    * ****/
   void printFilter();

private:

	DATA_FIELDS field_;
	DATA_FIELDS firstField_; // To check how to sort! For OR or AND filters, remembers the sorting for the first filter.
	SELECTION_CRITERIA selectCrit_;
	vector<Employee *> *pEmpVector_;

};

#endif
