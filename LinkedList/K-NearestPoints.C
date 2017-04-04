//
//  main.cpp
//  LinkedList
//
//  Created by Somnath Saha on 3/26/17.
//  Copyright © 2017 Somnath Saha. All rights reserved.
//

/*
 Find the K nearest points from the origin.
 Time Complexity: O(NK)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
using namespace std;

struct Node{
  
    int x;
    int y;
    Node* next;
};


Node* createNode(int x, int y)
{
    Node* ptr = new Node();
    ptr->x = x;
    ptr->y = y;
    ptr->next = NULL;
    return ptr;
}

Node* kNearestPoints(Node* head, int K, Node* origin)
{
    Node* ptr = head;
    Node* kListHead = NULL;
    Node* kListPtr = NULL;
    
    
    // Create a K elements array
    int index = 0;
    while ( index <= K )
    {
        if ( kListHead == NULL )
        {
            kListHead = createNode(1000, 1000);
            kListPtr = kListHead;
        }
        else{
            kListPtr->next = createNode(1000, 1000);
            kListPtr = kListPtr->next;
        }
        index++;
    }

    cout<<"Points:";
    
    while ( ptr != NULL)
    {
        cout<<"["<<ptr->x <<","<<ptr->y<<"] ,";
        
        if (( origin->x == ptr->x ) && (origin->y == ptr->y))
        {
            ptr = ptr->next;
            continue;
        }
        
        kListHead->x = ptr->x;
        kListHead->y = ptr->y;
        kListPtr = kListHead;
        
        while (kListPtr->next != NULL)
        {
            // calculate distance
            double  d1 = sqrt((kListPtr->x - origin->x) * (kListPtr->x - origin->x) +
                              (kListPtr->y - origin->y) * (kListPtr->y - origin->y));
            double d2 = sqrt((kListPtr->next->x - origin->x) * (kListPtr->next->x - origin->x) +
                             (kListPtr->next->y - origin->y) * (kListPtr->next->y - origin->y));
            
            if ( d1 < d2 )
            {
                int tempX = kListPtr->x;
                int tempY = kListPtr->y;
                kListPtr->x = kListPtr->next->x;
                kListPtr->y = kListPtr->next->y;
                
                kListPtr->next->x = tempX;
                kListPtr->next->y = tempY;
            }
            else{
                break;
            }
            
            kListPtr = kListPtr->next;
        }
        // Move to the next point of points of array
        ptr = ptr->next;
    }
    cout<<endl;
    cout<<"Origins: ["<< origin->x <<","<<origin->y <<"]"<<endl;
    
    Node* kListTemp = kListHead;
    kListHead   = kListHead->next;
    delete kListTemp;
    
    return kListHead;
}

int main(int argc, char** argv)
{
    // Crate the list
    Node* head = NULL;
    Node* ptr  = NULL;
    int K      = 3;  // Set K value 
    
    // Data points   
    int X[] = { 12, 22, 35, 42, 48, 53, 56};
    int Y[] = { 16, 30, 39,  45, 50, 55, 12};
    
    int nodeListSize = sizeof(X)/sizeof(X[0]);
    int index = 0;
    while ( index < nodeListSize )
    {
        if ( head == NULL )
        {
            head = createNode(X[index], Y[index]);
            ptr = head;
        }
        else{
            ptr->next = createNode(X[index], Y[index]);
            ptr = ptr->next;
        }
        index++;
    }
    
    // Set Origin
    Node* origin = createNode(35,39);
   
    // Call K nearest point function
    Node * list = kNearestPoints(head, K, origin);
    
    Node* temp = NULL;
    cout<< K <<" Nearest Points:";
    while( list != NULL)
    {
        cout<<"["<<list->x <<","<<list->y<<"],";
        temp = list;
        list = list->next;
        
        delete temp; // Delete memory
    }
    cout <<endl;
    

    // Delete LL
    while( head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    
    return 0;
}
