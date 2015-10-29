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
// File:       Person.h
//
// This is the header / implementation file of the Person class.

#ifndef PERSON_H
#define PERSON_H
#pragma once

#include <iostream>
#include "KeyedItem.h"

// abstract derived class, inheriting from KeyedItem
class Person : public KeyedItem{
    
public:    
    // get and set methods
    void setMnum(int inMnum) { pMnum = inMnum; }
    void setEmail(std::string inEmail){ pEmail=inEmail; }
    int getMnum() { return pMnum; }
    std::string getEmail() { return pEmail; }
    
 protected:
    // data members
    int pMnum;
    std::string pEmail;
};

#endif
