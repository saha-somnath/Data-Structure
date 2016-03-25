//
//  main.cpp
//  Merge Sort
//
//  Created by Somnath Saha on 10/7/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void divideData(int *A, int low, int end);
void mergeData(int *A,int low, int mid, int end);
void displayData(int *A, int low, int end);

int main(int argc, const char * argv[]) {
    
    int numberOfTestCases = 0;
    int numberOfElement   = 0;
    cout<<"This program accepts standard inputs."<<endl;
    cout<<"Pass the input file from commandline as: %> merger < list"<<endl;
    cout<<"Pass input directly from standard input as\n<Number of TestCases>\n<Number Of Elemnet> \n<List of Numbers>"<<endl;
    // Read number of testcases
    scanf("%d", &numberOfTestCases);
    
    // For each TestCase run the program
    for( int iTestCases = 0; iTestCases < numberOfTestCases ; iTestCases++)
    {
        // Read number of element for a list
        scanf("%d", &numberOfElement);
        // Dynamically allocate memory
        int * A = (int*)calloc( numberOfElement, sizeof(int));
    
        //int A[]= { 7,2,4,16,23,2,8,9,3,6,5};
        for ( int index =0 ; index< numberOfElement; index++ )
        {
            scanf( "%d", &A[index]);
        }
    
        cout<<"Input unsorted data:";
        displayData(A, 0, numberOfElement - 1 );
        // Divide data recursively
        divideData(A,0,numberOfElement -1 );
        // Display sorte data
        cout<<"Sorted data:";
        displayData(A, 0, numberOfElement -1);
    
        // Free array
        free(A);
    }
    return 0;
}


/*
 Function: divideData( <input Array> , <low index>, <high index> )
 */
void divideData(int *A, int low, int end )
{
    
    // stop recursive call when 2 element exist, low=0,end=1
    if ( end - low < 1 )
    {
        return;
    }
    int mid =( low + end ) / 2;
    
    // Split data recursively till it reaches to 1 elment and then backtrack to merge result.
    // First part ( 0 - mid )
    divideData( A, low, mid );
    // Second part (mid+1) - end
    divideData( A, mid + 1, end);
    // Merge the result
    mergeData( A, low, mid, end);
}



void mergeData( int *A, int low, int mid, int end )
{
    int lowIndex =low;
    int midIndex =mid;
    int endIndex =end;
    int startIndexSecondList = mid + 1; // Start index of second list
    int bufferIndex = 0;
    // Allocate memory for temporary buffer
    int *buffer = (int*) calloc( (end + 1), sizeof(int));
    // Display data before merge
    displayData(A, low, end);
    
    while ( lowIndex <= midIndex && startIndexSecondList <= endIndex )
    {
        if(A[lowIndex] < A[startIndexSecondList])
        {
            buffer[bufferIndex] = A[lowIndex];
            lowIndex++;
        }
        else
        {
            buffer[bufferIndex] = A[startIndexSecondList];
            startIndexSecondList++;
        }
        bufferIndex++;
    }
   // Fillup remaining part of first list into buffer
   while ( lowIndex <= midIndex)
    {
        buffer[bufferIndex] = A[lowIndex];
        lowIndex++;
        bufferIndex++;
    }
    // Fillup remaining part of second list into buffer.
    while ( startIndexSecondList <= endIndex)
    {
        buffer[bufferIndex] = A[startIndexSecondList];
        startIndexSecondList++;
        bufferIndex++;
    }
    // Copy sorted elements from buffer to original array A
    bufferIndex = 0;
    for ( lowIndex = low; lowIndex <= end ; lowIndex++)
    {
        A[lowIndex] = buffer[bufferIndex++];
    }
    
    // Free memory for temporary buffer
    free(buffer);
    // Dispaly sorted merged data
    displayData(A,low,end);
}

/*
 Function Name: displayData(<list of elements>, < low index>, < high index>)
 */
void displayData(int *A, int low, int end)
{
    for(int index=low; index<= end; index++)
    {
        cout<<A[index]<<" ";
    }
    cout<<endl;
}

