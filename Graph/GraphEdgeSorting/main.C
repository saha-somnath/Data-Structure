//
//  main.cpp
//  HeapSort
//
//  Created by Somnath Saha on 3/16/16.
//  Copyright © 2016 Somnath Saha. All rights reserved.
//

#include "Graph.h"
#include "HeapSort.h"

int main(int argc, const char * argv[]) {
  
    // Number of Vertices
    int noOfVertices;
    // Toatl Number of Edges
    int totalNumberOfEdges = 0;
    
    //Read Standard Input
    cin >> noOfVertices;
    // Create a Graph with specified noOfVertices
    Graph G(noOfVertices);
    // Create a Weighted Connected Undirected Graph
    totalNumberOfEdges = G.createWeightedConnectedGraph();
    
    // Display Adjacency List
    //G.displayGraph();
 
    int* unSortedEdgeList;
    
    unSortedEdgeList = G.getUnSortedEdgeList(totalNumberOfEdges);
    
    
    // Heapify List
    buildHeap( unSortedEdgeList, 1, totalNumberOfEdges - 1);
    
    // Heapified list of data
    cout<<"Heapified List: ";
    displayData(unSortedEdgeList, 0, totalNumberOfEdges - 1 );
    
    // HeapSort List
    heapSort(unSortedEdgeList, 0 , totalNumberOfEdges - 1 );
    
    // End CPU time
    //endCPUTime = clock();
    
    // Sorted data
    cout<<"Sorted List   : ";
    displayData(unSortedEdgeList, 0, totalNumberOfEdges - 1 );


    return 0;
}


/**********************************************************************************
 *Function Name :Graph::createWeightedConnectedGraph(int noOfVertices)            *
 *Input Argument: None                                                            *
 *Return        : Total Number of edges                                           *
 *Description   : Create a Connected Weighted Graph suing Adjacency List          *
 *********************************************************************************/

int Graph::createWeightedConnectedGraph()
{
    int noOfEdges;
    int noOfVertices = numberOfVertices; // Private Member
    int totalNumberOfEdges = 0;
    
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
            // Increament edge count;
            totalNumberOfEdges++;
            
        }
        // Link the Adjacent Node List to AdjacencyList Array
        AdjacencyList[vertexName] = ALNPtr;
    }
    
    return totalNumberOfEdges / 2;
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

/**********************************************************************************
 *Function Name: Graph::getUnSortedEdgeList( int numberOfEdges)                   *
 *Input Arg    : <int numberOfEdges> Number Of Edges in the Graph                 *
 *Return       : <int*> - un sorted edge list                                     *
 *Descripttion : Dispaly Graph                                                    *
 *********************************************************************************/
int* Graph::getUnSortedEdgeList( int numberOfEdges)
{
    // Start with initialization of Distance Cost Array
    // Create distance cost list for all the node
    map<char, AdjacentNode *>::iterator itAdjacencyList;
    
    int* unsortedEdgeListPtr = new int[numberOfEdges];
    int edgeCount = 0;
    
    //Step1: Get the edges from adjacency list and sort edges in ascending order.
    // Read Adjacency List and create a sorted list with {(U,V), Edge Cost}
    for(itAdjacencyList= AdjacencyList.begin(); itAdjacencyList != AdjacencyList.end(); itAdjacencyList++)
    {
        // Create a UV Node  i.e Source, Destination Vertex and distance
        AdjacentNode * AdjacecntNodeListPtr = itAdjacencyList->second;
        
        // Iterate through the list
        while (AdjacecntNodeListPtr != NULL)
        {
            // Print Vertex name , Weight of the edge
            if ( isVertexVisited[AdjacecntNodeListPtr->nameOfVertex] == false)
            {
                unsortedEdgeListPtr[edgeCount++] = AdjacecntNodeListPtr->edgeWeight;
            }
            
            // Traverese next node of Adjacent LinkedList
            AdjacecntNodeListPtr = AdjacecntNodeListPtr->nextNodePtr;
        }
        // Update isVertexVisited if it has been explored
        isVertexVisited[itAdjacencyList->first] = true;
    }

    
    return unsortedEdgeListPtr;
}

/****************************************************************************
 Function Name : void buildHeap()                                           *
 Input Argument: int* unOrderedList, size_t startIndex, size_t endIndex     *
 Output        : Initial Heapified List                                     *
 Description   : This function Build initial heapified list based on        *
                 heap property                                              *
 ***************************************************************************/
void buildHeap(int* A, size_t iStart, size_t iEnd)
{
    size_t index;
    for ( index = iStart; index <= iEnd ; index++ )
    {
        // Index of element to check with parent.
        shiftUp(A, index);
    }
}

/****************************************************************************
 Function Name : void shiftUp()                                             *
 Input Argument: int* unOrdered List, size_t startIndex                     *
 Output        : Partial Heapified List                                     *
 Description   : This function Build initial heapified list based on        *
                 heap property                                              *
 ***************************************************************************/

void shiftUp(int *A, size_t iStart)
{
    size_t iParent = 0;
    if ( iStart >= 1 )
    {
        iParent = (iStart - 1) / 2;
    }
    
    // Check the element is greater than parent element an do it recursively
    // unless it reaches to root.
    if ( A[iStart] > A[iParent])
    {
        // Swap element
        int parent = A[iStart];
        A[iStart]  = A[iParent];
        A[iParent] = parent;
        // Call buildHeap function
        shiftUp(A, iParent);
    }
    return;
}

/****************************************************************************
 Function Name : void heapify()                                             *
 Input Argument: int* unHeapifiedList, size_t start, size_t end             *
 Output        : Heapify elements of the list based on heap property        *
 Description   : This function used to re-heapify the heapified list        *
                 when root element has been removed for sorting.            *
 ***************************************************************************/
void heapify(int* unHeapifiedList, size_t start, size_t end)
{
    // Check which subnode of the root is bigger.
    size_t iLeftChild  = 2 * start + 1;
    size_t iRightChild = 2 * start + 2;
    
    size_t iBiggerChildNode = iLeftChild;
    
    if ( unHeapifiedList[ iLeftChild ] < unHeapifiedList[ iRightChild ] &&  (iRightChild) <= end )
    {
        iBiggerChildNode = iRightChild;
    }
    
    // Check if root is greater than (2i + 1) and (2i+2) element in the list?
    if ( unHeapifiedList[ start ] < unHeapifiedList[ iBiggerChildNode ] )
    {
        // Swap element root with bigger child
        int rootElement          = unHeapifiedList[ start ];
        unHeapifiedList[ start ] = unHeapifiedList[ iBiggerChildNode ];
        unHeapifiedList[ iBiggerChildNode ] = rootElement;
        // Call heapify function for re-heapify if required. Call it unleass it reaches to end.
        // Call left sub-tree
        if ( ( 2 * iLeftChild + 1 ) <= end)
        {
            heapify(unHeapifiedList, iLeftChild , end );
        }
        // Call right sub-tree
        if ( ( 2 * iRightChild + 1 ) <= end)
        {
            heapify(unHeapifiedList, iRightChild , end );
        }
        
    }
    
}

/****************************************************************************
 Function Name : void heapSort()                                            *
 Input Argument: int* HeapifiedList, size_t Root, size_t endIndex           *
 Output        : Sorted list of elements                                    *
 Description   : This function sorts the heapified list in assending order. *
 ***************************************************************************/

void heapSort(int* A, size_t iRoot, size_t iEnd)
{
    // Remove root and place it to the position of last elment
    // Move last elment to root.
    // Actually swap root with last elment till end reaches to start position.
    int rootElement = A[ iRoot ];
    A[iRoot] = A[iEnd];
    A[iEnd] = rootElement;
    
    // Root has been placed into sorted position, decrement last index
    iEnd = iEnd -1 ;
    // Call heapify function and heap short till iEnd reaches to root element
    if( iRoot < iEnd )
    {
        heapify(A, iRoot, iEnd);
        //displayData(A, iRoot, iEnd );
        // Sort Hipified Element
        heapSort(A, iRoot,iEnd);
    }
}
/*****************************************************************************
 Function Name : displayData(<list of elements>, < low index>, < high index>)*
 Input Argument: int* Aarray, size_t start, size_t end                       *
 Output        : Array elemnents                                             *
 Description   : Display array elements                                      *
 ****************************************************************************/
void displayData(int *A, size_t low, size_t  end)
{
    for(size_t index=low; index<= end; index++)
    {
        if ( index == low )
        {
            cout<<A[index];
        }
        else
        {
            cout<<" "<<A[index];
        }
    }
    cout<<endl;
}

