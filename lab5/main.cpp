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
// File:       main.cpp
//
// This is the client file.

#include <iostream>         // for cout
#include <iomanip>          // for fixed, setprecision()
#include <stdlib.h>			// for rand()
#include <algorithm>        // for sort() output as "ALGO sort"
#include <array>            // array STL for use in sort()
#include "swap.h"

void bubbleSort(int theArray[], int n);
void insertionSort(int theArray[], int n);
void merge(int theArray[], int first, int mid, int last, int* tempArray);
void mergesort(int theArray[], int first, int last, int* tempArray);
void choosePivot(int theArray[], int first, int last);
void partition(int theArray[], int first, int last, int& pivotIndex);
void quicksort(int theArray[], int first, int last);
int indexOfLargest(const int theArray[], int size);
void selectionSort(int theArray[], int n);

int main(){
    const long SIZE = 10000;   // number of items to sort
    const long AVG = 10;     // to average times on smaller sort sizes
    clock_t begin, end;
    int *arrayToSort, *tempArray;
    std::array<double, 6> results={0};       // to sort results
    std::cout << std::fixed << std::setprecision(10);
    std::cout << SIZE << " items sorted, averaged over " << AVG << " runs\n";
    
    double bsDuration=0, bsSum=0, bsAvg=0;
    for (long i = 0; i < AVG; i++)
    {
        arrayToSort = new int[SIZE];
        for (long i = 0; i < SIZE; i++)
            arrayToSort[i] = rand();
        begin = end = 0;
        begin = clock();
        bubbleSort(arrayToSort, SIZE);
        end = clock();
        bsDuration =  (end - begin) / double (CLOCKS_PER_SEC);
        bsSum += bsDuration;
        delete arrayToSort;
    }
    bsAvg = bsSum / AVG;
    results[0] = bsAvg;
 
    
    double isDuration=0, isSum=0, isAvg=0;
    for (long i = 0; i < AVG; i++)
    {
        arrayToSort = new int[SIZE];
        for (long i = 0; i < SIZE; i++)
            arrayToSort[i] = rand();
        begin = end = 0;
        begin = clock();
        insertionSort(arrayToSort, SIZE);
        end = clock();
        isDuration =  (end - begin) / (double)CLOCKS_PER_SEC;
        isSum += isDuration;
        delete arrayToSort;
    }
    isAvg = isSum / AVG;
    results[1] = isAvg;


    double msDuration=0, msSum=0, msAvg=0;
    for (long i = 0; i < AVG; i++)
    {
        arrayToSort = new int[SIZE];
        tempArray = new int[SIZE];
        for (long i = 0; i < SIZE; i++)
            arrayToSort[i] = rand();
        begin = end = 0;
        begin = clock();
        mergesort(arrayToSort, 0, SIZE-1, tempArray);
        end = clock();
        msDuration =  (end - begin) / double (CLOCKS_PER_SEC);
        msSum += msDuration;
        delete arrayToSort;
        delete tempArray;
    }
    msAvg = msSum / AVG;
    results[2] = msAvg;
    
 
    double qsDuration=0, qsSum=0, qsAvg=0;
    for (long i = 0; i < AVG; i++)
    {
        arrayToSort = new int[SIZE];
        for (long i = 0; i < SIZE; i++)
            arrayToSort[i] = rand();
        begin = end = 0;
        begin = clock();
        quicksort(arrayToSort, 0, SIZE-1);
        end = clock();
        qsDuration =  (end - begin) / double (CLOCKS_PER_SEC);
        qsSum += qsDuration;
        delete arrayToSort;
    }
    qsAvg = qsSum / AVG;
    results[3] = qsAvg;
    

    double ssDuration=0, ssSum=0, ssAvg=0;
    for (long i = 0; i < AVG; i++)
    {
        arrayToSort = new int[SIZE];
        for (long i = 0; i < SIZE; i++)
            arrayToSort[i] = rand();
        begin = end = 0;
        begin = clock();
        selectionSort(arrayToSort, SIZE);
        end = clock();
        ssDuration =  (end - begin) / double (CLOCKS_PER_SEC);
        ssSum += ssDuration;
        delete arrayToSort;
    }
    ssAvg = ssSum / AVG;
    results[4] = ssAvg;

    
    double asDuration=0, asSum=0, asAvg=0;
    std::array<int, SIZE> *array2;
    for (long i = 0; i < AVG; i++)
    {
        array2 = new std::array<int, SIZE>;
        for (long i = 0; i < SIZE; i++)
            (*array2)[i] = rand();
        begin = end = 0;
        begin = clock();
        std::sort(array2->begin(), array2->end());
        end = clock();
        asDuration =  (end - begin) / double (CLOCKS_PER_SEC);
        asSum += asDuration;
        delete array2;
    }
    asAvg = asSum / AVG;
    results[5] = asAvg;
    
    std::sort(results.begin(), results.end());

    for (int i = 0; i<6; i++)
    {
        if (results[i] == asAvg)
            std::cout << "ALGO SORT:\t" << asAvg << std::endl;
        if (results[i] == bsAvg)
            std::cout << "BUBBLE SORT:\t" << bsAvg << std::endl;
        if (results[i] == isAvg)
            std::cout << "INSERTION SORT:\t" << isAvg << std::endl;
        if (results[i] == msAvg)
            std::cout << "MERGE SORT:\t" << msAvg << std::endl;
        if (results[i] == qsAvg)
            std::cout << "QUICK SORT:\t" << qsAvg << std::endl;
        if (results[i] == ssAvg)
            std::cout << "SELECTION SORT:\t" << ssAvg << std::endl;
    }
   
    
    return 0;
}

//*********************************************************************************

/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. */
void bubbleSort(int theArray[], int n){
    bool sorted = false;  // false when swaps occur
    
    for (int pass = 1; (pass < n) && !sorted; ++pass){
        // Invariant: theArray[n+1-pass..n-1] is sorted
        //            and > theArray[0..n-pass]
        sorted = true;  // assume sorted
        for (int index = 0; index < n - pass; ++index){
            // Invariant: theArray[0..index-1] <= theArray[index]
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex]){
                // exchange items
                swap(theArray[index], theArray[nextIndex]);
                sorted = false;  // signal exchange
            }  // end if
        }  // end for
        
        // Assertion: theArray[0..n-pass-1] <
        // theArray[n-pass]
    }  // end for
}  // end bubbleSort

//*********************************************************************************

/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray.*/
void insertionSort(int theArray[], int n){
    // unSorted = first index of the unSorted region,
    // loc = index of insertion in the sorted region,
    // nextItem = next item in the unSorted region
    
    // initially, sorted region is theArray[0],
    //            unSorted region is theArray[1..n-1];
    // in general, sorted region is
    //             theArray[0..unSorted-1],
    // unSorted region is theArray[unSorted..n-1]
    
    for (int unSorted = 1; unSorted < n; ++unSorted)
    {  // Invariant: theArray[0..unSorted-1] is sorted
        
        // find the right position (loc) in
        // theArray[0..unSorted] for theArray[unSorted],
        // which is the first item in the unSorted
        // region; shift, if necessary, to make room
        int nextItem = theArray[unSorted];
        int loc = unSorted;
        
        for (;(loc > 0) && (theArray[loc-1 ]> nextItem);
             --loc)
            // shift theArray[loc-1] to the right
            theArray[loc] = theArray[loc-1];
        
        // Assertion: theArray[loc] is where nextItem
        // belongs
        
        // insert nextItem into sorted region
        theArray[loc] = nextItem;
    }  // end for
}  // end insertionSort

//*********************************************************************************

/** Merges two sorted array segments theArray[first..mid] and
 *  theArray[mid+1..last] into one sorted array.
 * @pre first <= mid <= last. The subarrays theArray[first..mid]
 * and theArray[mid+1..last] are each sorted in increasing order.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The beginning of the first segment in theArray.
 * @param mid  The end of the first segement in theArray.  mid + 1
 *        marks the beginning of the second segment.
 * @param last  The last element in the second segment in theArray.
 * @note This function merges the two subarrays into a temporary
 * array and copies the result into the original array theArray.*/
void merge(int theArray[],
           int first, int mid, int last, int* tempArray)
{
    // initialize the local indexes to indicate the subarrays
    int first1 = first;       // beginning of first subarray
    int last1  = mid;         // end of first subarray
    int first2 = mid + 1;     // beginning of second subarray
    int last2  = last;        // end of second subarray
    
    // while both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;    // next available location in
    // tempArray
    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {  // Invariant: tempArray[first..index-1] is in order
        if (theArray[first1] < theArray[first2])
        {  tempArray[index] = theArray[first1];
            ++first1;
        }
        else
        {  tempArray[index] = theArray[first2];
            ++first2;
        }  // end if
    }  // end for
    
    // finish off the nonempty subarray
    
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
        // Invariant: tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
    
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
        // Invariant: tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
    
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        theArray[index] = tempArray[index];
    }
}  // end merge

//*********************************************************************************

/** sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted in ascending order.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.*/
void mergesort(int theArray[], int first, int last, int* tempArray){
    
    if (first < last)
    {  // sort each half
        int mid = (first + last)/2;    // index of midpoint
        // sort left half theArray[first..mid]
        mergesort(theArray, first, mid, tempArray);
        // sort right half theArray[mid+1..last]
        mergesort(theArray, mid+1, last, tempArray);
        
        // merge the two halves
        merge(theArray, first, mid, last, tempArray);
    }  // end if
}  // end mergesort

//*********************************************************************************

/** Chooses a pivot for quicksort's partition algorithm and swaps
 *  it with the first item in an array.
 * @pre theArray[first..last] is an array; first <= last.
 * @post theArray[first] is the pivot.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void choosePivot(int theArray[], int first, int last){
    //cerr << "choosePivot(array, " << first << ", " << last << ")\n";
    int mid = (last - first) / 2;
    if( (theArray[first] <= theArray[mid] &&
         theArray[mid] <= theArray[last]) ||
       (theArray[last] <= theArray[mid] &&
        theArray[mid] <= theArray[first]) ){
           // value at mid index is middle of values at first and last indices
           swap(theArray[first], theArray[mid]);
       }else if( (theArray[first] <= theArray[last] &&
                  theArray[last] <= theArray[mid]) ||
                (theArray[mid] <= theArray[last] &&
                 theArray[last] <= theArray[first])){
                    // value at last index is middle of values
                    swap(theArray[first], theArray[last]);
                }
}

//*********************************************************************************

/** Partitions an array for quicksort.
 * @pre theArray[first..last] is an array; first <= last.
 * @post Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @param pivotIndex  The index of the pivot after partitioning.*/
void partition(int theArray[],
               int first, int last, int& pivotIndex){
    // place pivot in theArray[first]
    choosePivot(theArray, first, last);
    int pivot = theArray[first];     // copy pivot
    
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in
    // unknown
    
    // move one item at a time until unknown region is empty
    for (; firstUnknown <= last; ++firstUnknown)
    {  // Invariant: theArray[first+1..lastS1] < pivot
        //         theArray[lastS1+1..firstUnknown-1] >= pivot
        
        // move item from unknown to proper region
        if (theArray[firstUnknown] < pivot)
        {  // item from unknown belongs in S1
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1]);
        }  // end if
        
        // else item from unknown belongs in S2
    }  // end for
    
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    pivotIndex = lastS1;
}  // end partition

//*********************************************************************************

/** sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.*/
void quicksort(int theArray[], int first, int last){
    int pivotIndex;
    
    if (first < last)
    {  // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex);
        
        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1);
        quicksort(theArray, pivotIndex+1, last);
    }  // end if
}  // end quicksort

//*********************************************************************************

/** Finds the largest item in an array.
 * @pre theArray is an array of size items, size >= 1.
 * @post None.
 * @param theArray  The given array.
 * @param size  The number of elements in theArray.
 * @return The index of the largest item in the array. The
 *         arguments are unchanged.*/
int indexOfLargest(const int theArray[], int size)
{
    int indexSoFar = 0;  // index of largest item
    // found so far
    for (int currentIndex = 1; currentIndex < size;
         ++currentIndex)
    {  // Invariant: theArray[indexSoFar] >=
        //            theArray[0..currentIndex-1]
        if (theArray[currentIndex] > theArray[indexSoFar])
            indexSoFar = currentIndex;
    }  // end for
    
    return indexSoFar;  // index of largest item
}  // end indexOfLargest

//*********************************************************************************

/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post The array theArray is sorted into ascending order; n is
 *       unchanged.
 * @param theArray  The array to sort.
 * @param n  The size of theArray. */
void selectionSort(int theArray[], int n){
    // last = index of the last item in the subarray of
    //        items yet to be sorted,
    // largest = index of the largest item found
    
    for (int last = n-1; last >= 1; --last)
    {  // Invariant: theArray[last+1..n-1] is sorted and
        // > theArray[0..last]
        
        // select largest item in theArray[0..last]
        int largest = indexOfLargest(theArray, last+1);
        
        // swap largest item theArray[largest] with
        // theArray[last]
        swap(theArray[largest], theArray[last]);
    }  // end for
}  // end selectionSort

//*********************************************************************************
