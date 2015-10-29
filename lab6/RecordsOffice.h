// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       RecordsOffice.h
//
// This is the header file of the RecordsOffice class.

#include <iostream>
#include <string>
#ifndef RECORDSOFFICE_H
#define RECORDSOFFICE_H
#pragma once

#include "TwoThreeFourTree.h"

class RecordsOffice {
    
public:
    void importRecords(std::string& fileName);  // reads in and executes commands from a file
    
private:
    TwoThreeFourTree* newestHotness;
};

#endif
