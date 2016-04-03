//
//  Graph.h
//  Kruskal
//
//  Created by Somnath Saha on 3/13/16.
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


/**********************************************************************************
 *Structure Name : typedef struct uvNode                                          *
 *Elements       : <Source Vertex>,<Destination Vertex>, <Edge Weight>,           *
                   <Edge Belongs To MST>                                          *
 *Description    : Disjoint Set Used To Check Any Cycle if present into the Graph *
 Initially starts with V subsets. Gradually merge to a single                     *
 set which is the MST having V - 1 connecting all the V nodes                     *
 *********************************************************************************/

typedef struct uvNode
{
    // Source Vertex
    char vertexU;
    // Adjacent Vertex
    char vertexV;
    int edgeWeight;
    bool isBelogToMST;
}uvNode;

vector<uvNode*> uvNodeVector;

// An extra map to vertex and check if that vertex is visited?
map<char, bool> isVertexVisited;

/**********************************************************************************
 *Structure Name : typedef struct disjointSet                                     *
 *Elements       : <Parent Node of Subset>,<Rank>, <link To Subset>, <nodes>      *
 *Description    : Disjoint Set Used To Check Any Cycle if present into the Graph *
                   Initially starts with V subsets. Gradually merge to a single   *
                   set which is the MST having V - 1 connecting all the V nodes   *
 *********************************************************************************/

typedef struct disjointSet
{
    // Parent node of the set
    char parentNodeOfSet;
    // Rank of set is based on number of nodes , edge = nodes - 1
    // Initial Value = 1, indicates only one node in the disjoint set
    // rank = 0 indicates subset has merged to other subset.
    int rank;
    // Contains the index of the subset to which it is linked. Default: 0
    int linkToSubset;
    // A subset containing all the nodes.
    string subSet;
    
} disjointSet;

/**********************************************************************************
 *Function Name : findSet( disjointSet* disjointSetPtr, char checkVertexInSets,   *
 int numberOfVertices )                                          *
 *Input Argument: < Pointer to Disjoint Set>,<Vertex Name>,<Vertex Number>        *
 *Return        : Index of Subset                                                 *
 *Description   : find the index of set for Vertex from all disjoint set          *
 *********************************************************************************/

int findSet( disjointSet* disjointSetPtr, char checkVertexInSets, int numberOfVertices);

/**********************************************************************************
 *Function Name : getSubSetLink(disjointSet* disjointSetPtr, int indexOfSubSet)   *
 *Input Argument: < Pointer to Disjoint Set>,<Index Of Subset>                    *
 *Return        : Index of Subset                                                 *
 *Description   : Get the Subset Index recursively based on rank. rank=0,it looks *
                  for index of the parent subset to which it was unioned          *
 *********************************************************************************/
int getSubSetLink(disjointSet* disjointSetPtr, int indexOfSubSet);


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
    void createWeightedConnectedGraph();
    // Add edge between 2 vertices
    void displayGraph();
    // Run Kruskal Algorithm
    void Kruskal(char startNode);
};

#endif /* Graph_h */

