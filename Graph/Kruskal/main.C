//
//  main.cpp
//  Kruskal
//
//  Created by Somnath Saha on 3/13/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#include <iostream>
#include "Graph.h"


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
    
    // Apply Kruskal
    G.Kruskal('A');
    
    return 0;
}

/**********************************************************************************
 *Function Name: Graph::Kruskal(char startVertex)                                 *
 *Input Arg    : char startVertex                                                 *
 *Return       : None                                                             *
 *Descripttion : Apply Kruskal's MST algorithm to find MST from a Graph           *
 *********************************************************************************/
void Graph::Kruskal(char startVertex)
{
    // Start with initialization of Distance Cost Array
    // Create distance cost list for all the node
    map<char, AdjacentNode *>::iterator itAdjacencyList;
    uvNode *uvNodePtr;
    
    //Step1: Get the edges from adjacency list and sort edges in ascending order.
    // Read Adjacency List and create a sorted list with {(U,V), Edge Cost}
    for(itAdjacencyList= AdjacencyList.begin(); itAdjacencyList != AdjacencyList.end(); itAdjacencyList++)
    {
        // Create a UV Node  i.e Source, Destination Vertex and distance
        AdjacentNode * AdjacecntListPtr = itAdjacencyList->second;
        
        // Iterate through the list
        while (AdjacecntListPtr != NULL)
        {
            // Print Vertex name , Weight of the edge
            if ( isVertexVisited[AdjacecntListPtr->nameOfVertex] == false)
            {
                // Cont we check if the duplicate entry exist?
                uvNodePtr = new uvNode;
                uvNodePtr->vertexU = itAdjacencyList->first; // Source Node
                uvNodePtr->vertexV = AdjacecntListPtr->nameOfVertex; // Adjacent vertex
                uvNodePtr->edgeWeight = AdjacecntListPtr->edgeWeight; // Edge Weight from source U
            
                vector<uvNode*>::iterator itVector;
                itVector = uvNodeVector.begin();
                // Find out insert position into the vector
                for ( int iVector = 0; iVector< uvNodeVector.size(); iVector++)
                {
                    if ( uvNodeVector[iVector]->edgeWeight > uvNodePtr->edgeWeight )
                    {
                        break;
                    }
                    itVector++;
                }
                if ( itVector == uvNodeVector.end())
                {
                    uvNodeVector.push_back(uvNodePtr); // Push the node to the vector
                }
                else
                {
                    uvNodeVector.insert(itVector,  uvNodePtr);
                }
            }
            // Traverese next node of Adjacent LinkedList
            AdjacecntListPtr = AdjacecntListPtr->nextNodePtr;
        }
        // Update isVertexVisited if it has been explored
        isVertexVisited[itAdjacencyList->first] = true;
    }
    
    
    // Step2: Apply to Kruskal
    // Step2.1: Create (V = Total Vertex) disjoint sets and initialize with default values
    disjointSet *disjointSetPtr = new disjointSet[numberOfVertices];
    map<char,bool>::iterator it;
    int indexSet = 0;
    for( it= isVertexVisited.begin(); it != isVertexVisited.end(); ++it )
    {
        // Add the node to the parent node of the sub sets.
        disjointSetPtr[indexSet].parentNodeOfSet = it->first;
        // Initially rank of each set should be 1 as it indicate only one node in the set.
        disjointSetPtr[indexSet].rank = 1;
        // Initally link to subSet is a single space to indicate not linked
        disjointSetPtr[indexSet].linkToSubset = indexSet ;
        // Initially subSet contains nothing
        disjointSetPtr[indexSet].subSet = it->first;
        
        indexSet++; // Increase Index Set
    }

    int edgeCount = 0;
    // Foreach edge in the sorted list connect the nodes with edge.
    for ( int iVector = 0; iVector < uvNodeVector.size(); iVector++)
    {
        
        // Connect the nodes with edges in ascending order such that no cycle forms for all the nodes.
        
        // Get the vertices for each edge
        char vertexU = uvNodeVector[iVector]->vertexU;
        char vertexV = uvNodeVector[iVector]->vertexV;
        
        // Call find set to get index of the subset
        int indexSetU = findSet(disjointSetPtr, vertexU, numberOfVertices);
        int indexSetV = findSet(disjointSetPtr, vertexV, numberOfVertices);
        
        // If both parent node of subset is same, then graph contains cycle
        if( ! (indexSetU == indexSetV) )
        {
            edgeCount++;
            // Check the rank of setU and setV , Union both set based on higher rank
            // Lower rank set would be merged with the higher rank set
            
            if ( disjointSetPtr[indexSetU].rank > disjointSetPtr[indexSetV].rank)
            {
                // Merger subset V  -> Set U : Us{Us,Vs}
                disjointSetPtr[indexSetU].subSet.append(disjointSetPtr[indexSetV].subSet);
                // Increase rank of U with the number of newly added nodes
                disjointSetPtr[indexSetU].rank += disjointSetPtr[indexSetV].subSet.length();
                // Set the rank to 0 as subSet U geeting merged to subSet V
                disjointSetPtr[indexSetV].rank = 0;
                // Update linkToSubset field to indicate new parent node
                disjointSetPtr[indexSetV].linkToSubset = indexSetU;
            }
            else
            {
                // Merger subset U  -> Set V : Vs{Vs,Us}
                disjointSetPtr[indexSetV].subSet.append(disjointSetPtr[indexSetU].subSet);
                // Increase rank of V with the number of newly added nodes
                disjointSetPtr[indexSetV].rank += disjointSetPtr[indexSetU].subSet.length();
                // Set the rank to 0 as subSet U geeting merged to subSet V
                disjointSetPtr[indexSetU].rank = 0;
                // Update linkToSubset field to indicate new parent node
                disjointSetPtr[indexSetU].linkToSubset = indexSetV;
                
            }
            
            // Indicate the sorted edge is going to be used of MST
            uvNodeVector[iVector]->isBelogToMST = true;
            
        }
       
        // Exit iteration once all the nodes have been connected by V - 1 edges
        if ( edgeCount == (numberOfVertices - 1) )
        {
            break;
        }
            
    }
    
    //Step3: Print the result of Kruskal-MST
    // Iterate the vector
    int totalWeightMST = 0;
    string edgeSetMST  = "";
    string  vertexSet;
    for( int iVector = 0; iVector < uvNodeVector.size(); iVector++)
    {
        // get the edges based on the field isBelogToMST
        if ( uvNodeVector[iVector]->isBelogToMST )
        {
            // Add the edge weight to the Total Cost
            totalWeightMST += uvNodeVector[iVector]->edgeWeight;
            // Node set
            size_t charPosition;
            if ( (charPosition = vertexSet.find(uvNodeVector[iVector]->vertexU)) == std::string::npos)
            {
                vertexSet += uvNodeVector[iVector]->vertexU;
                vertexSet += ", ";
            }
            if( (charPosition = vertexSet.find(uvNodeVector[iVector]->vertexV)) == std::string::npos)
            {
                vertexSet += uvNodeVector[iVector]->vertexV;
                vertexSet += ", ";
            }
            
            // Edge set
            string edge;
            edge += uvNodeVector[iVector]->vertexU;
            edge += '-';
            edge += uvNodeVector[iVector]->vertexV;
            edge += ' ';
            edgeSetMST.append(edge);
        }
    }
    
    // Print finally
    cout<<"Minimum Spanning Tree: Total weights on MST edges = "<<totalWeightMST<<endl;
    // Remove last 2 char which extra conatins ", "
    vertexSet.erase(vertexSet.length() - 2 , 2  );
    // Node List Of MST
    cout<<"Node Set = {"<< vertexSet <<"}"<<endl;
    // Edge List of MST
    cout<<"Edge Set = { "<<edgeSetMST<<"}"<<endl;
    
    // Free dynamicaly allocated memory
    
    // Free dynamic memory allocated for uvNodeVector vector
    for( int iVector = 0; iVector< uvNodeVector.size() ; iVector++)
    {
        delete [] uvNodeVector[iVector];
    }
    // Free memory allocated for disjoint sets
    delete [] disjointSetPtr;
    
}

/**********************************************************************************
 *Function Name : findSet( disjointSet* disjointSetPtr, char checkVertexInSets,   *
                  int numberOfVertices )                                          *
 *Input Argument: < Pointer to Disjoint Set>,<Vertex Name>,<Vertex Number>        *
 *Return        : Index of Subset                                                 *
 *Description   : find the index of set for Vertex from all disjoint set          *
 *********************************************************************************/

int findSet( disjointSet* disjointSetPtr, char checkVertexInSets, int numberOfVertices )
{
    int indexOfSetParentNode = 0;
    // Check each subset
    for( int indexSet = 0; indexSet < numberOfVertices ; indexSet++)
    {
        // Find the matching parent for subset
        if ( disjointSetPtr[indexSet].parentNodeOfSet == checkVertexInSets)
        {
            // Check if Rank > 0 , that's mean its still disjoint set, not merged to any set
            if ( disjointSetPtr[indexSet].rank > 0)
            {
                indexOfSetParentNode = indexSet;
            }
            else{
                // If rank is zero, retrun linkToSubset
                indexOfSetParentNode = getSubSetLink( disjointSetPtr,disjointSetPtr[indexSet].linkToSubset);
            }
            break;
        }
    }
    
    return indexOfSetParentNode;
}


/**********************************************************************************
 *Function Name : getSubSetLink(disjointSet* disjointSetPtr, int indexOfSubSet)   *
 *Input Argument: < Pointer to Disjoint Set>,<Index Of Subset>                    *
 *Return        : Index of Subset                                                 *
 *Description   : Get the Subset Index recursively based on rank. rank=0, it looks*
                  for index of the parent subset to which it was unioned          *
 *********************************************************************************/

int getSubSetLink(disjointSet* disjointSetPtr, int indexOfSubSet)
{
    if ( disjointSetPtr[indexOfSubSet].rank  == 0 )
    {
        return getSubSetLink(disjointSetPtr, disjointSetPtr[indexOfSubSet].linkToSubset);
    }
    return indexOfSubSet;
}

/**********************************************************************************
 *Function Name :Graph::createWeightedConnectedGraph(int noOfVertices)            *
 *Input Argument: None                                                            *
 *Output        : None                                                            *
 *Description   : Create a Connected Weighted Graph suing Adjacency List          *
 *********************************************************************************/

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
 *Function Name: void Graph::displayGraph()                                       *
 *Input Arg    : None                                                             *
 *Return       : None                                                             *
 *Descripttion : Dispaly Graph                                                    *
 *********************************************************************************/
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

