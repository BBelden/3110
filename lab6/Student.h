// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
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

// derived class of Person, inheriting all public methods
class Student : public Person {
    
public:
    // get and set methods
    void setYear(int& inYear) { sYear = inYear; }
    void setMajor(std::string& inMajor) { sMajor = inMajor; }
    void setAll(std::string& inKey, int& inMnum, std::string& inEmail, int& inYear, std::string& inMajor);
    int getYear() { return sYear; }
    std::string getMajor() { return sMajor; }
    void print();
    
private:
    //  data members
    int sYear;
    std::string sMajor;
};

#endif
