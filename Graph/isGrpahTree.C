//
//  main.cpp
//  isGraphTree
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
#include <queue>

using namespace std;


/*
 Create a Graph using Adjacency List
*/
class Graph
{
    int numberOfVertices;
    list<int> *AdjacencyList;
public:
    Graph()
    {
        AdjacencyList    = NULL;
        numberOfVertices = 0;
    }
    Graph( int V)
    {
        // set vertices number
        numberOfVertices = V;
        // Create graph through adjacency list
        AdjacencyList = new list<int>[V];
    }
    // Destructor
    ~Graph()
    {
        // Delete each row
        if ( AdjacencyList != NULL)
        {
            for ( int index=0; index< numberOfVertices; index++)
            {
                AdjacencyList[index].clear();
            }
        }
    }
    
    // Add edge between 2 vertices
    void addEdge( int V1, int V2);
    // Is edge connected?
    bool isEdgeConnected( int V1, int V2 );
    // Search Graph and check if that is tree
    bool BSF( int startVertex );
    
};

// Add edge
void Graph::addEdge( int U, int V )
{
    cout<<"Add edge: "<< U <<"<=>" <<V <<endl;
    // Undirected graph, so both need to consider both the direction
    AdjacencyList[U].push_back(V);
    AdjacencyList[V].push_back(U);
}


/* Check if vertices are connected
 Might take O(E) time complexity to check connectivity.
*/
bool Graph::isEdgeConnected(int U, int V )
{
    list<int>::iterator it;
    for( it=AdjacencyList[U].begin(); it != AdjacencyList[U].end(); it++ )
    {
        if( *it ==  V )
        {
            return 1;
        }
    }
    return 0;
}

/* Iterative approach , Time complexity O(V+E)
 Check Graph is Tree: 
                1. Check if any node has two parents
                2. Adjacency List: In case of tree all the nodes will be checked twice
                  while checing each node using BFS. So total checking should be 2* number of node, 
                  In case of graph it should be >  2* number of node
*/
bool Graph::BSF( int startVertex)
{
    
    bool *enqueuedNodeList = new bool[numberOfVertices];
    // Default set all vertices as 0
    for ( int index = 0; index<numberOfVertices; index++ )
    {
        enqueuedNodeList[index] = 0;
    }
    
    queue<int> Q;
    Q.push(startVertex);
    enqueuedNodeList[startVertex] = 1; // Because first eelemnt has been pushed into the queue
    
    //int nodeCount = 1; // for the first node as that has been enqueued
    
    while (! Q.empty())
    {
        int v = Q.front();
        Q.pop();
        
        //cout<<"Visited:"<<v<<endl;
       
        int visitCount = 0;
        for( auto & node : AdjacencyList[v] )
        {
            //nodeCount++;// Increament node
            // Is node already enqued in the Q
            if( ! enqueuedNodeList[node] )
            {
                enqueuedNodeList[node] =  1;
                Q.push(node);
            }
            else
            {
            // Checking the parent, more than one parent is graph
            // Check if visited adjacent node more than one
                if (++visitCount == 2 )
                {
                    return false;
                }
            }
        }
    }
    
    // Delete explored
    delete [] enqueuedNodeList;
    
    /*cout <<"Node Visit Count:"<<nodeCount<<endl;
    if ( nodeCount > 2 * numberOfVertices)
    {
        return false;
    }*/
    
    return true; // Its tree
}

int main(int argc, const char * argv[]) {
    
    // Create a Graph object
    Graph G(6);
    G.addEdge(0,2);
    G.addEdge(0,4);
    G.addEdge(2,3);
    G.addEdge(3,5);
    G.addEdge(2,1);
    //G.addEdge(5,1);
    
    // Call BSF
    cout<<"Is Graph a Tree? ";
    if ( G.BSF(1) )
    {
        cout <<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}





