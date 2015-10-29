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
// File:       Digraph.cpp
//
// This is the implementation file of the Digraph class.

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "Digraph.h"

Digraph::Digraph()
{
    numEdges = numVertices=0;
} // end constructor

//************************************************************************************************

Digraph::~Digraph()
{
    for (int i = 0; i < numVertices; i++){
        adjList[i].clear();
        adjListHead[i].clear();
    } // end for
} // end destructor

//************************************************************************************************

void Digraph::addVertex(std::string& parent, std::string& child)
{
    bool parentInHead = false, childInHead = false;
    if (numVertices == 0){
        adjListHead[0] = parent;
        adjListHead[1] = child;
        adjList[0].emplace_front(child);
        numVertices += 2;
        numEdges++;
    } // end if
    else{
        for (int i = 0; i<numVertices; i++){
            if (adjListHead[i] == parent){
                adjList[i].emplace_front(child);
                numEdges++;
                parentInHead = true;
            } // end if
            if (adjListHead[i] == child)
                childInHead = true;
        } // end for
        if (!parentInHead){
            adjListHead[numVertices] = parent;
            adjList[numVertices].emplace_front(child);
            numVertices++;
            numEdges++;
        } // end if
        if (!childInHead){
            adjListHead[numVertices] = child;
            numVertices++;
        } // end if
    } // end else
} // end addVertex

//************************************************************************************************

void Digraph::print()
{
    std::list<std::string>::iterator itr;
    for (int i=0; i<numVertices; i++){
        std::cout << adjListHead[i] << " ";
        if (!adjList[i].empty()){
            for (itr = adjList[i].begin(); itr != adjList[i].end(); itr++)
                std::cout << (*itr) << " ";
        } // end if
        std::cout << std::endl;
    } // end for
} // end print

//************************************************************************************************

void Digraph::removeVertex(std::string& removeMe)
{
    int removeIndex = 0;
    std::list<std::string>::iterator itr, iter;
    for (int i=0; i<numVertices; i++){
        if (!adjList[i].empty()){
			itr = adjList[i].begin();
			{
				if ((*itr) == removeMe)
				{
					adjList[i].erase(itr);
					numEdges--;
				}
				else
					itr++;
			}
            /*for (itr = adjList[i].begin(); itr != adjList[i].end(); itr++){
                if ((*itr) == removeMe){
                    iter = itr;
					itr++;
					adjList[i].erase(iter);
					itr--;
                    numEdges--;
                } // end if
            } // end for */
        } // end if
        if (adjListHead[i] == removeMe)
            removeIndex = i;
    } // end for
    for (int i = removeIndex; i < numVertices; i++){
        adjList[i].clear();
        adjList[i] = adjList[i+1];
        adjListHead[i].clear();
        adjListHead[i] = adjListHead[i+1];
    } // end for
    numVertices--;
    numEdges--;
    adjListHead[numVertices].clear();
    adjList[numVertices].clear();
} // end removeVertex

//************************************************************************************************

void Digraph::printVertex(std::string& printMe)
{
    std::list<std::string>::iterator itr;
    for (int i=0; i<numVertices; i++){
        std::cout << adjListHead[i] << " ";
        if (!adjList[i].empty()){
            for (itr = adjList[i].begin(); itr != adjList[i].end(); itr++)
                ;
        } // end if
        ;
    } // end for
} // end printVertex

//************************************************************************************************

void Digraph::topoSort()
{
    int totalVertices = numVertices;
    std::string currVertex;
    while (numVertices != 0){
        for (int i=0; i<totalVertices; i++){
            if (adjList[i].empty() && !adjListHead[i].empty()){
                currVertex = adjListHead[i];
                break;
            } // end if
        } // end for
        sortedList.push_front(currVertex);
        removeVertex(currVertex);
    } // end while
    std::list<std::string>::iterator iter;
    std::cout << "Prerequisites graph: ";
    for (iter = sortedList.begin(); iter != sortedList.end(); iter++)
		std::cout << (*iter) << ", ";
	iter = sortedList.begin();
/*    while (iter != sortedList.end()){
        iter = sortedList.begin();
        std::cout << (*iter);
        sortedList.pop_front();
        iter++;
        //if (iter != sortedList.end())
            std::cout << ", ";
    } // end while*/
} // end topoSort

//************************************************************************************************

