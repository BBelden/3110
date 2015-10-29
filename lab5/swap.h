// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab5: Big O Exploration
// Due:        22:00:00, November 11, 2013
// Purpose:    Practice algorithmic analysis. Gain appreciation for what the growth-rate 
//             of a function means
// Input:      None.
// Output:     Print to terminal.
//
// File:       swap.h
//
// This is the header file of the swap class.

#ifndef _SWAP_H
#define _SWAP_H

/** Swaps two items.
 * @pre x and y are the items to be swapped.
 * @post Contents of actual locations that x and y represent are
 *       swapped.
 * @param x  Given data item.
 * @param y  Given data item. */
void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}  // end swap

#endif /* _SWAP_H */