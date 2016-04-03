
1. Implementation of Single Source Shortest Path Dijkstra Algorithm. 

a. Language Used: C++

b. Compilation of the program.
   Compiler: gcc/g++
   Environment: Mac/ Linux( Ubuntu - 14.10) 
   
  %> g++ main.C 

c. Input format.
   Input is the one of the AdjacencyList representation of the graph G in Graph.pdf
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
  
   

d. Execution:
            Program can be executed as below.
            %>./a.out < inputList.txt 
            
            OR a shell script which executes program and shows execution time in milli seconds.
            %>./runProgram 

e. Testing:
	%> ./a.out < input.txt 
	Destination Node B: path value = 22, path is: A->B
	Destination Node C: path value = 9, path is: A->C
	Destination Node D: path value = 12, path is: A->D
	Destination Node E: path value = 45, path is: A->D->E
	Destination Node F: path value = 51, path is: A->C->F
	Destination Node G: path value = 63, path is: A->D->I->G
	Destination Node H: path value = 56, path is: A->B->H
	Destination Node I: path value = 42, path is: A->D->I
        
        %> ./runProgram 
	Destination Node B: path value = 22, path is: A->B
	Destination Node C: path value = 9, path is: A->C
	Destination Node D: path value = 12, path is: A->D
	Destination Node E: path value = 45, path is: A->D->E
	Destination Node F: path value = 51, path is: A->C->F
	Destination Node G: path value = 63, path is: A->D->I->G
	Destination Node H: path value = 56, path is: A->B->H
	Destination Node I: path value = 42, path is: A->D->I

	Execution Time:8 milliseconds
   



