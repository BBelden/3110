// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab6: 2-3-4 Tree
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       TwoThreeFourTree.h
//
// This is the header file of the TwoThreeFourTree class.

#ifndef TWOTHREEFOURTREE_H
#define TWOTHREEFOURTREE_H
#pragma once

#include <iostream>
#include <string>
#include "Person.h"
#include "KeyedItem.h"
#include "TwoThreeFourTreeNode.h"

typedef KeyedItem TreeItemType;

class TwoThreeFourTree
{
public:
    TwoThreeFourTree();
    ~TwoThreeFourTree();
    void addItem(TreeItemType* newItem);
    void deleteItem(KeyType& key);
    void printTree();
    void printItem(const KeyType& key);
    
private:
    void inorderPrint(TwoThreeFourTreeNode* nodePtr);
    void splitRoot();
    void splitTwoRight();
    void splitTwoLeft();
    void splitThreeLeft();
    void splitThreeMiddle();
    void splitThreeRight();
    TwoThreeFourTreeNode* getTraversalNode(const KeyType& newItem);
    void insertIntoLeaf(TreeItemType* newItem);
    
    TwoThreeFourTreeNode* rootNode;
    TwoThreeFourTreeNode* currPtr;
};


#endif