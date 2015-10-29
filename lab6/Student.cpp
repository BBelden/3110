// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       Student.cpp
//
// This is the implementation file of the Student class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

// Method:      setAll
// Purpose:     sets all the data members of Student object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Student::setAll(std::string& inKey, int& inMnum, std::string& inEmail, int& inYear, std::string& inMajor)
{
    setKey(inKey);
    setMnum(inMnum);
    setEmail(inEmail);
    setYear(inYear);
    setMajor(inMajor);
}  // end setAll

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Student object to terminal
// Pre-cond:    Student object exists
// Post-cond:   data from Student object printed to terminal
void Student::print(){
    std::cout << "Student:\n";
	std::cout << "\tFull Name:\t" << getKey()<< std::endl;
	std::cout << "\tM Number:\t" << getMnum() << std::endl;
	std::cout << "\tEmail Addr:\t" << getEmail() << std::endl;
	std::cout << "\tGrade:\t\t";
    switch(getYear()){
        case 0 : std::cout << "Freshman\n"; break;
        case 1 : std::cout << "Sophomore\n"; break;
        case 2 : std::cout << "Junior\n"; break;
        case 3 : std::cout << "Senior\n"; break;
    }  // end switch
	std::cout << "\tMajor:\t\t" << getMajor() << std::endl << std::endl;
} // end print
