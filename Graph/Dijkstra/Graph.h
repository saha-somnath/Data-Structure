//
//  Graph.h
//  Dijkstra
//
//  Created by Somnath Saha on 3/12/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include<iostream>
#include<string.h>
#include<cstdio>
#include<map>

using namespace std;

// Structure of a Adjacency List Node
//  | Name Of Vertex | Edge Weight | Link To Next Node |
typedef struct AdjacentNode
{
    //Name Of Vertex
    char nameOfVertex;
    // Edge Weight
    int edgeWeight;
    //Link To Next Node
    AdjacentNode * nextNodePtr;
} AdjacencyListNode;

// distanceCost structure
typedef struct distanceCost
{
    // Shortest path from source.
    string shortestPath;
    // Minimum distance cost from source
    int cost;
    // Check if the node is visited or not
    bool isVisited;
}distanceCost;

// Hold the element as < vertex name, { Name of Vertext, Edge Cost, Adj Node Ptr}>
map<char,distanceCost *> dCost;

/**********************************************************************************
 *Function Name: void displayShortestPathAndCost()
 *Input Arg    : char source vertex
 *Return       : None
 *Descripttion : Dispaly shortest path and cost for each node from source node
 **********************************************************************************/
void displayShortestPathAndCost(char sourceVertex);

/**********************************************************************************
 *Function Name: char getMinCostAdjacentNode()
 *Input Arg    : None
 *Return       : type char, minimum distance cost
 *Descripttion : Get the minimum cost of adjacent vertex from distance cost list
 **********************************************************************************/
char getMinCostAdjacentNode();

/**********************************************************************************
 *Function Name: void destroyDistanceCost()
 *Input Arg    : None
 *Return       : None
 *Descripttion : Destroy distance cost array
 **********************************************************************************/
void destroyDistanceCost();


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
    // Run Dijkstra algorithm to findout shortest path from source to destination.
    void dijkstra( char sourceVertex );
    
};



#endif /* Graph_h */

