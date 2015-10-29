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
// File:       KeyedItem.h
//
// This is the header/implementation file of the KeyedItem class.

/***************************************************************
 borrowed from Dr. H. Carroll and enhanced by the DoubleBee
 ***************************************************************/

#ifndef KEYEDITEM_H
#define KEYEDITEM_H
#pragma once

#include <iostream>

typedef std::string KeyType;

// abstract base class
class KeyedItem{
public:
    KeyedItem() {}
    virtual ~KeyedItem(){}
    KeyedItem(const KeyType& keyValue)
    : searchKey(keyValue) {}
    void setKey(const KeyType& key){ searchKey = key; }
    KeyType getKey() const{ return searchKey; }
    virtual void print()=0;
private:
    KeyType searchKey;
};

#endif
