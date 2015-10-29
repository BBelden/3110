// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab6: 2-3-4 Tree
// Due:        22:00:00, November 30, 2013
// Purpose:    Implementation of a 2-3-4 tree.
// Input:      Pre-formatted file.
// Output:     Print to terminal.
//
// File:       TwoThreeFourTree.cpp
//
// This is the implementation file of the TwoThreeFourTree class.

#include <iostream>
#include <string>
#include "Person.h"
#include "KeyedItem.h"
#include "TwoThreeFourTree.h"
#include "TwoThreeFourTreeNode.h"

typedef KeyedItem TreeItemType;

// Method:      Constructor
// Purpose:     Create an empty tree
// Pre-cond:    none
// Post-cond:   tree created with an empty
TwoThreeFourTree::TwoThreeFourTree()
{
    rootNode = new TwoThreeFourTreeNode;
}

//************************************************************************************************

// Method:      Destructor
// Purpose:     Destroy a tree
// Pre-cond:    .
// Post-cond:   .
TwoThreeFourTree::~TwoThreeFourTree()
{
    
}

//************************************************************************************************

// Method:      addItem
// Purpose:     Insert newItem into the tree
// Pre-cond:    none
// Post-cond:   newItem inserted
void TwoThreeFourTree::addItem(TreeItemType* newItem)
{
    if (rootNode->itemsArray[0] == NULL){
        rootNode->itemsArray[0] = newItem;
        return;
    } // end if
    currPtr = rootNode;
    if (currPtr == rootNode && currPtr->itemsArray[2] != NULL)
        splitRoot();
    while (currPtr->kidsArray[0] != NULL){
        if (currPtr == rootNode && currPtr->itemsArray[2] != NULL)
            splitRoot();
        if (getTraversalNode(newItem->searchKey)->itemsArray[2] != NULL){ // split node
            if (currPtr->itemsArray[1] == NULL){ // checks if its a two node
                if (getTraversalNode(newItem->searchKey) == currPtr->kidsArray[0])
                    splitTwoLeft();
                else
                    splitTwoRight();
            } // end if
            else { // for three nodes
                if (getTraversalNode(newItem->searchKey) == currPtr->kidsArray[0])
                    splitThreeLeft();
                else if (getTraversalNode(newItem->searchKey) == currPtr->kidsArray[1])
                    splitThreeMiddle();
                else
                    splitThreeRight();
            }  // end else
            currPtr = getTraversalNode(newItem->searchKey);  // traverse down
        } // end if
        else
            currPtr = getTraversalNode(newItem->searchKey);  // traverse down
    } // end while
    if ((currPtr->itemsArray[0] != NULL && newItem->searchKey == currPtr->itemsArray[0]->searchKey) ||
        (currPtr->itemsArray[1] != NULL && newItem->searchKey == currPtr->itemsArray[1]->searchKey) ||
        (currPtr->itemsArray[2] != NULL && newItem->searchKey == currPtr->itemsArray[2]->searchKey)){
        std::cout << "ERROR: duplicate item found, cannot insert!\n\n";
        return;
    } // end if

    insertIntoLeaf(newItem);
} // end addItem

//************************************************************************************************

// Method:      deleteItem
// Purpose:     Deletes the object that matches key from the tree (or prints out a warning statement if not present)
// Pre-cond:    key passed in
// Post-cond:   item deleted
void TwoThreeFourTree::deleteItem(KeyType& key)
{
    std::cout << "yeah, this isn't done yet....\n\n";
    /*
    currPtr = rootNode;

    // is this a root node?
    if (currPtr == rootNode)
    {
        for (int i=0; i<MAXITEMS; i++)
        {
            if (currPtr->itemsArray[i] != NULL && key == currPtr->itemsArray[i]->searchKey)
            {
                ; // delete
                
                if (currPtr->itemsArray[i+1] != NULL)
                {
                    delete currPtr->itemsArray[i];
                    currPtr->itemsArray[i] = currPtr->itemsArray[i+1];
                    currPtr->itemsArray[i+1] = NULL;
                }
                else
                {
                    delete currPtr->itemsArray[i];
                    currPtr->itemsArray[i] = NULL;
                }
                return;
            }
        }
        //std::cout << "ERROR: can't remove " << key << ", not found!!\n\n";
        //return;
    }
    TwoThreeFourTreeNode* tempParent;
    tempParent = currPtr;
    currPtr = getTraversalNode(key);
    
    bool found = false;
    while (!found)
    {
        if (currPtr->itemsArray[1] == NULL)
        {
            ;   // if there is a wealthy sibling
                    // merge w/ wealthy sib, zigzag
                // else
                    // merge w/ adjacent sib, borrow from parent, merge left if possible
        }
        
        // if the key is in this node
        if (key == currPtr->itemsArray[0]->searchKey ||
            key == currPtr->itemsArray[1]->searchKey ||
            key == currPtr->itemsArray[2]->searchKey)
        {
            ; // delete item
            // return
            return;
        }
        // else
        else
        {
            // swap with inorder successor
            // chase down the original thing again
            // merging any 2-nodes along the way
            // delete
            // return
            return;
        }
        // traverse down again
        tempParent = currPtr;
        currPtr = getTraversalNode(key);
    }

    std::cout << "ERROR: can't remove " << key << ", not found!!\n\n";
    return;
    
    
    loop
    {
        is this node the root? if (currNode != rootNode){}
            yes
                ....is the key in this node?....
            no
            is this node a 2 node? if (currNode->itemsArray[1] == NULL){}
                yes
                    is there a wealthy sibling?
                        yes
                            merge with wealthy sibling
                            zigzag
                        no
                            merge with adjacent sibling
                            borrow from parent, merge left if possible
                no
        is the key in this node?
            yes
                is the node a leaf?
                    yes
                        delete item
                        return;
                    no
                        swap with inorder successor
                        and do magic?
                        //swapAndDelete(key, currPtr);
                        return;
            no
                traverse down
    }
*/
    
} // end deleteItem

//************************************************************************************************

// Method:      printTree
// Purpose:     Traverse the tree and print out each object in search key order
// Pre-cond:    none
// Post-cond:   tree printed
void TwoThreeFourTree::printTree()
{
    inorderPrint(rootNode);
} // end printTree

//************************************************************************************************

// Method:      printItem
// Purpose:     Prints the object that matches key (or prints out a warning statement if not present)
// Pre-cond:    none
// Post-cond:   item printed
void TwoThreeFourTree::printItem(const KeyType& key)
{
    currPtr = rootNode;
    bool found = false;
    if (currPtr->itemsArray[0] == NULL){
        std::cout << "ERROR: " << key << " not found!\n\n";
        return;
    } // end if
    while (!found || currPtr->kidsArray[0] != NULL){
        // look in current node
        for (int i=0; i<MAXITEMS; i++){
            if (currPtr->itemsArray[i] != NULL && key == currPtr->itemsArray[i]->searchKey){
                currPtr->itemsArray[i]->print();
                return;
            } // end if
        } // end for
        currPtr = getTraversalNode(key);
    } // end while
    std::cout << "ERROR: " << key << " not found!\n";
    return;
} // end printItem

//************************************************************************************************

// Method:      inorderPrint
// Purpose:     prints the 234 tree in order
// Pre-cond:    none
// Post-cond:   tree is printed in order
void TwoThreeFourTree::inorderPrint(TwoThreeFourTreeNode* nodePtr)
{
    if (nodePtr->kidsArray[0] == NULL){
        if (nodePtr->itemsArray[0] != NULL)
            nodePtr->itemsArray[0]->print();
        if (nodePtr->itemsArray[1] != NULL)
            nodePtr->itemsArray[1]->print();
        if (nodePtr->itemsArray[2] != NULL)
            nodePtr->itemsArray[2]->print();
        return;
    } // end if
    else
        inorderPrint(nodePtr->kidsArray[0]);
    nodePtr->itemsArray[0]->print();
    if (nodePtr->kidsArray[1] == NULL){
        if (nodePtr->itemsArray[1] != NULL)
            nodePtr->itemsArray[1]->print();
        if (nodePtr->itemsArray[2] != NULL)
            nodePtr->itemsArray[2]->print();
        return;
    } // end if
    else
        inorderPrint(nodePtr->kidsArray[1]);
    if (nodePtr->itemsArray[1] == NULL)
        return;
    else
        nodePtr->itemsArray[1]->print();
    if (nodePtr->kidsArray[2] == NULL){
        if (nodePtr->itemsArray[2] != NULL)
            nodePtr->itemsArray[2]->print();
        return;
    } // end if
    else
        inorderPrint(nodePtr->kidsArray[2]);
    if (nodePtr->itemsArray[2] == NULL)
        return;
    else
        nodePtr->itemsArray[2]->print();
    if (nodePtr->kidsArray[2] == NULL)
        return;
    else
        inorderPrint(nodePtr->kidsArray[3]);
} // end inorderPrint

//************************************************************************************************

// Method:      splitRoot
// Purpose:     split a four node if the root is a four node
// Pre-cond:    root is a four node
// Post-cond:   root is split
void TwoThreeFourTree::splitRoot()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* newRoot = new TwoThreeFourTreeNode(nodePtr->itemsArray[1]);
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRoot->kidsArray[0] = nodePtr;
    newRoot->kidsArray[1] = newRight;
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    rootNode = newRoot;
    currPtr = rootNode;
} // end splitRoot

//************************************************************************************************

// Method:      splitTwoLeft
// Purpose:     splits a four node if the parent is two node and node to split is the left child
// Pre-cond:    node is a four node
// Post-cond:   node is split
void TwoThreeFourTree::splitTwoLeft()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* parentNodePtr = nodePtr;
    nodePtr = nodePtr->kidsArray[0];
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    parentNodePtr->itemsArray[1] = parentNodePtr->itemsArray[0];
    parentNodePtr->itemsArray[0] = nodePtr->itemsArray[1];
    parentNodePtr->kidsArray[2] = parentNodePtr->kidsArray[1];
    parentNodePtr->kidsArray[1] = newRight;
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    currPtr = parentNodePtr;
} // end splitTwoLeft

//************************************************************************************************

// Method:      splitTwoRight
// Purpose:     splits a four node if the parent is a two node and node to split is the right child
// Pre-cond:    node is a four node
// Post-cond:   node is split
void TwoThreeFourTree::splitTwoRight()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* parentNodePtr = nodePtr;
    nodePtr = nodePtr->kidsArray[1];
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    parentNodePtr->kidsArray[2] = newRight;
    parentNodePtr->itemsArray[1] = nodePtr->itemsArray[1];
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    currPtr = parentNodePtr;
} // end splitTwoRight

//************************************************************************************************

// Method:      splitThreeLeft
// Purpose:     split a four node if the parent is a three node and node to split is the left child
// Pre-cond:    node is a four node
// Post-cond:   node is split
void TwoThreeFourTree::splitThreeLeft()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* parentNodePtr = nodePtr;
    nodePtr = nodePtr->kidsArray[0];
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    parentNodePtr->itemsArray[2] = parentNodePtr->itemsArray[1];
    parentNodePtr->itemsArray[1] = parentNodePtr->itemsArray[0];
    parentNodePtr->itemsArray[0] = nodePtr->itemsArray[1];
    parentNodePtr->kidsArray[3] = parentNodePtr->kidsArray[2];
    parentNodePtr->kidsArray[2] = parentNodePtr->kidsArray[1];
    parentNodePtr->kidsArray[1] = newRight;
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    currPtr = parentNodePtr;
} // end splitThreeLeft

//************************************************************************************************

// Method:      splitThreeMiddle
// Purpose:     splits a four node if the parent is a three node and node to split is the middle child
// Pre-cond:    node is a four node
// Post-cond:   node is split
void TwoThreeFourTree::splitThreeMiddle()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* parentNodePtr = nodePtr;
    nodePtr = nodePtr->kidsArray[1];
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    parentNodePtr->itemsArray[2] = parentNodePtr->itemsArray[1];
    parentNodePtr->itemsArray[1] = nodePtr->itemsArray[1];
    parentNodePtr->kidsArray[3] = parentNodePtr->kidsArray[2];
    parentNodePtr->kidsArray[2] = newRight;
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    currPtr = parentNodePtr;
} // end SplitThreeMiddle

//************************************************************************************************

// Method:      splitThreeRight
// Purpose:     split a four node if the parent is a three node and node to split is the right child
// Pre-cond:    node is a four node
// Post-cond:   node is split
void TwoThreeFourTree::splitThreeRight()
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    TwoThreeFourTreeNode* parentNodePtr = nodePtr;
    nodePtr = nodePtr->kidsArray[2];
    TwoThreeFourTreeNode* newRight = new TwoThreeFourTreeNode(nodePtr->itemsArray[2]);
    newRight->kidsArray[0] = nodePtr->kidsArray[2];
    newRight->kidsArray[1] = nodePtr->kidsArray[3];
    parentNodePtr->itemsArray[2] = nodePtr->itemsArray[1];
    parentNodePtr->kidsArray[3] = newRight;
    nodePtr->kidsArray[2] = nodePtr->kidsArray[3] = NULL;
    nodePtr->itemsArray[1] = nodePtr->itemsArray[2] = NULL;
    currPtr = parentNodePtr;
} // end splitThreeRight

//************************************************************************************************

// Method:      getTraversalNode
// Purpose:     find the pointer of the next node to traverse to
// Pre-cond:    none
// Post-cond:   returns a pointer to the next node
TwoThreeFourTreeNode* TwoThreeFourTree::getTraversalNode(const KeyType& newItem)
{
    if (currPtr->itemsArray[0] == NULL)
        return NULL;
    if (newItem < currPtr->itemsArray[0]->searchKey)
        return currPtr->kidsArray[0];
    if (newItem > currPtr->itemsArray[0]->searchKey){
        if (currPtr->itemsArray[1] == NULL || newItem < currPtr->itemsArray[1]->searchKey)
            return currPtr->kidsArray[1];
    } // end if
    if (newItem > currPtr->itemsArray[1]->searchKey){
        if (currPtr->itemsArray[2] == NULL || newItem < currPtr->itemsArray[2]->searchKey)
            return currPtr->kidsArray[2];
    } // end if
    if (newItem > currPtr->itemsArray[2]->searchKey)
        return currPtr->kidsArray[3];
    else
        return NULL;
} // end getTraversalNode

//************************************************************************************************

// Method:      insertIntoLeaf
// Purpose:     helper method for addItem, once at a leaf, will insert a KeyedItem into a leaf
// Pre-cond:    currPtr is pointing to a leaf node
// Post-cond:   item inserted
void TwoThreeFourTree::insertIntoLeaf(TreeItemType* newItem)
{
    TwoThreeFourTreeNode* nodePtr = currPtr;
    // insert into a 2 node
    if (nodePtr->itemsArray[1] == NULL){
        // insert into left position
        if (newItem->searchKey < nodePtr->itemsArray[0]->searchKey){
            nodePtr->itemsArray[1] = nodePtr->itemsArray[0];
            nodePtr->itemsArray[0] = newItem;
            return;
        } // end if
        // insert into right position
        else{
            nodePtr->itemsArray[1] = newItem;
            return;
        } // end else
    } // end if
    // insert into a 3 node
    else
    {
       // insert into left position
        if (newItem->searchKey < nodePtr->itemsArray[0]->searchKey){
            nodePtr->itemsArray[2] = nodePtr->itemsArray[1];
            nodePtr->itemsArray[1] = nodePtr->itemsArray[0];
            nodePtr->itemsArray[0] = newItem;
            return;
        } // end if
        // insert into middle position
        else if (newItem->searchKey < nodePtr->itemsArray[1]->searchKey){
            nodePtr->itemsArray[2] = nodePtr->itemsArray[1];
            nodePtr->itemsArray[1] = newItem;
            return;
        } // end else if
        // insert into right position
        else{
            nodePtr->itemsArray[2] = newItem;
            return;
        } // end else
    } // end else
} // end insertIntoLeaf

//************************************************************************************************

