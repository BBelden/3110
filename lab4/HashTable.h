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
// File:       HashTable.h
//
// This is the header file of the HashTable class.


#ifndef HASHTABLE_H
#define HASHTABLE_H
#pragma once

#include <iostream>
#include <list>
#include "Person.h"
#include "KeyedItem.h"

class HashTable {

friend std::ostream& operator<< (std::ostream& cout, const HashTable& rhs);
   
public:
    HashTable() : peopleInTable(0), indicesUsed(0) {}
    HashTable(int& size) : peopleInTable(0), indicesUsed(0)
        { tableSize = size; table = new std::list<KeyedItem*> [tableSize]; }
    void add(const std::string& name, KeyedItem* keyPtr);
    void remove(const std::string& name);
    void display(const std::string& name);
    void dump();

protected:
    long hashFunction (const std::string& name);
    int tableSize;
    std::list<KeyedItem*> *table;
    float peopleInTable;
    float indicesUsed;
};

#endif
