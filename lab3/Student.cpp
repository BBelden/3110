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
// File:       Student.cpp
//
// This is the implementation file of the Student class.

#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

using namespace std;

// Method:      default constructor
// Purpose:     instantiate an object of the Student class
// Pre-cond:    none
// Post-cond:   object instantiated
Student::Student(){} // default constructor

//************************************************************************************************

// Method:      setYear
// Purpose:     sets the "sYear" data member
// Pre-cond:    int is passed in
// Post-cond:   data member is set
void Student::setYear(int inYear){
    sYear = inYear;
} // end setYr

//************************************************************************************************

// Method:      setMajor
// Purpose:     sets the "sMajor" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Student::setMajor(string inMajor){
    sMajor = inMajor;
} // end setMaj

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Student object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Student::setAll(string inName, int inMnum, string inEmail, int inYear, string inMajor)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setYear(inYear);
    setMajor(inMajor);
}  // end setAll

//************************************************************************************************

// Method:      getYear
// Purpose:     called to access data member "sYear"
// Pre-cond:    data member "sYear" has a value
// Post-cond:   returns "sYear"
int Student::getYear(){
    return sYear;
}  // end getYear

//************************************************************************************************

// Method:      getMaj
// Purpose:     called to access data member "sMajor"
// Pre-cond:    data member "sMajor" has a value
// Post-cond:   returns "sMajor"
string Student::getMajor(){
    return sMajor;
}  // end getMaj

//************************************************************************************************

// Method:      print (polymorphic)
// Purpose:     print data from Student object to terminal
// Pre-cond:    Student object exists
// Post-cond:   data from Student object printed to terminal
void Student::print(){
    cout << "Student:\n";
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tGrade:\t\t";
    switch(getYear()){
        case 0 : cout << "Freshman\n"; break;
        case 1 : cout << "Sophomore\n"; break;
        case 2 : cout << "Junior\n"; break;
        case 3 : cout << "Senior\n"; break;
    }  // end switch
	cout << "\tMajor:\t\t" << getMajor() << endl << endl;
	return;
} // end print
