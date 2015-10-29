// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab3: Records Office III
// Due:        22:00:00, October 7, 2013
// Purpose:    Continuation of lab1 and lab2, addition of an abstract base class. Practice
//             using inheritance and polymorphism, and implementation of STL container and
//             iterators.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       lab3-main.cpp
// 
// This is the client file of the project.

#include <iostream>

using namespace std;

#include "RecordsOffice.h"

int main(){ //int argc, char* argv[]){
    //string commandsFileName = "lab3-commands-short.tab"; // for initial development
    string commandsFileName = "lab3-commands.tab";
    //string commandsFileName = "lab3-commands-test.tab"; // for testing & grading

    RecordsOffice records;
    cout << "Importing " << commandsFileName << endl;
    records.importRecords(commandsFileName);
    return 0;
}
