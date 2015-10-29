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
// File:       Faculty.cpp
//
// This is the implementation file of the Faculty class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Faculty.h"

using namespace std;

// Method:      default constructor
// Purpose:     instantiate an object of the Faculty class
// Pre-cond:    none
// Post-cond:   object instantiated
Faculty::Faculty(){}

//************************************************************************************************

// Method:      setDept
// Purpose:     sets the "fDept" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Faculty::setDept(string inDept){
    fDept = inDept;
}  // end setDept

//************************************************************************************************

// Method:      setTenure
// Purpose:     sets the "fTenure" data member
// Pre-cond:    bool is passed in
// Post-cond:   data member is set
void Faculty::setTenure(bool inTenure){
    fTenure = inTenure;
}  // end setTenure

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Faculty object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Faculty::setAll(string inName, int inMnum, string inEmail, string inDept, bool inTenure)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setDept(inDept);
    setTenure(inTenure);
}  // end setAll

//************************************************************************************************

// Method:      getDept
// Purpose:     called to access data member "fDept"
// Pre-cond:    data member "fDept" has a value
// Post-cond:   returns "fDept"
string Faculty::getDept(){
    return fDept;
}  // end getDept

//************************************************************************************************

// Method:      getTenure
// Purpose:     called to access data member "fTenure"
// Pre-cond:    data member "fTenure" has a value
// Post-cond:   returns "fTenure"
bool Faculty::getTenure(){
    return fTenure;
}  // end getTenure

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Faculty object to terminal
// Pre-cond:    Faculty object exists
// Post-cond:   data from Student object printed to terminal
void Faculty::print(){
    cout << "Faculty:\n";
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tDepartment:\t" << getDept() << endl;
	cout << "\tTenured:\t";
    switch (getTenure()) {
        case 0 : cout << "no\n\n"; break;
        case 1 : cout << "yes\n\n"; break;
    } // end switch
	return;
}  // end print
