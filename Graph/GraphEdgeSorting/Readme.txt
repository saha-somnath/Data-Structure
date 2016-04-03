1. Implementation of Heap and Heapsort for unsorted list of edges of Graph G in Graph.pdf.
  
a. Soring of Graph edges using HeapSort:
   

b. Compilation of the program.
   Compiler: gcc/g++
   Environment: Mac/ Linux( Ubuntu - 14.10) 
   
  %> g++ main.C 

c. Input format.
  
   Input File: inputList.txt 
   <No Testcases>
   <No Of Adjacent Edges>
   <Vertex U> <Adjacent Node V> < Weight of U,V edge >

   Sample Input:
   9
   3
   A B 22 C 9 D 12
   4
   B A 22 C 35 F 36 H 34
   5
   C A 9 B 35 D 4 E 65 F 42
   4
   D A 12 C 4 E 33 I 30
   4
   E C 65 D 33 F 18 G 23
   5
   F B 36 C 42 E 18 G 39 H 24
   4
   G E 23 F 39 H 25 I 21
   4
   H B 34 F 24 G 25 I 19
   3
   I D 30 G 21 H 19

c. Execution: 
   Program can be executed as below.
   %>./a.out < inputList.txt 
   
   OR a shell script which executes program and shows execution time in milli seconds.
   %>./runProgram 
   
c. Testing:
   Result should show heapified list as well as Sorted list of edges in ascending order.

   %>./a.out < inputList.txt 
   Heapified List: 65 42 39 36 33 23 34 25 35 22 30 12 18 4 24 9 21 19
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65
   %>./runProgram 
   Heapified List: 65 42 39 36 33 23 34 25 35 22 30 12 18 4 24 9 21 19
   Sorted List   : 4 9 12 18 19 21 22 23 24 25 30 33 34 35 36 39 42 65

   Execution Time:7 milliseconds

