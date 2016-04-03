//
//  main.cpp
//  Dijkstra
//
//  Created by Somnath Saha on 3/12/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

/*
 Standard Input: Provided as ./a.out < input.txt
 Input File Format
 <No Of Vertices>
 <No of Adjacent Edges>
 <V1> <Edge Weight btn V1-V2> <V2> <Edge Wright btn V1-V3> <V3>
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
 
*/

#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Number of Vertices
    int noOfVertices;
    //Read Standard Input
    cin >> noOfVertices;
    // Create a Graph with specified noOfVertices
    Graph G(noOfVertices);
    // Create a Weighted Connected Undirected Graph
    G.createWeightedConnectedGraph();
    
    // Display Adjacency List
    //G.displayGraph();
    
    // Dijekstra <start node>
    G.dijkstra('A');
    
    // Display Shortest path for all the Vertext from source node.
    //displayShortestPathAndCost();
    
    // Destroy Distance Cost Array
    destroyDistanceCost();
    return 0;
}



/*************************************************************************
 *Function Name :Graph::createWeightedConnectedGraph(int noOfVertices)
 *Input Argument: None
 *Output        : None
 *Description   : Create a Connected Weighted Graph suing Adjacency List
 *************************************************************************/

void Graph::createWeightedConnectedGraph()
{
    int noOfEdges;
    int noOfVertices = numberOfVertices; // Private Member
    
    for(int iVertex=0; iVertex < noOfVertices; iVertex++)
    {
        // Read no of Edges from standard input
        cin >> noOfEdges;
        // Insert Vertex to AdjacenyList
        char vertexName;
        cin >> vertexName;
        
        // Add the adjacent vertices to a Linked-List structure
        AdjacentNode * ALNPtr = NULL;
        AdjacentNode * prevPtr = NULL;
        // Populate the adjacent node to the above list
        for (int iEdges = 0; iEdges < noOfEdges; iEdges++ )
        {
            // Create node
            AdjacentNode * newNodePtr = new AdjacentNode;
            // Take Vertex Name
            cin>>newNodePtr->nameOfVertex;
            // Read weight of the edge
            cin >> newNodePtr->edgeWeight;
            // Assign NULL pointer to nextNodePtr
            newNodePtr->nextNodePtr =  NULL;
            
            // In not first node link to head pointer
            if ( ALNPtr == NULL)
            {
                ALNPtr= newNodePtr;
            }
            else
            {
                // Link to the previous node
                prevPtr->nextNodePtr = newNodePtr;
            }
            // Update previous ptr to point new node only
            prevPtr = newNodePtr;
            
        }
        // Link the Adjacent Node List to AdjacencyList Array
        AdjacencyList[vertexName] = ALNPtr;
    }
}

/**********************************************************************************
 *Function Name: void Graph::displayGraph()
 *Input Arg    : None
 *Return       : None
 *Descripttion : Dispaly Graph
 **********************************************************************************/
void Graph::displayGraph()
{
    map<char, AdjacentNode *>::iterator itAdjacencyList;
    
    for(itAdjacencyList= AdjacencyList.begin(); itAdjacencyList != AdjacencyList.end(); itAdjacencyList++)
    {
        AdjacentNode * AdjacecntListPtr = itAdjacencyList->second;
        
        // Print the name of Vertex from AdjacencyListArray
        cout<<itAdjacencyList->first;
        
        // Iterate through the list
        while (AdjacecntListPtr != NULL)
        {
            // Print Vertex name , Weight of the edge
            cout<<"->"<<AdjacecntListPtr->nameOfVertex<<"("<<AdjacecntListPtr->edgeWeight<<")";
            // Traverese next node
            AdjacecntListPtr = AdjacecntListPtr->nextNodePtr;
        }
        cout<<endl;
    }
}

/**********************************************************************************
 *Function Name: dijkstra(char startVertex)                                       *
 *Input Arg    : char startVertex                                                 *
 *Return       : None                                                             *
 *Descripttion : Apply dijkstra algorithm to find out shortest path for all the   *
 *               nodes from source node                                           *
 **********************************************************************************/
void Graph::dijkstra(char startVertex )
{
    // Start with initialization of Distance Cost Array 
    // Create distance cost list for all the node
    map<char, AdjacentNode *>::iterator itAdjacencyList;
    
    for(itAdjacencyList= AdjacencyList.begin(); itAdjacencyList != AdjacencyList.end(); itAdjacencyList++)
    {
        // Update vertex name in dCost list and add distance cost element
        dCost[itAdjacencyList->first] = new distanceCost[1];
        // Initially set all vertex with infine cost or big amount, here 10000
        dCost[itAdjacencyList->first]->cost = 10000;
        // Set isVisited to false
        dCost[itAdjacencyList->first]->isVisited = false;
        // Set shortest path
        dCost[itAdjacencyList->first]->shortestPath = startVertex;
        
    }
    
    // Initialization - Updated cost of adjacent vertex of start vertex,
    // considering distance cost of start vertex is 0
    dCost[startVertex]->cost = 0;
    // Add start vertex to set S = { startVertex} by setting isVisited = true
    dCost[startVertex]->isVisited = true;
    
    //AdjacencyListNode * adjNodePtr = adjList[startVertexIndex].linkAdjacentNodes;
    AdjacencyListNode * adjNodePtr = AdjacencyList[startVertex];
    // Update cost for adjacent nodes for the first time
    while(adjNodePtr != NULL)
    {
        // Update cost for each adjacent nodes
        dCost[adjNodePtr->nameOfVertex]->cost = adjNodePtr->edgeWeight;
        
        // Update shortest path from source
        string shortestPathString;
        shortestPathString += startVertex;
        shortestPathString += "->";
        shortestPathString += adjNodePtr->nameOfVertex;
        
        dCost[adjNodePtr->nameOfVertex]->shortestPath = shortestPathString;
        
        adjNodePtr = adjNodePtr->nextNodePtr;
    }
    
    /////////////////////////////////////////////////////////////////
    // For each node in the list we perform
    char minCostVertex = ' ';
    
    while( (minCostVertex = getMinCostAdjacentNode()) != ' ')
    {
        // Mark that vertex as vissited
        dCost[minCostVertex]->isVisited =  true;
    
        // Get the link of adjacent list
        AdjacencyListNode * adjNodePtr = AdjacencyList[minCostVertex];

        // Update the cost of adjacent nodes
        while(adjNodePtr != NULL)
        {
            // Update cost for each adjacent nodes
            //D’(w) = min( D’(w), D(v) + c(v,w) )
            if ( dCost[adjNodePtr->nameOfVertex]->cost > dCost[minCostVertex]->cost + adjNodePtr->edgeWeight)
            {
                // Update distance cost D(v) + c(v,w)
                dCost[adjNodePtr->nameOfVertex]->cost = dCost[minCostVertex]->cost + adjNodePtr->edgeWeight;
                // Update shortest path to the distance  vector
                string shortestPathString;
                shortestPathString += dCost[minCostVertex]->shortestPath;
                shortestPathString += "->";
                shortestPathString += adjNodePtr->nameOfVertex;
        
                dCost[adjNodePtr->nameOfVertex]->shortestPath = shortestPathString;
            }
            adjNodePtr = adjNodePtr->nextNodePtr;
        }

    }

    // Display minimum cost and shortest path for source to all the nodes
    displayShortestPathAndCost(startVertex);
    // Display minimum cost and shortest path for specific Node
    //cout<<"Destination Node "<<destinationNode<<":";
    //cout<<"Path Value = " << dCost[destinationNode]->cost<<", ";
    //cout<<"path is: " << dCost[destinationNode]->shortestPath<<endl;
}

/**********************************************************************************
 *Function Name: char getMinCostAdjacentNode()                                    *
 *Input Arg    : None                                                             *
 *Return       : type char, minimum distance cost                                 *
 *Descripttion : Get the minimum cost of adjacent vertex from distance cost list  *
 *********************************************************************************/
char getMinCostAdjacentNode()
{
    // Iterate distance cost list
    map<char,distanceCost *>::iterator itDistanceCost;
    int minCost = 10000; // Take a big value or more than maximum edge
    char minCostVertexName = ' ' ;
    for(itDistanceCost= dCost.begin(); itDistanceCost != dCost.end(); ++itDistanceCost)
    {
        // First element char/vertexName , second element link <struct distanceCost>
        if ( ! (itDistanceCost->second)->isVisited && (itDistanceCost->second)->cost < minCost)
        {
            minCost = (itDistanceCost->second)->cost ;
            minCostVertexName = itDistanceCost->first;
        }
    }
   return minCostVertexName;
}

/**********************************************************************************
 *Function Name: void displayShortestPathAndCost()                                *
 *Input Arg    : None                                                             *
 *Return       : None                                                             *
 *Descripttion : Dispaly shortest path and cost for each node from source node    *
 **********************************************************************************/
void displayShortestPathAndCost(char sourceVertex)
{
    // Iterate distance cost list
    map<char,distanceCost *>::iterator itDistanceCost;
    for(itDistanceCost= dCost.begin(); itDistanceCost != dCost.end(); itDistanceCost++)
    {
        if ( ! ( itDistanceCost->first == sourceVertex ) )
        { 
            // First element char/vertexName , second element link <struct distanceCost>
            cout<<"Destination Node "<<itDistanceCost->first <<": ";
            cout<<"path value = "<<(itDistanceCost->second)->cost <<", ";
            cout<<"path is: "<<(itDistanceCost->second)->shortestPath<<endl;
        }
    }
}

/**********************************************************************************
 *Function Name: void destroyDistanceCost()
 *Input Arg    : None
 *Return       : None
 *Descripttion : Destroy distance cost array
 **********************************************************************************/
void destroyDistanceCost()
{
    // Free dynamically allocated memory
    map<char,distanceCost *>::iterator itDistanceCost;
    for(itDistanceCost= dCost.begin(); itDistanceCost != dCost.end(); itDistanceCost++)
    {
        // Update vertex name in dCost list and add distance cost element
        delete [] itDistanceCost->second;
    }
}

