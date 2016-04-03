//
//  HeapSort.C
//  HeapSort
//
//  Created by Somnath Saha on 2/28/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#include "HeapSort.h"


/****************************************************************************
 Function Name : void buildHeap()                                           *
 Input Argument: int* unOrderedList, size_t startIndex, size_t endIndex     *
 Output        : Initial Heapified List                                     *
 Description   : This function Build initial heapified list based on        *
                 heap property                                              *
 ***************************************************************************/
void buildHeap(int* A, size_t iStart, size_t iEnd)
{
    size_t index;
    for ( index = iStart; index <= iEnd ; index++ )
    {
        // Index of element to check with parent.
        shiftUp(A, index);
    }
}

/****************************************************************************
 Function Name : void shiftUp()                                             *
 Input Argument: int* unOrdered List, size_t startIndex                     *
 Output        : Partial Heapified List                                     *
 Description   : This function Build initial heapified list based on        *
                 heap property                                              *
 ***************************************************************************/

void shiftUp(int *A, size_t iStart)
{
    size_t iParent = 0;
    if ( iStart >= 1 )
    {
        iParent = (iStart - 1) / 2;
    }
    
    // Check the element is greater than parent element an do it recursively 
    // unless it reaches to root.
    if ( A[iStart] > A[iParent])
    {
        // Swap element
        int parent = A[iStart];
        A[iStart]  = A[iParent];
        A[iParent] = parent;
        // Call buildHeap function
        shiftUp(A, iParent);
    }
    return;
}

/****************************************************************************
 Function Name : void heapify()                                             *
 Input Argument: int* unHeapifiedList, size_t start, size_t end             *
 Output        : Heapify elements of the list based on heap property        *
 Description   : This function used to re-heapify the heapified list        *
                 when root element has been removed for sorting.            *
 ***************************************************************************/
void heapify(int* unHeapifiedList, size_t start, size_t end)
{
    // Check which subnode of the root is bigger.
    size_t iLeftChild  = 2 * start + 1;
    size_t iRightChild = 2 * start + 2;
    
    size_t iBiggerChildNode = iLeftChild;
    
    if ( unHeapifiedList[ iLeftChild ] < unHeapifiedList[ iRightChild ] &&  (iRightChild) <= end )
    {
        iBiggerChildNode = iRightChild;
    }
    
    // Check if root is greater than (2i + 1) and (2i+2) element in the list?
    if ( unHeapifiedList[ start ] < unHeapifiedList[ iBiggerChildNode ] )
    {
        // Swap element root with bigger child
        int rootElement          = unHeapifiedList[ start ];
        unHeapifiedList[ start ] = unHeapifiedList[ iBiggerChildNode ];
        unHeapifiedList[ iBiggerChildNode ] = rootElement;
        // Call heapify function for re-heapify if required. Call it unleass it reaches to end.
        // Call left sub-tree
        if ( ( 2 * iLeftChild + 1 ) <= end)
        {
            heapify(unHeapifiedList, iLeftChild , end );
        }
        // Call right sub-tree
        if ( ( 2 * iRightChild + 1 ) <= end)
        {
            heapify(unHeapifiedList, iRightChild , end );
        }
        
    }
    
}

/****************************************************************************
 Function Name : void heapSort()                                            *
 Input Argument: int* HeapifiedList, size_t Root, size_t endIndex           *
 Output        : Sorted list of elements                                    *
 Description   : This function sorts the heapified list in assending order. *
 ***************************************************************************/

void heapSort(int* A, size_t iRoot, size_t iEnd)
{
    // Remove root and place it to the position of last elment
    // Move last elment to root.
    // Actually swap root with last elment till end reaches to start position.
    int rootElement = A[ iRoot ];
    A[iRoot] = A[iEnd];
    A[iEnd] = rootElement;
    
    // Root has been placed into sorted position, decrement last index
    iEnd = iEnd -1 ;
    // Call heapify function and heap short till iEnd reaches to root element
    if( iRoot < iEnd )
    {
        heapify(A, iRoot, iEnd);
        //displayData(A, iRoot, iEnd );
        // Sort Hipified Element
        heapSort(A, iRoot,iEnd);
    }
}
/*****************************************************************************
 Function Name: displayData(<list of elements>, < low index>, < high index>) *
 Input Argument: int* Aarray, size_t start, size_t end                       *
 Output        : Array elemnents                                             *
 Description   : Display array elements                                      *
 ****************************************************************************/
void displayData(int *A, size_t low, size_t  end)
{
    for(size_t index=low; index<= end; index++)
    {
        if ( index == low )
        {
            cout<<A[index];
        }
        else
        {
            cout<<" "<<A[index];
        }
    }
    cout<<endl;
}


