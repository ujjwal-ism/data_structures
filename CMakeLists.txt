cmake_minimum_required(VERSION 3.3)
project(cse250-fall2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/DataStructure.cpp src/DataStructure.h lecturenotes/pointersandreferences/PointerExample.cpp lecturenotes/pointersandreferences/PointerExample.h 0-FirstTaste/FirstTaste.cpp 0-FirstTaste/FirstTaste.h 1-BasicSyntax/Syntax.cpp 1-BasicSyntax/Syntax.h 1-BasicSyntax/FirstFunction.cpp 1-BasicSyntax/FirstFunction.h)
add_executable(cse250-fall2015 ${SOURCE_FILES} src/DataStructure.cpp src/DataStructure.h)