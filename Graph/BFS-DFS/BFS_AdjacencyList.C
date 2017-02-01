//
//  main.cpp
//  BSF
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
#include <queue>

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
    void BSF( int startVertex );
    
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

// Iterative approach , Time complexity O(V+E) 
void Graph::BSF( int startVertex)
{
   
    bool *explored = new bool[numberOfVertices];
    // Default set all vertices as 0
    for ( int index = 0; index<numberOfVertices; index++ )
    {
        explored[index] = 0;
    }
    
    queue<int> Q;
    Q.push(startVertex);
    explored[startVertex] = 1; // Because first eelemnt has been pushed into the queue

    while (! Q.empty())
    {
        int v = Q.front();
        Q.pop();

        cout<<"Explored:"<<v<<endl;

        list<int>::iterator it;
        for( it=AdjacencyList[v].begin(); it != AdjacencyList[v].end(); it++ )
        {
            if( ! explored[*it] )
            {
                explored[*it] =  1;
                Q.push(*it);
            }
        }
    }

    // Delete explored 
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
    
    // Call BSF
    G.BSF(1);
    
    return 0;
}

