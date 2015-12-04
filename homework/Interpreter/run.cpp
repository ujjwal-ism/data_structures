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


    sampleUsage();

    return 0;
}


void sampleUsage(){

    // Some example usage of the provided functions.
    // Feel free to use and modify this code to get started on the assignment.
    // We provide most of the string parsing code so you can focus on the data structures and logic.

    string worldlyString = "Hello there world!";

    vector<string> tokens = tokenize(worldlyString, " ");

    for(int i=0; i<tokens.size(); i++){
        cout << tokens.at(i) << endl;
    }
    cout << tokens.size() << endl << endl;

    string line = "var aVariableName =2+15 *(62 - anotherVariableName)*10";

    vector<string> splitLine = tokenize(line, "=");
    if(splitLine.size() > 2 || splitLine.size() < 1){
        // not a valid expression
    }else if(splitLine.size() == 2){
        // line with an assignment
        string lhs = splitLine.at(0);
        string rhs = splitLine.at(1);
        cout << "left hand side: " << endl;
        while(lhs.size() != 0){
            cout << getNextSymbol(lhs) << endl;
        }
        cout << endl << "right hand side: " << endl;
        while(rhs.size() != 0){
            cout << getNextSymbol(rhs) << endl;
        }
    }else{
        // line without an assignment
    }


    cout << endl;
    cout << "expected 1: " << isdigit('5') << endl;
    cout << "expected 1: " << isNumber("5") << endl;
    cout << "expected 1: " << isNumber("50.11") << endl;
    cout << "expected 1: " << isNumber(".000554325") << endl;
    cout << "expected 1: " << isNumber("53241.") << endl;
    cout << "expected 1: " << isNumber("53241.") << endl;
    cout << "expected -1: " << isNumber("") << endl;
    cout << "expected 0: " << isNumber("alphabet") << endl;
    cout << "expected 0: " << isNumber("these are words") << endl;
    cout << "expected 0: " << isNumber("5134589723452345a") << endl;
    cout << "expected 0: " << isNumber("a5134589723452345") << endl;
    cout << "expected 0: " << isNumber("5134589a723452345") << endl;
    cout << "expected 1: " << isNumber("5134589723452345") << endl;
    cout << "expected 0: " << isNumber("5134589723452345..") << endl;
    cout << "expected 0: " << isNumber("..5134589723452345") << endl;
    cout << "expected 0: " << isNumber("513.458972345.2345") << endl;
    cout << "expected 0: " << isNumber("513.4589723452345.") << endl;
    cout << "expected 0: " << isNumber(".513458972345.2345") << endl;

}
