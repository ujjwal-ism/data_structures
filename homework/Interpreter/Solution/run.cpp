#include "run.h"


int main(int argc, char *argv[]){

    if (argc != 3)
    {
        cout << "usage: " << argv[0] << " <input filename> <output filename>" << endl;
        exit(0);
    }

    ifstream inputFile;
    inputFile.open(argv[1]);
    if (!inputFile.is_open())
    {
        cout << "Could not open the input file \n";
        exit(0);
    }

    ofstream outputFile;
    outputFile.open(argv[2]);
    if (!outputFile.is_open())
    {
        cout << "Could not open the output file \n";
        exit(0);
    }


    Interpreter interpreter;
    interpreter.interpretScript(inputFile, outputFile);


    return 0;
}