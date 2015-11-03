#include "Interpreter.h"



void Interpreter::interpretScript(ifstream& inputFile, ofstream& outputFile){

    string lineFromFile;

    int lineNumber = 0;

    while (getline(inputFile, lineFromFile))
    {
        lineNumber++;
        LINE_TYPE lineType = getLineType(lineFromFile); // Check Parser.h for the different line types
        cout << "line " << lineNumber << " is type: " << lineType << endl;
        // Use your interpreter to execute each line
    }

    // write the result from the return statement of the program into the output file
    outputFile << "output of the document.write lines";

}

