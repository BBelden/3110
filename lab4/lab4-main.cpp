// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 4, 2013
// Purpose:    Continuation of labs 1, 2 and 3, addition of a hash table. Utilizes separate chaining
//             as a collision resolution system.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       lab3-main.cpp
//
// This is the client file of the project.

#include <iostream>
#include <string>

#include "RecordsOffice.h"

int main(){ //int argc, char* argv[]){
    //string commandsFileName = "lab4-commands-short.tab"; // for initial development
    std::string commandsFileName = "lab4-commands.tab";
    //string commandsFileName = "lab4-commands-test.tab"; // for testing & grading
    //string commandsFileName = "/Users/migration/Desktop/xCode/ADS/lab4/lab4/lab4-commands-short.tab";
   // string commandsFileName = "/Users/migration/Desktop/xCode/ADS/lab4/lab4/lab4-commands.tab";
    
    RecordsOffice records;
    std::cout << "Importing " << commandsFileName << std::endl;
    records.importRecords(commandsFileName);
    
    return 0;
}