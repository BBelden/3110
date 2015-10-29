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
// File:       Administrator.h
//
// This is the header file of the Administrator class.

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#pragma once

#include <iostream>
#include <string>
#include "Person.h"
#include "RecordsOffice.h"

using namespace std;

// derived class of Person, inheriting all public methods
class Administrator : public Person {
    
public:
    // default constructor
    Administrator();
    
    // get and set methods
    void setTitle(string);
    void setAll(string, int, string, string);
    string getTitle();
    
    // *** polymorphic method ***
    void print();
    
private:
    // data member
    string aTitle;
};

#endif
