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
// File:       RecordsOffice.h
//
// This is the header file of the RecordsOffice class.

#include <iostream>
#ifndef RECORDSOFFICE_H
#define RECORDSOFFICE_H
#pragma once

#include "HashTable.h"

class RecordsOffice {
    
public:
    void importRecords(std::string& fileName);  // reads in and executes commands from a file

private:
    HashTable* newerHotness;
};

#endif
