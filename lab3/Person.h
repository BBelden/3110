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
// File:       Person.h
//
// This is the header file of the Person class.

#ifndef PERSON_H
#define PERSON_H
#pragma once

#include <iostream>
#include <string>

using namespace std;

// abstract base class
class Person {
    
public:
    Person();  // default constructor
    
    // base class get and set methods
    void setName(string);
    void setMnum(int);
    void setEmail(string);
    string getName();
    int getMnum();
    string getEmail();
    
    // *** pure virtual method ***
    virtual void print()=0;
    
protected:
    // base class data members
    string pName;
    int pMnum;
    string pEmail;
};

#endif
