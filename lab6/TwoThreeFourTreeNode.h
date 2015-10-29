// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab6: 2-3-4 Tree
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       TwoThreeFourTreeNode.h
//
// This is the header file of the TwoThreeFourTreeNode class.

#ifndef TWOTHREEFOURTREENODE_H
#define TWOTHREEFOURTREENODE_H
#pragma once

#include <iostream>
#include <string>
#include "Person.h"
#include "KeyedItem.h"

typedef KeyedItem TreeItemType;
const int MAXITEMS=3;
const int MAXKIDNODES=4;

class TwoThreeFourTreeNode
{
    friend class TwoThreeFourTree;
    
private:
    TreeItemType* itemsArray[MAXITEMS];
    TwoThreeFourTreeNode* kidsArray[MAXKIDNODES];

    TwoThreeFourTreeNode()
    { itemsArray[0]=NULL; itemsArray[1]=NULL; itemsArray[2]=NULL;
        kidsArray[0]=NULL; kidsArray[1]=NULL; kidsArray[2]=NULL; kidsArray[3]=NULL; }

    TwoThreeFourTreeNode(TreeItemType* item)
    { itemsArray[0]=item; itemsArray[1]=NULL; itemsArray[2]=NULL;
        kidsArray[0]=NULL; kidsArray[1]=NULL; kidsArray[2]=NULL; kidsArray[3]=NULL; }
    
    ~TwoThreeFourTreeNode()
        { itemsArray[0]=NULL; itemsArray[1]=NULL; itemsArray[2]=NULL;
            kidsArray[0]=NULL; kidsArray[1]=NULL; kidsArray[2]=NULL; kidsArray[3]=NULL; }
};

#endif