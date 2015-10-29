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
// File:       Administrator.cpp
//
// This is the implemenataion file of the Administrator class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Administrator.h"

using namespace std;

// Method:      default constructor
// Purpose:     instantiate an object of the Administrator class
// Pre-cond:    none
// Post-cond:   object instantiated
Administrator::Administrator(){}

//************************************************************************************************

// Method:      setTitle
// Purpose:     sets the "aTitle" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Administrator::setTitle(string inTitle){
    aTitle = inTitle;
}  // end setTitle

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Administrator object at once by calling all
//              individual set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Administrator::setAll(string inName, int inMnum, string inEmail, string inTitle)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setTitle(inTitle);
}  // end setAll

//************************************************************************************************

// Method:      getTitle
// Purpose:     called to access data member "aTitle"
// Pre-cond:    data member "aTitle" has a value
// Post-cond:   returns "aTitle"
string Administrator::getTitle(){
    return aTitle;
}  // end setAll

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Administrator object to terminal
// Pre-cond:    Administrator object exists
// Post-cond:   data from Student object printed to terminal
void Administrator::print(){
    cout << "Administrator:\n";
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tTitle:\t\t" << getTitle() << endl << endl;
	return;
}  // end print
