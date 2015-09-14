cmake_minimum_required(VERSION 3.3)
project(cse250-fall2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/DataStructure.cpp src/DataStructure.h lecturenotes/pointersandreferences/PointerExample.cpp lecturenotes/pointersandreferences/PointerExample.h 0-FirstTaste/FirstTaste.cpp 0-FirstTaste/FirstTaste.h 1-BasicSyntax/Syntax.cpp 1-BasicSyntax/Syntax.h 1-BasicSyntax/FirstFunction.cpp 1-BasicSyntax/FirstFunction.h 1-BasicSyntax/StringFunction.cpp 1-BasicSyntax/StringFunction.h 2-PointersReferences/DictionaryReader.cpp 2-PointersReferences/DictionaryReader.h 3-Objects/FirstClass.cpp 3-Objects/FirstClass.h 3-Objects/Run.cpp 3-Objects/Main.h homework/hw2/PalindromeFinder.cpp homework/hw2/PalindromeFinder.h homework/hw2/run.cpp.cpp homework/hw2/run.cpp.h homework/hw2/run.cpp homework/hw2/run.h 2-PointersReferences/Pointers.cpp 2-PointersReferences/Pointers.h homework/hw2/ccccc.cpp homework/hw2/ccccc.h homework/hw2/hw2.cpp homework/hw2/hw2.h homework/hw2/Palindrome.cpp homework/hw2/Palindrome.h)
add_executable(cse250-fall2015 ${SOURCE_FILES} src/DataStructure.cpp src/DataStructure.h)