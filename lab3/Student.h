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
// File:       Student.h
//
// This is the header file of the Student class.

#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// derived class of Person, inheriting all public methods
class Student : public Person {
    
public:
    // default constructor
    Student();
    
    // get and set methods
    void setYear(int);
    void setMajor(string);
    void setAll(string, int, string, int, string);
    int getYear();
    string getMajor();
    
    // *** polymorphic method ***
    void print();
    
private:
    //  data members
    int sYear;
    string sMajor;
};

#endif
