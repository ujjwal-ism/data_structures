#include "UserFunction.h"


double UserFunction::call(vector<double>& arguments,
                          map<string, double>& varMap,
                          map<string, UserFunction>& funMap,
                          ofstream* outFile){

    Interpreter functionInterpreter;
    functionInterpreter.functionMap.insert(funMap.begin(), funMap.end());
    functionInterpreter.variableMap.insert(varMap.begin(), varMap.end());
    functionInterpreter.outFile = outFile;

    for(int i=0; i<arguments.size(); i++){
        functionInterpreter.variableMap.insert(make_pair(parameterNames[i],arguments[i]));
    }

    for(int i=0; i<functionDefinition.size(); i++){
        string line = functionDefinition[i];
        functionInterpreter.interpretLine(line);
        if(functionInterpreter.foundReturn){
            return functionInterpreter.toReturn;
        }
    }
    return 0.0; // functions that return void return 0.0
}