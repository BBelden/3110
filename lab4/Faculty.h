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
// File:       Faculty.h
//
// This is the header file of the Faculty class.

#ifndef FACULTY_H
#define FACULTY_H
#pragma once

#include <iostream>
#include "KeyedItem.h"

// derived class of Person, inheriting all public methods
class Faculty : public Person {
    
public:
    // get and set methods
    void setDept(std::string& inDept) { fDept = inDept; }
    void setTenure(bool& inTenure) { fTenure = inTenure; }
    void setAll(std::string& inKey, int& inMnum, std::string& inEmail, std::string& inDept, bool& inTenure);
    std::string getDept() { return fDept; }
    bool getTenure() { return fTenure; }
    void print();
    
private:
    // data members
    std::string fDept;
    bool fTenure;
};

#endif
