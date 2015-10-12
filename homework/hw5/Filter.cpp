#include <iostream> 
#include "Filter.h"

using namespace std;


Filter::Filter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit):
field_(field), firstField_(field), selectCrit_(selectCrit)
{
   // Modify or add code as requried. Even the next line!
	pEmpVector_ = pEmpVector;  

}

void Filter::printFilter()
{
   cout << getEmployeeFileHeader();
	for (size_t i = 0; i < pEmpVector_->size(); i++)
	{
		cout << *(pEmpVector_->at(i));
	}
}


void Filter::addFilter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit, FILTER_TYPE filterType)
{

}
