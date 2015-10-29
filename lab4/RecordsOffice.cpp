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
// File:       RecordsOffice.cpp
//
// This is the implementation file of the RecordsOffice class.

#include <iostream>
#include <fstream>
#include <string>
#include "KeyedItem.h"
#include "Administrator.h"
#include "Faculty.h"
#include "Student.h"
#include "RecordsOffice.h"
#include "HashTable.h"

// Method:      importRecords
// Purpose:     Read commands in from an input file and execute
// Pre-cond:    preformatted input file name passed in
// Post-cond:   Have read completely through the input file and executed all commands
void RecordsOffice::importRecords(std::string& fileName){
    
    // pointers to temp Student, Faculty, and Administrator objects
    Student *tempStudent;
    Faculty *tempFaculty;
    Administrator *tempAdmin;
    KeyedItem *keyPtr;
    
    char command;  // stores the command character
    int tableSize; // temporarily stores the hash table size from input file
    
	// temporarily holds personal data that is read in from input file and stored based
    // on the command (F, A, S)
	std::string tKey;
    int tMnum;
    std::string tEmail;
    int tYear;
    std::string tMajor;
    std::string tDept;
    std::string tTitle;
    bool tTen;
    
	// open input file, get the table size, instantiate the Hash Table, get first command
    std::ifstream myIn;
    myIn.open(fileName);
    myIn >> tableSize;
    newerHotness = new HashTable (tableSize);
    myIn >> command;
    
	while(myIn)  // EOF loop
    {
        switch(command){
            // initialize a new Student object, read in student data, copy student data into
            // Student object, add Student object to the linked list, print student data to
            // terminal
			case 'S':
                tempStudent = new Student;
                keyPtr = tempStudent;
                myIn >> tKey >> tMnum >> tEmail >> tYear >> tMajor;
                tempStudent->setAll(tKey, tMnum, tEmail, tYear, tMajor);
                std::cout << "Note: Adding " << tKey << " ...\n";
                tempStudent->print();
                newerHotness->add(tKey, keyPtr);
                break;
                
            // initialize a new Faculty object, read in faculty data, copy student data into
            // Faculty object, add Faculty object to the linked list, print faculty data to
            // terminal
            case 'F':
                tempFaculty = new Faculty;
                keyPtr = tempFaculty;
                myIn >> tKey >> tMnum >> tEmail >> tDept >> tTen;
                tempFaculty->setAll(tKey, tMnum, tEmail, tDept, tTen);
                std::cout << "Note: Adding " << tKey << " ...\n";
                tempFaculty->print();
                newerHotness->add(tKey, keyPtr);
                break;
                
            // initialize a new Administrator object, read in administrator data, copy
            // administrator data into Administrator object, add Administrator object to
            // the linked list, print administrator data to terminal
            case 'A':
                tempAdmin = new Administrator;
                keyPtr = tempAdmin;
                myIn >> tKey >> tMnum >> tEmail >> tTitle;
                tempAdmin->setAll(tKey, tMnum, tEmail, tTitle);
                std::cout << "Note: Adding " << tKey << " ...\n";
                tempAdmin->print();
                newerHotness->add(tKey, keyPtr);
                break;
                
            // read in m number of person to delete, searches the list for matching m number,
            // if found, delete. else ouput error statement.
			case 'D':
                myIn >> tKey;
                std::cout << "Removing " << tKey << " ...\n";
                newerHotness->remove(tKey);
                break;
                
            // read in m number of person to print, searches the list for matching m number,
            // if found, print. else ouput error statement.
			case 'P':
                myIn >> tKey;
				std::cout << "Note: Printing " << tKey << " ...\n";
                newerHotness->display(tKey);
                break;
                
            // prints entire list, front to back
            case 'L' :
                std::cout << "Dumping ...\n";
                newerHotness->dump();
                break;
        }  // end switch
        
        // set pointers to NULL and read in next command
        tempFaculty = NULL;
		tempAdmin = NULL;
        tempStudent = NULL;
        keyPtr = NULL;
        myIn >> command;
    }  // end while
    myIn.close();  // close input file
}  // end importRecords
