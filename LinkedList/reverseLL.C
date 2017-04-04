#include<iostream>
#include<stdlib.h>


using namespace std;

struct Node
{
    int data;
    Node *next;
};


Node* reverse(Node*);

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
    
   
    cout<<"Display LinkedList"<<endl;
    display(root);

    cout<<"Reversed LinkedList"<<endl;
    root = reverse(root);
    display(root);
    return 0;
}


Node* reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while( current != NULL )
    {
        next = current->next;
        current->next = prev; 
        prev = current;
        current = next;   
    }
    cout<<"N"<<prev->data<<endl;
    
    return prev;
}

void display(Node* head)
{
    Node *ptr = head;
    while ( ptr != NULL )
    {
        cout<<ptr->data<<"->";
        ptr= ptr->next;
    }
    cout<<"NULL\n";
}
