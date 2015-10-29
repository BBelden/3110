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
// File:       Faculty.h
//
// This is the header file of the Faculty class.

#ifndef FACULTY_H
#define FACULTY_H
#pragma once

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// derived class of Person, inheriting all public methods
class Faculty : public Person {
    
public:
    // default constructor
    Faculty();
    
    // get and set methods
    void setDept(string);
    void setTenure(bool);
    void setAll(string, int, string, string, bool);
    string getDept();
    bool getTenure();
    
    // *** polymorphic method ***
    void print();
    
private:
    // data members
    string fDept;
    bool fTenure;
};

#endif
