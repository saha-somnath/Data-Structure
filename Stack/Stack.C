//
//  main.cpp
//  Stack
//
//  Created by Somnath Saha on 10/6/15.
//  Copyright © 2015 Somnath Saha. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node *next;
};

class Stack
{
    Node* TOP;
   
public:
    Stack()
    {
        TOP =NULL;
    }
    ~Stack()
    {
        if ( TOP != NULL)
        {
            delete [] TOP;
        }
    }
    void push( int item);
    int  pop();
    bool isStackEmpty();
    void display();
};

// Enque operation add a new node to the tail
void Stack::push( int item )
{
    // Create New node
    Node *ptrNewNode = new Node();
    ptrNewNode->item = item;
    ptrNewNode->next = NULL;
    if ( TOP == NULL)
    {   // Empty Stack , so add new element and assign to TOP
        TOP = ptrNewNode;
    }   
    else
    {// Add in the TOP 
         ptrNewNode->next = TOP;      
         TOP = ptrNewNode;
    }
}

// Dequeue operation, get the TOP elemnt out
int Stack::pop()
{
    int element = 0;

    if ( ! isStackEmpty() )
    {
        cout<<"Exception Stack is empty"<<endl;
    }
    else
    {
        int element;
        element = TOP->item;
        Node *ptrDeleteNode = TOP;
        TOP = TOP->next;
        // remove the element
        delete ptrDeleteNode;
    }
    return element;
}

// Check if Stack is empty
bool Stack::isStackEmpty()
{
    if ( TOP == NULL )
    {
        return 0;
    }
    return 1;
}

// Display elments of the queue
void Stack::display()
{
    if (! isStackEmpty() )
    {
        cout<<"Stack is empty, nothing to display"<<endl;
        return;
    }
    Node* ptrTraverseStack = TOP;
    cout<<"Element of the Stack"<<endl;
    while( ptrTraverseStack != NULL )
    {
        cout<<ptrTraverseStack->item<<"->";
        ptrTraverseStack = ptrTraverseStack->next;
    }
    cout<<"NULL"<<endl;
}



int main(int argc, const char * argv[]) {
    // Craete Stack
    Stack myStack;
    myStack.pop();
    myStack.display();
    // Populate queue with 5 elements
    myStack.push(4);
    myStack.push(9);
    myStack.push(2);
    myStack.push(5);
    // Display queue
    myStack.display();
    cout<< "Popped up element from queue is => "<<myStack.pop()<<endl;
    
    myStack.display();

    myStack.push(6);
    myStack.display();
    
    
    return 0;
}

