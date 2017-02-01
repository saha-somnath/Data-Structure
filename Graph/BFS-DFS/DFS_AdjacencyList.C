//
//  main.cpp
//  BFS
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>

using namespace std;

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
    // Search Graph
    void startDFS( int startVertex);
    void DFS( int vertex, bool * explored);
    
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
    return 1;
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

void Graph::startDFS( int startVertex)
{


       
    bool *explored = new bool[numberOfVertices];
    // Default set all vertices as 0
    for ( int index = 0; index<numberOfVertices; index++ )
    {
        explored[index] = 0;
    }
    
    DFS( startVertex, explored);

    // Delete explored 
    delete [] explored;
    
}

void Graph::DFS( int vertex, bool * explored)
{
    explored[vertex] = true;
    cout<<"Explored:"<<vertex<<endl;

    list<int>::iterator it;
    for( it=AdjacencyList[vertex].begin(); it != AdjacencyList[vertex].end(); it++ )
    {
        if( ! explored[*it] )
        {
            DFS(*it, explored);
        }
    }
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
    G.startDFS( 1);
    
    return 0;
}

