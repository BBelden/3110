// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab6: 2-3-4 Tree
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       lab6-main.cpp
//
// This is the client file of the project.

#include <iostream>
#include <string>
#include "RecordsOffice.h"

int main(){ //int argc, char* argv[]){
    
    //std::string commandsFileName = "lab6-commands-short.tab"; // for initial development
    std::string commandsFileName = "lab6-commands.tab";
    //std::string commandsFileName = "lab6-commands-test.tab"; // for testing & grading   
    RecordsOffice records;
    std::cout << "Importing " << commandsFileName << std::endl;
    records.importRecords(commandsFileName);
    
    return 0;
}