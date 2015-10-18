#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Employee.h"
#include "Filter.h"
using namespace std;


void getUserInput(vector <vector<Employee *> *>  &sortedByDataFieldVector);

int main(int argc, char *argv[])
{
   if (argc != 5)
   {
      // We print argv[0] assuming it is the program name
      cout << "usage: " << argv[0] << " <input filename>  <output filename> <Sorted By> <Is Ascending> \n";
      cout << "Sorted By: Name => 0 ; Status => 1; SALARY => 2, PAY_BASIS => 3 POSITION => 4 " << endl;
      cout << "Sample : " << argv[0] << " 2014.csv  2014_Salary_Asc.rpt 2 1 \n";
      cout << " The earlier command creates a report file 2014_Salary_Asc.rpt from 2014.csv." << endl
         << " The output is sorted based on Salary (2) in ascending order (1)" << endl;
      exit(0);
   }

   ifstream inputFile;
   ofstream outputFile;

   // We assume argv[1] is a filename to open for input
   inputFile.open(argv[1]);
   // We assume argv[2] is a filename to open for output
   outputFile.open(argv[2]);
   // argv[3] is sorted by
   DATA_FIELDS sortedBy = DATA_FIELDS(atoi(argv[3]));

   bool isAscending = atoi(argv[4]);

   // Always check to see if file opening succeeded
   if (!inputFile.is_open())
   {
      cout << "Could not open the input file \n";
      exit(0);
   }
   // Always check to see if file opening succeeded
   if (!outputFile.is_open())
   {
      cout << "Could not open the output file \n";
      exit(0);
   }

   if ((sortedBy > 4) || (sortedBy < 0))
   {
      cout << "Try again" << endl;
      cout << "usage: " << argv[0] << " <input filename>  <outputasc filename> <Sorted By> <Is Ascending> <\n";
      cout << "Sorted By: Name => 0 ; Status => 1; SALARY => 2, PAY_BASIS => 3 POSITION => 4 " << endl;
      exit(0);
   }

   string lineFromFile;
   getline(inputFile, lineFromFile);

   vector<Employee *> employeeVector;

   while (getline(inputFile, lineFromFile))
   {
      Employee *pEmployee = new Employee(lineFromFile);
      employeeVector.push_back(pEmployee);
   }

   // TODO: Part 2. Perform the sorting based on the criteria passed
   // Add functionality to Employee.h. 
   // i.e., write code for operator()
   CompareClass compareClass(sortedBy, isAscending);
   std::sort(employeeVector.begin(), employeeVector.end(), compareClass);
 

   outputFile << getEmployeeFileHeader();
   for (size_t i = 0; i < employeeVector.size(); i++)
   {
      outputFile << *(employeeVector[i]);
   }
   outputFile.close();

   vector <vector<Employee *> *>  sortedByDataFieldVector;

   for (int i = NAME; i <= POSITION; i++)
   {
      vector <Employee *> *pEmployeeVector = new vector <Employee *>(employeeVector.begin(), employeeVector.end());
      CompareClass compareClass(static_cast<DATA_FIELDS>(i));
      std::sort(pEmployeeVector->begin(), pEmployeeVector->end(), compareClass);
      sortedByDataFieldVector.push_back(pEmployeeVector);
   }

   while (true)
   {
      // NOTE: Don't modify this function
      getUserInput(sortedByDataFieldVector);

   }

   int x = 8;

}


unsigned get_uint_as_Input()
{
   unsigned int userInput;
   //executes loop if the input fails (e.g., no characters were read)
   while (!(cin >> userInput)) {
      std::cin.clear(); //clear bad input flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
      std::cout << "Invalid input; please re-enter.\n";
   }
   return userInput;
}

void getUserInput(vector <vector<Employee *> *>  &sortedByDataFieldVector)
{
   cout << "Enter your choice" << endl;
   cout << "1. New query" << endl;
   cout << "2. Quit" << endl;

   unsigned int userInput = get_uint_as_Input();
   if (userInput != 1)
   {
      exit(0);
   }

   unsigned int filterType = FIRST;

   Filter *pNewFilter = NULL;

   while (filterType != END)
   {

      cout << " Filter on " << endl;
      cout << " 0. NAME" << endl;
      cout << " 1. STATUS" << endl;
      cout << " 2. SALARY" << endl;
      cout << " 3. PAY_BASIS" << endl;
      cout << " 4. POSITION" << endl;
      cout << " 5. RETURN" << endl;

      userInput = get_uint_as_Input();

      if (userInput > 4)
      {
         return;
      }


      cout << "Select Condition" << endl;

      cout << "0. IS_EQUAL" << endl;
      cout << "1. BETWEEN" << endl;
      cout << "2. GREATER" << endl;
      cout << "3. LESS" << endl;
      cout << "4. RETURN" << endl;

   
      int userCondition = get_uint_as_Input();

      if (userCondition >  3)
      {
         return;
      }

      string rangeStart = "";
      string rangeEnd = "";

      if (userCondition == 1)
      {
         cout << "Insert start and end of range: ";
         cin >> rangeStart >> rangeEnd;
         if (rangeStart > rangeEnd)
         {
            cout << "Start range cannot be greater than End range" << endl;
            return;
         }
      }
      else
      {
         cout << "Insert value: ";
         cin >> rangeStart;
      }

      if (filterType == FIRST)
      {
         if (pNewFilter != NULL)
         {
            delete pNewFilter;
         }
         pNewFilter  = new Filter(sortedByDataFieldVector[userInput], static_cast<DATA_FIELDS>(userInput), static_cast<SELECTION_CRITERIA>(userCondition), make_pair(rangeStart, rangeEnd));
      }
      else
      {
         pNewFilter->addFilter(sortedByDataFieldVector[userInput], static_cast<DATA_FIELDS>(userInput), static_cast<SELECTION_CRITERIA>(userCondition), make_pair(rangeStart, rangeEnd), static_cast<FILTER_TYPE>(filterType));
      }
      
      pNewFilter->printFilter();

      cout << "Add more filters to the existing one? " << endl;
      cout << "1. OR filter " << endl;
      cout << "2. AND filter " << endl;
      cout << "3. End the current filter and display " << endl;

      filterType = get_uint_as_Input();

      if (filterType > 2)
      {
         filterType = END;
         cout << "====================================================================================================================================\n";
         pNewFilter->printFilter();
         cout << "====================================================================================================================================\n";
      }

   }


}

