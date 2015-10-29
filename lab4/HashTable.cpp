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
// File:       HashTable.cpp
//
// This is the implementation file of the HashTable class.

#include <iostream>
#include <string>
#include "HashTable.h"
#include "KeyedItem.h"

// Method:      add
// Purpose:     adds a person to the hash table based on a name-key. hash function is called
//				to generate table index, person object added to STL list
// Pre-cond:    name-key and pointer to person object both passed in.
// Post-cond:   person object added to STL list
void HashTable::add(const std::string& name, KeyedItem* keyPtr)
{
    long index = hashFunction(name);
    if (table[index].size() == 0)
        indicesUsed++;
    std::cout << "Bucket index: " << index << std::endl;
    table[index].emplace_front(keyPtr);
    peopleInTable++;
    
    if (indicesUsed != 0)
        std::cout << "Alpha: " << peopleInTable / indicesUsed << std::endl << std::endl;
    else
        std::cout << "Alpha: 0\n\n";
} // end add

//************************************************************************************************

// Method:      remove
// Purpose:     removes a person from the hash table based on a name-key
// Pre-cond:    name-key is passed into initialized hash table
// Post-cond:   if found: person is removed; if not found: display error message
void HashTable::remove(const std::string& name)
{
    int visited=0;
    long index = hashFunction(name);
    std::list<KeyedItem*>::iterator itr = table[index].begin();
    if (table[index].size() != 0){
        for (itr = table[index].begin(); itr != table[index].end(); itr++){
            visited++;
            if((*itr)->getKey() == name){
                break;
            }
            
        }
    }
    if (itr != table[index].end()){
        delete (*itr);
        table[index].erase(itr);
        peopleInTable--;
        if (table[index].size() == 0)
            indicesUsed--;
    } // end if
    else
        std::cout << "ERROR: cannot remove, " << name << " not found!" << std::endl;
    
    std::cout << visited << " items visited for remove()\n";
    if (indicesUsed != 0)
        std::cout << "Alpha: " << peopleInTable / indicesUsed << std::endl << std::endl;
    else
        std::cout << "Alpha: 0\n\n";
} // end remove

//************************************************************************************************

// Method:      display
// Purpose:     find a person based on a given name-key, display
// Pre-cond:    name-key passed in
// Post-cond:   if found: display person info; if not found: display error message
void HashTable::display(const std::string& name)
{
    long index = hashFunction(name);
    std::list<KeyedItem*>::iterator itr = table[index].begin();
    if (table[index].size() != 0)
        for (itr = table[index].begin(); itr != table[index].end(); itr++)
            if((*itr)->getKey() == name)
                break;
    
    if (itr != table[index].end())
        (*itr)->print();
    else
        std::cout << "ERROR: cannot print, " << name << " not found!" << std::endl;
    std::cout << std::endl;
} // end display

//************************************************************************************************

// Method:      dump
// Purpose:     display all persons (and person data) in hash table
// Pre-cond:    hash table initialized
// Post-cond:   display all persons (and person data) in hash table
void HashTable::dump()
{
    std::cout << (*this);
} // end dump

//************************************************************************************************

// Method:      overloaded <<
// Purpose:     Allows to std::cout instances of a HashTable
// Pre-cond:    none
// Post-cond:   HashTable is streamed out
std::ostream& operator<< (std::ostream& os, const HashTable& rhs)
{
    for (int i = 0; i < rhs.tableSize; i++){
        if (rhs.table[i].size() != 0){
            std::list<KeyedItem*>::iterator itr;
            for (itr = rhs.table[i].begin(); itr != rhs.table[i].end(); itr++){
                os << "Bucket index: " << i << std::endl;
                (*itr)->print();
                os << std::endl;
			} // end for
        } // end if
    } // end for
    return os;
} // end overloaded <<

//************************************************************************************************

// Method:      hashFunction
// Purpose:     provides an index value
// Pre-cond:    passed a name-key
// Post-cond:   returns an index value
long HashTable::hashFunction (const std::string& name)
{
    unsigned long int value=1;
    for (int i = 0; i < name.length(); i++){
        value *= name[i];
    } // end for
    return value%tableSize;
} // end hashFunction

//************************************************************************************************

