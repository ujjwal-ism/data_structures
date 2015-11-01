#include "Interpreter.h"



void interpretScript(ifstream inputFile, ofstream outputFile){

    while (getline(inputFile, lineFromFile))
    {
        LINE_TYPE lineType = getLineType(lineFromFile); // Check Parser.h for the different line types
        // Use your interpreter to execute each line
    }

    // write the result from the return statement of the program into the output file
    outputFile << "output of the document.write lines";

}