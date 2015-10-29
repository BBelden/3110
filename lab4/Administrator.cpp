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
// File:       Administrator.cpp
//
// This is the implemenataion file of the Administrator class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Administrator.h"

// Method:      setAll
// Purpose:     sets all the data members of Administrator object at once by calling all
//              individual set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Administrator::setAll(std::string& inKey, int& inMnum, std::string& inEmail, std::string& inTitle)
{
    setKey(inKey);
    setMnum(inMnum);
    setEmail(inEmail);
    setTitle(inTitle);
}  // end setAll

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Administrator object to terminal
// Pre-cond:    Administrator object exists
// Post-cond:   data from Student object printed to terminal
void Administrator::print(){
    std::cout << "Administrator:\n";
	std::cout << "\tFull Name:\t" << getKey()<< std::endl;
	std::cout << "\tM Number:\t" << getMnum() << std::endl;
	std::cout << "\tEmail Addr:\t" << getEmail() << std::endl;
	std::cout << "\tTitle:\t\t" << getTitle() << std::endl;
}  // end print
