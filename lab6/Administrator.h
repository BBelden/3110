// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
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
#include "KeyedItem.h"
#include "RecordsOffice.h"

// derived class of Person, inheriting all public methods
class Administrator : public Person {
    
public:
    // get and set methods
    void setTitle(std::string& inTitle) { aTitle = inTitle; }
    void setAll(std::string& inKey, int& inMnum, std::string& inEmail, std::string& inTitle);
    std::string getTitle() { return aTitle; }
    void print();
    
private:
    // data member
    std::string aTitle;
};

#endif
