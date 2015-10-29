// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab7: topological sorting
// Due:        23:59:59, December 05, 2013
// Purpose:    The university wants to upgrade part of its registration system. They've
//             asked you to provide them with a list of classes, which if taking one class
//             per semester that a student would meet all of the prerequisites.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       Digraph.h
//
// This is the header file of the Digraph class.

#ifndef DIGRAPH_H
#define DIGRAPH_H
#pragma once

#include <iostream>
#include <string>
#include <list>

class Digraph {
public:
    Digraph ();
    ~Digraph();
    void addVertex(std::string& parent, std::string& child);
    void removeVertex(std::string& removeMe);
    void printVertex(std::string& printMe);
    void topoSort();
    void print();
    
private:
    static const int MAX_VERTICES=100;
    int numVertices;
    int numEdges;
    int size;
    std::list<std::string> adjList[MAX_VERTICES];
    std::string adjListHead[MAX_VERTICES];
    std::list<std::string> sortedList;
};

#endif
