//
//  Graph.h
//  HeapSort
//
//  Created by Somnath Saha on 3/16/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#ifndef Graph_h
#define Graph_h


#include<iostream>
#include<string.h>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

// Structure of a Adjacency List Node
//  | Name Of Vertex | Edge Weight | Link To Next Node |
typedef struct AdjacentNode
{
    //Name Of Vertex
    char nameOfVertex;
    // Edge Weight
    int edgeWeight;
    //Link To Next Node? Default: NULL
    AdjacentNode * nextNodePtr;
    
} AdjacencyListNode;

// An extra map to vertex and check if that vertex is visited?
map<char, bool> isVertexVisited;


class Graph
{
    int numberOfVertices;
    // Map having 2 element < Vertex Name, { Adj Name Of Vertex , Edge Weight , Link To Next Node } >
    map<char, AdjacentNode *> AdjacencyList;
public:
    Graph() {}
    Graph( int V):numberOfVertices(V)
    {
    }
    // Destructor
    ~Graph()
    {
        map<char, AdjacentNode *>::iterator itAdjacencyList;
        // Remove dynamically allocated memory for list
        for(itAdjacencyList= AdjacencyList.begin(); itAdjacencyList != AdjacencyList.end(); itAdjacencyList++)
        {
            delete [] itAdjacencyList->second;
        }
        
    }
    
    // Complete the Graph Creation with Adjacency List Representation
    int createWeightedConnectedGraph();
    // Add edge between 2 vertices
    void displayGraph();
    
    int* getUnSortedEdgeList(int numberOfEdges);
   
};


#endif /* Graph_h */

