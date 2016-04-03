1. Implemented the Heap and Heapsort for unsorted list.
   - Program has been compiled in personal Mac( v 10.11.3, Kernel Version 15.3.0)
   /Linux( Ubuntu v 14.04.1 ) machine.   

a. Compilation of the program.
   Compiler: gcc/g++
   Environment: Mac/ Linux( Ubuntu - 14.10) 
   
  %> g++ Heapsort.C 

b. Input format.
   Input File: inputList.txt contains the 5 testcase
   <No Testcases>
   <No Of Element>
   <Unsorted list>
   ---------------------------------------------------
   Input File: inputList.txt
   ---------------------------------------------------
   5
   18
   22 9 12 35 4 34 36 42 65 33 30 18 23 39 24 25 21 19
   18
   22 9 12 35 4 36 42 65 33 18 23 39 24 25 21 34 30 19
   18
   12 4 33 30 9 65 23 21 22 35 42 18 39 25 19 36 24 34
   18
   22 35 36 34 9 42 24 12 4 65 18 39 25 19 23 30 21 34
   18
   4 33 30 9 65 23 21 22 35 42 12 18 39 25 19 36 24 34

   ---------------------------------------------------
   Input File: TestFile.txt
   ---------------------------------------------------
   5
   10
   9 2 9 11 21 20 31 5 8 4
   5
   21 20 9 11 31
   15 
   11 5 8 4 21 20 31 18 13 7 9 25 17 34 2
   8
   31 18 13 4 20 7 9 25
   12
   8 4 21 20 31 5 18 13 7 9 15 5
   

c. Execution.
   %> ./a.out < inputList.txt 
   %> ./a.out < TestFile.txt 

d. Testing:
   
   ----------------------------------------------------------------
   Test 1:
   ----------------------------------------------------------------   

   % ./a.out < inputList.txt 
   T/C->1
   Heapified List: 65 42 39 36 33 23 35 25 22 4 30 12 18 34 24 9 21 19
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65
   Execution Time: 0.02 Milliseconds

   T/C->2
   Heapified List: 65 42 39 34 23 36 35 33 22 4 18 12 24 25 21 9 30 19
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65
   Execution Time: 0.016 Milliseconds

   T/C->3
   Heapified List: 65 42 39 36 35 33 25 24 34 9 30 12 18 23 19 4 22 21
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65
   Execution Time: 0.016 Milliseconds

   T/C->4
   Heapified List: 65 42 39 34 34 36 24 22 30 9 18 35 25 19 23 12 21 4
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 34 34 35 36 39 42 65
   Execution Time: 0.017 Milliseconds

   T/C->5
   Heapified List: 65 42 39 36 35 30 25 33 34 9 12 18 23 21 19 4 24 22
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65
   Execution Time: 0.016 Milliseconds
  
   ---------------------------------------------------
   Test 2
   ---------------------------------------------------
   %> ./a.out < TestFile.txt 
   T/C->1
   Heapified List: 31 11 21 8 9 9 20 2 5 4
   Sorted List   : 2 4 5 8 9 9 11 20 21 31
   Execution Time: 0.01 Milliseconds

   T/C->2
   Heapified List: 31 21 9 11 20
   Sorted List   : 9 11 20 21 31
   Execution Time: 0.005 Milliseconds

   T/C->3
   Heapified List: 34 18 31 13 9 21 25 4 11 5 7 8 17 20 2
   Sorted List   : 2 4 5 7 8 9 11 13 17 18 20 21 25 31 34
   Execution Time: 0.01 Milliseconds

   T/C->4
   Heapified List: 31 25 13 20 18 7 9 4
   Sorted List   : 4 7 9 13 18 20 25 31
   Execution Time: 0.006 Milliseconds

   T/C->5
   Heapified List: 31 21 18 13 20 5 8 4 7 9 15 5
   Sorted List   : 4 5 5 7 8 9 13 15 18 20 21 31
   Execution Time: 0.031 Milliseconds


   
