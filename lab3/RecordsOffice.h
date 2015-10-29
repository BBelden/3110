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
// File:       RecordsOffice.h
//
// This is the header file of the RecordsOffice class.

#ifndef RECORDSOFFICE_H
#define RECORDSOFFICE_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Administrator.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

class RecordsOffice {
    
public:
    RecordsOffice();  // default constructor
    void importRecords(string);  // reads in and executes commands from a file
    
private:
    vector < Person* > theNewHotness; // STL list of type Person*
    //vector < Person* >::iterator itr; // iterator
};

#endif
