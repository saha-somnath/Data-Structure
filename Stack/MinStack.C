//
//  main.cpp
//  StackMin
//
//  Created by Somnath Saha on 1/4/17.
//  Copyright © 2017 Somnath Saha. All rights reserved.
//

#include <iostream>

using namespace  std;

struct Node{
    int data;
    int min;
    Node * next;
};


class Stack{
    Node * TOP;
public:
    void push(int);
    int pop();
    int min();
    void display();
    bool isEmpty();
    Stack ()
    {
        TOP = NULL;
    }
    ~Stack()
    {
        while(TOP != NULL)
        {
            Node *dPtr = TOP;
            TOP = TOP->next;
            delete dPtr;
        }
    }
};

/*
 Function Name: push()
 Description  : Push A value to the stack and update min of the stack to the min value of new node.
 */
void Stack::push(int item)
{
    Node * newNode = new Node();
    newNode->data = item;
    newNode->min  = item;
    newNode->next = NULL;
    if ( TOP == NULL )
    {
        TOP = newNode;
    }
    else{
        // Update min value
        if ( item > TOP->min){
            newNode->min = TOP->min;
        }
        newNode->next = TOP;
        TOP = newNode;
    }
}

int Stack::pop()
{
    int element = -1;
    if ( ! isEmpty() )
    {
        element = TOP->data;
        Node * dPtr = TOP;
        TOP = TOP->next;
        delete dPtr;
    }
    return element;
}

bool Stack::isEmpty()
{
    
    if( TOP == NULL)
    {
        cout <<"Empty Stack !! "<<endl;
        return 1;
    }
    else{
        return 0;
    }
}
int Stack::min()
{
    if ( ! isEmpty())
    {
        return TOP->min;
    }
    return -1;
}

void Stack::display()
{
    // If Stack Not empty
    if ( ! isEmpty())
    {
        Node * tPtr = TOP;
        while( tPtr != NULL )
        {
            cout<<tPtr->data << "->";
            tPtr = tPtr->next;
        }
        cout <<"NULL"<<endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Stack Min Program!\n";
    
    Stack S;
    S.push(4);
    S.push(3);
    S.push(5);
    S.display();
    cout<<"Min:" << S.min()<<endl;
    cout <<"Poped Element:" << S.pop()<<endl;
    S.push(1);
    S.display();
    cout<<"Min:" << S.min()<<endl;
    cout <<"Poped Element:" << S.pop()<<endl;
    S.push(7);
    S.display();
    cout<<"Min:" << S.min()<<endl;

    
    
    return 0;
}

