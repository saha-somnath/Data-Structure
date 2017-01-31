//
//  main.cpp
//  BFS
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

/*
Program: BFS 
- Graph representation using Adjacency List
- Time Complexity: O( V^2 ) where V is number of vertices
*/

#include <iostream>
#include <stack>

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
    friend void DFS( Graph & G, int startVertex);
    
};

// Add edge
void Graph::addEdge( int U, int V )
{
    cout<<"Add edge: "<< U <<"<=>" <<V <<endl;
    AdjacencyMatrix[U] [V] = AdjacencyMatrix[V] [U] = 1;
}
// is vertices are connected
bool Graph::isEdgeConnected(int U, int V )
{
    return ( AdjacencyMatrix[U][V] == 1);
}

void DFS( Graph & G, int startVertex)
{
    bool *explored = new bool[G.numberOfVertices];
    // Default set all vertices as 0
    for ( int index = 0; index< G.numberOfVertices; index++ )
    {
        explored[index] = 0;
    }
    
    std::stack<int> dfsStack;
    // Enqueue start element in te queue
    dfsStack.push(startVertex);
    
    explored[startVertex] = true;
    // Check the adjacent of start vertex
    while(! dfsStack.empty())
    {
        // Start with the specified vertex
        int vertex = dfsStack.top();
        // Pop the element out
        dfsStack.pop();
        cout<<"Vertex->"<<vertex<<" has been explored"<<endl;
        //explored[vertex] = true;
        
        // Check for the adjacent verties
        for ( int index = 0; index< G.numberOfVertices; index++)
        {
            if ( G.AdjacencyMatrix[vertex][index] && ! explored[index] )
            {
                // Push the element inot the bfsQueue
                dfsStack.push( index );
                // make it explored
                explored[index] = 1;
                //cout<<"Vertex->"<<index<<" has been explored"<<endl;
            }
        }
    }
    // Delete explore
    delete [] explored;
}


int main(int argc, const char * argv[]) {
    
    // Create a Graph object
    Graph G(8);
    G.addEdge(0,2);
    G.addEdge(0,7);
    G.addEdge(2,3);
    G.addEdge(3,5);
    G.addEdge(2,1);
    G.addEdge(5,1);
    
    // Call BFS
    DFS( G, 1);
    
    return 0;
}

