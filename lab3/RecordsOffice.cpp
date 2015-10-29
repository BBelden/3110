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
// File:       RecordsOffice.cpp
//
// This is the implementation file of the RecordsOffice class.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Administrator.h"
#include "Faculty.h"
#include "Student.h"
#include "RecordsOffice.h"

using namespace std;

// Method:      default constructor
// Purpose:     instantiate an object of the RecordsOffice class
// Pre-cond:    none
// Post-cond:   object instantiated
RecordsOffice::RecordsOffice(){}

//************************************************************************************************

// Method:      importRecords
// Purpose:     Read commands in from an input file and execute
// Pre-cond:    preformatted input file name passed in
// Post-cond:   Have read completely through the input file and executed all commands
void RecordsOffice::importRecords(string fileName){
    
    // pointers to temp Student, Faculty, and Administrator objects
    Student *tempStudent;
    Faculty *tempFaculty;
    Administrator *tempAdmin;
    Person *personPtr;
	vector < Person* >::iterator itr; // iterator

    
    char command;  // stores the command character
    
	// temporarily holds personal data that is read in from input file and stored based
    // on the command (F, A, S)
	string tName;
    int tMnum;
    string tEmail;
    int tYear;
    string tMajor;
    string tDept;
    string tTitle;
    bool tTen;
    
	// open input file and get the first command
    ifstream myIn;
    myIn.open(fileName);
    myIn >> command;
    
	while(myIn)  // EOF loop
    {
        switch(command){
                // initialize a new Student object, read in student data, copy student data into
                // Student object, add Student object to the linked list, print student data to
                // terminal
			case 'S':
                tempStudent = new Student;
                personPtr = tempStudent;
                myIn >> tName >> tMnum >> tEmail >> tYear >> tMajor;
                tempStudent->setAll(tName, tMnum, tEmail, tYear, tMajor);
                theNewHotness.push_back(personPtr);
                cout << "Note: Adding " << tMnum << " ...\n";
                tempStudent->print();
                break;
                
                // initialize a new Faculty object, read in faculty data, copy student data into
                // Faculty object, add Faculty object to the linked list, print faculty data to
                // terminal
            case 'F':
                tempFaculty = new Faculty;
                personPtr = tempFaculty;
                myIn >> tName >> tMnum >> tEmail >> tDept >> tTen;
                tempFaculty->setAll(tName, tMnum, tEmail, tDept, tTen);
                theNewHotness.push_back(personPtr);
                cout << "Note: Adding " << tMnum << " ...\n";
                tempFaculty->print();
                break;
                
                // initialize a new Administrator object, read in administrator data, copy
                // administrator data into Administrator object, add Administrator object to
                // the linked list, print administrator data to terminal
            case 'A':
                tempAdmin = new Administrator;
                personPtr = tempAdmin;
                myIn >> tName >> tMnum >> tEmail >> tTitle;
                tempAdmin->setAll(tName, tMnum, tEmail, tTitle);
                theNewHotness.push_back(personPtr);
                cout << "Note: Adding " << tMnum << " ...\n";
                tempAdmin->print();
                break;
                
                // read in m number of person to delete, searches the list for matching m number,
                // if found, delete. else ouput error statement.
			case 'D':
                myIn >> tMnum;
                cout << "Note: Deleting " << tMnum << " ...\n\n";
				for (itr = theNewHotness.begin(); itr != theNewHotness.end(); itr++)
                {
                    if ((*itr)->getMnum() == tMnum)
                        break;
                }
				if (itr != theNewHotness.end())
					theNewHotness.erase(itr);
				else if (itr == theNewHotness.end()) 
                {
                    cout << "ERROR: cannot delete person with M number " << tMnum;
                    cout << ", M number not found!\n\n";
                }
                break;
                
                // read in m number of person to print, searches the list for matching m number,
                // if found, print. else ouput error statement.
			case 'P':
                myIn >> tMnum;
				cout << "Note: Printing " << tMnum << " ...\n";
                for (itr = theNewHotness.begin(); itr != theNewHotness.end(); itr++)
                {
                    if ((*itr)->getMnum() == tMnum)
                    {
                        (*itr)->print();
                        break;
                    }
                }
                if (itr == theNewHotness.end())
                {
                    cout << "ERROR: cannot print person with M number " << tMnum;
                    cout << ", M number not found!\n\n";
                }
                break;
                
                // prints entire list, front to back
            case 'L' :
                cout << "Listing people ...\n";
                for (itr = theNewHotness.begin(); itr != theNewHotness.end(); itr++)
                    (*itr)->print();
                break;
        }  // end switch
        
        // set pointers to NULL and read in next command
        tempFaculty = NULL;
		tempAdmin = NULL;
        tempStudent = NULL;
        personPtr = NULL;
		itr = theNewHotness.end();
        myIn >> command;
    }  // end while
    myIn.close();  // close input file
}  // end importRecords
