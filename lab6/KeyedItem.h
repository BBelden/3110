// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab4: Records Office IV
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
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
#include <string>

typedef std::string KeyType;

// abstract base class
class KeyedItem{
    friend class TwoThreeFourTree;
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
