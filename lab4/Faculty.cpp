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
// File:       Faculty.cpp
//
// This is the implementation file of the Faculty class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Faculty.h"

// Method:      setAll
// Purpose:     sets all the data members of Faculty object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Faculty::setAll(std::string& inKey, int& inMnum, std::string& inEmail, std::string& inDept, bool& inTenure)
{
    setKey(inKey);
    setMnum(inMnum);
    setEmail(inEmail);
    setDept(inDept);
    setTenure(inTenure);
}  // end setAll

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Faculty object to terminal
// Pre-cond:    Faculty object exists
// Post-cond:   data from Student object printed to terminal
void Faculty::print(){
    std::cout << "Faculty:\n";
	std::cout << "\tFull Name:\t" << getKey()<< std::endl;
	std::cout << "\tM Number:\t" << getMnum() << std::endl;
	std::cout << "\tEmail Addr:\t" << getEmail() << std::endl;
	std::cout << "\tDepartment:\t" << getDept() << std::endl;
	std::cout << "\tTenured:\t";
    switch (getTenure()) {
        case 0 : std::cout << "no\n"; break;
        case 1 : std::cout << "yes\n"; break;
    } // end switch
}  // end print
