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
// File:       lab7-main.cpp
//
// This is the client file.

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.h"

int main(int argc, const char * argv[])
{
    std::ifstream myFile;
    myFile.open("prereqs.tab");
    std::string parent;
    std::string child;
    Digraph prereqs;
    
    myFile >> parent;
    myFile >> child;
    while (myFile)
    {
        prereqs.addVertex(parent, child);
        myFile >> parent;
        myFile >> child;
    }
    prereqs.topoSort();
    std::cout << std::endl;
    return 0;
}
