//
//  HeapSort.h
//  Kruskal
//
//  Created by Somnath Saha on 3/13/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

// Include any system framework and library headers here that should be included in all compilation units.
// You will also need to set the Prefix Header build setting of one or more of your targets to reference this file.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<ctime>
#include "Graph.h"


using namespace std;

void heapify(int* A, size_t start, size_t end);
void buildHeap(int* A, size_t iStart, size_t iEnd);
void shiftUp(int* A, size_t iRoot);
void heapSort(int* A, size_t start, size_t end);
void displayData(int *A, size_t low, size_t end);

#endif /* HeapSort_h */

