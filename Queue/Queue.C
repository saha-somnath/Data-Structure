//
//  main.cpp
//  Queue
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//


/*
Implementation of Queue using LinkedList which has front and rear pointer.

*/

#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node *next;
};

class Queue
{
    Node* front;
    Node* rear;
public:
    Queue()
    {
        front =NULL;
        rear  =NULL;
    }
    ~Queue()
    {
        if( front){
          while(front){
            Node* ptr = front;
            front = front->next;
            delete ptr;
          }
          rear = NULL;
        }
    }
    void enqueue( int item);
    int dequeue();
    bool isQueueEmpty();
    void display();
};

// Enque operation add a new node to the tail or rare
void Queue::enqueue( int item )
{
    Node *ptrTraverse = front;
    // Create New node
    Node *ptrNewNode = new Node();
    ptrNewNode->item = item;
    ptrNewNode->next = NULL;
    if ( front == NULL)
    {   // Empty Queue , so add new element and assign to front
        front = ptrNewNode;
        rear  = front;
    }
    else
    {
                
        // Add element at the rear
        rear->next = ptrNewNode;
        rear = ptrNewNode; // Update rear
        
        
    }
}

// Dequeue operation, get the front elemnt out
int Queue::dequeue()
{
    if ( ! isQueueEmpty() )
    {
        cout<<"Exception Queue is empty"<<endl;
        return 0;
    }
    else
    {
        int element;
        element = front->item;
        Node *ptrDeleteNode = front;
        front = front->next;
        // remove the lement
        delete ptrDeleteNode;
        return element;
    }
}

// Check if Queue is empty
bool Queue::isQueueEmpty()
{
    if ( front == NULL )
    {
        return 0;
    }
    return 1;
}

// Display elments of the queue
void Queue::display()
{
    if (! isQueueEmpty() )
    {
        cout<<"Queue is empty, nothing to display"<<endl;
        return;
    }
    Node* ptrTraverseQueue = front;
    cout<<"Element of the Queue"<<endl;
    while( ptrTraverseQueue != NULL )
    {
        cout<<ptrTraverseQueue->item<<"->";
        ptrTraverseQueue = ptrTraverseQueue->next;
    }
    cout<<"NULL"<<endl;
}



int main(int argc, const char * argv[]) {
    // Craete Queue
    Queue myQueue;
    myQueue.dequeue();
    myQueue.display();
    // Populate queue with 5 elements
    myQueue.enqueue(4);
    myQueue.enqueue(9);
    myQueue.enqueue(2);
    myQueue.enqueue(5);
    // Display queue
    myQueue.display();
    // Dequeue operation
    cout<< "Popped up element from queue is => "<<myQueue.dequeue()<<endl;
    myQueue.display();

    // Enqueue
    myQueue.enqueue(6);
    myQueue.display();
    
    
    return 0;
}

