#include<iostream>
#include<stdlib.h>


using namespace std;

struct Node
{
    int data;
    Node *next;
};


bool detectLoopAndRemove( Node * );
void remove(Node*, Node*);

void display(Node*);

int main(int argc, char** argv)
{
    int i = 0;
    int noOfNode       = atoi(argv[1]);
    int loopStartIndex = atoi(argv[2]);
 
    Node * root = NULL;
    Node * ptr;
    cout<<"Create LinkedList"<<endl;
    while( i < noOfNode )
    {
        Node * newNode = new Node();
        cin>> newNode->data ;
        newNode->next  = NULL;
        if ( ! root )
        {
            root = newNode;
            ptr  = root;
        } 
        else
        {
            ptr->next = newNode;
            ptr       = ptr->next;
        }
        i++;
    }    
    
    // Create a loop
    i = 0;
    Node *ptrLoop = root;
    cout<<"Create Loop"<<endl;
    while ( i < loopStartIndex )
    {
        ptrLoop = ptrLoop->next;
        i++;
    }
    // Loop Back 
    ptr->next = ptrLoop; 
    cout<<"PTR"<<ptr->data<<"START"<<ptrLoop->data<<endl;

    cout<<"Detect Loop"<<endl;
    // Detect Loop
    if ( detectLoopAndRemove(root) )
    {
        cout<<"Loop Exist and Removed"<<endl;
    }
    else
    {
        cout<<"No Loop"<<endl;
    }

    cout<<"Display LinkedList"<<endl;
    display(root);
    return 0;
}

bool detectLoopAndRemove(Node * root)
{
    Node *slow = root;
    Node *fast = root;
    
    while( slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if ( slow == fast )
        {   
            // Remove Link
            cout<<"Loop Detected:"<<slow->data<<endl;
            remove(slow, root );
            return 1;
        }
    }
    return 0;
}

void remove(Node * slow, Node* head)
{
    Node * prev;
    
    if ( slow == head )
    {
        // find and node
        while( slow->next != head)
            slow = slow->next;
        prev = slow; 
    }
    else
    {
    while( slow != head )
    {
        prev = slow;
        slow = slow->next;
        head = head->next;
    }
    }
    cout<<"Loop Begin Node:"<<prev->next->data<<endl;
    prev->next = NULL;
}

void display(Node* head)
{
    while ( head != NULL )
    {
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<"\n";
}
