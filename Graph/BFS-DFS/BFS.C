//
//  main.cpp
//  BFS
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

/*
Program: DFS
- Graph representation using Adjacency List
- Time Complexity: O(V^2) 
*/


#include <iostream>
#include <queue>

using namespace std;

class Graph
{
    int numberOfVertices;
    int **AdjacencyMatrix;
public:
    Graph()
    {
        AdjacencyMatrix = NULL;
    }
    Graph( int V)
    {
        // set vertices number
        numberOfVertices = V;
        // Create graph through adjacency matrixn
        AdjacencyMatrix = new int*[V];
        for ( int index =0; index< V; index++)
        {
            AdjacencyMatrix[index] = new int[V];
        }
        for ( int index =0; index<V; index++)
        {
            for ( int indexJ=0; indexJ < V; indexJ++)
                AdjacencyMatrix[index][indexJ] = 0;
        }
    }
    // Destructor
    ~Graph()
    {
        // Delete each row
        if ( AdjacencyMatrix != NULL)
        {
        for ( int index=0; index< numberOfVertices; index++)
        {
            if ( AdjacencyMatrix[index] )
            {
                delete [] AdjacencyMatrix[index];
            }
        }
        delete [] AdjacencyMatrix;
        }
    }
    
    // Add edge between 2 vertices
    void addEdge( int V1, int V2);
    // Is edge connected?
    bool isEdgeConnected( int V1, int V2 );
    // Search Graph
    friend void BFS( Graph & G, int startVertex);
    
};

// Add edge by joining 2 adjaent vertices
void Graph::addEdge( int U, int V )
{
    cout<<"Add edge: "<< U <<"<=>" <<V <<endl;
    // Connect U & V vertices, so assign 1 to (u,v) & (v,u) to indicate those vertices are connected.
    AdjacencyMatrix[U] [V] = AdjacencyMatrix[V] [U] = 1;
}
// is vertices are connected
bool Graph::isEdgeConnected(int U, int V )
{
    return ( AdjacencyMatrix[U][V] == 1);
}

void BFS( Graph & G, int startVertex)
{
    bool *enqueuedElement = new bool[G.numberOfVertices];
    // Default set all vertices as 0
    for ( int index = 0; index< G.numberOfVertices; index++ )
    {
        enqueuedElement[index] = 0;
    }
    
    std::queue<int> bfsQueue;
    // Enqueue start element in te queue
    bfsQueue.push(startVertex);
    // Make start vertex visited
    enqueuedElement[startVertex] = true;

    // Check the adjacent of start vertex
    while(! bfsQueue.empty())
    {
        // Start with the specified vertex
        int vertex = bfsQueue.front();
        // Pop the element out
        bfsQueue.pop();
        cout<<"Vertex->"<<vertex<<" has been explored"<<endl;
                
        // Check for the adjacent verties
        for ( int index = 0; index< G.numberOfVertices; index++)
        {
            if ( G.AdjacencyMatrix[vertex][index] && ! enqueuedElement[index] )
            {
                cout<<"pushed:"<<index<<endl;
                // Push the element into the bfsQueue
                bfsQueue.push( index );
                // make it Enqueued
                enqueuedElement[index] = 1;
            }
        }
    }
    // Delete explore
    delete [] enqueuedElement;
}


int main(int argc, const char * argv[]) {
    
    // Create a Graph object by adding edges 
    Graph G(8);
    G.addEdge(0,2);
    G.addEdge(0,7);
    G.addEdge(2,3);
    G.addEdge(3,5);
    G.addEdge(2,1);
    G.addEdge(5,1);
    
    // Call BFS & start traversing from vertex 1
    BFS( G, 1);
    
    return 0;
}

