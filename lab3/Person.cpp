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
// File:       Person.cpp
//
// This is the implementation file of the Person class.

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// Method:      default constructor
// Purpose:     instantiate an object of the Person class
// Pre-cond:    none
// Post-cond:   object instantiated
Person::Person(){}

//************************************************************************************************

// Method:      setName
// Purpose:     sets the "pName" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Person::setName(string inName){
    pName = inName;
}  // end setName

//************************************************************************************************

// Method:      setMnum
// Purpose:     sets the "pMnum" data member
// Pre-cond:    int is passed in
// Post-cond:   data member is set
void Person::setMnum(int inMnum){
    pMnum = inMnum;
}  // end setMnum

//************************************************************************************************

// Method:      setEmail
// Purpose:     sets the "pEmail" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Person::setEmail(string inEmail){
    pEmail = inEmail;
}  // end setEmail

//************************************************************************************************

// Method:      getName
// Purpose:     called to access data member "pName"
// Pre-cond:    data member "pName" has a value
// Post-cond:   returns "pName"
string Person::getName(){
    return pName;
}  // end getName

//************************************************************************************************

// Method:      getMnum
// Purpose:     called to access data member "pMnum"
// Pre-cond:    data member "pMnum" has a value
// Post-cond:   returns "pMnum"
int Person::getMnum(){
    return pMnum;
}  // end getMnum

//************************************************************************************************

// Method:      getEmail
// Purpose:     called to access data member "pEmail"
// Pre-cond:    data member "pEmail" has a value
// Post-cond:   returns "pEmail"
string Person::getEmail(){
    return pEmail;
}  // end getEmail
