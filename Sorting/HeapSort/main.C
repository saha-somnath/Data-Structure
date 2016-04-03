//
//  main.cpp
//  HeapSort
//
//  Created by Somnath Saha on 3/13/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#include <iostream>
#include "HeapSort.h"

int main(int argc, const char * argv[]) {
    
    
    size_t numberOfTestCases = 0;
    size_t numberOfElement   = 0;
    size_t startCPUTime      = 0;
    size_t endCPUTime        = 0;
    
    //cout<<"This program accepts standard inputs."<<endl;
    //cout<<"Pass the input file from commandline as: %> heapsort < list"<<endl;
    //cout<<"Pass input directly from standard input as\n<Number of TestCases>\n<Number Of Elemnet> \n<List of Numbers>"<<endl;
    // Read number of testcases
    scanf("%zd", &numberOfTestCases);
    
    // For each TestCase run the program
    for( int iTestCases = 0; iTestCases < numberOfTestCases ; iTestCases++)
    {
        cout<<"T/C->"<< iTestCases + 1 << endl;
        // Read number of element for a list
        scanf("%zd", &numberOfElement);
        // Dynamically allocate memory
        int * unHeapifiedList = (int*)calloc( numberOfElement, sizeof(int));
        
        for ( size_t index =0 ; index< numberOfElement; index++ )
        {
            scanf( "%d", &unHeapifiedList[index]);
        }
        
        // Take the start CPU time
        startCPUTime = clock();
        
        
        
        // Heapify List
        buildHeap( unHeapifiedList, 1, numberOfElement - 1);
        
        // Heapified list of data
        cout<<"Heapified List: ";
        displayData(unHeapifiedList, 0, numberOfElement - 1 );
        
        // HeapSort List
        heapSort(unHeapifiedList, 0 , numberOfElement - 1 );
        
        // End CPU time
        endCPUTime = clock();
        
        // Sorted data
        cout<<"Sorted List   : ";
        displayData(unHeapifiedList, 0, numberOfElement - 1 );
        
        // Free array
        free(unHeapifiedList);
        
        cout<<"Execution Time: "<< ((endCPUTime - startCPUTime)) /double(CLOCKS_PER_SEC)*1000<<" Milliseconds\n" << endl;
    }
    return 0;
}

